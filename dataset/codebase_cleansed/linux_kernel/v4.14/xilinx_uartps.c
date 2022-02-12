static void cdns_uart_handle_rx(void *dev_id, unsigned int isrstatus)
{
struct uart_port *port = (struct uart_port *)dev_id;
struct cdns_uart *cdns_uart = port->private_data;
unsigned int data;
unsigned int rxbs_status = 0;
unsigned int status_mask;
unsigned int framerrprocessed = 0;
char status = TTY_NORMAL;
bool is_rxbs_support;
is_rxbs_support = cdns_uart->quirks & CDNS_UART_RXBS_SUPPORT;
while ((readl(port->membase + CDNS_UART_SR) &
CDNS_UART_SR_RXEMPTY) != CDNS_UART_SR_RXEMPTY) {
if (is_rxbs_support)
rxbs_status = readl(port->membase + CDNS_UART_RXBS);
data = readl(port->membase + CDNS_UART_FIFO);
port->icount.rx++;
if (!is_rxbs_support && (isrstatus & CDNS_UART_IXR_FRAMING)) {
if (!data) {
port->read_status_mask |= CDNS_UART_IXR_BRK;
framerrprocessed = 1;
continue;
}
}
if (is_rxbs_support && (rxbs_status & CDNS_UART_RXBS_BRK)) {
port->icount.brk++;
status = TTY_BREAK;
if (uart_handle_break(port))
continue;
}
isrstatus &= port->read_status_mask;
isrstatus &= ~port->ignore_status_mask;
status_mask = port->read_status_mask;
status_mask &= ~port->ignore_status_mask;
if (data &&
(port->read_status_mask & CDNS_UART_IXR_BRK)) {
port->read_status_mask &= ~CDNS_UART_IXR_BRK;
port->icount.brk++;
if (uart_handle_break(port))
continue;
}
if (uart_handle_sysrq_char(port, data))
continue;
if (is_rxbs_support) {
if ((rxbs_status & CDNS_UART_RXBS_PARITY)
&& (status_mask & CDNS_UART_IXR_PARITY)) {
port->icount.parity++;
status = TTY_PARITY;
}
if ((rxbs_status & CDNS_UART_RXBS_FRAMING)
&& (status_mask & CDNS_UART_IXR_PARITY)) {
port->icount.frame++;
status = TTY_FRAME;
}
} else {
if (isrstatus & CDNS_UART_IXR_PARITY) {
port->icount.parity++;
status = TTY_PARITY;
}
if ((isrstatus & CDNS_UART_IXR_FRAMING) &&
!framerrprocessed) {
port->icount.frame++;
status = TTY_FRAME;
}
}
if (isrstatus & CDNS_UART_IXR_OVERRUN) {
port->icount.overrun++;
tty_insert_flip_char(&port->state->port, 0,
TTY_OVERRUN);
}
tty_insert_flip_char(&port->state->port, data, status);
isrstatus = 0;
}
spin_unlock(&port->lock);
tty_flip_buffer_push(&port->state->port);
spin_lock(&port->lock);
}
static void cdns_uart_handle_tx(void *dev_id)
{
struct uart_port *port = (struct uart_port *)dev_id;
unsigned int numbytes;
if (uart_circ_empty(&port->state->xmit)) {
writel(CDNS_UART_IXR_TXEMPTY, port->membase + CDNS_UART_IDR);
} else {
numbytes = port->fifosize;
while (numbytes && !uart_circ_empty(&port->state->xmit) &&
!(readl(port->membase + CDNS_UART_SR) & CDNS_UART_SR_TXFULL)) {
writel(
port->state->xmit.buf[port->state->xmit.
tail], port->membase + CDNS_UART_FIFO);
port->icount.tx++;
port->state->xmit.tail =
(port->state->xmit.tail + 1) &
(UART_XMIT_SIZE - 1);
numbytes--;
}
if (uart_circ_chars_pending(
&port->state->xmit) < WAKEUP_CHARS)
uart_write_wakeup(port);
}
}
static irqreturn_t cdns_uart_isr(int irq, void *dev_id)
{
struct uart_port *port = (struct uart_port *)dev_id;
unsigned int isrstatus;
spin_lock(&port->lock);
isrstatus = readl(port->membase + CDNS_UART_ISR);
writel(isrstatus, port->membase + CDNS_UART_ISR);
if (isrstatus & CDNS_UART_IXR_TXEMPTY) {
cdns_uart_handle_tx(dev_id);
isrstatus &= ~CDNS_UART_IXR_TXEMPTY;
}
if (isrstatus & CDNS_UART_IXR_MASK)
cdns_uart_handle_rx(dev_id, isrstatus);
spin_unlock(&port->lock);
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
mreg = readl(port->membase + CDNS_UART_MR);
if (div8)
mreg |= CDNS_UART_MR_CLKSEL;
else
mreg &= ~CDNS_UART_MR_CLKSEL;
writel(mreg, port->membase + CDNS_UART_MR);
writel(cd, port->membase + CDNS_UART_BAUDGEN);
writel(bdiv, port->membase + CDNS_UART_BAUDDIV);
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
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg |= CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
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
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg |= CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
while (readl(port->membase + CDNS_UART_CR) &
(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST))
cpu_relax();
writel(rx_timeout, port->membase + CDNS_UART_RXTOUT);
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg &= ~(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS);
ctrl_reg |= CDNS_UART_CR_TX_EN | CDNS_UART_CR_RX_EN;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
spin_unlock_irqrestore(&cdns_uart->port->lock, flags);
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static void cdns_uart_start_tx(struct uart_port *port)
{
unsigned int status;
if (uart_tx_stopped(port))
return;
status = readl(port->membase + CDNS_UART_CR);
status &= ~CDNS_UART_CR_TX_DIS;
status |= CDNS_UART_CR_TX_EN;
writel(status, port->membase + CDNS_UART_CR);
if (uart_circ_empty(&port->state->xmit))
return;
cdns_uart_handle_tx(port);
writel(CDNS_UART_IXR_TXEMPTY, port->membase + CDNS_UART_ISR);
writel(CDNS_UART_IXR_TXEMPTY, port->membase + CDNS_UART_IER);
}
static void cdns_uart_stop_tx(struct uart_port *port)
{
unsigned int regval;
regval = readl(port->membase + CDNS_UART_CR);
regval |= CDNS_UART_CR_TX_DIS;
writel(regval, port->membase + CDNS_UART_CR);
}
static void cdns_uart_stop_rx(struct uart_port *port)
{
unsigned int regval;
writel(CDNS_UART_RX_IRQS, port->membase + CDNS_UART_IDR);
regval = readl(port->membase + CDNS_UART_CR);
regval |= CDNS_UART_CR_RX_DIS;
writel(regval, port->membase + CDNS_UART_CR);
}
static unsigned int cdns_uart_tx_empty(struct uart_port *port)
{
unsigned int status;
status = readl(port->membase + CDNS_UART_SR) &
CDNS_UART_SR_TXEMPTY;
return status ? TIOCSER_TEMT : 0;
}
static void cdns_uart_break_ctl(struct uart_port *port, int ctl)
{
unsigned int status;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
status = readl(port->membase + CDNS_UART_CR);
if (ctl == -1)
writel(CDNS_UART_CR_STARTBRK | status,
port->membase + CDNS_UART_CR);
else {
if ((status & CDNS_UART_CR_STOPBRK) == 0)
writel(CDNS_UART_CR_STOPBRK | status,
port->membase + CDNS_UART_CR);
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
if (!(readl(port->membase + CDNS_UART_CR) &
CDNS_UART_CR_TX_DIS)) {
while (!(readl(port->membase + CDNS_UART_SR) &
CDNS_UART_SR_TXEMPTY)) {
cpu_relax();
}
}
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg |= CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
minbaud = port->uartclk /
((CDNS_UART_BDIV_MAX + 1) * CDNS_UART_CD_MAX * 8);
maxbaud = port->uartclk / (CDNS_UART_BDIV_MIN + 1);
baud = uart_get_baud_rate(port, termios, old, minbaud, maxbaud);
baud = cdns_uart_set_baud_rate(port, baud);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
uart_update_timeout(port, termios->c_cflag, baud);
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg |= CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
while (readl(port->membase + CDNS_UART_CR) &
(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST))
cpu_relax();
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg &= ~(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS);
ctrl_reg |= CDNS_UART_CR_TX_EN | CDNS_UART_CR_RX_EN;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
writel(rx_timeout, port->membase + CDNS_UART_RXTOUT);
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
mode_reg = readl(port->membase + CDNS_UART_MR);
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
writel(cval, port->membase + CDNS_UART_MR);
spin_unlock_irqrestore(&port->lock, flags);
}
static int cdns_uart_startup(struct uart_port *port)
{
struct cdns_uart *cdns_uart = port->private_data;
bool is_brk_support;
int ret;
unsigned long flags;
unsigned int status = 0;
is_brk_support = cdns_uart->quirks & CDNS_UART_RXBS_SUPPORT;
spin_lock_irqsave(&port->lock, flags);
writel(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS,
port->membase + CDNS_UART_CR);
writel(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST,
port->membase + CDNS_UART_CR);
while (readl(port->membase + CDNS_UART_CR) &
(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST))
cpu_relax();
status = readl(port->membase + CDNS_UART_CR);
status &= CDNS_UART_CR_RX_DIS;
status |= CDNS_UART_CR_RX_EN;
writel(status, port->membase + CDNS_UART_CR);
writel(CDNS_UART_MR_CHMODE_NORM | CDNS_UART_MR_STOPMODE_1_BIT
| CDNS_UART_MR_PARITY_NONE | CDNS_UART_MR_CHARLEN_8_BIT,
port->membase + CDNS_UART_MR);
writel(rx_trigger_level, port->membase + CDNS_UART_RXWM);
writel(rx_timeout, port->membase + CDNS_UART_RXTOUT);
writel(readl(port->membase + CDNS_UART_ISR),
port->membase + CDNS_UART_ISR);
spin_unlock_irqrestore(&port->lock, flags);
ret = request_irq(port->irq, cdns_uart_isr, 0, CDNS_UART_NAME, port);
if (ret) {
dev_err(port->dev, "request_irq '%d' failed with %d\n",
port->irq, ret);
return ret;
}
if (is_brk_support)
writel(CDNS_UART_RX_IRQS | CDNS_UART_IXR_BRK,
port->membase + CDNS_UART_IER);
else
writel(CDNS_UART_RX_IRQS, port->membase + CDNS_UART_IER);
return 0;
}
static void cdns_uart_shutdown(struct uart_port *port)
{
int status;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
status = readl(port->membase + CDNS_UART_IMR);
writel(status, port->membase + CDNS_UART_IDR);
writel(0xffffffff, port->membase + CDNS_UART_ISR);
writel(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS,
port->membase + CDNS_UART_CR);
spin_unlock_irqrestore(&port->lock, flags);
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
u32 val;
u32 mode_reg;
val = readl(port->membase + CDNS_UART_MODEMCR);
mode_reg = readl(port->membase + CDNS_UART_MR);
val &= ~(CDNS_UART_MODEMCR_RTS | CDNS_UART_MODEMCR_DTR);
mode_reg &= ~CDNS_UART_MR_CHMODE_MASK;
if (mctrl & TIOCM_RTS)
val |= CDNS_UART_MODEMCR_RTS;
if (mctrl & TIOCM_DTR)
val |= CDNS_UART_MODEMCR_DTR;
if (mctrl & TIOCM_LOOP)
mode_reg |= CDNS_UART_MR_CHMODE_L_LOOP;
else
mode_reg |= CDNS_UART_MR_CHMODE_NORM;
writel(val, port->membase + CDNS_UART_MODEMCR);
writel(mode_reg, port->membase + CDNS_UART_MR);
}
static int cdns_uart_poll_get_char(struct uart_port *port)
{
int c;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (readl(port->membase + CDNS_UART_SR) & CDNS_UART_SR_RXEMPTY)
c = NO_POLL_CHAR;
else
c = (unsigned char) readl(port->membase + CDNS_UART_FIFO);
spin_unlock_irqrestore(&port->lock, flags);
return c;
}
static void cdns_uart_poll_put_char(struct uart_port *port, unsigned char c)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
while (!(readl(port->membase + CDNS_UART_SR) & CDNS_UART_SR_TXEMPTY))
cpu_relax();
writel(c, port->membase + CDNS_UART_FIFO);
while (!(readl(port->membase + CDNS_UART_SR) & CDNS_UART_SR_TXEMPTY))
cpu_relax();
spin_unlock_irqrestore(&port->lock, flags);
return;
}
static void cdns_uart_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
switch (state) {
case UART_PM_STATE_OFF:
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
break;
default:
pm_runtime_get_sync(port->dev);
break;
}
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
while (!(readl(port->membase + CDNS_UART_SR) & CDNS_UART_SR_TXEMPTY))
barrier();
}
static void cdns_uart_console_putchar(struct uart_port *port, int ch)
{
cdns_uart_console_wait_tx(port);
writel(ch, port->membase + CDNS_UART_FIFO);
}
static void cdns_early_write(struct console *con, const char *s,
unsigned n)
{
struct earlycon_device *dev = con->data;
uart_console_write(&dev->port, s, n, cdns_uart_console_putchar);
}
static int __init cdns_early_console_setup(struct earlycon_device *device,
const char *opt)
{
struct uart_port *port = &device->port;
if (!port->membase)
return -ENODEV;
writel(CDNS_UART_CR_TX_EN|CDNS_UART_CR_TXRST|CDNS_UART_CR_RXRST,
port->membase + CDNS_UART_CR);
if (device->baud) {
u32 cd = 0, bdiv = 0;
u32 mr;
int div8;
cdns_uart_calc_baud_divs(port->uartclk, device->baud,
&bdiv, &cd, &div8);
mr = CDNS_UART_MR_PARITY_NONE;
if (div8)
mr |= CDNS_UART_MR_CLKSEL;
writel(mr, port->membase + CDNS_UART_MR);
writel(cd, port->membase + CDNS_UART_BAUDGEN);
writel(bdiv, port->membase + CDNS_UART_BAUDDIV);
}
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
if (port->sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock_irqsave(&port->lock, flags);
else
spin_lock_irqsave(&port->lock, flags);
imr = readl(port->membase + CDNS_UART_IMR);
writel(imr, port->membase + CDNS_UART_IDR);
ctrl = readl(port->membase + CDNS_UART_CR);
ctrl &= ~CDNS_UART_CR_TX_DIS;
ctrl |= CDNS_UART_CR_TX_EN;
writel(ctrl, port->membase + CDNS_UART_CR);
uart_console_write(port, s, count, cdns_uart_console_putchar);
cdns_uart_console_wait_tx(port);
writel(ctrl, port->membase + CDNS_UART_CR);
writel(imr, port->membase + CDNS_UART_IER);
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
if (!port->membase) {
pr_debug("console on " CDNS_UART_TTY_NAME "%i not present\n",
co->index);
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
if (!(console_suspend_enabled && !may_wake)) {
unsigned long flags = 0;
spin_lock_irqsave(&port->lock, flags);
while (!(readl(port->membase + CDNS_UART_SR) &
CDNS_UART_SR_RXEMPTY))
readl(port->membase + CDNS_UART_FIFO);
writel(1, port->membase + CDNS_UART_RXWM);
writel(CDNS_UART_IXR_TOUT, port->membase + CDNS_UART_IDR);
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
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg |= CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
while (readl(port->membase + CDNS_UART_CR) &
(CDNS_UART_CR_TXRST | CDNS_UART_CR_RXRST))
cpu_relax();
writel(rx_timeout, port->membase + CDNS_UART_RXTOUT);
ctrl_reg = readl(port->membase + CDNS_UART_CR);
ctrl_reg &= ~(CDNS_UART_CR_TX_DIS | CDNS_UART_CR_RX_DIS);
ctrl_reg |= CDNS_UART_CR_TX_EN | CDNS_UART_CR_RX_EN;
writel(ctrl_reg, port->membase + CDNS_UART_CR);
clk_disable(cdns_uart->uartclk);
clk_disable(cdns_uart->pclk);
spin_unlock_irqrestore(&port->lock, flags);
} else {
spin_lock_irqsave(&port->lock, flags);
writel(rx_trigger_level, port->membase + CDNS_UART_RXWM);
writel(CDNS_UART_IXR_TOUT, port->membase + CDNS_UART_IER);
spin_unlock_irqrestore(&port->lock, flags);
}
return uart_resume_port(&cdns_uart_uart_driver, port);
}
static int __maybe_unused cdns_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct uart_port *port = platform_get_drvdata(pdev);
struct cdns_uart *cdns_uart = port->private_data;
clk_disable(cdns_uart->uartclk);
clk_disable(cdns_uart->pclk);
return 0;
}
static int __maybe_unused cdns_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct uart_port *port = platform_get_drvdata(pdev);
struct cdns_uart *cdns_uart = port->private_data;
clk_enable(cdns_uart->pclk);
clk_enable(cdns_uart->uartclk);
return 0;
}
static int cdns_uart_probe(struct platform_device *pdev)
{
int rc, id, irq;
struct uart_port *port;
struct resource *res;
struct cdns_uart *cdns_uart_data;
const struct of_device_id *match;
cdns_uart_data = devm_kzalloc(&pdev->dev, sizeof(*cdns_uart_data),
GFP_KERNEL);
if (!cdns_uart_data)
return -ENOMEM;
match = of_match_node(cdns_uart_of_match, pdev->dev.of_node);
if (match && match->data) {
const struct cdns_platform_data *data = match->data;
cdns_uart_data->quirks = data->quirks;
}
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
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
rc = -ENXIO;
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
}
port->mapbase = res->start;
port->irq = irq;
port->dev = &pdev->dev;
port->uartclk = clk_get_rate(cdns_uart_data->uartclk);
port->private_data = cdns_uart_data;
cdns_uart_data->port = port;
platform_set_drvdata(pdev, port);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, UART_AUTOSUSPEND_TIMEOUT);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
rc = uart_add_one_port(&cdns_uart_uart_driver, port);
if (rc) {
dev_err(&pdev->dev,
"uart_add_one_port() failed; err=%i\n", rc);
goto err_out_pm_disable;
}
return 0;
err_out_pm_disable:
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
pm_runtime_dont_use_autosuspend(&pdev->dev);
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
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
pm_runtime_dont_use_autosuspend(&pdev->dev);
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
