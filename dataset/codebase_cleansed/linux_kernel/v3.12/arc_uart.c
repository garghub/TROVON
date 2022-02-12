static void arc_serial_stop_rx(struct uart_port *port)
{
struct arc_uart_port *uart = to_arc_port(port);
UART_RX_IRQ_DISABLE(uart);
}
static void arc_serial_stop_tx(struct uart_port *port)
{
struct arc_uart_port *uart = to_arc_port(port);
while (!(UART_GET_STATUS(uart) & TXEMPTY))
cpu_relax();
UART_TX_IRQ_DISABLE(uart);
}
static unsigned int arc_serial_tx_empty(struct uart_port *port)
{
struct arc_uart_port *uart = to_arc_port(port);
unsigned int stat;
stat = UART_GET_STATUS(uart);
if (stat & TXEMPTY)
return TIOCSER_TEMT;
return 0;
}
static void arc_serial_tx_chars(struct arc_uart_port *uart)
{
struct circ_buf *xmit = &uart->port.state->xmit;
int sent = 0;
unsigned char ch;
if (unlikely(uart->port.x_char)) {
UART_SET_DATA(uart, uart->port.x_char);
uart->port.icount.tx++;
uart->port.x_char = 0;
sent = 1;
} else if (xmit->tail != xmit->head) {
ch = xmit->buf[xmit->tail];
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
uart->port.icount.tx++;
while (!(UART_GET_STATUS(uart) & TXEMPTY))
cpu_relax();
UART_SET_DATA(uart, ch);
sent = 1;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&uart->port);
if (sent)
UART_TX_IRQ_ENABLE(uart);
}
static void arc_serial_start_tx(struct uart_port *port)
{
struct arc_uart_port *uart = to_arc_port(port);
arc_serial_tx_chars(uart);
}
static void arc_serial_rx_chars(struct arc_uart_port *uart, unsigned int status)
{
unsigned int ch, flg = 0;
do {
if (unlikely(status & (RXOERR | RXFERR))) {
if (status & RXOERR) {
uart->port.icount.overrun++;
flg = TTY_OVERRUN;
UART_CLR_STATUS(uart, RXOERR);
}
if (status & RXFERR) {
uart->port.icount.frame++;
flg = TTY_FRAME;
UART_CLR_STATUS(uart, RXFERR);
}
} else
flg = TTY_NORMAL;
if (status & RXEMPTY)
continue;
ch = UART_GET_DATA(uart);
uart->port.icount.rx++;
if (!(uart_handle_sysrq_char(&uart->port, ch)))
uart_insert_char(&uart->port, status, RXOERR, ch, flg);
spin_unlock(&uart->port.lock);
tty_flip_buffer_push(&uart->port.state->port);
spin_lock(&uart->port.lock);
} while (!((status = UART_GET_STATUS(uart)) & RXEMPTY));
}
static irqreturn_t arc_serial_isr(int irq, void *dev_id)
{
struct arc_uart_port *uart = dev_id;
unsigned int status;
status = UART_GET_STATUS(uart);
if (status & RXIENB) {
spin_lock(&uart->port.lock);
arc_serial_rx_chars(uart, status);
spin_unlock(&uart->port.lock);
}
if ((status & TXIENB) && (status & TXEMPTY)) {
UART_TX_IRQ_DISABLE(uart);
spin_lock(&uart->port.lock);
if (!uart_tx_stopped(&uart->port))
arc_serial_tx_chars(uart);
spin_unlock(&uart->port.lock);
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
static void arc_serial_enable_ms(struct uart_port *port)
{
}
static void arc_serial_break_ctl(struct uart_port *port, int break_state)
{
}
static int arc_serial_startup(struct uart_port *port)
{
struct arc_uart_port *uart = to_arc_port(port);
UART_ALL_IRQ_DISABLE(uart);
if (request_irq(uart->port.irq, arc_serial_isr, 0, "arc uart rx-tx",
uart)) {
dev_warn(uart->port.dev, "Unable to attach ARC UART intr\n");
return -EBUSY;
}
UART_RX_IRQ_ENABLE(uart);
return 0;
}
static void arc_serial_shutdown(struct uart_port *port)
{
struct arc_uart_port *uart = to_arc_port(port);
free_irq(uart->port.irq, uart);
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
if (uart->is_emulated)
uarth = 1;
spin_lock_irqsave(&port->lock, flags);
UART_ALL_IRQ_DISABLE(uart);
UART_SET_BAUDL(uart, uartl);
UART_SET_BAUDH(uart, uarth);
UART_RX_IRQ_ENABLE(uart);
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
struct arc_uart_port *uart = to_arc_port(port);
return uart->port.type == PORT_ARC ? DRIVER_NAME : NULL;
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
struct arc_uart_port *uart = to_arc_port(port);
if (flags & UART_CONFIG_TYPE)
uart->port.type = PORT_ARC;
}
static void arc_serial_poll_putchar(struct uart_port *port, unsigned char chr)
{
struct arc_uart_port *uart = to_arc_port(port);
while (!(UART_GET_STATUS(uart) & TXEMPTY))
cpu_relax();
UART_SET_DATA(uart, chr);
}
static int arc_serial_poll_getchar(struct uart_port *port)
{
struct arc_uart_port *uart = to_arc_port(port);
unsigned char chr;
while (!(UART_GET_STATUS(uart) & RXEMPTY))
cpu_relax();
chr = UART_GET_DATA(uart);
return chr;
}
static int
arc_uart_init_one(struct platform_device *pdev, int dev_id)
{
struct resource *res, *res2;
unsigned long *plat_data;
struct arc_uart_port *uart = &arc_uart_ports[dev_id];
plat_data = (unsigned long *)dev_get_platdata(&pdev->dev);
if (!plat_data)
return -ENODEV;
uart->is_emulated = !!plat_data[0];
if (is_early_platform_device(pdev)) {
uart->port.uartclk = plat_data[1];
uart->baud = plat_data[2];
} else {
struct device_node *np = pdev->dev.of_node;
u32 val;
if (of_property_read_u32(np, "clock-frequency", &val)) {
dev_err(&pdev->dev, "clock-frequency property NOTset\n");
return -EINVAL;
}
uart->port.uartclk = val;
if (of_property_read_u32(np, "current-speed", &val)) {
dev_err(&pdev->dev, "current-speed property NOT set\n");
return -EINVAL;
}
uart->baud = val;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res2)
return -ENODEV;
uart->port.mapbase = res->start;
uart->port.membase = ioremap_nocache(res->start, resource_size(res));
if (!uart->port.membase)
return -ENXIO;
uart->port.irq = res2->start;
uart->port.dev = &pdev->dev;
uart->port.iotype = UPIO_MEM;
uart->port.flags = UPF_BOOT_AUTOCONF;
uart->port.line = dev_id;
uart->port.ops = &arc_serial_pops;
uart->port.fifosize = ARC_UART_TX_FIFO_SIZE;
uart->port.ignore_status_mask = 0;
return 0;
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
arc_serial_poll_putchar(port, (unsigned char)ch);
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
static __init void early_serial_write(struct console *con, const char *s,
unsigned int n)
{
struct uart_port *port = &arc_uart_ports[con->index].port;
unsigned int i;
for (i = 0; i < n; i++, s++) {
if (*s == '\n')
arc_serial_poll_putchar(port, '\r');
arc_serial_poll_putchar(port, *s);
}
}
static int __init arc_serial_probe_earlyprintk(struct platform_device *pdev)
{
int dev_id = pdev->id < 0 ? 0 : pdev->id;
int rc;
arc_early_serial_console.index = dev_id;
rc = arc_uart_init_one(pdev, dev_id);
if (rc)
panic("early console init failed\n");
arc_serial_console_setup(&arc_early_serial_console, NULL);
register_console(&arc_early_serial_console);
return 0;
}
static int arc_serial_probe(struct platform_device *pdev)
{
int rc, dev_id;
struct device_node *np = pdev->dev.of_node;
if (!np)
return -ENODEV;
dev_id = of_alias_get_id(np, "serial");
if (dev_id < 0)
dev_id = 0;
rc = arc_uart_init_one(pdev, dev_id);
if (rc)
return rc;
rc = uart_add_one_port(&arc_uart_driver, &arc_uart_ports[dev_id].port);
return rc;
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
