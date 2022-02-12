static void
gregex_fvalue_new(fvalue_t *fv)
{
fv->value.re = NULL;
}
static void
gregex_fvalue_free(fvalue_t *fv)
{
if (fv->value.re) {
g_regex_unref(fv->value.re);
fv->value.re = NULL;
}
}
static gboolean
raw_flag_needed(const gchar *pattern)
{
gboolean found = FALSE;
const gchar *s = pattern;
size_t i, len;
len = strlen(s);
for (i = 0; i < len; i++) {
if ((guchar)(s[i] & 0xF0) >= 0xA0 &&
(guchar)(s[i] & 0x0F) >= 0x0A)
{
found = TRUE;
break;
}
}
return found;
}
static gboolean
val_from_string(fvalue_t *fv, const char *pattern, gchar **err_msg)
{
GError *regex_error = NULL;
GRegexCompileFlags cflags = G_REGEX_OPTIMIZE;
if (raw_flag_needed(pattern)) {
cflags = (GRegexCompileFlags)(G_REGEX_OPTIMIZE | G_REGEX_RAW);
}
gregex_fvalue_free(fv);
fv->value.re = g_regex_new(
pattern,
cflags,
(GRegexMatchFlags)0,
&regex_error
);
if (regex_error) {
if (err_msg) {
*err_msg = g_strdup(regex_error->message);
}
g_error_free(regex_error);
if (fv->value.re) {
g_regex_unref(fv->value.re);
}
return FALSE;
}
return TRUE;
}
static gboolean
val_from_unparsed(fvalue_t *fv, const char *pattern, gboolean allow_partial_value _U_, gchar **err_msg)
{
g_assert(! allow_partial_value);
return val_from_string(fv, pattern, err_msg);
}
static int
gregex_repr_len(fvalue_t *fv, ftrepr_t rtype, int field_display _U_)
{
g_assert(rtype == FTREPR_DFILTER);
return (int)strlen(g_regex_get_pattern(fv->value.re));
}
static void
gregex_to_repr(fvalue_t *fv, ftrepr_t rtype, int field_display _U_, char *buf)
{
g_assert(rtype == FTREPR_DFILTER);
strcpy(buf, g_regex_get_pattern(fv->value.re));
}
static void
gregex_fvalue_set(fvalue_t *fv, const char *value)
{
g_assert(value != NULL);
gregex_fvalue_free(fv);
val_from_unparsed(fv, value, FALSE, NULL);
}
static gpointer
gregex_fvalue_get(fvalue_t *fv)
{
return fv->value.re;
}
void
ftype_register_pcre(void)
{
static ftype_t pcre_type = {
FT_PCRE,
"FT_PCRE",
"Compiled Perl-Compatible Regular Expression (GRegex) object",
0,
gregex_fvalue_new,
gregex_fvalue_free,
val_from_unparsed,
val_from_string,
gregex_to_repr,
gregex_repr_len,
NULL,
NULL,
NULL,
NULL,
gregex_fvalue_set,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
gregex_fvalue_get,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
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
ftype_register(FT_PCRE, &pcre_type);
}
