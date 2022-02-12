static void
ipv6_fvalue_set(fvalue_t *fv, const guint8 *value)
{
memcpy(fv->value.ipv6.addr.bytes, value, FT_IPv6_LEN);
fv->value.ipv6.prefix = 128;
}
static gboolean
ipv6_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg)
{
const char *has_slash;
char *addr_str;
unsigned int nmask_bits;
fvalue_t *nmask_fvalue;
gboolean free_addr_str = FALSE;
if ((has_slash = strchr(s, '/'))) {
addr_str = wmem_strndup(NULL, s, has_slash-s);
free_addr_str = TRUE;
}
else
addr_str = (char*)s;
if (!get_host_ipaddr6(addr_str, &(fv->value.ipv6.addr))) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid hostname or IPv6 address.", s);
if (free_addr_str)
wmem_free(NULL, addr_str);
return FALSE;
}
if (free_addr_str)
wmem_free(NULL, addr_str);
if (has_slash) {
nmask_fvalue = fvalue_from_unparsed(FT_UINT32, has_slash+1, FALSE, err_msg);
if (!nmask_fvalue) {
return FALSE;
}
nmask_bits = fvalue_get_uinteger(nmask_fvalue);
FVALUE_FREE(nmask_fvalue);
if (nmask_bits > 128) {
if (err_msg != NULL) {
*err_msg = g_strdup_printf("Prefix in a IPv6 address should be <= 128, not %u",
nmask_bits);
}
return FALSE;
}
fv->value.ipv6.prefix = nmask_bits;
} else {
fv->value.ipv6.prefix = 128;
}
return TRUE;
}
static int
ipv6_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 39;
}
static void
ipv6_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf)
{
ip6_to_str_buf(&(fv->value.ipv6.addr), buf);
}
static gpointer
value_get(fvalue_t *fv)
{
return fv->value.ipv6.addr.bytes;
}
static gint
cmp_compare(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
const ipv6_addr *a = &(fv_a->value.ipv6);
const ipv6_addr *b = &(fv_b->value.ipv6);
guint32 prefix;
int pos = 0;
prefix = MIN(a->prefix, b->prefix);
prefix = MIN(prefix, 128);
while (prefix >= 8) {
gint byte_a = (gint) (a->addr.bytes[pos]);
gint byte_b = (gint) (b->addr.bytes[pos]);
if (byte_a != byte_b)
return byte_a - byte_b;
prefix -= 8;
pos++;
}
if (prefix != 0) {
gint byte_a = (gint) (a->addr.bytes[pos] & (bitmasks[prefix]));
gint byte_b = (gint) (b->addr.bytes[pos] & (bitmasks[prefix]));
if (byte_a != byte_b)
return byte_a - byte_b;
}
return 0;
}
static gboolean
cmp_eq(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
return (cmp_compare(fv_a, fv_b) == 0);
}
static gboolean
cmp_ne(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
return (cmp_compare(fv_a, fv_b) != 0);
}
static gboolean
cmp_gt(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
return (cmp_compare(fv_a, fv_b) > 0);
}
static gboolean
cmp_ge(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
return (cmp_compare(fv_a, fv_b) >= 0);
}
static gboolean
cmp_lt(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
return (cmp_compare(fv_a, fv_b) < 0);
}
static gboolean
cmp_le(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
return (cmp_compare(fv_a, fv_b) <= 0);
}
static gboolean
cmp_bitwise_and(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
const ipv6_addr *a = &(fv_a->value.ipv6);
const ipv6_addr *b = &(fv_b->value.ipv6);
guint32 prefix;
int pos = 0;
prefix = MIN(a->prefix, b->prefix);
prefix = MIN(prefix, 128);
while (prefix >= 8) {
if (a->addr.bytes[pos] & b->addr.bytes[pos])
return TRUE;
prefix -= 8;
pos++;
}
if (prefix != 0) {
guint8 byte_a = (a->addr.bytes[pos] & (bitmasks[prefix]));
guint8 byte_b = (b->addr.bytes[pos] & (bitmasks[prefix]));
if (byte_a & byte_b)
return TRUE;
}
return FALSE;
}
static void
slice(fvalue_t *fv, GByteArray *bytes, guint offset, guint length)
{
guint8* data;
data = fv->value.ipv6.addr.bytes + offset;
g_byte_array_append(bytes, data, length);
}
void
ftype_register_ipv6(void)
{
static ftype_t ipv6_type = {
FT_IPv6,
"FT_IPv6",
"IPv6 address",
FT_IPv6_LEN,
NULL,
NULL,
ipv6_from_unparsed,
NULL,
ipv6_to_repr,
ipv6_repr_len,
NULL,
ipv6_fvalue_set,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
value_get,
NULL,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
slice,
};
ftype_register(FT_IPv6, &ipv6_type);
}
