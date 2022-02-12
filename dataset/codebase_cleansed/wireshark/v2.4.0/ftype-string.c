static void
string_fvalue_new(fvalue_t *fv)
{
fv->value.string = NULL;
}
static void
string_fvalue_free(fvalue_t *fv)
{
g_free(fv->value.string);
}
static void
string_fvalue_set_string(fvalue_t *fv, const gchar *value)
{
DISSECTOR_ASSERT(value != NULL);
string_fvalue_free(fv);
fv->value.string = (gchar *)g_strdup(value);
}
static int
string_repr_len(fvalue_t *fv, ftrepr_t rtype, int field_display _U_)
{
switch (rtype) {
case FTREPR_DISPLAY:
return (int)strlen(fv->value.string);
case FTREPR_DFILTER:
return escape_string_len(fv->value.string);
}
g_assert_not_reached();
return -1;
}
static void
string_to_repr(fvalue_t *fv, ftrepr_t rtype, int field_display _U_, char *buf, unsigned int size)
{
switch (rtype) {
case FTREPR_DISPLAY:
g_strlcpy(buf, fv->value.string, size);
return;
case FTREPR_DFILTER:
escape_string(buf, fv->value.string);
return;
}
g_assert_not_reached();
}
static gpointer
value_get(fvalue_t *fv)
{
return fv->value.string;
}
static gboolean
val_from_string(fvalue_t *fv, const char *s, gchar **err_msg _U_)
{
string_fvalue_free(fv);
fv->value.string = g_strdup(s);
return TRUE;
}
static gboolean
val_from_unparsed(fvalue_t *fv, const char *s, gboolean allow_partial_value _U_, gchar **err_msg)
{
fvalue_t *fv_bytes;
string_fvalue_free(fv);
fv_bytes = fvalue_from_unparsed(FT_BYTES, s, TRUE, NULL);
if (fv_bytes) {
int num_bytes = fv_bytes->value.bytes->len;
fv->value.string = (gchar *)g_malloc(num_bytes + 1);
memcpy(fv->value.string, fv_bytes->value.bytes->data, num_bytes);
fv->value.string[num_bytes] = '\0';
FVALUE_FREE(fv_bytes);
return TRUE;
}
return val_from_string(fv, s, err_msg);
}
static guint
len(fvalue_t *fv)
{
return (guint)strlen(fv->value.string);
}
static void
slice(fvalue_t *fv, GByteArray *bytes, guint offset, guint length)
{
guint8* data;
data = fv->value.ustring + offset;
g_byte_array_append(bytes, data, length);
}
static gboolean
cmp_eq(const fvalue_t *a, const fvalue_t *b)
{
return (strcmp(a->value.string, b->value.string) == 0);
}
static gboolean
cmp_ne(const fvalue_t *a, const fvalue_t *b)
{
return (strcmp(a->value.string, b->value.string) != 0);
}
static gboolean
cmp_gt(const fvalue_t *a, const fvalue_t *b)
{
return (strcmp(a->value.string, b->value.string) > 0);
}
static gboolean
cmp_ge(const fvalue_t *a, const fvalue_t *b)
{
return (strcmp(a->value.string, b->value.string) >= 0);
}
static gboolean
cmp_lt(const fvalue_t *a, const fvalue_t *b)
{
return (strcmp(a->value.string, b->value.string) < 0);
}
static gboolean
cmp_le(const fvalue_t *a, const fvalue_t *b)
{
return (strcmp(a->value.string, b->value.string) <= 0);
}
static gboolean
cmp_contains(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
if (strlen(fv_b->value.string) == 0) {
return FALSE;
}
if (strstr(fv_a->value.string, fv_b->value.string)) {
return TRUE;
}
else {
return FALSE;
}
}
static gboolean
cmp_matches(const fvalue_t *fv_a, const fvalue_t *fv_b)
{
char *str = fv_a->value.string;
GRegex *regex = fv_b->value.re;
if (strcmp(fv_b->ftype->name, "FT_PCRE") != 0) {
return FALSE;
}
if (! regex) {
return FALSE;
}
return g_regex_match_full(
regex,
str,
(int)strlen(str),
0,
(GRegexMatchFlags)0,
NULL,
NULL
);
}
void
ftype_register_string(void)
{
static ftype_t string_type = {
FT_STRING,
"FT_STRING",
"Character string",
0,
string_fvalue_new,
string_fvalue_free,
val_from_unparsed,
val_from_string,
string_to_repr,
string_repr_len,
{ .set_value_string = string_fvalue_set_string },
{ .get_value_ptr = value_get },
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
static ftype_t stringz_type = {
FT_STRINGZ,
"FT_STRINGZ",
"Character string",
0,
string_fvalue_new,
string_fvalue_free,
val_from_unparsed,
val_from_string,
string_to_repr,
string_repr_len,
{ .set_value_string = string_fvalue_set_string },
{ .get_value_ptr = value_get },
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
static ftype_t uint_string_type = {
FT_UINT_STRING,
"FT_UINT_STRING",
"Character string",
0,
string_fvalue_new,
string_fvalue_free,
val_from_unparsed,
val_from_string,
string_to_repr,
string_repr_len,
{ .set_value_string = string_fvalue_set_string },
{ .get_value_ptr = value_get },
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
static ftype_t stringzpad_type = {
FT_STRINGZPAD,
"FT_STRINGZPAD",
"Character string",
0,
string_fvalue_new,
string_fvalue_free,
val_from_unparsed,
val_from_string,
string_to_repr,
string_repr_len,
{ .set_value_string = string_fvalue_set_string },
{ .get_value_ptr = value_get },
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
ftype_register(FT_STRING, &string_type);
ftype_register(FT_STRINGZ, &stringz_type);
ftype_register(FT_UINT_STRING, &uint_string_type);
ftype_register(FT_STRINGZPAD, &stringzpad_type);
}
