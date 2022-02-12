gchar *
wmem_strdup(wmem_allocator_t *allocator, const gchar *src)
{
size_t len;
if(!src) {
src = "<NULL>";
}
len = strlen(src) + 1;
return (gchar *)memcpy(wmem_alloc(allocator, len), src, len);
}
gchar *
wmem_strndup(wmem_allocator_t *allocator, const gchar *src, const size_t len)
{
gchar *dst;
guint i;
dst = (gchar *)wmem_alloc(allocator, len+1);
for (i=0; (i < len) && src[i]; i++) {
dst[i] = src[i];
}
dst[i] = '\0';
return dst;
}
gchar *
wmem_strdup_printf(wmem_allocator_t *allocator, const gchar *fmt, ...)
{
va_list ap;
gchar *dst;
va_start(ap, fmt);
dst = wmem_strdup_vprintf(allocator, fmt, ap);
va_end(ap);
return dst;
}
gchar *
wmem_strdup_vprintf(wmem_allocator_t *allocator, const gchar *fmt, va_list ap)
{
va_list ap2;
gsize len;
gchar* dst;
G_VA_COPY(ap2, ap);
len = g_printf_string_upper_bound(fmt, ap);
dst = (gchar *)wmem_alloc(allocator, len+1);
g_vsnprintf(dst, (gulong) len, fmt, ap2);
va_end(ap2);
return dst;
}
