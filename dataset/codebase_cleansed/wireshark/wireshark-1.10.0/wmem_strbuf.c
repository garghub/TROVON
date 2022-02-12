wmem_strbuf_t *
wmem_strbuf_sized_new(wmem_allocator_t *allocator,
gsize alloc_len, gsize max_len)
{
wmem_strbuf_t *strbuf;
g_assert((max_len == 0) || (alloc_len <= max_len));
strbuf = (wmem_strbuf_t *)wmem_alloc(allocator, sizeof(wmem_strbuf_t));
strbuf->allocator = allocator;
strbuf->len = 0;
strbuf->alloc_len = alloc_len ? alloc_len : DEFAULT_MINIMUM_LEN;
strbuf->max_len = max_len;
strbuf->str = (gchar *)wmem_alloc(strbuf->allocator, strbuf->alloc_len);
strbuf->str[0] = '\0';
return strbuf;
}
wmem_strbuf_t *
wmem_strbuf_new(wmem_allocator_t *allocator, const gchar *str)
{
wmem_strbuf_t *strbuf;
gsize len, alloc_len;
len = str ? strlen(str) : 0;
alloc_len = DEFAULT_MINIMUM_LEN;
while (alloc_len < (len + 1)) {
alloc_len *= 2;
}
strbuf = wmem_strbuf_sized_new(allocator, alloc_len, 0);
if (str && len > 0) {
strcpy(strbuf->str, str);
strbuf->len = len;
}
return strbuf;
}
static void
wmem_strbuf_grow(wmem_strbuf_t *strbuf, const gsize to_add)
{
gsize new_alloc_len, new_len;
new_alloc_len = strbuf->alloc_len;
new_len = strbuf->len + to_add;
while (new_alloc_len < (new_len + 1)) {
new_alloc_len *= 2;
}
if (strbuf->max_len && new_alloc_len > strbuf->max_len) {
new_alloc_len = strbuf->max_len;
}
if (new_alloc_len == strbuf->alloc_len) {
return;
}
strbuf->str = (gchar *)wmem_realloc(strbuf->allocator, strbuf->str, new_alloc_len);
strbuf->alloc_len = new_alloc_len;
}
void
wmem_strbuf_append(wmem_strbuf_t *strbuf, const gchar *str)
{
gsize append_len;
if (!strbuf || !str || str[0] == '\0') {
return;
}
append_len = strlen(str);
wmem_strbuf_grow(strbuf, append_len);
g_strlcpy(&strbuf->str[strbuf->len], str, strbuf->alloc_len - strbuf->len);
strbuf->len = MIN(strbuf->len + append_len, strbuf->alloc_len - 1);
}
static void
wmem_strbuf_append_vprintf(wmem_strbuf_t *strbuf, const gchar *fmt, va_list ap)
{
va_list ap2;
gsize append_len;
G_VA_COPY(ap2, ap);
append_len = g_printf_string_upper_bound(fmt, ap);
wmem_strbuf_grow(strbuf, append_len - 1);
append_len = g_vsnprintf(&strbuf->str[strbuf->len],
(gulong) (strbuf->alloc_len - strbuf->len),
fmt, ap2);
va_end(ap2);
strbuf->len = MIN(strbuf->len + append_len, strbuf->alloc_len - 1);
}
void
wmem_strbuf_append_printf(wmem_strbuf_t *strbuf, const gchar *format, ...)
{
va_list ap;
va_start(ap, format);
wmem_strbuf_append_vprintf(strbuf, format, ap);
va_end(ap);
}
const gchar *
wmem_strbuf_get_str(wmem_strbuf_t *strbuf)
{
return strbuf->str;
}
gsize
wmem_strbuf_get_len(wmem_strbuf_t *strbuf)
{
return strbuf->len;
}
