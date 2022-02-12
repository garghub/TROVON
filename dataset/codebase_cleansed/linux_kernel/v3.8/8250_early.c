unsigned int __weak __init serial8250_early_in(struct uart_port *port, int offset)
{
switch (port->iotype) {
case UPIO_MEM:
return readb(port->membase + offset);
case UPIO_MEM32:
return readl(port->membase + (offset << 2));
case UPIO_PORT:
return inb(port->iobase + offset);
default:
return 0;
}
}
void __weak __init serial8250_early_out(struct uart_port *port, int offset, int value)
{
switch (port->iotype) {
case UPIO_MEM:
writeb(value, port->membase + offset);
break;
case UPIO_MEM32:
writel(value, port->membase + (offset << 2));
break;
case UPIO_PORT:
outb(value, port->iobase + offset);
break;
}
}
static void __init wait_for_xmitr(struct uart_port *port)
{
unsigned int status;
for (;;) {
status = serial8250_early_in(port, UART_LSR);
if ((status & BOTH_EMPTY) == BOTH_EMPTY)
return;
cpu_relax();
}
}
static void __init serial_putc(struct uart_port *port, int c)
{
wait_for_xmitr(port);
serial8250_early_out(port, UART_TX, c);
}
static void __init early_serial8250_write(struct console *console,
const char *s, unsigned int count)
{
struct uart_port *port = &early_device.port;
unsigned int ier;
ier = serial8250_early_in(port, UART_IER);
serial8250_early_out(port, UART_IER, 0);
uart_console_write(port, s, count, serial_putc);
wait_for_xmitr(port);
serial8250_early_out(port, UART_IER, ier);
}
static unsigned int __init probe_baud(struct uart_port *port)
{
unsigned char lcr, dll, dlm;
unsigned int quot;
lcr = serial8250_early_in(port, UART_LCR);
serial8250_early_out(port, UART_LCR, lcr | UART_LCR_DLAB);
dll = serial8250_early_in(port, UART_DLL);
dlm = serial8250_early_in(port, UART_DLM);
serial8250_early_out(port, UART_LCR, lcr);
quot = (dlm << 8) | dll;
return (port->uartclk / 16) / quot;
}
static void __init init_port(struct early_serial8250_device *device)
{
struct uart_port *port = &device->port;
unsigned int divisor;
unsigned char c;
serial8250_early_out(port, UART_LCR, 0x3);
serial8250_early_out(port, UART_IER, 0);
serial8250_early_out(port, UART_FCR, 0);
serial8250_early_out(port, UART_MCR, 0x3);
divisor = DIV_ROUND_CLOSEST(port->uartclk, 16 * device->baud);
c = serial8250_early_in(port, UART_LCR);
serial8250_early_out(port, UART_LCR, c | UART_LCR_DLAB);
serial8250_early_out(port, UART_DLL, divisor & 0xff);
serial8250_early_out(port, UART_DLM, (divisor >> 8) & 0xff);
serial8250_early_out(port, UART_LCR, c & ~UART_LCR_DLAB);
}
static int __init parse_options(struct early_serial8250_device *device,
char *options)
{
struct uart_port *port = &device->port;
int mmio, mmio32, length;
if (!options)
return -ENODEV;
port->uartclk = BASE_BAUD * 16;
mmio = !strncmp(options, "mmio,", 5);
mmio32 = !strncmp(options, "mmio32,", 7);
if (mmio || mmio32) {
port->iotype = (mmio ? UPIO_MEM : UPIO_MEM32);
port->mapbase = simple_strtoul(options + (mmio ? 5 : 7),
&options, 0);
if (mmio32)
port->regshift = 2;
#ifdef CONFIG_FIX_EARLYCON_MEM
set_fixmap_nocache(FIX_EARLYCON_MEM_BASE,
port->mapbase & PAGE_MASK);
port->membase =
(void __iomem *)__fix_to_virt(FIX_EARLYCON_MEM_BASE);
port->membase += port->mapbase & ~PAGE_MASK;
#else
port->membase = ioremap_nocache(port->mapbase, 64);
if (!port->membase) {
printk(KERN_ERR "%s: Couldn't ioremap 0x%llx\n",
__func__,
(unsigned long long) port->mapbase);
return -ENOMEM;
}
#endif
} else if (!strncmp(options, "io,", 3)) {
port->iotype = UPIO_PORT;
port->iobase = simple_strtoul(options + 3, &options, 0);
mmio = 0;
} else
return -EINVAL;
options = strchr(options, ',');
if (options) {
options++;
device->baud = simple_strtoul(options, NULL, 0);
length = min(strcspn(options, " "), sizeof(device->options));
strncpy(device->options, options, length);
} else {
device->baud = probe_baud(port);
snprintf(device->options, sizeof(device->options), "%u",
device->baud);
}
if (mmio || mmio32)
printk(KERN_INFO
"Early serial console at MMIO%s 0x%llx (options '%s')\n",
mmio32 ? "32" : "",
(unsigned long long)port->mapbase,
device->options);
else
printk(KERN_INFO
"Early serial console at I/O port 0x%lx (options '%s')\n",
port->iobase,
device->options);
return 0;
}
static int __init early_serial8250_setup(char *options)
{
struct early_serial8250_device *device = &early_device;
int err;
if (device->port.membase || device->port.iobase)
return 0;
err = parse_options(device, options);
if (err < 0)
return err;
init_port(device);
return 0;
}
int __init setup_early_serial8250_console(char *cmdline)
{
char *options;
int err;
options = strstr(cmdline, "uart8250,");
if (!options) {
options = strstr(cmdline, "uart,");
if (!options)
return 0;
}
options = strchr(cmdline, ',') + 1;
err = early_serial8250_setup(options);
if (err < 0)
return err;
register_console(&early_serial8250_console);
return 0;
}
int serial8250_find_port_for_earlycon(void)
{
struct early_serial8250_device *device = &early_device;
struct uart_port *port = &device->port;
int line;
int ret;
if (!device->port.membase && !device->port.iobase)
return -ENODEV;
line = serial8250_find_port(port);
if (line < 0)
return -ENODEV;
ret = update_console_cmdline("uart", 8250,
"ttyS", line, device->options);
if (ret < 0)
ret = update_console_cmdline("uart", 0,
"ttyS", line, device->options);
return ret;
}
