void
ws_add_crash_info(const char *fmt, ...)
{
va_list ap;
char *m, *old_info, *new_info;
va_start(ap, fmt);
m = g_strdup_vprintf(fmt, ap);
va_end(ap);
if (__crashreporter_info__ == NULL)
__crashreporter_info__ = m;
else {
old_info = __crashreporter_info__;
new_info = g_strdup_printf("%s\n%s", old_info, m);
g_free(m);
__crashreporter_info__ = new_info;
g_free(old_info);
}
}
void
ws_add_crash_info(const char *fmt _U_, ...)
{
}
