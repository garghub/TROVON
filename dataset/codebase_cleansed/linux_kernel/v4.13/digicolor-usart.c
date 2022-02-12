static bool digicolor_uart_tx_full(struct uart_port *port)
{
return !!(readb_relaxed(port->membase + UA_STATUS_FIFO) &
UA_STATUS_FIFO_TX_FULL);
}
static bool digicolor_uart_rx_empty(struct uart_port *port)
{
return !!(readb_relaxed(port->membase + UA_STATUS_FIFO) &
UA_STATUS_FIFO_RX_EMPTY);
}
static void digicolor_uart_stop_tx(struct uart_port *port)
{
u8 int_enable = readb_relaxed(port->membase + UA_INT_ENABLE);
int_enable &= ~UA_INT_TX;
writeb_relaxed(int_enable, port->membase + UA_INT_ENABLE);
}
static void digicolor_uart_start_tx(struct uart_port *port)
{
u8 int_enable = readb_relaxed(port->membase + UA_INT_ENABLE);
int_enable |= UA_INT_TX;
writeb_relaxed(int_enable, port->membase + UA_INT_ENABLE);
}
static void digicolor_uart_stop_rx(struct uart_port *port)
{
u8 int_enable = readb_relaxed(port->membase + UA_INT_ENABLE);
int_enable &= ~UA_INT_RX;
writeb_relaxed(int_enable, port->membase + UA_INT_ENABLE);
}
static void digicolor_rx_poll(struct work_struct *work)
{
struct digicolor_port *dp =
container_of(to_delayed_work(work),
struct digicolor_port, rx_poll_work);
if (!digicolor_uart_rx_empty(&dp->port))
writeb_relaxed(UA_INT_RX, dp->port.membase + UA_INTFLAG_SET);
schedule_delayed_work(&dp->rx_poll_work, msecs_to_jiffies(100));
}
static void digicolor_uart_rx(struct uart_port *port)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
while (1) {
u8 status, ch;
unsigned int ch_flag;
if (digicolor_uart_rx_empty(port))
break;
ch = readb_relaxed(port->membase + UA_EMI_REC);
status = readb_relaxed(port->membase + UA_STATUS);
port->icount.rx++;
ch_flag = TTY_NORMAL;
if (status) {
if (status & UA_STATUS_PARITY_ERR)
port->icount.parity++;
else if (status & UA_STATUS_FRAME_ERR)
port->icount.frame++;
else if (status & UA_STATUS_OVERRUN_ERR)
port->icount.overrun++;
status &= port->read_status_mask;
if (status & UA_STATUS_PARITY_ERR)
ch_flag = TTY_PARITY;
else if (status & UA_STATUS_FRAME_ERR)
ch_flag = TTY_FRAME;
else if (status & UA_STATUS_OVERRUN_ERR)
ch_flag = TTY_OVERRUN;
}
if (status & port->ignore_status_mask)
continue;
uart_insert_char(port, status, UA_STATUS_OVERRUN_ERR, ch,
ch_flag);
}
spin_unlock_irqrestore(&port->lock, flags);
tty_flip_buffer_push(&port->state->port);
}
static void digicolor_uart_tx(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
unsigned long flags;
if (digicolor_uart_tx_full(port))
return;
spin_lock_irqsave(&port->lock, flags);
if (port->x_char) {
writeb_relaxed(port->x_char, port->membase + UA_EMI_REC);
port->icount.tx++;
port->x_char = 0;
goto out;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
digicolor_uart_stop_tx(port);
goto out;
}
while (!uart_circ_empty(xmit)) {
writeb(xmit->buf[xmit->tail], port->membase + UA_EMI_REC);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (digicolor_uart_tx_full(port))
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
out:
spin_unlock_irqrestore(&port->lock, flags);
}
static irqreturn_t digicolor_uart_int(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
u8 int_status = readb_relaxed(port->membase + UA_INT_STATUS);
writeb_relaxed(UA_INT_RX | UA_INT_TX,
port->membase + UA_INTFLAG_CLEAR);
if (int_status & UA_INT_RX)
digicolor_uart_rx(port);
if (int_status & UA_INT_TX)
digicolor_uart_tx(port);
return IRQ_HANDLED;
}
static unsigned int digicolor_uart_tx_empty(struct uart_port *port)
{
u8 status = readb_relaxed(port->membase + UA_STATUS);
return (status & UA_STATUS_TX_READY) ? TIOCSER_TEMT : 0;
}
static unsigned int digicolor_uart_get_mctrl(struct uart_port *port)
{
return TIOCM_CTS;
}
static void digicolor_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static void digicolor_uart_break_ctl(struct uart_port *port, int state)
{
}
static int digicolor_uart_startup(struct uart_port *port)
{
struct digicolor_port *dp =
container_of(port, struct digicolor_port, port);
writeb_relaxed(UA_ENABLE_ENABLE, port->membase + UA_ENABLE);
writeb_relaxed(UA_CONTROL_SOFT_RESET, port->membase + UA_CONTROL);
writeb_relaxed(0, port->membase + UA_CONTROL);
writeb_relaxed(UA_CONFIG_FIFO_RX_FIFO_MODE
| UA_CONFIG_FIFO_TX_FIFO_MODE | UA_CONFIG_FIFO_RX_THRESH,
port->membase + UA_CONFIG_FIFO);
writeb_relaxed(UA_STATUS_FIFO_RX_INT_ALMOST,
port->membase + UA_STATUS_FIFO);
writeb_relaxed(UA_CONTROL_RX_ENABLE | UA_CONTROL_TX_ENABLE,
port->membase + UA_CONTROL);
writeb_relaxed(UA_INT_TX | UA_INT_RX,
port->membase + UA_INT_ENABLE);
schedule_delayed_work(&dp->rx_poll_work, msecs_to_jiffies(100));
return 0;
}
static void digicolor_uart_shutdown(struct uart_port *port)
{
struct digicolor_port *dp =
container_of(port, struct digicolor_port, port);
writeb_relaxed(0, port->membase + UA_ENABLE);
cancel_delayed_work_sync(&dp->rx_poll_work);
}
static void digicolor_uart_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
unsigned int baud, divisor;
u8 config = 0;
unsigned long flags;
termios->c_cflag &= ~CMSPAR;
termios->c_iflag &= ~(BRKINT | IGNBRK);
baud = uart_get_baud_rate(port, termios, old,
port->uartclk / (0x10000*16),
port->uartclk / 256);
divisor = uart_get_divisor(port, baud) - 1;
switch (termios->c_cflag & CSIZE) {
case CS7:
break;
case CS8:
default:
config |= UA_CONFIG_CHAR_LEN;
break;
}
if (termios->c_cflag & CSTOPB)
config |= UA_CONFIG_STOP_BITS;
if (termios->c_cflag & PARENB) {
config |= UA_CONFIG_PARITY;
if (termios->c_cflag & PARODD)
config |= UA_CONFIG_ODD_PARITY;
}
port->read_status_mask = UA_STATUS_OVERRUN_ERR;
if (termios->c_iflag & INPCK)
port->read_status_mask |= UA_STATUS_PARITY_ERR
| UA_STATUS_FRAME_ERR;
port->ignore_status_mask = 0;
if (!(termios->c_cflag & CREAD))
port->ignore_status_mask |= UA_STATUS_OVERRUN_ERR
| UA_STATUS_PARITY_ERR | UA_STATUS_FRAME_ERR;
spin_lock_irqsave(&port->lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
writeb_relaxed(config, port->membase + UA_CONFIG);
writeb_relaxed(divisor & 0xff, port->membase + UA_HBAUD_LO);
writeb_relaxed(divisor >> 8, port->membase + UA_HBAUD_HI);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *digicolor_uart_type(struct uart_port *port)
{
return (port->type == PORT_DIGICOLOR) ? "DIGICOLOR USART" : NULL;
}
static void digicolor_uart_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE)
port->type = PORT_DIGICOLOR;
}
static void digicolor_uart_release_port(struct uart_port *port)
{
}
static int digicolor_uart_request_port(struct uart_port *port)
{
return 0;
}
static void digicolor_uart_console_putchar(struct uart_port *port, int ch)
{
while (digicolor_uart_tx_full(port))
cpu_relax();
writeb_relaxed(ch, port->membase + UA_EMI_REC);
}
static void digicolor_uart_console_write(struct console *co, const char *c,
unsigned n)
{
struct uart_port *port = digicolor_ports[co->index];
u8 status;
unsigned long flags;
int locked = 1;
if (oops_in_progress)
locked = spin_trylock_irqsave(&port->lock, flags);
else
spin_lock_irqsave(&port->lock, flags);
uart_console_write(port, c, n, digicolor_uart_console_putchar);
if (locked)
spin_unlock_irqrestore(&port->lock, flags);
do {
status = readb_relaxed(port->membase + UA_STATUS);
} while ((status & UA_STATUS_TX_READY) == 0);
}
static int digicolor_uart_console_setup(struct console *co, char *options)
{
int baud = 115200, bits = 8, parity = 'n', flow = 'n';
struct uart_port *port;
if (co->index < 0 || co->index >= DIGICOLOR_USART_NR)
return -EINVAL;
port = digicolor_ports[co->index];
if (!port)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int digicolor_uart_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int irq, ret, index;
struct digicolor_port *dp;
struct resource *res;
struct clk *uart_clk;
if (!np) {
dev_err(&pdev->dev, "Missing device tree node\n");
return -ENXIO;
}
index = of_alias_get_id(np, "serial");
if (index < 0 || index >= DIGICOLOR_USART_NR)
return -EINVAL;
dp = devm_kzalloc(&pdev->dev, sizeof(*dp), GFP_KERNEL);
if (!dp)
return -ENOMEM;
uart_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(uart_clk))
return PTR_ERR(uart_clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dp->port.mapbase = res->start;
dp->port.membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dp->port.membase))
return PTR_ERR(dp->port.membase);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
dp->port.irq = irq;
dp->port.iotype = UPIO_MEM;
dp->port.uartclk = clk_get_rate(uart_clk);
dp->port.fifosize = 16;
dp->port.dev = &pdev->dev;
dp->port.ops = &digicolor_uart_ops;
dp->port.line = index;
dp->port.type = PORT_DIGICOLOR;
spin_lock_init(&dp->port.lock);
digicolor_ports[index] = &dp->port;
platform_set_drvdata(pdev, &dp->port);
INIT_DELAYED_WORK(&dp->rx_poll_work, digicolor_rx_poll);
ret = devm_request_irq(&pdev->dev, dp->port.irq, digicolor_uart_int, 0,
dev_name(&pdev->dev), &dp->port);
if (ret)
return ret;
return uart_add_one_port(&digicolor_uart, &dp->port);
}
static int digicolor_uart_remove(struct platform_device *pdev)
{
struct uart_port *port = platform_get_drvdata(pdev);
uart_remove_one_port(&digicolor_uart, port);
return 0;
}
static int __init digicolor_uart_init(void)
{
int ret;
if (IS_ENABLED(CONFIG_SERIAL_CONEXANT_DIGICOLOR_CONSOLE)) {
digicolor_uart.cons = &digicolor_console;
digicolor_console.data = &digicolor_uart;
}
ret = uart_register_driver(&digicolor_uart);
if (ret)
return ret;
return platform_driver_register(&digicolor_uart_platform);
}
static void __exit digicolor_uart_exit(void)
{
platform_driver_unregister(&digicolor_uart_platform);
uart_unregister_driver(&digicolor_uart);
}
