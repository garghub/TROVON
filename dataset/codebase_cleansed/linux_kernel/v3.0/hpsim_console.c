static int
simcons_init (struct console *cons, char *options)
{
return 0;
}
static void
simcons_write (struct console *cons, const char *buf, unsigned count)
{
unsigned long ch;
while (count-- > 0) {
ch = *buf++;
ia64_ssc(ch, 0, 0, 0, SSC_PUTCHAR);
if (ch == '\n')
ia64_ssc('\r', 0, 0, 0, SSC_PUTCHAR);
}
}
static struct tty_driver *simcons_console_device (struct console *c, int *index)
{
*index = c->index;
return hp_simserial_driver;
}
int simcons_register(void)
{
if (!ia64_platform_is("hpsim"))
return 1;
if (hpsim_cons.flags & CON_ENABLED)
return 1;
register_console(&hpsim_cons);
return 0;
}
