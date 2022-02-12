static void
bytes_fvalue_new(fvalue_t *fv)
{
fv->value.bytes = NULL;
}
static void
bytes_fvalue_free(fvalue_t *fv)
{
if (fv->value.bytes) {
g_byte_array_free(fv->value.bytes, TRUE);
fv->value.bytes=NULL;
}
}
static void
bytes_fvalue_set(fvalue_t *fv, GByteArray *value)
{
bytes_fvalue_free(fv);
fv->value.bytes = value;
}
static int
bytes_repr_len(fvalue_t *fv, ftrepr_t rtype _U_)
{
if (fv->value.bytes->len == 0) {
return 0;
} else {
return fv->value.bytes->len * 3 - 1;
}
}
static int
oid_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_)
{
return OID_REPR_LEN(fv);
}
static void
oid_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, char *buf)
{
const char* oid_str = oid_encoded2string(fv->value.bytes->data,fv->value.bytes->len);
strncpy(buf,oid_str,OID_REPR_LEN(fv));
}
static int
rel_oid_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_)
{
return REL_OID_REPR_LEN(fv);
}
static void
rel_oid_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, char *buf)
{
const char* oid_str = rel_oid_encoded2string(fv->value.bytes->data,fv->value.bytes->len);
*buf++ = '.';
strncpy(buf,oid_str,REL_OID_REPR_LEN(fv));
}
static void
system_id_to_repr(fvalue_t *fv, ftrepr_t rtype, char *buf)
{
print_system_id_buf(fv->value.bytes->data,fv->value.bytes->len, buf, bytes_repr_len(fv, rtype));
}
static void
bytes_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, char *buf)
{
guint8 *c;
char *write_cursor;
unsigned int i;
c = fv->value.bytes->data;
write_cursor = buf;
for (i = 0; i < fv->value.bytes->len; i++) {
if (i == 0) {
sprintf(write_cursor, "%02x", *c++);
write_cursor += 2;
}
else {
sprintf(write_cursor, ":%02x", *c++);
write_cursor += 3;
}
}
}
static void
common_fvalue_set(fvalue_t *fv, const guint8* data, guint len)
{
bytes_fvalue_free(fv);
fv->value.bytes = g_byte_array_new();
g_byte_array_append(fv->value.bytes, data, len);
}
static void
ax25_fvalue_set(fvalue_t *fv, const guint8 *value)
{
common_fvalue_set(fv, value, FT_AX25_ADDR_LEN);
}
static void
vines_fvalue_set(fvalue_t *fv, const guint8 *value)
{
common_fvalue_set(fv, value, FT_VINES_ADDR_LEN);
}
static void
ether_fvalue_set(fvalue_t *fv, const guint8 *value)
{
common_fvalue_set(fv, value, FT_ETHER_LEN);
}
static void
oid_fvalue_set(fvalue_t *fv, GByteArray *value)
{
bytes_fvalue_free(fv);
fv->value.bytes = value;
}
static void
system_id_fvalue_set(fvalue_t *fv, GByteArray *value)
{
bytes_fvalue_free(fv);
fv->value.bytes = value;
}
static gpointer
value_get(fvalue_t *fv)
{
return fv->value.bytes->data;
}
static gboolean
bytes_from_string(fvalue_t *fv, const char *s, LogFunc logfunc _U_)
{
GByteArray *bytes;
bytes = g_byte_array_new();
g_byte_array_append(bytes, (const guint8 *)s, (guint)strlen(s));
bytes_fvalue_free(fv);
fv->value.bytes = bytes;
return TRUE;
}
static gboolean
bytes_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, LogFunc logfunc)
{
GByteArray *bytes;
gboolean res;
bytes = g_byte_array_new();
res = hex_str_to_bytes(s, bytes, TRUE);
if (!res) {
if (logfunc != NULL)
logfunc("\"%s\" is not a valid byte string.", s);
g_byte_array_free(bytes, TRUE);
return FALSE;
}
bytes_fvalue_free(fv);
fv->value.bytes = bytes;
return TRUE;
}
static gboolean
ax25_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, LogFunc logfunc)
{
if (bytes_from_unparsed(fv, s, TRUE, NULL)) {
if (fv->value.bytes->len > FT_AX25_ADDR_LEN) {
logfunc("\"%s\" contains too many bytes to be a valid AX.25 address.",
s);
return FALSE;
}
else if (fv->value.bytes->len < FT_AX25_ADDR_LEN && !allow_partial_value) {
logfunc("\"%s\" contains too few bytes to be a valid AX.25 address.",
s);
return FALSE;
}
return TRUE;
}
logfunc("\"%s\" is not a valid AX.25 address.", s);
return FALSE;
}
static gboolean
vines_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, LogFunc logfunc)
{
if (bytes_from_unparsed(fv, s, TRUE, NULL)) {
if (fv->value.bytes->len > FT_VINES_ADDR_LEN) {
logfunc("\"%s\" contains too many bytes to be a valid Vines address.",
s);
return FALSE;
}
else if (fv->value.bytes->len < FT_VINES_ADDR_LEN && !allow_partial_value) {
logfunc("\"%s\" contains too few bytes to be a valid Vines address.",
s);
return FALSE;
}
return TRUE;
}
logfunc("\"%s\" is not a valid Vines address.", s);
return FALSE;
}
static gboolean
ether_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, LogFunc logfunc)
{
guint8 *mac;
if (bytes_from_unparsed(fv, s, TRUE, NULL)) {
if (fv->value.bytes->len > FT_ETHER_LEN) {
logfunc("\"%s\" contains too many bytes to be a valid Ethernet address.",
s);
return FALSE;
}
else if (fv->value.bytes->len < FT_ETHER_LEN && !allow_partial_value) {
logfunc("\"%s\" contains too few bytes to be a valid Ethernet address.",
s);
return FALSE;
}
return TRUE;
}
mac = get_ether_addr(s);
if (!mac) {
logfunc("\"%s\" is not a valid hostname or Ethernet address.",
s);
return FALSE;
}
ether_fvalue_set(fv, mac);
return TRUE;
}
static gboolean
oid_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, LogFunc logfunc)
{
GByteArray *bytes;
gboolean res;
bytes = g_byte_array_new();
res = oid_str_to_bytes(s, bytes);
if (!res) {
if (logfunc != NULL)
logfunc("\"%s\" is not a valid OBJECT IDENTIFIER.", s);
g_byte_array_free(bytes, TRUE);
return FALSE;
}
bytes_fvalue_free(fv);
fv->value.bytes = bytes;
return TRUE;
}
static gboolean
rel_oid_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, LogFunc logfunc)
{
GByteArray *bytes;
gboolean res;
bytes = g_byte_array_new();
res = rel_oid_str_to_bytes(s, bytes, FALSE);
if (!res) {
if (logfunc != NULL)
logfunc("\"%s\" is not a valid RELATIVE-OID.", s);
g_byte_array_free(bytes, TRUE);
return FALSE;
}
bytes_fvalue_free(fv);
fv->value.bytes = bytes;
return TRUE;
}
static gboolean
system_id_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, LogFunc logfunc)
{
if (bytes_from_unparsed(fv, s, TRUE, NULL)) {
if (fv->value.bytes->len > MAX_SYSTEMID_LEN) {
logfunc("\"%s\" contains too many bytes to be a valid OSI System-ID.",
s);
return FALSE;
}
return TRUE;
}
logfunc("\"%s\" is not a valid OSI System-ID.", s);
return FALSE;
}
static guint
len(fvalue_t *fv)
{
return fv->value.bytes->len;
}
static void
slice(fvalue_t *fv, GByteArray *bytes, guint offset, guint length)
{
guint8* data;
data = fv->value.bytes->data + offset;
g_byte_array_append(bytes, data, length);
}
static gboolean
cmp_eq(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
if (a->len != b->len) {
return FALSE;
}
return (memcmp(a->data, b->data, a->len) == 0);
}
static gboolean
cmp_ne(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
if (a->len != b->len) {
return TRUE;
}
return (memcmp(a->data, b->data, a->len) != 0);
}
static gboolean
cmp_gt(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
if (a->len > b->len) {
return TRUE;
}
if (a->len < b->len) {
return FALSE;
}
return (memcmp(a->data, b->data, a->len) > 0);
}
static gboolean
cmp_ge(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
if (a->len > b->len) {
return TRUE;
}
if (a->len < b->len) {
return FALSE;
}
return (memcmp(a->data, b->data, a->len) >= 0);
}
static gboolean
cmp_lt(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
if (a->len < b->len) {
return TRUE;
}
if (a->len > b->len) {
return FALSE;
}
return (memcmp(a->data, b->data, a->len) < 0);
}
static gboolean
cmp_le(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
if (a->len < b->len) {
return TRUE;
}
if (a->len > b->len) {
return FALSE;
}
return (memcmp(a->data, b->data, a->len) <= 0);
}
static gboolean
cmp_bitwise_and(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
guint i = 0;
unsigned char *p_a, *p_b;
if (b->len != a->len) {
return FALSE;
}
p_a = a->data;
p_b = b->data;
while (i < b->len) {
if (p_a[i] & p_b[i])
return TRUE;
else
i++;
}
return FALSE;
}
static gboolean
cmp_contains(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GByteArray *b = fv_b->value.bytes;
if (epan_memmem(a->data, a->len, b->data, b->len)) {
return TRUE;
}
else {
return FALSE;
}
}
static gboolean
cmp_matches(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
GByteArray *a = fv_a->value.bytes;
GRegex *regex = fv_b->value.re;
if (strcmp(fv_b->ftype->name, "FT_PCRE") != 0) {
return FALSE;
}
if (! regex) {
return FALSE;
}
return g_regex_match_full(
regex,
(char *)a->data,
(int)a->len,
0,
(GRegexMatchFlags)0,
NULL,
NULL
);
}
void
ftype_register_bytes(void)
{
static ftype_t bytes_type = {
FT_BYTES,
"FT_BYTES",
"Sequence of bytes",
0,
bytes_fvalue_new,
bytes_fvalue_free,
bytes_from_unparsed,
bytes_from_string,
bytes_to_repr,
bytes_repr_len,
bytes_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
CMP_MATCHES,
len,
slice,
};
static ftype_t uint_bytes_type = {
FT_UINT_BYTES,
"FT_UINT_BYTES",
"Sequence of bytes",
0,
bytes_fvalue_new,
bytes_fvalue_free,
bytes_from_unparsed,
NULL,
bytes_to_repr,
bytes_repr_len,
bytes_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
NULL,
len,
slice,
};
static ftype_t ax25_type = {
FT_AX25,
"FT_AX25",
"AX.25 address",
FT_AX25_ADDR_LEN,
bytes_fvalue_new,
bytes_fvalue_free,
ax25_from_unparsed,
NULL,
bytes_to_repr,
bytes_repr_len,
NULL,
ax25_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
CMP_MATCHES,
len,
slice,
};
static ftype_t vines_type = {
FT_VINES,
"FT_VINES",
"VINES address",
FT_VINES_ADDR_LEN,
bytes_fvalue_new,
bytes_fvalue_free,
vines_from_unparsed,
NULL,
bytes_to_repr,
bytes_repr_len,
NULL,
vines_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
CMP_MATCHES,
len,
slice,
};
static ftype_t ether_type = {
FT_ETHER,
"FT_ETHER",
"Ethernet or other MAC address",
FT_ETHER_LEN,
bytes_fvalue_new,
bytes_fvalue_free,
ether_from_unparsed,
NULL,
bytes_to_repr,
bytes_repr_len,
NULL,
ether_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
CMP_MATCHES,
len,
slice,
};
static ftype_t oid_type = {
FT_OID,
"FT_OID",
"ASN.1 object identifier",
0,
bytes_fvalue_new,
bytes_fvalue_free,
oid_from_unparsed,
NULL,
oid_to_repr,
oid_repr_len,
oid_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
NULL,
len,
slice,
};
static ftype_t rel_oid_type = {
FT_REL_OID,
"FT_REL_OID",
"ASN.1 relative object identifier",
0,
bytes_fvalue_new,
bytes_fvalue_free,
rel_oid_from_unparsed,
NULL,
rel_oid_to_repr,
rel_oid_repr_len,
oid_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
NULL,
len,
slice,
};
static ftype_t system_id_type = {
FT_SYSTEM_ID,
"FT_SYSTEM_ID",
"OSI System-ID",
0,
bytes_fvalue_new,
bytes_fvalue_free,
system_id_from_unparsed,
NULL,
system_id_to_repr,
bytes_repr_len,
system_id_fvalue_set,
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
cmp_eq,
cmp_ne,
cmp_gt,
cmp_ge,
cmp_lt,
cmp_le,
cmp_bitwise_and,
cmp_contains,
NULL,
len,
slice,
};
ftype_register(FT_BYTES, &bytes_type);
ftype_register(FT_UINT_BYTES, &uint_bytes_type);
ftype_register(FT_AX25, &ax25_type);
ftype_register(FT_VINES, &vines_type);
ftype_register(FT_ETHER, &ether_type);
ftype_register(FT_OID, &oid_type);
ftype_register(FT_REL_OID, &rel_oid_type);
ftype_register(FT_SYSTEM_ID, &system_id_type);
}
