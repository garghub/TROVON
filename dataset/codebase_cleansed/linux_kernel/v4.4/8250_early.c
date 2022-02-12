static unsigned int __init serial8250_early_in(struct uart_port *port, int offset)
{
switch (port->iotype) {
case UPIO_MEM:
return readb(port->membase + offset);
case UPIO_MEM32:
return readl(port->membase + (offset << 2));
case UPIO_MEM32BE:
return ioread32be(port->membase + (offset << 2));
case UPIO_PORT:
return inb(port->iobase + offset);
default:
return 0;
}
}
static void __init serial8250_early_out(struct uart_port *port, int offset, int value)
{
switch (port->iotype) {
case UPIO_MEM:
writeb(value, port->membase + offset);
break;
case UPIO_MEM32:
writel(value, port->membase + (offset << 2));
break;
case UPIO_MEM32BE:
iowrite32be(value, port->membase + (offset << 2));
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
struct earlycon_device *device = console->data;
struct uart_port *port = &device->port;
unsigned int ier;
ier = serial8250_early_in(port, UART_IER);
if (ier)
serial8250_early_out(port, UART_IER, ier & UART_IER_UUE);
uart_console_write(port, s, count, serial_putc);
wait_for_xmitr(port);
if (ier)
serial8250_early_out(port, UART_IER, ier);
}
static void __init init_port(struct earlycon_device *device)
{
struct uart_port *port = &device->port;
unsigned int divisor;
unsigned char c;
unsigned int ier;
serial8250_early_out(port, UART_LCR, 0x3);
ier = serial8250_early_in(port, UART_IER);
serial8250_early_out(port, UART_IER, ier & UART_IER_UUE);
serial8250_early_out(port, UART_FCR, 0);
serial8250_early_out(port, UART_MCR, 0x3);
divisor = DIV_ROUND_CLOSEST(port->uartclk, 16 * device->baud);
c = serial8250_early_in(port, UART_LCR);
serial8250_early_out(port, UART_LCR, c | UART_LCR_DLAB);
serial8250_early_out(port, UART_DLL, divisor & 0xff);
serial8250_early_out(port, UART_DLM, (divisor >> 8) & 0xff);
serial8250_early_out(port, UART_LCR, c & ~UART_LCR_DLAB);
}
int __init early_serial8250_setup(struct earlycon_device *device,
const char *options)
{
if (!(device->port.membase || device->port.iobase))
return -ENODEV;
if (!device->baud) {
struct uart_port *port = &device->port;
unsigned int ier;
ier = serial8250_early_in(port, UART_IER);
serial8250_early_out(port, UART_IER, ier & UART_IER_UUE);
} else
init_port(device);
device->con->write = early_serial8250_write;
return 0;
}
