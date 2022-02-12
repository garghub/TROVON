static void send_bits(
deflate_state *s,
int value,
int length
)
{
Tracevv((stderr," l %2d v %4x ", length, value));
Assert(length > 0 && length <= 15, "invalid length");
s->bits_sent += (ulg)length;
if (s->bi_valid > (int)Buf_size - length) {
s->bi_buf |= (value << s->bi_valid);
put_short(s, s->bi_buf);
s->bi_buf = (ush)value >> (Buf_size - s->bi_valid);
s->bi_valid += length - Buf_size;
} else {
s->bi_buf |= value << s->bi_valid;
s->bi_valid += length;
}
}
static void tr_static_init(void)
{
static int static_init_done;
int n;
int bits;
int length;
int code;
int dist;
ush bl_count[MAX_BITS+1];
if (static_init_done) return;
length = 0;
for (code = 0; code < LENGTH_CODES-1; code++) {
base_length[code] = length;
for (n = 0; n < (1<<extra_lbits[code]); n++) {
length_code[length++] = (uch)code;
}
}
Assert (length == 256, "tr_static_init: length != 256");
length_code[length-1] = (uch)code;
dist = 0;
for (code = 0 ; code < 16; code++) {
base_dist[code] = dist;
for (n = 0; n < (1<<extra_dbits[code]); n++) {
dist_code[dist++] = (uch)code;
}
}
Assert (dist == 256, "tr_static_init: dist != 256");
dist >>= 7;
for ( ; code < D_CODES; code++) {
base_dist[code] = dist << 7;
for (n = 0; n < (1<<(extra_dbits[code]-7)); n++) {
dist_code[256 + dist++] = (uch)code;
}
}
Assert (dist == 256, "tr_static_init: 256+dist != 512");
for (bits = 0; bits <= MAX_BITS; bits++) bl_count[bits] = 0;
n = 0;
while (n <= 143) static_ltree[n++].Len = 8, bl_count[8]++;
while (n <= 255) static_ltree[n++].Len = 9, bl_count[9]++;
while (n <= 279) static_ltree[n++].Len = 7, bl_count[7]++;
while (n <= 287) static_ltree[n++].Len = 8, bl_count[8]++;
gen_codes((ct_data *)static_ltree, L_CODES+1, bl_count);
for (n = 0; n < D_CODES; n++) {
static_dtree[n].Len = 5;
static_dtree[n].Code = bitrev32((u32)n) >> (32 - 5);
}
static_init_done = 1;
}
void zlib_tr_init(
deflate_state *s
)
{
tr_static_init();
s->compressed_len = 0L;
s->l_desc.dyn_tree = s->dyn_ltree;
s->l_desc.stat_desc = &static_l_desc;
s->d_desc.dyn_tree = s->dyn_dtree;
s->d_desc.stat_desc = &static_d_desc;
s->bl_desc.dyn_tree = s->bl_tree;
s->bl_desc.stat_desc = &static_bl_desc;
s->bi_buf = 0;
s->bi_valid = 0;
s->last_eob_len = 8;
#ifdef DEBUG_ZLIB
s->bits_sent = 0L;
#endif
init_block(s);
}
static void init_block(
deflate_state *s
)
{
int n;
for (n = 0; n < L_CODES; n++) s->dyn_ltree[n].Freq = 0;
for (n = 0; n < D_CODES; n++) s->dyn_dtree[n].Freq = 0;
for (n = 0; n < BL_CODES; n++) s->bl_tree[n].Freq = 0;
s->dyn_ltree[END_BLOCK].Freq = 1;
s->opt_len = s->static_len = 0L;
s->last_lit = s->matches = 0;
}
static void pqdownheap(
deflate_state *s,
ct_data *tree,
int k
)
{
int v = s->heap[k];
int j = k << 1;
while (j <= s->heap_len) {
if (j < s->heap_len &&
smaller(tree, s->heap[j+1], s->heap[j], s->depth)) {
j++;
}
if (smaller(tree, v, s->heap[j], s->depth)) break;
s->heap[k] = s->heap[j]; k = j;
j <<= 1;
}
s->heap[k] = v;
}
static void gen_bitlen(
deflate_state *s,
tree_desc *desc
)
{
ct_data *tree = desc->dyn_tree;
int max_code = desc->max_code;
const ct_data *stree = desc->stat_desc->static_tree;
const int *extra = desc->stat_desc->extra_bits;
int base = desc->stat_desc->extra_base;
int max_length = desc->stat_desc->max_length;
int h;
int n, m;
int bits;
int xbits;
ush f;
int overflow = 0;
for (bits = 0; bits <= MAX_BITS; bits++) s->bl_count[bits] = 0;
tree[s->heap[s->heap_max]].Len = 0;
for (h = s->heap_max+1; h < HEAP_SIZE; h++) {
n = s->heap[h];
bits = tree[tree[n].Dad].Len + 1;
if (bits > max_length) bits = max_length, overflow++;
tree[n].Len = (ush)bits;
if (n > max_code) continue;
s->bl_count[bits]++;
xbits = 0;
if (n >= base) xbits = extra[n-base];
f = tree[n].Freq;
s->opt_len += (ulg)f * (bits + xbits);
if (stree) s->static_len += (ulg)f * (stree[n].Len + xbits);
}
if (overflow == 0) return;
Trace((stderr,"\nbit length overflow\n"));
do {
bits = max_length-1;
while (s->bl_count[bits] == 0) bits--;
s->bl_count[bits]--;
s->bl_count[bits+1] += 2;
s->bl_count[max_length]--;
overflow -= 2;
} while (overflow > 0);
for (bits = max_length; bits != 0; bits--) {
n = s->bl_count[bits];
while (n != 0) {
m = s->heap[--h];
if (m > max_code) continue;
if (tree[m].Len != (unsigned) bits) {
Trace((stderr,"code %d bits %d->%d\n", m, tree[m].Len, bits));
s->opt_len += ((long)bits - (long)tree[m].Len)
*(long)tree[m].Freq;
tree[m].Len = (ush)bits;
}
n--;
}
}
}
static void gen_codes(
ct_data *tree,
int max_code,
ush *bl_count
)
{
ush next_code[MAX_BITS+1];
ush code = 0;
int bits;
int n;
for (bits = 1; bits <= MAX_BITS; bits++) {
next_code[bits] = code = (code + bl_count[bits-1]) << 1;
}
Assert (code + bl_count[MAX_BITS]-1 == (1<<MAX_BITS)-1,
"inconsistent bit counts");
Tracev((stderr,"\ngen_codes: max_code %d ", max_code));
for (n = 0; n <= max_code; n++) {
int len = tree[n].Len;
if (len == 0) continue;
tree[n].Code = bitrev32((u32)(next_code[len]++)) >> (32 - len);
Tracecv(tree != static_ltree, (stderr,"\nn %3d %c l %2d c %4x (%x) ",
n, (isgraph(n) ? n : ' '), len, tree[n].Code, next_code[len]-1));
}
}
static void build_tree(
deflate_state *s,
tree_desc *desc
)
{
ct_data *tree = desc->dyn_tree;
const ct_data *stree = desc->stat_desc->static_tree;
int elems = desc->stat_desc->elems;
int n, m;
int max_code = -1;
int node;
s->heap_len = 0, s->heap_max = HEAP_SIZE;
for (n = 0; n < elems; n++) {
if (tree[n].Freq != 0) {
s->heap[++(s->heap_len)] = max_code = n;
s->depth[n] = 0;
} else {
tree[n].Len = 0;
}
}
while (s->heap_len < 2) {
node = s->heap[++(s->heap_len)] = (max_code < 2 ? ++max_code : 0);
tree[node].Freq = 1;
s->depth[node] = 0;
s->opt_len--; if (stree) s->static_len -= stree[node].Len;
}
desc->max_code = max_code;
for (n = s->heap_len/2; n >= 1; n--) pqdownheap(s, tree, n);
node = elems;
do {
pqremove(s, tree, n);
m = s->heap[SMALLEST];
s->heap[--(s->heap_max)] = n;
s->heap[--(s->heap_max)] = m;
tree[node].Freq = tree[n].Freq + tree[m].Freq;
s->depth[node] = (uch) (max(s->depth[n], s->depth[m]) + 1);
tree[n].Dad = tree[m].Dad = (ush)node;
#ifdef DUMP_BL_TREE
if (tree == s->bl_tree) {
fprintf(stderr,"\nnode %d(%d), sons %d(%d) %d(%d)",
node, tree[node].Freq, n, tree[n].Freq, m, tree[m].Freq);
}
#endif
s->heap[SMALLEST] = node++;
pqdownheap(s, tree, SMALLEST);
} while (s->heap_len >= 2);
s->heap[--(s->heap_max)] = s->heap[SMALLEST];
gen_bitlen(s, (tree_desc *)desc);
gen_codes ((ct_data *)tree, max_code, s->bl_count);
}
static void scan_tree(
deflate_state *s,
ct_data *tree,
int max_code
)
{
int n;
int prevlen = -1;
int curlen;
int nextlen = tree[0].Len;
int count = 0;
int max_count = 7;
int min_count = 4;
if (nextlen == 0) max_count = 138, min_count = 3;
tree[max_code+1].Len = (ush)0xffff;
for (n = 0; n <= max_code; n++) {
curlen = nextlen; nextlen = tree[n+1].Len;
if (++count < max_count && curlen == nextlen) {
continue;
} else if (count < min_count) {
s->bl_tree[curlen].Freq += count;
} else if (curlen != 0) {
if (curlen != prevlen) s->bl_tree[curlen].Freq++;
s->bl_tree[REP_3_6].Freq++;
} else if (count <= 10) {
s->bl_tree[REPZ_3_10].Freq++;
} else {
s->bl_tree[REPZ_11_138].Freq++;
}
count = 0; prevlen = curlen;
if (nextlen == 0) {
max_count = 138, min_count = 3;
} else if (curlen == nextlen) {
max_count = 6, min_count = 3;
} else {
max_count = 7, min_count = 4;
}
}
}
static void send_tree(
deflate_state *s,
ct_data *tree,
int max_code
)
{
int n;
int prevlen = -1;
int curlen;
int nextlen = tree[0].Len;
int count = 0;
int max_count = 7;
int min_count = 4;
if (nextlen == 0) max_count = 138, min_count = 3;
for (n = 0; n <= max_code; n++) {
curlen = nextlen; nextlen = tree[n+1].Len;
if (++count < max_count && curlen == nextlen) {
continue;
} else if (count < min_count) {
do { send_code(s, curlen, s->bl_tree); } while (--count != 0);
} else if (curlen != 0) {
if (curlen != prevlen) {
send_code(s, curlen, s->bl_tree); count--;
}
Assert(count >= 3 && count <= 6, " 3_6?");
send_code(s, REP_3_6, s->bl_tree); send_bits(s, count-3, 2);
} else if (count <= 10) {
send_code(s, REPZ_3_10, s->bl_tree); send_bits(s, count-3, 3);
} else {
send_code(s, REPZ_11_138, s->bl_tree); send_bits(s, count-11, 7);
}
count = 0; prevlen = curlen;
if (nextlen == 0) {
max_count = 138, min_count = 3;
} else if (curlen == nextlen) {
max_count = 6, min_count = 3;
} else {
max_count = 7, min_count = 4;
}
}
}
static int build_bl_tree(
deflate_state *s
)
{
int max_blindex;
scan_tree(s, (ct_data *)s->dyn_ltree, s->l_desc.max_code);
scan_tree(s, (ct_data *)s->dyn_dtree, s->d_desc.max_code);
build_tree(s, (tree_desc *)(&(s->bl_desc)));
for (max_blindex = BL_CODES-1; max_blindex >= 3; max_blindex--) {
if (s->bl_tree[bl_order[max_blindex]].Len != 0) break;
}
s->opt_len += 3*(max_blindex+1) + 5+5+4;
Tracev((stderr, "\ndyn trees: dyn %ld, stat %ld",
s->opt_len, s->static_len));
return max_blindex;
}
static void send_all_trees(
deflate_state *s,
int lcodes,
int dcodes,
int blcodes
)
{
int rank;
Assert (lcodes >= 257 && dcodes >= 1 && blcodes >= 4, "not enough codes");
Assert (lcodes <= L_CODES && dcodes <= D_CODES && blcodes <= BL_CODES,
"too many codes");
Tracev((stderr, "\nbl counts: "));
send_bits(s, lcodes-257, 5);
send_bits(s, dcodes-1, 5);
send_bits(s, blcodes-4, 4);
for (rank = 0; rank < blcodes; rank++) {
Tracev((stderr, "\nbl code %2d ", bl_order[rank]));
send_bits(s, s->bl_tree[bl_order[rank]].Len, 3);
}
Tracev((stderr, "\nbl tree: sent %ld", s->bits_sent));
send_tree(s, (ct_data *)s->dyn_ltree, lcodes-1);
Tracev((stderr, "\nlit tree: sent %ld", s->bits_sent));
send_tree(s, (ct_data *)s->dyn_dtree, dcodes-1);
Tracev((stderr, "\ndist tree: sent %ld", s->bits_sent));
}
void zlib_tr_stored_block(
deflate_state *s,
char *buf,
ulg stored_len,
int eof
)
{
send_bits(s, (STORED_BLOCK<<1)+eof, 3);
s->compressed_len = (s->compressed_len + 3 + 7) & (ulg)~7L;
s->compressed_len += (stored_len + 4) << 3;
copy_block(s, buf, (unsigned)stored_len, 1);
}
void zlib_tr_stored_type_only(
deflate_state *s
)
{
send_bits(s, (STORED_BLOCK << 1), 3);
bi_windup(s);
s->compressed_len = (s->compressed_len + 3) & ~7L;
}
void zlib_tr_align(
deflate_state *s
)
{
send_bits(s, STATIC_TREES<<1, 3);
send_code(s, END_BLOCK, static_ltree);
s->compressed_len += 10L;
bi_flush(s);
if (1 + s->last_eob_len + 10 - s->bi_valid < 9) {
send_bits(s, STATIC_TREES<<1, 3);
send_code(s, END_BLOCK, static_ltree);
s->compressed_len += 10L;
bi_flush(s);
}
s->last_eob_len = 7;
}
int zlib_tr_tally(
deflate_state *s,
unsigned dist,
unsigned lc
)
{
s->d_buf[s->last_lit] = (ush)dist;
s->l_buf[s->last_lit++] = (uch)lc;
if (dist == 0) {
s->dyn_ltree[lc].Freq++;
} else {
s->matches++;
dist--;
Assert((ush)dist < (ush)MAX_DIST(s) &&
(ush)lc <= (ush)(MAX_MATCH-MIN_MATCH) &&
(ush)d_code(dist) < (ush)D_CODES, "zlib_tr_tally: bad match");
s->dyn_ltree[length_code[lc]+LITERALS+1].Freq++;
s->dyn_dtree[d_code(dist)].Freq++;
}
if ((s->last_lit & 0xfff) == 0 && s->level > 2) {
ulg out_length = (ulg)s->last_lit*8L;
ulg in_length = (ulg)((long)s->strstart - s->block_start);
int dcode;
for (dcode = 0; dcode < D_CODES; dcode++) {
out_length += (ulg)s->dyn_dtree[dcode].Freq *
(5L+extra_dbits[dcode]);
}
out_length >>= 3;
Tracev((stderr,"\nlast_lit %u, in %ld, out ~%ld(%ld%%) ",
s->last_lit, in_length, out_length,
100L - out_length*100L/in_length));
if (s->matches < s->last_lit/2 && out_length < in_length/2) return 1;
}
return (s->last_lit == s->lit_bufsize-1);
}
static void compress_block(
deflate_state *s,
ct_data *ltree,
ct_data *dtree
)
{
unsigned dist;
int lc;
unsigned lx = 0;
unsigned code;
int extra;
if (s->last_lit != 0) do {
dist = s->d_buf[lx];
lc = s->l_buf[lx++];
if (dist == 0) {
send_code(s, lc, ltree);
Tracecv(isgraph(lc), (stderr," '%c' ", lc));
} else {
code = length_code[lc];
send_code(s, code+LITERALS+1, ltree);
extra = extra_lbits[code];
if (extra != 0) {
lc -= base_length[code];
send_bits(s, lc, extra);
}
dist--;
code = d_code(dist);
Assert (code < D_CODES, "bad d_code");
send_code(s, code, dtree);
extra = extra_dbits[code];
if (extra != 0) {
dist -= base_dist[code];
send_bits(s, dist, extra);
}
}
Assert(s->pending < s->lit_bufsize + 2*lx, "pendingBuf overflow");
} while (lx < s->last_lit);
send_code(s, END_BLOCK, ltree);
s->last_eob_len = ltree[END_BLOCK].Len;
}
static void set_data_type(
deflate_state *s
)
{
int n = 0;
unsigned ascii_freq = 0;
unsigned bin_freq = 0;
while (n < 7) bin_freq += s->dyn_ltree[n++].Freq;
while (n < 128) ascii_freq += s->dyn_ltree[n++].Freq;
while (n < LITERALS) bin_freq += s->dyn_ltree[n++].Freq;
s->data_type = (Byte)(bin_freq > (ascii_freq >> 2) ? Z_BINARY : Z_ASCII);
}
static void copy_block(
deflate_state *s,
char *buf,
unsigned len,
int header
)
{
bi_windup(s);
s->last_eob_len = 8;
if (header) {
put_short(s, (ush)len);
put_short(s, (ush)~len);
#ifdef DEBUG_ZLIB
s->bits_sent += 2*16;
#endif
}
#ifdef DEBUG_ZLIB
s->bits_sent += (ulg)len<<3;
#endif
memcpy(&s->pending_buf[s->pending], buf, len);
s->pending += len;
}
