static ssize_t huff_encode_sym(nghttp2_bufs *bufs, size_t *avail_ptr,
size_t rembits,
const nghttp2_huff_sym *sym)
{
int rv;
size_t nbits = sym->nbits;
for(;;) {
if(rembits > nbits) {
if(*avail_ptr) {
nghttp2_bufs_fast_orb_hold(bufs, sym->code << (rembits - nbits));
} else {
rv = nghttp2_bufs_orb_hold(bufs, sym->code << (rembits - nbits));
if(rv != 0) {
return rv;
}
*avail_ptr = nghttp2_bufs_cur_avail(bufs);
}
rembits -= nbits;
break;
}
if(*avail_ptr) {
nghttp2_bufs_fast_orb(bufs, sym->code >> (nbits - rembits));
--*avail_ptr;
} else {
rv = nghttp2_bufs_orb(bufs, sym->code >> (nbits - rembits));
if(rv != 0) {
return rv;
}
*avail_ptr = nghttp2_bufs_cur_avail(bufs);
}
nbits -= rembits;
rembits = 8;
if(nbits == 0) {
break;
}
if(*avail_ptr) {
nghttp2_bufs_fast_addb_hold(bufs, 0);
} else {
rv = nghttp2_bufs_addb_hold(bufs, 0);
if(rv != 0) {
return rv;
}
*avail_ptr = nghttp2_bufs_cur_avail(bufs);
}
}
return (ssize_t)rembits;
}
size_t nghttp2_hd_huff_encode_count(const uint8_t *src, size_t len)
{
size_t i;
size_t nbits = 0;
for(i = 0; i < len; ++i) {
nbits += huff_sym_table[src[i]].nbits;
}
return (nbits + 7) / 8;
}
int nghttp2_hd_huff_encode(nghttp2_bufs *bufs,
const uint8_t *src, size_t srclen)
{
int rv;
ssize_t rembits = 8;
size_t i;
size_t avail;
avail = nghttp2_bufs_cur_avail(bufs);
for(i = 0; i < srclen; ++i) {
const nghttp2_huff_sym *sym = &huff_sym_table[src[i]];
if(rembits == 8) {
if(avail) {
nghttp2_bufs_fast_addb_hold(bufs, 0);
} else {
rv = nghttp2_bufs_addb_hold(bufs, 0);
if(rv != 0) {
return rv;
}
avail = nghttp2_bufs_cur_avail(bufs);
}
}
rembits = huff_encode_sym(bufs, &avail, rembits, sym);
if(rembits < 0) {
return (int)rembits;
}
}
if(rembits < 8) {
const nghttp2_huff_sym *sym = &huff_sym_table[256];
if(avail) {
nghttp2_bufs_fast_orb(bufs, sym->code >> (sym->nbits - rembits));
} else {
rv = nghttp2_bufs_orb(bufs, sym->code >> (sym->nbits - rembits));
if(rv != 0) {
return rv;
}
}
}
return 0;
}
void nghttp2_hd_huff_decode_context_init(nghttp2_hd_huff_decode_context *ctx)
{
ctx->state = 0;
ctx->accept = 1;
}
ssize_t nghttp2_hd_huff_decode(nghttp2_hd_huff_decode_context *ctx,
nghttp2_bufs *bufs,
const uint8_t *src, size_t srclen, int final)
{
size_t i, j;
int rv;
size_t avail;
avail = nghttp2_bufs_cur_avail(bufs);
for(i = 0; i < srclen; ++i) {
uint8_t in = src[i] >> 4;
for(j = 0; j < 2; ++j) {
const nghttp2_huff_decode *t;
t = &huff_decode_table[ctx->state][in];
if(t->flags & NGHTTP2_HUFF_FAIL) {
return NGHTTP2_ERR_HEADER_COMP;
}
if(t->flags & NGHTTP2_HUFF_SYM) {
if(avail) {
nghttp2_bufs_fast_addb(bufs, t->sym);
--avail;
} else {
rv = nghttp2_bufs_addb(bufs, t->sym);
if(rv != 0) {
return rv;
}
avail = nghttp2_bufs_cur_avail(bufs);
}
}
ctx->state = t->state;
ctx->accept = (t->flags & NGHTTP2_HUFF_ACCEPTED) != 0;
in = src[i] & 0xf;
}
}
if(final && !ctx->accept) {
return NGHTTP2_ERR_HEADER_COMP;
}
return (ssize_t)i;
}
