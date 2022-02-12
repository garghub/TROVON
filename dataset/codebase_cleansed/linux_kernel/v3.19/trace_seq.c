static inline void __trace_seq_init(struct trace_seq *s)
{
if (unlikely(!s->seq.size))
trace_seq_init(s);
}
int trace_print_seq(struct seq_file *m, struct trace_seq *s)
{
int ret;
__trace_seq_init(s);
ret = seq_buf_print_seq(m, &s->seq);
if (!ret)
trace_seq_init(s);
return ret;
}
void trace_seq_printf(struct trace_seq *s, const char *fmt, ...)
{
unsigned int save_len = s->seq.len;
va_list ap;
if (s->full)
return;
__trace_seq_init(s);
va_start(ap, fmt);
seq_buf_vprintf(&s->seq, fmt, ap);
va_end(ap);
if (unlikely(seq_buf_has_overflowed(&s->seq))) {
s->seq.len = save_len;
s->full = 1;
}
}
void trace_seq_bitmask(struct trace_seq *s, const unsigned long *maskp,
int nmaskbits)
{
unsigned int save_len = s->seq.len;
if (s->full)
return;
__trace_seq_init(s);
seq_buf_bitmask(&s->seq, maskp, nmaskbits);
if (unlikely(seq_buf_has_overflowed(&s->seq))) {
s->seq.len = save_len;
s->full = 1;
}
}
void trace_seq_vprintf(struct trace_seq *s, const char *fmt, va_list args)
{
unsigned int save_len = s->seq.len;
if (s->full)
return;
__trace_seq_init(s);
seq_buf_vprintf(&s->seq, fmt, args);
if (unlikely(seq_buf_has_overflowed(&s->seq))) {
s->seq.len = save_len;
s->full = 1;
}
}
void trace_seq_bprintf(struct trace_seq *s, const char *fmt, const u32 *binary)
{
unsigned int save_len = s->seq.len;
if (s->full)
return;
__trace_seq_init(s);
seq_buf_bprintf(&s->seq, fmt, binary);
if (unlikely(seq_buf_has_overflowed(&s->seq))) {
s->seq.len = save_len;
s->full = 1;
return;
}
}
void trace_seq_puts(struct trace_seq *s, const char *str)
{
unsigned int len = strlen(str);
if (s->full)
return;
__trace_seq_init(s);
if (len > TRACE_SEQ_BUF_LEFT(s)) {
s->full = 1;
return;
}
seq_buf_putmem(&s->seq, str, len);
}
void trace_seq_putc(struct trace_seq *s, unsigned char c)
{
if (s->full)
return;
__trace_seq_init(s);
if (TRACE_SEQ_BUF_LEFT(s) < 1) {
s->full = 1;
return;
}
seq_buf_putc(&s->seq, c);
}
void trace_seq_putmem(struct trace_seq *s, const void *mem, unsigned int len)
{
if (s->full)
return;
__trace_seq_init(s);
if (len > TRACE_SEQ_BUF_LEFT(s)) {
s->full = 1;
return;
}
seq_buf_putmem(&s->seq, mem, len);
}
void trace_seq_putmem_hex(struct trace_seq *s, const void *mem,
unsigned int len)
{
unsigned int save_len = s->seq.len;
if (s->full)
return;
__trace_seq_init(s);
if (len * 2 > TRACE_SEQ_BUF_LEFT(s)) {
s->full = 1;
return;
}
seq_buf_putmem_hex(&s->seq, mem, len);
if (unlikely(seq_buf_has_overflowed(&s->seq))) {
s->seq.len = save_len;
s->full = 1;
return;
}
}
int trace_seq_path(struct trace_seq *s, const struct path *path)
{
unsigned int save_len = s->seq.len;
if (s->full)
return 0;
__trace_seq_init(s);
if (TRACE_SEQ_BUF_LEFT(s) < 1) {
s->full = 1;
return 0;
}
seq_buf_path(&s->seq, path, "\n");
if (unlikely(seq_buf_has_overflowed(&s->seq))) {
s->seq.len = save_len;
s->full = 1;
return 0;
}
return 1;
}
int trace_seq_to_user(struct trace_seq *s, char __user *ubuf, int cnt)
{
__trace_seq_init(s);
return seq_buf_to_user(&s->seq, ubuf, cnt);
}
