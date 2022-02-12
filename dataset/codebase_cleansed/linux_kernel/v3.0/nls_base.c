int utf8_to_utf32(const u8 *s, int len, unicode_t *pu)
{
unsigned long l;
int c0, c, nc;
const struct utf8_table *t;
nc = 0;
c0 = *s;
l = c0;
for (t = utf8_table; t->cmask; t++) {
nc++;
if ((c0 & t->cmask) == t->cval) {
l &= t->lmask;
if (l < t->lval || l > UNICODE_MAX ||
(l & SURROGATE_MASK) == SURROGATE_PAIR)
return -1;
*pu = (unicode_t) l;
return nc;
}
if (len <= nc)
return -1;
s++;
c = (*s ^ 0x80) & 0xFF;
if (c & 0xC0)
return -1;
l = (l << 6) | c;
}
return -1;
}
int utf32_to_utf8(unicode_t u, u8 *s, int maxlen)
{
unsigned long l;
int c, nc;
const struct utf8_table *t;
if (!s)
return 0;
l = u;
if (l > UNICODE_MAX || (l & SURROGATE_MASK) == SURROGATE_PAIR)
return -1;
nc = 0;
for (t = utf8_table; t->cmask && maxlen; t++, maxlen--) {
nc++;
if (l <= t->lmask) {
c = t->shift;
*s = (u8) (t->cval | (l >> c));
while (c > 0) {
c -= 6;
s++;
*s = (u8) (0x80 | ((l >> c) & 0x3F));
}
return nc;
}
}
return -1;
}
int utf8s_to_utf16s(const u8 *s, int len, wchar_t *pwcs)
{
u16 *op;
int size;
unicode_t u;
op = pwcs;
while (*s && len > 0) {
if (*s & 0x80) {
size = utf8_to_utf32(s, len, &u);
if (size < 0)
return -EINVAL;
if (u >= PLANE_SIZE) {
u -= PLANE_SIZE;
*op++ = (wchar_t) (SURROGATE_PAIR |
((u >> 10) & SURROGATE_BITS));
*op++ = (wchar_t) (SURROGATE_PAIR |
SURROGATE_LOW |
(u & SURROGATE_BITS));
} else {
*op++ = (wchar_t) u;
}
s += size;
len -= size;
} else {
*op++ = *s++;
len--;
}
}
return op - pwcs;
}
static inline unsigned long get_utf16(unsigned c, enum utf16_endian endian)
{
switch (endian) {
default:
return c;
case UTF16_LITTLE_ENDIAN:
return __le16_to_cpu(c);
case UTF16_BIG_ENDIAN:
return __be16_to_cpu(c);
}
}
int utf16s_to_utf8s(const wchar_t *pwcs, int len, enum utf16_endian endian,
u8 *s, int maxlen)
{
u8 *op;
int size;
unsigned long u, v;
op = s;
while (len > 0 && maxlen > 0) {
u = get_utf16(*pwcs, endian);
if (!u)
break;
pwcs++;
len--;
if (u > 0x7f) {
if ((u & SURROGATE_MASK) == SURROGATE_PAIR) {
if (u & SURROGATE_LOW) {
continue;
}
if (len <= 0)
break;
v = get_utf16(*pwcs, endian);
if ((v & SURROGATE_MASK) != SURROGATE_PAIR ||
!(v & SURROGATE_LOW)) {
continue;
}
u = PLANE_SIZE + ((u & SURROGATE_BITS) << 10)
+ (v & SURROGATE_BITS);
pwcs++;
len--;
}
size = utf32_to_utf8(u, op, maxlen);
if (size == -1) {
} else {
op += size;
maxlen -= size;
}
} else {
*op++ = (u8) u;
maxlen--;
}
}
return op - s;
}
int register_nls(struct nls_table * nls)
{
struct nls_table ** tmp = &tables;
if (nls->next)
return -EBUSY;
spin_lock(&nls_lock);
while (*tmp) {
if (nls == *tmp) {
spin_unlock(&nls_lock);
return -EBUSY;
}
tmp = &(*tmp)->next;
}
nls->next = tables;
tables = nls;
spin_unlock(&nls_lock);
return 0;
}
int unregister_nls(struct nls_table * nls)
{
struct nls_table ** tmp = &tables;
spin_lock(&nls_lock);
while (*tmp) {
if (nls == *tmp) {
*tmp = nls->next;
spin_unlock(&nls_lock);
return 0;
}
tmp = &(*tmp)->next;
}
spin_unlock(&nls_lock);
return -EINVAL;
}
static struct nls_table *find_nls(char *charset)
{
struct nls_table *nls;
spin_lock(&nls_lock);
for (nls = tables; nls; nls = nls->next) {
if (!strcmp(nls->charset, charset))
break;
if (nls->alias && !strcmp(nls->alias, charset))
break;
}
if (nls && !try_module_get(nls->owner))
nls = NULL;
spin_unlock(&nls_lock);
return nls;
}
struct nls_table *load_nls(char *charset)
{
return try_then_request_module(find_nls(charset), "nls_%s", charset);
}
void unload_nls(struct nls_table *nls)
{
if (nls)
module_put(nls->owner);
}
static int uni2char(wchar_t uni, unsigned char *out, int boundlen)
{
const unsigned char *uni2charset;
unsigned char cl = uni & 0x00ff;
unsigned char ch = (uni & 0xff00) >> 8;
if (boundlen <= 0)
return -ENAMETOOLONG;
uni2charset = page_uni2charset[ch];
if (uni2charset && uni2charset[cl])
out[0] = uni2charset[cl];
else
return -EINVAL;
return 1;
}
static int char2uni(const unsigned char *rawstring, int boundlen, wchar_t *uni)
{
*uni = charset2uni[*rawstring];
if (*uni == 0x0000)
return -EINVAL;
return 1;
}
struct nls_table *load_nls_default(void)
{
struct nls_table *default_nls;
default_nls = load_nls(CONFIG_NLS_DEFAULT);
if (default_nls != NULL)
return default_nls;
else
return &default_table;
}
