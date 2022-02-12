gboolean ws_strtoi64(const gchar* str, const gchar** endptr, gint64* cint)
{
gchar* end;
gint64 val;
g_assert(cint);
if (!str) {
errno = EINVAL;
return FALSE;
}
errno = 0;
val = g_ascii_strtoll(str, &end, 10);
if ((val == 0 && end == str) || (endptr == NULL && *end != '\0')) {
*cint = 0;
if (endptr != NULL)
*endptr = end;
errno = EINVAL;
return FALSE;
}
if ((val == G_MAXINT64 || val == G_MININT64) && errno == ERANGE) {
*cint = val;
if (endptr != NULL)
*endptr = end;
return FALSE;
}
if (endptr != NULL)
*endptr = end;
*cint = val;
return TRUE;
}
static gboolean ws_basestrtou64(const gchar* str, const gchar** endptr, guint64* cint, int base)
{
gchar* end;
guint64 val;
g_assert(cint);
if (!str) {
errno = EINVAL;
return FALSE;
}
if (str[0] == '-' || str[0] == '+') {
*cint = 0;
if (endptr != NULL)
*endptr = str;
errno = EINVAL;
return FALSE;
}
errno = 0;
val = g_ascii_strtoull(str, &end, base);
if ((val == 0 && end == str) || (endptr == NULL && *end != '\0')) {
*cint = 0;
if (endptr != NULL)
*endptr = end;
errno = EINVAL;
return FALSE;
}
if (val == G_MAXUINT64 && errno == ERANGE) {
*cint = val;
if (endptr != NULL)
*endptr = end;
return FALSE;
}
if (endptr != NULL)
*endptr = end;
*cint = val;
return TRUE;
}
gboolean ws_strtou64(const gchar* str, const gchar** endptr, guint64* cint)
{
return ws_basestrtou64(str, endptr, cint, 10);
}
gboolean ws_hexstrtou64(const gchar* str, const gchar** endptr, guint64* cint)
{
return ws_basestrtou64(str, endptr, cint, 16);
}
