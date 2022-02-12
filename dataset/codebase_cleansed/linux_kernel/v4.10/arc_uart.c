static void arc_serial_stop_rx(struct uart_port *port)
{
UART_RX_IRQ_DISABLE(port);
}
static void arc_serial_stop_tx(struct uart_port *port)
{
while (!(UART_GET_STATUS(port) & TXEMPTY))
cpu_relax();
UART_TX_IRQ_DISABLE(port);
}
static unsigned int arc_serial_tx_empty(struct uart_port *port)
{
unsigned int stat;
stat = UART_GET_STATUS(port);
if (stat & TXEMPTY)
return TIOCSER_TEMT;
return 0;
}
static void arc_serial_tx_chars(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
int sent = 0;
unsigned char ch;
if (unlikely(port->x_char)) {
UART_SET_DATA(port, port->x_char);
port->icount.tx++;
port->x_char = 0;
sent = 1;
} else if (!uart_circ_empty(xmit)) {
ch = xmit->buf[xmit->tail];
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
while (!(UART_GET_STATUS(port) & TXEMPTY))
cpu_relax();
UART_SET_DATA(port, ch);
sent = 1;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (sent)
UART_TX_IRQ_ENABLE(port);
}
static void arc_serial_start_tx(struct uart_port *port)
{
arc_serial_tx_chars(port);
}
static void arc_serial_rx_chars(struct uart_port *port, unsigned int status)
{
unsigned int ch, flg = 0;
do {
if (unlikely(status & (RXOERR | RXFERR))) {
if (status & RXOERR) {
port->icount.overrun++;
flg = TTY_OVERRUN;
UART_CLR_STATUS(port, RXOERR);
}
if (status & RXFERR) {
port->icount.frame++;
flg = TTY_FRAME;
UART_CLR_STATUS(port, RXFERR);
}
} else
flg = TTY_NORMAL;
if (status & RXEMPTY)
continue;
ch = UART_GET_DATA(port);
port->icount.rx++;
if (!(uart_handle_sysrq_char(port, ch)))
uart_insert_char(port, status, RXOERR, ch, flg);
spin_unlock(&port->lock);
tty_flip_buffer_push(&port->state->port);
spin_lock(&port->lock);
} while (!((status = UART_GET_STATUS(port)) & RXEMPTY));
}
static irqreturn_t arc_serial_isr(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
unsigned int status;
status = UART_GET_STATUS(port);
if (status & RXIENB) {
spin_lock(&port->lock);
arc_serial_rx_chars(port, status);
spin_unlock(&port->lock);
}
if ((status & TXIENB) && (status & TXEMPTY)) {
UART_TX_IRQ_DISABLE(port);
spin_lock(&port->lock);
if (!uart_tx_stopped(port))
arc_serial_tx_chars(port);
spin_unlock(&port->lock);
}
return IRQ_HANDLED;
}
static unsigned int arc_serial_get_mctrl(struct uart_port *port)
{
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}
static void arc_serial_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void arc_serial_break_ctl(struct uart_port *port, int break_state)
{
}
static int arc_serial_startup(struct uart_port *port)
{
UART_ALL_IRQ_DISABLE(port);
if (request_irq(port->irq, arc_serial_isr, 0, "arc uart rx-tx", port)) {
dev_warn(port->dev, "Unable to attach ARC UART intr\n");
return -EBUSY;
}
UART_RX_IRQ_ENABLE(port);
return 0;
}
static void arc_serial_shutdown(struct uart_port *port)
{
free_irq(port->irq, port);
}
static void
arc_serial_set_termios(struct uart_port *port, struct ktermios *new,
struct ktermios *old)
{
struct arc_uart_port *uart = to_arc_port(port);
unsigned int baud, uartl, uarth, hw_val;
unsigned long flags;
baud = uart_get_baud_rate(port, new, old, 0, 460800);
hw_val = port->uartclk / (uart->baud * 4) - 1;
uartl = hw_val & 0xFF;
uarth = (hw_val >> 8) & 0xFF;
spin_lock_irqsave(&port->lock, flags);
UART_ALL_IRQ_DISABLE(port);
UART_SET_BAUDL(port, uartl);
UART_SET_BAUDH(port, uarth);
UART_RX_IRQ_ENABLE(port);
new->c_cflag &= ~(CMSPAR|CRTSCTS|CSIZE);
new->c_cflag |= CS8;
if (old)
tty_termios_copy_hw(new, old);
if (tty_termios_baud_rate(new))
tty_termios_encode_baud_rate(new, baud, baud);
uart_update_timeout(port, new->c_cflag, baud);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *arc_serial_type(struct uart_port *port)
{
return port->type == PORT_ARC ? DRIVER_NAME : NULL;
}
static void arc_serial_release_port(struct uart_port *port)
{
}
static int arc_serial_request_port(struct uart_port *port)
{
return 0;
}
static int
arc_serial_verify_port(struct uart_port *port, struct serial_struct *ser)
{
if (port->type != PORT_UNKNOWN && ser->type != PORT_ARC)
return -EINVAL;
return 0;
}
static void arc_serial_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_ARC;
}
static void arc_serial_poll_putchar(struct uart_port *port, unsigned char chr)
{
while (!(UART_GET_STATUS(port) & TXEMPTY))
cpu_relax();
UART_SET_DATA(port, chr);
}
static int arc_serial_poll_getchar(struct uart_port *port)
{
unsigned char chr;
while (!(UART_GET_STATUS(port) & RXEMPTY))
cpu_relax();
chr = UART_GET_DATA(port);
return chr;
}
static int arc_serial_console_setup(struct console *co, char *options)
{
struct uart_port *port;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= CONFIG_SERIAL_ARC_NR_PORTS)
return -ENODEV;
port = &arc_uart_ports[co->index].port;
if (!port->membase)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static void arc_serial_console_putchar(struct uart_port *port, int ch)
{
while (!(UART_GET_STATUS(port) & TXEMPTY))
cpu_relax();
UART_SET_DATA(port, (unsigned char)ch);
}
static void arc_serial_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_port *port = &arc_uart_ports[co->index].port;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
uart_console_write(port, s, count, arc_serial_console_putchar);
spin_unlock_irqrestore(&port->lock, flags);
}
static __init void arc_early_serial_write(struct console *con, const char *s,
unsigned int n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, arc_serial_console_putchar);
}
static int __init arc_early_console_setup(struct earlycon_device *dev,
const char *opt)
{
struct uart_port *port = &dev->port;
unsigned int l, h, hw_val;
if (!dev->port.membase)
return -ENODEV;
hw_val = port->uartclk / (dev->baud * 4) - 1;
l = hw_val & 0xFF;
h = (hw_val >> 8) & 0xFF;
UART_SET_BAUDL(port, l);
UART_SET_BAUDH(port, h);
dev->con->write = arc_early_serial_write;
return 0;
}
static int arc_serial_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct arc_uart_port *uart;
struct uart_port *port;
int dev_id;
u32 val;
if (!np)
return -ENODEV;
dev_id = of_alias_get_id(np, "serial");
if (dev_id < 0)
dev_id = 0;
uart = &arc_uart_ports[dev_id];
port = &uart->port;
if (of_property_read_u32(np, "clock-frequency", &val)) {
dev_err(&pdev->dev, "clock-frequency property NOTset\n");
return -EINVAL;
}
port->uartclk = val;
if (of_property_read_u32(np, "current-speed", &val)) {
dev_err(&pdev->dev, "current-speed property NOT set\n");
return -EINVAL;
}
uart->baud = val;
port->membase = of_iomap(np, 0);
if (!port->membase)
return -ENXIO;
port->irq = irq_of_parse_and_map(np, 0);
port->dev = &pdev->dev;
port->iotype = UPIO_MEM;
port->flags = UPF_BOOT_AUTOCONF;
port->line = dev_id;
port->ops = &arc_serial_pops;
port->fifosize = ARC_UART_TX_FIFO_SIZE;
port->ignore_status_mask = 0;
return uart_add_one_port(&arc_uart_driver, &arc_uart_ports[dev_id].port);
}
static int arc_serial_remove(struct platform_device *pdev)
{
return 0;
}
static int __init arc_serial_init(void)
{
int ret;
ret = uart_register_driver(&arc_uart_driver);
if (ret)
return ret;
ret = platform_driver_register(&arc_platform_driver);
if (ret)
uart_unregister_driver(&arc_uart_driver);
return ret;
}
static void __exit arc_serial_exit(void)
{
platform_driver_unregister(&arc_platform_driver);
uart_unregister_driver(&arc_uart_driver);
}
