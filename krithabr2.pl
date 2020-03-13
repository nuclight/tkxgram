#!/usr/bin/perl -w
use Modern::Perl;
use utf8;

use Tkx;
use Time::HiRes qw(time);

require EmojiTGData;
use constant SIZE => 24;

use CBOR::XS;
use Data::Dumper;
use POSIX;
use Encode;
use TL::Object;
use Telegram::ObjTable;
use MTProto::ObjTable;

require $_ for map { $_->{file} } values %Telegram::ObjTable::tl_type;
require $_ for map { $_->{file} } values %MTProto::ObjTable::tl_type;

use Data::DPath qw'dpath dpathr';
use Getopt::Long::Descriptive;

sub option_spec {
    [ 'filter|f=s'  => 'Data::DPath filter expression' ],
    [ 'tl_len=s'    => 'try to pack back to TL and count length' ],
    [ 'verbose|v:+' => 'more twitting about actions', { default => 0} ],
    [ 'nomark'      => 'do not output marker records', { default => 0} ],
}

### initialization

my ($opts, $usage);

eval { ($opts, $usage) = describe_options( '%c %o ...', option_spec() ) };
die "Invalid opts: $@\nUsage: $usage\n" if $@;

die "Input filename(s) must be specified\n" unless @ARGV;

# messages, file read
my @msgs;

say "start";

my $t0 = time;   

Tkx::package_require($_)
    for qw(img::jpeg img::png treectrl);

Tkx::image_create_photo("feather", -file => '../androwish/jni/tktreectrl/demos/pics/feather.gif');
Tkx::image_create_photo("sky", -file => '../androwish/jni/tktreectrl/demos/pics/sky.gif');
#$Tkx::TRACE = 1;

# TODO tabs
my $textBg = "light green";
my %UI;
$UI{mw}         = Tkx::widget->new("."); # main window
$UI{panw}       = $UI{mw}->new_ttk__panedwindow(-orient => 'horizontal');
$UI{frmRight}   = $UI{panw}->new_ttk__frame();
$UI{panLeft}    = $UI{panw}->new_ttk__panedwindow(-orient => 'vertical');
$UI{panMiddle}  = $UI{panw}->new_ttk__panedwindow(-orient => 'vertical');
$UI{frmLeftBot} = $UI{panLeft}->new_ttk__frame();
$UI{frmMidTop}  = $UI{panMiddle}->new_ttk__frame();
$UI{frmMidBott} = $UI{panMiddle}->new_ttk__frame();
$UI{treeMidTop} = $UI{frmMidTop}->new_treectrl(-showroot => 0, -showrootbutton => 0, -showrootlines => 0, -selectmode => 'single');
$UI{sbvMidTop}  = $UI{frmMidTop}->new_ttk__scrollbar(-command => [$UI{treeMidTop}, "yview"], -orient => "vertical");
$UI{treeLeft}   = $UI{frmLeftBot}->new_treectrl(-showroot => 0, -showrootbutton => 0, -showrootlines => 0, -selectmode => 'single');
$UI{sbvLeft}    = $UI{frmLeftBot}->new_ttk__scrollbar(-command => [$UI{treeLeft}, "yview"], -orient => "vertical");
$UI{treeMidBot} = $UI{frmMidBott}->new_treectrl(-showroot => 0, -showrootbutton => 0, -showrootlines => 0, -selectmode => 'single');
$UI{sbvMidBot}  = $UI{frmMidBott}->new_ttk__scrollbar(-command => [$UI{treeMidBot}, "yview"], -orient => "vertical");
$UI{treeRight}  = $UI{frmRight}->new_treectrl(-showroot => 0, -showrootbutton => 0, -showrootlines => 0, -selectmode => 'single');
$UI{sbvRight}   = $UI{frmRight}->new_ttk__scrollbar(-command => [$UI{treeRight}, "yview"], -orient => "vertical");
$UI{panw}->add($UI{panLeft}, -weight => 1);
$UI{panw}->add($UI{panMiddle}, -weight => 1);
$UI{panw}->add($UI{frmRight}, -weight => 1);
$UI{panMiddle}->add($UI{frmMidTop}, -weight => 4);
$UI{panMiddle}->add($UI{frmMidBott}, -weight => 3);
$UI{panLeft}->add($UI{frmLeftBot}, -weight => 2);
$UI{treeMidTop}->configure( -yscrollcommand => [$UI{sbvMidTop}, 'set']);
$UI{treeLeft}->configure(-yscrollcommand => [$UI{sbvLeft}, 'set']);
$UI{treeMidBot}->configure(-yscrollcommand => [$UI{sbvMidBot}, 'set']);
$UI{treeRight}->configure(-yscrollcommand => [$UI{sbvRight}, 'set']);

