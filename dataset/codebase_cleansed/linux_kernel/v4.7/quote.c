static inline int need_bs_quote(char c)
{
return (c == '\'' || c == '!');
}
static int sq_quote_buf(struct strbuf *dst, const char *src)
{
char *to_free = NULL;
int ret;
if (dst->buf == src)
to_free = strbuf_detach(dst, NULL);
ret = strbuf_addch(dst, '\'');
while (!ret && *src) {
size_t len = strcspn(src, "'!");
ret = strbuf_add(dst, src, len);
src += len;
while (!ret && need_bs_quote(*src))
ret = strbuf_addf(dst, "'\\%c\'", *src++);
}
if (!ret)
ret = strbuf_addch(dst, '\'');
free(to_free);
return ret;
}
int sq_quote_argv(struct strbuf *dst, const char** argv, size_t maxlen)
{
int i, ret;
ret = strbuf_grow(dst, 255);
for (i = 0; !ret && argv[i]; ++i) {
ret = strbuf_addch(dst, ' ');
if (ret)
break;
ret = sq_quote_buf(dst, argv[i]);
if (maxlen && dst->len > maxlen)
die("Too many or long arguments");
}
return ret;
}
