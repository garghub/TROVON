void ui_helpline__pop(void)
{
newtPopHelpLine();
}
void ui_helpline__push(const char *msg)
{
newtPushHelpLine(msg);
}
void ui_helpline__vpush(const char *fmt, va_list ap)
{
char *s;
if (vasprintf(&s, fmt, ap) < 0)
vfprintf(stderr, fmt, ap);
else {
ui_helpline__push(s);
free(s);
}
}
void ui_helpline__fpush(const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
ui_helpline__vpush(fmt, ap);
va_end(ap);
}
void ui_helpline__puts(const char *msg)
{
ui_helpline__pop();
ui_helpline__push(msg);
}
void ui_helpline__init(void)
{
ui_helpline__puts(" ");
}
int ui_helpline__show_help(const char *format, va_list ap)
{
int ret;
static int backlog;
pthread_mutex_lock(&ui__lock);
ret = vsnprintf(ui_helpline__last_msg + backlog,
sizeof(ui_helpline__last_msg) - backlog, format, ap);
backlog += ret;
if (ui_helpline__last_msg[backlog - 1] == '\n') {
ui_helpline__puts(ui_helpline__last_msg);
newtRefresh();
backlog = 0;
}
pthread_mutex_unlock(&ui__lock);
return ret;
}
