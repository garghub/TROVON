static int memeq(const void *s1, const void *s2, size_t n) {
return memcmp(s1, s2, n) == 0;
}
static int32_t lookup_token(const uint8_t *name, size_t namelen) {
switch (namelen) {
case 2:
switch (name[1]) {
case 'e':
if (lstreq("t", name, 1)) {
return NGHTTP2_TOKEN_TE;
}
break;
}
break;
case 3:
switch (name[2]) {
case 'a':
if (lstreq("vi", name, 2)) {
return NGHTTP2_TOKEN_VIA;
}
break;
case 'e':
if (lstreq("ag", name, 2)) {
return NGHTTP2_TOKEN_AGE;
}
break;
}
break;
case 4:
switch (name[3]) {
case 'e':
if (lstreq("dat", name, 3)) {
return NGHTTP2_TOKEN_DATE;
}
break;
case 'g':
if (lstreq("eta", name, 3)) {
return NGHTTP2_TOKEN_ETAG;
}
break;
case 'k':
if (lstreq("lin", name, 3)) {
return NGHTTP2_TOKEN_LINK;
}
break;
case 'm':
if (lstreq("fro", name, 3)) {
return NGHTTP2_TOKEN_FROM;
}
break;
case 't':
if (lstreq("hos", name, 3)) {
return NGHTTP2_TOKEN_HOST;
}
break;
case 'y':
if (lstreq("var", name, 3)) {
return NGHTTP2_TOKEN_VARY;
}
break;
}
break;
case 5:
switch (name[4]) {
case 'e':
if (lstreq("rang", name, 4)) {
return NGHTTP2_TOKEN_RANGE;
}
break;
case 'h':
if (lstreq(":pat", name, 4)) {
return NGHTTP2_TOKEN__PATH;
}
if (lstreq(":pat", name, 4)) {
return NGHTTP2_TOKEN__PATH;
}
break;
case 'w':
if (lstreq("allo", name, 4)) {
return NGHTTP2_TOKEN_ALLOW;
}
break;
}
break;
case 6:
switch (name[5]) {
case 'e':
if (lstreq("cooki", name, 5)) {
return NGHTTP2_TOKEN_COOKIE;
}
break;
case 'r':
if (lstreq("serve", name, 5)) {
return NGHTTP2_TOKEN_SERVER;
}
break;
case 't':
if (lstreq("accep", name, 5)) {
return NGHTTP2_TOKEN_ACCEPT;
}
if (lstreq("expec", name, 5)) {
return NGHTTP2_TOKEN_EXPECT;
}
break;
}
break;
case 7:
switch (name[6]) {
case 'd':
if (lstreq(":metho", name, 6)) {
return NGHTTP2_TOKEN__METHOD;
}
if (lstreq(":metho", name, 6)) {
return NGHTTP2_TOKEN__METHOD;
}
break;
case 'e':
if (lstreq(":schem", name, 6)) {
return NGHTTP2_TOKEN__SCHEME;
}
if (lstreq(":schem", name, 6)) {
return NGHTTP2_TOKEN__SCHEME;
}
if (lstreq("upgrad", name, 6)) {
return NGHTTP2_TOKEN_UPGRADE;
}
break;
case 'h':
if (lstreq("refres", name, 6)) {
return NGHTTP2_TOKEN_REFRESH;
}
break;
case 'r':
if (lstreq("refere", name, 6)) {
return NGHTTP2_TOKEN_REFERER;
}
break;
case 's':
if (lstreq(":statu", name, 6)) {
return NGHTTP2_TOKEN__STATUS;
}
if (lstreq(":statu", name, 6)) {
return NGHTTP2_TOKEN__STATUS;
}
if (lstreq(":statu", name, 6)) {
return NGHTTP2_TOKEN__STATUS;
}
if (lstreq(":statu", name, 6)) {
return NGHTTP2_TOKEN__STATUS;
}
if (lstreq(":statu", name, 6)) {
return NGHTTP2_TOKEN__STATUS;
}
if (lstreq(":statu", name, 6)) {
return NGHTTP2_TOKEN__STATUS;
}
if (lstreq(":statu", name, 6)) {
return NGHTTP2_TOKEN__STATUS;
}
if (lstreq("expire", name, 6)) {
return NGHTTP2_TOKEN_EXPIRES;
}
break;
}
break;
case 8:
switch (name[7]) {
case 'e':
if (lstreq("if-rang", name, 7)) {
return NGHTTP2_TOKEN_IF_RANGE;
}
break;
case 'h':
if (lstreq("if-matc", name, 7)) {
return NGHTTP2_TOKEN_IF_MATCH;
}
break;
case 'n':
if (lstreq("locatio", name, 7)) {
return NGHTTP2_TOKEN_LOCATION;
}
break;
}
break;
case 10:
switch (name[9]) {
case 'e':
if (lstreq("keep-aliv", name, 9)) {
return NGHTTP2_TOKEN_KEEP_ALIVE;
}
if (lstreq("set-cooki", name, 9)) {
return NGHTTP2_TOKEN_SET_COOKIE;
}
break;
case 'n':
if (lstreq("connectio", name, 9)) {
return NGHTTP2_TOKEN_CONNECTION;
}
break;
case 't':
if (lstreq("user-agen", name, 9)) {
return NGHTTP2_TOKEN_USER_AGENT;
}
break;
case 'y':
if (lstreq(":authorit", name, 9)) {
return NGHTTP2_TOKEN__AUTHORITY;
}
break;
}
break;
case 11:
switch (name[10]) {
case 'r':
if (lstreq("retry-afte", name, 10)) {
return NGHTTP2_TOKEN_RETRY_AFTER;
}
break;
}
break;
case 12:
switch (name[11]) {
case 'e':
if (lstreq("content-typ", name, 11)) {
return NGHTTP2_TOKEN_CONTENT_TYPE;
}
break;
case 's':
if (lstreq("max-forward", name, 11)) {
return NGHTTP2_TOKEN_MAX_FORWARDS;
}
break;
}
break;
case 13:
switch (name[12]) {
case 'd':
if (lstreq("last-modifie", name, 12)) {
return NGHTTP2_TOKEN_LAST_MODIFIED;
}
break;
case 'e':
if (lstreq("content-rang", name, 12)) {
return NGHTTP2_TOKEN_CONTENT_RANGE;
}
break;
case 'h':
if (lstreq("if-none-matc", name, 12)) {
return NGHTTP2_TOKEN_IF_NONE_MATCH;
}
break;
case 'l':
if (lstreq("cache-contro", name, 12)) {
return NGHTTP2_TOKEN_CACHE_CONTROL;
}
break;
case 'n':
if (lstreq("authorizatio", name, 12)) {
return NGHTTP2_TOKEN_AUTHORIZATION;
}
break;
case 's':
if (lstreq("accept-range", name, 12)) {
return NGHTTP2_TOKEN_ACCEPT_RANGES;
}
break;
}
break;
case 14:
switch (name[13]) {
case 'h':
if (lstreq("content-lengt", name, 13)) {
return NGHTTP2_TOKEN_CONTENT_LENGTH;
}
break;
case 't':
if (lstreq("accept-charse", name, 13)) {
return NGHTTP2_TOKEN_ACCEPT_CHARSET;
}
break;
}
break;
case 15:
switch (name[14]) {
case 'e':
if (lstreq("accept-languag", name, 14)) {
return NGHTTP2_TOKEN_ACCEPT_LANGUAGE;
}
break;
case 'g':
if (lstreq("accept-encodin", name, 14)) {
return NGHTTP2_TOKEN_ACCEPT_ENCODING;
}
break;
}
break;
case 16:
switch (name[15]) {
case 'e':
if (lstreq("content-languag", name, 15)) {
return NGHTTP2_TOKEN_CONTENT_LANGUAGE;
}
if (lstreq("www-authenticat", name, 15)) {
return NGHTTP2_TOKEN_WWW_AUTHENTICATE;
}
break;
case 'g':
if (lstreq("content-encodin", name, 15)) {
return NGHTTP2_TOKEN_CONTENT_ENCODING;
}
break;
case 'n':
if (lstreq("content-locatio", name, 15)) {
return NGHTTP2_TOKEN_CONTENT_LOCATION;
}
if (lstreq("proxy-connectio", name, 15)) {
return NGHTTP2_TOKEN_PROXY_CONNECTION;
}
break;
}
break;
case 17:
switch (name[16]) {
case 'e':
if (lstreq("if-modified-sinc", name, 16)) {
return NGHTTP2_TOKEN_IF_MODIFIED_SINCE;
}
break;
case 'g':
if (lstreq("transfer-encodin", name, 16)) {
return NGHTTP2_TOKEN_TRANSFER_ENCODING;
}
break;
}
break;
case 18:
switch (name[17]) {
case 'e':
if (lstreq("proxy-authenticat", name, 17)) {
return NGHTTP2_TOKEN_PROXY_AUTHENTICATE;
}
break;
}
break;
case 19:
switch (name[18]) {
case 'e':
if (lstreq("if-unmodified-sinc", name, 18)) {
return NGHTTP2_TOKEN_IF_UNMODIFIED_SINCE;
}
break;
case 'n':
if (lstreq("content-dispositio", name, 18)) {
return NGHTTP2_TOKEN_CONTENT_DISPOSITION;
}
if (lstreq("proxy-authorizatio", name, 18)) {
return NGHTTP2_TOKEN_PROXY_AUTHORIZATION;
}
break;
}
break;
case 25:
switch (name[24]) {
case 'y':
if (lstreq("strict-transport-securit", name, 24)) {
return NGHTTP2_TOKEN_STRICT_TRANSPORT_SECURITY;
}
break;
}
break;
case 27:
switch (name[26]) {
case 'n':
if (lstreq("access-control-allow-origi", name, 26)) {
return NGHTTP2_TOKEN_ACCESS_CONTROL_ALLOW_ORIGIN;
}
break;
}
break;
}
return -1;
}
void nghttp2_hd_entry_init(nghttp2_hd_entry *ent, nghttp2_hd_nv *nv) {
ent->nv = *nv;
ent->cnv.name = nv->name->base;
ent->cnv.namelen = nv->name->len;
ent->cnv.value = nv->value->base;
ent->cnv.valuelen = nv->value->len;
ent->cnv.flags = nv->flags;
ent->next = NULL;
ent->hash = 0;
nghttp2_rcbuf_incref(ent->nv.name);
nghttp2_rcbuf_incref(ent->nv.value);
}
void nghttp2_hd_entry_free(nghttp2_hd_entry *ent) {
nghttp2_rcbuf_decref(ent->nv.value);
nghttp2_rcbuf_decref(ent->nv.name);
}
static int name_eq(const nghttp2_hd_nv *a, const nghttp2_nv *b) {
return a->name->len == b->namelen &&
memeq(a->name->base, b->name, b->namelen);
}
static int value_eq(const nghttp2_hd_nv *a, const nghttp2_nv *b) {
return a->value->len == b->valuelen &&
memeq(a->value->base, b->value, b->valuelen);
}
static uint32_t name_hash(const nghttp2_nv *nv) {
uint32_t h = 2166136261u;
size_t i;
for (i = 0; i < nv->namelen; ++i) {
h ^= nv->name[i];
h += (h << 1) + (h << 4) + (h << 7) + (h << 8) + (h << 24);
}
return h;
}
static void hd_map_init(nghttp2_hd_map *map) {
memset(map, 0, sizeof(nghttp2_hd_map));
}
static void hd_map_insert(nghttp2_hd_map *map, nghttp2_hd_entry *ent) {
nghttp2_hd_entry **bucket;
bucket = &map->table[ent->hash & (HD_MAP_SIZE - 1)];
if (*bucket == NULL) {
*bucket = ent;
return;
}
ent->next = *bucket;
*bucket = ent;
}
static nghttp2_hd_entry *hd_map_find(nghttp2_hd_map *map, int *exact_match,
const nghttp2_nv *nv, int32_t token,
uint32_t hash) {
nghttp2_hd_entry *p;
nghttp2_hd_entry *res = NULL;
*exact_match = 0;
for (p = map->table[hash & (HD_MAP_SIZE - 1)]; p; p = p->next) {
if (token != p->nv.token ||
(token == -1 && (hash != p->hash || !name_eq(&p->nv, nv)))) {
continue;
}
if (!res) {
res = p;
}
if (value_eq(&p->nv, nv)) {
res = p;
*exact_match = 1;
break;
}
}
return res;
}
static void hd_map_remove(nghttp2_hd_map *map, nghttp2_hd_entry *ent) {
nghttp2_hd_entry **dst;
dst = &map->table[ent->hash & (HD_MAP_SIZE - 1)];
for (; *dst; dst = &(*dst)->next) {
if (*dst != ent) {
continue;
}
*dst = ent->next;
ent->next = NULL;
return;
}
}
static int hd_ringbuf_init(nghttp2_hd_ringbuf *ringbuf, size_t bufsize,
nghttp2_mem *mem) {
size_t size;
for (size = 1; size < bufsize; size <<= 1)
;
ringbuf->buffer = (nghttp2_hd_entry **)nghttp2_mem_malloc(mem, sizeof(nghttp2_hd_entry *) * size);
if (ringbuf->buffer == NULL) {
return NGHTTP2_ERR_NOMEM;
}
ringbuf->mask = size - 1;
ringbuf->first = 0;
ringbuf->len = 0;
return 0;
}
static nghttp2_hd_entry *hd_ringbuf_get(nghttp2_hd_ringbuf *ringbuf,
size_t idx) {
assert(idx < ringbuf->len);
return ringbuf->buffer[(ringbuf->first + idx) & ringbuf->mask];
}
static int hd_ringbuf_reserve(nghttp2_hd_ringbuf *ringbuf, size_t bufsize,
nghttp2_mem *mem) {
size_t i;
size_t size;
nghttp2_hd_entry **buffer;
if (ringbuf->mask + 1 >= bufsize) {
return 0;
}
for (size = 1; size < bufsize; size <<= 1)
;
buffer = (nghttp2_hd_entry **)nghttp2_mem_malloc(mem, sizeof(nghttp2_hd_entry *) * size);
if (buffer == NULL) {
return NGHTTP2_ERR_NOMEM;
}
for (i = 0; i < ringbuf->len; ++i) {
buffer[i] = hd_ringbuf_get(ringbuf, i);
}
nghttp2_mem_free(mem, ringbuf->buffer);
ringbuf->buffer = buffer;
ringbuf->mask = size - 1;
ringbuf->first = 0;
return 0;
}
static void hd_ringbuf_free(nghttp2_hd_ringbuf *ringbuf, nghttp2_mem *mem) {
size_t i;
if (ringbuf == NULL) {
return;
}
for (i = 0; i < ringbuf->len; ++i) {
nghttp2_hd_entry *ent = hd_ringbuf_get(ringbuf, i);
nghttp2_hd_entry_free(ent);
nghttp2_mem_free(mem, ent);
}
nghttp2_mem_free(mem, ringbuf->buffer);
}
static int hd_ringbuf_push_front(nghttp2_hd_ringbuf *ringbuf,
nghttp2_hd_entry *ent, nghttp2_mem *mem) {
int rv;
rv = hd_ringbuf_reserve(ringbuf, ringbuf->len + 1, mem);
if (rv != 0) {
return rv;
}
ringbuf->buffer[--ringbuf->first & ringbuf->mask] = ent;
++ringbuf->len;
return 0;
}
static void hd_ringbuf_pop_back(nghttp2_hd_ringbuf *ringbuf) {
assert(ringbuf->len > 0);
--ringbuf->len;
}
static int hd_context_init(nghttp2_hd_context *context, nghttp2_mem *mem) {
int rv;
context->mem = mem;
context->bad = 0;
context->hd_table_bufsize_max = NGHTTP2_HD_DEFAULT_MAX_BUFFER_SIZE;
rv = hd_ringbuf_init(&context->hd_table, context->hd_table_bufsize_max /
NGHTTP2_HD_ENTRY_OVERHEAD,
mem);
if (rv != 0) {
return rv;
}
context->hd_table_bufsize = 0;
context->next_seq = 0;
return 0;
}
static void hd_context_free(nghttp2_hd_context *context) {
hd_ringbuf_free(&context->hd_table, context->mem);
}
int nghttp2_hd_deflate_init(nghttp2_hd_deflater *deflater, nghttp2_mem *mem) {
return nghttp2_hd_deflate_init2(
deflater, NGHTTP2_HD_DEFAULT_MAX_DEFLATE_BUFFER_SIZE, mem);
}
int nghttp2_hd_deflate_init2(nghttp2_hd_deflater *deflater,
size_t deflate_hd_table_bufsize_max,
nghttp2_mem *mem) {
int rv;
rv = hd_context_init(&deflater->ctx, mem);
if (rv != 0) {
return rv;
}
hd_map_init(&deflater->map);
if (deflate_hd_table_bufsize_max < NGHTTP2_HD_DEFAULT_MAX_BUFFER_SIZE) {
deflater->notify_table_size_change = 1;
deflater->ctx.hd_table_bufsize_max = deflate_hd_table_bufsize_max;
} else {
deflater->notify_table_size_change = 0;
}
deflater->deflate_hd_table_bufsize_max = deflate_hd_table_bufsize_max;
deflater->min_hd_table_bufsize_max = UINT32_MAX;
return 0;
}
int nghttp2_hd_inflate_init(nghttp2_hd_inflater *inflater, nghttp2_mem *mem) {
int rv;
rv = hd_context_init(&inflater->ctx, mem);
if (rv != 0) {
goto fail;
}
inflater->settings_hd_table_bufsize_max = NGHTTP2_HD_DEFAULT_MAX_BUFFER_SIZE;
inflater->min_hd_table_bufsize_max = UINT32_MAX;
inflater->nv_name_keep = NULL;
inflater->nv_value_keep = NULL;
inflater->opcode = NGHTTP2_HD_OPCODE_NONE;
inflater->state = NGHTTP2_HD_STATE_INFLATE_START;
nghttp2_buf_init(&inflater->namebuf);
nghttp2_buf_init(&inflater->valuebuf);
inflater->namercbuf = NULL;
inflater->valuercbuf = NULL;
inflater->huffman_encoded = 0;
inflater->index = 0;
inflater->left = 0;
inflater->shift = 0;
inflater->index_required = 0;
inflater->no_index = 0;
return 0;
fail:
return rv;
}
static void hd_inflate_keep_free(nghttp2_hd_inflater *inflater) {
nghttp2_rcbuf_decref(inflater->nv_value_keep);
nghttp2_rcbuf_decref(inflater->nv_name_keep);
inflater->nv_value_keep = NULL;
inflater->nv_name_keep = NULL;
}
void nghttp2_hd_deflate_free(nghttp2_hd_deflater *deflater) {
hd_context_free(&deflater->ctx);
}
void nghttp2_hd_inflate_free(nghttp2_hd_inflater *inflater) {
hd_inflate_keep_free(inflater);
nghttp2_rcbuf_decref(inflater->valuercbuf);
nghttp2_rcbuf_decref(inflater->namercbuf);
hd_context_free(&inflater->ctx);
}
static size_t entry_room(size_t namelen, size_t valuelen) {
return NGHTTP2_HD_ENTRY_OVERHEAD + namelen + valuelen;
}
static int emit_header(nghttp2_hd_nv *nv_out, nghttp2_hd_nv *nv) {
DEBUGF(fprintf(stderr, "inflatehd: header emission: %s: %s\n", nv->name->base,
nv->value->base));
*nv_out = *nv;
return 0;
}
static size_t count_encoded_length(size_t n, size_t prefix) {
size_t k = (size_t)((1 << prefix) - 1);
size_t len = 0;
if (n < k) {
return 1;
}
n -= k;
++len;
for (; n >= 128; n >>= 7, ++len)
;
return len + 1;
}
static size_t encode_length(uint8_t *buf, size_t n, size_t prefix) {
size_t k = (size_t)((1 << prefix) - 1);
uint8_t *begin = buf;
*buf = (uint8_t)(*buf & ~k);
if (n < k) {
*buf = (uint8_t)(*buf | n);
return 1;
}
*buf = (uint8_t)(*buf | k);
++buf;
n -= k;
for (; n >= 128; n >>= 7) {
*buf++ = (uint8_t)((1 << 7) | (n & 0x7f));
}
*buf++ = (uint8_t)n;
return (size_t)(buf - begin);
}
static ssize_t decode_length(uint32_t *res, size_t *shift_ptr, int *final,
uint32_t initial, size_t shift, const uint8_t *in,
const uint8_t *last, size_t prefix) {
uint32_t k = (uint8_t)((1 << prefix) - 1);
uint32_t n = initial;
const uint8_t *start = in;
*shift_ptr = 0;
*final = 0;
if (n == 0) {
if ((*in & k) != k) {
*res = (*in) & k;
*final = 1;
return 1;
}
n = k;
if (++in == last) {
*res = n;
return (ssize_t)(in - start);
}
}
for (; in != last; ++in, shift += 7) {
uint32_t add = *in & 0x7f;
if ((UINT32_MAX >> shift) < add) {
DEBUGF(fprintf(stderr, "inflate: integer overflow on shift\n"));
return -1;
}
add <<= shift;
if (UINT32_MAX - add < n) {
DEBUGF(fprintf(stderr, "inflate: integer overflow on addition\n"));
return -1;
}
n += add;
if ((*in & (1 << 7)) == 0) {
break;
}
}
*shift_ptr = shift;
if (in == last) {
*res = n;
return (ssize_t)(in - start);
}
*res = n;
*final = 1;
return (ssize_t)(in + 1 - start);
}
static int emit_table_size(nghttp2_bufs *bufs, size_t table_size) {
int rv;
uint8_t *bufp;
size_t blocklen;
uint8_t sb[16];
DEBUGF(fprintf(stderr, "deflatehd: emit table_size=%zu\n", table_size));
blocklen = count_encoded_length(table_size, 5);
if (sizeof(sb) < blocklen) {
return NGHTTP2_ERR_HEADER_COMP;
}
bufp = sb;
*bufp = 0x20u;
encode_length(bufp, table_size, 5);
rv = nghttp2_bufs_add(bufs, sb, blocklen);
if (rv != 0) {
return rv;
}
return 0;
}
static int emit_indexed_block(nghttp2_bufs *bufs, size_t idx) {
int rv;
size_t blocklen;
uint8_t sb[16];
uint8_t *bufp;
blocklen = count_encoded_length(idx + 1, 7);
DEBUGF(fprintf(stderr, "deflatehd: emit indexed index=%zu, %zu bytes\n", idx,
blocklen));
if (sizeof(sb) < blocklen) {
return NGHTTP2_ERR_HEADER_COMP;
}
bufp = sb;
*bufp = 0x80u;
encode_length(bufp, idx + 1, 7);
rv = nghttp2_bufs_add(bufs, sb, blocklen);
if (rv != 0) {
return rv;
}
return 0;
}
static int emit_string(nghttp2_bufs *bufs, const uint8_t *str, size_t len) {
int rv;
uint8_t sb[16];
uint8_t *bufp;
size_t blocklen;
size_t enclen;
int huffman = 0;
enclen = nghttp2_hd_huff_encode_count(str, len);
if (enclen < len) {
huffman = 1;
} else {
enclen = len;
}
blocklen = count_encoded_length(enclen, 7);
DEBUGF(fprintf(stderr, "deflatehd: emit string str="));
DEBUGF(fwrite(str, len, 1, stderr));
DEBUGF(fprintf(stderr, ", length=%zu, huffman=%d, encoded_length=%zu\n", len,
huffman, enclen));
if (sizeof(sb) < blocklen) {
return NGHTTP2_ERR_HEADER_COMP;
}
bufp = sb;
*bufp = huffman ? 1 << 7 : 0;
encode_length(bufp, enclen, 7);
rv = nghttp2_bufs_add(bufs, sb, blocklen);
if (rv != 0) {
return rv;
}
if (huffman) {
rv = nghttp2_hd_huff_encode(bufs, str, len);
} else {
assert(enclen == len);
rv = nghttp2_bufs_add(bufs, str, len);
}
return rv;
}
static uint8_t pack_first_byte(int indexing_mode) {
switch (indexing_mode) {
case NGHTTP2_HD_WITH_INDEXING:
return 0x40u;
case NGHTTP2_HD_WITHOUT_INDEXING:
return 0;
case NGHTTP2_HD_NEVER_INDEXING:
return 0x10u;
default:
assert(0);
}
return 0;
}
static int emit_indname_block(nghttp2_bufs *bufs, size_t idx,
const nghttp2_nv *nv, int indexing_mode) {
int rv;
uint8_t *bufp;
size_t blocklen;
uint8_t sb[16];
size_t prefixlen;
if (indexing_mode == NGHTTP2_HD_WITH_INDEXING) {
prefixlen = 6;
} else {
prefixlen = 4;
}
DEBUGF(fprintf(stderr, "deflatehd: emit indname index=%zu, valuelen=%zu, "
"indexing_mode=%d\n",
idx, nv->valuelen, indexing_mode));
blocklen = count_encoded_length(idx + 1, prefixlen);
if (sizeof(sb) < blocklen) {
return NGHTTP2_ERR_HEADER_COMP;
}
bufp = sb;
*bufp = pack_first_byte(indexing_mode);
encode_length(bufp, idx + 1, prefixlen);
rv = nghttp2_bufs_add(bufs, sb, blocklen);
if (rv != 0) {
return rv;
}
rv = emit_string(bufs, nv->value, nv->valuelen);
if (rv != 0) {
return rv;
}
return 0;
}
static int emit_newname_block(nghttp2_bufs *bufs, const nghttp2_nv *nv,
int indexing_mode) {
int rv;
DEBUGF(fprintf(stderr, "deflatehd: emit newname namelen=%zu, valuelen=%zu, "
"indexing_mode=%d\n",
nv->namelen, nv->valuelen, indexing_mode));
rv = nghttp2_bufs_addb(bufs, pack_first_byte(indexing_mode));
if (rv != 0) {
return rv;
}
rv = emit_string(bufs, nv->name, nv->namelen);
if (rv != 0) {
return rv;
}
rv = emit_string(bufs, nv->value, nv->valuelen);
if (rv != 0) {
return rv;
}
return 0;
}
static int add_hd_table_incremental(nghttp2_hd_context *context,
nghttp2_hd_nv *nv, nghttp2_hd_map *map,
uint32_t hash) {
int rv;
nghttp2_hd_entry *new_ent;
size_t room;
nghttp2_mem *mem;
mem = context->mem;
room = entry_room(nv->name->len, nv->value->len);
while (context->hd_table_bufsize + room > context->hd_table_bufsize_max &&
context->hd_table.len > 0) {
size_t idx = context->hd_table.len - 1;
nghttp2_hd_entry *ent = hd_ringbuf_get(&context->hd_table, idx);
context->hd_table_bufsize -=
entry_room(ent->nv.name->len, ent->nv.value->len);
DEBUGF(fprintf(stderr, "hpack: remove item from header table: %s: %s\n",
(char *)ent->nv.name->base, (char *)ent->nv.value->base));
hd_ringbuf_pop_back(&context->hd_table);
if (map) {
hd_map_remove(map, ent);
}
nghttp2_hd_entry_free(ent);
nghttp2_mem_free(mem, ent);
}
if (room > context->hd_table_bufsize_max) {
return 0;
}
new_ent = (nghttp2_hd_entry *)nghttp2_mem_malloc(mem, sizeof(nghttp2_hd_entry));
if (new_ent == NULL) {
return NGHTTP2_ERR_NOMEM;
}
nghttp2_hd_entry_init(new_ent, nv);
rv = hd_ringbuf_push_front(&context->hd_table, new_ent, mem);
if (rv != 0) {
nghttp2_hd_entry_free(new_ent);
nghttp2_mem_free(mem, new_ent);
return rv;
}
new_ent->seq = context->next_seq++;
new_ent->hash = hash;
if (map) {
hd_map_insert(map, new_ent);
}
context->hd_table_bufsize += room;
return 0;
}
static search_result search_static_table(const nghttp2_nv *nv, int32_t token,
int indexing_mode) {
search_result res = {token, 0};
int i;
nghttp2_hd_static_entry *ent;
if (indexing_mode == NGHTTP2_HD_NEVER_INDEXING) {
return res;
}
for (i = token;
i <= NGHTTP2_TOKEN_WWW_AUTHENTICATE && static_table[i].token == token;
++i) {
ent = &static_table[i];
if (ent->value.len == nv->valuelen &&
memcmp(ent->value.base, nv->value, nv->valuelen) == 0) {
res.index = i;
res.name_value_match = 1;
return res;
}
}
return res;
}
static search_result search_hd_table(nghttp2_hd_context *context,
const nghttp2_nv *nv, int32_t token,
int indexing_mode, nghttp2_hd_map *map,
uint32_t hash) {
search_result res = {-1, 0};
nghttp2_hd_entry *ent;
int exact_match;
if (token >= 0 && token <= NGHTTP2_TOKEN_WWW_AUTHENTICATE) {
res = search_static_table(nv, token, indexing_mode);
if (res.name_value_match) {
return res;
}
}
exact_match = 0;
ent = hd_map_find(map, &exact_match, nv, token, hash);
if (ent == NULL) {
return res;
}
if (res.index != -1 && !exact_match) {
return res;
}
res.index =
(ssize_t)(context->next_seq - 1 - ent->seq + NGHTTP2_STATIC_TABLE_LENGTH);
if (exact_match) {
res.name_value_match = 1;
}
return res;
}
static void hd_context_shrink_table_size(nghttp2_hd_context *context,
nghttp2_hd_map *map) {
nghttp2_mem *mem;
mem = context->mem;
while (context->hd_table_bufsize > context->hd_table_bufsize_max &&
context->hd_table.len > 0) {
size_t idx = context->hd_table.len - 1;
nghttp2_hd_entry *ent = hd_ringbuf_get(&context->hd_table, idx);
context->hd_table_bufsize -=
entry_room(ent->nv.name->len, ent->nv.value->len);
hd_ringbuf_pop_back(&context->hd_table);
if (map) {
hd_map_remove(map, ent);
}
nghttp2_hd_entry_free(ent);
nghttp2_mem_free(mem, ent);
}
}
int nghttp2_hd_deflate_change_table_size(nghttp2_hd_deflater *deflater,
size_t settings_hd_table_bufsize_max) {
size_t next_bufsize = nghttp2_min(settings_hd_table_bufsize_max,
deflater->deflate_hd_table_bufsize_max);
deflater->ctx.hd_table_bufsize_max = next_bufsize;
deflater->min_hd_table_bufsize_max =
nghttp2_min(deflater->min_hd_table_bufsize_max, next_bufsize);
deflater->notify_table_size_change = 1;
hd_context_shrink_table_size(&deflater->ctx, &deflater->map);
return 0;
}
int nghttp2_hd_inflate_change_table_size(nghttp2_hd_inflater *inflater,
size_t settings_hd_table_bufsize_max) {
switch (inflater->state) {
case NGHTTP2_HD_STATE_EXPECT_TABLE_SIZE:
case NGHTTP2_HD_STATE_INFLATE_START:
break;
default:
return NGHTTP2_ERR_INVALID_STATE;
}
if (inflater->ctx.hd_table_bufsize_max > settings_hd_table_bufsize_max) {
inflater->state = NGHTTP2_HD_STATE_EXPECT_TABLE_SIZE;
inflater->min_hd_table_bufsize_max = settings_hd_table_bufsize_max;
}
inflater->settings_hd_table_bufsize_max = settings_hd_table_bufsize_max;
inflater->ctx.hd_table_bufsize_max = settings_hd_table_bufsize_max;
hd_context_shrink_table_size(&inflater->ctx, NULL);
return 0;
}
static size_t get_max_index(nghttp2_hd_context *context) {
return context->hd_table.len + NGHTTP2_STATIC_TABLE_LENGTH - 1;
}
nghttp2_hd_nv nghttp2_hd_table_get(nghttp2_hd_context *context, size_t idx) {
assert(INDEX_RANGE_VALID(context, idx));
if (idx >= NGHTTP2_STATIC_TABLE_LENGTH) {
return hd_ringbuf_get(&context->hd_table, idx - NGHTTP2_STATIC_TABLE_LENGTH)
->nv;
} else {
nghttp2_hd_static_entry *ent = &static_table[idx];
nghttp2_hd_nv nv = {&ent->name, &ent->value, ent->token,
NGHTTP2_NV_FLAG_NONE};
return nv;
}
}
static const nghttp2_nv *nghttp2_hd_table_get2(nghttp2_hd_context *context,
size_t idx) {
assert(INDEX_RANGE_VALID(context, idx));
if (idx >= NGHTTP2_STATIC_TABLE_LENGTH) {
return &hd_ringbuf_get(&context->hd_table,
idx - NGHTTP2_STATIC_TABLE_LENGTH)->cnv;
}
return &static_table[idx].cnv;
}
static int hd_deflate_decide_indexing(nghttp2_hd_deflater *deflater,
const nghttp2_nv *nv, int32_t token) {
if (token == NGHTTP2_TOKEN__PATH || token == NGHTTP2_TOKEN_AGE ||
token == NGHTTP2_TOKEN_CONTENT_LENGTH || token == NGHTTP2_TOKEN_ETAG ||
token == NGHTTP2_TOKEN_IF_MODIFIED_SINCE ||
token == NGHTTP2_TOKEN_IF_NONE_MATCH || token == NGHTTP2_TOKEN_LOCATION ||
token == NGHTTP2_TOKEN_SET_COOKIE ||
entry_room(nv->namelen, nv->valuelen) >
deflater->ctx.hd_table_bufsize_max * 3 / 4) {
return NGHTTP2_HD_WITHOUT_INDEXING;
}
return NGHTTP2_HD_WITH_INDEXING;
}
static int deflate_nv(nghttp2_hd_deflater *deflater, nghttp2_bufs *bufs,
const nghttp2_nv *nv) {
int rv;
search_result res;
ssize_t idx;
int indexing_mode;
int32_t token;
nghttp2_mem *mem;
uint32_t hash = 0;
DEBUGF(fprintf(stderr, "deflatehd: deflating %.*s: %.*s\n", (int)nv->namelen,
nv->name, (int)nv->valuelen, nv->value));
mem = deflater->ctx.mem;
token = lookup_token(nv->name, nv->namelen);
if (token == -1) {
hash = name_hash(nv);
} else if (token <= NGHTTP2_TOKEN_WWW_AUTHENTICATE) {
hash = static_table[token].hash;
}
indexing_mode =
token == NGHTTP2_TOKEN_AUTHORIZATION ||
(token == NGHTTP2_TOKEN_COOKIE && nv->valuelen < 20) ||
(nv->flags & NGHTTP2_NV_FLAG_NO_INDEX)
? NGHTTP2_HD_NEVER_INDEXING
: hd_deflate_decide_indexing(deflater, nv, token);
res = search_hd_table(&deflater->ctx, nv, token, indexing_mode,
&deflater->map, hash);
idx = res.index;
if (res.name_value_match) {
DEBUGF(fprintf(stderr, "deflatehd: name/value match index=%zd\n", idx));
rv = emit_indexed_block(bufs, (size_t)idx);
if (rv != 0) {
return rv;
}
return 0;
}
if (res.index != -1) {
DEBUGF(fprintf(stderr, "deflatehd: name match index=%zd\n", res.index));
}
if (indexing_mode == NGHTTP2_HD_WITH_INDEXING) {
nghttp2_hd_nv hd_nv;
if (idx != -1 && idx < (ssize_t)NGHTTP2_STATIC_TABLE_LENGTH) {
hd_nv.name = nghttp2_hd_table_get(&deflater->ctx, (size_t)idx).name;
nghttp2_rcbuf_incref(hd_nv.name);
} else {
rv = nghttp2_rcbuf_new2(&hd_nv.name, nv->name, nv->namelen, mem);
if (rv != 0) {
return rv;
}
}
rv = nghttp2_rcbuf_new2(&hd_nv.value, nv->value, nv->valuelen, mem);
if (rv != 0) {
nghttp2_rcbuf_decref(hd_nv.name);
return rv;
}
hd_nv.token = token;
hd_nv.flags = NGHTTP2_NV_FLAG_NONE;
rv = add_hd_table_incremental(&deflater->ctx, &hd_nv, &deflater->map, hash);
nghttp2_rcbuf_decref(hd_nv.value);
nghttp2_rcbuf_decref(hd_nv.name);
if (rv != 0) {
return NGHTTP2_ERR_HEADER_COMP;
}
}
if (idx == -1) {
rv = emit_newname_block(bufs, nv, indexing_mode);
} else {
rv = emit_indname_block(bufs, (size_t)idx, nv, indexing_mode);
}
if (rv != 0) {
return rv;
}
return 0;
}
int nghttp2_hd_deflate_hd_bufs(nghttp2_hd_deflater *deflater,
nghttp2_bufs *bufs, const nghttp2_nv *nv,
size_t nvlen) {
size_t i;
int rv = 0;
if (deflater->ctx.bad) {
return NGHTTP2_ERR_HEADER_COMP;
}
if (deflater->notify_table_size_change) {
size_t min_hd_table_bufsize_max;
min_hd_table_bufsize_max = deflater->min_hd_table_bufsize_max;
deflater->notify_table_size_change = 0;
deflater->min_hd_table_bufsize_max = UINT32_MAX;
if (deflater->ctx.hd_table_bufsize_max > min_hd_table_bufsize_max) {
rv = emit_table_size(bufs, min_hd_table_bufsize_max);
if (rv != 0) {
goto fail;
}
}
rv = emit_table_size(bufs, deflater->ctx.hd_table_bufsize_max);
if (rv != 0) {
goto fail;
}
}
for (i = 0; i < nvlen; ++i) {
rv = deflate_nv(deflater, bufs, &nv[i]);
if (rv != 0) {
goto fail;
}
}
DEBUGF(
fprintf(stderr, "deflatehd: all input name/value pairs were deflated\n"));
return 0;
fail:
DEBUGF(fprintf(stderr, "deflatehd: error return %d\n", rv));
deflater->ctx.bad = 1;
return rv;
}
ssize_t nghttp2_hd_deflate_hd(nghttp2_hd_deflater *deflater, uint8_t *buf,
size_t buflen, const nghttp2_nv *nv,
size_t nvlen) {
nghttp2_bufs bufs;
int rv;
nghttp2_mem *mem;
mem = deflater->ctx.mem;
rv = nghttp2_bufs_wrap_init(&bufs, buf, buflen, mem);
if (rv != 0) {
return rv;
}
rv = nghttp2_hd_deflate_hd_bufs(deflater, &bufs, nv, nvlen);
buflen = nghttp2_bufs_len(&bufs);
nghttp2_bufs_wrap_free(&bufs);
if (rv == NGHTTP2_ERR_BUFFER_ERROR) {
return NGHTTP2_ERR_INSUFF_BUFSIZE;
}
if (rv != 0) {
return rv;
}
return (ssize_t)buflen;
}
size_t nghttp2_hd_deflate_bound(nghttp2_hd_deflater *deflater _U_,
const nghttp2_nv *nva, size_t nvlen) {
size_t n = 0;
size_t i;
n += 12;
n += 6 * 2 * nvlen;
for (i = 0; i < nvlen; ++i) {
n += nva[i].namelen + nva[i].valuelen;
}
return n;
}
int nghttp2_hd_deflate_new(nghttp2_hd_deflater **deflater_ptr,
size_t deflate_hd_table_bufsize_max) {
return nghttp2_hd_deflate_new2(deflater_ptr, deflate_hd_table_bufsize_max,
NULL);
}
int nghttp2_hd_deflate_new2(nghttp2_hd_deflater **deflater_ptr,
size_t deflate_hd_table_bufsize_max,
nghttp2_mem *mem) {
int rv;
nghttp2_hd_deflater *deflater;
if (mem == NULL) {
mem = nghttp2_mem_default();
}
deflater = (nghttp2_hd_deflater *)nghttp2_mem_malloc(mem, sizeof(nghttp2_hd_deflater));
if (deflater == NULL) {
return NGHTTP2_ERR_NOMEM;
}
rv = nghttp2_hd_deflate_init2(deflater, deflate_hd_table_bufsize_max, mem);
if (rv != 0) {
nghttp2_mem_free(mem, deflater);
return rv;
}
*deflater_ptr = deflater;
return 0;
}
void nghttp2_hd_deflate_del(nghttp2_hd_deflater *deflater) {
nghttp2_mem *mem;
mem = deflater->ctx.mem;
nghttp2_hd_deflate_free(deflater);
nghttp2_mem_free(mem, deflater);
}
static void hd_inflate_set_huffman_encoded(nghttp2_hd_inflater *inflater,
const uint8_t *in) {
inflater->huffman_encoded = (*in & (1 << 7)) != 0;
}
static ssize_t hd_inflate_read_len(nghttp2_hd_inflater *inflater, int *rfin,
const uint8_t *in, const uint8_t *last,
size_t prefix, size_t maxlen) {
ssize_t rv;
uint32_t out;
*rfin = 0;
rv = decode_length(&out, &inflater->shift, rfin, (uint32_t)inflater->left,
inflater->shift, in, last, prefix);
if (rv == -1) {
DEBUGF(fprintf(stderr, "inflatehd: integer decoding failed\n"));
return NGHTTP2_ERR_HEADER_COMP;
}
if (out > maxlen) {
DEBUGF(fprintf(
stderr, "inflatehd: integer exceeded the maximum value %zu\n", maxlen));
return NGHTTP2_ERR_HEADER_COMP;
}
inflater->left = out;
DEBUGF(fprintf(stderr, "inflatehd: decoded integer is %u\n", out));
return rv;
}
static ssize_t hd_inflate_read_huff(nghttp2_hd_inflater *inflater,
nghttp2_buf *buf, const uint8_t *in,
const uint8_t *last) {
ssize_t readlen;
int final = 0;
if ((size_t)(last - in) >= inflater->left) {
last = in + inflater->left;
final = 1;
}
readlen = nghttp2_hd_huff_decode(&inflater->huff_decode_ctx, buf, in,
(size_t)(last - in), final);
if (readlen < 0) {
DEBUGF(fprintf(stderr, "inflatehd: huffman decoding failed\n"));
return readlen;
}
inflater->left -= (size_t)readlen;
return readlen;
}
static ssize_t hd_inflate_read(nghttp2_hd_inflater *inflater, nghttp2_buf *buf,
const uint8_t *in, const uint8_t *last) {
size_t len = nghttp2_min((size_t)(last - in), inflater->left);
buf->last = nghttp2_cpymem(buf->last, in, len);
inflater->left -= len;
return (ssize_t)len;
}
static int hd_inflate_commit_indexed(nghttp2_hd_inflater *inflater,
nghttp2_hd_nv *nv_out) {
nghttp2_hd_nv nv = nghttp2_hd_table_get(&inflater->ctx, inflater->index);
emit_header(nv_out, &nv);
return 0;
}
static int hd_inflate_commit_newname(nghttp2_hd_inflater *inflater,
nghttp2_hd_nv *nv_out) {
nghttp2_hd_nv nv;
int rv;
if (inflater->no_index) {
nv.flags = NGHTTP2_NV_FLAG_NO_INDEX;
} else {
nv.flags = NGHTTP2_NV_FLAG_NONE;
}
nv.name = inflater->namercbuf;
nv.value = inflater->valuercbuf;
nv.token = lookup_token(inflater->namercbuf->base, inflater->namercbuf->len);
if (inflater->index_required) {
rv = add_hd_table_incremental(&inflater->ctx, &nv, NULL, 0);
if (rv != 0) {
return rv;
}
}
emit_header(nv_out, &nv);
inflater->nv_name_keep = nv.name;
inflater->nv_value_keep = nv.value;
inflater->namercbuf = NULL;
inflater->valuercbuf = NULL;
return 0;
}
static int hd_inflate_commit_indname(nghttp2_hd_inflater *inflater,
nghttp2_hd_nv *nv_out) {
nghttp2_hd_nv nv;
int rv;
nv = nghttp2_hd_table_get(&inflater->ctx, inflater->index);
if (inflater->no_index) {
nv.flags = NGHTTP2_NV_FLAG_NO_INDEX;
} else {
nv.flags = NGHTTP2_NV_FLAG_NONE;
}
nghttp2_rcbuf_incref(nv.name);
nv.value = inflater->valuercbuf;
if (inflater->index_required) {
rv = add_hd_table_incremental(&inflater->ctx, &nv, NULL, 0);
if (rv != 0) {
nghttp2_rcbuf_decref(nv.name);
return NGHTTP2_ERR_NOMEM;
}
}
emit_header(nv_out, &nv);
inflater->nv_name_keep = nv.name;
inflater->nv_value_keep = nv.value;
inflater->valuercbuf = NULL;
return 0;
}
ssize_t nghttp2_hd_inflate_hd(nghttp2_hd_inflater *inflater, nghttp2_nv *nv_out,
int *inflate_flags, uint8_t *in, size_t inlen,
int in_final) {
return nghttp2_hd_inflate_hd2(inflater, nv_out, inflate_flags, in, inlen,
in_final);
}
ssize_t nghttp2_hd_inflate_hd2(nghttp2_hd_inflater *inflater,
nghttp2_nv *nv_out, int *inflate_flags,
const uint8_t *in, size_t inlen, int in_final) {
ssize_t rv;
nghttp2_hd_nv hd_nv;
rv = nghttp2_hd_inflate_hd_nv(inflater, &hd_nv, inflate_flags, in, inlen,
in_final);
if (rv < 0) {
return rv;
}
if (*inflate_flags & NGHTTP2_HD_INFLATE_EMIT) {
nv_out->name = hd_nv.name->base;
nv_out->namelen = hd_nv.name->len;
nv_out->value = hd_nv.value->base;
nv_out->valuelen = hd_nv.value->len;
nv_out->flags = hd_nv.flags;
}
return rv;
}
ssize_t nghttp2_hd_inflate_hd_nv(nghttp2_hd_inflater *inflater,
nghttp2_hd_nv *nv_out, int *inflate_flags,
const uint8_t *in, size_t inlen,
int in_final) {
ssize_t rv = 0;
const uint8_t *first = in;
const uint8_t *last = in + inlen;
int rfin = 0;
int busy = 0;
nghttp2_mem *mem;
mem = inflater->ctx.mem;
if (inflater->ctx.bad) {
return NGHTTP2_ERR_HEADER_COMP;
}
DEBUGF(fprintf(stderr, "inflatehd: start state=%d\n", inflater->state));
hd_inflate_keep_free(inflater);
*inflate_flags = NGHTTP2_HD_INFLATE_NONE;
for (; in != last || busy;) {
busy = 0;
switch (inflater->state) {
case NGHTTP2_HD_STATE_EXPECT_TABLE_SIZE:
if ((*in & 0xe0u) != 0x20u) {
DEBUGF(fprintf(stderr, "inflatehd: header table size change was "
"expected, but saw 0x%02x as first byte",
*in));
rv = NGHTTP2_ERR_HEADER_COMP;
goto fail;
}
case NGHTTP2_HD_STATE_INFLATE_START:
case NGHTTP2_HD_STATE_OPCODE:
if ((*in & 0xe0u) == 0x20u) {
DEBUGF(fprintf(stderr, "inflatehd: header table size change\n"));
if (inflater->state == NGHTTP2_HD_STATE_OPCODE) {
DEBUGF(fprintf(stderr, "inflatehd: header table size change must "
"appear at the head of header block\n"));
rv = NGHTTP2_ERR_HEADER_COMP;
goto fail;
}
inflater->opcode = NGHTTP2_HD_OPCODE_INDEXED;
inflater->state = NGHTTP2_HD_STATE_READ_TABLE_SIZE;
} else if (*in & 0x80u) {
DEBUGF(fprintf(stderr, "inflatehd: indexed repr\n"));
inflater->opcode = NGHTTP2_HD_OPCODE_INDEXED;
inflater->state = NGHTTP2_HD_STATE_READ_INDEX;
} else {
if (*in == 0x40u || *in == 0 || *in == 0x10u) {
DEBUGF(
fprintf(stderr, "inflatehd: literal header repr - new name\n"));
inflater->opcode = NGHTTP2_HD_OPCODE_NEWNAME;
inflater->state = NGHTTP2_HD_STATE_NEWNAME_CHECK_NAMELEN;
} else {
DEBUGF(fprintf(stderr,
"inflatehd: literal header repr - indexed name\n"));
inflater->opcode = NGHTTP2_HD_OPCODE_INDNAME;
inflater->state = NGHTTP2_HD_STATE_READ_INDEX;
}
inflater->index_required = (*in & 0x40) != 0;
inflater->no_index = (*in & 0xf0u) == 0x10u;
DEBUGF(fprintf(stderr, "inflatehd: indexing required=%d, no_index=%d\n",
inflater->index_required, inflater->no_index));
if (inflater->opcode == NGHTTP2_HD_OPCODE_NEWNAME) {
++in;
}
}
inflater->left = 0;
inflater->shift = 0;
break;
case NGHTTP2_HD_STATE_READ_TABLE_SIZE:
rfin = 0;
rv = hd_inflate_read_len(
inflater, &rfin, in, last, 5,
nghttp2_min(inflater->min_hd_table_bufsize_max,
inflater->settings_hd_table_bufsize_max));
if (rv < 0) {
goto fail;
}
in += rv;
if (!rfin) {
goto almost_ok;
}
DEBUGF(fprintf(stderr, "inflatehd: table_size=%zu\n", inflater->left));
inflater->min_hd_table_bufsize_max = UINT32_MAX;
inflater->ctx.hd_table_bufsize_max = inflater->left;
hd_context_shrink_table_size(&inflater->ctx, NULL);
inflater->state = NGHTTP2_HD_STATE_INFLATE_START;
break;
case NGHTTP2_HD_STATE_READ_INDEX: {
size_t prefixlen;
if (inflater->opcode == NGHTTP2_HD_OPCODE_INDEXED) {
prefixlen = 7;
} else if (inflater->index_required) {
prefixlen = 6;
} else {
prefixlen = 4;
}
rfin = 0;
rv = hd_inflate_read_len(inflater, &rfin, in, last, prefixlen,
get_max_index(&inflater->ctx) + 1);
if (rv < 0) {
goto fail;
}
in += rv;
if (!rfin) {
goto almost_ok;
}
if (inflater->left == 0) {
rv = NGHTTP2_ERR_HEADER_COMP;
goto fail;
}
DEBUGF(fprintf(stderr, "inflatehd: index=%zu\n", inflater->left));
if (inflater->opcode == NGHTTP2_HD_OPCODE_INDEXED) {
inflater->index = inflater->left;
--inflater->index;
rv = hd_inflate_commit_indexed(inflater, nv_out);
if (rv < 0) {
goto fail;
}
inflater->state = NGHTTP2_HD_STATE_OPCODE;
if (rv == 0) {
*inflate_flags |= NGHTTP2_HD_INFLATE_EMIT;
return (ssize_t)(in - first);
}
} else {
inflater->index = inflater->left;
--inflater->index;
inflater->state = NGHTTP2_HD_STATE_CHECK_VALUELEN;
}
break;
}
case NGHTTP2_HD_STATE_NEWNAME_CHECK_NAMELEN:
hd_inflate_set_huffman_encoded(inflater, in);
inflater->state = NGHTTP2_HD_STATE_NEWNAME_READ_NAMELEN;
inflater->left = 0;
inflater->shift = 0;
DEBUGF(fprintf(stderr, "inflatehd: huffman encoded=%d\n",
inflater->huffman_encoded != 0));
case NGHTTP2_HD_STATE_NEWNAME_READ_NAMELEN:
rfin = 0;
rv = hd_inflate_read_len(inflater, &rfin, in, last, 7, NGHTTP2_HD_MAX_NV);
if (rv < 0) {
goto fail;
}
in += rv;
if (!rfin) {
DEBUGF(fprintf(stderr,
"inflatehd: integer not fully decoded. current=%zu\n",
inflater->left));
goto almost_ok;
}
if (inflater->huffman_encoded) {
nghttp2_hd_huff_decode_context_init(&inflater->huff_decode_ctx);
inflater->state = NGHTTP2_HD_STATE_NEWNAME_READ_NAMEHUFF;
rv = nghttp2_rcbuf_new(&inflater->namercbuf, inflater->left * 2 + 1,
mem);
} else {
inflater->state = NGHTTP2_HD_STATE_NEWNAME_READ_NAME;
rv = nghttp2_rcbuf_new(&inflater->namercbuf, inflater->left + 1, mem);
}
if (rv != 0) {
goto fail;
}
nghttp2_buf_wrap_init(&inflater->namebuf, inflater->namercbuf->base,
inflater->namercbuf->len);
break;
case NGHTTP2_HD_STATE_NEWNAME_READ_NAMEHUFF:
rv = hd_inflate_read_huff(inflater, &inflater->namebuf, in, last);
if (rv < 0) {
goto fail;
}
in += rv;
DEBUGF(fprintf(stderr, "inflatehd: %zd bytes read\n", rv));
if (inflater->left) {
DEBUGF(fprintf(stderr, "inflatehd: still %zu bytes to go\n",
inflater->left));
goto almost_ok;
}
*inflater->namebuf.last = '\0';
inflater->namercbuf->len = nghttp2_buf_len(&inflater->namebuf);
inflater->state = NGHTTP2_HD_STATE_CHECK_VALUELEN;
break;
case NGHTTP2_HD_STATE_NEWNAME_READ_NAME:
rv = hd_inflate_read(inflater, &inflater->namebuf, in, last);
if (rv < 0) {
goto fail;
}
in += rv;
DEBUGF(fprintf(stderr, "inflatehd: %zd bytes read\n", rv));
if (inflater->left) {
DEBUGF(fprintf(stderr, "inflatehd: still %zu bytes to go\n",
inflater->left));
goto almost_ok;
}
*inflater->namebuf.last = '\0';
inflater->namercbuf->len = nghttp2_buf_len(&inflater->namebuf);
inflater->state = NGHTTP2_HD_STATE_CHECK_VALUELEN;
break;
case NGHTTP2_HD_STATE_CHECK_VALUELEN:
hd_inflate_set_huffman_encoded(inflater, in);
inflater->state = NGHTTP2_HD_STATE_READ_VALUELEN;
inflater->left = 0;
inflater->shift = 0;
DEBUGF(fprintf(stderr, "inflatehd: huffman encoded=%d\n",
inflater->huffman_encoded != 0));
case NGHTTP2_HD_STATE_READ_VALUELEN:
rfin = 0;
rv = hd_inflate_read_len(inflater, &rfin, in, last, 7, NGHTTP2_HD_MAX_NV);
if (rv < 0) {
goto fail;
}
in += rv;
if (!rfin) {
goto almost_ok;
}
DEBUGF(fprintf(stderr, "inflatehd: valuelen=%zu\n", inflater->left));
if (inflater->huffman_encoded) {
nghttp2_hd_huff_decode_context_init(&inflater->huff_decode_ctx);
inflater->state = NGHTTP2_HD_STATE_READ_VALUEHUFF;
rv = nghttp2_rcbuf_new(&inflater->valuercbuf, inflater->left * 2 + 1,
mem);
} else {
inflater->state = NGHTTP2_HD_STATE_READ_VALUE;
rv = nghttp2_rcbuf_new(&inflater->valuercbuf, inflater->left + 1, mem);
}
if (rv != 0) {
goto fail;
}
nghttp2_buf_wrap_init(&inflater->valuebuf, inflater->valuercbuf->base,
inflater->valuercbuf->len);
busy = 1;
break;
case NGHTTP2_HD_STATE_READ_VALUEHUFF:
rv = hd_inflate_read_huff(inflater, &inflater->valuebuf, in, last);
if (rv < 0) {
goto fail;
}
in += rv;
DEBUGF(fprintf(stderr, "inflatehd: %zd bytes read\n", rv));
if (inflater->left) {
DEBUGF(fprintf(stderr, "inflatehd: still %zu bytes to go\n",
inflater->left));
goto almost_ok;
}
*inflater->valuebuf.last = '\0';
inflater->valuercbuf->len = nghttp2_buf_len(&inflater->valuebuf);
if (inflater->opcode == NGHTTP2_HD_OPCODE_NEWNAME) {
rv = hd_inflate_commit_newname(inflater, nv_out);
} else {
rv = hd_inflate_commit_indname(inflater, nv_out);
}
if (rv != 0) {
goto fail;
}
inflater->state = NGHTTP2_HD_STATE_OPCODE;
*inflate_flags |= NGHTTP2_HD_INFLATE_EMIT;
return (ssize_t)(in - first);
case NGHTTP2_HD_STATE_READ_VALUE:
rv = hd_inflate_read(inflater, &inflater->valuebuf, in, last);
if (rv < 0) {
DEBUGF(fprintf(stderr, "inflatehd: value read failure %zd: %s\n", rv,
nghttp2_strerror((int)rv)));
goto fail;
}
in += rv;
DEBUGF(fprintf(stderr, "inflatehd: %zd bytes read\n", rv));
if (inflater->left) {
DEBUGF(fprintf(stderr, "inflatehd: still %zu bytes to go\n",
inflater->left));
goto almost_ok;
}
*inflater->valuebuf.last = '\0';
inflater->valuercbuf->len = nghttp2_buf_len(&inflater->valuebuf);
if (inflater->opcode == NGHTTP2_HD_OPCODE_NEWNAME) {
rv = hd_inflate_commit_newname(inflater, nv_out);
} else {
rv = hd_inflate_commit_indname(inflater, nv_out);
}
if (rv != 0) {
goto fail;
}
inflater->state = NGHTTP2_HD_STATE_OPCODE;
*inflate_flags |= NGHTTP2_HD_INFLATE_EMIT;
return (ssize_t)(in - first);
}
}
assert(in == last);
DEBUGF(fprintf(stderr, "inflatehd: all input bytes were processed\n"));
if (in_final) {
DEBUGF(fprintf(stderr, "inflatehd: in_final set\n"));
if (inflater->state != NGHTTP2_HD_STATE_OPCODE &&
inflater->state != NGHTTP2_HD_STATE_INFLATE_START) {
DEBUGF(fprintf(stderr, "inflatehd: unacceptable state=%d\n",
inflater->state));
rv = NGHTTP2_ERR_HEADER_COMP;
goto fail;
}
*inflate_flags |= NGHTTP2_HD_INFLATE_FINAL;
}
return (ssize_t)(in - first);
almost_ok:
if (in_final) {
DEBUGF(fprintf(stderr, "inflatehd: input ended prematurely\n"));
rv = NGHTTP2_ERR_HEADER_COMP;
goto fail;
}
return (ssize_t)(in - first);
fail:
DEBUGF(fprintf(stderr, "inflatehd: error return %zd\n", rv));
inflater->ctx.bad = 1;
return rv;
}
int nghttp2_hd_inflate_end_headers(nghttp2_hd_inflater *inflater) {
hd_inflate_keep_free(inflater);
inflater->state = NGHTTP2_HD_STATE_INFLATE_START;
return 0;
}
int nghttp2_hd_inflate_new(nghttp2_hd_inflater **inflater_ptr) {
return nghttp2_hd_inflate_new2(inflater_ptr, NULL);
}
int nghttp2_hd_inflate_new2(nghttp2_hd_inflater **inflater_ptr,
nghttp2_mem *mem) {
int rv;
nghttp2_hd_inflater *inflater;
if (mem == NULL) {
mem = nghttp2_mem_default();
}
inflater = (nghttp2_hd_inflater *)nghttp2_mem_malloc(mem, sizeof(nghttp2_hd_inflater));
if (inflater == NULL) {
return NGHTTP2_ERR_NOMEM;
}
rv = nghttp2_hd_inflate_init(inflater, mem);
if (rv != 0) {
nghttp2_mem_free(mem, inflater);
return rv;
}
*inflater_ptr = inflater;
return 0;
}
void nghttp2_hd_inflate_del(nghttp2_hd_inflater *inflater) {
nghttp2_mem *mem;
mem = inflater->ctx.mem;
nghttp2_hd_inflate_free(inflater);
nghttp2_mem_free(mem, inflater);
}
int nghttp2_hd_emit_indname_block(nghttp2_bufs *bufs, size_t idx,
nghttp2_nv *nv, int indexing_mode) {
return emit_indname_block(bufs, idx, nv, indexing_mode);
}
int nghttp2_hd_emit_newname_block(nghttp2_bufs *bufs, nghttp2_nv *nv,
int indexing_mode) {
return emit_newname_block(bufs, nv, indexing_mode);
}
int nghttp2_hd_emit_table_size(nghttp2_bufs *bufs, size_t table_size) {
return emit_table_size(bufs, table_size);
}
ssize_t nghttp2_hd_decode_length(uint32_t *res, size_t *shift_ptr, int *final,
uint32_t initial, size_t shift, uint8_t *in,
uint8_t *last, size_t prefix) {
return decode_length(res, shift_ptr, final, initial, shift, in, last, prefix);
}
static size_t hd_get_num_table_entries(nghttp2_hd_context *context) {
return context->hd_table.len + NGHTTP2_STATIC_TABLE_LENGTH;
}
static const nghttp2_nv *hd_get_table_entry(nghttp2_hd_context *context,
size_t idx) {
if (idx == 0) {
return NULL;
}
--idx;
if (!INDEX_RANGE_VALID(context, idx)) {
return NULL;
}
return nghttp2_hd_table_get2(context, idx);
}
size_t nghttp2_hd_deflate_get_num_table_entries(nghttp2_hd_deflater *deflater) {
return hd_get_num_table_entries(&deflater->ctx);
}
const nghttp2_nv *
nghttp2_hd_deflate_get_table_entry(nghttp2_hd_deflater *deflater, size_t idx) {
return hd_get_table_entry(&deflater->ctx, idx);
}
size_t
nghttp2_hd_deflate_get_dynamic_table_size(nghttp2_hd_deflater *deflater) {
return deflater->ctx.hd_table_bufsize;
}
size_t
nghttp2_hd_deflate_get_max_dynamic_table_size(nghttp2_hd_deflater *deflater) {
return deflater->ctx.hd_table_bufsize_max;
}
size_t nghttp2_hd_inflate_get_num_table_entries(nghttp2_hd_inflater *inflater) {
return hd_get_num_table_entries(&inflater->ctx);
}
const nghttp2_nv *
nghttp2_hd_inflate_get_table_entry(nghttp2_hd_inflater *inflater, size_t idx) {
return hd_get_table_entry(&inflater->ctx, idx);
}
size_t
nghttp2_hd_inflate_get_dynamic_table_size(nghttp2_hd_inflater *inflater) {
return inflater->ctx.hd_table_bufsize;
}
size_t
nghttp2_hd_inflate_get_max_dynamic_table_size(nghttp2_hd_inflater *inflater) {
return inflater->ctx.hd_table_bufsize_max;
}
