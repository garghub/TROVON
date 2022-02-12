static u32 uart_read(struct uart_8250_port *up, u32 reg)
{
return readl(up->port.membase + (reg << up->port.regshift));
}
static void omap8250_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_8250_port *up = up_to_u8250p(port);
struct omap8250_priv *priv = up->port.private_data;
u8 lcr;
serial8250_do_set_mctrl(port, mctrl);
lcr = serial_in(up, UART_LCR);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
if ((mctrl & TIOCM_RTS) && (port->status & UPSTAT_AUTORTS))
priv->efr |= UART_EFR_RTS;
else
priv->efr &= ~UART_EFR_RTS;
serial_out(up, UART_EFR, priv->efr);
serial_out(up, UART_LCR, lcr);
}
static void omap_8250_mdr1_errataset(struct uart_8250_port *up,
struct omap8250_priv *priv)
{
u8 timeout = 255;
u8 old_mdr1;
old_mdr1 = serial_in(up, UART_OMAP_MDR1);
if (old_mdr1 == priv->mdr1)
return;
serial_out(up, UART_OMAP_MDR1, priv->mdr1);
udelay(2);
serial_out(up, UART_FCR, up->fcr | UART_FCR_CLEAR_XMIT |
UART_FCR_CLEAR_RCVR);
while (UART_LSR_THRE != (serial_in(up, UART_LSR) &
(UART_LSR_THRE | UART_LSR_DR))) {
timeout--;
if (!timeout) {
dev_crit(up->port.dev, "Errata i202: timedout %x\n",
serial_in(up, UART_LSR));
break;
}
udelay(1);
}
}
static void omap_8250_get_divisor(struct uart_port *port, unsigned int baud,
struct omap8250_priv *priv)
{
unsigned int uartclk = port->uartclk;
unsigned int div_13, div_16;
unsigned int abs_d13, abs_d16;
if (baud == 38400 && (port->flags & UPF_SPD_MASK) == UPF_SPD_CUST) {
priv->quot = port->custom_divisor & 0xffff;
if (port->custom_divisor & (1 << 16))
priv->mdr1 = UART_OMAP_MDR1_13X_MODE;
else
priv->mdr1 = UART_OMAP_MDR1_16X_MODE;
return;
}
div_13 = DIV_ROUND_CLOSEST(uartclk, 13 * baud);
div_16 = DIV_ROUND_CLOSEST(uartclk, 16 * baud);
if (!div_13)
div_13 = 1;
if (!div_16)
div_16 = 1;
abs_d13 = abs(baud - uartclk / 13 / div_13);
abs_d16 = abs(baud - uartclk / 16 / div_16);
if (abs_d13 >= abs_d16) {
priv->mdr1 = UART_OMAP_MDR1_16X_MODE;
priv->quot = div_16;
} else {
priv->mdr1 = UART_OMAP_MDR1_13X_MODE;
priv->quot = div_13;
}
}
static void omap8250_update_scr(struct uart_8250_port *up,
struct omap8250_priv *priv)
{
u8 old_scr;
old_scr = serial_in(up, UART_OMAP_SCR);
if (old_scr == priv->scr)
return;
if (priv->scr & OMAP_UART_SCR_DMAMODE_MASK)
serial_out(up, UART_OMAP_SCR,
priv->scr & ~OMAP_UART_SCR_DMAMODE_MASK);
serial_out(up, UART_OMAP_SCR, priv->scr);
}
static void omap8250_update_mdr1(struct uart_8250_port *up,
struct omap8250_priv *priv)
{
if (priv->habit & UART_ERRATA_i202_MDR1_ACCESS)
omap_8250_mdr1_errataset(up, priv);
else
serial_out(up, UART_OMAP_MDR1, priv->mdr1);
}
static void omap8250_restore_regs(struct uart_8250_port *up)
{
struct omap8250_priv *priv = up->port.private_data;
struct uart_8250_dma *dma = up->dma;
if (dma && dma->tx_running) {
priv->delayed_restore = 1;
return;
}
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, UART_EFR_ECB);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_MCR, UART_MCR_TCRTLR);
serial_out(up, UART_FCR, up->fcr);
omap8250_update_scr(up, priv);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_TI752_TCR, OMAP_UART_TCR_RESTORE(16) |
OMAP_UART_TCR_HALT(52));
serial_out(up, UART_TI752_TLR,
TRIGGER_TLR_MASK(TX_TRIGGER) << UART_TI752_TLR_TX |
TRIGGER_TLR_MASK(RX_TRIGGER) << UART_TI752_TLR_RX);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_MCR, up->mcr);
serial_out(up, UART_IER, up->ier);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_dl_write(up, priv->quot);
serial_out(up, UART_EFR, priv->efr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_XON1, priv->xon);
serial_out(up, UART_XOFF1, priv->xoff);
serial_out(up, UART_LCR, up->lcr);
omap8250_update_mdr1(up, priv);
up->port.ops->set_mctrl(&up->port, up->port.mctrl);
}
static void omap_8250_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
struct omap8250_priv *priv = up->port.private_data;
unsigned char cval = 0;
unsigned int baud;
switch (termios->c_cflag & CSIZE) {
case CS5:
cval = UART_LCR_WLEN5;
break;
case CS6:
cval = UART_LCR_WLEN6;
break;
case CS7:
cval = UART_LCR_WLEN7;
break;
default:
case CS8:
cval = UART_LCR_WLEN8;
break;
}
if (termios->c_cflag & CSTOPB)
cval |= UART_LCR_STOP;
if (termios->c_cflag & PARENB)
cval |= UART_LCR_PARITY;
if (!(termios->c_cflag & PARODD))
cval |= UART_LCR_EPAR;
if (termios->c_cflag & CMSPAR)
cval |= UART_LCR_SPAR;
baud = uart_get_baud_rate(port, termios, old,
port->uartclk / 16 / 0xffff,
port->uartclk / 13);
omap_8250_get_divisor(port, baud, priv);
pm_runtime_get_sync(port->dev);
spin_lock_irq(&port->lock);
uart_update_timeout(port, termios->c_cflag, baud);
up->port.read_status_mask = UART_LSR_OE | UART_LSR_THRE | UART_LSR_DR;
if (termios->c_iflag & INPCK)
up->port.read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (termios->c_iflag & (IGNBRK | PARMRK))
up->port.read_status_mask |= UART_LSR_BI;
up->port.ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_PE | UART_LSR_FE;
if (termios->c_iflag & IGNBRK) {
up->port.ignore_status_mask |= UART_LSR_BI;
if (termios->c_iflag & IGNPAR)
up->port.ignore_status_mask |= UART_LSR_OE;
}
if ((termios->c_cflag & CREAD) == 0)
up->port.ignore_status_mask |= UART_LSR_DR;
up->ier &= ~UART_IER_MSI;
if (UART_ENABLE_MS(&up->port, termios->c_cflag))
up->ier |= UART_IER_MSI;
up->lcr = cval;
up->fcr = UART_FCR_ENABLE_FIFO;
up->fcr |= TRIGGER_FCR_MASK(TX_TRIGGER) << OMAP_UART_FCR_TX_TRIG;
up->fcr |= TRIGGER_FCR_MASK(RX_TRIGGER) << OMAP_UART_FCR_RX_TRIG;
priv->scr = OMAP_UART_SCR_RX_TRIG_GRANU1_MASK | OMAP_UART_SCR_TX_EMPTY |
OMAP_UART_SCR_TX_TRIG_GRANU1_MASK;
if (up->dma)
priv->scr |= OMAP_UART_SCR_DMAMODE_1 |
OMAP_UART_SCR_DMAMODE_CTL;
priv->xon = termios->c_cc[VSTART];
priv->xoff = termios->c_cc[VSTOP];
priv->efr = 0;
up->mcr &= ~(UART_MCR_RTS | UART_MCR_XONANY);
up->port.status &= ~(UPSTAT_AUTOCTS | UPSTAT_AUTORTS | UPSTAT_AUTOXOFF);
if (termios->c_cflag & CRTSCTS && up->port.flags & UPF_HARD_FLOW) {
up->port.status |= UPSTAT_AUTOCTS | UPSTAT_AUTORTS;
priv->efr |= UART_EFR_CTS;
} else if (up->port.flags & UPF_SOFT_FLOW) {
if (termios->c_iflag & IXOFF) {
up->port.status |= UPSTAT_AUTOXOFF;
priv->efr |= OMAP_UART_SW_TX;
}
}
omap8250_restore_regs(up);
spin_unlock_irq(&up->port.lock);
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
priv->calc_latency = USEC_PER_SEC * 64 * 8 / baud;
priv->latency = priv->calc_latency;
schedule_work(&priv->qos_work);
if (tty_termios_baud_rate(termios))
tty_termios_encode_baud_rate(termios, baud, baud);
}
static void omap_8250_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct uart_8250_port *up = up_to_u8250p(port);
u8 efr;
pm_runtime_get_sync(port->dev);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
efr = serial_in(up, UART_EFR);
serial_out(up, UART_EFR, efr | UART_EFR_ECB);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_IER, (state != 0) ? UART_IERX_SLEEP : 0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, efr);
serial_out(up, UART_LCR, 0);
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
}
static void omap_serial_fill_features_erratas(struct uart_8250_port *up,
struct omap8250_priv *priv)
{
u32 mvr, scheme;
u16 revision, major, minor;
mvr = uart_read(up, UART_OMAP_MVER);
scheme = mvr >> OMAP_UART_MVR_SCHEME_SHIFT;
switch (scheme) {
case 0:
major = (mvr & OMAP_UART_LEGACY_MVR_MAJ_MASK) >>
OMAP_UART_LEGACY_MVR_MAJ_SHIFT;
minor = (mvr & OMAP_UART_LEGACY_MVR_MIN_MASK);
break;
case 1:
major = (mvr & OMAP_UART_MVR_MAJ_MASK) >>
OMAP_UART_MVR_MAJ_SHIFT;
minor = (mvr & OMAP_UART_MVR_MIN_MASK);
break;
default:
dev_warn(up->port.dev,
"Unknown revision, defaulting to highest\n");
major = 0xff;
minor = 0xff;
}
revision = UART_BUILD_REVISION(major, minor);
switch (revision) {
case OMAP_UART_REV_46:
priv->habit |= UART_ERRATA_i202_MDR1_ACCESS;
break;
case OMAP_UART_REV_52:
priv->habit |= UART_ERRATA_i202_MDR1_ACCESS |
OMAP_UART_WER_HAS_TX_WAKEUP;
break;
case OMAP_UART_REV_63:
priv->habit |= UART_ERRATA_i202_MDR1_ACCESS |
OMAP_UART_WER_HAS_TX_WAKEUP;
break;
default:
break;
}
}
static void omap8250_uart_qos_work(struct work_struct *work)
{
struct omap8250_priv *priv;
priv = container_of(work, struct omap8250_priv, qos_work);
pm_qos_update_request(&priv->pm_qos_request, priv->latency);
}
static irqreturn_t omap8250_irq(int irq, void *dev_id)
{
struct uart_port *port = dev_id;
struct uart_8250_port *up = up_to_u8250p(port);
unsigned int iir;
int ret;
#ifdef CONFIG_SERIAL_8250_DMA
if (up->dma) {
ret = omap_8250_dma_handle_irq(port);
return IRQ_RETVAL(ret);
}
#endif
serial8250_rpm_get(up);
iir = serial_port_in(port, UART_IIR);
ret = serial8250_handle_irq(port, iir);
serial8250_rpm_put(up);
return IRQ_RETVAL(ret);
}
static int omap_8250_startup(struct uart_port *port)
{
struct uart_8250_port *up = up_to_u8250p(port);
struct omap8250_priv *priv = port->private_data;
int ret;
if (priv->wakeirq) {
ret = dev_pm_set_dedicated_wake_irq(port->dev, priv->wakeirq);
if (ret)
return ret;
}
pm_runtime_get_sync(port->dev);
up->mcr = 0;
serial_out(up, UART_FCR, UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
serial_out(up, UART_LCR, UART_LCR_WLEN8);
up->lsr_saved_flags = 0;
up->msr_saved_flags = 0;
if (up->dma) {
ret = serial8250_request_dma(up);
if (ret) {
dev_warn_ratelimited(port->dev,
"failed to request DMA\n");
up->dma = NULL;
}
}
ret = request_irq(port->irq, omap8250_irq, IRQF_SHARED,
dev_name(port->dev), port);
if (ret < 0)
goto err;
up->ier = UART_IER_RLSI | UART_IER_RDI;
serial_out(up, UART_IER, up->ier);
#ifdef CONFIG_PM
up->capabilities |= UART_CAP_RPM;
#endif
priv->wer = OMAP_UART_WER_MOD_WKUP;
if (priv->habit & OMAP_UART_WER_HAS_TX_WAKEUP)
priv->wer |= OMAP_UART_TX_WAKEUP_EN;
serial_out(up, UART_OMAP_WER, priv->wer);
if (up->dma)
up->dma->rx_dma(up, 0);
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
return 0;
err:
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
dev_pm_clear_wake_irq(port->dev);
return ret;
}
static void omap_8250_shutdown(struct uart_port *port)
{
struct uart_8250_port *up = up_to_u8250p(port);
struct omap8250_priv *priv = port->private_data;
flush_work(&priv->qos_work);
if (up->dma)
up->dma->rx_dma(up, UART_IIR_RX_TIMEOUT);
pm_runtime_get_sync(port->dev);
serial_out(up, UART_OMAP_WER, 0);
up->ier = 0;
serial_out(up, UART_IER, 0);
if (up->dma)
serial8250_release_dma(up);
if (up->lcr & UART_LCR_SBC)
serial_out(up, UART_LCR, up->lcr & ~UART_LCR_SBC);
serial_out(up, UART_FCR, UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
free_irq(port->irq, port);
dev_pm_clear_wake_irq(port->dev);
}
static void omap_8250_throttle(struct uart_port *port)
{
unsigned long flags;
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
pm_runtime_get_sync(port->dev);
spin_lock_irqsave(&port->lock, flags);
up->ier &= ~(UART_IER_RLSI | UART_IER_RDI);
serial_out(up, UART_IER, up->ier);
spin_unlock_irqrestore(&port->lock, flags);
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
}
static void omap_8250_unthrottle(struct uart_port *port)
{
unsigned long flags;
struct uart_8250_port *up =
container_of(port, struct uart_8250_port, port);
pm_runtime_get_sync(port->dev);
spin_lock_irqsave(&port->lock, flags);
up->ier |= UART_IER_RLSI | UART_IER_RDI;
serial_out(up, UART_IER, up->ier);
spin_unlock_irqrestore(&port->lock, flags);
pm_runtime_mark_last_busy(port->dev);
pm_runtime_put_autosuspend(port->dev);
}
static void __dma_rx_do_complete(struct uart_8250_port *p, bool error)
{
struct omap8250_priv *priv = p->port.private_data;
struct uart_8250_dma *dma = p->dma;
struct tty_port *tty_port = &p->port.state->port;
struct dma_tx_state state;
int count;
unsigned long flags;
dma_sync_single_for_cpu(dma->rxchan->device->dev, dma->rx_addr,
dma->rx_size, DMA_FROM_DEVICE);
spin_lock_irqsave(&priv->rx_dma_lock, flags);
if (!dma->rx_running)
goto unlock;
dma->rx_running = 0;
dmaengine_tx_status(dma->rxchan, dma->rx_cookie, &state);
dmaengine_terminate_all(dma->rxchan);
count = dma->rx_size - state.residue;
tty_insert_flip_string(tty_port, dma->rx_buf, count);
p->port.icount.rx += count;
unlock:
spin_unlock_irqrestore(&priv->rx_dma_lock, flags);
if (!error)
omap_8250_rx_dma(p, 0);
tty_flip_buffer_push(tty_port);
}
static void __dma_rx_complete(void *param)
{
__dma_rx_do_complete(param, false);
}
static void omap_8250_rx_dma_flush(struct uart_8250_port *p)
{
struct omap8250_priv *priv = p->port.private_data;
struct uart_8250_dma *dma = p->dma;
unsigned long flags;
int ret;
spin_lock_irqsave(&priv->rx_dma_lock, flags);
if (!dma->rx_running) {
spin_unlock_irqrestore(&priv->rx_dma_lock, flags);
return;
}
ret = dmaengine_pause(dma->rxchan);
if (WARN_ON_ONCE(ret))
priv->rx_dma_broken = true;
spin_unlock_irqrestore(&priv->rx_dma_lock, flags);
__dma_rx_do_complete(p, true);
}
static int omap_8250_rx_dma(struct uart_8250_port *p, unsigned int iir)
{
struct omap8250_priv *priv = p->port.private_data;
struct uart_8250_dma *dma = p->dma;
int err = 0;
struct dma_async_tx_descriptor *desc;
unsigned long flags;
switch (iir & 0x3f) {
case UART_IIR_RLSI:
omap_8250_rx_dma_flush(p);
return -EIO;
case UART_IIR_RX_TIMEOUT:
omap_8250_rx_dma_flush(p);
return -ETIMEDOUT;
case UART_IIR_RDI:
omap_8250_rx_dma_flush(p);
return -ETIMEDOUT;
default:
break;
}
if (priv->rx_dma_broken)
return -EINVAL;
spin_lock_irqsave(&priv->rx_dma_lock, flags);
if (dma->rx_running)
goto out;
desc = dmaengine_prep_slave_single(dma->rxchan, dma->rx_addr,
dma->rx_size, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
err = -EBUSY;
goto out;
}
dma->rx_running = 1;
desc->callback = __dma_rx_complete;
desc->callback_param = p;
dma->rx_cookie = dmaengine_submit(desc);
dma_sync_single_for_device(dma->rxchan->device->dev, dma->rx_addr,
dma->rx_size, DMA_FROM_DEVICE);
dma_async_issue_pending(dma->rxchan);
out:
spin_unlock_irqrestore(&priv->rx_dma_lock, flags);
return err;
}
static void omap_8250_dma_tx_complete(void *param)
{
struct uart_8250_port *p = param;
struct uart_8250_dma *dma = p->dma;
struct circ_buf *xmit = &p->port.state->xmit;
unsigned long flags;
bool en_thri = false;
struct omap8250_priv *priv = p->port.private_data;
dma_sync_single_for_cpu(dma->txchan->device->dev, dma->tx_addr,
UART_XMIT_SIZE, DMA_TO_DEVICE);
spin_lock_irqsave(&p->port.lock, flags);
dma->tx_running = 0;
xmit->tail += dma->tx_size;
xmit->tail &= UART_XMIT_SIZE - 1;
p->port.icount.tx += dma->tx_size;
if (priv->delayed_restore) {
priv->delayed_restore = 0;
omap8250_restore_regs(p);
}
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&p->port);
if (!uart_circ_empty(xmit) && !uart_tx_stopped(&p->port)) {
int ret;
ret = omap_8250_tx_dma(p);
if (ret)
en_thri = true;
} else if (p->capabilities & UART_CAP_RPM) {
en_thri = true;
}
if (en_thri) {
dma->tx_err = 1;
p->ier |= UART_IER_THRI;
serial_port_out(&p->port, UART_IER, p->ier);
}
spin_unlock_irqrestore(&p->port.lock, flags);
}
static int omap_8250_tx_dma(struct uart_8250_port *p)
{
struct uart_8250_dma *dma = p->dma;
struct omap8250_priv *priv = p->port.private_data;
struct circ_buf *xmit = &p->port.state->xmit;
struct dma_async_tx_descriptor *desc;
unsigned int skip_byte = 0;
int ret;
if (dma->tx_running)
return 0;
if (uart_tx_stopped(&p->port) || uart_circ_empty(xmit)) {
if (dma->tx_err || p->capabilities & UART_CAP_RPM) {
ret = -EBUSY;
goto err;
}
if (p->ier & UART_IER_THRI) {
p->ier &= ~UART_IER_THRI;
serial_out(p, UART_IER, p->ier);
}
return 0;
}
dma->tx_size = CIRC_CNT_TO_END(xmit->head, xmit->tail, UART_XMIT_SIZE);
if (priv->habit & OMAP_DMA_TX_KICK) {
u8 tx_lvl;
tx_lvl = serial_in(p, UART_OMAP_TX_LVL);
if (tx_lvl == p->tx_loadsz) {
ret = -EBUSY;
goto err;
}
if (dma->tx_size < 4) {
ret = -EINVAL;
goto err;
}
skip_byte = 1;
}
desc = dmaengine_prep_slave_single(dma->txchan,
dma->tx_addr + xmit->tail + skip_byte,
dma->tx_size - skip_byte, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
ret = -EBUSY;
goto err;
}
dma->tx_running = 1;
desc->callback = omap_8250_dma_tx_complete;
desc->callback_param = p;
dma->tx_cookie = dmaengine_submit(desc);
dma_sync_single_for_device(dma->txchan->device->dev, dma->tx_addr,
UART_XMIT_SIZE, DMA_TO_DEVICE);
dma_async_issue_pending(dma->txchan);
if (dma->tx_err)
dma->tx_err = 0;
if (p->ier & UART_IER_THRI) {
p->ier &= ~UART_IER_THRI;
serial_out(p, UART_IER, p->ier);
}
if (skip_byte)
serial_out(p, UART_TX, xmit->buf[xmit->tail]);
return 0;
err:
dma->tx_err = 1;
return ret;
}
static int omap_8250_dma_handle_irq(struct uart_port *port)
{
struct uart_8250_port *up = up_to_u8250p(port);
unsigned char status;
unsigned long flags;
u8 iir;
int dma_err = 0;
serial8250_rpm_get(up);
iir = serial_port_in(port, UART_IIR);
if (iir & UART_IIR_NO_INT) {
serial8250_rpm_put(up);
return 0;
}
spin_lock_irqsave(&port->lock, flags);
status = serial_port_in(port, UART_LSR);
if (status & (UART_LSR_DR | UART_LSR_BI)) {
dma_err = omap_8250_rx_dma(up, iir);
if (dma_err) {
status = serial8250_rx_chars(up, status);
omap_8250_rx_dma(up, 0);
}
}
serial8250_modem_status(up);
if (status & UART_LSR_THRE && up->dma->tx_err) {
if (uart_tx_stopped(&up->port) ||
uart_circ_empty(&up->port.state->xmit)) {
up->dma->tx_err = 0;
serial8250_tx_chars(up);
} else {
dma_err = omap_8250_tx_dma(up);
if (dma_err)
serial8250_tx_chars(up);
}
}
spin_unlock_irqrestore(&port->lock, flags);
serial8250_rpm_put(up);
return 1;
}
static bool the_no_dma_filter_fn(struct dma_chan *chan, void *param)
{
return false;
}
static inline int omap_8250_rx_dma(struct uart_8250_port *p, unsigned int iir)
{
return -EINVAL;
}
static int omap8250_no_handle_irq(struct uart_port *port)
{
WARN_ONCE(1, "Unexpected irq handling before port startup\n");
return 0;
}
static int omap8250_probe(struct platform_device *pdev)
{
struct resource *regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct resource *irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
struct omap8250_priv *priv;
struct uart_8250_port up;
int ret;
void __iomem *membase;
if (!regs || !irq) {
dev_err(&pdev->dev, "missing registers or irq\n");
return -EINVAL;
}
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
membase = devm_ioremap_nocache(&pdev->dev, regs->start,
resource_size(regs));
if (!membase)
return -ENODEV;
memset(&up, 0, sizeof(up));
up.port.dev = &pdev->dev;
up.port.mapbase = regs->start;
up.port.membase = membase;
up.port.irq = irq->start;
up.port.type = PORT_8250;
up.port.iotype = UPIO_MEM;
up.port.flags = UPF_FIXED_PORT | UPF_FIXED_TYPE | UPF_SOFT_FLOW |
UPF_HARD_FLOW;
up.port.private_data = priv;
up.port.regshift = 2;
up.port.fifosize = 64;
up.tx_loadsz = 64;
up.capabilities = UART_CAP_FIFO;
#ifdef CONFIG_PM
up.capabilities |= UART_CAP_RPM;
#endif
up.port.set_termios = omap_8250_set_termios;
up.port.set_mctrl = omap8250_set_mctrl;
up.port.pm = omap_8250_pm;
up.port.startup = omap_8250_startup;
up.port.shutdown = omap_8250_shutdown;
up.port.throttle = omap_8250_throttle;
up.port.unthrottle = omap_8250_unthrottle;
if (pdev->dev.of_node) {
const struct of_device_id *id;
ret = of_alias_get_id(pdev->dev.of_node, "serial");
of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&up.port.uartclk);
priv->wakeirq = irq_of_parse_and_map(pdev->dev.of_node, 1);
id = of_match_device(of_match_ptr(omap8250_dt_ids), &pdev->dev);
if (id && id->data)
priv->habit |= *(u8 *)id->data;
} else {
ret = pdev->id;
}
if (ret < 0) {
dev_err(&pdev->dev, "failed to get alias/pdev id\n");
return ret;
}
up.port.line = ret;
if (!up.port.uartclk) {
up.port.uartclk = DEFAULT_CLK_SPEED;
dev_warn(&pdev->dev,
"No clock speed specified: using default: %d\n",
DEFAULT_CLK_SPEED);
}
priv->latency = PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE;
priv->calc_latency = PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE;
pm_qos_add_request(&priv->pm_qos_request, PM_QOS_CPU_DMA_LATENCY,
priv->latency);
INIT_WORK(&priv->qos_work, omap8250_uart_qos_work);
spin_lock_init(&priv->rx_dma_lock);
device_init_wakeup(&pdev->dev, true);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, -1);
pm_runtime_irq_safe(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
omap_serial_fill_features_erratas(&up, priv);
up.port.handle_irq = omap8250_no_handle_irq;
#ifdef CONFIG_SERIAL_8250_DMA
if (pdev->dev.of_node) {
ret = of_property_count_strings(pdev->dev.of_node, "dma-names");
if (ret == 2) {
up.dma = &priv->omap8250_dma;
priv->omap8250_dma.fn = the_no_dma_filter_fn;
priv->omap8250_dma.tx_dma = omap_8250_tx_dma;
priv->omap8250_dma.rx_dma = omap_8250_rx_dma;
priv->omap8250_dma.rx_size = RX_TRIGGER;
priv->omap8250_dma.rxconf.src_maxburst = RX_TRIGGER;
priv->omap8250_dma.txconf.dst_maxburst = TX_TRIGGER;
if (of_machine_is_compatible("ti,am33xx"))
priv->habit |= OMAP_DMA_TX_KICK;
priv->rx_dma_broken = true;
}
}
#endif
ret = serial8250_register_8250_port(&up);
if (ret < 0) {
dev_err(&pdev->dev, "unable to register 8250 port\n");
goto err;
}
priv->line = ret;
platform_set_drvdata(pdev, priv);
pm_runtime_mark_last_busy(&pdev->dev);
pm_runtime_put_autosuspend(&pdev->dev);
return 0;
err:
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int omap8250_remove(struct platform_device *pdev)
{
struct omap8250_priv *priv = platform_get_drvdata(pdev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
serial8250_unregister_port(priv->line);
pm_qos_remove_request(&priv->pm_qos_request);
device_init_wakeup(&pdev->dev, false);
return 0;
}
static int omap8250_prepare(struct device *dev)
{
struct omap8250_priv *priv = dev_get_drvdata(dev);
if (!priv)
return 0;
priv->is_suspending = true;
return 0;
}
static void omap8250_complete(struct device *dev)
{
struct omap8250_priv *priv = dev_get_drvdata(dev);
if (!priv)
return;
priv->is_suspending = false;
}
static int omap8250_suspend(struct device *dev)
{
struct omap8250_priv *priv = dev_get_drvdata(dev);
serial8250_suspend_port(priv->line);
flush_work(&priv->qos_work);
return 0;
}
static int omap8250_resume(struct device *dev)
{
struct omap8250_priv *priv = dev_get_drvdata(dev);
serial8250_resume_port(priv->line);
return 0;
}
static int omap8250_lost_context(struct uart_8250_port *up)
{
u32 val;
val = serial_in(up, UART_OMAP_SCR);
if (!val)
return 1;
return 0;
}
static int omap8250_soft_reset(struct device *dev)
{
struct omap8250_priv *priv = dev_get_drvdata(dev);
struct uart_8250_port *up = serial8250_get_port(priv->line);
int timeout = 100;
int sysc;
int syss;
sysc = serial_in(up, UART_OMAP_SYSC);
sysc |= OMAP_UART_SYSC_SOFTRESET;
serial_out(up, UART_OMAP_SYSC, sysc);
do {
udelay(1);
syss = serial_in(up, UART_OMAP_SYSS);
} while (--timeout && !(syss & OMAP_UART_SYSS_RESETDONE));
if (!timeout) {
dev_err(dev, "timed out waiting for reset done\n");
return -ETIMEDOUT;
}
return 0;
}
static int omap8250_runtime_suspend(struct device *dev)
{
struct omap8250_priv *priv = dev_get_drvdata(dev);
struct uart_8250_port *up;
up = serial8250_get_port(priv->line);
if (priv->is_suspending && !console_suspend_enabled) {
if (uart_console(&up->port))
return -EBUSY;
}
if (priv->habit & UART_ERRATA_CLOCK_DISABLE) {
int ret;
ret = omap8250_soft_reset(dev);
if (ret)
return ret;
omap8250_update_mdr1(up, priv);
}
if (up->dma && up->dma->rxchan)
omap_8250_rx_dma(up, UART_IIR_RX_TIMEOUT);
priv->latency = PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE;
schedule_work(&priv->qos_work);
return 0;
}
static int omap8250_runtime_resume(struct device *dev)
{
struct omap8250_priv *priv = dev_get_drvdata(dev);
struct uart_8250_port *up;
int loss_cntx;
if (!priv)
return 0;
up = serial8250_get_port(priv->line);
loss_cntx = omap8250_lost_context(up);
if (loss_cntx)
omap8250_restore_regs(up);
if (up->dma && up->dma->rxchan)
omap_8250_rx_dma(up, 0);
priv->latency = priv->calc_latency;
schedule_work(&priv->qos_work);
return 0;
}
static int __init omap8250_console_fixup(void)
{
char *omap_str;
char *options;
u8 idx;
if (strstr(boot_command_line, "console=ttyS"))
return 0;
omap_str = strstr(boot_command_line, "console=ttyO");
if (!omap_str)
return 0;
omap_str += 12;
if ('0' <= *omap_str && *omap_str <= '9')
idx = *omap_str - '0';
else
return 0;
omap_str++;
if (omap_str[0] == ',') {
omap_str++;
options = omap_str;
} else {
options = NULL;
}
add_preferred_console("ttyS", idx, options);
pr_err("WARNING: Your 'console=ttyO%d' has been replaced by 'ttyS%d'\n",
idx, idx);
pr_err("This ensures that you still see kernel messages. Please\n");
pr_err("update your kernel commandline.\n");
return 0;
}
