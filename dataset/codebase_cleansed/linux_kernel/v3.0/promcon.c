static void prom_console_write(struct console *co, const char *s,
unsigned count)
{
unsigned i;
for (i = 0; i < count; i++) {
if (*s == 10)
prom_printf("%c", 13);
prom_printf("%c", *s++);
}
}
static int __init prom_console_setup(struct console *co, char *options)
{
return 0;
}
static int __init prom_console_init(void)
{
register_console(&sercons);
return 0;
}
