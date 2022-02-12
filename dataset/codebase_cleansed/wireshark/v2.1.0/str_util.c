int
ws_xton(char ch)
{
switch (ch) {
case '0': return 0;
case '1': return 1;
case '2': return 2;
case '3': return 3;
case '4': return 4;
case '5': return 5;
case '6': return 6;
case '7': return 7;
case '8': return 8;
case '9': return 9;
case 'a': case 'A': return 10;
case 'b': case 'B': return 11;
case 'c': case 'C': return 12;
case 'd': case 'D': return 13;
case 'e': case 'E': return 14;
case 'f': case 'F': return 15;
default: return -1;
}
}
gchar *
ascii_strdown_inplace(gchar *str)
{
gchar *s;
for (s = str; *s; s++)
*s = g_ascii_isupper (*s) ? *s - 'A' + 'a' : *s;
return (str);
}
gchar *
ascii_strup_inplace(gchar *str)
{
gchar *s;
for (s = str; *s; s++)
*s = g_ascii_islower (*s) ? *s - 'a' + 'A' : *s;
return (str);
}
gboolean
isprint_string(const gchar *str)
{
guint pos;
for(pos = 0; str[pos] != '\0'; pos++){
if(!g_ascii_isprint(str[pos])){
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
if(!g_ascii_isdigit(str[pos])){
return FALSE;
}
}
return TRUE;
}
gchar *
format_size(gint64 size, format_size_flags_e flags)
{
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
DIAG_OFF(format)
if (size / power / power / power / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power / power / power / power, prefix[pfx_off]);
} else if (size / power / power / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power / power / power, prefix[pfx_off+1]);
} else if (size / power / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power / power, prefix[pfx_off+2]);
} else if (size / power >= 10) {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d %s", size / power, prefix[pfx_off+3]);
} else {
g_string_printf(human_str, "%" GROUP_FLAG G_GINT64_MODIFIER "d", size);
is_small = TRUE;
}
DIAG_ON(format)
switch (flags & FORMAT_SIZE_UNIT_MASK) {
case format_size_unit_none:
break;
case format_size_unit_bytes:
g_string_append(human_str, is_small ? " bytes" : "B");
break;
case format_size_unit_bits:
g_string_append(human_str, is_small ? " bits" : "b");
break;
case format_size_unit_bits_s:
g_string_append(human_str, is_small ? " bits/s" : "bps");
break;
case format_size_unit_bytes_s:
g_string_append(human_str, is_small ? " bytes/s" : "Bps");
break;
case format_size_unit_packets:
g_string_append(human_str, is_small ? " packets" : "packets");
break;
case format_size_unit_packets_s:
g_string_append(human_str, is_small ? " packets/s" : "packets/s");
break;
default:
g_assert_not_reached();
}
ret_val = g_string_free(human_str, FALSE);
return g_strchomp(ret_val);
}
gchar
printable_char_or_period(gchar c)
{
return g_ascii_isprint(c) ? c : '.';
}
