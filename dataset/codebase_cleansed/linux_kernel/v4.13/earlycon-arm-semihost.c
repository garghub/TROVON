static void smh_putc(struct uart_port *port, int c)
{
#ifdef CONFIG_ARM64
asm volatile("mov x1, %0\n"
"mov x0, #3\n"
"hlt 0xf000\n"
: : "r" (&c) : "x0", "x1", "memory");
#else
asm volatile("mov r1, %0\n"
"mov r0, #3\n"
"svc " SEMIHOST_SWI "\n"
: : "r" (&c) : "r0", "r1", "memory");
#endif
}
static void smh_write(struct console *con, const char *s, unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, smh_putc);
}
static int
__init early_smh_setup(struct earlycon_device *device, const char *opt)
{
device->con->write = smh_write;
return 0;
}
