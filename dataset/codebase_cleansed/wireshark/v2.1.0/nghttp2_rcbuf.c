int nghttp2_rcbuf_new(nghttp2_rcbuf **rcbuf_ptr, size_t size,
nghttp2_mem *mem) {
uint8_t *p;
p = (uint8_t *)nghttp2_mem_malloc(mem, sizeof(nghttp2_rcbuf) + size);
if (p == NULL) {
return NGHTTP2_ERR_NOMEM;
}
*rcbuf_ptr = (nghttp2_rcbuf *)(void *)p;
(*rcbuf_ptr)->mem_user_data = mem->mem_user_data;
(*rcbuf_ptr)->free = mem->free;
(*rcbuf_ptr)->base = p + sizeof(nghttp2_rcbuf);
(*rcbuf_ptr)->len = size;
(*rcbuf_ptr)->ref = 1;
return 0;
}
int nghttp2_rcbuf_new2(nghttp2_rcbuf **rcbuf_ptr, const uint8_t *src,
size_t srclen, nghttp2_mem *mem) {
int rv;
rv = nghttp2_rcbuf_new(rcbuf_ptr, srclen + 1, mem);
if (rv != 0) {
return rv;
}
memcpy((*rcbuf_ptr)->base, src, srclen);
(*rcbuf_ptr)->len = srclen;
(*rcbuf_ptr)->base[srclen] = '\0';
return 0;
}
void nghttp2_rcbuf_del(nghttp2_rcbuf *rcbuf) {
nghttp2_mem_free2(rcbuf->free, rcbuf, rcbuf->mem_user_data);
}
void nghttp2_rcbuf_incref(nghttp2_rcbuf *rcbuf) {
if (rcbuf->ref == -1) {
return;
}
++rcbuf->ref;
}
void nghttp2_rcbuf_decref(nghttp2_rcbuf *rcbuf) {
if (rcbuf == NULL || rcbuf->ref == -1) {
return;
}
assert(rcbuf->ref > 0);
if (--rcbuf->ref == 0) {
nghttp2_rcbuf_del(rcbuf);
}
}
nghttp2_vec nghttp2_rcbuf_get_buf(nghttp2_rcbuf *rcbuf) {
nghttp2_vec res = {rcbuf->base, rcbuf->len};
return res;
}
