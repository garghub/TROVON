static inline void vt8500_write(struct uart_port *port, unsigned int val,
unsigned int off)
{
writel(val, port->membase + off);
}
static inline unsigned int vt8500_read(struct uart_port *port, unsigned int off)
{
return readl(port->membase + off);
}
static void vt8500_stop_tx(struct uart_port *port)
{
struct vt8500_port *vt8500_port = container_of(port,
struct vt8500_port,
uart);
vt8500_port->ier &= ~TX_FIFO_INTS;
vt8500_write(port, vt8500_port->ier, VT8500_URIER);
}
static void vt8500_stop_rx(struct uart_port *port)
{
struct vt8500_port *vt8500_port = container_of(port,
struct vt8500_port,
uart);
vt8500_port->ier &= ~RX_FIFO_INTS;
vt8500_write(port, vt8500_port->ier, VT8500_URIER);
}
static void vt8500_enable_ms(struct uart_port *port)
{
struct vt8500_port *vt8500_port = container_of(port,
struct vt8500_port,
uart);
vt8500_port->ier |= TCTS;
vt8500_write(port, vt8500_port->ier, VT8500_URIER);
}
static void handle_rx(struct uart_port *port)
{
struct tty_struct *tty = tty_port_tty_get(&port->state->port);
if (!tty) {
int count = (vt8500_read(port, VT8500_URFIDX) & 0x1f00) >> 8;
u16 ch;
while (count--)
ch = readw(port->membase + VT8500_RXFIFO);
return;
}
if ((vt8500_read(port, VT8500_URISR) & RXOVER)) {
port->icount.overrun++;
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
}
while (vt8500_read(port, VT8500_URFIDX) & 0x1f00) {
unsigned int c;
char flag = TTY_NORMAL;
c = readw(port->membase + VT8500_RXFIFO) & 0x3ff;
c &= ~port->read_status_mask;
if (c & FER) {
port->icount.frame++;
flag = TTY_FRAME;
} else if (c & PER) {
port->icount.parity++;
flag = TTY_PARITY;
}
port->icount.rx++;
if (!uart_handle_sysrq_char(port, c))
tty_insert_flip_char(tty, c, flag);
}
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
static void handle_tx(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
if (port->x_char) {
writeb(port->x_char, port->membase + VT8500_TXFIFO);
port->icount.tx++;
port->x_char = 0;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
vt8500_stop_tx(port);
return;
}
while ((vt8500_read(port, VT8500_URFIDX) & 0x1f) < 16) {
if (uart_circ_empty(xmit))
break;
writeb(xmit->buf[xmit->tail], port->membase + VT8500_TXFIFO);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit))
vt8500_stop_tx(port);
}
static void vt8500_start_tx(struct uart_port *port)
{
struct vt8500_port *vt8500_port = container_of(port,
struct vt8500_port,
uart);
vt8500_port->ier &= ~TX_FIFO_INTS;
vt8500_write(port, vt8500_port->ier, VT8500_URIER);
handle_tx(port);
vt8500_port->ier |= TX_FIFO_INTS;
vt8500_write(port, vt8500_port->ier, VT8500_URIER);
}
static void handle_delta_cts(struct uart_port *port)
{
port->icount.cts++;
wake_up_interruptible(&port->state->port.delta_msr_wait);
}
static irqreturn_t vt8500_irq(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
unsigned long isr;
spin_lock(&port->lock);
isr = vt8500_read(port, VT8500_URISR);
vt8500_write(port, isr, VT8500_URISR);
if (isr & RX_FIFO_INTS)
handle_rx(port);
if (isr & TX_FIFO_INTS)
handle_tx(port);
if (isr & TCTS)
handle_delta_cts(port);
spin_unlock(&port->lock);
return IRQ_HANDLED;
}
static unsigned int vt8500_tx_empty(struct uart_port *port)
{
return (vt8500_read(port, VT8500_URFIDX) & 0x1f) < 16 ?
TIOCSER_TEMT : 0;
}
static unsigned int vt8500_get_mctrl(struct uart_port *port)
{
unsigned int usr;
usr = vt8500_read(port, VT8500_URUSR);
if (usr & (1 << 4))
return TIOCM_CTS;
else
return 0;
}
static void vt8500_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void vt8500_break_ctl(struct uart_port *port, int break_ctl)
{
if (break_ctl)
vt8500_write(port, vt8500_read(port, VT8500_URLCR) | (1 << 9),
VT8500_URLCR);
}
static int vt8500_set_baud_rate(struct uart_port *port, unsigned int baud)
{
unsigned long div;
unsigned int loops = 1000;
div = vt8500_read(port, VT8500_URDIV) & ~(0x3ff);
if (unlikely((baud < 900) || (baud > 921600)))
div |= 7;
else
div |= (921600 / baud) - 1;
while ((vt8500_read(port, VT8500_URUSR) & (1 << 5)) && --loops)
cpu_relax();
vt8500_write(port, div, VT8500_URDIV);
return baud;
}
static int vt8500_startup(struct uart_port *port)
{
struct vt8500_port *vt8500_port =
container_of(port, struct vt8500_port, uart);
int ret;
snprintf(vt8500_port->name, sizeof(vt8500_port->name),
"vt8500_serial%d", port->line);
ret = request_irq(port->irq, vt8500_irq, IRQF_TRIGGER_HIGH,
vt8500_port->name, port);
if (unlikely(ret))
return ret;
vt8500_write(port, 0x03, VT8500_URLCR);
return 0;
}
static void vt8500_shutdown(struct uart_port *port)
{
struct vt8500_port *vt8500_port =
container_of(port, struct vt8500_port, uart);
vt8500_port->ier = 0;
vt8500_write(&vt8500_port->uart, 0, VT8500_URIER);
vt8500_write(&vt8500_port->uart, 0x880, VT8500_URFCR);
free_irq(port->irq, port);
}
static void vt8500_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
struct vt8500_port *vt8500_port =
container_of(port, struct vt8500_port, uart);
unsigned long flags;
unsigned int baud, lcr;
unsigned int loops = 1000;
spin_lock_irqsave(&port->lock, flags);
baud = uart_get_baud_rate(port, termios, old, 900, 921600);
baud = vt8500_set_baud_rate(port, baud);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
lcr = vt8500_read(&vt8500_port->uart, VT8500_URLCR);
lcr &= ~((1 << 5) | (1 << 4));
if (termios->c_cflag & PARENB) {
lcr |= (1 << 4);
termios->c_cflag &= ~CMSPAR;
if (termios->c_cflag & PARODD)
lcr |= (1 << 5);
}
lcr &= ~(1 << 2);
switch (termios->c_cflag & CSIZE) {
case CS7:
break;
case CS8:
default:
lcr |= (1 << 2);
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= CS8;
break;
}
lcr &= ~(1 << 3);
if (termios->c_cflag & CSTOPB)
lcr |= (1 << 3);
vt8500_write(&vt8500_port->uart, lcr, VT8500_URLCR);
port->read_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->read_status_mask = FER | PER;
uart_update_timeout(port, termios->c_cflag, baud);
vt8500_write(&vt8500_port->uart, 0x88c, VT8500_URFCR);
while ((vt8500_read(&vt8500_port->uart, VT8500_URFCR) & 0xc)
&& --loops)
cpu_relax();
vt8500_port->ier = RX_FIFO_INTS | TX_FIFO_INTS;
if (UART_ENABLE_MS(&vt8500_port->uart, termios->c_cflag))
vt8500_port->ier |= TCTS;
vt8500_write(&vt8500_port->uart, 0x881, VT8500_URFCR);
vt8500_write(&vt8500_port->uart, vt8500_port->ier, VT8500_URIER);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *vt8500_type(struct uart_port *port)
{
struct vt8500_port *vt8500_port =
container_of(port, struct vt8500_port, uart);
return vt8500_port->name;
}
static void vt8500_release_port(struct uart_port *port)
{
}
static int vt8500_request_port(struct uart_port *port)
{
return 0;
}
static void vt8500_config_port(struct uart_port *port, int flags)
{
port->type = PORT_VT8500;
}
static int vt8500_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
if (unlikely(ser->type != PORT_UNKNOWN && ser->type != PORT_VT8500))
return -EINVAL;
if (unlikely(port->irq != ser->irq))
return -EINVAL;
return 0;
}
static inline void wait_for_xmitr(struct uart_port *port)
{
unsigned int status, tmout = 10000;
do {
status = vt8500_read(port, VT8500_URFIDX);
if (--tmout == 0)
break;
udelay(1);
} while (status & 0x10);
}
static void vt8500_console_putchar(struct uart_port *port, int c)
{
wait_for_xmitr(port);
writeb(c, port->membase + VT8500_TXFIFO);
}
static void vt8500_console_write(struct console *co, const char *s,
unsigned int count)
{
struct vt8500_port *vt8500_port = vt8500_uart_ports[co->index];
unsigned long ier;
BUG_ON(co->index < 0 || co->index >= vt8500_uart_driver.nr);
ier = vt8500_read(&vt8500_port->uart, VT8500_URIER);
vt8500_write(&vt8500_port->uart, VT8500_URIER, 0);
uart_console_write(&vt8500_port->uart, s, count,
vt8500_console_putchar);
wait_for_xmitr(&vt8500_port->uart);
vt8500_write(&vt8500_port->uart, VT8500_URIER, ier);
}
static int __init vt8500_console_setup(struct console *co, char *options)
{
struct vt8500_port *vt8500_port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (unlikely(co->index >= vt8500_uart_driver.nr || co->index < 0))
return -ENXIO;
vt8500_port = vt8500_uart_ports[co->index];
if (!vt8500_port)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&vt8500_port->uart,
co, baud, parity, bits, flow);
}
static int __init vt8500_serial_probe(struct platform_device *pdev)
{
struct vt8500_port *vt8500_port;
struct resource *mmres, *irqres;
int ret;
mmres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irqres = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!mmres || !irqres)
return -ENODEV;
vt8500_port = kzalloc(sizeof(struct vt8500_port), GFP_KERNEL);
if (!vt8500_port)
return -ENOMEM;
vt8500_port->uart.type = PORT_VT8500;
vt8500_port->uart.iotype = UPIO_MEM;
vt8500_port->uart.mapbase = mmres->start;
vt8500_port->uart.irq = irqres->start;
vt8500_port->uart.fifosize = 16;
vt8500_port->uart.ops = &vt8500_uart_pops;
vt8500_port->uart.line = pdev->id;
vt8500_port->uart.dev = &pdev->dev;
vt8500_port->uart.flags = UPF_IOREMAP | UPF_BOOT_AUTOCONF;
vt8500_port->uart.uartclk = 24000000;
snprintf(vt8500_port->name, sizeof(vt8500_port->name),
"VT8500 UART%d", pdev->id);
vt8500_port->uart.membase = ioremap(mmres->start,
mmres->end - mmres->start + 1);
if (!vt8500_port->uart.membase) {
ret = -ENOMEM;
goto err;
}
vt8500_uart_ports[pdev->id] = vt8500_port;
uart_add_one_port(&vt8500_uart_driver, &vt8500_port->uart);
platform_set_drvdata(pdev, vt8500_port);
return 0;
err:
kfree(vt8500_port);
return ret;
}
static int __devexit vt8500_serial_remove(struct platform_device *pdev)
{
struct vt8500_port *vt8500_port = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
uart_remove_one_port(&vt8500_uart_driver, &vt8500_port->uart);
kfree(vt8500_port);
return 0;
}
static int __init vt8500_serial_init(void)
{
int ret;
ret = uart_register_driver(&vt8500_uart_driver);
if (unlikely(ret))
return ret;
ret = platform_driver_register(&vt8500_platform_driver);
if (unlikely(ret))
uart_unregister_driver(&vt8500_uart_driver);
return ret;
}
static void __exit vt8500_serial_exit(void)
{
#ifdef CONFIG_SERIAL_VT8500_CONSOLE
unregister_console(&vt8500_console);
#endif
platform_driver_unregister(&vt8500_platform_driver);
uart_unregister_driver(&vt8500_uart_driver);
}
