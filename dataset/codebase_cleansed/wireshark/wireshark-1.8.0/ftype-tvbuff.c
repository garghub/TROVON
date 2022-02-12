static void
value_new(fvalue_t *fv)
{
fv->value.tvb = NULL;
fv->tvb_is_private = FALSE;
}
static void
value_free(fvalue_t *fv)
{
if (fv->value.tvb && fv->tvb_is_private) {
tvb_free_chain(fv->value.tvb);
}
}
static void
value_set(fvalue_t *fv, gpointer value, gboolean already_copied)
{
g_assert(already_copied);
value_free(fv);
fv->value.tvb = (tvbuff_t *)value;
}
static void
free_tvb_data(void *data)
{
g_free(data);
}
static gboolean
val_from_string(fvalue_t *fv, char *s, LogFunc logfunc _U_)
{
tvbuff_t *new_tvb;
guint8 *private_data;
value_free(fv);
private_data = (guint8 *)g_memdup(s, (guint)strlen(s));
new_tvb = tvb_new_real_data(private_data,
(guint)strlen(s), (gint)strlen(s));
tvb_set_free_cb(new_tvb, free_tvb_data);
fv->tvb_is_private = TRUE;
fv->value.tvb = new_tvb;
return TRUE;
}
static gboolean
val_from_unparsed(fvalue_t *fv, char *s, gboolean allow_partial_value _U_, LogFunc logfunc)
{
fvalue_t *fv_bytes;
tvbuff_t *new_tvb;
guint8 *private_data;
value_free(fv);
fv_bytes = fvalue_from_unparsed(FT_BYTES, s, TRUE, NULL);
if (fv_bytes) {
private_data = (guint8 *)g_memdup(fv_bytes->value.bytes->data,
fv_bytes->value.bytes->len);
new_tvb = tvb_new_real_data(private_data,
fv_bytes->value.bytes->len,
fv_bytes->value.bytes->len);
tvb_set_free_cb(new_tvb, free_tvb_data);
fv->tvb_is_private = TRUE;
fv->value.tvb = new_tvb;
return TRUE;
}
return val_from_string(fv, s, logfunc);
}
static int
val_repr_len(fvalue_t *fv, ftrepr_t rtype)
{
volatile guint length = 0;
if (rtype != FTREPR_DFILTER) return -1;
TRY {
length = tvb_length(fv->value.tvb) * 3 - 1;
}
CATCH_ALL {
}
ENDTRY;
return (int) length;
}
static void
val_to_repr(fvalue_t *fv, ftrepr_t rtype, char *buf)
{
guint length;
const guint8 *c;
char *write_cursor;
unsigned int i;
g_assert(rtype == FTREPR_DFILTER);
TRY {
length = tvb_length(fv->value.tvb);
c = tvb_get_ptr(fv->value.tvb, 0, length);
write_cursor = buf;
for (i = 0; i < length; i++) {
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
CATCH_ALL {
}
ENDTRY;
}
static gpointer
value_get(fvalue_t *fv)
{
return fv->value.tvb;
}
static guint
len(fvalue_t *fv)
{
volatile guint length = 0;
TRY {
if (fv->value.tvb)
length = tvb_length(fv->value.tvb);
}
CATCH_ALL {
}
ENDTRY;
return length;
}
static void
slice(fvalue_t *fv, GByteArray *bytes, guint offset, guint length)
{
const guint8* data;
if (fv->value.tvb) {
TRY {
data = tvb_get_ptr(fv->value.tvb, offset, length);
g_byte_array_append(bytes, data, length);
}
CATCH_ALL {
}
ENDTRY;
}
}
static gboolean
cmp_eq(fvalue_t *fv_a, fvalue_t *fv_b)
{
tvbuff_t *a = fv_a->value.tvb;
tvbuff_t *b = fv_b->value.tvb;
volatile gboolean eq = FALSE;
TRY {
guint a_len = tvb_length(a);
if (a_len == tvb_length(b))
eq = (memcmp(tvb_get_ptr(a, 0, a_len), tvb_get_ptr(b, 0, a_len), a_len) == 0);
}
CATCH_ALL {
}
ENDTRY;
return eq;
}
static gboolean
cmp_ne(fvalue_t *fv_a, fvalue_t *fv_b)
{
tvbuff_t *a = fv_a->value.tvb;
tvbuff_t *b = fv_b->value.tvb;
volatile gboolean ne = TRUE;
TRY {
guint a_len = tvb_length(a);
if (a_len == tvb_length(b)) {
ne = (memcmp(tvb_get_ptr(a, 0, a_len), tvb_get_ptr(b, 0, a_len), a_len) != 0);
}
}
CATCH_ALL {
}
ENDTRY;
return ne;
}
static gboolean
cmp_gt(fvalue_t *fv_a, fvalue_t *fv_b)
{
tvbuff_t *a = fv_a->value.tvb;
tvbuff_t *b = fv_b->value.tvb;
volatile gboolean gt = FALSE;
TRY {
guint a_len = tvb_length(a);
guint b_len = tvb_length(b);
if (a_len > b_len) {
gt = TRUE;
} else if (a_len == b_len) {
gt = (memcmp(tvb_get_ptr(a, 0, a_len), tvb_get_ptr(b, 0, a_len), a_len) > 0);
}
}
CATCH_ALL {
}
ENDTRY;
return gt;
}
static gboolean
cmp_ge(fvalue_t *fv_a, fvalue_t *fv_b)
{
tvbuff_t *a = fv_a->value.tvb;
tvbuff_t *b = fv_b->value.tvb;
volatile gboolean ge = FALSE;
TRY {
guint a_len = tvb_length(a);
guint b_len = tvb_length(b);
if (a_len > b_len) {
ge = TRUE;
} else if (a_len == b_len) {
ge = (memcmp(tvb_get_ptr(a, 0, a_len), tvb_get_ptr(b, 0, a_len), a_len) >= 0);
}
}
CATCH_ALL {
}
ENDTRY;
return ge;
}
static gboolean
cmp_lt(fvalue_t *fv_a, fvalue_t *fv_b)
{
tvbuff_t *a = fv_a->value.tvb;
tvbuff_t *b = fv_b->value.tvb;
volatile gboolean lt = FALSE;
TRY {
guint a_len = tvb_length(a);
guint b_len = tvb_length(b);
if (a_len < b_len) {
lt = TRUE;
} else if (a_len == b_len) {
lt = (memcmp(tvb_get_ptr(a, 0, a_len), tvb_get_ptr(b, 0, a_len), a_len) < 0);
}
}
CATCH_ALL {
}
ENDTRY;
return lt;
}
static gboolean
cmp_le(fvalue_t *fv_a, fvalue_t *fv_b)
{
tvbuff_t *a = fv_a->value.tvb;
tvbuff_t *b = fv_b->value.tvb;
volatile gboolean le = FALSE;
TRY {
guint a_len = tvb_length(a);
guint b_len = tvb_length(b);
if (a_len < b_len) {
le = TRUE;
} else if (a_len == b_len) {
le = (memcmp(tvb_get_ptr(a, 0, a_len), tvb_get_ptr(b, 0, a_len), a_len) <= 0);
}
}
CATCH_ALL {
}
ENDTRY;
return le;
}
static gboolean
cmp_contains(fvalue_t *fv_a, fvalue_t *fv_b)
{
volatile gboolean contains = FALSE;
TRY {
if (tvb_find_tvb(fv_a->value.tvb, fv_b->value.tvb, 0) > -1) {
contains = TRUE;
}
}
CATCH_ALL {
}
ENDTRY;
return contains;
}
static gboolean
cmp_matches(fvalue_t *fv_a, fvalue_t *fv_b)
{
tvbuff_t *tvb = fv_a->value.tvb;
GRegex *regex = fv_b->value.re;
volatile gboolean rc = FALSE;
const char *data = NULL;
guint32 tvb_len;
if (strcmp(fv_b->ftype->name, "FT_PCRE") != 0) {
return FALSE;
}
if (! regex) {
return FALSE;
}
TRY {
tvb_len = tvb_length(tvb);
data = (const char *)tvb_get_ptr(tvb, 0, tvb_len);
rc = g_regex_match_full(
regex,
data,
tvb_len,
0,
0,
NULL,
NULL
);
}
CATCH_ALL {
return FALSE;
}
ENDTRY;
return rc;
}
void
ftype_register_tvbuff(void)
{
static ftype_t protocol_type = {
FT_PROTOCOL,
"FT_PROTOCOL",
"Protocol",
0,
value_new,
value_free,
val_from_unparsed,
val_from_string,
val_to_repr,
val_repr_len,
value_set,
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
NULL,
cmp_contains,
CMP_MATCHES,
len,
slice,
};
ftype_register(FT_PROTOCOL, &protocol_type);
}
