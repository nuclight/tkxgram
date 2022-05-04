#!/usr/bin/env perl

my $VERSION = 0.02;

use Modern::Perl;
use utf8;

use Config::Tiny;
use Storable qw(store retrieve freeze thaw dclone);
use Getopt::Long::Descriptive;

use CBOR::XS;

use AnyEvent;
use AnyEvent::Log;
eval { use Time::HiRes qw(time); };
use AnyEvent::Fork;
use AnyEvent::Fork::RPC;
use File::Spec;
use File::Basename;
use List::Util qw(max);

use Telegram;

use Telegram::Messages::GetDialogs;
use Telegram::InputPeer;
use Telegram::Messages::GetHistory;

use Telegram::ObjTable; # be independent if someone regens schema while we work
require $_ for map { $_->{file} } values %Telegram::ObjTable::tl_type;

use Data::Dumper;
use Teleperl::Util qw(:DEFAULT unlock_hashref_recurse);

sub option_spec {
    [ 'verbose|v!'  => 'be verbose, by default also influences logger'      ],
    [ 'noupdate!'   => 'pass noupdate to Telegram->new'                     ],
    [ 'debug|d:+'   => 'pass debug (2=trace) to Telegram->new & AE::log', {default=>0}],
    [ 'session=s'   => 'name of session data save file', { default => 'session.dat'} ],
    [ 'config|c=s'  => 'name of configuration file', { default => "teleperl.conf" } ],
    [ 'logfile|l=s' => 'path to log file', { default => "cborsave.log" }    ],
    [ 'prefix|p=s'  => 'directory where create files', { default => '.' }   ],
    [ 'schempath=s' => 'regexp for external process schemas path ($1 for version)' ],
}

### initialization

my ($opts, $usage);

eval { ($opts, $usage) = describe_options( '%c %o ...', option_spec() ) };
die "Invalid opts: $@\nUsage: $usage\n" if $@;

my $session = retrieve( $opts->session ) if -e $opts->session;
my $conf = Config::Tiny->read($opts->config);

$Data::Dumper::Indent = 1;
$AnyEvent::Log::FILTER->level(
    $opts->debug > 1 ? "trace" :
        $opts->debug ? "debug" :
            $opts->verbose ? "info" : "note"
);
$AnyEvent::Log::LOG->log_to_path($opts->logfile) if $opts->{logfile}; # XXX path vs file

install_AE_log_crutch();

my $pid = &check_exit();
AE::log fatal => "flag exists on start with $pid contents\n" if $pid;

my $cond = AnyEvent->condvar;

my %decoders;

if (my $pat = $opts->schempath) {
    my $basedir = dirname($pat);
    my $leafpat = basename($pat);

    opendir DIR, $basedir
        or die "Can't open schemata directory $basedir: $!";

    %decoders = map {
        my $fullpath = File::Spec->catfile($basedir, $_);
        /$leafpat/ && -d $fullpath
            ? ($1, +{ inc => $fullpath })
            : ()
    } grep {
        $_ ne '.' and $_ ne '..'
    } readdir DIR;

    closedir(DIR);

    my $proctmpl = AnyEvent::Fork
        ->new_exec                  # clean of _our_ schema
        ->require("TLExtDecoder");

    for my $layer (keys %decoders) {
        AE::log info => "starting process for layer $layer on %s", $decoders{$layer}->{inc};
        $cond->begin;
        $decoders{$layer}->{proc} = $proctmpl
            ->fork
            ->send_arg($decoders{$layer}->{inc})
            ->AnyEvent::Fork::RPC::run ("TLExtDecoder::run",
                init       => "TLExtDecoder::init",
                serialiser => $AnyEvent::Fork::RPC::NSTORABLE_SERIALISER,
                buflen     => 40960,
                on_destroy => sub { AE::log trace => "layer $layer exited"; $cond->end },
                on_error   => sub { save_cbor(1); AE::log fatal => "RPCFORK $layer ERROR: $_[0]"; },
                on_event   => sub {
                    if ($_[0] eq "ae_log") {
                        my (undef, $pid, $ctx, $level, $message) = @_;
                        (AnyEvent::Log::ctx "$layer\[$pid]/$ctx")->log($level, $message);
                    } else {
                        AE::log warn => "event from layer $layer: $_[0]\n";
                    }
                },
        );
    }

    $TL::Object::EXT_DECODER_CB = \&ext_decoder_cb if scalar keys %decoders;

    no strict 'refs';
    *UNIVERSAL::TO_CBOR = \&TL::Object::TO_CBOR;
}

install_AE_log_SIG_WARN();
install_AE_log_SIG_DIE();

