static void
int_fvalue_new(fvalue_t *fv)
{
fv->value.uinteger = 0;
}
static void
set_uinteger(fvalue_t *fv, guint32 value)
{
fv->value.uinteger = value;
}
static void
set_sinteger(fvalue_t *fv, gint32 value)
{
fv->value.sinteger = value;
}
static guint32
get_uinteger(fvalue_t *fv)
{
return fv->value.uinteger;
}
static gint32
get_sinteger(fvalue_t *fv)
{
return fv->value.sinteger;
}
static gboolean
uint_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg,
guint32 max)
{
unsigned long value;
char *endptr;
if (strchr (s, '-') && strtol(s, NULL, 0) < 0) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" too small for this field, minimum 0.", s);
return FALSE;
}
errno = 0;
value = strtoul(s, &endptr, 0);
if (errno == EINVAL || endptr == s || *endptr != '\0') {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid number.", s);
return FALSE;
}
if (errno == ERANGE) {
if (err_msg != NULL) {
if (value == ULONG_MAX) {
*err_msg = g_strdup_printf("\"%s\" causes an integer overflow.",
s);
}
else {
*err_msg = g_strdup_printf("\"%s\" is not an integer.", s);
}
}
return FALSE;
}
if (value > max) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" too big for this field, maximum %u.", s, max);
return FALSE;
}
fv->value.uinteger = (guint32)value;
return TRUE;
}
static gboolean
uint32_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return uint_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXUINT32);
}
static gboolean
uint24_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return uint_from_unparsed (fv, s, allow_partial_value, err_msg, 0xFFFFFF);
}
static gboolean
uint16_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return uint_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXUINT16);
}
static gboolean
uint8_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return uint_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXUINT8);
}
static gboolean
sint_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg,
gint32 max, gint32 min)
{
long value;
char *endptr;
if (!strchr (s, '-') && strtoul(s, NULL, 0) > G_MAXINT32) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" causes an integer overflow.", s);
return FALSE;
}
errno = 0;
value = strtol(s, &endptr, 0);
if (errno == EINVAL || endptr == s || *endptr != '\0') {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid number.", s);
return FALSE;
}
if (errno == ERANGE) {
if (err_msg != NULL) {
if (value == LONG_MAX) {
*err_msg = g_strdup_printf("\"%s\" causes an integer overflow.", s);
}
else if (value == LONG_MIN) {
*err_msg = g_strdup_printf("\"%s\" causes an integer underflow.", s);
}
else {
*err_msg = g_strdup_printf("\"%s\" is not an integer.", s);
}
}
return FALSE;
}
if (value > max) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" too big for this field, maximum %d.",
s, max);
return FALSE;
} else if (value < min) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" too small for this field, minimum %d.",
s, min);
return FALSE;
}
fv->value.sinteger = (gint32)value;
return TRUE;
}
static gboolean
sint32_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return sint_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXINT32, G_MININT32);
}
static gboolean
sint24_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return sint_from_unparsed (fv, s, allow_partial_value, err_msg, 0x7FFFFF, -0x800000);
}
static gboolean
sint16_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return sint_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXINT16, G_MININT16);
}
static gboolean
sint8_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return sint_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXINT8, G_MININT8);
}
static int
integer_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 11;
}
static void
integer_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf)
{
guint32 val;
if (fv->value.sinteger < 0) {
*buf++ = '-';
val = -fv->value.sinteger;
} else
val = fv->value.sinteger;
guint32_to_str_buf(val, buf, 11);
}
static int
uinteger_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 10;
}
static void
uinteger_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display, char *buf)
{
if ((field_display == BASE_HEX) || (field_display == BASE_HEX_DEC))
{
*buf++ = '0';
*buf++ = 'x';
buf = dword_to_hex(buf, fv->value.uinteger);
*buf++ = '\0';
}
else
{
guint32_to_str_buf(fv->value.uinteger, buf, 11);
}
}
static gboolean
ipxnet_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg)
{
guint32 val;
gboolean known;
if (uint32_from_unparsed(fv, s, TRUE, NULL)) {
return TRUE;
}
val = get_ipxnet_addr(s, &known);
if (known) {
fv->value.uinteger = val;
return TRUE;
}
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid IPX network name or address.", s);
return FALSE;
}
static int
ipxnet_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 2+8;
}
static void
ipxnet_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf)
{
uinteger_to_repr(fv, rtype, BASE_HEX, buf);
}
static gboolean
cmp_eq(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger == b->value.uinteger;
}
static gboolean
cmp_ne(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger != b->value.uinteger;
}
static gboolean
u_cmp_gt(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger > b->value.uinteger;
}
static gboolean
u_cmp_ge(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger >= b->value.uinteger;
}
static gboolean
u_cmp_lt(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger < b->value.uinteger;
}
static gboolean
u_cmp_le(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger <= b->value.uinteger;
}
static gboolean
s_cmp_gt(const fvalue_t *a, const fvalue_t *b)
{
return a->value.sinteger > b->value.sinteger;
}
static gboolean
s_cmp_ge(const fvalue_t *a, const fvalue_t *b)
{
return a->value.sinteger >= b->value.sinteger;
}
static gboolean
s_cmp_lt(const fvalue_t *a, const fvalue_t *b)
{
return a->value.sinteger < b->value.sinteger;
}
static gboolean
s_cmp_le(const fvalue_t *a, const fvalue_t *b)
{
return a->value.sinteger <= b->value.sinteger;
}
static gboolean
cmp_bitwise_and(const fvalue_t *a, const fvalue_t *b)
{
return ((a->value.uinteger & b->value.uinteger) != 0);
}
static void
int64_fvalue_new(fvalue_t *fv)
{
fv->value.sinteger64 = 0;
}
static void
set_uinteger64(fvalue_t *fv, guint64 value)
{
fv->value.uinteger64 = value;
}
static void
set_sinteger64(fvalue_t *fv, gint64 value)
{
fv->value.sinteger64 = value;
}
static guint64
get_uinteger64(fvalue_t *fv)
{
return fv->value.uinteger64;
}
static gint64
get_sinteger64(fvalue_t *fv)
{
return fv->value.sinteger64;
}
static gboolean
_uint64_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg,
guint64 max)
{
guint64 value;
char *endptr;
if (strchr (s, '-') && g_ascii_strtoll(s, NULL, 0) < 0) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" causes an integer underflow.", s);
return FALSE;
}
errno = 0;
value = g_ascii_strtoull(s, &endptr, 0);
if (errno == EINVAL || endptr == s || *endptr != '\0') {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid number.", s);
return FALSE;
}
if (errno == ERANGE) {
if (err_msg != NULL) {
if (value == G_MAXUINT64) {
*err_msg = g_strdup_printf("\"%s\" causes an integer overflow.", s);
}
else {
*err_msg = g_strdup_printf("\"%s\" is not an integer.", s);
}
}
return FALSE;
}
if (value > max) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" too big for this field, maximum %" G_GINT64_MODIFIER "u.", s, max);
return FALSE;
}
fv->value.uinteger64 = value;
return TRUE;
}
static gboolean
uint64_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _uint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXUINT64);
}
static gboolean
uint56_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _uint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_GUINT64_CONSTANT(0xFFFFFFFFFFFFFF));
}
static gboolean
uint48_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _uint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_GUINT64_CONSTANT(0xFFFFFFFFFFFF));
}
static gboolean
uint40_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _uint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_GUINT64_CONSTANT(0xFFFFFFFFFF));
}
static gboolean
_sint64_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg,
gint64 max, gint64 min)
{
gint64 value;
char *endptr;
if (!strchr (s, '-') && g_ascii_strtoull(s, NULL, 0) > G_MAXINT64) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" causes an integer overflow.", s);
return FALSE;
}
errno = 0;
value = g_ascii_strtoll(s, &endptr, 0);
if (errno == EINVAL || endptr == s || *endptr != '\0') {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid number.", s);
return FALSE;
}
if (errno == ERANGE) {
if (err_msg != NULL) {
if (value == G_MAXINT64) {
*err_msg = g_strdup_printf("\"%s\" causes an integer overflow.", s);
}
else if (value == G_MININT64) {
*err_msg = g_strdup_printf("\"%s\" causes an integer underflow.", s);
}
else {
*err_msg = g_strdup_printf("\"%s\" is not an integer.", s);
}
}
return FALSE;
}
if (value > max) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" too big for this field, maximum %" G_GINT64_MODIFIER "u.", s, max);
return FALSE;
} else if (value < min) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" too small for this field, maximum %" G_GINT64_MODIFIER "u.", s, max);
return FALSE;
}
fv->value.sinteger64 = (guint64)value;
return TRUE;
}
static gboolean
sint64_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _sint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_MAXINT64, G_MININT64);
}
static gboolean
sint56_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _sint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_GINT64_CONSTANT(0x7FFFFFFFFFFFFF), G_GINT64_CONSTANT(-0x80000000000000));
}
static gboolean
sint48_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _sint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_GINT64_CONSTANT(0x7FFFFFFFFFFF), G_GINT64_CONSTANT(-0x800000000000));
}
static gboolean
sint40_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value, gchar **err_msg)
{
return _sint64_from_unparsed (fv, s, allow_partial_value, err_msg, G_GINT64_CONSTANT(0x7FFFFFFFFF), G_GINT64_CONSTANT(-0x8000000000));
}
static int
integer64_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 20;
}
static void
integer64_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf)
{
guint64 val;
if (fv->value.sinteger64 < 0) {
*buf++ = '-';
val = -fv->value.sinteger64;
} else
val = fv->value.sinteger64;
guint64_to_str_buf(val, buf, 20);
}
static int
uinteger64_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 20;
}
static void
uinteger64_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf)
{
if ((field_display == BASE_HEX) || (field_display == BASE_HEX_DEC))
{
*buf++ = '0';
*buf++ = 'x';
buf = qword_to_hex(buf, fv->value.uinteger64);
*buf++ = '\0';
}
else
{
guint64_to_str_buf(fv->value.uinteger64, buf, 21);
}
}
static gboolean
cmp_eq64(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger64 == b->value.uinteger64;
}
static gboolean
cmp_ne64(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger64 != b->value.uinteger64;
}
static gboolean
u_cmp_gt64(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger64 > b->value.uinteger64;
}
static gboolean
u_cmp_ge64(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger64 >= b->value.uinteger64;
}
static gboolean
u_cmp_lt64(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger64 < b->value.uinteger64;
}
static gboolean
u_cmp_le64(const fvalue_t *a, const fvalue_t *b)
{
return a->value.uinteger64 <= b->value.uinteger64;
}
static gboolean
s_cmp_gt64(const fvalue_t *a, const fvalue_t *b)
{
return (gint64)a->value.sinteger64 > (gint64)b->value.sinteger64;
}
static gboolean
s_cmp_ge64(const fvalue_t *a, const fvalue_t *b)
{
return (gint64)a->value.sinteger64 >= (gint64)b->value.sinteger64;
}
static gboolean
s_cmp_lt64(const fvalue_t *a, const fvalue_t *b)
{
return (gint64)a->value.sinteger64 < (gint64)b->value.sinteger64;
}
static gboolean
s_cmp_le64(const fvalue_t *a, const fvalue_t *b)
{
return (gint64)a->value.sinteger64 <= (gint64)b->value.sinteger64;
}
static gboolean
cmp_bitwise_and64(const fvalue_t *a, const fvalue_t *b)
{
return ((a->value.uinteger64 & b->value.uinteger64) != 0);
}
static void
boolean_fvalue_new(fvalue_t *fv)
{
fv->value.uinteger = TRUE;
}
static int
boolean_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 1;
}
static void
boolean_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf)
{
*buf++ = (fv->value.uinteger) ? '1' : '0';
*buf = '\0';
}
static gboolean
bool_eq(const fvalue_t *a, const fvalue_t *b)
{
if (a->value.uinteger) {
if (b->value.uinteger) {
return TRUE;
}
else {
return FALSE;
}
}
else {
if (b->value.uinteger) {
return FALSE;
}
else {
return TRUE;
}
}
}
static gboolean
bool_ne(const fvalue_t *a, const fvalue_t *b)
{
return (!bool_eq(a,b));
}
static gboolean
eui64_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg)
{
GByteArray *bytes;
gboolean res;
union {
guint64 value;
guint8 bytes[8];
} eui64;
if (uint64_from_unparsed(fv, s, TRUE, NULL)) {
return TRUE;
}
bytes = g_byte_array_new();
res = hex_str_to_bytes(s, bytes, TRUE);
if (!res || bytes->len != 8) {
if (err_msg != NULL)
*err_msg = g_strdup_printf("\"%s\" is not a valid EUI-64 address.", s);
g_byte_array_free(bytes, TRUE);
return FALSE;
}
memcpy(eui64.bytes, bytes->data, 8);
g_byte_array_free(bytes, TRUE);
fv->value.integer64 = GUINT64_FROM_BE(eui64.value);
return TRUE;
}
static int
eui64_repr_len(fvalue_t *fv _U_, ftrepr_t rtype _U_, int field_display _U_)
{
return 8*3-1;
}
static void
eui64_to_repr(fvalue_t *fv, ftrepr_t rtype _U_, int field_display _U_, char *buf)
{
union {
guint64 value;
guint8 bytes[8];
} eui64;
eui64.value = GUINT64_TO_BE(fv->value.integer64);
g_snprintf(buf, EUI64_STR_LEN, "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x:%.2x:%.2x",
eui64.bytes[0], eui64.bytes[1], eui64.bytes[2], eui64.bytes[3],
eui64.bytes[4], eui64.bytes[5], eui64.bytes[6], eui64.bytes[7]);
}
void
ftype_register_integers(void)
{
static ftype_t uint8_type = {
FT_UINT8,
"FT_UINT8",
"Unsigned integer, 1 byte",
1,
int_fvalue_new,
NULL,
uint8_from_unparsed,
NULL,
uinteger_to_repr,
uinteger_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
u_cmp_gt,
u_cmp_ge,
u_cmp_lt,
u_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t uint16_type = {
FT_UINT16,
"FT_UINT16",
"Unsigned integer, 2 bytes",
2,
int_fvalue_new,
NULL,
uint16_from_unparsed,
NULL,
uinteger_to_repr,
uinteger_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
u_cmp_gt,
u_cmp_ge,
u_cmp_lt,
u_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t uint24_type = {
FT_UINT24,
"FT_UINT24",
"Unsigned integer, 3 bytes",
3,
int_fvalue_new,
NULL,
uint24_from_unparsed,
NULL,
uinteger_to_repr,
uinteger_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
u_cmp_gt,
u_cmp_ge,
u_cmp_lt,
u_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t uint32_type = {
FT_UINT32,
"FT_UINT32",
"Unsigned integer, 4 bytes",
4,
int_fvalue_new,
NULL,
uint32_from_unparsed,
NULL,
uinteger_to_repr,
uinteger_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
u_cmp_gt,
u_cmp_ge,
u_cmp_lt,
u_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t uint40_type = {
FT_UINT40,
"FT_UINT40",
"Unsigned integer, 5 bytes",
5,
int64_fvalue_new,
NULL,
uint40_from_unparsed,
NULL,
uinteger64_to_repr,
uinteger64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger64,
NULL,
NULL,
cmp_eq64,
cmp_ne64,
u_cmp_gt64,
u_cmp_ge64,
u_cmp_lt64,
u_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t uint48_type = {
FT_UINT48,
"FT_UINT48",
"Unsigned integer, 6 bytes",
6,
int64_fvalue_new,
NULL,
uint48_from_unparsed,
NULL,
uinteger64_to_repr,
uinteger64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger64,
NULL,
NULL,
cmp_eq64,
cmp_ne64,
u_cmp_gt64,
u_cmp_ge64,
u_cmp_lt64,
u_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t uint56_type = {
FT_UINT56,
"FT_UINT56",
"Unsigned integer, 7 bytes",
7,
int64_fvalue_new,
NULL,
uint56_from_unparsed,
NULL,
uinteger64_to_repr,
uinteger64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger64,
NULL,
NULL,
cmp_eq64,
cmp_ne64,
u_cmp_gt64,
u_cmp_ge64,
u_cmp_lt64,
u_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t uint64_type = {
FT_UINT64,
"FT_UINT64",
"Unsigned integer, 8 bytes",
8,
int64_fvalue_new,
NULL,
uint64_from_unparsed,
NULL,
uinteger64_to_repr,
uinteger64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger64,
NULL,
NULL,
cmp_eq64,
cmp_ne64,
u_cmp_gt64,
u_cmp_ge64,
u_cmp_lt64,
u_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int8_type = {
FT_INT8,
"FT_INT8",
"Signed integer, 1 byte",
1,
int_fvalue_new,
NULL,
sint8_from_unparsed,
NULL,
integer_to_repr,
integer_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
s_cmp_gt,
s_cmp_ge,
s_cmp_lt,
s_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int16_type = {
FT_INT16,
"FT_INT16",
"Signed integer, 2 bytes",
2,
int_fvalue_new,
NULL,
sint16_from_unparsed,
NULL,
integer_to_repr,
integer_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
s_cmp_gt,
s_cmp_ge,
s_cmp_lt,
s_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int24_type = {
FT_INT24,
"FT_INT24",
"Signed integer, 3 bytes",
3,
int_fvalue_new,
NULL,
sint24_from_unparsed,
NULL,
integer_to_repr,
integer_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
s_cmp_gt,
s_cmp_ge,
s_cmp_lt,
s_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int32_type = {
FT_INT32,
"FT_INT32",
"Signed integer, 4 bytes",
4,
int_fvalue_new,
NULL,
sint32_from_unparsed,
NULL,
integer_to_repr,
integer_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
s_cmp_gt,
s_cmp_ge,
s_cmp_lt,
s_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int40_type = {
FT_INT40,
"FT_INT40",
"Signed integer, 5 bytes",
5,
int64_fvalue_new,
NULL,
sint40_from_unparsed,
NULL,
integer64_to_repr,
integer64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger64,
NULL,
cmp_eq64,
cmp_ne64,
s_cmp_gt64,
s_cmp_ge64,
s_cmp_lt64,
s_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int48_type = {
FT_INT48,
"FT_INT48",
"Signed integer, 6 bytes",
6,
int64_fvalue_new,
NULL,
sint48_from_unparsed,
NULL,
integer64_to_repr,
integer64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger64,
NULL,
cmp_eq64,
cmp_ne64,
s_cmp_gt64,
s_cmp_ge64,
s_cmp_lt64,
s_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int56_type = {
FT_INT56,
"FT_INT56",
"Signed integer, 7 bytes",
7,
int64_fvalue_new,
NULL,
sint56_from_unparsed,
NULL,
integer64_to_repr,
integer64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger64,
NULL,
cmp_eq64,
cmp_ne64,
s_cmp_gt64,
s_cmp_ge64,
s_cmp_lt64,
s_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t int64_type = {
FT_INT64,
"FT_INT64",
"Signed integer, 8 bytes",
8,
int64_fvalue_new,
NULL,
sint64_from_unparsed,
NULL,
integer64_to_repr,
integer64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_sinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_sinteger64,
NULL,
cmp_eq64,
cmp_ne64,
s_cmp_gt64,
s_cmp_ge64,
s_cmp_lt64,
s_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t boolean_type = {
FT_BOOLEAN,
"FT_BOOLEAN",
"Boolean",
0,
boolean_fvalue_new,
NULL,
uint64_from_unparsed,
NULL,
boolean_to_repr,
boolean_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger,
NULL,
set_uinteger64,
NULL,
NULL,
NULL,
get_uinteger,
NULL,
get_uinteger64,
NULL,
NULL,
bool_eq,
bool_ne,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t ipxnet_type = {
FT_IPXNET,
"FT_IPXNET",
"IPX network number",
4,
int_fvalue_new,
NULL,
ipxnet_from_unparsed,
NULL,
ipxnet_to_repr,
ipxnet_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
u_cmp_gt,
u_cmp_ge,
u_cmp_lt,
u_cmp_le,
cmp_bitwise_and,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t framenum_type = {
FT_FRAMENUM,
"FT_FRAMENUM",
"Frame number",
4,
int_fvalue_new,
NULL,
uint32_from_unparsed,
NULL,
uinteger_to_repr,
uinteger_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger,
NULL,
NULL,
NULL,
NULL,
cmp_eq,
cmp_ne,
u_cmp_gt,
u_cmp_ge,
u_cmp_lt,
u_cmp_le,
NULL,
NULL,
NULL,
NULL,
NULL,
};
static ftype_t eui64_type = {
FT_EUI64,
"FT_EUI64",
"EUI64 address",
FT_EUI64_LEN,
int64_fvalue_new,
NULL,
eui64_from_unparsed,
NULL,
eui64_to_repr,
eui64_repr_len,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
set_uinteger64,
NULL,
NULL,
NULL,
NULL,
NULL,
get_uinteger64,
NULL,
NULL,
cmp_eq64,
cmp_ne64,
u_cmp_gt64,
u_cmp_ge64,
u_cmp_lt64,
u_cmp_le64,
cmp_bitwise_and64,
NULL,
NULL,
NULL,
NULL,
};
ftype_register(FT_UINT8, &uint8_type);
ftype_register(FT_UINT16, &uint16_type);
ftype_register(FT_UINT24, &uint24_type);
ftype_register(FT_UINT32, &uint32_type);
ftype_register(FT_UINT40, &uint40_type);
ftype_register(FT_UINT48, &uint48_type);
ftype_register(FT_UINT56, &uint56_type);
ftype_register(FT_UINT64, &uint64_type);
ftype_register(FT_INT8, &int8_type);
ftype_register(FT_INT16, &int16_type);
ftype_register(FT_INT24, &int24_type);
ftype_register(FT_INT32, &int32_type);
ftype_register(FT_INT40, &int40_type);
ftype_register(FT_INT48, &int48_type);
ftype_register(FT_INT56, &int56_type);
ftype_register(FT_INT64, &int64_type);
ftype_register(FT_BOOLEAN, &boolean_type);
ftype_register(FT_IPXNET, &ipxnet_type);
ftype_register(FT_FRAMENUM, &framenum_type);
ftype_register(FT_EUI64, &eui64_type);
}
