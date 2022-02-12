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
struct uart_port *port = &early_device->port;
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
static void __init init_port(struct earlycon_device *device)
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
static int __init early_serial8250_setup(struct earlycon_device *device,
const char *options)
{
if (!(device->port.membase || device->port.iobase))
return 0;
if (!device->baud) {
device->baud = probe_baud(&device->port);
snprintf(device->options, sizeof(device->options), "%u",
device->baud);
}
init_port(device);
early_device = device;
device->con->write = early_serial8250_write;
return 0;
}
int __init setup_early_serial8250_console(char *cmdline)
{
char match[] = "uart8250";
if (cmdline && cmdline[4] == ',')
match[4] = '\0';
return setup_earlycon(cmdline, match, early_serial8250_setup);
}
int serial8250_find_port_for_earlycon(void)
{
struct earlycon_device *device = early_device;
struct uart_port *port = device ? &device->port : NULL;
int line;
int ret;
if (!port || (!port->membase && !port->iobase))
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
