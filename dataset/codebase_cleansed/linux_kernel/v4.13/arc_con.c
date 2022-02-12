static void prom_console_write(struct console *co, const char *s,
unsigned count)
{
while (count--) {
if (*s == '\n')
prom_putchar('\r');
prom_putchar(*s++);
}
}
static int prom_console_setup(struct console *co, char *options)
{
return !(prom_flags & PROM_FLAG_USE_AS_CONSOLE);
}
static int __init arc_console_init(void)
{
register_console(&arc_cons);
return 0;
}