my $tg = Telegram->new(
    dc => $conf->{dc},
    app => $conf->{app},
    proxy => $conf->{proxy},
    session => $session,
    reconnect => 1,
    keepalive => 1,
    noupdate => $opts->{noupdate},
    debug => $opts->{debug},
    minutonline => 0,
);
$tg->{on_raw_msg} = \&one_message;
$tg->{after_invoke} = \&after_invoke;

my $cbor = CBOR::XS->new->pack_strings(1);
my $cbor_data;
my @clones;
my $decode_fails = 0;
my %ext_layers = ();    # per record
my %seen_layers = ();   # per file
my %generated = ();

sub ext_decoder_cb {
    my ($hash, $stream) = @_;

    AE::log info => "got hash=%x with stream length %d", $hash, scalar(@$stream);

    # stop reading on handle to prevent 100% CPU load by event loop,
    # it should be re-enabled automatically as docs say
    if (defined $TL::Object::EXT_DEC_ST_HDL) {
        $TL::Object::EXT_DEC_ST_HDL->();
    }

    # here externally decoded object will be placed (or not)
    my $ext_obj;

    # we must stay here, in this func, not unwind main MTProto/TL::Object stack
    # until decoder processes are polled and return their answers
    local $AnyEvent::CondVar::Base::WAITING = 0;  # NOTE FUCK recursion!!!
    my $asks = AnyEvent->condvar;

    # as object can be big, first ask all if they could 
    my %whohas;
    for my $layer (keys %decoders) {
        AE::log debug => "trying to ask layer $layer";
        $asks->begin;
        $decoders{$layer}->{proc}->('has_hash', $hash, sub {
            AE::log debug => "layer $layer answered '$_[0]'";
                $whohas{$layer} = $_[0] if $_[0];
                $asks->end;
            });

        # one-time question info about process
        unless (%generated) {
            $asks->begin;
            AE::log debug => "asking $layer about it's scheme version";
            $decoders{$layer}->{proc}->('info_generated_from', sub {
                    $generated{$layer} = $_[0];
                    AE::log debug => "layer $layer generated from $_[0]";
                    $asks->end;
            });
        }
    }
    $asks->recv;

    unless (scalar keys %whohas) {
        AE::log error => "no external decoding for hash %x found", $hash;
        save_cbor();    # NOTE before we could possibly crash later
        $decode_fails++;
        return undef;
    }

    # now decoding itself, which still could possibly fail
    # we try from max version and go down on fails
    my ($successful, $trim);
    my @trylist = sort { $b <=> $a } keys %whohas;
    while (my $layer = shift @trylist)  {
        AE::log info => "trying to decode layer $layer";

        my $spin = AnyEvent->condvar;   # CV can't be reused :(

        $decoders{$layer}->{proc}->('tl_unpack_obj', $hash, $stream, sub {
                my ($consumed, $obj) = @_;
                AE::log debug => "decoder $layer returned consumed=$consumed obj=%s", defined $obj ? ref $obj : 'undef';

                if ($consumed && $obj) {
                    $ext_obj = $obj;
                    $successful = $layer;
                    $trim = $consumed;
                } else {
                    AE::log error => "decoder $layer has hash but failed decode";
                    delete $whohas{$layer};
                }
                $spin->send;
            });

        $spin->recv;
        last if $trim;
    }

    unless ($trim) {
        AE::log error => "external decoding for hash %x failed", $hash;
        save_cbor();    # NOTE before we could possibly crash later
        $decode_fails++;
        return undef;
    }

    # as now TL::Object will continue decoding "as if nothing happened" on
    # main scheme, need to adjust $stream for it
    splice @$stream, 0, $trim;

    # record info for later CBOR saver
    $ext_layers{$successful}->{$hash} = $whohas{$successful};

    AE::log note => "decoded hash %x to %s by external layer %d worker",
        $hash, $whohas{$successful}, $successful;
    $TL::Object::EXT_DECODED++;
    return $ext_obj;
}

sub one_message {
    my $mesg = shift;

    return if ref($mesg) =~ /MTProto::P.ng/ and not $opts->verbose;

    AE::log error => ">1 arg " . Dumper(@_) if @_;

    # XXX workaround of 'use fields' :(
    my $clone = dclone $mesg;
    AE::log trace => "$mesg $clone".Dumper($mesg, $clone);
    unlock_hashref_recurse($clone);

    my $rec = +{ time => time, in => $clone };

    if ($TL::Object::EXT_DECODED && %ext_layers) {
        $rec->{ext_layers} = dclone \%ext_layers;

        $seen_layers{$_} = $generated{$_} for keys %ext_layers;

        # clear per-message stat
        %ext_layers = ();

        $TL::Object::EXT_DECODED--; # XXX several per message?
    }

    push @clones, $rec;

    _pack() if @clones > 254;   # one byte economy :)
};

