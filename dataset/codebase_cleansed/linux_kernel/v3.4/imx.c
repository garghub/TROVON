static inline unsigned uts_reg(struct imx_port *sport)
{
return sport->devdata->uts_reg;
}
static inline int is_imx1_uart(struct imx_port *sport)
{
return sport->devdata->devtype == IMX1_UART;
}
static inline int is_imx21_uart(struct imx_port *sport)
{
return sport->devdata->devtype == IMX21_UART;
}
static void imx_port_ucrs_save(struct uart_port *port,
struct imx_port_ucrs *ucr)
{
ucr->ucr1 = readl(port->membase + UCR1);
ucr->ucr2 = readl(port->membase + UCR2);
ucr->ucr3 = readl(port->membase + UCR3);
}
static void imx_port_ucrs_restore(struct uart_port *port,
struct imx_port_ucrs *ucr)
{
writel(ucr->ucr1, port->membase + UCR1);
writel(ucr->ucr2, port->membase + UCR2);
writel(ucr->ucr3, port->membase + UCR3);
}
static void imx_mctrl_check(struct imx_port *sport)
{
unsigned int status, changed;
status = sport->port.ops->get_mctrl(&sport->port);
changed = status ^ sport->old_status;
if (changed == 0)
return;
sport->old_status = status;
if (changed & TIOCM_RI)
sport->port.icount.rng++;
if (changed & TIOCM_DSR)
sport->port.icount.dsr++;
if (changed & TIOCM_CAR)
uart_handle_dcd_change(&sport->port, status & TIOCM_CAR);
if (changed & TIOCM_CTS)
uart_handle_cts_change(&sport->port, status & TIOCM_CTS);
wake_up_interruptible(&sport->port.state->port.delta_msr_wait);
}
static void imx_timeout(unsigned long data)
{
struct imx_port *sport = (struct imx_port *)data;
unsigned long flags;
if (sport->port.state) {
spin_lock_irqsave(&sport->port.lock, flags);
imx_mctrl_check(sport);
spin_unlock_irqrestore(&sport->port.lock, flags);
mod_timer(&sport->timer, jiffies + MCTRL_TIMEOUT);
}
}
static void imx_stop_tx(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
if (USE_IRDA(sport)) {
int n = 256;
while ((--n > 0) &&
!(readl(sport->port.membase + USR2) & USR2_TXDC)) {
udelay(5);
barrier();
}
udelay(sport->trcv_delay);
if (readl(sport->port.membase + USR2) & USR2_TXDC) {
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_TXMPTYEN | UCR1_TRDYEN);
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR4);
temp &= ~(UCR4_TCEN);
writel(temp, sport->port.membase + UCR4);
while (readl(sport->port.membase + URXD0) &
URXD_CHARRDY)
barrier();
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_RRDYEN;
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR4);
temp |= UCR4_DREN;
writel(temp, sport->port.membase + UCR4);
}
return;
}
temp = readl(sport->port.membase + UCR1);
writel(temp & ~UCR1_TXMPTYEN, sport->port.membase + UCR1);
}
static void imx_stop_rx(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
temp = readl(sport->port.membase + UCR2);
writel(temp &~ UCR2_RXEN, sport->port.membase + UCR2);
}
static void imx_enable_ms(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
mod_timer(&sport->timer, jiffies);
}
static inline void imx_transmit_buffer(struct imx_port *sport)
{
struct circ_buf *xmit = &sport->port.state->xmit;
while (!uart_circ_empty(xmit) &&
!(readl(sport->port.membase + uts_reg(sport))
& UTS_TXFULL)) {
writel(xmit->buf[xmit->tail], sport->port.membase + URTX0);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
sport->port.icount.tx++;
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
if (uart_circ_empty(xmit))
imx_stop_tx(&sport->port);
}
static void imx_start_tx(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
if (USE_IRDA(sport)) {
temp = readl(sport->port.membase + UCR4);
temp &= ~(UCR4_DREN);
writel(temp, sport->port.membase + UCR4);
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_RRDYEN);
writel(temp, sport->port.membase + UCR1);
}
temp = readl(sport->port.membase + UCR1);
writel(temp | UCR1_TXMPTYEN, sport->port.membase + UCR1);
if (USE_IRDA(sport)) {
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_TRDYEN;
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR4);
temp |= UCR4_TCEN;
writel(temp, sport->port.membase + UCR4);
}
if (readl(sport->port.membase + uts_reg(sport)) & UTS_TXEMPTY)
imx_transmit_buffer(sport);
}
static irqreturn_t imx_rtsint(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
unsigned int val;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock, flags);
writel(USR1_RTSD, sport->port.membase + USR1);
val = readl(sport->port.membase + USR1) & USR1_RTSS;
uart_handle_cts_change(&sport->port, !!val);
wake_up_interruptible(&sport->port.state->port.delta_msr_wait);
spin_unlock_irqrestore(&sport->port.lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t imx_txint(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
struct circ_buf *xmit = &sport->port.state->xmit;
unsigned long flags;
spin_lock_irqsave(&sport->port.lock,flags);
if (sport->port.x_char)
{
writel(sport->port.x_char, sport->port.membase + URTX0);
goto out;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&sport->port)) {
imx_stop_tx(&sport->port);
goto out;
}
imx_transmit_buffer(sport);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&sport->port);
out:
spin_unlock_irqrestore(&sport->port.lock,flags);
return IRQ_HANDLED;
}
static irqreturn_t imx_rxint(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
unsigned int rx,flg,ignored = 0;
struct tty_struct *tty = sport->port.state->port.tty;
unsigned long flags, temp;
spin_lock_irqsave(&sport->port.lock,flags);
while (readl(sport->port.membase + USR2) & USR2_RDR) {
flg = TTY_NORMAL;
sport->port.icount.rx++;
rx = readl(sport->port.membase + URXD0);
temp = readl(sport->port.membase + USR2);
if (temp & USR2_BRCD) {
writel(USR2_BRCD, sport->port.membase + USR2);
if (uart_handle_break(&sport->port))
continue;
}
if (uart_handle_sysrq_char(&sport->port, (unsigned char)rx))
continue;
if (unlikely(rx & URXD_ERR)) {
if (rx & URXD_BRK)
sport->port.icount.brk++;
else if (rx & URXD_PRERR)
sport->port.icount.parity++;
else if (rx & URXD_FRMERR)
sport->port.icount.frame++;
if (rx & URXD_OVRRUN)
sport->port.icount.overrun++;
if (rx & sport->port.ignore_status_mask) {
if (++ignored > 100)
goto out;
continue;
}
rx &= sport->port.read_status_mask;
if (rx & URXD_BRK)
flg = TTY_BREAK;
else if (rx & URXD_PRERR)
flg = TTY_PARITY;
else if (rx & URXD_FRMERR)
flg = TTY_FRAME;
if (rx & URXD_OVRRUN)
flg = TTY_OVERRUN;
#ifdef SUPPORT_SYSRQ
sport->port.sysrq = 0;
#endif
}
tty_insert_flip_char(tty, rx, flg);
}
out:
spin_unlock_irqrestore(&sport->port.lock,flags);
tty_flip_buffer_push(tty);
return IRQ_HANDLED;
}
static irqreturn_t imx_int(int irq, void *dev_id)
{
struct imx_port *sport = dev_id;
unsigned int sts;
sts = readl(sport->port.membase + USR1);
if (sts & USR1_RRDY)
imx_rxint(irq, dev_id);
if (sts & USR1_TRDY &&
readl(sport->port.membase + UCR1) & UCR1_TXMPTYEN)
imx_txint(irq, dev_id);
if (sts & USR1_RTSD)
imx_rtsint(irq, dev_id);
if (sts & USR1_AWAKE)
writel(USR1_AWAKE, sport->port.membase + USR1);
return IRQ_HANDLED;
}
static unsigned int imx_tx_empty(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
return (readl(sport->port.membase + USR2) & USR2_TXDC) ? TIOCSER_TEMT : 0;
}
static unsigned int imx_get_mctrl(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned int tmp = TIOCM_DSR | TIOCM_CAR;
if (readl(sport->port.membase + USR1) & USR1_RTSS)
tmp |= TIOCM_CTS;
if (readl(sport->port.membase + UCR2) & UCR2_CTS)
tmp |= TIOCM_RTS;
return tmp;
}
static void imx_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
temp = readl(sport->port.membase + UCR2) & ~UCR2_CTS;
if (mctrl & TIOCM_RTS)
temp |= UCR2_CTS;
writel(temp, sport->port.membase + UCR2);
}
static void imx_break_ctl(struct uart_port *port, int break_state)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long flags, temp;
spin_lock_irqsave(&sport->port.lock, flags);
temp = readl(sport->port.membase + UCR1) & ~UCR1_SNDBRK;
if ( break_state != 0 )
temp |= UCR1_SNDBRK;
writel(temp, sport->port.membase + UCR1);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static int imx_setup_ufcr(struct imx_port *sport, unsigned int mode)
{
unsigned int val;
unsigned int ufcr_rfdiv;
val = TXTL << 10 | RXTL;
ufcr_rfdiv = (clk_get_rate(sport->clk) + sport->port.uartclk / 2)
/ sport->port.uartclk;
if(!ufcr_rfdiv)
ufcr_rfdiv = 1;
val |= UFCR_RFDIV_REG(ufcr_rfdiv);
writel(val, sport->port.membase + UFCR);
return 0;
}
static int imx_startup(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
int retval;
unsigned long flags, temp;
imx_setup_ufcr(sport, 0);
temp = readl(sport->port.membase + UCR4);
if (USE_IRDA(sport))
temp |= UCR4_IRSC;
temp &= ~(UCR4_CTSTL_MASK<< UCR4_CTSTL_SHF);
temp |= CTSTL<< UCR4_CTSTL_SHF;
writel(temp & ~UCR4_DREN, sport->port.membase + UCR4);
if (USE_IRDA(sport)) {
int i = 100;
temp = readl(sport->port.membase + UCR2);
temp &= ~UCR2_SRST;
writel(temp, sport->port.membase + UCR2);
while (!(readl(sport->port.membase + UCR2) & UCR2_SRST) &&
(--i > 0)) {
udelay(1);
}
}
if (sport->txirq > 0) {
retval = request_irq(sport->rxirq, imx_rxint, 0,
DRIVER_NAME, sport);
if (retval)
goto error_out1;
retval = request_irq(sport->txirq, imx_txint, 0,
DRIVER_NAME, sport);
if (retval)
goto error_out2;
if (!USE_IRDA(sport)) {
retval = request_irq(sport->rtsirq, imx_rtsint,
(sport->rtsirq < MAX_INTERNAL_IRQ) ? 0 :
IRQF_TRIGGER_FALLING |
IRQF_TRIGGER_RISING,
DRIVER_NAME, sport);
if (retval)
goto error_out3;
}
} else {
retval = request_irq(sport->port.irq, imx_int, 0,
DRIVER_NAME, sport);
if (retval) {
free_irq(sport->port.irq, sport);
goto error_out1;
}
}
writel(USR1_RTSD, sport->port.membase + USR1);
temp = readl(sport->port.membase + UCR1);
temp |= UCR1_RRDYEN | UCR1_RTSDEN | UCR1_UARTEN;
if (USE_IRDA(sport)) {
temp |= UCR1_IREN;
temp &= ~(UCR1_RTSDEN);
}
writel(temp, sport->port.membase + UCR1);
temp = readl(sport->port.membase + UCR2);
temp |= (UCR2_RXEN | UCR2_TXEN);
writel(temp, sport->port.membase + UCR2);
if (USE_IRDA(sport)) {
int i = 64;
while ((--i > 0) &&
(readl(sport->port.membase + URXD0) & URXD_CHARRDY)) {
barrier();
}
}
if (is_imx21_uart(sport)) {
temp = readl(sport->port.membase + UCR3);
temp |= IMX21_UCR3_RXDMUXSEL;
writel(temp, sport->port.membase + UCR3);
}
if (USE_IRDA(sport)) {
temp = readl(sport->port.membase + UCR4);
if (sport->irda_inv_rx)
temp |= UCR4_INVR;
else
temp &= ~(UCR4_INVR);
writel(temp | UCR4_DREN, sport->port.membase + UCR4);
temp = readl(sport->port.membase + UCR3);
if (sport->irda_inv_tx)
temp |= UCR3_INVT;
else
temp &= ~(UCR3_INVT);
writel(temp, sport->port.membase + UCR3);
}
spin_lock_irqsave(&sport->port.lock,flags);
imx_enable_ms(&sport->port);
spin_unlock_irqrestore(&sport->port.lock,flags);
if (USE_IRDA(sport)) {
struct imxuart_platform_data *pdata;
pdata = sport->port.dev->platform_data;
sport->irda_inv_rx = pdata->irda_inv_rx;
sport->irda_inv_tx = pdata->irda_inv_tx;
sport->trcv_delay = pdata->transceiver_delay;
if (pdata->irda_enable)
pdata->irda_enable(1);
}
return 0;
error_out3:
if (sport->txirq)
free_irq(sport->txirq, sport);
error_out2:
if (sport->rxirq)
free_irq(sport->rxirq, sport);
error_out1:
return retval;
}
static void imx_shutdown(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long temp;
temp = readl(sport->port.membase + UCR2);
temp &= ~(UCR2_TXEN);
writel(temp, sport->port.membase + UCR2);
if (USE_IRDA(sport)) {
struct imxuart_platform_data *pdata;
pdata = sport->port.dev->platform_data;
if (pdata->irda_enable)
pdata->irda_enable(0);
}
del_timer_sync(&sport->timer);
if (sport->txirq > 0) {
if (!USE_IRDA(sport))
free_irq(sport->rtsirq, sport);
free_irq(sport->txirq, sport);
free_irq(sport->rxirq, sport);
} else
free_irq(sport->port.irq, sport);
temp = readl(sport->port.membase + UCR1);
temp &= ~(UCR1_TXMPTYEN | UCR1_RRDYEN | UCR1_RTSDEN | UCR1_UARTEN);
if (USE_IRDA(sport))
temp &= ~(UCR1_IREN);
writel(temp, sport->port.membase + UCR1);
}
static void
imx_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct imx_port *sport = (struct imx_port *)port;
unsigned long flags;
unsigned int ucr2, old_ucr1, old_txrxen, baud, quot;
unsigned int old_csize = old ? old->c_cflag & CSIZE : CS8;
unsigned int div, ufcr;
unsigned long num, denom;
uint64_t tdiv64;
if (0) {
termios->c_cflag &= ~(HUPCL | CRTSCTS | CMSPAR);
termios->c_cflag |= CLOCAL;
}
while ((termios->c_cflag & CSIZE) != CS7 &&
(termios->c_cflag & CSIZE) != CS8) {
termios->c_cflag &= ~CSIZE;
termios->c_cflag |= old_csize;
old_csize = CS8;
}
if ((termios->c_cflag & CSIZE) == CS8)
ucr2 = UCR2_WS | UCR2_SRST | UCR2_IRTS;
else
ucr2 = UCR2_SRST | UCR2_IRTS;
if (termios->c_cflag & CRTSCTS) {
if( sport->have_rtscts ) {
ucr2 &= ~UCR2_IRTS;
ucr2 |= UCR2_CTSC;
} else {
termios->c_cflag &= ~CRTSCTS;
}
}
if (termios->c_cflag & CSTOPB)
ucr2 |= UCR2_STPB;
if (termios->c_cflag & PARENB) {
ucr2 |= UCR2_PREN;
if (termios->c_cflag & PARODD)
ucr2 |= UCR2_PROE;
}
del_timer_sync(&sport->timer);
baud = uart_get_baud_rate(port, termios, old, 50, port->uartclk / 16);
quot = uart_get_divisor(port, baud);
spin_lock_irqsave(&sport->port.lock, flags);
sport->port.read_status_mask = 0;
if (termios->c_iflag & INPCK)
sport->port.read_status_mask |= (URXD_FRMERR | URXD_PRERR);
if (termios->c_iflag & (BRKINT | PARMRK))
sport->port.read_status_mask |= URXD_BRK;
sport->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= URXD_PRERR;
if (termios->c_iflag & IGNBRK) {
sport->port.ignore_status_mask |= URXD_BRK;
if (termios->c_iflag & IGNPAR)
sport->port.ignore_status_mask |= URXD_OVRRUN;
}
uart_update_timeout(port, termios->c_cflag, baud);
old_ucr1 = readl(sport->port.membase + UCR1);
writel(old_ucr1 & ~(UCR1_TXMPTYEN | UCR1_RRDYEN | UCR1_RTSDEN),
sport->port.membase + UCR1);
while ( !(readl(sport->port.membase + USR2) & USR2_TXDC))
barrier();
old_txrxen = readl(sport->port.membase + UCR2);
writel(old_txrxen & ~( UCR2_TXEN | UCR2_RXEN),
sport->port.membase + UCR2);
old_txrxen &= (UCR2_TXEN | UCR2_RXEN);
if (USE_IRDA(sport)) {
div = 1;
} else {
div = sport->port.uartclk / (baud * 16);
if (div > 7)
div = 7;
if (!div)
div = 1;
}
rational_best_approximation(16 * div * baud, sport->port.uartclk,
1 << 16, 1 << 16, &num, &denom);
tdiv64 = sport->port.uartclk;
tdiv64 *= num;
do_div(tdiv64, denom * 16 * div);
tty_termios_encode_baud_rate(termios,
(speed_t)tdiv64, (speed_t)tdiv64);
num -= 1;
denom -= 1;
ufcr = readl(sport->port.membase + UFCR);
ufcr = (ufcr & (~UFCR_RFDIV)) | UFCR_RFDIV_REG(div);
writel(ufcr, sport->port.membase + UFCR);
writel(num, sport->port.membase + UBIR);
writel(denom, sport->port.membase + UBMR);
if (is_imx21_uart(sport))
writel(sport->port.uartclk / div / 1000,
sport->port.membase + IMX21_ONEMS);
writel(old_ucr1, sport->port.membase + UCR1);
writel(ucr2 | old_txrxen, sport->port.membase + UCR2);
if (UART_ENABLE_MS(&sport->port, termios->c_cflag))
imx_enable_ms(&sport->port);
spin_unlock_irqrestore(&sport->port.lock, flags);
}
static const char *imx_type(struct uart_port *port)
{
struct imx_port *sport = (struct imx_port *)port;
return sport->port.type == PORT_IMX ? "IMX" : NULL;
}
static void imx_release_port(struct uart_port *port)
{
struct platform_device *pdev = to_platform_device(port->dev);
struct resource *mmres;
mmres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mmres->start, resource_size(mmres));
}
static int imx_request_port(struct uart_port *port)
{
struct platform_device *pdev = to_platform_device(port->dev);
struct resource *mmres;
void *ret;
mmres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mmres)
return -ENODEV;
ret = request_mem_region(mmres->start, resource_size(mmres), "imx-uart");
return ret ? 0 : -EBUSY;
}
static void imx_config_port(struct uart_port *port, int flags)
{
struct imx_port *sport = (struct imx_port *)port;
if (flags & UART_CONFIG_TYPE &&
imx_request_port(&sport->port) == 0)
sport->port.type = PORT_IMX;
}
static int
imx_verify_port(struct uart_port *port, struct serial_struct *ser)
{
struct imx_port *sport = (struct imx_port *)port;
int ret = 0;
if (ser->type != PORT_UNKNOWN && ser->type != PORT_IMX)
ret = -EINVAL;
if (sport->port.irq != ser->irq)
ret = -EINVAL;
if (ser->io_type != UPIO_MEM)
ret = -EINVAL;
if (sport->port.uartclk / 16 != ser->baud_base)
ret = -EINVAL;
if ((void *)sport->port.mapbase != ser->iomem_base)
ret = -EINVAL;
if (sport->port.iobase != ser->port)
ret = -EINVAL;
if (ser->hub6 != 0)
ret = -EINVAL;
return ret;
}
static int imx_poll_get_char(struct uart_port *port)
{
struct imx_port_ucrs old_ucr;
unsigned int status;
unsigned char c;
imx_port_ucrs_save(port, &old_ucr);
writel(UCR1_UARTEN, port->membase + UCR1);
writel(old_ucr.ucr2 & ~(UCR2_ATEN | UCR2_RTSEN | UCR2_ESCI),
port->membase + UCR2);
writel(old_ucr.ucr3 & ~(UCR3_DCD | UCR3_RI | UCR3_DTREN),
port->membase + UCR3);
do {
status = readl(port->membase + USR2);
} while (~status & USR2_RDR);
c = readl(port->membase + URXD0);
imx_port_ucrs_restore(port, &old_ucr);
return c;
}
static void imx_poll_put_char(struct uart_port *port, unsigned char c)
{
struct imx_port_ucrs old_ucr;
unsigned int status;
imx_port_ucrs_save(port, &old_ucr);
writel(UCR1_UARTEN, port->membase + UCR1);
writel(old_ucr.ucr2 & ~(UCR2_ATEN | UCR2_RTSEN | UCR2_ESCI),
port->membase + UCR2);
writel(old_ucr.ucr3 & ~(UCR3_DCD | UCR3_RI | UCR3_DTREN),
port->membase + UCR3);
do {
status = readl(port->membase + USR1);
} while (~status & USR1_TRDY);
writel(c, port->membase + URTX0);
do {
status = readl(port->membase + USR2);
} while (~status & USR2_TXDC);
imx_port_ucrs_restore(port, &old_ucr);
}
static void imx_console_putchar(struct uart_port *port, int ch)
{
struct imx_port *sport = (struct imx_port *)port;
while (readl(sport->port.membase + uts_reg(sport)) & UTS_TXFULL)
barrier();
writel(ch, sport->port.membase + URTX0);
}
static void
imx_console_write(struct console *co, const char *s, unsigned int count)
{
struct imx_port *sport = imx_ports[co->index];
struct imx_port_ucrs old_ucr;
unsigned int ucr1;
imx_port_ucrs_save(&sport->port, &old_ucr);
ucr1 = old_ucr.ucr1;
if (is_imx1_uart(sport))
ucr1 |= IMX1_UCR1_UARTCLKEN;
ucr1 |= UCR1_UARTEN;
ucr1 &= ~(UCR1_TXMPTYEN | UCR1_RRDYEN | UCR1_RTSDEN);
writel(ucr1, sport->port.membase + UCR1);
writel(old_ucr.ucr2 | UCR2_TXEN, sport->port.membase + UCR2);
uart_console_write(&sport->port, s, count, imx_console_putchar);
while (!(readl(sport->port.membase + USR2) & USR2_TXDC));
imx_port_ucrs_restore(&sport->port, &old_ucr);
}
static void __init
imx_console_get_options(struct imx_port *sport, int *baud,
int *parity, int *bits)
{
if (readl(sport->port.membase + UCR1) & UCR1_UARTEN) {
unsigned int ucr2, ubir,ubmr, uartclk;
unsigned int baud_raw;
unsigned int ucfr_rfdiv;
ucr2 = readl(sport->port.membase + UCR2);
*parity = 'n';
if (ucr2 & UCR2_PREN) {
if (ucr2 & UCR2_PROE)
*parity = 'o';
else
*parity = 'e';
}
if (ucr2 & UCR2_WS)
*bits = 8;
else
*bits = 7;
ubir = readl(sport->port.membase + UBIR) & 0xffff;
ubmr = readl(sport->port.membase + UBMR) & 0xffff;
ucfr_rfdiv = (readl(sport->port.membase + UFCR) & UFCR_RFDIV) >> 7;
if (ucfr_rfdiv == 6)
ucfr_rfdiv = 7;
else
ucfr_rfdiv = 6 - ucfr_rfdiv;
uartclk = clk_get_rate(sport->clk);
uartclk /= ucfr_rfdiv;
{
unsigned int mul = ubir + 1;
unsigned int div = 16 * (ubmr + 1);
unsigned int rem = uartclk % div;
baud_raw = (uartclk / div) * mul;
baud_raw += (rem * mul + div / 2) / div;
*baud = (baud_raw + 50) / 100 * 100;
}
if(*baud != baud_raw)
printk(KERN_INFO "Serial: Console IMX rounded baud rate from %d to %d\n",
baud_raw, *baud);
}
}
static int __init
imx_console_setup(struct console *co, char *options)
{
struct imx_port *sport;
int baud = 9600;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (co->index == -1 || co->index >= ARRAY_SIZE(imx_ports))
co->index = 0;
sport = imx_ports[co->index];
if(sport == NULL)
return -ENODEV;
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
else
imx_console_get_options(sport, &baud, &parity, &bits);
imx_setup_ufcr(sport, 0);
return uart_set_options(&sport->port, co, baud, parity, bits, flow);
}
static int serial_imx_suspend(struct platform_device *dev, pm_message_t state)
{
struct imx_port *sport = platform_get_drvdata(dev);
unsigned int val;
val = readl(sport->port.membase + UCR3);
val |= UCR3_AWAKEN;
writel(val, sport->port.membase + UCR3);
if (sport)
uart_suspend_port(&imx_reg, &sport->port);
return 0;
}
static int serial_imx_resume(struct platform_device *dev)
{
struct imx_port *sport = platform_get_drvdata(dev);
unsigned int val;
val = readl(sport->port.membase + UCR3);
val &= ~UCR3_AWAKEN;
writel(val, sport->port.membase + UCR3);
if (sport)
uart_resume_port(&imx_reg, &sport->port);
return 0;
}
static int serial_imx_probe_dt(struct imx_port *sport,
struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id =
of_match_device(imx_uart_dt_ids, &pdev->dev);
int ret;
if (!np)
return 1;
ret = of_alias_get_id(np, "serial");
if (ret < 0) {
dev_err(&pdev->dev, "failed to get alias id, errno %d\n", ret);
return ret;
}
sport->port.line = ret;
if (of_get_property(np, "fsl,uart-has-rtscts", NULL))
sport->have_rtscts = 1;
if (of_get_property(np, "fsl,irda-mode", NULL))
sport->use_irda = 1;
sport->devdata = of_id->data;
return 0;
}
static inline int serial_imx_probe_dt(struct imx_port *sport,
struct platform_device *pdev)
{
return 1;
}
static void serial_imx_probe_pdata(struct imx_port *sport,
struct platform_device *pdev)
{
struct imxuart_platform_data *pdata = pdev->dev.platform_data;
sport->port.line = pdev->id;
sport->devdata = (struct imx_uart_data *) pdev->id_entry->driver_data;
if (!pdata)
return;
if (pdata->flags & IMXUART_HAVE_RTSCTS)
sport->have_rtscts = 1;
if (pdata->flags & IMXUART_IRDA)
sport->use_irda = 1;
}
static int serial_imx_probe(struct platform_device *pdev)
{
struct imx_port *sport;
struct imxuart_platform_data *pdata;
void __iomem *base;
int ret = 0;
struct resource *res;
sport = kzalloc(sizeof(*sport), GFP_KERNEL);
if (!sport)
return -ENOMEM;
ret = serial_imx_probe_dt(sport, pdev);
if (ret > 0)
serial_imx_probe_pdata(sport, pdev);
else if (ret < 0)
goto free;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENODEV;
goto free;
}
base = ioremap(res->start, PAGE_SIZE);
if (!base) {
ret = -ENOMEM;
goto free;
}
sport->port.dev = &pdev->dev;
sport->port.mapbase = res->start;
sport->port.membase = base;
sport->port.type = PORT_IMX,
sport->port.iotype = UPIO_MEM;
sport->port.irq = platform_get_irq(pdev, 0);
sport->rxirq = platform_get_irq(pdev, 0);
sport->txirq = platform_get_irq(pdev, 1);
sport->rtsirq = platform_get_irq(pdev, 2);
sport->port.fifosize = 32;
sport->port.ops = &imx_pops;
sport->port.flags = UPF_BOOT_AUTOCONF;
init_timer(&sport->timer);
sport->timer.function = imx_timeout;
sport->timer.data = (unsigned long)sport;
sport->clk = clk_get(&pdev->dev, "uart");
if (IS_ERR(sport->clk)) {
ret = PTR_ERR(sport->clk);
goto unmap;
}
clk_prepare_enable(sport->clk);
sport->port.uartclk = clk_get_rate(sport->clk);
imx_ports[sport->port.line] = sport;
pdata = pdev->dev.platform_data;
if (pdata && pdata->init) {
ret = pdata->init(pdev);
if (ret)
goto clkput;
}
ret = uart_add_one_port(&imx_reg, &sport->port);
if (ret)
goto deinit;
platform_set_drvdata(pdev, &sport->port);
return 0;
deinit:
if (pdata && pdata->exit)
pdata->exit(pdev);
clkput:
clk_disable_unprepare(sport->clk);
clk_put(sport->clk);
unmap:
iounmap(sport->port.membase);
free:
kfree(sport);
return ret;
}
static int serial_imx_remove(struct platform_device *pdev)
{
struct imxuart_platform_data *pdata;
struct imx_port *sport = platform_get_drvdata(pdev);
pdata = pdev->dev.platform_data;
platform_set_drvdata(pdev, NULL);
if (sport) {
uart_remove_one_port(&imx_reg, &sport->port);
clk_disable_unprepare(sport->clk);
clk_put(sport->clk);
}
if (pdata && pdata->exit)
pdata->exit(pdev);
iounmap(sport->port.membase);
kfree(sport);
return 0;
}
static int __init imx_serial_init(void)
{
int ret;
printk(KERN_INFO "Serial: IMX driver\n");
ret = uart_register_driver(&imx_reg);
if (ret)
return ret;
ret = platform_driver_register(&serial_imx_driver);
if (ret != 0)
uart_unregister_driver(&imx_reg);
return ret;
}
static void __exit imx_serial_exit(void)
{
platform_driver_unregister(&serial_imx_driver);
uart_unregister_driver(&imx_reg);
}
