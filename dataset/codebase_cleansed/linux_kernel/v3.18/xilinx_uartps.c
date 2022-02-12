static irqreturn_t cdns_uart_isr(int irq, void *dev_id)
{
struct uart_port *port = (struct uart_port *)dev_id;
unsigned long flags;
unsigned int isrstatus, numbytes;
unsigned int data;
char status = TTY_NORMAL;
spin_lock_irqsave(&port->lock, flags);
isrstatus = cdns_uart_readl(CDNS_UART_ISR_OFFSET);
if (isrstatus & CDNS_UART_IXR_FRAMING) {
while (!(cdns_uart_readl(CDNS_UART_SR_OFFSET) &
CDNS_UART_SR_RXEMPTY)) {
if (!cdns_uart_readl(CDNS_UART_FIFO_OFFSET)) {
port->read_status_mask |= CDNS_UART_IXR_BRK;
isrstatus &= ~CDNS_UART_IXR_FRAMING;
}
}
cdns_uart_writel(CDNS_UART_IXR_FRAMING, CDNS_UART_ISR_OFFSET);
}
if (isrstatus & port->ignore_status_mask & CDNS_UART_IXR_PARITY)
isrstatus &= ~(CDNS_UART_IXR_RXTRIG | CDNS_UART_IXR_TOUT);
isrstatus &= port->read_status_mask;
isrstatus &= ~port->ignore_status_mask;
if ((isrstatus & CDNS_UART_IXR_TOUT) ||
(isrstatus & CDNS_UART_IXR_RXTRIG)) {
while ((cdns_uart_readl(CDNS_UART_SR_OFFSET) &
CDNS_UART_SR_RXEMPTY) != CDNS_UART_SR_RXEMPTY) {
data = cdns_uart_readl(CDNS_UART_FIFO_OFFSET);
if (data && (port->read_status_mask &
CDNS_UART_IXR_BRK)) {
port->read_status_mask &= ~CDNS_UART_IXR_BRK;
port->icount.brk++;
if (uart_handle_break(port))
continue;
}
#ifdef SUPPORT_SYSRQ
if (port->sysrq) {
spin_unlock(&port->lock);
if (uart_handle_sysrq_char(port,
(unsigned char)data)) {
spin_lock(&port->lock);
continue;
}
spin_lock(&port->lock);
}
#endif
port->icount.rx++;
if (isrstatus & CDNS_UART_IXR_PARITY) {
port->icount.parity++;
status = TTY_PARITY;
} else if (isrstatus & CDNS_UART_IXR_FRAMING) {
port->icount.frame++;
status = TTY_FRAME;
} else if (isrstatus & CDNS_UART_IXR_OVERRUN) {
port->icount.overrun++;
}
uart_insert_char(port, isrstatus, CDNS_UART_IXR_OVERRUN,
data, status);
}
spin_unlock(&port->lock);
tty_flip_buffer_push(&port->state->port);
spin_lock(&port->lock);
}
if ((isrstatus & CDNS_UART_IXR_TXEMPTY) == CDNS_UART_IXR_TXEMPTY) {
if (uart_circ_empty(&port->state->xmit)) {
cdns_uart_writel(CDNS_UART_IXR_TXEMPTY,
CDNS_UART_IDR_OFFSET);
} else {
numbytes = port->fifosize;
while (numbytes--) {
if (uart_circ_empty(&port->state->xmit))
break;
cdns_uart_writel(
port->state->xmit.buf[port->state->xmit.
tail], CDNS_UART_FIFO_OFFSET);
port->icount.tx++;
port->state->xmit.tail =
(port->state->xmit.tail + 1) &
(UART_XMIT_SIZE - 1);
}
if (uart_circ_chars_pending(
&port->state->xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
}
cdns_uart_writel(isrstatus, CDNS_UART_ISR_OFFSET);
spin_unlock_irqrestore(&port->lock, flags);
return IRQ_HANDLED;
}
static unsigned int cdns_uart_calc_baud_divs(unsigned int clk,
unsigned int baud, u32 *rbdiv, u32 *rcd, int *div8)
{
u32 cd, bdiv;
unsigned int calc_baud;
unsigned int bestbaud = 0;
unsigned int bauderror;
unsigned int besterror = ~0;
if (baud < clk / ((CDNS_UART_BDIV_MAX + 1) * CDNS_UART_CD_MAX)) {
*div8 = 1;
clk /= 8;
} else {
*div8 = 0;
}
for (bdiv = CDNS_UART_BDIV_MIN; bdiv <= CDNS_UART_BDIV_MAX; bdiv++) {
cd = DIV_ROUND_CLOSEST(clk, baud * (bdiv + 1));
if (cd < 1 || cd > CDNS_UART_CD_MAX)
continue;
calc_baud = clk / (cd * (bdiv + 1));
if (baud > calc_baud)
bauderror = baud - calc_baud;
else
bauderror = calc_baud - baud;
if (besterror > bauderror) {
*rbdiv = bdiv;
*rcd = cd;
bestbaud = calc_baud;
besterror = bauderror;
}
}
if (((besterror * 100) / baud) < 3)
bestbaud = baud;
return bestbaud;
}
static unsigned int cdns_uart_set_baud_rate(struct uart_port *port,
unsigned int baud)
{
unsigned int calc_baud;
u32 cd = 0, bdiv = 0;
u32 mreg;
int div8;
struct cdns_uart *cdns_uart = port->private_data;
calc_baud = cdns_uart_calc_baud_divs(port->uartclk, baud, &bdiv, &cd,
&div8);
mreg = cdns_uart_readl(CDNS_UART_MR_OFFSET);
if (div8)
mreg |= CDNS_UART_MR_CLKSEL;
else
mreg &= ~CDNS_UART_MR_CLKSEL;
cdns_uart_writel(mreg, CDNS_UART_MR_OFFSET);
cdns_uart_writel(cd, CDNS_UART_BAUDGEN_OFFSET);
cdns_uart_writel(bdiv, CDNS_UART_BAUDDIV_OFFSET);
cdns_uart->baud = baud;
return calc_baud;
}
static int cdns_uart_clk_notifier_cb(struct notifier_block *nb,
unsigned long event, void *data)
{
u32 ctrl_reg;
struct uart_port *port;
int locked = 0;
struct clk_notifier_data *ndata = data;
unsigned long flags = 0;
struct cdns_uart *cdns_uart = to_cdns_uart(nb);
port = cdns_uart->port;
if (port->suspended)
return NOTIFY_OK;
switch (event) {
case PRE_RATE_CHANGE:
{
u32 bdiv, cd;
int div8;
if (!cdns_uart_calc_baud_divs(ndata->new_rate, cdns_uart->baud,
&bdiv, &cd, &div8)) {
dev_warn(port->dev, "clock rate change rejected\n");
return NOTIFY_BAD;
}
spin_lock_irqsave(&cdns_uart->port->lock, flags);
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg |= CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
spin_unlock_irqrestore(&cdns_uart->port->lock, flags);
return NOTIFY_OK;
}
case POST_RATE_CHANGE:
spin_lock_irqsave(&cdns_uart->port->lock, flags);
locked = 1;
port->uartclk = ndata->new_rate;
cdns_uart->baud = cdns_uart_set_baud_rate(cdns_uart->port,
cdns_uart->baud);
case ABORT_RATE_CHANGE:
if (!locked)
spin_lock_irqsave(&cdns_uart->port->lock, flags);
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg |= CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
while (cdns_uart_readl(CDNS_UART_CR_OFFSET) &
(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST))
cpu_relax();
cdns_uart_writel(rx_timeout, CDNS_UART_RXTOUT_OFFSET);
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg &= ~(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS);
ctrl_reg |= CDNS_UART_CR_TX_EN | CDNS_UART_CR_RX_EN;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
spin_unlock_irqrestore(&cdns_uart->port->lock, flags);
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static void cdns_uart_start_tx(struct uart_port *port)
{
unsigned int status, numbytes = port->fifosize;
if (uart_circ_empty(&port->state->xmit) || uart_tx_stopped(port))
return;
status = cdns_uart_readl(CDNS_UART_CR_OFFSET);
cdns_uart_writel((status & ~CDNS_UART_CR_TX_DIS) | CDNS_UART_CR_TX_EN,
CDNS_UART_CR_OFFSET);
while (numbytes-- && ((cdns_uart_readl(CDNS_UART_SR_OFFSET) &
CDNS_UART_SR_TXFULL)) != CDNS_UART_SR_TXFULL) {
if (uart_circ_empty(&port->state->xmit))
break;
cdns_uart_writel(
port->state->xmit.buf[port->state->xmit.tail],
CDNS_UART_FIFO_OFFSET);
port->icount.tx++;
port->state->xmit.tail = (port->state->xmit.tail + 1) &
(UART_XMIT_SIZE - 1);
}
cdns_uart_writel(CDNS_UART_IXR_TXEMPTY, CDNS_UART_ISR_OFFSET);
cdns_uart_writel(CDNS_UART_IXR_TXEMPTY, CDNS_UART_IER_OFFSET);
if (uart_circ_chars_pending(&port->state->xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
static void cdns_uart_stop_tx(struct uart_port *port)
{
unsigned int regval;
regval = cdns_uart_readl(CDNS_UART_CR_OFFSET);
regval |= CDNS_UART_CR_TX_DIS;
cdns_uart_writel(regval, CDNS_UART_CR_OFFSET);
}
static void cdns_uart_stop_rx(struct uart_port *port)
{
unsigned int regval;
regval = cdns_uart_readl(CDNS_UART_CR_OFFSET);
regval |= CDNS_UART_CR_RX_DIS;
cdns_uart_writel(regval, CDNS_UART_CR_OFFSET);
}
static unsigned int cdns_uart_tx_empty(struct uart_port *port)
{
unsigned int status;
status = cdns_uart_readl(CDNS_UART_SR_OFFSET) & CDNS_UART_SR_TXEMPTY;
return status ? TIOCSER_TEMT : 0;
}
static void cdns_uart_break_ctl(struct uart_port *port, int ctl)
{
unsigned int status;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
status = cdns_uart_readl(CDNS_UART_CR_OFFSET);
if (ctl == -1)
cdns_uart_writel(CDNS_UART_CR_STARTBRK | status,
CDNS_UART_CR_OFFSET);
else {
if ((status & CDNS_UART_CR_STOPBRK) == 0)
cdns_uart_writel(CDNS_UART_CR_STOPBRK | status,
CDNS_UART_CR_OFFSET);
}
spin_unlock_irqrestore(&port->lock, flags);
}
static void cdns_uart_set_termios(struct uart_port *port,
struct ktermios *termios, struct ktermios *old)
{
unsigned int cval = 0;
unsigned int baud, minbaud, maxbaud;
unsigned long flags;
unsigned int ctrl_reg, mode_reg;
spin_lock_irqsave(&port->lock, flags);
while ((cdns_uart_readl(CDNS_UART_SR_OFFSET) &
CDNS_UART_SR_RXEMPTY) != CDNS_UART_SR_RXEMPTY) {
cdns_uart_readl(CDNS_UART_FIFO_OFFSET);
}
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg |= CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
minbaud = port->uartclk /
((CDNS_UART_BDIV_MAX + 1) * CDNS_UART_CD_MAX * 8);
maxbaud = port->uartclk / (CDNS_UART_BDIV_MIN + 1);
baud = uart_get_baud_rate(port, termios, old, minbaud, maxbaud);
baud = cdns_uart_set_baud_rate(port, baud);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
uart_update_timeout(port, termios->c_cflag, baud);
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg |= CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg &= ~(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS);
ctrl_reg |= CDNS_UART_CR_TX_EN | CDNS_UART_CR_RX_EN;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
cdns_uart_writel(rx_timeout, CDNS_UART_RXTOUT_OFFSET);
port->read_status_mask = CDNS_UART_IXR_TXEMPTY | CDNS_UART_IXR_RXTRIG |
CDNS_UART_IXR_OVERRUN | CDNS_UART_IXR_TOUT;
port->ignore_status_mask = 0;
if (termios->c_iflag & INPCK)
port->read_status_mask |= CDNS_UART_IXR_PARITY |
CDNS_UART_IXR_FRAMING;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= CDNS_UART_IXR_PARITY |
CDNS_UART_IXR_FRAMING | CDNS_UART_IXR_OVERRUN;
if ((termios->c_cflag & CREAD) == 0)
port->ignore_status_mask |= CDNS_UART_IXR_RXTRIG |
CDNS_UART_IXR_TOUT | CDNS_UART_IXR_PARITY |
CDNS_UART_IXR_FRAMING | CDNS_UART_IXR_OVERRUN;
mode_reg = cdns_uart_readl(CDNS_UART_MR_OFFSET);
switch (termios->c_cflag & CSIZE) {
case CS6:
cval |= CDNS_UART_MR_CHARLEN_6_BIT;
break;
case CS7:
cval |= CDNS_UART_MR_CHARLEN_7_BIT;
break;
default:
case CS8:
cval |= CDNS_UART_MR_CHARLEN_8_BIT;
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= CS8;
break;
}
if (termios->c_cflag & CSTOPB)
cval |= CDNS_UART_MR_STOPMODE_2_BIT;
else
cval |= CDNS_UART_MR_STOPMODE_1_BIT;
if (termios->c_cflag & PARENB) {
if (termios->c_cflag & CMSPAR) {
if (termios->c_cflag & PARODD)
cval |= CDNS_UART_MR_PARITY_MARK;
else
cval |= CDNS_UART_MR_PARITY_SPACE;
} else {
if (termios->c_cflag & PARODD)
cval |= CDNS_UART_MR_PARITY_ODD;
else
cval |= CDNS_UART_MR_PARITY_EVEN;
}
} else {
cval |= CDNS_UART_MR_PARITY_NONE;
}
cval |= mode_reg & 1;
cdns_uart_writel(cval, CDNS_UART_MR_OFFSET);
spin_unlock_irqrestore(&port->lock, flags);
}
static int cdns_uart_startup(struct uart_port *port)
{
unsigned int retval = 0, status = 0;
retval = request_irq(port->irq, cdns_uart_isr, 0, CDNS_UART_NAME,
(void *)port);
if (retval)
return retval;
cdns_uart_writel(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS,
CDNS_UART_CR_OFFSET);
cdns_uart_writel(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST,
CDNS_UART_CR_OFFSET);
status = cdns_uart_readl(CDNS_UART_CR_OFFSET);
cdns_uart_writel((status & ~(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS))
| (CDNS_UART_CR_TX_EN | CDNS_UART_CR_RX_EN |
CDNS_UART_CR_STOPBRK), CDNS_UART_CR_OFFSET);
cdns_uart_writel(CDNS_UART_MR_CHMODE_NORM | CDNS_UART_MR_STOPMODE_1_BIT
| CDNS_UART_MR_PARITY_NONE | CDNS_UART_MR_CHARLEN_8_BIT,
CDNS_UART_MR_OFFSET);
cdns_uart_writel(rx_trigger_level, CDNS_UART_RXWM_OFFSET);
cdns_uart_writel(rx_timeout, CDNS_UART_RXTOUT_OFFSET);
cdns_uart_writel(cdns_uart_readl(CDNS_UART_ISR_OFFSET),
CDNS_UART_ISR_OFFSET);
cdns_uart_writel(CDNS_UART_IXR_TXEMPTY | CDNS_UART_IXR_PARITY |
CDNS_UART_IXR_FRAMING | CDNS_UART_IXR_OVERRUN |
CDNS_UART_IXR_RXTRIG | CDNS_UART_IXR_TOUT,
CDNS_UART_IER_OFFSET);
return retval;
}
static void cdns_uart_shutdown(struct uart_port *port)
{
int status;
status = cdns_uart_readl(CDNS_UART_IMR_OFFSET);
cdns_uart_writel(status, CDNS_UART_IDR_OFFSET);
cdns_uart_writel(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS,
CDNS_UART_CR_OFFSET);
free_irq(port->irq, port);
}
static const char *cdns_uart_type(struct uart_port *port)
{
return port->type == PORT_XUARTPS ? CDNS_UART_NAME : NULL;
}
static int cdns_uart_verify_port(struct uart_port *port,
struct serial_struct *ser)
{
if (ser->type != PORT_UNKNOWN && ser->type != PORT_XUARTPS)
return -EINVAL;
if (port->irq != ser->irq)
return -EINVAL;
if (ser->io_type != UPIO_MEM)
return -EINVAL;
if (port->iobase != ser->port)
return -EINVAL;
if (ser->hub6 != 0)
return -EINVAL;
return 0;
}
static int cdns_uart_request_port(struct uart_port *port)
{
if (!request_mem_region(port->mapbase, CDNS_UART_REGISTER_SPACE,
CDNS_UART_NAME)) {
return -ENOMEM;
}
port->membase = ioremap(port->mapbase, CDNS_UART_REGISTER_SPACE);
if (!port->membase) {
dev_err(port->dev, "Unable to map registers\n");
release_mem_region(port->mapbase, CDNS_UART_REGISTER_SPACE);
return -ENOMEM;
}
return 0;
}
static void cdns_uart_release_port(struct uart_port *port)
{
release_mem_region(port->mapbase, CDNS_UART_REGISTER_SPACE);
iounmap(port->membase);
port->membase = NULL;
}
static void cdns_uart_config_port(struct uart_port *port, int flags)
{
if (flags & UART_CONFIG_TYPE && cdns_uart_request_port(port) == 0)
port->type = PORT_XUARTPS;
}
static unsigned int cdns_uart_get_mctrl(struct uart_port *port)
{
return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}
static void cdns_uart_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
}
static int cdns_uart_poll_get_char(struct uart_port *port)
{
u32 imr;
int c;
imr = cdns_uart_readl(CDNS_UART_IMR_OFFSET);
cdns_uart_writel(imr, CDNS_UART_IDR_OFFSET);
if (cdns_uart_readl(CDNS_UART_SR_OFFSET) & CDNS_UART_SR_RXEMPTY)
c = NO_POLL_CHAR;
else
c = (unsigned char) cdns_uart_readl(CDNS_UART_FIFO_OFFSET);
cdns_uart_writel(imr, CDNS_UART_IER_OFFSET);
return c;
}
static void cdns_uart_poll_put_char(struct uart_port *port, unsigned char c)
{
u32 imr;
imr = cdns_uart_readl(CDNS_UART_IMR_OFFSET);
cdns_uart_writel(imr, CDNS_UART_IDR_OFFSET);
while (!(cdns_uart_readl(CDNS_UART_SR_OFFSET) & CDNS_UART_SR_TXEMPTY))
cpu_relax();
cdns_uart_writel(c, CDNS_UART_FIFO_OFFSET);
while (!(cdns_uart_readl(CDNS_UART_SR_OFFSET) & CDNS_UART_SR_TXEMPTY))
cpu_relax();
cdns_uart_writel(imr, CDNS_UART_IER_OFFSET);
return;
}
static struct uart_port *cdns_uart_get_port(int id)
{
struct uart_port *port;
if (cdns_uart_port[id].mapbase != 0) {
for (id = 0; id < CDNS_UART_NR_PORTS; id++)
if (cdns_uart_port[id].mapbase == 0)
break;
}
if (id >= CDNS_UART_NR_PORTS)
return NULL;
port = &cdns_uart_port[id];
spin_lock_init(&port->lock);
port->membase = NULL;
port->iobase = 1;
port->irq = 0;
port->type = PORT_UNKNOWN;
port->iotype = UPIO_MEM32;
port->flags = UPF_BOOT_AUTOCONF;
port->ops = &cdns_uart_ops;
port->fifosize = CDNS_UART_FIFO_SIZE;
port->line = id;
port->dev = NULL;
return port;
}
static void cdns_uart_console_wait_tx(struct uart_port *port)
{
while ((cdns_uart_readl(CDNS_UART_SR_OFFSET) & CDNS_UART_SR_TXEMPTY)
!= CDNS_UART_SR_TXEMPTY)
barrier();
}
static void cdns_uart_console_putchar(struct uart_port *port, int ch)
{
cdns_uart_console_wait_tx(port);
cdns_uart_writel(ch, CDNS_UART_FIFO_OFFSET);
}
static void cdns_early_write(struct console *con, const char *s, unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, cdns_uart_console_putchar);
}
static int __init cdns_early_console_setup(struct earlycon_device *device,
const char *opt)
{
if (!device->port.membase)
return -ENODEV;
device->con->write = cdns_early_write;
return 0;
}
static void cdns_uart_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_port *port = &cdns_uart_port[co->index];
unsigned long flags;
unsigned int imr, ctrl;
int locked = 1;
if (oops_in_progress)
locked = spin_trylock_irqsave(&port->lock, flags);
else
spin_lock_irqsave(&port->lock, flags);
imr = cdns_uart_readl(CDNS_UART_IMR_OFFSET);
cdns_uart_writel(imr, CDNS_UART_IDR_OFFSET);
ctrl = cdns_uart_readl(CDNS_UART_CR_OFFSET);
cdns_uart_writel((ctrl & ~CDNS_UART_CR_TX_DIS) | CDNS_UART_CR_TX_EN,
CDNS_UART_CR_OFFSET);
uart_console_write(port, s, count, cdns_uart_console_putchar);
cdns_uart_console_wait_tx(port);
cdns_uart_writel(ctrl, CDNS_UART_CR_OFFSET);
cdns_uart_writel(imr, CDNS_UART_IER_OFFSET);
if (locked)
spin_unlock_irqrestore(&port->lock, flags);
}
static int __init cdns_uart_console_setup(struct console *co, char *options)
{
struct uart_port *port = &cdns_uart_port[co->index];
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index < 0 || co->index >= CDNS_UART_NR_PORTS)
return -EINVAL;
if (!port->mapbase) {
pr_debug("console on ttyPS%i not present\n", co->index);
return -ENODEV;
}
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(port, co, baud, parity, bits, flow);
}
static int __init cdns_uart_console_init(void)
{
register_console(&cdns_uart_console);
return 0;
}
static int cdns_uart_suspend(struct device *device)
{
struct uart_port *port = dev_get_drvdata(device);
struct tty_struct *tty;
struct device *tty_dev;
int may_wake = 0;
tty = tty_port_tty_get(&port->state->port);
if (tty) {
tty_dev = tty->dev;
may_wake = device_may_wakeup(tty_dev);
tty_kref_put(tty);
}
uart_suspend_port(&cdns_uart_uart_driver, port);
if (console_suspend_enabled && !may_wake) {
struct cdns_uart *cdns_uart = port->private_data;
clk_disable(cdns_uart->uartclk);
clk_disable(cdns_uart->pclk);
} else {
unsigned long flags = 0;
spin_lock_irqsave(&port->lock, flags);
while (!(cdns_uart_readl(CDNS_UART_SR_OFFSET) &
CDNS_UART_SR_RXEMPTY))
cdns_uart_readl(CDNS_UART_FIFO_OFFSET);
cdns_uart_writel(1, CDNS_UART_RXWM_OFFSET);
cdns_uart_writel(CDNS_UART_IXR_TOUT, CDNS_UART_IDR_OFFSET);
spin_unlock_irqrestore(&port->lock, flags);
}
return 0;
}
static int cdns_uart_resume(struct device *device)
{
struct uart_port *port = dev_get_drvdata(device);
unsigned long flags = 0;
u32 ctrl_reg;
struct tty_struct *tty;
struct device *tty_dev;
int may_wake = 0;
tty = tty_port_tty_get(&port->state->port);
if (tty) {
tty_dev = tty->dev;
may_wake = device_may_wakeup(tty_dev);
tty_kref_put(tty);
}
if (console_suspend_enabled && !may_wake) {
struct cdns_uart *cdns_uart = port->private_data;
clk_enable(cdns_uart->pclk);
clk_enable(cdns_uart->uartclk);
spin_lock_irqsave(&port->lock, flags);
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg |= CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
while (cdns_uart_readl(CDNS_UART_CR_OFFSET) &
(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST))
cpu_relax();
cdns_uart_writel(rx_timeout, CDNS_UART_RXTOUT_OFFSET);
ctrl_reg = cdns_uart_readl(CDNS_UART_CR_OFFSET);
ctrl_reg &= ~(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS);
ctrl_reg |= CDNS_UART_CR_TX_EN | CDNS_UART_CR_RX_EN;
cdns_uart_writel(ctrl_reg, CDNS_UART_CR_OFFSET);
spin_unlock_irqrestore(&port->lock, flags);
} else {
spin_lock_irqsave(&port->lock, flags);
cdns_uart_writel(rx_trigger_level, CDNS_UART_RXWM_OFFSET);
cdns_uart_writel(CDNS_UART_IXR_TOUT, CDNS_UART_IER_OFFSET);
spin_unlock_irqrestore(&port->lock, flags);
}
return uart_resume_port(&cdns_uart_uart_driver, port);
}
static int cdns_uart_probe(struct platform_device *pdev)
{
int rc, id;
struct uart_port *port;
struct resource *res, *res2;
struct cdns_uart *cdns_uart_data;
cdns_uart_data = devm_kzalloc(&pdev->dev, sizeof(*cdns_uart_data),
GFP_KERNEL);
if (!cdns_uart_data)
return -ENOMEM;
cdns_uart_data->pclk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(cdns_uart_data->pclk)) {
cdns_uart_data->pclk = devm_clk_get(&pdev->dev, "aper_clk");
if (!IS_ERR(cdns_uart_data->pclk))
dev_err(&pdev->dev, "clock name 'aper_clk' is deprecated.\n");
}
if (IS_ERR(cdns_uart_data->pclk)) {
dev_err(&pdev->dev, "pclk clock not found.\n");
return PTR_ERR(cdns_uart_data->pclk);
}
cdns_uart_data->uartclk = devm_clk_get(&pdev->dev, "uart_clk");
if (IS_ERR(cdns_uart_data->uartclk)) {
cdns_uart_data->uartclk = devm_clk_get(&pdev->dev, "ref_clk");
if (!IS_ERR(cdns_uart_data->uartclk))
dev_err(&pdev->dev, "clock name 'ref_clk' is deprecated.\n");
}
if (IS_ERR(cdns_uart_data->uartclk)) {
dev_err(&pdev->dev, "uart_clk clock not found.\n");
return PTR_ERR(cdns_uart_data->uartclk);
}
rc = clk_prepare_enable(cdns_uart_data->pclk);
if (rc) {
dev_err(&pdev->dev, "Unable to enable pclk clock.\n");
return rc;
}
rc = clk_prepare_enable(cdns_uart_data->uartclk);
if (rc) {
dev_err(&pdev->dev, "Unable to enable device clock.\n");
goto err_out_clk_dis_pclk;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
rc = -ENODEV;
goto err_out_clk_disable;
}
res2 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res2) {
rc = -ENODEV;
goto err_out_clk_disable;
}
#ifdef CONFIG_COMMON_CLK
cdns_uart_data->clk_rate_change_nb.notifier_call =
cdns_uart_clk_notifier_cb;
if (clk_notifier_register(cdns_uart_data->uartclk,
&cdns_uart_data->clk_rate_change_nb))
dev_warn(&pdev->dev, "Unable to register clock notifier.\n");
#endif
id = of_alias_get_id(pdev->dev.of_node, "serial");
if (id < 0)
id = 0;
port = cdns_uart_get_port(id);
if (!port) {
dev_err(&pdev->dev, "Cannot get uart_port structure\n");
rc = -ENODEV;
goto err_out_notif_unreg;
} else {
port->mapbase = res->start;
port->irq = res2->start;
port->dev = &pdev->dev;
port->uartclk = clk_get_rate(cdns_uart_data->uartclk);
port->private_data = cdns_uart_data;
cdns_uart_data->port = port;
platform_set_drvdata(pdev, port);
rc = uart_add_one_port(&cdns_uart_uart_driver, port);
if (rc) {
dev_err(&pdev->dev,
"uart_add_one_port() failed; err=%i\n", rc);
goto err_out_notif_unreg;
}
return 0;
}
err_out_notif_unreg:
#ifdef CONFIG_COMMON_CLK
clk_notifier_unregister(cdns_uart_data->uartclk,
&cdns_uart_data->clk_rate_change_nb);
#endif
err_out_clk_disable:
clk_disable_unprepare(cdns_uart_data->uartclk);
err_out_clk_dis_pclk:
clk_disable_unprepare(cdns_uart_data->pclk);
return rc;
}
static int cdns_uart_remove(struct platform_device *pdev)
{
struct uart_port *port = platform_get_drvdata(pdev);
struct cdns_uart *cdns_uart_data = port->private_data;
int rc;
#ifdef CONFIG_COMMON_CLK
clk_notifier_unregister(cdns_uart_data->uartclk,
&cdns_uart_data->clk_rate_change_nb);
#endif
rc = uart_remove_one_port(&cdns_uart_uart_driver, port);
port->mapbase = 0;
clk_disable_unprepare(cdns_uart_data->uartclk);
clk_disable_unprepare(cdns_uart_data->pclk);
return rc;
}
static int __init cdns_uart_init(void)
{
int retval = 0;
retval = uart_register_driver(&cdns_uart_uart_driver);
if (retval)
return retval;
retval = platform_driver_register(&cdns_uart_platform_driver);
if (retval)
uart_unregister_driver(&cdns_uart_uart_driver);
return retval;
}
static void __exit cdns_uart_exit(void)
{
platform_driver_unregister(&cdns_uart_platform_driver);
uart_unregister_driver(&cdns_uart_uart_driver);
}
