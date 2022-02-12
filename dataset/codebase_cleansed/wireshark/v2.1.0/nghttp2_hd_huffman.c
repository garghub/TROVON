static ssize_t huff_encode_sym(nghttp2_bufs *bufs, size_t *avail_ptr,
size_t rembits, const nghttp2_huff_sym *sym) {
int rv;
size_t nbits = sym->nbits;
uint32_t code = sym->code;
if (rembits > nbits) {
nghttp2_bufs_fast_orb_hold(bufs, (uint8_t)(code << (rembits - nbits)));
return (ssize_t)(rembits - nbits);
}
if (rembits == nbits) {
nghttp2_bufs_fast_orb(bufs, (uint8_t)code);
--*avail_ptr;
return 8;
}
nghttp2_bufs_fast_orb(bufs, (uint8_t)(code >> (nbits - rembits)));
--*avail_ptr;
nbits -= rembits;
if (nbits & 0x7) {
code <<= 8 - (nbits & 0x7);
}
if (*avail_ptr < (nbits + 7) / 8) {
rv = nghttp2_bufs_advance(bufs);
if (rv != 0) {
return rv;
}
*avail_ptr = nghttp2_bufs_cur_avail(bufs);
assert(*avail_ptr >= 3);
}
if (nbits < 8) {
nghttp2_bufs_fast_addb_hold(bufs, (uint8_t)code);
*avail_ptr = nghttp2_bufs_cur_avail(bufs);
return (ssize_t)(8 - nbits);
}
if (nbits > 24) {
nghttp2_bufs_fast_addb(bufs, (uint8_t)(code >> 24));
nbits -= 8;
}
if (nbits > 16) {
nghttp2_bufs_fast_addb(bufs, (uint8_t)(code >> 16));
nbits -= 8;
}
if (nbits > 8) {
nghttp2_bufs_fast_addb(bufs, (uint8_t)(code >> 8));
nbits -= 8;
}
if (nbits == 8) {
nghttp2_bufs_fast_addb(bufs, (uint8_t)code);
*avail_ptr = nghttp2_bufs_cur_avail(bufs);
return 8;
}
nghttp2_bufs_fast_addb_hold(bufs, (uint8_t)code);
*avail_ptr = nghttp2_bufs_cur_avail(bufs);
return (ssize_t)(8 - nbits);
}
size_t nghttp2_hd_huff_encode_count(const uint8_t *src, size_t len) {
size_t i;
size_t nbits = 0;
for (i = 0; i < len; ++i) {
nbits += huff_sym_table[src[i]].nbits;
}
return (nbits + 7) / 8;
}
int nghttp2_hd_huff_encode(nghttp2_bufs *bufs, const uint8_t *src,
size_t srclen) {
int rv;
ssize_t rembits = 8;
size_t i;
size_t avail;
avail = nghttp2_bufs_cur_avail(bufs);
for (i = 0; i < srclen; ++i) {
const nghttp2_huff_sym *sym = &huff_sym_table[src[i]];
if (rembits == 8) {
if (avail) {
nghttp2_bufs_fast_addb_hold(bufs, 0);
} else {
rv = nghttp2_bufs_addb_hold(bufs, 0);
if (rv != 0) {
return rv;
}
avail = nghttp2_bufs_cur_avail(bufs);
}
}
rembits = huff_encode_sym(bufs, &avail, (size_t)rembits, sym);
if (rembits < 0) {
return (int)rembits;
}
}
if (rembits < 8) {
const nghttp2_huff_sym *sym = &huff_sym_table[256];
assert(avail);
nghttp2_bufs_fast_orb(
bufs, (uint8_t)(sym->code >> (sym->nbits - (size_t)rembits)));
}
return 0;
}
void nghttp2_hd_huff_decode_context_init(nghttp2_hd_huff_decode_context *ctx) {
ctx->state = 0;
ctx->accept = 1;
}
ssize_t nghttp2_hd_huff_decode(nghttp2_hd_huff_decode_context *ctx,
nghttp2_buf *buf, const uint8_t *src,
size_t srclen, int final) {
size_t i;
for (i = 0; i < srclen; ++i) {
const nghttp2_huff_decode *t;
t = &huff_decode_table[ctx->state][src[i] >> 4];
if (t->flags & NGHTTP2_HUFF_FAIL) {
return NGHTTP2_ERR_HEADER_COMP;
}
if (t->flags & NGHTTP2_HUFF_SYM) {
*buf->last++ = t->sym;
}
t = &huff_decode_table[t->state][src[i] & 0xf];
if (t->flags & NGHTTP2_HUFF_FAIL) {
return NGHTTP2_ERR_HEADER_COMP;
}
if (t->flags & NGHTTP2_HUFF_SYM) {
*buf->last++ = t->sym;
}
ctx->state = t->state;
ctx->accept = (t->flags & NGHTTP2_HUFF_ACCEPTED) != 0;
}
if (final && !ctx->accept) {
return NGHTTP2_ERR_HEADER_COMP;
}
return (ssize_t)i;
}