# overall
$UI{mw}->g_wm_title("Test TreeCtrl -f ". $opts->filter . " " . $ARGV[0]);
$UI{panw}->g_grid(-column => 0, -row => 1, -columnspan => 8, -sticky => "nwes", -pady => 1, -padx => 5);

# left
$UI{treeLeft}->g_grid( -column => 0, -row => 0, -sticky => "nwes");
$UI{sbvLeft}->g_grid( -column => 1, -row => 0, -sticky => "ens");
$UI{frmLeftBot}->g_grid_columnconfigure(0, -weight => 1);
$UI{frmLeftBot}->g_grid_rowconfigure(0, -weight => 1);

# middle pane
$UI{treeMidTop}->g_grid( -column => 0, -row => 0, -sticky => "nwes");
$UI{sbvMidTop}->g_grid( -column => 1, -row => 0, -sticky => "ens");
$UI{frmMidTop}->g_grid_columnconfigure(0, -weight => 1);
$UI{frmMidTop}->g_grid_rowconfigure(0, -weight => 1);
$UI{treeMidBot}->g_grid( -column => 0, -row => 0, -sticky => "nwes");
$UI{sbvMidBot}->g_grid( -column => 1, -row => 0, -sticky => "ens");
$UI{frmMidBott}->g_grid_columnconfigure(0, -weight => 1);
$UI{frmMidBott}->g_grid_rowconfigure(0, -weight => 1);

# right frame
$UI{treeRight}->g_grid( -column => 0, -row => 0, -sticky => "nwes");
$UI{sbvRight}->g_grid(-column => 1, -row => 0, -sticky => "ens");
$UI{frmRight}->g_grid_columnconfigure(0, -weight => 1);
$UI{frmRight}->g_grid_rowconfigure(0, -weight => 1);

# all window
$UI{mw}->g_grid_columnconfigure("all", -weight => 1);
$UI{mw}->g_grid_columnconfigure(0, -weight => 0);
$UI{mw}->g_grid_columnconfigure(7, -weight => 0);
$UI{mw}->g_grid_rowconfigure(1, -weight => 1);

# do setup
setup_treemsgs($UI{treeLeft}, 'feather');
setup_treemsgs($UI{treeMidTop}, 'sky', 1);
setup_treemsgs($UI{treeMidBot}, 'feather');
setup_treemsgs($UI{treeRight}, 'sky', 1);

### main start
my $fname = shift;
last unless $fname;

open FH, "<", $fname
    or die "can't open '$fname': $!";
binmode FH;

my $cbor_data;

# slurp all file at once :)
{
    local $/ = undef;
    $cbor_data = <FH>;
    close FH;
}

my $cbor = CBOR::XS->new;

my ($rec, $octets, $filter);

local $Data::Dumper::Sortkeys = 1;
local $Data::Dumper::Indent = 1;
local $Data::Dumper::Varname = $opts->filter ? 'filter' : '';
$| = 1;

$Data::DPath::USE_SAFE = 0; # or it will not see our classes O_o
$filter = dpath($opts->filter) if $opts->filter;

my $cborlen = length $cbor_data;
my $tl_len = 0;

sub one_rec {
    my $obj = exists $_->{in} ? $_->{in} : $_->{out};
    $obj = $_->{data} unless $obj;
    if ($opts->tl_len) {
        eval { $tl_len += 4*scalar($obj->pack) if $obj };
        warn "inaccurate tl_len $@" if $@;
    }
    unless (exists $_[0]->{time}) {
        local $Data::Dumper::Indent = 0;
        local $Data::Dumper::Varname = "markerecrd";
        say Dumper $_[0] unless $opts->{nomark};
        return;
    }
    push @msgs, defined $filter
          ? $filter->match($obj)
          : $obj
}

while (my $left = length $cbor_data) {
    if ($opts->verbose) {
        my $ofs = $cborlen-length($cbor_data);
        say sprintf "decoding at offset 0x%x, %d bytes left", $ofs, $left;
    }
    # log saver was buggy one time
    last if $left == 3 and $cbor_data eq $CBOR::XS::MAGIC;
    ($rec, $octets) = $cbor->decode_prefix ($cbor_data);
    substr($cbor_data, 0, $octets) = '';
    one_rec $_ for (ref $rec eq 'HASH' ? $rec : @$rec);
}

