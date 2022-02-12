static void early_write(const char *s, unsigned n)
{
while (n-- > 0) {
if (*s == '\n')
printch('\r');
printch(*s);
s++;
}
}
static void early_console_write(struct console *con, const char *s, unsigned n)
{
early_write(s, n);
}
asmlinkage void early_printk(const char *fmt, ...)
{
char buf[512];
int n;
va_list ap;
va_start(ap, fmt);
n = vscnprintf(buf, sizeof(buf), fmt, ap);
early_write(buf, n);
va_end(ap);
}
static int __init setup_early_printk(char *buf)
{
register_console(&early_console);
return 0;
}
