static inline unsigned int serial_in(struct uart_omap_port *up, int offset)
{
offset <<= up->port.regshift;
return readw(up->port.membase + offset);
}
static inline void serial_out(struct uart_omap_port *up, int offset, int value)
{
offset <<= up->port.regshift;
writew(value, up->port.membase + offset);
}
static inline void serial_omap_clear_fifos(struct uart_omap_port *up)
{
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO);
serial_out(up, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
serial_out(up, UART_FCR, 0);
}
static int serial_omap_get_context_loss_count(struct uart_omap_port *up)
{
struct omap_uart_port_info *pdata = dev_get_platdata(up->dev);
if (!pdata || !pdata->get_context_loss_count)
return -EINVAL;
return pdata->get_context_loss_count(up->dev);
}
static inline void serial_omap_enable_wakeirq(struct uart_omap_port *up,
bool enable)
{
if (!up->wakeirq)
return;
if (enable)
enable_irq(up->wakeirq);
else
disable_irq(up->wakeirq);
}
static void serial_omap_enable_wakeup(struct uart_omap_port *up, bool enable)
{
struct omap_uart_port_info *pdata = dev_get_platdata(up->dev);
serial_omap_enable_wakeirq(up, enable);
if (!pdata || !pdata->enable_wakeup)
return;
pdata->enable_wakeup(up->dev, enable);
}
static bool
serial_omap_baud_is_mode16(struct uart_port *port, unsigned int baud)
{
unsigned int n13 = port->uartclk / (13 * baud);
unsigned int n16 = port->uartclk / (16 * baud);
int baudAbsDiff13 = baud - (port->uartclk / (13 * n13));
int baudAbsDiff16 = baud - (port->uartclk / (16 * n16));
if (baudAbsDiff13 < 0)
baudAbsDiff13 = -baudAbsDiff13;
if (baudAbsDiff16 < 0)
baudAbsDiff16 = -baudAbsDiff16;
return (baudAbsDiff13 >= baudAbsDiff16);
}
static unsigned int
serial_omap_get_divisor(struct uart_port *port, unsigned int baud)
{
unsigned int mode;
if (!serial_omap_baud_is_mode16(port, baud))
mode = 13;
else
mode = 16;
return port->uartclk/(mode * baud);
}
static void serial_omap_enable_ms(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
dev_dbg(up->port.dev, "serial_omap_enable_ms+%d\n", up->port.line);
pm_runtime_get_sync(up->dev);
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static void serial_omap_stop_tx(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
int res;
pm_runtime_get_sync(up->dev);
if (up->rs485.flags & SER_RS485_ENABLED) {
if (up->scr & OMAP_UART_SCR_TX_EMPTY) {
up->scr &= ~OMAP_UART_SCR_TX_EMPTY;
serial_out(up, UART_OMAP_SCR, up->scr);
res = (up->rs485.flags & SER_RS485_RTS_AFTER_SEND) ? 1 : 0;
if (gpio_get_value(up->rts_gpio) != res) {
if (up->rs485.delay_rts_after_send > 0)
mdelay(up->rs485.delay_rts_after_send);
gpio_set_value(up->rts_gpio, res);
}
} else {
up->scr |= OMAP_UART_SCR_TX_EMPTY;
serial_out(up, UART_OMAP_SCR, up->scr);
return;
}
}
if (up->ier & UART_IER_THRI) {
up->ier &= ~UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
if ((up->rs485.flags & SER_RS485_ENABLED) &&
!(up->rs485.flags & SER_RS485_RX_DURING_TX)) {
up->ier = UART_IER_RLSI | UART_IER_RDI;
serial_out(up, UART_IER, up->ier);
}
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static void serial_omap_stop_rx(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
pm_runtime_get_sync(up->dev);
up->ier &= ~UART_IER_RLSI;
up->port.read_status_mask &= ~UART_LSR_DR;
serial_out(up, UART_IER, up->ier);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static void transmit_chars(struct uart_omap_port *up, unsigned int lsr)
{
struct circ_buf *xmit = &up->port.state->xmit;
int count;
if (up->port.x_char) {
serial_out(up, UART_TX, up->port.x_char);
up->port.icount.tx++;
up->port.x_char = 0;
return;
}
if (uart_circ_empty(xmit) || uart_tx_stopped(&up->port)) {
serial_omap_stop_tx(&up->port);
return;
}
count = up->port.fifosize / 4;
do {
serial_out(up, UART_TX, xmit->buf[xmit->tail]);
xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);
up->port.icount.tx++;
if (uart_circ_empty(xmit))
break;
} while (--count > 0);
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS) {
spin_unlock(&up->port.lock);
uart_write_wakeup(&up->port);
spin_lock(&up->port.lock);
}
if (uart_circ_empty(xmit))
serial_omap_stop_tx(&up->port);
}
static inline void serial_omap_enable_ier_thri(struct uart_omap_port *up)
{
if (!(up->ier & UART_IER_THRI)) {
up->ier |= UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
}
static void serial_omap_start_tx(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
int res;
pm_runtime_get_sync(up->dev);
if (up->rs485.flags & SER_RS485_ENABLED) {
up->scr &= ~OMAP_UART_SCR_TX_EMPTY;
serial_out(up, UART_OMAP_SCR, up->scr);
res = (up->rs485.flags & SER_RS485_RTS_ON_SEND) ? 1 : 0;
if (gpio_get_value(up->rts_gpio) != res) {
gpio_set_value(up->rts_gpio, res);
if (up->rs485.delay_rts_before_send > 0)
mdelay(up->rs485.delay_rts_before_send);
}
}
if ((up->rs485.flags & SER_RS485_ENABLED) &&
!(up->rs485.flags & SER_RS485_RX_DURING_TX))
serial_omap_stop_rx(port);
serial_omap_enable_ier_thri(up);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static void serial_omap_throttle(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned long flags;
pm_runtime_get_sync(up->dev);
spin_lock_irqsave(&up->port.lock, flags);
up->ier &= ~(UART_IER_RLSI | UART_IER_RDI);
serial_out(up, UART_IER, up->ier);
spin_unlock_irqrestore(&up->port.lock, flags);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static void serial_omap_unthrottle(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned long flags;
pm_runtime_get_sync(up->dev);
spin_lock_irqsave(&up->port.lock, flags);
up->ier |= UART_IER_RLSI | UART_IER_RDI;
serial_out(up, UART_IER, up->ier);
spin_unlock_irqrestore(&up->port.lock, flags);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static unsigned int check_modem_status(struct uart_omap_port *up)
{
unsigned int status;
status = serial_in(up, UART_MSR);
status |= up->msr_saved_flags;
up->msr_saved_flags = 0;
if ((status & UART_MSR_ANY_DELTA) == 0)
return status;
if (status & UART_MSR_ANY_DELTA && up->ier & UART_IER_MSI &&
up->port.state != NULL) {
if (status & UART_MSR_TERI)
up->port.icount.rng++;
if (status & UART_MSR_DDSR)
up->port.icount.dsr++;
if (status & UART_MSR_DDCD)
uart_handle_dcd_change
(&up->port, status & UART_MSR_DCD);
if (status & UART_MSR_DCTS)
uart_handle_cts_change
(&up->port, status & UART_MSR_CTS);
wake_up_interruptible(&up->port.state->port.delta_msr_wait);
}
return status;
}
static void serial_omap_rlsi(struct uart_omap_port *up, unsigned int lsr)
{
unsigned int flag;
unsigned char ch = 0;
if (likely(lsr & UART_LSR_DR))
ch = serial_in(up, UART_RX);
up->port.icount.rx++;
flag = TTY_NORMAL;
if (lsr & UART_LSR_BI) {
flag = TTY_BREAK;
lsr &= ~(UART_LSR_FE | UART_LSR_PE);
up->port.icount.brk++;
if (uart_handle_break(&up->port))
return;
}
if (lsr & UART_LSR_PE) {
flag = TTY_PARITY;
up->port.icount.parity++;
}
if (lsr & UART_LSR_FE) {
flag = TTY_FRAME;
up->port.icount.frame++;
}
if (lsr & UART_LSR_OE)
up->port.icount.overrun++;
#ifdef CONFIG_SERIAL_OMAP_CONSOLE
if (up->port.line == up->port.cons->index) {
lsr |= up->lsr_break_flag;
}
#endif
uart_insert_char(&up->port, lsr, UART_LSR_OE, 0, flag);
}
static void serial_omap_rdi(struct uart_omap_port *up, unsigned int lsr)
{
unsigned char ch = 0;
unsigned int flag;
if (!(lsr & UART_LSR_DR))
return;
ch = serial_in(up, UART_RX);
flag = TTY_NORMAL;
up->port.icount.rx++;
if (uart_handle_sysrq_char(&up->port, ch))
return;
uart_insert_char(&up->port, lsr, UART_LSR_OE, ch, flag);
}
static irqreturn_t serial_omap_irq(int irq, void *dev_id)
{
struct uart_omap_port *up = dev_id;
unsigned int iir, lsr;
unsigned int type;
irqreturn_t ret = IRQ_NONE;
int max_count = 256;
spin_lock(&up->port.lock);
pm_runtime_get_sync(up->dev);
do {
iir = serial_in(up, UART_IIR);
if (iir & UART_IIR_NO_INT)
break;
ret = IRQ_HANDLED;
lsr = serial_in(up, UART_LSR);
type = iir & 0x3e;
switch (type) {
case UART_IIR_MSI:
check_modem_status(up);
break;
case UART_IIR_THRI:
transmit_chars(up, lsr);
break;
case UART_IIR_RX_TIMEOUT:
case UART_IIR_RDI:
serial_omap_rdi(up, lsr);
break;
case UART_IIR_RLSI:
serial_omap_rlsi(up, lsr);
break;
case UART_IIR_CTS_RTS_DSR:
break;
case UART_IIR_XOFF:
default:
break;
}
} while (!(iir & UART_IIR_NO_INT) && max_count--);
spin_unlock(&up->port.lock);
tty_flip_buffer_push(&up->port.state->port);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
up->port_activity = jiffies;
return ret;
}
static unsigned int serial_omap_tx_empty(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned long flags = 0;
unsigned int ret = 0;
pm_runtime_get_sync(up->dev);
dev_dbg(up->port.dev, "serial_omap_tx_empty+%d\n", up->port.line);
spin_lock_irqsave(&up->port.lock, flags);
ret = serial_in(up, UART_LSR) & UART_LSR_TEMT ? TIOCSER_TEMT : 0;
spin_unlock_irqrestore(&up->port.lock, flags);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
return ret;
}
static unsigned int serial_omap_get_mctrl(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned int status;
unsigned int ret = 0;
pm_runtime_get_sync(up->dev);
status = check_modem_status(up);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
dev_dbg(up->port.dev, "serial_omap_get_mctrl+%d\n", up->port.line);
if (status & UART_MSR_DCD)
ret |= TIOCM_CAR;
if (status & UART_MSR_RI)
ret |= TIOCM_RNG;
if (status & UART_MSR_DSR)
ret |= TIOCM_DSR;
if (status & UART_MSR_CTS)
ret |= TIOCM_CTS;
return ret;
}
static void serial_omap_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned char mcr = 0, old_mcr;
dev_dbg(up->port.dev, "serial_omap_set_mctrl+%d\n", up->port.line);
if (mctrl & TIOCM_RTS)
mcr |= UART_MCR_RTS;
if (mctrl & TIOCM_DTR)
mcr |= UART_MCR_DTR;
if (mctrl & TIOCM_OUT1)
mcr |= UART_MCR_OUT1;
if (mctrl & TIOCM_OUT2)
mcr |= UART_MCR_OUT2;
if (mctrl & TIOCM_LOOP)
mcr |= UART_MCR_LOOP;
pm_runtime_get_sync(up->dev);
old_mcr = serial_in(up, UART_MCR);
old_mcr &= ~(UART_MCR_LOOP | UART_MCR_OUT2 | UART_MCR_OUT1 |
UART_MCR_DTR | UART_MCR_RTS);
up->mcr = old_mcr | mcr;
serial_out(up, UART_MCR, up->mcr);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
if (gpio_is_valid(up->DTR_gpio) &&
!!(mctrl & TIOCM_DTR) != up->DTR_active) {
up->DTR_active = !up->DTR_active;
if (gpio_cansleep(up->DTR_gpio))
schedule_work(&up->qos_work);
else
gpio_set_value(up->DTR_gpio,
up->DTR_active != up->DTR_inverted);
}
}
static void serial_omap_break_ctl(struct uart_port *port, int break_state)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned long flags = 0;
dev_dbg(up->port.dev, "serial_omap_break_ctl+%d\n", up->port.line);
pm_runtime_get_sync(up->dev);
spin_lock_irqsave(&up->port.lock, flags);
if (break_state == -1)
up->lcr |= UART_LCR_SBC;
else
up->lcr &= ~UART_LCR_SBC;
serial_out(up, UART_LCR, up->lcr);
spin_unlock_irqrestore(&up->port.lock, flags);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static int serial_omap_startup(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned long flags = 0;
int retval;
retval = request_irq(up->port.irq, serial_omap_irq, up->port.irqflags,
up->name, up);
if (retval)
return retval;
if (up->wakeirq) {
retval = request_irq(up->wakeirq, serial_omap_irq,
up->port.irqflags, up->name, up);
if (retval) {
free_irq(up->port.irq, up);
return retval;
}
disable_irq(up->wakeirq);
} else {
dev_info(up->port.dev, "no wakeirq for uart%d\n",
up->port.line);
}
dev_dbg(up->port.dev, "serial_omap_startup+%d\n", up->port.line);
pm_runtime_get_sync(up->dev);
serial_omap_clear_fifos(up);
serial_out(up, UART_MCR, UART_MCR_RTS);
(void) serial_in(up, UART_LSR);
if (serial_in(up, UART_LSR) & UART_LSR_DR)
(void) serial_in(up, UART_RX);
(void) serial_in(up, UART_IIR);
(void) serial_in(up, UART_MSR);
serial_out(up, UART_LCR, UART_LCR_WLEN8);
spin_lock_irqsave(&up->port.lock, flags);
up->port.mctrl |= TIOCM_OUT2;
serial_omap_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
up->msr_saved_flags = 0;
up->ier = UART_IER_RLSI | UART_IER_RDI;
serial_out(up, UART_IER, up->ier);
up->wer = OMAP_UART_WER_MOD_WKUP;
if (up->features & OMAP_UART_WER_HAS_TX_WAKEUP)
up->wer |= OMAP_UART_TX_WAKEUP_EN;
serial_out(up, UART_OMAP_WER, up->wer);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
up->port_activity = jiffies;
return 0;
}
static void serial_omap_shutdown(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned long flags = 0;
dev_dbg(up->port.dev, "serial_omap_shutdown+%d\n", up->port.line);
pm_runtime_get_sync(up->dev);
up->ier = 0;
serial_out(up, UART_IER, 0);
spin_lock_irqsave(&up->port.lock, flags);
up->port.mctrl &= ~TIOCM_OUT2;
serial_omap_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
serial_out(up, UART_LCR, serial_in(up, UART_LCR) & ~UART_LCR_SBC);
serial_omap_clear_fifos(up);
if (serial_in(up, UART_LSR) & UART_LSR_DR)
(void) serial_in(up, UART_RX);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
free_irq(up->port.irq, up);
if (up->wakeirq)
free_irq(up->wakeirq, up);
}
static void serial_omap_uart_qos_work(struct work_struct *work)
{
struct uart_omap_port *up = container_of(work, struct uart_omap_port,
qos_work);
pm_qos_update_request(&up->pm_qos_request, up->latency);
if (gpio_is_valid(up->DTR_gpio))
gpio_set_value_cansleep(up->DTR_gpio,
up->DTR_active != up->DTR_inverted);
}
static void
serial_omap_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned char cval = 0;
unsigned long flags = 0;
unsigned int baud, quot;
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
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/13);
quot = serial_omap_get_divisor(port, baud);
up->calc_latency = (USEC_PER_SEC * up->port.fifosize) / (baud / 8);
up->latency = up->calc_latency;
schedule_work(&up->qos_work);
up->dll = quot & 0xff;
up->dlh = quot >> 8;
up->mdr1 = UART_OMAP_MDR1_DISABLE;
up->fcr = UART_FCR_R_TRIG_01 | UART_FCR_T_TRIG_01 |
UART_FCR_ENABLE_FIFO;
pm_runtime_get_sync(up->dev);
spin_lock_irqsave(&up->port.lock, flags);
uart_update_timeout(port, termios->c_cflag, baud);
up->port.read_status_mask = UART_LSR_OE | UART_LSR_THRE | UART_LSR_DR;
if (termios->c_iflag & INPCK)
up->port.read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (termios->c_iflag & (BRKINT | PARMRK))
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
serial_out(up, UART_IER, up->ier);
serial_out(up, UART_LCR, cval);
up->lcr = cval;
up->scr = 0;
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_DLL, 0);
serial_out(up, UART_DLM, 0);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
up->efr = serial_in(up, UART_EFR) & ~UART_EFR_ECB;
up->efr &= ~UART_EFR_SCD;
serial_out(up, UART_EFR, up->efr | UART_EFR_ECB);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
up->mcr = serial_in(up, UART_MCR) & ~UART_MCR_TCRTLR;
serial_out(up, UART_MCR, up->mcr | UART_MCR_TCRTLR);
up->scr |= OMAP_UART_SCR_RX_TRIG_GRANU1_MASK;
up->fcr &= ~OMAP_UART_FCR_RX_FIFO_TRIG_MASK;
up->fcr &= ~OMAP_UART_FCR_TX_FIFO_TRIG_MASK;
up->fcr |= UART_FCR6_R_TRIGGER_16 | UART_FCR6_T_TRIGGER_24 |
UART_FCR_ENABLE_FIFO;
serial_out(up, UART_FCR, up->fcr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_OMAP_SCR, up->scr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_MCR, up->mcr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, up->efr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
if (up->errata & UART_ERRATA_i202_MDR1_ACCESS)
serial_omap_mdr1_errataset(up, up->mdr1);
else
serial_out(up, UART_OMAP_MDR1, up->mdr1);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, up->efr | UART_EFR_ECB);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_IER, 0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_DLL, up->dll);
serial_out(up, UART_DLM, up->dlh);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_IER, up->ier);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, up->efr);
serial_out(up, UART_LCR, cval);
if (!serial_omap_baud_is_mode16(port, baud))
up->mdr1 = UART_OMAP_MDR1_13X_MODE;
else
up->mdr1 = UART_OMAP_MDR1_16X_MODE;
if (up->errata & UART_ERRATA_i202_MDR1_ACCESS)
serial_omap_mdr1_errataset(up, up->mdr1);
else
serial_out(up, UART_OMAP_MDR1, up->mdr1);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_XON1, termios->c_cc[VSTART]);
serial_out(up, UART_XOFF1, termios->c_cc[VSTOP]);
serial_out(up, UART_EFR, up->efr | UART_EFR_ECB);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_MCR, up->mcr | UART_MCR_TCRTLR);
serial_out(up, UART_TI752_TCR, OMAP_UART_TCR_TRIG);
if (termios->c_cflag & CRTSCTS && up->port.flags & UPF_HARD_FLOW) {
up->efr |= UART_EFR_CTS | UART_EFR_RTS;
up->mcr |= UART_MCR_RTS;
} else {
up->efr &= ~(UART_EFR_CTS | UART_EFR_RTS);
}
if (up->port.flags & UPF_SOFT_FLOW) {
up->efr &= OMAP_UART_SW_CLR;
if (termios->c_iflag & IXON)
up->efr |= OMAP_UART_SW_RX;
if (termios->c_iflag & IXOFF)
up->efr |= OMAP_UART_SW_TX;
if (termios->c_iflag & IXANY)
up->mcr |= UART_MCR_XONANY;
else
up->mcr &= ~UART_MCR_XONANY;
}
serial_out(up, UART_MCR, up->mcr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, up->efr);
serial_out(up, UART_LCR, up->lcr);
serial_omap_set_mctrl(&up->port, up->port.mctrl);
spin_unlock_irqrestore(&up->port.lock, flags);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
dev_dbg(up->port.dev, "serial_omap_set_termios+%d\n", up->port.line);
}
static void
serial_omap_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned char efr;
dev_dbg(up->port.dev, "serial_omap_pm+%d\n", up->port.line);
pm_runtime_get_sync(up->dev);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
efr = serial_in(up, UART_EFR);
serial_out(up, UART_EFR, efr | UART_EFR_ECB);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_IER, (state != 0) ? UART_IERX_SLEEP : 0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, efr);
serial_out(up, UART_LCR, 0);
if (!device_may_wakeup(up->dev)) {
if (!state)
pm_runtime_forbid(up->dev);
else
pm_runtime_allow(up->dev);
}
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static void serial_omap_release_port(struct uart_port *port)
{
dev_dbg(port->dev, "serial_omap_release_port+\n");
}
static int serial_omap_request_port(struct uart_port *port)
{
dev_dbg(port->dev, "serial_omap_request_port+\n");
return 0;
}
static void serial_omap_config_port(struct uart_port *port, int flags)
{
struct uart_omap_port *up = to_uart_omap_port(port);
dev_dbg(up->port.dev, "serial_omap_config_port+%d\n",
up->port.line);
up->port.type = PORT_OMAP;
up->port.flags |= UPF_SOFT_FLOW | UPF_HARD_FLOW;
}
static int
serial_omap_verify_port(struct uart_port *port, struct serial_struct *ser)
{
dev_dbg(port->dev, "serial_omap_verify_port+\n");
return -EINVAL;
}
static const char *
serial_omap_type(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
dev_dbg(up->port.dev, "serial_omap_type+%d\n", up->port.line);
return up->name;
}
static inline void wait_for_xmitr(struct uart_omap_port *up)
{
unsigned int status, tmout = 10000;
do {
status = serial_in(up, UART_LSR);
if (status & UART_LSR_BI)
up->lsr_break_flag = UART_LSR_BI;
if (--tmout == 0)
break;
udelay(1);
} while ((status & BOTH_EMPTY) != BOTH_EMPTY);
if (up->port.flags & UPF_CONS_FLOW) {
tmout = 1000000;
for (tmout = 1000000; tmout; tmout--) {
unsigned int msr = serial_in(up, UART_MSR);
up->msr_saved_flags |= msr & MSR_SAVE_FLAGS;
if (msr & UART_MSR_CTS)
break;
udelay(1);
}
}
}
static void serial_omap_poll_put_char(struct uart_port *port, unsigned char ch)
{
struct uart_omap_port *up = to_uart_omap_port(port);
pm_runtime_get_sync(up->dev);
wait_for_xmitr(up);
serial_out(up, UART_TX, ch);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static int serial_omap_poll_get_char(struct uart_port *port)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned int status;
pm_runtime_get_sync(up->dev);
status = serial_in(up, UART_LSR);
if (!(status & UART_LSR_DR)) {
status = NO_POLL_CHAR;
goto out;
}
status = serial_in(up, UART_RX);
out:
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
return status;
}
static void serial_omap_console_putchar(struct uart_port *port, int ch)
{
struct uart_omap_port *up = to_uart_omap_port(port);
wait_for_xmitr(up);
serial_out(up, UART_TX, ch);
}
static void
serial_omap_console_write(struct console *co, const char *s,
unsigned int count)
{
struct uart_omap_port *up = serial_omap_console_ports[co->index];
unsigned long flags;
unsigned int ier;
int locked = 1;
pm_runtime_get_sync(up->dev);
local_irq_save(flags);
if (up->port.sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock(&up->port.lock);
else
spin_lock(&up->port.lock);
ier = serial_in(up, UART_IER);
serial_out(up, UART_IER, 0);
uart_console_write(&up->port, s, count, serial_omap_console_putchar);
wait_for_xmitr(up);
serial_out(up, UART_IER, ier);
if (up->msr_saved_flags)
check_modem_status(up);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
if (locked)
spin_unlock(&up->port.lock);
local_irq_restore(flags);
}
static int __init
serial_omap_console_setup(struct console *co, char *options)
{
struct uart_omap_port *up;
int baud = 115200;
int bits = 8;
int parity = 'n';
int flow = 'n';
if (serial_omap_console_ports[co->index] == NULL)
return -ENODEV;
up = serial_omap_console_ports[co->index];
if (options)
uart_parse_options(options, &baud, &parity, &bits, &flow);
return uart_set_options(&up->port, co, baud, parity, bits, flow);
}
static void serial_omap_add_console_port(struct uart_omap_port *up)
{
serial_omap_console_ports[up->port.line] = up;
}
static inline void serial_omap_add_console_port(struct uart_omap_port *up)
{}
static void
serial_omap_config_rs485(struct uart_port *port, struct serial_rs485 *rs485conf)
{
struct uart_omap_port *up = to_uart_omap_port(port);
unsigned long flags;
unsigned int mode;
int val;
pm_runtime_get_sync(up->dev);
spin_lock_irqsave(&up->port.lock, flags);
mode = up->ier;
up->ier = 0;
serial_out(up, UART_IER, 0);
up->rs485 = *rs485conf;
if (gpio_is_valid(up->rts_gpio)) {
val = (up->rs485.flags & SER_RS485_ENABLED) ?
SER_RS485_RTS_AFTER_SEND : SER_RS485_RTS_ON_SEND;
val = (up->rs485.flags & val) ? 1 : 0;
gpio_set_value(up->rts_gpio, val);
} else
up->rs485.flags &= ~SER_RS485_ENABLED;
up->ier = mode;
serial_out(up, UART_IER, up->ier);
if (!(up->rs485.flags & SER_RS485_ENABLED) &&
(up->scr & OMAP_UART_SCR_TX_EMPTY)) {
up->scr &= ~OMAP_UART_SCR_TX_EMPTY;
serial_out(up, UART_OMAP_SCR, up->scr);
}
spin_unlock_irqrestore(&up->port.lock, flags);
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
}
static int
serial_omap_ioctl(struct uart_port *port, unsigned int cmd, unsigned long arg)
{
struct serial_rs485 rs485conf;
switch (cmd) {
case TIOCSRS485:
if (copy_from_user(&rs485conf, (struct serial_rs485 *) arg,
sizeof(rs485conf)))
return -EFAULT;
serial_omap_config_rs485(port, &rs485conf);
break;
case TIOCGRS485:
if (copy_to_user((struct serial_rs485 *) arg,
&(to_uart_omap_port(port)->rs485),
sizeof(rs485conf)))
return -EFAULT;
break;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static int serial_omap_prepare(struct device *dev)
{
struct uart_omap_port *up = dev_get_drvdata(dev);
up->is_suspending = true;
return 0;
}
static void serial_omap_complete(struct device *dev)
{
struct uart_omap_port *up = dev_get_drvdata(dev);
up->is_suspending = false;
}
static int serial_omap_suspend(struct device *dev)
{
struct uart_omap_port *up = dev_get_drvdata(dev);
uart_suspend_port(&serial_omap_reg, &up->port);
flush_work(&up->qos_work);
return 0;
}
static int serial_omap_resume(struct device *dev)
{
struct uart_omap_port *up = dev_get_drvdata(dev);
uart_resume_port(&serial_omap_reg, &up->port);
return 0;
}
static void omap_serial_fill_features_erratas(struct uart_omap_port *up)
{
u32 mvr, scheme;
u16 revision, major, minor;
mvr = readl(up->port.membase + (UART_OMAP_MVER << up->port.regshift));
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
dev_warn(up->dev,
"Unknown %s revision, defaulting to highest\n",
up->name);
major = 0xff;
minor = 0xff;
}
revision = UART_BUILD_REVISION(major, minor);
switch (revision) {
case OMAP_UART_REV_46:
up->errata |= (UART_ERRATA_i202_MDR1_ACCESS |
UART_ERRATA_i291_DMA_FORCEIDLE);
break;
case OMAP_UART_REV_52:
up->errata |= (UART_ERRATA_i202_MDR1_ACCESS |
UART_ERRATA_i291_DMA_FORCEIDLE);
up->features |= OMAP_UART_WER_HAS_TX_WAKEUP;
break;
case OMAP_UART_REV_63:
up->errata |= UART_ERRATA_i202_MDR1_ACCESS;
up->features |= OMAP_UART_WER_HAS_TX_WAKEUP;
break;
default:
break;
}
}
static struct omap_uart_port_info *of_get_uart_port_info(struct device *dev)
{
struct omap_uart_port_info *omap_up_info;
omap_up_info = devm_kzalloc(dev, sizeof(*omap_up_info), GFP_KERNEL);
if (!omap_up_info)
return NULL;
of_property_read_u32(dev->of_node, "clock-frequency",
&omap_up_info->uartclk);
return omap_up_info;
}
static int serial_omap_probe_rs485(struct uart_omap_port *up,
struct device_node *np)
{
struct serial_rs485 *rs485conf = &up->rs485;
u32 rs485_delay[2];
enum of_gpio_flags flags;
int ret;
rs485conf->flags = 0;
up->rts_gpio = -EINVAL;
if (!np)
return 0;
if (of_property_read_bool(np, "rs485-rts-active-high"))
rs485conf->flags |= SER_RS485_RTS_ON_SEND;
else
rs485conf->flags |= SER_RS485_RTS_AFTER_SEND;
up->rts_gpio = of_get_named_gpio_flags(np, "rts-gpio", 0, &flags);
if (gpio_is_valid(up->rts_gpio)) {
ret = gpio_request(up->rts_gpio, "omap-serial");
if (ret < 0)
return ret;
ret = gpio_direction_output(up->rts_gpio,
flags & SER_RS485_RTS_AFTER_SEND);
if (ret < 0)
return ret;
} else
up->rts_gpio = -EINVAL;
if (of_property_read_u32_array(np, "rs485-rts-delay",
rs485_delay, 2) == 0) {
rs485conf->delay_rts_before_send = rs485_delay[0];
rs485conf->delay_rts_after_send = rs485_delay[1];
}
if (of_property_read_bool(np, "rs485-rx-during-tx"))
rs485conf->flags |= SER_RS485_RX_DURING_TX;
if (of_property_read_bool(np, "linux,rs485-enabled-at-boot-time"))
rs485conf->flags |= SER_RS485_ENABLED;
return 0;
}
static int serial_omap_probe(struct platform_device *pdev)
{
struct uart_omap_port *up;
struct resource *mem, *irq;
struct omap_uart_port_info *omap_up_info = dev_get_platdata(&pdev->dev);
int ret, uartirq = 0, wakeirq = 0;
if (pdev->dev.of_node) {
uartirq = irq_of_parse_and_map(pdev->dev.of_node, 0);
if (!uartirq)
return -EPROBE_DEFER;
wakeirq = irq_of_parse_and_map(pdev->dev.of_node, 1);
omap_up_info = of_get_uart_port_info(&pdev->dev);
pdev->dev.platform_data = omap_up_info;
} else {
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq) {
dev_err(&pdev->dev, "no irq resource?\n");
return -ENODEV;
}
uartirq = irq->start;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -ENODEV;
}
if (!devm_request_mem_region(&pdev->dev, mem->start, resource_size(mem),
pdev->dev.driver->name)) {
dev_err(&pdev->dev, "memory region already claimed\n");
return -EBUSY;
}
if (gpio_is_valid(omap_up_info->DTR_gpio) &&
omap_up_info->DTR_present) {
ret = gpio_request(omap_up_info->DTR_gpio, "omap-serial");
if (ret < 0)
return ret;
ret = gpio_direction_output(omap_up_info->DTR_gpio,
omap_up_info->DTR_inverted);
if (ret < 0)
return ret;
}
up = devm_kzalloc(&pdev->dev, sizeof(*up), GFP_KERNEL);
if (!up)
return -ENOMEM;
if (gpio_is_valid(omap_up_info->DTR_gpio) &&
omap_up_info->DTR_present) {
up->DTR_gpio = omap_up_info->DTR_gpio;
up->DTR_inverted = omap_up_info->DTR_inverted;
} else
up->DTR_gpio = -EINVAL;
up->DTR_active = 0;
up->dev = &pdev->dev;
up->port.dev = &pdev->dev;
up->port.type = PORT_OMAP;
up->port.iotype = UPIO_MEM;
up->port.irq = uartirq;
up->wakeirq = wakeirq;
up->port.regshift = 2;
up->port.fifosize = 64;
up->port.ops = &serial_omap_pops;
if (pdev->dev.of_node)
up->port.line = of_alias_get_id(pdev->dev.of_node, "serial");
else
up->port.line = pdev->id;
if (up->port.line < 0) {
dev_err(&pdev->dev, "failed to get alias/pdev id, errno %d\n",
up->port.line);
ret = -ENODEV;
goto err_port_line;
}
ret = serial_omap_probe_rs485(up, pdev->dev.of_node);
if (ret < 0)
goto err_rs485;
sprintf(up->name, "OMAP UART%d", up->port.line);
up->port.mapbase = mem->start;
up->port.membase = devm_ioremap(&pdev->dev, mem->start,
resource_size(mem));
if (!up->port.membase) {
dev_err(&pdev->dev, "can't ioremap UART\n");
ret = -ENOMEM;
goto err_ioremap;
}
up->port.flags = omap_up_info->flags;
up->port.uartclk = omap_up_info->uartclk;
if (!up->port.uartclk) {
up->port.uartclk = DEFAULT_CLK_SPEED;
dev_warn(&pdev->dev,
"No clock speed specified: using default: %d\n",
DEFAULT_CLK_SPEED);
}
up->latency = PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE;
up->calc_latency = PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE;
pm_qos_add_request(&up->pm_qos_request,
PM_QOS_CPU_DMA_LATENCY, up->latency);
serial_omap_uart_wq = create_singlethread_workqueue(up->name);
INIT_WORK(&up->qos_work, serial_omap_uart_qos_work);
platform_set_drvdata(pdev, up);
if (omap_up_info->autosuspend_timeout == 0)
omap_up_info->autosuspend_timeout = -1;
device_init_wakeup(up->dev, true);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev,
omap_up_info->autosuspend_timeout);
pm_runtime_irq_safe(&pdev->dev);
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
omap_serial_fill_features_erratas(up);
ui[up->port.line] = up;
serial_omap_add_console_port(up);
ret = uart_add_one_port(&serial_omap_reg, &up->port);
if (ret != 0)
goto err_add_port;
pm_runtime_mark_last_busy(up->dev);
pm_runtime_put_autosuspend(up->dev);
return 0;
err_add_port:
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
err_ioremap:
err_rs485:
err_port_line:
dev_err(&pdev->dev, "[UART%d]: failure [%s]: %d\n",
pdev->id, __func__, ret);
return ret;
}
static int serial_omap_remove(struct platform_device *dev)
{
struct uart_omap_port *up = platform_get_drvdata(dev);
pm_runtime_put_sync(up->dev);
pm_runtime_disable(up->dev);
uart_remove_one_port(&serial_omap_reg, &up->port);
pm_qos_remove_request(&up->pm_qos_request);
return 0;
}
static void serial_omap_mdr1_errataset(struct uart_omap_port *up, u8 mdr1)
{
u8 timeout = 255;
serial_out(up, UART_OMAP_MDR1, mdr1);
udelay(2);
serial_out(up, UART_FCR, up->fcr | UART_FCR_CLEAR_XMIT |
UART_FCR_CLEAR_RCVR);
while (UART_LSR_THRE != (serial_in(up, UART_LSR) &
(UART_LSR_THRE | UART_LSR_DR))) {
timeout--;
if (!timeout) {
dev_crit(up->dev, "Errata i202: timedout %x\n",
serial_in(up, UART_LSR));
break;
}
udelay(1);
}
}
static void serial_omap_restore_context(struct uart_omap_port *up)
{
if (up->errata & UART_ERRATA_i202_MDR1_ACCESS)
serial_omap_mdr1_errataset(up, UART_OMAP_MDR1_DISABLE);
else
serial_out(up, UART_OMAP_MDR1, UART_OMAP_MDR1_DISABLE);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, UART_EFR_ECB);
serial_out(up, UART_LCR, 0x0);
serial_out(up, UART_IER, 0x0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_DLL, up->dll);
serial_out(up, UART_DLM, up->dlh);
serial_out(up, UART_LCR, 0x0);
serial_out(up, UART_IER, up->ier);
serial_out(up, UART_FCR, up->fcr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_MCR, up->mcr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_OMAP_SCR, up->scr);
serial_out(up, UART_EFR, up->efr);
serial_out(up, UART_LCR, up->lcr);
if (up->errata & UART_ERRATA_i202_MDR1_ACCESS)
serial_omap_mdr1_errataset(up, up->mdr1);
else
serial_out(up, UART_OMAP_MDR1, up->mdr1);
serial_out(up, UART_OMAP_WER, up->wer);
}
static int serial_omap_runtime_suspend(struct device *dev)
{
struct uart_omap_port *up = dev_get_drvdata(dev);
if (!up)
return -EINVAL;
if (up->is_suspending && !console_suspend_enabled &&
uart_console(&up->port))
return -EBUSY;
up->context_loss_cnt = serial_omap_get_context_loss_count(up);
if (device_may_wakeup(dev)) {
if (!up->wakeups_enabled) {
serial_omap_enable_wakeup(up, true);
up->wakeups_enabled = true;
}
} else {
if (up->wakeups_enabled) {
serial_omap_enable_wakeup(up, false);
up->wakeups_enabled = false;
}
}
up->latency = PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE;
schedule_work(&up->qos_work);
return 0;
}
static int serial_omap_runtime_resume(struct device *dev)
{
struct uart_omap_port *up = dev_get_drvdata(dev);
int loss_cnt = serial_omap_get_context_loss_count(up);
if (loss_cnt < 0) {
dev_dbg(dev, "serial_omap_get_context_loss_count failed : %d\n",
loss_cnt);
serial_omap_restore_context(up);
} else if (up->context_loss_cnt != loss_cnt) {
serial_omap_restore_context(up);
}
up->latency = up->calc_latency;
schedule_work(&up->qos_work);
return 0;
}
static int __init serial_omap_init(void)
{
int ret;
ret = uart_register_driver(&serial_omap_reg);
if (ret != 0)
return ret;
ret = platform_driver_register(&serial_omap_driver);
if (ret != 0)
uart_unregister_driver(&serial_omap_reg);
return ret;
}
static void __exit serial_omap_exit(void)
{
platform_driver_unregister(&serial_omap_driver);
uart_unregister_driver(&serial_omap_reg);
}