printf "CBOR finished in %fs\n", (time-$t0); $t0 = time;

#say Dumper (\@msgs) if $opts->verbose;
die "no Telegram::Message for render was found! check your -f" unless @msgs;

Tkx::image_create_photo("emoji_sprite$_", -file => "../tkxgram/res/24emoji_$_.png"),
printf "sprite $_ loaded, time is %fs after start\n", (time-$t0)
    for (1..5);
printf "sprites loaded in %fs, begin loop\n", (time-$t0); $t0 = time;
for my $emojidx (0 .. $#EmojiTGData::items) {
    my $item = $EmojiTGData::items[$emojidx];
    my $sprite = 1 + ($emojidx >> 9) & 0x1FF;
    my $spridx = $emojidx % 512;
    my $row = $spridx >> 5;
    my $col = $spridx % 32;

    my ($x1, $y1, $x2, $y2) = ($col*SIZE, $row*SIZE, ($col+1)*SIZE - 1, ($row+1)*SIZE - 1);

    my $hImage = Tkx::image_create_photo("emoji_$emojidx");

    Tkx::i::call($hImage, 'copy' ,"emoji_sprite$sprite", -from => $x1, $y1, $x2, $y2 );
}
printf "emojis copied in %fs\n", (time-$t0); $t0 = time;

Tkx::after(20000, sub { say "destroing sprite $_", Tkx::image_delete("emoji_sprite$_") for (1..5) });

for (@msgs) {
    if ((ref $_) =~ /Telegram::Message|Telegram::UpdateShortChatMessage/) {
        my $w;
        # TODO more _get_from_to_where
        if ((ref $_) =~ /Short/ or not exists $_->{to_id}) {
            $w = $UI{treeLeft};
        } elsif ($_->{to_id}->isa('Telegram::PeerChannel')) {
            $w = $UI{treeMidTop};
        } elsif ($_->{to_id}->isa('Telegram::PeerChat')) {
            $w = $UI{treeMidBot};
        } else {
            $w = $UI{treeRight};
        }
        tree_add_msg($w, $_);
    }
}

Tkx::MainLoop();

