gchar *
ascii_strdown_inplace(gchar *str)
{
gchar *s;
for (s = str; *s; s++)
*s = g_ascii_tolower (*s);
return (str);
}
gchar *
ascii_strup_inplace(gchar *str)
{
gchar *s;
for (s = str; *s; s++)
*s = g_ascii_toupper (*s);
return (str);
}
gboolean
isprint_string(const gchar *str)
{
guint pos;
for(pos = 0; str[pos] != '\0'; pos++){
if(!isprint(str[pos])){
return FALSE;
}
}
return TRUE;
}
gboolean
isdigit_string(guchar *str)
{
guint pos;
for(pos = 0; str[pos] != '\0'; pos++){
if(!isdigit(str[pos])){
return FALSE;
}
}
return TRUE;
}
gchar *format_size(gint64 size, format_size_flags_e flags) {
GString *human_str = g_string_new("");
int power = 1000;
int pfx_off = 0;
gboolean is_small = FALSE;
static const gchar *prefix[] = {"T", "G", "M", "k", "Ti", "Gi", "Mi", "Ki"};
gchar *ret_val;
if ((flags & FORMAT_SIZE_PFX_MASK) == format_size_prefix_iec) {
pfx_off = 4;
power = 1024;
}
if (size / power / power / power / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power / power / power / power, prefix[pfx_off]);
} else if (size / power / power / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power / power / power, prefix[pfx_off+1]);
} else if (size / power / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power / power, prefix[pfx_off+2]);
} else if (size / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power, prefix[pfx_off+3]);
} else {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d ", size);
is_small = TRUE;
}
switch (flags & FORMAT_SIZE_UNIT_MASK) {
case format_size_unit_none:
break;
case format_size_unit_bytes:
g_string_append(human_str, is_small ? "bytes" : "B");
break;
case format_size_unit_bits:
g_string_append(human_str, is_small ? "bits" : "b");
break;
case format_size_unit_bits_s:
g_string_append(human_str, is_small ? "bits/s" : "bps");
break;
case format_size_unit_bytes_s:
g_string_append(human_str, is_small ? "bytes/s" : "Bps");
break;
default:
g_assert_not_reached();
}
ret_val = human_str->str;
g_string_free(human_str, FALSE);
return ret_val;
}
