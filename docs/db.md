# Architecture of SQLite Database

## Requirements

Using ideas at [SQLite forum post](https://sqlite.org/forum/forumpost/5e93e18fa9) as a start point of thinking (a must read to understand what is below).

We need to have somewhat universal storage of objects, which also could be called "documents" for MongoDB people, but may be real blessed Perl classes - [EAV/CR model](https://en.wikipedia.org/wiki/Entity%E2%80%93attribute%E2%80%93value_model).

However, some types of them need different metadata.

Messages need, at least:

 * deleted flag
 * unseen/unread flag
 * score

Files need:

* path to file in cache
* MD5, may be?
* some grouping - several files may be for same picture in different resolutions

### Plugin data

Variants of plugins (in respect to storage) we want to support, are, at least:

* annotating an object with text, e.g. OCR of meme picture - to be searchable by text
* layer of presenting instead of - e.g. a GPG encrypted/decrypted version of message

### Peering support

For ability to circumvent e.g. bans (personal or like "this channel marked porno so not available in your country") some way of interchanging objects between different people's databases is needed.
So a version of object need to have at least:

* received from this peer
* time of this version (time range?)
* schema version
* ??? which software version wrote this object?

Other questions need to be considered:

- what to do if objects from different peers mismatch? (maliciuos peer?)
- how to somewhat efficiently scan for new object to send to peer, e.g. "in today batch" ?

### Query like XPath/DPath/MongoDB

As this is historical data storage, and may be of different protocols, some universal way to find object should exist, like by any leaf value, e.g. any text string. And consider some internal structure in such queries, as schema of object may change in time.

## Examples of objects and their versions - what we should store efficiently

**Example 1.** Consider following relatively raw example of message object, which also includes some other file objects:

```perl
    'message' => bless( {
      'from_id' => bless( {
        'user_id' => 123456789
      }, 'Telegram::PeerUser' ),
      'id' => 92437,
      'flags' => 8389380,
      'media' => bless( {
        'flags' => 1,
        'photo' => bless( {
          'sizes' => [
            bless( {
              'type' => 'i',    # means inline image thumbnail data
              'bytes' => '^A($<A6><A7><A0>^X<A7><AC>N<EC>2<A3><93><8E>^M<^A^Z^F^X^Y^]<E9><A6>r<84>...long bytestring stripped...P^G'
            }, 'Telegram::PhotoStrippedSize' ),
            bless( {
              'w' => 286,
              'type' => 'm',
              'h' => 320,
              'size' => 28361
            }, 'Telegram::PhotoSize' ),
            bless( {
              'h' => 800,
              'type' => 'x',
              'w' => 714,
              'size' => 105315
            }, 'Telegram::PhotoSize' ),
            bless( {
              'sizes' => [
                15636,
                38692,
                77746,
                107586,
		121261
              ],
              'h' => 1028,
              'w' => 918,
              'type' => 'y'
            }, 'Telegram::PhotoSizeProgressive' )
          ],
          'date' => 1651091496,
          'access_hash' => '-7392190489400277356',
          'id' => '5425109394036734746',
          'dc_id' => 2,
          'file_reference' => '^BC\\^X<D8>^@^Ai^Ubi<DA><ED>|@<DF>A9>^T<E3><C6>w<CB>1<F2>',
          'flags' => 0
        }, 'Telegram::Photo' )
      }, 'Telegram::MessageMediaPhoto' ),
      'replies' => bless( {
        'replies_pts' => 94010,
        'replies' => 0,
        'flags' => 0
      }, 'Telegram::MessageReplies' ),
      'reply_to' => bless( {
         'reply_to_msg_id' => 634609,
	 'reply_to_top_id' => 292840,
          'flags' => 0
      }, 'Telegram::MessageReplyHeader' ),
      'fwd_from' => bless( {
        'date' => 1651091496,
        'flags' => 32,
        'from_name' => 'Some User'
      }, 'Telegram::MessageFwdHeader' ),
      'message' => 'here goes message text, may be short, may be as long as even 4 Kbytes!',
      'peer_id' => bless( {
        'channel_id' => 1123581119
      }, 'Telegram::PeerChannel' ),
      'date' => 1651091930
    }, 'Telegram::Message' ),
```

**Example 2.** Original (unedited) message:

```perl
    'message' => bless( {
      'peer_id' => bless( {
        'channel_id' => 1194168656
      }, 'Telegram::PeerChannel' ),
      'views' => 1,
      'reply_markup' => bless( {
        'rows' => [
          bless( {
            'buttons' => [
              bless( {
                'text' => '🧡',
                'flags' => 0,
                'data' => 'send_reaction_0'
              }, 'Telegram::KeyboardButtonCallback' ),
              bless( {
                'text' => '🖤',
                'flags' => 0,
                'data' => 'send_reaction_1'
              }, 'Telegram::KeyboardButtonCallback' )
            ]
          }, 'Telegram::KeyboardButtonRow' )
        ]
      }, 'Telegram::ReplyInlineMarkup' ),
      'media' => bless( {
         'id' => '5081221150508849332',
         # ... long object was here, skipped ...
      }, 'Telegram::MessageMediaWebPage' ),
      'date' => 1645507727,
      'post' => 1,
      'forwards' => 0,
      'entities' => [
        bless( {
          'offset' => 0,
          'length' => 39
        }, 'Telegram::MessageEntityUrl' )
      ],
      'message' => 'https://telegra.ph/Diana-de-Puate-02-22 Here goes some descriptive text for humorous text at the link, about half Kbyte long.…',
      'id' => 526,
      'flags' => 18112
    }, 'Telegram::Message' )
```

**Example 3.** First edit of message:

```perl
    'message' => bless( {
      'post' => 1,
      'forwards' => 0,
      'entities' => [
        bless( {
          'length' => 39,
          'offset' => 0
        }, 'Telegram::MessageEntityUrl' )
      ],
      'message' => 'https://telegra.ph/Diana-de-Puate-02-22 Here goes some fixed descriptive text for humorous text at the link, about half Kbyte long.…',
      'id' => 526,
      'media' => bless( {
         'id' => '5081221150508849332',
         # ... long object was here, skipped ...
      }, 'Telegram::MessageMediaWebPage' ),
      'flags' => 2148032,
      'peer_id' => bless( {
        'channel_id' => 1194168656
      }, 'Telegram::PeerChannel' ),
      'edit_date' => 1645507730,
      'date' => 1645507727,
      'reply_markup' => bless( {
        'rows' => [
          bless( {
            'buttons' => [
              bless( {
                'data' => 'send_reaction_0',
                'flags' => 0,
                'text' => '🧡'
              }, 'Telegram::KeyboardButtonCallback' ),
              bless( {
                'data' => 'send_reaction_1',
                'text' => '🖤',
                'flags' => 0
              }, 'Telegram::KeyboardButtonCallback' )
            ]
          }, 'Telegram::KeyboardButtonRow' )
        ]
      }, 'Telegram::ReplyInlineMarkup' ),
      'views' => 2
    }, 'Telegram::Message' )
```

**Example 4.** Last edit:

```perl
    'message' => bless( {
      'views' => 12527,
      'flags' => 2148032,
      'peer_id' => bless( {
        'channel_id' => 1194168656
      }, 'Telegram::PeerChannel' ),
      'entities' => [
        bless( {
          'offset' => 0,
          'length' => 39
        }, 'Telegram::MessageEntityUrl' )
      ],
      'date' => 1645507727,
      'id' => 526,
      'message' => 'https://telegra.ph/Diana-de-Puate-02-22 Here goes some descriptive text for humorous text at the link, about half Kbyte long.…',
      'post' => 1,
      'edit_date' => 1648838557,
      'reply_markup' => bless( {
        'rows' => [
          bless( {
            'buttons' => [
              bless( {
                'text' => '🧡 168',
                'data' => 'send_reaction_0',
                'flags' => 0
              }, 'Telegram::KeyboardButtonCallback' ),
              bless( {
                'flags' => 0,
                'text' => '🖤 8',
                'data' => 'send_reaction_1'
              }, 'Telegram::KeyboardButtonCallback' )
            ]
          }, 'Telegram::KeyboardButtonRow' )
        ]
      }, 'Telegram::ReplyInlineMarkup' ),
      'media' => bless( {
         'id' => '5081221150508849332',
         # ... long object was here, skipped ...
      }, 'Telegram::MessageMediaWebPage' ),
      'edit_hide' => 1,
      'forwards' => 36
    }, 'Telegram::Message' ),

```

**Example 5.** And object without edit date in it (only creation date), though fields may change in time:


```perl
  bless( {
    'id' => 1194168656,
    'min' => 1,
    'date' => 1571057257,
    'photo' => bless( {
      'stripped_thumb' => '^A^H^H<98><AC><9B><81>^\<AF>z(<A2><B9>&<96><86><E9><9F>',
      'flags' => 2,
      'photo_id' => '5222279361619669161',
      'dc_id' => 2
    }, 'Telegram::ChatPhoto' ),
    'flags' => 1060960,
    'has_link' => 1,
    'username' => 'history_chill',
    'broadcast' => 1,
    'title' => 'Heestorie on Leisure',
    'access_hash' => '-1935335668194123456'
  }, 'Telegram::Channel' )
```

**Example 6.** And finally object without any date in it, though `status` field changes often, other names may be changed also:

```perl
  bless( {
    'status' => bless( {}, 'Telegram::UserStatusRecently' ),
    'photo' => bless( {
      'stripped_thumb' => '^A^H^Hrܹ<9B>^D^M<BF>N<94>QEf<E4><FB><97>ʏ',
      'photo_id' => '911160643534564107',
      'dc_id' => 2,
      'flags' => 2
    }, 'Telegram::UserProfilePhoto' ),
    'last_name' => 'A hidden',
    'access_hash' => '-2789501974264567890',
    'first_name' => 'Alexander',
    'flags' => 1048679,
    'min' => 1,
    'id' => 212146119
  }, 'Telegram::User' )

```

### Sub-objects problem

As it can be seen, raw objects often include other objects with their own IDs, which could be requested independently from server by other methods - e.g. files, or webpage previews. Thus, these need in fact be stored as separate objects in DB - so, a some way to **reference** them to "include" or "mount" is needed. But this interferences with versions - e.g. one edit of message could reference one file or webpage, other edit could reference another one. So this "references" must point to concrete versions - and if versions are _inside_ of `inode`, we have a problem.

## Individual object/versions storage thoughts

So let's brainstorm how we can store all such versions efficiently, avoiding duplicating data.

### C object graph / memory dump - variant 0

Imagine we have machine with 1 TB memory and unbreakable power, so we don't need a database - how would store objects Perl itself in memory? It will have a bunch of SV, AV and HV objects with refcounts, which maps to DB tables very simply - just put ID's instead of reference pointers in memory. Given helper haches to index e.g. long PV's to avoid duplicate data, this will also be very effective storage!

However, how would we query such database for questions like "give me root objects where strings contain this word at any level deep" ? This would require a truly graph-oriented DB or at least some subset, wuth DAG paths. Even if we use some workaround knowing it's DAG staring only at objects of some type, there will be still too many paths in graph with every elementary object as a node.

### Everything in CBOR, texts outside, deltas - variant 1

Put every string into special `texts` table, which is FTS4 or FTS5 one - for searching. Then, every document is serialized into CBOR with text strings changed to special integer tags, and stored as BLOB. Every version must be stored as separate CBOR, or it may have `delta_to` field with ID of BLOB to which we are diff - for this, [Fossil Delta](https://www.sqlite.org/src/file?name=ext/misc/fossildelta.c&ci=tip) or similar must be used.

For searching texts, there must be a table which maps CBOR BLOB id to texts IDs.

For searching other values, [Application-defined SQL function](https://sqlite.org/appfunc.html) must be exported like e.g. `cbor_extract(path...)` and then [Indexes On Expressions](https://sqlite.org/expridx.html) must be utilized.

PROs:

* serializing and deserealizing from CBOR is very simple and can support any data
* given auxiliary object with every field name in database, using [Repeated string compression CBOR Tag](http://cbor.schmorp.de/stringref) (combined with some help like prepending aux object and deleting it) will also yield very compact storage - just about two integers for every 'key => value' pair

CONs:

* requires relatively new SQLite for indexes on expressions and compiling/loading delta extension - may be difficult on some ~~ancient~~ stable distros
* every index on every field must be created individually, and this may change when schema of objects changes - maintenance burden

### Hybrid model, CBOR plus leaf values - variant 2

Consider that in Data::Dumper examples above output is, with except of container (`[`/`{`/`bless`) lines, formatted with one scalar value per line, which could be called "leaf" value, if we represent an object as a tree.

Let's put them into table where each row will correspond to one line of dump, with key in one column and value in another. First, as key names in hashes repeat often, define auxiliary table to store only numbers:

**Attribute_name table:**

| id | name |
|----|------|
| INT| TEXT |

For arrays in dump, let it pretend that "key name" is a number - that is, value index in array. Now, our main main values table will have just number for both key name or index, and a flag to distinguish them.

**Leaf values table:**

| id | is_array | reftype | nameidx | value | value_aux |
|----|----------|---------|---------|-------|-----------|
| INT| BOOL   | what is val | key name or array index | actual value or reference | helper, e.g. hash of text |

Now, we can have `INDEX ON (nameidx, value)` and so  Just query like `WHERE key = 'user_id' AND value = 123456789` (conceptually, JOINs will complicate actual queries).

We still need to keep tree structure of objects somehow. Luckily, [CBOR Tag 26](http://cbor.schmorp.de/perl-object) does not mandate rigid format, so arguments in arrays may be just IDs from leaf values table - very efficient, even more than [stringref](http://cbor.schmorp.de/stringref) (tags 25/256), except that some subtleties of storing contatiner names must be resolved (probably with some custom CBOR tag).

And now, for searching from leaf values to master object, we have table:

**Object to leaf table**:

| entity_id | leaf_id |
|-----------|---------|
|   INT     |  INT    |

with _superset_ of all leaf values of all versions for this object. Why superset? If we'll keep matching for every version, this becomes very space-consuming for each versions - most rows will duplicate! And we still not yet have structure instead of plain rows...

Then, for structure of versions, we'll have:

| entity_id | version | CBOR |
|-----------|---------|------|
|   INT     |  INT    | BLOB |

with just structure of each object in it, consisting of just INTs and tags in CBOR.

Discussion:

* PRO: storing those INTs in CBOR is somewhat more space-efficient than in SQLite table
* PRO: no more maintenance pain of individual expression indexes!
* CON: indexes on everything will take significant amount of space
* PRO: from every leaf value search, we immediately have master object, without any intermediate version
* CON: if we want a version, we must deserialize & scan **all** CBOR BLOBs for master object - what if there are too many of them?
* PRO/CON: but user usually wants a master object, so no need for additional query to get master from version, in many cases
* CON: self cross-join problem to filter on - hard to build queries
* not so CON: only leaf matching, no paths in structure - user must deal with later-different-meaning but same-named fields (e.g. `reply_to` could be INT, but later became object like in example 1), etc.

### A non-CBOR but SQL+FTS - variant 3

The [Data::DPath](https://metacpan.org/pod/Data::DPath) module allows one to make XPath-like queries against Perl object, with requests like `'//.[isa("Telegram::Message")]/peer_id/channel_id[value==1383907943]/../../../../../..'` - and while full support of it's language in SQL database would require too much effort and will consume too much space for indexes, having at least _some_ of it's features would be handy for long-term history data storage, when schema changes over time, and old objects could not be converted. As you can see, the "leaf values table" from variant 2 is essentially having last part of this path, bound to tail (with always enough `/../` to root of object).

Meanwhile, consider the textual form of examples 3 and 4 - if we'd run a `diff -u` on them, we'd get a fragment like:

```diff
      'post' => 1,
-     'edit_date' => 1645507730,
+     'edit_date' => 1648838557,
+     'edit_hide' => 1,
      'reply_markup' => bless( {
        'rows' => [
          bless( {
            'buttons' => [
              bless( {
-               'text' => '🧡',
+               'text' => '🧡 168',
                'data' => 'send_reaction_0',
                'flags' => 0
              }, 'Telegram::KeyboardButtonCallback' ),
              bless( {
                'flags' => 0,
-               'text' => '🖤',
+               'text' => '🖤 8',
                'data' => 'send_reaction_1'
              }, 'Telegram::KeyboardButtonCallback' )
```

with all other lines, some of them very long lines - unchanged! What if could store big objects and their small diffs in DB like that?..

Anyone who have seen subtrees output from `sysctl` command will immediately get the idea. Let's depict how we could recreate some lines from examples 1, 3 and 4 one value at a time:

```perl
# of obj path elem 1      elem 2    elem 3    elem 4  elem 5     leaf table name/idx and value
$root    ->{reply_markup} ->{rows}  ->[0]                        ->{data} = 'send_reaction_0';
$root    ->{reply_markup} ->{rows}  ->[1]                        ->{text} = '🧡 168';
$root    ->{media}        ->{photo} ->{sizes} ->[3]   ->{sizes}  ->[4]    = 121261;
```

Of course, in addition to autovivifucation we'll need class information (to bless) here. First, let's define auxiliary class information table, with base/child class relationships:

| id (INT) | parent (INT) | class_name (TEXT) |
|-----------|-----------|
| 0 | NULL | '' |
| 1 | NULL | 'Telegram::Message' |
| 2 | 1 | 'Telegram::ServiceMessage' |

Now, modify **Object to leaf table** from variant 2 to two tables:

**Object_value_plus** and **Object_value_minus** tables, of the same schema:

| object_id | ipath_id | leaf_id |
|-----------|----------|---------|
|    INT    |    INT   |   INT   |

Each row will correspond to perl depict above, but with either included or excluded, and each object now has `diff_to` property - from which to borrow path/values, or vice versa, to include (non-diff object will have rows only in `plus` table`).

And, of course. the most interesting part...

**Internal paths table** `USING fts5`:

| ipath_id (INT) | name_path (TEXT) | class_path (TEXT) |
|----------------|------------------|-------------------|
|        0       |   ''            |       ''       |
|        1       |   '3'           |      '0'       |
|        2       |   'a b'         |      'cd ef'   |

This is a table with two text columns indexed by full text search. Many attempts to save space are made. Only unique paths are placed here, having just a compact integer ID in referencing leaves. Root and leaf are never part of path, so for common case "object is just a hash with no subobjects" the path will be empty.

Then, IDs constituing path from `Attribute_name` table are base32-encoded, most significant bit will show, is it array index or hash key. And this "words" are placed into `name_path` column.

For classes, things are more complicated, given that we have to support inheritance. Zero class is no class (for just plain hashrefs and arrayrefs). All others are constructed as words from Unicode characters, where each character, from left to right, has number (`ord()`) from class table, in order of inheritance chain.

For example, if class number encoded to `'d'` character is child of class whose number is encoded to `'c'` character, and current element in path is blessed to `'d'` class, then word becomes `'cd'`. If it is `'e'` class, whose parent is `'d'` - then `'cde'`, and so on.

This allows to make FTS queries like `"c*"` - so FTS engine will match base class and all it's descendants for us. If we need only `'d'` class, we'll put `"cd*"` in query, and so on.

PROs:

* no CBOR / Delta / app functions: ability to work on out-of-the-box SQLite found in old distros
* diff algorithm is more suited to nature of data, instead of more generic Fossil Delta (which would also depend on sort order inside blob)
* probably most possible indexing/matching capabilities from the unmodified SQL DB, without writing any C code for graphs or manual indexes

CONs:

* still the same self cross-join problem as in variant 2
* hard work to support from application
* either had to cache in memory "words" for classes and attributes or issue many quieries
* limit of 1 million classes, no multiple inheritance
* need to somehow to find a good candidate for diff - this is again not a group of versions, but individual objects
* complicated queries with compoud SELECT - probably will support only one level "delta to base", not "delta to delta"

## TBD / Still open questions

1. A structure of directory/inode tree table - is one-element enough, or do we need additional fields? E.g. object's path

   `/Telegram/chat=1234&message=2345/some`

   would correspond to table

   | id | d_name | chat | message | parent | inode |
   |----|--------|------|---------|--------|-------|
   |  1 |Telegram| NULL | NULL    |   NULL | NULL  |
   |  2 | NULL   | 1234 | 2345    |    1   | NULL  |
   |  3 | some   | NULL | NULL    |    2   | 3456  |

   but this duplicates this fields on **every** directory level, even if they are not used - is it good for indexes?..

2. How to add needed flags to only those types, then? E.g. an `unread` flag is for entire message, not only all it's versions. And how to store versions? If we add some fields to **directory** table right of inode, to keep versions and flags:

   | id | d_name | chat | message | parent | inode |    time    | API_vers | from_peer | deleted | unread | score |
   |----|--------|------|---------|--------|-------|------------|----------|-----------|---------|--------|-------|
   |  1 |Telegram| NULL | NULL    |   NULL | NULL  |    NULL    |   NULL   |   NULL    |  NULL   | NULL   |    0  |
   |  2 | NULL   | 1234 | 2345    |    1   | NULL  |    NULL    |   NULL   |   NULL    |  NULL   | NULL   |    0  |
   |  3 | some   | NULL | NULL    |    2   | 3456  | 1650123456 | layer136 | localhost |  false  | true   |  200  |
   |  4 | some   | NULL | NULL    |    2   | 3457  | 1651234567 | layer138 | alexhost  |  false  | true   |  100  |

   then such fields will need to be

   * superset of all possible needed fields
   * some of them will be waste for most rows in directory (of different type)

   This is in fact repetition (in smaller scale) of EAV problem for objects itself, just without hierarchy this time.

   * so keep this in some table and JOIN with `classes` table? or even put a table name?..

3. How to store references to split objects, e.g. webpage outside of message? How to query against them? Repeat graph way from variant 3, but now with object IDs?

4. Augmentation of main objects (let's call this **public** part, even if that's of private message) with private/volatile feilds (e.g. `access_hash`, `file_reference`, `UserStatusOnline/expires`) - just repeat mini-objects on e.g. per-account path and then merge them? This echoes object "include/mount" problem.

       main: /Telegram/Chan1234/2345
       priv: /Telegram/Acc98/Chan1234/2345

   or inverse path? Finding all occurences for message 2345 in channel 1234 under all accounts - could be expensive.

   -> no, let's have separate tables for this.

   | inode | account_id |  private  | volatile  | volatile_date
   |-------|------------|-----------|-----------|--------------
   |  INT  |    INT     | CBOR BLOB | CBOR BLOB | DATE when what's in `volatile` was received from cloud

   and

   | inode | volatile | volatile_date
   |-------|----------|--------------
   |  INT  | CBOR BLOB | DATE when what's in `volatile` was received from cloud

   for globally non-private volatile XXX probably move this into main inode info, no need for separate 2-column table

   XXX UserStatusOnline/expires is really per version?

5. Other "normal" relational table - how to mix without errors with all these?..

6. Purge pain.


**XXX**

still inode2versions table:

| inode | object_id |  obj_time  | API_version | writer_version | from_peer |
|-------|-----------|------------|-------------|----------------|-----------|
| 3456  | 235678    | 1650123456 |  layer136   |   Teleperl 0.1 | localhost |
| 3456  | 235679    | 1651234567 |  layer138   |  TeleGayJS 0.2 | alexhost  |

and deleted/unread/score etc. - must be per-inode

# Compression

## Texts

FTS4 (not FTS5) has `compress=` and `uncompress=` options, so this should be used.

Have a table (crc32 INT, dictionary BLOB) ??? may be language_id also?

Don't compress texts less than 90 bytes as per RFC 2394 recommendation, or whose compressed versions expands more than uncompressed (in total length, with header described below). In compressed BLOB, first 3 bytes are `'*z\0'` (meaning gz, bz, xz, lz, ...) to be distinguishable from UTF8 text, next 1 byte is compressor (TODO: have them named in separate table?), then follows 4 bytes of CRC32 of dictionary used to compress. Then data which decompressor will understand. E.g. `deflate` allows 32 Kb dictionaries and checks them with CRC32.

TODO what if no dict - waste 4 zero bytes or reduce to 128 compressors?  
-> make compressor SQLite varint format (actually Perl's `pack('w')`) so it can has flags and be extensible

As dictionaries are supposed to be cached in memory, as `deflate` has 32 Kb limit which will not waste much, there should not be many of them, so there is problem to have good dictionary. Possible way is to process corpus of texts for several years, split them to words (here Unicode normalization and FTS tokenizers must be taken into account), drop words with length 3 chars or less, sort words by rarest first frequent last then by length shortest last, and take `tail -c 32768` of this output as dictionary TBD eliminate space in this output?

TBD as edits are often just correcting typos, combine text compression with Fossil delta? Then need an algo to look for similar text to take as delta... edit versions are natural candidates, but that's not always the case, and may be possible from another group. Also, this contradicts is we want to support deleting edits (intermediate, oldest) - this may require repacking other texts, and first have to find them!

## CBOR repeated strings

[CBOR::XS](https://metacpan.org/pod/CBOR::XS) supports [repeated string compression CBOR Tag](http://cbor.schmorp.de/stringref). Actually, it is defined only on previous part of CBOR document itself, so the following hacky trick is employed: we create an outer array of two elements, first ([0]) will be array of strings which will serve as a dictionary, second is our actual data structure. On encoding the dictionary is prepended this way, then initial array byte and dictionary array are removed, leaving only relevant data structure (so if it happens it has no repeated strings from dictionary, it will be just equal to as encoded without all these complexities). On decoding, initial array byte and encoded dictionary array are prepened to CBOR BLOB, and then `decode_cbor($constructed_blob)->[1]` is returned.

The dictionary array of strings is obtained by:

```sql
SELECT name FROM attribute_name ORDER BY id LIMIT (
    SELECT value FROM db_settings WHERE param = 'cbor_dict_limit'
)
```

The limit is here as it takes memory to hash all dictionary strings, which can be unacceptable when database grows too large.

# TODO / TBD

unseen / unread / read @ time, to see new edits ...or just ctime?

refetch_access_lost for not deleted but bans?

on object splitting, how to find an INT id for reference to? create a way to have SHA256 of object?

variant: at INSERT populate `additional_section` (? a-la DNS ? or `outgoing_edge` ?) with links to object (concrete versions) to return with this, e.g. for `user` together with `message`; as Telegram returns users and chats
...but, querying and returning `chats` for every message could be expensive, and caller likely to have it in memory cache already
- still should be done for mentioned chats, however (not that which it belongs to)
- what with using this for compound objects? e.g. a local comment to picture will find picture by this, but what if there are too many messages referring to this picture?
- about name "compound object", should it be really used for "photo of different sizes" or "video + thumbnail? may be "package" ?

ipath=NULL for metadata

not inode, but versions also in tree, so distinguish tree children and attributes like XML/DOM ?

move `from_peer` in front of tree? this would be consistent with e.g. Telegram's "common box" messages, which are enumerated per-account - but conflicts with `unread` being per-message, not per-version... though it's interesting idea, what if received version differs from what was read? the same problem with edited messages, BTW

...looks like need a table, one or more columns of it itself a path/tree - that is, not a "table inside a tree ['s node]", but a "tree (or more) inside a table" ?

the concept of FS-like tree and inodes was for hardlinks - e.g. `Telegram/commonbox/712345` and `Telegram/Chat/123/712345` is in fact the same message, as well as `Telegram/commonbox/712346` and `Telegram/User/456/712346` are also the same, due to continuous numeration of messages in old chats and private dialogs in Telegram

also, single tree is a natural fit for MQTT topics, for splitting by path to different DB shards, and for DB object browser with standard Tree Control widgets, Regedit-like - though latter possibly may be tree+table...

may be don't give any real sense to inode? i.e. just JOIN on it and nothing more?
