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
static int __init setup_early_printk(char *buf)
{
early_console = &early_console_dev;
register_console(&early_console_dev);
return 0;
}
