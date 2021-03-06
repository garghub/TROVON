int zlib_deflateInit2(
z_streamp strm,
int level,
int method,
int windowBits,
int memLevel,
int strategy
)
{
deflate_state *s;
int noheader = 0;
deflate_workspace *mem;
char *next;
ush *overlay;
if (strm == NULL) return Z_STREAM_ERROR;
strm->msg = NULL;
if (level == Z_DEFAULT_COMPRESSION) level = 6;
mem = (deflate_workspace *) strm->workspace;
if (windowBits < 0) {
noheader = 1;
windowBits = -windowBits;
}
if (memLevel < 1 || memLevel > MAX_MEM_LEVEL || method != Z_DEFLATED ||
windowBits < 9 || windowBits > 15 || level < 0 || level > 9 ||
strategy < 0 || strategy > Z_HUFFMAN_ONLY) {
return Z_STREAM_ERROR;
}
next = (char *) mem;
next += sizeof(*mem);
mem->window_memory = (Byte *) next;
next += zlib_deflate_window_memsize(windowBits);
mem->prev_memory = (Pos *) next;
next += zlib_deflate_prev_memsize(windowBits);
mem->head_memory = (Pos *) next;
next += zlib_deflate_head_memsize(memLevel);
mem->overlay_memory = next;
s = (deflate_state *) &(mem->deflate_memory);
strm->state = (struct internal_state *)s;
s->strm = strm;
s->noheader = noheader;
s->w_bits = windowBits;
s->w_size = 1 << s->w_bits;
s->w_mask = s->w_size - 1;
s->hash_bits = memLevel + 7;
s->hash_size = 1 << s->hash_bits;
s->hash_mask = s->hash_size - 1;
s->hash_shift = ((s->hash_bits+MIN_MATCH-1)/MIN_MATCH);
s->window = (Byte *) mem->window_memory;
s->prev = (Pos *) mem->prev_memory;
s->head = (Pos *) mem->head_memory;
s->lit_bufsize = 1 << (memLevel + 6);
overlay = (ush *) mem->overlay_memory;
s->pending_buf = (uch *) overlay;
s->pending_buf_size = (ulg)s->lit_bufsize * (sizeof(ush)+2L);
s->d_buf = overlay + s->lit_bufsize/sizeof(ush);
s->l_buf = s->pending_buf + (1+sizeof(ush))*s->lit_bufsize;
s->level = level;
s->strategy = strategy;
s->method = (Byte)method;
return zlib_deflateReset(strm);
}
int zlib_deflateReset(
z_streamp strm
)
{
deflate_state *s;
if (strm == NULL || strm->state == NULL)
return Z_STREAM_ERROR;
strm->total_in = strm->total_out = 0;
strm->msg = NULL;
strm->data_type = Z_UNKNOWN;
s = (deflate_state *)strm->state;
s->pending = 0;
s->pending_out = s->pending_buf;
if (s->noheader < 0) {
s->noheader = 0;
}
s->status = s->noheader ? BUSY_STATE : INIT_STATE;
strm->adler = 1;
s->last_flush = Z_NO_FLUSH;
zlib_tr_init(s);
lm_init(s);
return Z_OK;
}
static void putShortMSB(
deflate_state *s,
uInt b
)
{
put_byte(s, (Byte)(b >> 8));
put_byte(s, (Byte)(b & 0xff));
}
static void flush_pending(
z_streamp strm
)
{
deflate_state *s = (deflate_state *) strm->state;
unsigned len = s->pending;
if (len > strm->avail_out) len = strm->avail_out;
if (len == 0) return;
if (strm->next_out != NULL) {
memcpy(strm->next_out, s->pending_out, len);
strm->next_out += len;
}
s->pending_out += len;
strm->total_out += len;
strm->avail_out -= len;
s->pending -= len;
if (s->pending == 0) {
s->pending_out = s->pending_buf;
}
}
int zlib_deflate(
z_streamp strm,
int flush
)
{
int old_flush;
deflate_state *s;
if (strm == NULL || strm->state == NULL ||
flush > Z_FINISH || flush < 0) {
return Z_STREAM_ERROR;
}
s = (deflate_state *) strm->state;
if ((strm->next_in == NULL && strm->avail_in != 0) ||
(s->status == FINISH_STATE && flush != Z_FINISH)) {
return Z_STREAM_ERROR;
}
if (strm->avail_out == 0) return Z_BUF_ERROR;
s->strm = strm;
old_flush = s->last_flush;
s->last_flush = flush;
if (s->status == INIT_STATE) {
uInt header = (Z_DEFLATED + ((s->w_bits-8)<<4)) << 8;
uInt level_flags = (s->level-1) >> 1;
if (level_flags > 3) level_flags = 3;
header |= (level_flags << 6);
if (s->strstart != 0) header |= PRESET_DICT;
header += 31 - (header % 31);
s->status = BUSY_STATE;
putShortMSB(s, header);
if (s->strstart != 0) {
putShortMSB(s, (uInt)(strm->adler >> 16));
putShortMSB(s, (uInt)(strm->adler & 0xffff));
}
strm->adler = 1L;
}
if (s->pending != 0) {
flush_pending(strm);
if (strm->avail_out == 0) {
s->last_flush = -1;
return Z_OK;
}
} else if (strm->avail_in == 0 && flush <= old_flush &&
flush != Z_FINISH) {
return Z_BUF_ERROR;
}
if (s->status == FINISH_STATE && strm->avail_in != 0) {
return Z_BUF_ERROR;
}
if (strm->avail_in != 0 || s->lookahead != 0 ||
(flush != Z_NO_FLUSH && s->status != FINISH_STATE)) {
block_state bstate;
bstate = (*(configuration_table[s->level].func))(s, flush);
if (bstate == finish_started || bstate == finish_done) {
s->status = FINISH_STATE;
}
if (bstate == need_more || bstate == finish_started) {
if (strm->avail_out == 0) {
s->last_flush = -1;
}
return Z_OK;
}
if (bstate == block_done) {
if (flush == Z_PARTIAL_FLUSH) {
zlib_tr_align(s);
} else if (flush == Z_PACKET_FLUSH) {
zlib_tr_stored_type_only(s);
} else {
zlib_tr_stored_block(s, (char*)0, 0L, 0);
if (flush == Z_FULL_FLUSH) {
CLEAR_HASH(s);
}
}
flush_pending(strm);
if (strm->avail_out == 0) {
s->last_flush = -1;
return Z_OK;
}
}
}
Assert(strm->avail_out > 0, "bug2");
if (flush != Z_FINISH) return Z_OK;
if (s->noheader) return Z_STREAM_END;
putShortMSB(s, (uInt)(strm->adler >> 16));
putShortMSB(s, (uInt)(strm->adler & 0xffff));
flush_pending(strm);
s->noheader = -1;
return s->pending != 0 ? Z_OK : Z_STREAM_END;
}
int zlib_deflateEnd(
z_streamp strm
)
{
int status;
deflate_state *s;
if (strm == NULL || strm->state == NULL) return Z_STREAM_ERROR;
s = (deflate_state *) strm->state;
status = s->status;
if (status != INIT_STATE && status != BUSY_STATE &&
status != FINISH_STATE) {
return Z_STREAM_ERROR;
}
strm->state = NULL;
return status == BUSY_STATE ? Z_DATA_ERROR : Z_OK;
}
static int read_buf(
z_streamp strm,
Byte *buf,
unsigned size
)
{
unsigned len = strm->avail_in;
if (len > size) len = size;
if (len == 0) return 0;
strm->avail_in -= len;
if (!((deflate_state *)(strm->state))->noheader) {
strm->adler = zlib_adler32(strm->adler, strm->next_in, len);
}
memcpy(buf, strm->next_in, len);
strm->next_in += len;
strm->total_in += len;
return (int)len;
}
static void lm_init(
deflate_state *s
)
{
s->window_size = (ulg)2L*s->w_size;
CLEAR_HASH(s);
s->max_lazy_match = configuration_table[s->level].max_lazy;
s->good_match = configuration_table[s->level].good_length;
s->nice_match = configuration_table[s->level].nice_length;
s->max_chain_length = configuration_table[s->level].max_chain;
s->strstart = 0;
s->block_start = 0L;
s->lookahead = 0;
s->match_length = s->prev_length = MIN_MATCH-1;
s->match_available = 0;
s->ins_h = 0;
}
static uInt longest_match(
deflate_state *s,
IPos cur_match
)
{
unsigned chain_length = s->max_chain_length;
register Byte *scan = s->window + s->strstart;
register Byte *match;
register int len;
int best_len = s->prev_length;
int nice_match = s->nice_match;
IPos limit = s->strstart > (IPos)MAX_DIST(s) ?
s->strstart - (IPos)MAX_DIST(s) : NIL;
Pos *prev = s->prev;
uInt wmask = s->w_mask;
#ifdef UNALIGNED_OK
register Byte *strend = s->window + s->strstart + MAX_MATCH - 1;
register ush scan_start = *(ush*)scan;
register ush scan_end = *(ush*)(scan+best_len-1);
#else
register Byte *strend = s->window + s->strstart + MAX_MATCH;
register Byte scan_end1 = scan[best_len-1];
register Byte scan_end = scan[best_len];
#endif
Assert(s->hash_bits >= 8 && MAX_MATCH == 258, "Code too clever");
if (s->prev_length >= s->good_match) {
chain_length >>= 2;
}
if ((uInt)nice_match > s->lookahead) nice_match = s->lookahead;
Assert((ulg)s->strstart <= s->window_size-MIN_LOOKAHEAD, "need lookahead");
do {
Assert(cur_match < s->strstart, "no future");
match = s->window + cur_match;
#if (defined(UNALIGNED_OK) && MAX_MATCH == 258)
if (*(ush*)(match+best_len-1) != scan_end ||
*(ush*)match != scan_start) continue;
Assert(scan[2] == match[2], "scan[2]?");
scan++, match++;
do {
} while (*(ush*)(scan+=2) == *(ush*)(match+=2) &&
*(ush*)(scan+=2) == *(ush*)(match+=2) &&
*(ush*)(scan+=2) == *(ush*)(match+=2) &&
*(ush*)(scan+=2) == *(ush*)(match+=2) &&
scan < strend);
Assert(scan <= s->window+(unsigned)(s->window_size-1), "wild scan");
if (*scan == *match) scan++;
len = (MAX_MATCH - 1) - (int)(strend-scan);
scan = strend - (MAX_MATCH-1);
#else
if (match[best_len] != scan_end ||
match[best_len-1] != scan_end1 ||
*match != *scan ||
*++match != scan[1]) continue;
scan += 2, match++;
Assert(*scan == *match, "match[2]?");
do {
} while (*++scan == *++match && *++scan == *++match &&
*++scan == *++match && *++scan == *++match &&
*++scan == *++match && *++scan == *++match &&
*++scan == *++match && *++scan == *++match &&
scan < strend);
Assert(scan <= s->window+(unsigned)(s->window_size-1), "wild scan");
len = MAX_MATCH - (int)(strend - scan);
scan = strend - MAX_MATCH;
#endif
if (len > best_len) {
s->match_start = cur_match;
best_len = len;
if (len >= nice_match) break;
#ifdef UNALIGNED_OK
scan_end = *(ush*)(scan+best_len-1);
#else
scan_end1 = scan[best_len-1];
scan_end = scan[best_len];
#endif
}
} while ((cur_match = prev[cur_match & wmask]) > limit
&& --chain_length != 0);
if ((uInt)best_len <= s->lookahead) return best_len;
return s->lookahead;
}
static void check_match(
deflate_state *s,
IPos start,
IPos match,
int length
)
{
if (memcmp((char *)s->window + match,
(char *)s->window + start, length) != EQUAL) {
fprintf(stderr, " start %u, match %u, length %d\n",
start, match, length);
do {
fprintf(stderr, "%c%c", s->window[match++], s->window[start++]);
} while (--length != 0);
z_error("invalid match");
}
if (z_verbose > 1) {
fprintf(stderr,"\\[%d,%d]", start-match, length);
do { putc(s->window[start++], stderr); } while (--length != 0);
}
}
static void fill_window(
deflate_state *s
)
{
register unsigned n, m;
register Pos *p;
unsigned more;
uInt wsize = s->w_size;
do {
more = (unsigned)(s->window_size -(ulg)s->lookahead -(ulg)s->strstart);
if (more == 0 && s->strstart == 0 && s->lookahead == 0) {
more = wsize;
} else if (more == (unsigned)(-1)) {
more--;
} else if (s->strstart >= wsize+MAX_DIST(s)) {
memcpy((char *)s->window, (char *)s->window+wsize,
(unsigned)wsize);
s->match_start -= wsize;
s->strstart -= wsize;
s->block_start -= (long) wsize;
n = s->hash_size;
p = &s->head[n];
do {
m = *--p;
*p = (Pos)(m >= wsize ? m-wsize : NIL);
} while (--n);
n = wsize;
p = &s->prev[n];
do {
m = *--p;
*p = (Pos)(m >= wsize ? m-wsize : NIL);
} while (--n);
more += wsize;
}
if (s->strm->avail_in == 0) return;
Assert(more >= 2, "more < 2");
n = read_buf(s->strm, s->window + s->strstart + s->lookahead, more);
s->lookahead += n;
if (s->lookahead >= MIN_MATCH) {
s->ins_h = s->window[s->strstart];
UPDATE_HASH(s, s->ins_h, s->window[s->strstart+1]);
#if MIN_MATCH != 3
Call UPDATE_HASH() MIN_MATCH-3 more times
#endif
}
} while (s->lookahead < MIN_LOOKAHEAD && s->strm->avail_in != 0);
}
static block_state deflate_stored(
deflate_state *s,
int flush
)
{
ulg max_block_size = 0xffff;
ulg max_start;
if (max_block_size > s->pending_buf_size - 5) {
max_block_size = s->pending_buf_size - 5;
}
for (;;) {
if (s->lookahead <= 1) {
Assert(s->strstart < s->w_size+MAX_DIST(s) ||
s->block_start >= (long)s->w_size, "slide too late");
fill_window(s);
if (s->lookahead == 0 && flush == Z_NO_FLUSH) return need_more;
if (s->lookahead == 0) break;
}
Assert(s->block_start >= 0L, "block gone");
s->strstart += s->lookahead;
s->lookahead = 0;
max_start = s->block_start + max_block_size;
if (s->strstart == 0 || (ulg)s->strstart >= max_start) {
s->lookahead = (uInt)(s->strstart - max_start);
s->strstart = (uInt)max_start;
FLUSH_BLOCK(s, 0);
}
if (s->strstart - (uInt)s->block_start >= MAX_DIST(s)) {
FLUSH_BLOCK(s, 0);
}
}
FLUSH_BLOCK(s, flush == Z_FINISH);
return flush == Z_FINISH ? finish_done : block_done;
}
static block_state deflate_fast(
deflate_state *s,
int flush
)
{
IPos hash_head = NIL;
int bflush;
for (;;) {
if (s->lookahead < MIN_LOOKAHEAD) {
fill_window(s);
if (s->lookahead < MIN_LOOKAHEAD && flush == Z_NO_FLUSH) {
return need_more;
}
if (s->lookahead == 0) break;
}
if (s->lookahead >= MIN_MATCH) {
INSERT_STRING(s, s->strstart, hash_head);
}
if (hash_head != NIL && s->strstart - hash_head <= MAX_DIST(s)) {
if (s->strategy != Z_HUFFMAN_ONLY) {
s->match_length = longest_match (s, hash_head);
}
}
if (s->match_length >= MIN_MATCH) {
check_match(s, s->strstart, s->match_start, s->match_length);
bflush = zlib_tr_tally(s, s->strstart - s->match_start,
s->match_length - MIN_MATCH);
s->lookahead -= s->match_length;
if (s->match_length <= s->max_insert_length &&
s->lookahead >= MIN_MATCH) {
s->match_length--;
do {
s->strstart++;
INSERT_STRING(s, s->strstart, hash_head);
} while (--s->match_length != 0);
s->strstart++;
} else {
s->strstart += s->match_length;
s->match_length = 0;
s->ins_h = s->window[s->strstart];
UPDATE_HASH(s, s->ins_h, s->window[s->strstart+1]);
#if MIN_MATCH != 3
Call UPDATE_HASH() MIN_MATCH-3 more times
#endif
}
} else {
Tracevv((stderr,"%c", s->window[s->strstart]));
bflush = zlib_tr_tally (s, 0, s->window[s->strstart]);
s->lookahead--;
s->strstart++;
}
if (bflush) FLUSH_BLOCK(s, 0);
}
FLUSH_BLOCK(s, flush == Z_FINISH);
return flush == Z_FINISH ? finish_done : block_done;
}
static block_state deflate_slow(
deflate_state *s,
int flush
)
{
IPos hash_head = NIL;
int bflush;
for (;;) {
if (s->lookahead < MIN_LOOKAHEAD) {
fill_window(s);
if (s->lookahead < MIN_LOOKAHEAD && flush == Z_NO_FLUSH) {
return need_more;
}
if (s->lookahead == 0) break;
}
if (s->lookahead >= MIN_MATCH) {
INSERT_STRING(s, s->strstart, hash_head);
}
s->prev_length = s->match_length, s->prev_match = s->match_start;
s->match_length = MIN_MATCH-1;
if (hash_head != NIL && s->prev_length < s->max_lazy_match &&
s->strstart - hash_head <= MAX_DIST(s)) {
if (s->strategy != Z_HUFFMAN_ONLY) {
s->match_length = longest_match (s, hash_head);
}
if (s->match_length <= 5 && (s->strategy == Z_FILTERED ||
(s->match_length == MIN_MATCH &&
s->strstart - s->match_start > TOO_FAR))) {
s->match_length = MIN_MATCH-1;
}
}
if (s->prev_length >= MIN_MATCH && s->match_length <= s->prev_length) {
uInt max_insert = s->strstart + s->lookahead - MIN_MATCH;
check_match(s, s->strstart-1, s->prev_match, s->prev_length);
bflush = zlib_tr_tally(s, s->strstart -1 - s->prev_match,
s->prev_length - MIN_MATCH);
s->lookahead -= s->prev_length-1;
s->prev_length -= 2;
do {
if (++s->strstart <= max_insert) {
INSERT_STRING(s, s->strstart, hash_head);
}
} while (--s->prev_length != 0);
s->match_available = 0;
s->match_length = MIN_MATCH-1;
s->strstart++;
if (bflush) FLUSH_BLOCK(s, 0);
} else if (s->match_available) {
Tracevv((stderr,"%c", s->window[s->strstart-1]));
if (zlib_tr_tally (s, 0, s->window[s->strstart-1])) {
FLUSH_BLOCK_ONLY(s, 0);
}
s->strstart++;
s->lookahead--;
if (s->strm->avail_out == 0) return need_more;
} else {
s->match_available = 1;
s->strstart++;
s->lookahead--;
}
}
Assert (flush != Z_NO_FLUSH, "no flush?");
if (s->match_available) {
Tracevv((stderr,"%c", s->window[s->strstart-1]));
zlib_tr_tally (s, 0, s->window[s->strstart-1]);
s->match_available = 0;
}
FLUSH_BLOCK(s, flush == Z_FINISH);
return flush == Z_FINISH ? finish_done : block_done;
}
int zlib_deflate_workspacesize(int windowBits, int memLevel)
{
if (windowBits < 0)
windowBits = -windowBits;
BUG_ON(memLevel < 1 || memLevel > MAX_MEM_LEVEL || windowBits < 9 ||
windowBits > 15);
return sizeof(deflate_workspace)
+ zlib_deflate_window_memsize(windowBits)
+ zlib_deflate_prev_memsize(windowBits)
+ zlib_deflate_head_memsize(memLevel)
+ zlib_deflate_overlay_memsize(memLevel);
}
