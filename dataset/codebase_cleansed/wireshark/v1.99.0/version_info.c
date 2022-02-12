static void
end_string(GString *str)
{
size_t point;
char *p, *q;
point = str->len;
if (point == 0 || str->str[point - 1] != '\n')
g_string_append(str, "\n");
p = str->str;
while (*p != '\0') {
q = strchr(p, '\n');
if (q - p > 80) {
q = p + 80;
while (q > p && *q != ' ')
q--;
if (q != p)
*q = '\n';
}
p = q + 1;
}
}
void
get_compiled_version_info(GString *str, void (*prepend_info)(GString *),
void (*append_info)(GString *))
{
if (sizeof(str) == 4)
g_string_append(str, "(32-bit) ");
else
g_string_append(str, "(64-bit) ");
if (prepend_info) {
(*prepend_info)(str);
g_string_append(str, ", ");
}
get_glib_version_info(str);
if (append_info)
(*append_info)(str);
g_string_append(str, ".");
end_string(str);
}
void
get_runtime_version_info(GString *str, void (*additional_info)(GString *))
{
#ifndef _WIN32
gchar *lang;
#endif
g_string_append(str, "on ");
get_os_version_info(str);
#ifndef _WIN32
if ((lang = getenv ("LANG")) != NULL)
g_string_append_printf(str, ", with locale %s", lang);
else
g_string_append(str, ", without locale");
#endif
if (additional_info)
(*additional_info)(str);
g_string_append(str, ".");
get_cpu_info(str);
get_mem_info(str);
get_compiler_info(str);
end_string(str);
}
