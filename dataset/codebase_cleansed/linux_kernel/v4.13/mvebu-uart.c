static unsigned int mvebu_uart_tx_empty(struct uart_port *port)
{
unsigned long flags;
unsigned int st;
spin_lock_irqsave(&port->lock, flags);
st = readl(port->membase + UART_STAT);
spin_unlock_irqrestore(&port->lock, flags);
return (st & STAT_TX_FIFO_EMP) ? TIOCSER_TEMT : 0;
}
static unsigned int mvebu_uart_get_mctrl(struct uart_port *port)
{
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}
static void mvebu_uart_set_mctrl(struct uart_port *port,
unsigned int mctrl)
{
}
static void mvebu_uart_stop_tx(struct uart_port *port)
{
unsigned int ctl = readl(port->membase + UART_CTRL);
ctl &= ~CTRL_TX_RDY_INT;
writel(ctl, port->membase + UART_CTRL);
}
static void mvebu_uart_start_tx(struct uart_port *port)
{
unsigned int ctl = readl(port->membase + UART_CTRL);
ctl |= CTRL_TX_RDY_INT;
writel(ctl, port->membase + UART_CTRL);
}
static void mvebu_uart_stop_rx(struct uart_port *port)
{
unsigned int ctl = readl(port->membase + UART_CTRL);
ctl &= ~CTRL_RX_INT;
writel(ctl, port->membase + UART_CTRL);
}
static void mvebu_uart_break_ctl(struct uart_port *port, int brk)
{
unsigned int ctl;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
ctl = readl(port->membase + UART_CTRL);
if (brk == -1)
ctl |= CTRL_SND_BRK_SEQ;
else
ctl &= ~CTRL_SND_BRK_SEQ;
writel(ctl, port->membase + UART_CTRL);
spin_unlock_irqrestore(&port->lock, flags);
}
static void mvebu_uart_rx_chars(struct uart_port *port, unsigned int status)
{
struct tty_port *tport = &port->state->port;
unsigned char ch = 0;
char flag = 0;
do {
if (status & STAT_RX_RDY) {
ch = readl(port->membase + UART_RBR);
ch &= 0xff;
flag = TTY_NORMAL;
port->icount.rx++;
if (status & STAT_PAR_ERR)
port->icount.parity++;
}
if (status & STAT_BRK_DET) {
port->icount.brk++;
status &= ~(STAT_FRM_ERR | STAT_PAR_ERR);
if (uart_handle_break(port))
goto ignore_char;
}
if (status & STAT_OVR_ERR)
port->icount.overrun++;
if (status & STAT_FRM_ERR)
port->icount.frame++;
if (uart_handle_sysrq_char(port, ch))
goto ignore_char;
if (status & port->ignore_status_mask & STAT_PAR_ERR)
status &= ~STAT_RX_RDY;
status &= port->read_status_mask;
if (status & STAT_PAR_ERR)
flag = TTY_PARITY;
status &= ~port->ignore_status_mask;
if (status & STAT_RX_RDY)
tty_insert_flip_char(tport, ch, flag);
if (status & STAT_BRK_DET)
tty_insert_flip_char(tport, 0, TTY_BREAK);
if (status & STAT_FRM_ERR)
tty_insert_flip_char(tport, 0, TTY_FRAME);
if (status & STAT_OVR_ERR)
tty_insert_flip_char(tport, 0, TTY_OVERRUN);
ignore_char:
status = readl(port->membase + UART_STAT);
} while (status & (STAT_RX_RDY | STAT_BRK_DET));
tty_flip_buffer_push(tport);
}
static void mvebu_uart_tx_chars(struct uart_port *port, unsigned int status)
{
struct circ_buf *xmit = &port->state->xmit;
unsigned int count;
unsigned int st;
if (port->x_char) {
writel(port->x_char, port->membase + UART_TSH);
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port)) {
mvebu_uart_stop_tx(port);
return;
}
for (count = 0; count < port->fifosize; count++) {
writel(xmit->buf[xmit->tail], port->membase + UART_TSH);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
st = readl(port->membase + UART_STAT);
if (st & STAT_TX_FIFO_FUL)
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
if (uart_circ_empty(xmit))
mvebu_uart_stop_tx(port);
}
static irqreturn_t mvebu_uart_isr(int irq, void *dev_id)
{
struct uart_port *port = (struct uart_port *)dev_id;
unsigned int st = readl(port->membase + UART_STAT);
if (st & (STAT_RX_RDY | STAT_OVR_ERR | STAT_FRM_ERR | STAT_BRK_DET))
mvebu_uart_rx_chars(port, st);
if (st & STAT_TX_RDY)
mvebu_uart_tx_chars(port, st);
return IRQ_HANDLED;
}
static int mvebu_uart_startup(struct uart_port *port)
{
int ret;
writel(CTRL_TXFIFO_RST | CTRL_RXFIFO_RST,
port->membase + UART_CTRL);
udelay(1);
writel(CTRL_RX_INT, port->membase + UART_CTRL);
ret = request_irq(port->irq, mvebu_uart_isr, port->irqflags, "serial",
port);
if (ret) {
dev_err(port->dev, "failed to request irq\n");
return ret;
}
return 0;
}
static void mvebu_uart_shutdown(struct uart_port *port)
{
writel(0, port->membase + UART_CTRL);
free_irq(port->irq, port);
}
static void mvebu_uart_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
unsigned long flags;
unsigned int baud;
spin_lock_irqsave(&port->lock, flags);
port->read_status_mask = STAT_RX_RDY | STAT_OVR_ERR |
STAT_TX_RDY | STAT_TX_FIFO_FUL;
if (termios->c_iflag & INPCK)
port->read_status_mask |= STAT_FRM_ERR | STAT_PAR_ERR;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |=
STAT_FRM_ERR | STAT_PAR_ERR | STAT_OVR_ERR;
if ((termios->c_cflag & CREAD) == 0)
port->ignore_status_mask |= STAT_RX_RDY | STAT_BRK_ERR;
if (old)
tty_termios_copy_hw(termios, old);
baud = uart_get_baud_rate(port, termios, old, 0, 460800);
uart_update_timeout(port, termios->c_cflag, baud);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *mvebu_uart_type(struct uart_port *port)
{
return MVEBU_UART_TYPE;
}
static void mvebu_uart_release_port(struct uart_port *port)
{
}
static int mvebu_uart_request_port(struct uart_port *port)
{
return 0;
}
static int mvebu_uart_get_poll_char(struct uart_port *port)
{
unsigned int st = readl(port->membase + UART_STAT);
if (!(st & STAT_RX_RDY))
return NO_POLL_CHAR;
return readl(port->membase + UART_RBR);
}
static void mvebu_uart_put_poll_char(struct uart_port *port, unsigned char c)
{
unsigned int st;
for (;;) {
st = readl(port->membase + UART_STAT);
if (!(st & STAT_TX_FIFO_FUL))
break;
udelay(1);
}
writel(c, port->membase + UART_TSH);
}
static void mvebu_uart_putc(struct uart_port *port, int c)
{
unsigned int st;
for (;;) {
st = readl(port->membase + UART_STAT);
if (!(st & STAT_TX_FIFO_FUL))
break;
}
writel(c, port->membase + UART_TSH);
for (;;) {
st = readl(port->membase + UART_STAT);
if (st & STAT_TX_FIFO_EMP)
break;
}
}
static void mvebu_uart_putc_early_write(struct console *con,
const char *s,
unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, mvebu_uart_putc);
}
static int __init
mvebu_uart_early_console_setup(struct earlycon_device *device,
const char *opt)
{
if (!device->port.membase)
return -ENODEV;
device->con->write = mvebu_uart_putc_early_write;
return 0;
}
static void wait_for_xmitr(struct uart_port *port)
{
u32 val;
readl_poll_timeout_atomic(port->membase + UART_STAT, val,
(val & STAT_TX_EMP), 1, 10000);
}
static void mvebu_uart_console_putchar(struct uart_port *port, int ch)
{
wait_for_xmitr(port);
writel(ch, port->membase + UART_TSH);
}
static void mvebu_uart_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_port *port = &mvebu_uart_ports[co->index];
unsigned long flags;
unsigned int ier;
int locked = 1;
if (oops_in_progress)
locked = spin_trylock_irqsave(&port->lock, flags);
else
spin_lock_irqsave(&port->lock, flags);
ier = readl(port->membase + UART_CTRL) &
(CTRL_RX_INT | CTRL_TX_RDY_INT);
writel(0, port->membase + UART_CTRL);
uart_console_write(port, s, count, mvebu_uart_console_putchar);
wait_for_xmitr(port);
if (ier)
writel(ier, port->membase + UART_CTRL);
if (locked)
spin_unlock_irqrestore(&port->lock, flags);
}
static int mvebu_uart_console_setup(struct console *co, char *options)
{
struct uart_port *port;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= MVEBU_NR_UARTS)
return -EINVAL;
port = &mvebu_uart_ports[co->index];
if (!port->mapbase || !port->membase) {
pr_debug("console on ttyMV%i not present\n", co->index);
return -ENODEV;
}
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init mvebu_uart_console_init(void)
{
register_console(&mvebu_uart_console);
return 0;
}
static int mvebu_uart_probe(struct platform_device *pdev)
{
struct resource *reg = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
struct uart_port *port;
struct mvebu_uart_data *data;
int ret;
if (!reg || !irq) {
dev_err(&pdev->dev, "no registers/irq defined\n");
return -EINVAL;
}
port = &mvebu_uart_ports[0];
spin_lock_init(&port->lock);
port->dev = &pdev->dev;
port->type = PORT_MVEBU;
port->ops = &mvebu_uart_ops;
port->regshift = 0;
port->fifosize = 32;
port->iotype = UPIO_MEM32;
port->flags = UPF_FIXED_PORT;
port->line = 0;
port->irq = irq->start;
port->irqflags = 0;
port->mapbase = reg->start;
port->membase = devm_ioremap_resource(&pdev->dev, reg);
if (IS_ERR(port->membase))
return -PTR_ERR(port->membase);
data = devm_kzalloc(&pdev->dev, sizeof(struct mvebu_uart_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->port = port;
port->private_data = data;
platform_set_drvdata(pdev, data);
ret = uart_add_one_port(&mvebu_uart_driver, port);
if (ret)
return ret;
return 0;
}
static int __init mvebu_uart_init(void)
{
int ret;
ret = uart_register_driver(&mvebu_uart_driver);
if (ret)
return ret;
ret = platform_driver_register(&mvebu_uart_platform_driver);
if (ret)
uart_unregister_driver(&mvebu_uart_driver);
return ret;
}
