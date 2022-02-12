int trace_print_seq(struct seq_file *m, struct trace_seq *s)
{
unsigned int len = TRACE_SEQ_BUF_USED(s);
int ret;
ret = seq_write(m, s->buffer, len);
if (!ret)
trace_seq_init(s);
return ret;
}
int trace_seq_printf(struct trace_seq *s, const char *fmt, ...)
{
unsigned int len = TRACE_SEQ_BUF_LEFT(s);
va_list ap;
int ret;
if (s->full || !len)
return 0;
va_start(ap, fmt);
ret = vsnprintf(s->buffer + s->len, len, fmt, ap);
va_end(ap);
if (ret >= len) {
s->full = 1;
return 0;
}
s->len += ret;
return 1;
}
int trace_seq_bitmask(struct trace_seq *s, const unsigned long *maskp,
int nmaskbits)
{
unsigned int len = TRACE_SEQ_BUF_LEFT(s);
int ret;
if (s->full || !len)
return 0;
ret = bitmap_scnprintf(s->buffer, len, maskp, nmaskbits);
s->len += ret;
return 1;
}
int trace_seq_vprintf(struct trace_seq *s, const char *fmt, va_list args)
{
unsigned int len = TRACE_SEQ_BUF_LEFT(s);
int ret;
if (s->full || !len)
return 0;
ret = vsnprintf(s->buffer + s->len, len, fmt, args);
if (ret >= len) {
s->full = 1;
return 0;
}
s->len += ret;
return len;
}
int trace_seq_bprintf(struct trace_seq *s, const char *fmt, const u32 *binary)
{
unsigned int len = TRACE_SEQ_BUF_LEFT(s);
int ret;
if (s->full || !len)
return 0;
ret = bstr_printf(s->buffer + s->len, len, fmt, binary);
if (ret >= len) {
s->full = 1;
return 0;
}
s->len += ret;
return len;
}
int trace_seq_puts(struct trace_seq *s, const char *str)
{
unsigned int len = strlen(str);
if (s->full)
return 0;
if (len > TRACE_SEQ_BUF_LEFT(s)) {
s->full = 1;
return 0;
}
memcpy(s->buffer + s->len, str, len);
s->len += len;
return len;
}
int trace_seq_putc(struct trace_seq *s, unsigned char c)
{
if (s->full)
return 0;
if (TRACE_SEQ_BUF_LEFT(s) < 1) {
s->full = 1;
return 0;
}
s->buffer[s->len++] = c;
return 1;
}
int trace_seq_putmem(struct trace_seq *s, const void *mem, unsigned int len)
{
if (s->full)
return 0;
if (len > TRACE_SEQ_BUF_LEFT(s)) {
s->full = 1;
return 0;
}
memcpy(s->buffer + s->len, mem, len);
s->len += len;
return len;
}
int trace_seq_path(struct trace_seq *s, const struct path *path)
{
unsigned char *p;
if (s->full)
return 0;
if (TRACE_SEQ_BUF_LEFT(s) < 1) {
s->full = 1;
return 0;
}
p = d_path(path, s->buffer + s->len, PAGE_SIZE - s->len);
if (!IS_ERR(p)) {
p = mangle_path(s->buffer + s->len, p, "\n");
if (p) {
s->len = p - s->buffer;
return 1;
}
} else {
s->buffer[s->len++] = '?';
return 1;
}
s->full = 1;
return 0;
}
int trace_seq_to_user(struct trace_seq *s, char __user *ubuf, int cnt)
{
int len;
int ret;
if (!cnt)
return 0;
if (s->len <= s->readpos)
return -EBUSY;
len = s->len - s->readpos;
if (cnt > len)
cnt = len;
ret = copy_to_user(ubuf, s->buffer + s->readpos, cnt);
if (ret == cnt)
return -EFAULT;
cnt -= ret;
s->readpos += cnt;
return cnt;
}
