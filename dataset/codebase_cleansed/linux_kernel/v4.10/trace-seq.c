void trace_seq_init(struct trace_seq *s)
{
s->len = 0;
s->readpos = 0;
s->buffer_size = TRACE_SEQ_BUF_SIZE;
s->buffer = malloc(s->buffer_size);
if (s->buffer != NULL)
s->state = TRACE_SEQ__GOOD;
else
s->state = TRACE_SEQ__MEM_ALLOC_FAILED;
}
void trace_seq_reset(struct trace_seq *s)
{
if (!s)
return;
TRACE_SEQ_CHECK(s);
s->len = 0;
s->readpos = 0;
}
void trace_seq_destroy(struct trace_seq *s)
{
if (!s)
return;
TRACE_SEQ_CHECK_RET(s);
free(s->buffer);
s->buffer = TRACE_SEQ_POISON;
}
static void expand_buffer(struct trace_seq *s)
{
char *buf;
buf = realloc(s->buffer, s->buffer_size + TRACE_SEQ_BUF_SIZE);
if (WARN_ONCE(!buf, "Can't allocate trace_seq buffer memory")) {
s->state = TRACE_SEQ__MEM_ALLOC_FAILED;
return;
}
s->buffer = buf;
s->buffer_size += TRACE_SEQ_BUF_SIZE;
}
int
trace_seq_printf(struct trace_seq *s, const char *fmt, ...)
{
va_list ap;
int len;
int ret;
try_again:
TRACE_SEQ_CHECK_RET0(s);
len = (s->buffer_size - 1) - s->len;
va_start(ap, fmt);
ret = vsnprintf(s->buffer + s->len, len, fmt, ap);
va_end(ap);
if (ret >= len) {
expand_buffer(s);
goto try_again;
}
s->len += ret;
return 1;
}
int
trace_seq_vprintf(struct trace_seq *s, const char *fmt, va_list args)
{
int len;
int ret;
try_again:
TRACE_SEQ_CHECK_RET0(s);
len = (s->buffer_size - 1) - s->len;
ret = vsnprintf(s->buffer + s->len, len, fmt, args);
if (ret >= len) {
expand_buffer(s);
goto try_again;
}
s->len += ret;
return len;
}
int trace_seq_puts(struct trace_seq *s, const char *str)
{
int len;
TRACE_SEQ_CHECK_RET0(s);
len = strlen(str);
while (len > ((s->buffer_size - 1) - s->len))
expand_buffer(s);
TRACE_SEQ_CHECK_RET0(s);
memcpy(s->buffer + s->len, str, len);
s->len += len;
return len;
}
int trace_seq_putc(struct trace_seq *s, unsigned char c)
{
TRACE_SEQ_CHECK_RET0(s);
while (s->len >= (s->buffer_size - 1))
expand_buffer(s);
TRACE_SEQ_CHECK_RET0(s);
s->buffer[s->len++] = c;
return 1;
}
void trace_seq_terminate(struct trace_seq *s)
{
TRACE_SEQ_CHECK_RET(s);
s->buffer[s->len] = 0;
}
int trace_seq_do_fprintf(struct trace_seq *s, FILE *fp)
{
TRACE_SEQ_CHECK(s);
switch (s->state) {
case TRACE_SEQ__GOOD:
return fprintf(fp, "%.*s", s->len, s->buffer);
case TRACE_SEQ__BUFFER_POISONED:
fprintf(fp, "%s\n", "Usage of trace_seq after it was destroyed");
break;
case TRACE_SEQ__MEM_ALLOC_FAILED:
fprintf(fp, "%s\n", "Can't allocate trace_seq buffer memory");
break;
}
return -1;
}
int trace_seq_do_printf(struct trace_seq *s)
{
return trace_seq_do_fprintf(s, stdout);
}