# NOTE this doesn't make sense here in right this daemon - serves mostly
# an example for real app wishing to log
sub after_invoke {
    my ($req_id, $query, $res_cb) = @_;

    my $cbname;
    $cbname= eval {
        require Sub::Util;
        Sub::Util::subname($res_cb);
    } if defined $res_cb;

    # XXX workaround of 'use fields' :(
    my $clone = dclone $query;
    AE::log trace => "$req_id $clone".Dumper($req_id, $clone);
    unlock_hashref_recurse($clone);

    push @clones, +{
        time => time,
        out => $clone,
        req_id => $req_id,
        ($cbname ? (cb => $cbname) : ())
    };
    # don't pack here, request may be still on queue and not sent yet
}

sub _pack {
    return unless @clones;
    $cbor_data .= $cbor->encode(@clones > 1 ? \@clones : $clones[0]);
    @clones = ();
}

# to be redefined in customary versions e.g. specialized dumpers
sub get_fname {
    my $fname = POSIX::strftime("%Y.%m.%d_%H", localtime);
    $fname = "$opts->{prefix}/$fname.cbor";
}

my $prev_fname = get_fname();;
sub save_cbor {
    my $last_and_quit = $_[0];
    _pack();
    return unless length $cbor_data > 3;

    my $fname = get_fname();
    my $new_fname = $fname;

    # last chunk - to previous, with seen external schema info
    if ($last_and_quit
        or
        $fname ne $prev_fname and -e $prev_fname and not -e $fname
    ) {
        $cbor_data .= $cbor->encode({
                   marktime => time,
                   externally_decoded_schema_seen => \%seen_layers,
               });
        # clear per-file stat
        %seen_layers = ();

        # direct write to previous file
        $fname = $prev_fname;
    } else {
        # usual case, new or same file
        $cbor_data = $CBOR::XS::MAGIC
                   . $cbor->encode({    # what version decoder should use
                           marktime => time,
                           schema => $Telegram::ObjTable::GENERATED_FROM,
                       })
                   . $cbor_data
            unless -e $fname;
    }

    sysopen my $fh, $fname, AnyEvent::IO::O_CREAT | AnyEvent::IO::O_WRONLY | AnyEvent::IO::O_APPEND, 0666
        or AE::log fatal => "can't open $fname: $!";
    binmode($fh);

    AE::log info => "length cbor=" . length $cbor_data;
    my ($n, $wrlen) = (0, 0);
    while ($wrlen < length $cbor_data) {
        $n = syswrite $fh, $cbor_data; #, $wrlen; # XXX bug with 3 arg on mswin O_o
        $n or AE::log fatal => "can't write $fname: $!";
        $n == length $cbor_data or AE::log fatal => "can't write $fname: short write $n"; 
        AE::log debug => "write returned $n";
        $wrlen += $n;
    }

    close $fh
        or AE::log fatal => "can't close $fname: $!";

    $cbor_data = '';
    $prev_fname = $new_fname;
}

sub save_session {
    AE::log note => "saving session file";
    store( $tg->{session}, $opts->session );
}

sub check_exit {
    my $flag = $opts->{session} . ".exitflg";
    return 0 unless -e $flag;

    my $body = do {
        local $/ = undef;
        open FLG, "<$flag";
        <FLG>
    };
    close FLG if $cbor_data;
    unlink $flag
        or AE::log error => "unlink: $!";

    return ($body || 'empty');
}

AE::log info => "starting tg on schema '$Telegram::ObjTable::GENERATED_FROM'";
$tg->start;

# XXX socks5 crutch!
AnyEvent->_poll until defined $tg->{_mt};

# subscribe to updates by any high-level query
$tg->invoke(
    Telegram::Messages::GetDialogs->new(
        offset_date => 0,
        offset_id => 0,
        offset_peer => Telegram::InputPeerEmpty->new,
        limit => -1,
        hash => 0,
    ), \&one_message
);
$tg->reg_cb(fatal => sub { shift; $cond->send(); });

my $save_i = 1;
my $watch = AnyEvent->timer(
    after => 2,
    interval => 1,
    cb => sub {
        save_cbor if $save_i % 60 == 0;
        $cond->send if &check_exit;
        save_session() if $save_i++ % 3600 == 0;
    },
);

my $signal;
if ($^O ne 'MSWin32') {
    $signal->{C} = AnyEvent->signal( signal => 'INT', cb => sub {
            AE::log note => "INT recvd";
            $cond->send;
        }
    );
    $signal->{T} = AnyEvent->signal( signal => 'TERM', cb => sub {
            AE::log note => "TERM recvd";
            $cond->send;
        }
    );
    $signal->{U} = AnyEvent->signal( signal => 'USR1', cb => sub {
            AE::log note => "USR1 recvd";
            save_session();
        }
    );
}

AE::log note => "entering main loop on schema '$Telegram::ObjTable::GENERATED_FROM'";
$cond->recv;
save_cbor(1) if @clones;

AE::log note => "quittin..";
save_session();
