static void wait_for_xmit_empty(struct uart_port *port)
{
unsigned int timeout = 10000;
do {
if (LPC32XX_HSU_TX_LEV(readl(LPC32XX_HSUART_LEVEL(
port->membase))) == 0)
break;
if (--timeout == 0)
break;
udelay(1);
} while (1);
}
static void wait_for_xmit_ready(struct uart_port *port)
{
unsigned int timeout = 10000;
while (1) {
if (LPC32XX_HSU_TX_LEV(readl(LPC32XX_HSUART_LEVEL(
port->membase))) < 32)
break;
if (--timeout == 0)
break;
udelay(1);
}
}
static void lpc32xx_hsuart_console_putchar(struct uart_port *port, int ch)
{
wait_for_xmit_ready(port);
writel((u32)ch, LPC32XX_HSUART_FIFO(port->membase));
}
static void lpc32xx_hsuart_console_write(struct console *co, const char *s,
unsigned int count)
{
struct lpc32xx_hsuart_port *up = &lpc32xx_hs_ports[co->index];
unsigned long flags;
int locked = 1;
touch_nmi_watchdog();
local_irq_save(flags);
if (up->port.sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock(&up->port.lock);
else
spin_lock(&up->port.lock);
uart_console_write(&up->port, s, count, lpc32xx_hsuart_console_putchar);
wait_for_xmit_empty(&up->port);
if (locked)
spin_unlock(&up->port.lock);
local_irq_restore(flags);
}
static int __init lpc32xx_hsuart_console_setup(struct console *co,
char *options)
{
struct uart_port *port;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index >= MAX_PORTS)
co->index = 0;
port = &lpc32xx_hs_ports[co->index].port;
if (!port->membase)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init lpc32xx_hsuart_console_init(void)
{
register_console(&lpc32xx_hsuart_console);
return 0;
}
static unsigned int __serial_get_clock_div(unsigned long uartclk,
unsigned long rate)
{
u32 div, goodrate, hsu_rate, l_hsu_rate, comprate;
u32 rate_diff;
div = uartclk / rate;
goodrate = hsu_rate = (div / 14) - 1;
if (hsu_rate != 0)
hsu_rate--;
l_hsu_rate = hsu_rate + 3;
rate_diff = 0xFFFFFFFF;
while (hsu_rate < l_hsu_rate) {
comprate = uartclk / ((hsu_rate + 1) * 14);
if (abs(comprate - rate) < rate_diff) {
goodrate = hsu_rate;
rate_diff = abs(comprate - rate);
}
hsu_rate++;
}
if (hsu_rate > 0xFF)
hsu_rate = 0xFF;
return goodrate;
}
static void __serial_uart_flush(struct uart_port *port)
{
u32 tmp;
int cnt = 0;
while ((readl(LPC32XX_HSUART_LEVEL(port->membase)) > 0) &&
(cnt++ < FIFO_READ_LIMIT))
tmp = readl(LPC32XX_HSUART_FIFO(port->membase));
}
static void __serial_lpc32xx_rx(struct uart_port *port)
{
unsigned int tmp, flag;
struct tty_struct *tty = tty_port_tty_get(&port->state->port);
if (!tty) {
while (!(readl(LPC32XX_HSUART_FIFO(port->membase)) &
LPC32XX_HSU_RX_EMPTY))
;
return;
}
tmp = readl(LPC32XX_HSUART_FIFO(port->membase));
while (!(tmp & LPC32XX_HSU_RX_EMPTY)) {
flag = TTY_NORMAL;
port->icount.rx++;
if (tmp & LPC32XX_HSU_ERROR_DATA) {
writel(LPC32XX_HSU_FE_INT,
LPC32XX_HSUART_IIR(port->membase));
port->icount.frame++;
flag = TTY_FRAME;
tty_insert_flip_char(tty, 0, TTY_FRAME);
}
tty_insert_flip_char(tty, (tmp & 0xFF), flag);
tmp = readl(LPC32XX_HSUART_FIFO(port->membase));
}
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
static void __serial_lpc32xx_tx(struct uart_port *port)
{
struct circ_buf *xmit = &port->state->xmit;
unsigned int tmp;
if (port->x_char) {
writel((u32)port->x_char, LPC32XX_HSUART_FIFO(port->membase));
port->icount.tx++;
port->x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(port))
goto exit_tx;
while (LPC32XX_HSU_TX_LEV(readl(
LPC32XX_HSUART_LEVEL(port->membase))) < 64) {
writel((u32) xmit->buf[xmit->tail],
LPC32XX_HSUART_FIFO(port->membase));
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
port->icount.tx++;
if (uart_circ_empty(xmit))
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
exit_tx:
if (uart_circ_empty(xmit)) {
tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
tmp &= ~LPC32XX_HSU_TX_INT_EN;
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
}
}
static irqreturn_t serial_lpc32xx_interrupt(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
struct tty_struct *tty = tty_port_tty_get(&port->state->port);
u32 status;
spin_lock(&port->lock);
status = readl(LPC32XX_HSUART_IIR(port->membase));
if (status & LPC32XX_HSU_BRK_INT) {
writel(LPC32XX_HSU_BRK_INT, LPC32XX_HSUART_IIR(port->membase));
port->icount.brk++;
uart_handle_break(port);
}
if (status & LPC32XX_HSU_FE_INT)
writel(LPC32XX_HSU_FE_INT, LPC32XX_HSUART_IIR(port->membase));
if (status & LPC32XX_HSU_RX_OE_INT) {
writel(LPC32XX_HSU_RX_OE_INT,
LPC32XX_HSUART_IIR(port->membase));
port->icount.overrun++;
if (tty) {
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
tty_schedule_flip(tty);
}
}
if (status & (LPC32XX_HSU_RX_TIMEOUT_INT | LPC32XX_HSU_RX_TRIG_INT)) {
__serial_lpc32xx_rx(port);
if (tty)
tty_flip_buffer_push(tty);
}
if ((status & LPC32XX_HSU_TX_INT) && (!uart_tx_stopped(port))) {
writel(LPC32XX_HSU_TX_INT, LPC32XX_HSUART_IIR(port->membase));
__serial_lpc32xx_tx(port);
}
spin_unlock(&port->lock);
tty_kref_put(tty);
return IRQ_HANDLED;
}
static unsigned int serial_lpc32xx_tx_empty(struct uart_port *port)
{
unsigned int ret = 0;
if (LPC32XX_HSU_TX_LEV(readl(LPC32XX_HSUART_LEVEL(port->membase))) == 0)
ret = TIOCSER_TEMT;
return ret;
}
static void serial_lpc32xx_set_mctrl(struct uart_port *port,
unsigned int mctrl)
{
}
static unsigned int serial_lpc32xx_get_mctrl(struct uart_port *port)
{
return TIOCM_CAR | TIOCM_DSR | TIOCM_CTS;
}
static void serial_lpc32xx_stop_tx(struct uart_port *port)
{
u32 tmp;
tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
tmp &= ~LPC32XX_HSU_TX_INT_EN;
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
}
static void serial_lpc32xx_start_tx(struct uart_port *port)
{
u32 tmp;
__serial_lpc32xx_tx(port);
tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
tmp |= LPC32XX_HSU_TX_INT_EN;
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
}
static void serial_lpc32xx_stop_rx(struct uart_port *port)
{
u32 tmp;
tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
tmp &= ~(LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN);
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
writel((LPC32XX_HSU_BRK_INT | LPC32XX_HSU_RX_OE_INT |
LPC32XX_HSU_FE_INT), LPC32XX_HSUART_IIR(port->membase));
}
static void serial_lpc32xx_enable_ms(struct uart_port *port)
{
}
static void serial_lpc32xx_break_ctl(struct uart_port *port,
int break_state)
{
unsigned long flags;
u32 tmp;
spin_lock_irqsave(&port->lock, flags);
tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
if (break_state != 0)
tmp |= LPC32XX_HSU_BREAK;
else
tmp &= ~LPC32XX_HSU_BREAK;
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
spin_unlock_irqrestore(&port->lock, flags);
}
static void lpc32xx_loopback_set(resource_size_t mapbase, int state)
{
int bit;
u32 tmp;
switch (mapbase) {
case LPC32XX_HS_UART1_BASE:
bit = 0;
break;
case LPC32XX_HS_UART2_BASE:
bit = 1;
break;
case LPC32XX_HS_UART7_BASE:
bit = 6;
break;
default:
WARN(1, "lpc32xx_hs: Warning: Unknown port at %08x\n", mapbase);
return;
}
tmp = readl(LPC32XX_UARTCTL_CLOOP);
if (state)
tmp |= (1 << bit);
else
tmp &= ~(1 << bit);
writel(tmp, LPC32XX_UARTCTL_CLOOP);
}
static int serial_lpc32xx_startup(struct uart_port *port)
{
int retval;
unsigned long flags;
u32 tmp;
spin_lock_irqsave(&port->lock, flags);
__serial_uart_flush(port);
writel((LPC32XX_HSU_TX_INT | LPC32XX_HSU_FE_INT |
LPC32XX_HSU_BRK_INT | LPC32XX_HSU_RX_OE_INT),
LPC32XX_HSUART_IIR(port->membase));
writel(0xFF, LPC32XX_HSUART_RATE(port->membase));
tmp = LPC32XX_HSU_TX_TL8B | LPC32XX_HSU_RX_TL32B |
LPC32XX_HSU_OFFSET(20) | LPC32XX_HSU_TMO_INACT_4B;
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
lpc32xx_loopback_set(port->mapbase, 0);
spin_unlock_irqrestore(&port->lock, flags);
retval = request_irq(port->irq, serial_lpc32xx_interrupt,
0, MODNAME, port);
if (!retval)
writel((tmp | LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN),
LPC32XX_HSUART_CTRL(port->membase));
return retval;
}
static void serial_lpc32xx_shutdown(struct uart_port *port)
{
u32 tmp;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
tmp = LPC32XX_HSU_TX_TL8B | LPC32XX_HSU_RX_TL32B |
LPC32XX_HSU_OFFSET(20) | LPC32XX_HSU_TMO_INACT_4B;
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
lpc32xx_loopback_set(port->mapbase, 1);
spin_unlock_irqrestore(&port->lock, flags);
free_irq(port->irq, port);
}
static void serial_lpc32xx_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
unsigned long flags;
unsigned int baud, quot;
u32 tmp;
termios->c_cflag &= ~(CSIZE | CSTOPB | PARENB | PARODD);
termios->c_cflag |= CS8;
termios->c_cflag &= ~(HUPCL | CMSPAR | CLOCAL | CRTSCTS);
baud = uart_get_baud_rate(port, termios, old, 0,
port->uartclk / 14);
quot = __serial_get_clock_div(port->uartclk, baud);
spin_lock_irqsave(&port->lock, flags);
tmp = readl(LPC32XX_HSUART_CTRL(port->membase));
if ((termios->c_cflag & CREAD) == 0)
tmp &= ~(LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN);
else
tmp |= LPC32XX_HSU_RX_INT_EN | LPC32XX_HSU_ERR_INT_EN;
writel(tmp, LPC32XX_HSUART_CTRL(port->membase));
writel(quot, LPC32XX_HSUART_RATE(port->membase));
uart_update_timeout(port, termios->c_cflag, baud);
spin_unlock_irqrestore(&port->lock, flags);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
}
static const char *serial_lpc32xx_type(struct uart_port *port)
{
return MODNAME;
}
static void serial_lpc32xx_release_port(struct uart_port *port)
{
if ((port->iotype == UPIO_MEM32) && (port->mapbase)) {
if (port->flags & UPF_IOREMAP) {
iounmap(port->membase);
port->membase = NULL;
}
release_mem_region(port->mapbase, SZ_4K);
}
}
static int serial_lpc32xx_request_port(struct uart_port *port)
{
int ret = -ENODEV;
if ((port->iotype == UPIO_MEM32) && (port->mapbase)) {
ret = 0;
if (!request_mem_region(port->mapbase, SZ_4K, MODNAME))
ret = -EBUSY;
else if (port->flags & UPF_IOREMAP) {
port->membase = ioremap(port->mapbase, SZ_4K);
if (!port->membase) {
release_mem_region(port->mapbase, SZ_4K);
ret = -ENOMEM;
}
}
}
return ret;
}
static void serial_lpc32xx_config_port(struct uart_port *port, int uflags)
{
int ret;
ret = serial_lpc32xx_request_port(port);
if (ret < 0)
return;
port->type = PORT_UART00;
port->fifosize = 64;
__serial_uart_flush(port);
writel((LPC32XX_HSU_TX_INT | LPC32XX_HSU_FE_INT |
LPC32XX_HSU_BRK_INT | LPC32XX_HSU_RX_OE_INT),
LPC32XX_HSUART_IIR(port->membase));
writel(0xFF, LPC32XX_HSUART_RATE(port->membase));
writel(LPC32XX_HSU_TX_TL8B | LPC32XX_HSU_RX_TL32B |
LPC32XX_HSU_OFFSET(20) | LPC32XX_HSU_TMO_INACT_4B,
LPC32XX_HSUART_CTRL(port->membase));
}
static int serial_lpc32xx_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
int ret = 0;
if (ser->type != PORT_UART00)
ret = -EINVAL;
return ret;
}
static int serial_hs_lpc32xx_probe(struct platform_device *pdev)
{
struct lpc32xx_hsuart_port *p = &lpc32xx_hs_ports[uarts_registered];
int ret = 0;
struct resource *res;
if (uarts_registered >= MAX_PORTS) {
dev_err(&pdev->dev,
"Error: Number of possible ports exceeded (%d)!\n",
uarts_registered + 1);
return -ENXIO;
}
memset(p, 0, sizeof(*p));
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev,
"Error getting mem resource for HS UART port %d\n",
uarts_registered);
return -ENXIO;
}
p->port.mapbase = res->start;
p->port.membase = NULL;
p->port.irq = platform_get_irq(pdev, 0);
if (p->port.irq < 0) {
dev_err(&pdev->dev, "Error getting irq for HS UART port %d\n",
uarts_registered);
return p->port.irq;
}
p->port.iotype = UPIO_MEM32;
p->port.uartclk = LPC32XX_MAIN_OSC_FREQ;
p->port.regshift = 2;
p->port.flags = UPF_BOOT_AUTOCONF | UPF_FIXED_PORT | UPF_IOREMAP;
p->port.dev = &pdev->dev;
p->port.ops = &serial_lpc32xx_pops;
p->port.line = uarts_registered++;
spin_lock_init(&p->port.lock);
lpc32xx_loopback_set(p->port.mapbase, 1);
ret = uart_add_one_port(&lpc32xx_hs_reg, &p->port);
platform_set_drvdata(pdev, p);
return ret;
}
static int serial_hs_lpc32xx_remove(struct platform_device *pdev)
{
struct lpc32xx_hsuart_port *p = platform_get_drvdata(pdev);
uart_remove_one_port(&lpc32xx_hs_reg, &p->port);
return 0;
}
static int serial_hs_lpc32xx_suspend(struct platform_device *pdev,
pm_message_t state)
{
struct lpc32xx_hsuart_port *p = platform_get_drvdata(pdev);
uart_suspend_port(&lpc32xx_hs_reg, &p->port);
return 0;
}
static int serial_hs_lpc32xx_resume(struct platform_device *pdev)
{
struct lpc32xx_hsuart_port *p = platform_get_drvdata(pdev);
uart_resume_port(&lpc32xx_hs_reg, &p->port);
return 0;
}
static int __init lpc32xx_hsuart_init(void)
{
int ret;
ret = uart_register_driver(&lpc32xx_hs_reg);
if (ret)
return ret;
ret = platform_driver_register(&serial_hs_lpc32xx_driver);
if (ret)
uart_unregister_driver(&lpc32xx_hs_reg);
return ret;
}
static void __exit lpc32xx_hsuart_exit(void)
{
platform_driver_unregister(&serial_hs_lpc32xx_driver);
uart_unregister_driver(&lpc32xx_hs_reg);
}
