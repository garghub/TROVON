static bool seq_buf_can_fit(struct seq_buf *s, size_t len)
{
return s->len + len <= s->size;
}
int seq_buf_print_seq(struct seq_file *m, struct seq_buf *s)
{
unsigned int len = seq_buf_used(s);
return seq_write(m, s->buffer, len);
}
int seq_buf_vprintf(struct seq_buf *s, const char *fmt, va_list args)
{
int len;
WARN_ON(s->size == 0);
if (s->len < s->size) {
len = vsnprintf(s->buffer + s->len, s->size - s->len, fmt, args);
if (s->len + len < s->size) {
s->len += len;
return 0;
}
}
seq_buf_set_overflow(s);
return -1;
}
int seq_buf_printf(struct seq_buf *s, const char *fmt, ...)
{
va_list ap;
int ret;
va_start(ap, fmt);
ret = seq_buf_vprintf(s, fmt, ap);
va_end(ap);
return ret;
}
int seq_buf_bprintf(struct seq_buf *s, const char *fmt, const u32 *binary)
{
unsigned int len = seq_buf_buffer_left(s);
int ret;
WARN_ON(s->size == 0);
if (s->len < s->size) {
ret = bstr_printf(s->buffer + s->len, len, fmt, binary);
if (s->len + ret < s->size) {
s->len += ret;
return 0;
}
}
seq_buf_set_overflow(s);
return -1;
}
int seq_buf_puts(struct seq_buf *s, const char *str)
{
unsigned int len = strlen(str);
WARN_ON(s->size == 0);
if (seq_buf_can_fit(s, len)) {
memcpy(s->buffer + s->len, str, len);
s->len += len;
return 0;
}
seq_buf_set_overflow(s);
return -1;
}
int seq_buf_putc(struct seq_buf *s, unsigned char c)
{
WARN_ON(s->size == 0);
if (seq_buf_can_fit(s, 1)) {
s->buffer[s->len++] = c;
return 0;
}
seq_buf_set_overflow(s);
return -1;
}
int seq_buf_putmem(struct seq_buf *s, const void *mem, unsigned int len)
{
WARN_ON(s->size == 0);
if (seq_buf_can_fit(s, len)) {
memcpy(s->buffer + s->len, mem, len);
s->len += len;
return 0;
}
seq_buf_set_overflow(s);
return -1;
}
int seq_buf_path(struct seq_buf *s, const struct path *path, const char *esc)
{
char *buf;
size_t size = seq_buf_get_buf(s, &buf);
int res = -1;
WARN_ON(s->size == 0);
if (size) {
char *p = d_path(path, buf, size);
if (!IS_ERR(p)) {
char *end = mangle_path(buf, p, esc);
if (end)
res = end - buf;
}
}
seq_buf_commit(s, res);
return res;
}
int seq_buf_to_user(struct seq_buf *s, char __user *ubuf, int cnt)
{
int len;
int ret;
if (!cnt)
return 0;
len = seq_buf_used(s);
if (len <= s->readpos)
return -EBUSY;
len -= s->readpos;
if (cnt > len)
cnt = len;
ret = copy_to_user(ubuf, s->buffer + s->readpos, cnt);
if (ret == cnt)
return -EFAULT;
cnt -= ret;
s->readpos += cnt;
return cnt;
}
