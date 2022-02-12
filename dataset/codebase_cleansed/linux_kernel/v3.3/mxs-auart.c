static inline void mxs_auart_tx_chars(struct mxs_auart_port *s)
{
struct circ_buf *xmit = &s->port.state->xmit;
while (!(readl(s->port.membase + AUART_STAT) &
AUART_STAT_TXFF)) {
if (s->port.x_char) {
s->port.icount.tx++;
writel(s->port.x_char,
s->port.membase + AUART_DATA);
s->port.x_char = 0;
continue;
}
if (!uart_circ_empty(xmit) && !uart_tx_stopped(&s->port)) {
s->port.icount.tx++;
writel(xmit->buf[xmit->tail],
s->port.membase + AUART_DATA);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
} else
break;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&s->port);
if (uart_circ_empty(&(s->port.state->xmit)))
writel(AUART_INTR_TXIEN,
s->port.membase + AUART_INTR_CLR);
else
writel(AUART_INTR_TXIEN,
s->port.membase + AUART_INTR_SET);
if (uart_tx_stopped(&s->port))
mxs_auart_stop_tx(&s->port);
}
static void mxs_auart_rx_char(struct mxs_auart_port *s)
{
int flag;
u32 stat;
u8 c;
c = readl(s->port.membase + AUART_DATA);
stat = readl(s->port.membase + AUART_STAT);
flag = TTY_NORMAL;
s->port.icount.rx++;
if (stat & AUART_STAT_BERR) {
s->port.icount.brk++;
if (uart_handle_break(&s->port))
goto out;
} else if (stat & AUART_STAT_PERR) {
s->port.icount.parity++;
} else if (stat & AUART_STAT_FERR) {
s->port.icount.frame++;
}
stat &= s->port.read_status_mask;
if (stat & AUART_STAT_BERR) {
flag = TTY_BREAK;
} else if (stat & AUART_STAT_PERR)
flag = TTY_PARITY;
else if (stat & AUART_STAT_FERR)
flag = TTY_FRAME;
if (stat & AUART_STAT_OERR)
s->port.icount.overrun++;
if (uart_handle_sysrq_char(&s->port, c))
goto out;
uart_insert_char(&s->port, stat, AUART_STAT_OERR, c, flag);
out:
writel(stat, s->port.membase + AUART_STAT);
}
static void mxs_auart_rx_chars(struct mxs_auart_port *s)
{
struct tty_struct *tty = s->port.state->port.tty;
u32 stat = 0;
for (;;) {
stat = readl(s->port.membase + AUART_STAT);
if (stat & AUART_STAT_RXFE)
break;
mxs_auart_rx_char(s);
}
writel(stat, s->port.membase + AUART_STAT);
tty_flip_buffer_push(tty);
}
static int mxs_auart_request_port(struct uart_port *u)
{
return 0;
}
static int mxs_auart_verify_port(struct uart_port *u,
struct serial_struct *ser)
{
if (u->type != PORT_UNKNOWN && u->type != PORT_IMX)
return -EINVAL;
return 0;
}
static void mxs_auart_config_port(struct uart_port *u, int flags)
{
}
static const char *mxs_auart_type(struct uart_port *u)
{
struct mxs_auart_port *s = to_auart_port(u);
return dev_name(s->dev);
}
static void mxs_auart_release_port(struct uart_port *u)
{
}
static void mxs_auart_set_mctrl(struct uart_port *u, unsigned mctrl)
{
struct mxs_auart_port *s = to_auart_port(u);
u32 ctrl = readl(u->membase + AUART_CTRL2);
ctrl &= ~AUART_CTRL2_RTS;
if (mctrl & TIOCM_RTS)
ctrl |= AUART_CTRL2_RTS;
s->ctrl = mctrl;
writel(ctrl, u->membase + AUART_CTRL2);
}
static u32 mxs_auart_get_mctrl(struct uart_port *u)
{
struct mxs_auart_port *s = to_auart_port(u);
u32 stat = readl(u->membase + AUART_STAT);
int ctrl2 = readl(u->membase + AUART_CTRL2);
u32 mctrl = s->ctrl;
mctrl &= ~TIOCM_CTS;
if (stat & AUART_STAT_CTS)
mctrl |= TIOCM_CTS;
if (ctrl2 & AUART_CTRL2_RTS)
mctrl |= TIOCM_RTS;
return mctrl;
}
static void mxs_auart_settermios(struct uart_port *u,
struct ktermios *termios,
struct ktermios *old)
{
u32 bm, ctrl, ctrl2, div;
unsigned int cflag, baud;
cflag = termios->c_cflag;
ctrl = AUART_LINECTRL_FEN;
ctrl2 = readl(u->membase + AUART_CTRL2);
switch (cflag & CSIZE) {
case CS5:
bm = 0;
break;
case CS6:
bm = 1;
break;
case CS7:
bm = 2;
break;
case CS8:
bm = 3;
break;
default:
return;
}
ctrl |= AUART_LINECTRL_WLEN(bm);
if (cflag & PARENB) {
ctrl |= AUART_LINECTRL_PEN;
if ((cflag & PARODD) == 0)
ctrl |= AUART_LINECTRL_EPS;
}
u->read_status_mask = 0;
if (termios->c_iflag & INPCK)
u->read_status_mask |= AUART_STAT_PERR;
if (termios->c_iflag & (BRKINT | PARMRK))
u->read_status_mask |= AUART_STAT_BERR;
u->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
u->ignore_status_mask |= AUART_STAT_PERR;
if (termios->c_iflag & IGNBRK) {
u->ignore_status_mask |= AUART_STAT_BERR;
if (termios->c_iflag & IGNPAR)
u->ignore_status_mask |= AUART_STAT_OERR;
}
if (cflag & CREAD)
ctrl2 |= AUART_CTRL2_RXE;
else
ctrl2 &= ~AUART_CTRL2_RXE;
if (cflag & CSTOPB)
ctrl |= AUART_LINECTRL_STP2;
if (cflag & CRTSCTS)
ctrl2 |= AUART_CTRL2_CTSEN;
else
ctrl2 &= ~AUART_CTRL2_CTSEN;
baud = uart_get_baud_rate(u, termios, old, 0, u->uartclk);
div = u->uartclk * 32 / baud;
ctrl |= AUART_LINECTRL_BAUD_DIVFRAC(div & 0x3F);
ctrl |= AUART_LINECTRL_BAUD_DIVINT(div >> 6);
writel(ctrl, u->membase + AUART_LINECTRL);
writel(ctrl2, u->membase + AUART_CTRL2);
}
static irqreturn_t mxs_auart_irq_handle(int irq, void *context)
{
u32 istatus, istat;
struct mxs_auart_port *s = context;
u32 stat = readl(s->port.membase + AUART_STAT);
istatus = istat = readl(s->port.membase + AUART_INTR);
if (istat & AUART_INTR_CTSMIS) {
uart_handle_cts_change(&s->port, stat & AUART_STAT_CTS);
writel(AUART_INTR_CTSMIS,
s->port.membase + AUART_INTR_CLR);
istat &= ~AUART_INTR_CTSMIS;
}
if (istat & (AUART_INTR_RTIS | AUART_INTR_RXIS)) {
mxs_auart_rx_chars(s);
istat &= ~(AUART_INTR_RTIS | AUART_INTR_RXIS);
}
if (istat & AUART_INTR_TXIS) {
mxs_auart_tx_chars(s);
istat &= ~AUART_INTR_TXIS;
}
writel(istatus & (AUART_INTR_RTIS
| AUART_INTR_TXIS
| AUART_INTR_RXIS
| AUART_INTR_CTSMIS),
s->port.membase + AUART_INTR_CLR);
return IRQ_HANDLED;
}
static void mxs_auart_reset(struct uart_port *u)
{
int i;
unsigned int reg;
writel(AUART_CTRL0_SFTRST, u->membase + AUART_CTRL0_CLR);
for (i = 0; i < 10000; i++) {
reg = readl(u->membase + AUART_CTRL0);
if (!(reg & AUART_CTRL0_SFTRST))
break;
udelay(3);
}
writel(AUART_CTRL0_CLKGATE, u->membase + AUART_CTRL0_CLR);
}
static int mxs_auart_startup(struct uart_port *u)
{
struct mxs_auart_port *s = to_auart_port(u);
clk_prepare_enable(s->clk);
writel(AUART_CTRL0_CLKGATE, u->membase + AUART_CTRL0_CLR);
writel(AUART_CTRL2_UARTEN, u->membase + AUART_CTRL2_SET);
writel(AUART_INTR_RXIEN | AUART_INTR_RTIEN | AUART_INTR_CTSMIEN,
u->membase + AUART_INTR);
writel(AUART_LINECTRL_FEN, u->membase + AUART_LINECTRL_SET);
return 0;
}
static void mxs_auart_shutdown(struct uart_port *u)
{
struct mxs_auart_port *s = to_auart_port(u);
writel(AUART_CTRL2_UARTEN, u->membase + AUART_CTRL2_CLR);
writel(AUART_CTRL0_CLKGATE, u->membase + AUART_CTRL0_SET);
writel(AUART_INTR_RXIEN | AUART_INTR_RTIEN | AUART_INTR_CTSMIEN,
u->membase + AUART_INTR_CLR);
clk_disable_unprepare(s->clk);
}
static unsigned int mxs_auart_tx_empty(struct uart_port *u)
{
if (readl(u->membase + AUART_STAT) & AUART_STAT_TXFE)
return TIOCSER_TEMT;
else
return 0;
}
static void mxs_auart_start_tx(struct uart_port *u)
{
struct mxs_auart_port *s = to_auart_port(u);
writel(AUART_CTRL2_TXE, u->membase + AUART_CTRL2_SET);
mxs_auart_tx_chars(s);
}
static void mxs_auart_stop_tx(struct uart_port *u)
{
writel(AUART_CTRL2_TXE, u->membase + AUART_CTRL2_CLR);
}
static void mxs_auart_stop_rx(struct uart_port *u)
{
writel(AUART_CTRL2_RXE, u->membase + AUART_CTRL2_CLR);
}
static void mxs_auart_break_ctl(struct uart_port *u, int ctl)
{
if (ctl)
writel(AUART_LINECTRL_BRK,
u->membase + AUART_LINECTRL_SET);
else
writel(AUART_LINECTRL_BRK,
u->membase + AUART_LINECTRL_CLR);
}
static void mxs_auart_enable_ms(struct uart_port *port)
{
}
static void mxs_auart_console_putchar(struct uart_port *port, int ch)
{
unsigned int to = 1000;
while (readl(port->membase + AUART_STAT) & AUART_STAT_TXFF) {
if (!to--)
break;
udelay(1);
}
writel(ch, port->membase + AUART_DATA);
}
static void
auart_console_write(struct console *co, const char *str, unsigned int count)
{
struct mxs_auart_port *s;
struct uart_port *port;
unsigned int old_ctrl0, old_ctrl2;
unsigned int to = 1000;
if (co->index > MXS_AUART_PORTS || co->index < 0)
return;
s = auart_port[co->index];
port = &s->port;
clk_enable(s->clk);
old_ctrl2 = readl(port->membase + AUART_CTRL2);
old_ctrl0 = readl(port->membase + AUART_CTRL0);
writel(AUART_CTRL0_CLKGATE,
port->membase + AUART_CTRL0_CLR);
writel(AUART_CTRL2_UARTEN | AUART_CTRL2_TXE,
port->membase + AUART_CTRL2_SET);
uart_console_write(port, str, count, mxs_auart_console_putchar);
while (readl(port->membase + AUART_STAT) & AUART_STAT_BUSY) {
if (!to--)
break;
udelay(1);
}
writel(old_ctrl0, port->membase + AUART_CTRL0);
writel(old_ctrl2, port->membase + AUART_CTRL2);
clk_disable(s->clk);
}
static void __init
auart_console_get_options(struct uart_port *port, int *baud,
int *parity, int *bits)
{
unsigned int lcr_h, quot;
if (!(readl(port->membase + AUART_CTRL2) & AUART_CTRL2_UARTEN))
return;
lcr_h = readl(port->membase + AUART_LINECTRL);
*parity = 'n';
if (lcr_h & AUART_LINECTRL_PEN) {
if (lcr_h & AUART_LINECTRL_EPS)
*parity = 'e';
else
*parity = 'o';
}
if ((lcr_h & AUART_LINECTRL_WLEN_MASK) == AUART_LINECTRL_WLEN(2))
*bits = 7;
else
*bits = 8;
quot = ((readl(port->membase + AUART_LINECTRL)
& AUART_LINECTRL_BAUD_DIVINT_MASK))
>> (AUART_LINECTRL_BAUD_DIVINT_SHIFT - 6);
quot |= ((readl(port->membase + AUART_LINECTRL)
& AUART_LINECTRL_BAUD_DIVFRAC_MASK))
>> AUART_LINECTRL_BAUD_DIVFRAC_SHIFT;
if (quot == 0)
quot = 1;
*baud = (port->uartclk << 2) / quot;
}
static int __init
auart_console_setup(struct console *co, char *options)
{
struct mxs_auart_port *s;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
int ret;
if (co->index == -1 || co->index >= ARRAY_SIZE(auart_port))
co->index = 0;
s = auart_port[co->index];
if (!s)
return -ENODEV;
clk_prepare_enable(s->clk);
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
auart_console_get_options(&s->port, &baud, &parity, &bits);
ret = uart_set_options(&s->port, co, baud, parity, bits, flow);
clk_disable_unprepare(s->clk);
return ret;
}
static int __devinit mxs_auart_probe(struct platform_device *pdev)
{
struct mxs_auart_port *s;
u32 version;
int ret = 0;
struct resource *r;
s = kzalloc(sizeof(struct mxs_auart_port), GFP_KERNEL);
if (!s) {
ret = -ENOMEM;
goto out;
}
s->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(s->clk)) {
ret = PTR_ERR(s->clk);
goto out_free;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
ret = -ENXIO;
goto out_free_clk;
}
s->port.mapbase = r->start;
s->port.membase = ioremap(r->start, resource_size(r));
s->port.ops = &mxs_auart_ops;
s->port.iotype = UPIO_MEM;
s->port.line = pdev->id < 0 ? 0 : pdev->id;
s->port.fifosize = 16;
s->port.uartclk = clk_get_rate(s->clk);
s->port.type = PORT_IMX;
s->port.dev = s->dev = get_device(&pdev->dev);
s->flags = 0;
s->ctrl = 0;
s->irq = platform_get_irq(pdev, 0);
s->port.irq = s->irq;
ret = request_irq(s->irq, mxs_auart_irq_handle, 0, dev_name(&pdev->dev), s);
if (ret)
goto out_free_clk;
platform_set_drvdata(pdev, s);
auart_port[pdev->id] = s;
mxs_auart_reset(&s->port);
ret = uart_add_one_port(&auart_driver, &s->port);
if (ret)
goto out_free_irq;
version = readl(s->port.membase + AUART_VERSION);
dev_info(&pdev->dev, "Found APPUART %d.%d.%d\n",
(version >> 24) & 0xff,
(version >> 16) & 0xff, version & 0xffff);
return 0;
out_free_irq:
auart_port[pdev->id] = NULL;
free_irq(s->irq, s);
out_free_clk:
clk_put(s->clk);
out_free:
kfree(s);
out:
return ret;
}
static int __devexit mxs_auart_remove(struct platform_device *pdev)
{
struct mxs_auart_port *s = platform_get_drvdata(pdev);
uart_remove_one_port(&auart_driver, &s->port);
auart_port[pdev->id] = NULL;
clk_put(s->clk);
free_irq(s->irq, s);
kfree(s);
return 0;
}
static int __init mxs_auart_init(void)
{
int r;
r = uart_register_driver(&auart_driver);
if (r)
goto out;
r = platform_driver_register(&mxs_auart_driver);
if (r)
goto out_err;
return 0;
out_err:
uart_unregister_driver(&auart_driver);
out:
return r;
}
static void __exit mxs_auart_exit(void)
{
platform_driver_unregister(&mxs_auart_driver);
uart_unregister_driver(&auart_driver);
}