sub render_msg {
    my $txtwidg = shift;
    #@type Telegram::MessageABC
    my $msg = shift;

    $txtwidg->configure(-state => "normal");
    $txtwidg->delete("1.0", "end");

    local $Data::Dumper::Varname = "object";
    say Dumper($msg) if $opts->verbose;

    my $msgtext = dutf8($msg->{message});

    ### Handle Emoji, the way in TDesktop - pictures. THEY HAVE BUG
    # XXX unfixable NOTE: As Tk is usually not compiled for such avant-garde
    # (aggravated by fact of different Emoji sequences and meanings at
    # different vendors), we must axe out *ALL* Emoji strings of message before
    # passing to Tk's render, because NOTE that some of them are in Unicode's
    # BMP (e.g. "\x{2649}" alone) and would be rendered different by "normal"
    # font engine! (yep, entire Emoji theme is mistake of humankind and Unicode
    # Consortium). But...
    #
    # But here formatting (bold etc.) comes into play. Message entities are
    # offset/length pairs, and tk::text index expressions are VERY handy to
    # deal with this... Telegram docs say entities are in UTF-8 codepoints,
    # unfortunately, it's actually in UTF-16 :( But also, Emoji string could
    # consist of 1 to 8 (?) codepoints!
    #
    # So we do a dirty hack here. First, we search for Emoji in text, remember
    # which it is and at what index, and replace all it's codepoints with dummy
    # character for length to stay the same. Also, we insert dummy to compensate
    # for UTF-8 - UTF-16 length difference. Then, we apply formatting Entities.
    # And last, we delete dummy characters and insert Emoji pictures using
    # remembered index/length information.
    #
    # NOTE Also 'postfixed' Emoji really have \x{FE0F} appended, but this is:
    # 1) only for one-char length strings
    # 2) not always true in real incoming messages!

    # housekeeping info
    my %offsets;    # text index -> [emoji id, has seen postfix]
    my @adjust;     # offset -> how many chars added

    # longest first, ascending inside
    my @esorted = sort {
        length $b <=> length $a
            or
        $a cmp $b
    } keys %EmojiTGData::emoji2i;

    my @ssorted = sort {
        length $b <=> length $a
            or
        $a cmp $b
    } keys %EmojiTGData::semibare2i;

    my @bsorted = sort {
        length $b <=> length $a
            or
        $a cmp $b
    } keys %EmojiTGData::bare2i;

    local $Data::Dumper::Varname = "msgtext";
    say Dumper($msgtext) if $opts->verbose;

    if (exists $msg->{entities}) {
        foreach (@{ $msg->{entities} }) {
            local $Data::Dumper::Varname = "before".substr(ref $_, 9);
            say Dumper(substr($msgtext, $_->{offset}, $_->{length})) if $opts->verbose;
        }
    }
    for my $emoji (@esorted) {
        my $id = $EmojiTGData::emoji2i{$emoji};
        my $item = $EmojiTGData::items[$id];
        my $len = length($emoji);
        my $ofs;
        my $seen_postfix = 0;
        my $adj = 0;
        while (($ofs = index($msgtext, $emoji)) > -1) {
            $offsets{$ofs} = $id;
            if ($item->{postfixed}) {
                # from TDesktop src we know len=1 here
                if (substr($msgtext, $ofs+$len, 1) eq $EmojiTGData::POSTFIX) {
                    $seen_postfix = 1;
                }
                else {
                    # crutch for their non-Emoji versions
                    next if grep { $emoji eq $_ } @EmojiTGData::POSTFIX_REQUIRED;
                }
            }
            substr($msgtext, $ofs, $len, "\N{U+FFFD}" x $len);
            $adj += ord > 0xFFFF for split('', $emoji);
            $offsets{$ofs} .= " $adj $seen_postfix";
        }
    }
    # if not found by normal data, try with postfix chopped
    for my $emoji (@ssorted) {
        my $id = $EmojiTGData::semibare2i{$emoji};
        my $item = $EmojiTGData::items[$id];
        my $len = length($emoji);
        my $ofs;
        my $adj = 0;
        while (($ofs = index($msgtext, $emoji)) > -1) {
            $offsets{$ofs} = $id;
            substr($msgtext, $ofs, $len, "\N{U+FFFD}" x $len);
            $adj += ord > 0xFFFF for split('', $emoji);
            $offsets{$ofs} .= " $adj 0";
        }
    }
    # and finally, if nothing helped, search for strings with postfix
    # cutted *anywhere* in a string - this is clearly standard violation
    # in Telegram (so e.g. :pound_symbol: not supported), so warn about!
    for my $emoji (@bsorted) {
        my $id = $EmojiTGData::bare2i{$emoji};
        my $item = $EmojiTGData::items[$id];
        my $len = length($emoji);
        my $ofs;
        my $adj = 0;
        while (($ofs = index($msgtext, $emoji)) > -1) {
            warn "bare emoji #$id matched at $ofs, report standard violation to Telegram";
            $offsets{$ofs} = $id;
            substr($msgtext, $ofs, $len, "\N{U+FFFD}" x $len);
            $adj += ord > 0xFFFF for split('', $emoji);
            $offsets{$ofs} .= " $adj 0";
        }
    }

    # now, we have to compensate for UTF-16 offsets/length in entities by
    # inserting \x{A0} - non-breaking space
    my $accumulated = 0;
    for my $ofs (sort { $a <=> $b } keys %offsets) {
        my ($id, $adj, undef) = split ' ', $offsets{$ofs};
        next unless $adj;
        substr($msgtext, $ofs+$accumulated, 0, "\N{U+A0}" x $adj);
        push @adjust, [ $ofs+$accumulated, $adj ];
        $accumulated += $adj;
    }

    local $Data::Dumper::Varname = "substed";
    say Dumper($msgtext) if $opts->verbose;
    local $Data::Dumper::Varname = "offsets";
    say Dumper(\%offsets) if $opts->verbose;
    local $Data::Dumper::Varname = "adjusts";
    say Dumper(@adjust) if $opts->verbose;

    # insert patched body into widget
    $txtwidg->insert_end($msgtext);

    # now apply message entities
    if (exists $msg->{entities}) {
        foreach (@{ $msg->{entities} }) {
            local $Data::Dumper::Varname = substr(ref $_, 9);
            say Dumper(substr($msgtext, $_->{offset}, $_->{length})) if $opts->verbose;
            $txtwidg->tag_add(
                substr(ref $_, 8),
                "1.0+" . $_->{offset} . "chars",
                "1.0+" . ($_->{offset} + $_->{length}) . "chars"
            );
        }
    }

    # make %offsets great again!
    while (my $patch = pop @adjust) {
        my ($ofs, $adj) = @$patch;
        $txtwidg->delete("1.0+" . $ofs . "chars") while $adj--;
    }

    # now delete substitions and insert emoji pictures
    # do this from end of text for simplicity (no index shifting)
    my $_dbg = '';
    for my $ofs (sort { $b <=> $a } keys %offsets) {
        my ($id, $adj, $postfixed) = split ' ', $offsets{$ofs};
        my $item = $EmojiTGData::items[$id];
        my $len = length($item->{id});

        my $tidx = "1.0+" . $ofs . "chars";
        local $Data::Dumper::Varname = "emoji";
        $_dbg = "id=$id ofs=$ofs len=$len tidx=$tidx adj=$adj post=$postfixed "
          . Dumper($EmojiTGData::items[$id]->{id}) . $_dbg
            if $opts->verbose;

        $len += ($postfixed//0);
        $txtwidg->delete($tidx) while $len--;

        $txtwidg->image_create($tidx, -image => "emoji_$id", -padx => 2, -pady => 2);
    }
    say $_dbg if $opts->verbose;

    # offsets for entities are done, now we can insert to beginning
    $txtwidg->insert("1.0", "\n");   # for headers

    $txtwidg->insert("1.0", "From: ".($msg->{from_id}//""));
    # don't want for Instant View be on own message's background
    $txtwidg->tag_add("out", "1.0", "2.0") if $msg->{out};
    local $Data::Dumper::Indent=0;
    local $Data::Dumper::Varname = "to_id";
    $txtwidg->insert("1.0", "To: ".Dumper($msg->{to_id})."\n") if exists $msg->{to_id};


#    $txtwidg->configure(-state => "disabled");
}

sub dutf8 ($) { decode_utf8($_[0], Encode::WARN_ON_ERR|Encode::FB_PERLQQ) }

sub presetup_tags {
    my $text = shift;   # widget

    # TODO font_actual (especially for subscripts/superscripts)
    # '::' correspond to generated classes, others are manual and from ::PageBlock
    # TODO elided text for additional fields (see comments like '#url')

    # usual message formatting
    $text->tag_configure('::MessageEntityMention',      -foreground => 'red', );
    $text->tag_configure('::MessageEntityHashtag',      -foreground => 'darkgreen', );
    $text->tag_configure('::MessageEntityBotCommand',   -foreground => 'brown', );
    $text->tag_configure('::MessageEntityUrl',          -foreground => 'blue', -underline => 1);
    $text->tag_configure('::MessageEntityTextUrl',      -foreground => 'blue', -underline => 1);#url
    $text->tag_configure('::MessageEntityEmail',        -foreground => 'blue',);
    $text->tag_configure('::MessageEntityBold',         -font => "-weight bold");
    $text->tag_configure('::MessageEntityItalic',       -font => "-slant italic");
    $text->tag_configure('::MessageEntityCode',         -foreground => 'red', -font => 'TkFixedFont'); # as on Mac
    $text->tag_configure('::MessageEntityPre',          -font => 'TkFixedFont', ); # language
    $text->tag_configure('::MessageEntityMentionName',  -foreground => 'brown', ); # user_id
    $text->tag_configure('::InputMessageEntityMentionName', -foreground => '#8e68c9', ); # user_id
    $text->tag_configure('::MessageEntityPhone',        -foreground => '#69e34b', );
    $text->tag_configure('::MessageEntityCashtag',      -foreground => '#4e743f', );
    $text->tag_configure('::MessageEntityStrike',       -overstrike=> 1);
    $text->tag_configure('::MessageEntityUnderline',    -underline => 1);
    $text->tag_configure('::MessageEntityBlockquote',   -lmargin1 => "1c", -lmargin2 => "1c", -background => 'gray');

    # Instant View: RichText
    $text->tag_configure('::TextUrl',                   -foreground => 'blue', -underline => 1);#url webpage_id 
    $text->tag_configure('::TextEmail',                 -foreground => 'blue',); # email
    $text->tag_configure('::TextBold',                  -font => "-weight bold");
    $text->tag_configure('::TextItalic',                -font => "-slant italic");
    $text->tag_configure('::TextUnderline',             -underline => 1);
    $text->tag_configure('::TextStrike',                -overstrike=> 1);
    $text->tag_configure('::TextFixed',                 -font => 'TkFixedFont', );
    $text->tag_configure('::TextSubscript',             -offset => '6p',  -font => "-size 8" );
    $text->tag_configure('::TextSuperscript',           -offset => '-6p', -font => "-size 8");
    $text->tag_configure('::TextMarked',                -foreground => '#ffa0ff', );
    $text->tag_configure('::TextPhone',                 -foreground => '#69e34b',); #phone
    $text->tag_configure('::TextAnchor',                -foreground => 'blue', ); #name

    # Instant View & others
    $text->tag_configure('Title',                       -font => "Helvetica 18 bold", );
    $text->tag_configure('Caption',                     -font => 'TkCaptionFont', );
    $text->tag_configure('Subtitle',                    -font => "Helvetica 16", );
    $text->tag_configure('Header',                      -font => "Helvetica 14 bold", );
    $text->tag_configure('Subheader',                   -font => "-weight bold", );
    $text->tag_configure('Paragraph',                   -font => "", );
    $text->tag_configure('Preformatted',                -font => 'TkFixedFont', );
    $text->tag_configure('Footer',                      -font => 'TkSmallCaptionFont', );
    $text->tag_configure('Kicker',                      -font => 'TkSmallCaptionFont', ); #XXX wtf is this?
    $text->tag_configure('Small',                       -font => 'TkSmallCaptionFont', );
    $text->tag_configure("MessageService",              -background => "#a000a0");
    $text->tag_configure("List",                        -lmargin2 => "5m", -tabs => "5m");
    $text->tag_configure("Blockquote",                  -lmargin1 => "1c", -lmargin2 => "1c");
    $text->tag_configure("out",                         -background => "#f6fbed");
    $text->tag_configure("Unsupported",                 -font => 'TkCaptionFont', -background => "pink");
    $text->tag_configure("non_handled",                 -background => "red");
}

sub setup_treemsgs {
    my $trc = shift;    # tree control
    my $bg_pic = shift;
    my $bgopaq = shift;

    $trc->configure(-yscrollincrement => 4); #, -borderwidth => 0, -highlightthickness => 0);
    $trc->configure(-bgimage => $bg_pic, -bgimageopaque => $bgopaq ? 'yes' : 'no')
        if $bg_pic;

    # elements
    $trc->element_create(elemTxtDate => 'text', -fill => 'blue');
    $trc->element_create(elemBubble => 'rect', -rx => 7);
    $trc->element_create(elemWidget => 'window', -destroy => 'yes'); # TODO clip

    ## styles
    $trc->style_create('styMessageText', -orient => "vertical");
    $trc->style_elements(styMessageText => [qw{elemBubble elemTxtDate elemWidget}]);
    $trc->style_layout(styMessageText => 'elemBubble', -union => 'elemTxtDate elemWidget', -ipadx => 8, -ipady => 8, -padx => 4, -pady => 4);
    $trc->style_layout(styMessageText => 'elemTxtDate', -pady => '0 6', -squeeze => 'x');
    $trc->style_layout(styMessageText => 'elemWidget', -iexpand => 'x', -squeeze => 'x');

    my $vars = $trc->_data();
    $vars->{hColumn}{main} = $trc->column_create(-text => "This a main column", -itemstyle => 'styMessageText');

    # This binding configures the -height option of a Text widget to the
    # number of lines it is displaying
    Tkx::bind(TextWrapBindTag => '<Configure>', q{
        scan [textlayout [%W cget -font] [%W get 1.0 "end - 1 chars"] \
            -width %w] "%%d %%d" width height
        set height [expr {$height / [font metrics [%W cget -font] -linespace]}]
        if {$height != [%W cget -height]} {
            %W configure -height $height
        }
    });
}

sub tree_add_msg {
    my ($tree, $msg) = @_;

    my $vars = $tree->_data();

    my $hItem = $tree->item_create();

    $tree->item_element_configure($hItem,
        $vars->{hColumn}{main}, 'elemTxtDate',
        -text => POSIX::strftime("%Y.%m.%d %H:%M:%S ", localtime $msg->{date})
            . (exists $_->{edit_date} ? 'edit ' : '')
            . substr(ref $msg, 10)
        );

    $tree->item_element_configure($hItem,
        $vars->{hColumn}{main}, 'elemBubble',
        -fill => [$textBg] 
    );

    my $txt = $tree->new_tk__text(-name => "txt$hItem",
        -background => $textBg, -borderwidth => 0, -highlightthickness => 0, -width => 26, -height => 1,
        -wrap => 'word', -cursor => "");
    $txt->g_bindtags('TextWrapBindTag');

    $tree->item_element_configure($hItem,
        $vars->{hColumn}{main}, 'elemWidget',
        -window => $txt
    );

    presetup_tags($txt);

    render_msg($txt, $msg);

    $tree->item_lastchild(root => $hItem);
}
