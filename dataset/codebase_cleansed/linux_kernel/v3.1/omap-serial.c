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
static unsigned int
serial_omap_get_divisor(struct uart_port *port, unsigned int baud)
{
unsigned int divisor;
if (baud > OMAP_MODE13X_SPEED && baud != 3000000)
divisor = 13;
else
divisor = 16;
return port->uartclk/(baud * divisor);
}
static void serial_omap_stop_rxdma(struct uart_omap_port *up)
{
if (up->uart_dma.rx_dma_used) {
del_timer(&up->uart_dma.rx_timer);
omap_stop_dma(up->uart_dma.rx_dma_channel);
omap_free_dma(up->uart_dma.rx_dma_channel);
up->uart_dma.rx_dma_channel = OMAP_UART_DMA_CH_FREE;
up->uart_dma.rx_dma_used = false;
}
}
static void serial_omap_enable_ms(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
dev_dbg(up->port.dev, "serial_omap_enable_ms+%d\n", up->pdev->id);
up->ier |= UART_IER_MSI;
serial_out(up, UART_IER, up->ier);
}
static void serial_omap_stop_tx(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
if (up->use_dma &&
up->uart_dma.tx_dma_channel != OMAP_UART_DMA_CH_FREE) {
if (omap_get_dma_active_status(up->uart_dma.tx_dma_channel))
return;
omap_stop_dma(up->uart_dma.tx_dma_channel);
omap_free_dma(up->uart_dma.tx_dma_channel);
up->uart_dma.tx_dma_channel = OMAP_UART_DMA_CH_FREE;
}
if (up->ier & UART_IER_THRI) {
up->ier &= ~UART_IER_THRI;
serial_out(up, UART_IER, up->ier);
}
}
static void serial_omap_stop_rx(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
if (up->use_dma)
serial_omap_stop_rxdma(up);
up->ier &= ~UART_IER_RLSI;
up->port.read_status_mask &= ~UART_LSR_DR;
serial_out(up, UART_IER, up->ier);
}
static inline void receive_chars(struct uart_omap_port *up, int *status)
{
struct tty_struct *tty = up->port.state->port.tty;
unsigned int flag;
unsigned char ch, lsr = *status;
int max_count = 256;
do {
if (likely(lsr & UART_LSR_DR))
ch = serial_in(up, UART_RX);
flag = TTY_NORMAL;
up->port.icount.rx++;
if (unlikely(lsr & UART_LSR_BRK_ERROR_BITS)) {
if (lsr & UART_LSR_BI) {
lsr &= ~(UART_LSR_FE | UART_LSR_PE);
up->port.icount.brk++;
if (uart_handle_break(&up->port))
goto ignore_char;
} else if (lsr & UART_LSR_PE) {
up->port.icount.parity++;
} else if (lsr & UART_LSR_FE) {
up->port.icount.frame++;
}
if (lsr & UART_LSR_OE)
up->port.icount.overrun++;
lsr &= up->port.read_status_mask;
#ifdef CONFIG_SERIAL_OMAP_CONSOLE
if (up->port.line == up->port.cons->index) {
lsr |= up->lsr_break_flag;
}
#endif
if (lsr & UART_LSR_BI)
flag = TTY_BREAK;
else if (lsr & UART_LSR_PE)
flag = TTY_PARITY;
else if (lsr & UART_LSR_FE)
flag = TTY_FRAME;
}
if (uart_handle_sysrq_char(&up->port, ch))
goto ignore_char;
uart_insert_char(&up->port, lsr, UART_LSR_OE, ch, flag);
ignore_char:
lsr = serial_in(up, UART_LSR);
} while ((lsr & (UART_LSR_DR | UART_LSR_BI)) && (max_count-- > 0));
spin_unlock(&up->port.lock);
tty_flip_buffer_push(tty);
spin_lock(&up->port.lock);
}
static void transmit_chars(struct uart_omap_port *up)
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
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
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
struct uart_omap_port *up = (struct uart_omap_port *)port;
struct circ_buf *xmit;
unsigned int start;
int ret = 0;
if (!up->use_dma) {
serial_omap_enable_ier_thri(up);
return;
}
if (up->uart_dma.tx_dma_used)
return;
xmit = &up->port.state->xmit;
if (up->uart_dma.tx_dma_channel == OMAP_UART_DMA_CH_FREE) {
ret = omap_request_dma(up->uart_dma.uart_dma_tx,
"UART Tx DMA",
(void *)uart_tx_dma_callback, up,
&(up->uart_dma.tx_dma_channel));
if (ret < 0) {
serial_omap_enable_ier_thri(up);
return;
}
}
spin_lock(&(up->uart_dma.tx_lock));
up->uart_dma.tx_dma_used = true;
spin_unlock(&(up->uart_dma.tx_lock));
start = up->uart_dma.tx_buf_dma_phys +
(xmit->tail & (UART_XMIT_SIZE - 1));
up->uart_dma.tx_buf_size = uart_circ_chars_pending(xmit);
if (start + up->uart_dma.tx_buf_size >=
up->uart_dma.tx_buf_dma_phys + UART_XMIT_SIZE)
up->uart_dma.tx_buf_size =
(up->uart_dma.tx_buf_dma_phys +
UART_XMIT_SIZE) - start;
omap_set_dma_dest_params(up->uart_dma.tx_dma_channel, 0,
OMAP_DMA_AMODE_CONSTANT,
up->uart_dma.uart_base, 0, 0);
omap_set_dma_src_params(up->uart_dma.tx_dma_channel, 0,
OMAP_DMA_AMODE_POST_INC, start, 0, 0);
omap_set_dma_transfer_params(up->uart_dma.tx_dma_channel,
OMAP_DMA_DATA_TYPE_S8,
up->uart_dma.tx_buf_size, 1,
OMAP_DMA_SYNC_ELEMENT,
up->uart_dma.uart_dma_tx, 0);
omap_start_dma(up->uart_dma.tx_dma_channel);
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
static inline irqreturn_t serial_omap_irq(int irq, void *dev_id)
{
struct uart_omap_port *up = dev_id;
unsigned int iir, lsr;
unsigned long flags;
iir = serial_in(up, UART_IIR);
if (iir & UART_IIR_NO_INT)
return IRQ_NONE;
spin_lock_irqsave(&up->port.lock, flags);
lsr = serial_in(up, UART_LSR);
if (iir & UART_IIR_RLSI) {
if (!up->use_dma) {
if (lsr & UART_LSR_DR)
receive_chars(up, &lsr);
} else {
up->ier &= ~(UART_IER_RDI | UART_IER_RLSI);
serial_out(up, UART_IER, up->ier);
if ((serial_omap_start_rxdma(up) != 0) &&
(lsr & UART_LSR_DR))
receive_chars(up, &lsr);
}
}
check_modem_status(up);
if ((lsr & UART_LSR_THRE) && (iir & UART_IIR_THRI))
transmit_chars(up);
spin_unlock_irqrestore(&up->port.lock, flags);
up->port_activity = jiffies;
return IRQ_HANDLED;
}
static unsigned int serial_omap_tx_empty(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned long flags = 0;
unsigned int ret = 0;
dev_dbg(up->port.dev, "serial_omap_tx_empty+%d\n", up->pdev->id);
spin_lock_irqsave(&up->port.lock, flags);
ret = serial_in(up, UART_LSR) & UART_LSR_TEMT ? TIOCSER_TEMT : 0;
spin_unlock_irqrestore(&up->port.lock, flags);
return ret;
}
static unsigned int serial_omap_get_mctrl(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned char status;
unsigned int ret = 0;
status = check_modem_status(up);
dev_dbg(up->port.dev, "serial_omap_get_mctrl+%d\n", up->pdev->id);
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
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned char mcr = 0;
dev_dbg(up->port.dev, "serial_omap_set_mctrl+%d\n", up->pdev->id);
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
mcr |= up->mcr;
serial_out(up, UART_MCR, mcr);
}
static void serial_omap_break_ctl(struct uart_port *port, int break_state)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned long flags = 0;
dev_dbg(up->port.dev, "serial_omap_break_ctl+%d\n", up->pdev->id);
spin_lock_irqsave(&up->port.lock, flags);
if (break_state == -1)
up->lcr |= UART_LCR_SBC;
else
up->lcr &= ~UART_LCR_SBC;
serial_out(up, UART_LCR, up->lcr);
spin_unlock_irqrestore(&up->port.lock, flags);
}
static int serial_omap_startup(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned long flags = 0;
int retval;
retval = request_irq(up->port.irq, serial_omap_irq, up->port.irqflags,
up->name, up);
if (retval)
return retval;
dev_dbg(up->port.dev, "serial_omap_startup+%d\n", up->pdev->id);
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
if (up->use_dma) {
free_page((unsigned long)up->port.state->xmit.buf);
up->port.state->xmit.buf = dma_alloc_coherent(NULL,
UART_XMIT_SIZE,
(dma_addr_t *)&(up->uart_dma.tx_buf_dma_phys),
0);
init_timer(&(up->uart_dma.rx_timer));
up->uart_dma.rx_timer.function = serial_omap_rx_timeout;
up->uart_dma.rx_timer.data = up->pdev->id;
up->uart_dma.rx_buf = dma_alloc_coherent(NULL,
up->uart_dma.rx_buf_size,
(dma_addr_t *)&(up->uart_dma.rx_buf_dma_phys), 0);
}
up->ier = UART_IER_RLSI | UART_IER_RDI;
serial_out(up, UART_IER, up->ier);
serial_out(up, UART_OMAP_WER, OMAP_UART_WER_MOD_WKUP);
up->port_activity = jiffies;
return 0;
}
static void serial_omap_shutdown(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned long flags = 0;
dev_dbg(up->port.dev, "serial_omap_shutdown+%d\n", up->pdev->id);
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
if (up->use_dma) {
dma_free_coherent(up->port.dev,
UART_XMIT_SIZE, up->port.state->xmit.buf,
up->uart_dma.tx_buf_dma_phys);
up->port.state->xmit.buf = NULL;
serial_omap_stop_rx(port);
dma_free_coherent(up->port.dev,
up->uart_dma.rx_buf_size, up->uart_dma.rx_buf,
up->uart_dma.rx_buf_dma_phys);
up->uart_dma.rx_buf = NULL;
}
free_irq(up->port.irq, up);
}
static inline void
serial_omap_configure_xonxoff
(struct uart_omap_port *up, struct ktermios *termios)
{
unsigned char efr = 0;
up->lcr = serial_in(up, UART_LCR);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
up->efr = serial_in(up, UART_EFR);
serial_out(up, UART_EFR, up->efr & ~UART_EFR_ECB);
serial_out(up, UART_XON1, termios->c_cc[VSTART]);
serial_out(up, UART_XOFF1, termios->c_cc[VSTOP]);
efr = up->efr;
efr &= OMAP_UART_SW_CLR;
if (termios->c_iflag & IXON)
efr |= OMAP_UART_SW_TX;
if (termios->c_iflag & IXOFF)
efr |= OMAP_UART_SW_RX;
serial_out(up, UART_EFR, up->efr | UART_EFR_ECB);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
up->mcr = serial_in(up, UART_MCR);
if (termios->c_iflag & IXANY)
up->mcr |= UART_MCR_XONANY;
serial_out(up, UART_MCR, up->mcr | UART_MCR_TCRTLR);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_TI752_TCR, OMAP_UART_TCR_TRIG);
serial_out(up, UART_EFR, efr | UART_EFR_SCD);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_MCR, up->mcr & ~UART_MCR_TCRTLR);
serial_out(up, UART_LCR, up->lcr);
}
static void
serial_omap_set_termios(struct uart_port *port, struct ktermios *termios,
struct ktermios *old)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned char cval = 0;
unsigned char efr = 0;
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
baud = uart_get_baud_rate(port, termios, old, 0, port->uartclk/13);
quot = serial_omap_get_divisor(port, baud);
up->fcr = UART_FCR_R_TRIG_01 | UART_FCR_T_TRIG_01 |
UART_FCR_ENABLE_FIFO;
if (up->use_dma)
up->fcr |= UART_FCR_DMA_SELECT;
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
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_DLL, 0);
serial_out(up, UART_DLM, 0);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
up->efr = serial_in(up, UART_EFR);
serial_out(up, UART_EFR, up->efr | UART_EFR_ECB);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
up->mcr = serial_in(up, UART_MCR);
serial_out(up, UART_MCR, up->mcr | UART_MCR_TCRTLR);
serial_out(up, UART_FCR, up->fcr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
if (up->use_dma) {
serial_out(up, UART_TI752_TLR, 0);
serial_out(up, UART_OMAP_SCR,
(UART_FCR_TRIGGER_4 | UART_FCR_TRIGGER_8));
}
serial_out(up, UART_EFR, up->efr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_MCR, up->mcr);
serial_out(up, UART_OMAP_MDR1, UART_OMAP_MDR1_DISABLE);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
up->efr = serial_in(up, UART_EFR);
serial_out(up, UART_EFR, up->efr | UART_EFR_ECB);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_IER, 0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_DLL, quot & 0xff);
serial_out(up, UART_DLM, quot >> 8);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_IER, up->ier);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, up->efr);
serial_out(up, UART_LCR, cval);
if (baud > 230400 && baud != 3000000)
serial_out(up, UART_OMAP_MDR1, UART_OMAP_MDR1_13X_MODE);
else
serial_out(up, UART_OMAP_MDR1, UART_OMAP_MDR1_16X_MODE);
if (termios->c_cflag & CRTSCTS) {
efr |= (UART_EFR_CTS | UART_EFR_RTS);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
up->mcr = serial_in(up, UART_MCR);
serial_out(up, UART_MCR, up->mcr | UART_MCR_TCRTLR);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
up->efr = serial_in(up, UART_EFR);
serial_out(up, UART_EFR, up->efr | UART_EFR_ECB);
serial_out(up, UART_TI752_TCR, OMAP_UART_TCR_TRIG);
serial_out(up, UART_EFR, efr);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_A);
serial_out(up, UART_MCR, up->mcr | UART_MCR_RTS);
serial_out(up, UART_LCR, cval);
}
serial_omap_set_mctrl(&up->port, up->port.mctrl);
serial_omap_configure_xonxoff(up, termios);
spin_unlock_irqrestore(&up->port.lock, flags);
dev_dbg(up->port.dev, "serial_omap_set_termios+%d\n", up->pdev->id);
}
static void
serial_omap_pm(struct uart_port *port, unsigned int state,
unsigned int oldstate)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned char efr;
dev_dbg(up->port.dev, "serial_omap_pm+%d\n", up->pdev->id);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
efr = serial_in(up, UART_EFR);
serial_out(up, UART_EFR, efr | UART_EFR_ECB);
serial_out(up, UART_LCR, 0);
serial_out(up, UART_IER, (state != 0) ? UART_IERX_SLEEP : 0);
serial_out(up, UART_LCR, UART_LCR_CONF_MODE_B);
serial_out(up, UART_EFR, efr);
serial_out(up, UART_LCR, 0);
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
struct uart_omap_port *up = (struct uart_omap_port *)port;
dev_dbg(up->port.dev, "serial_omap_config_port+%d\n",
up->pdev->id);
up->port.type = PORT_OMAP;
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
struct uart_omap_port *up = (struct uart_omap_port *)port;
dev_dbg(up->port.dev, "serial_omap_type+%d\n", up->pdev->id);
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
struct uart_omap_port *up = (struct uart_omap_port *)port;
wait_for_xmitr(up);
serial_out(up, UART_TX, ch);
}
static int serial_omap_poll_get_char(struct uart_port *port)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
unsigned int status = serial_in(up, UART_LSR);
if (!(status & UART_LSR_DR))
return NO_POLL_CHAR;
return serial_in(up, UART_RX);
}
static void serial_omap_console_putchar(struct uart_port *port, int ch)
{
struct uart_omap_port *up = (struct uart_omap_port *)port;
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
serial_omap_console_ports[up->pdev->id] = up;
}
static inline void serial_omap_add_console_port(struct uart_omap_port *up)
{}
static int
serial_omap_suspend(struct platform_device *pdev, pm_message_t state)
{
struct uart_omap_port *up = platform_get_drvdata(pdev);
if (up)
uart_suspend_port(&serial_omap_reg, &up->port);
return 0;
}
static int serial_omap_resume(struct platform_device *dev)
{
struct uart_omap_port *up = platform_get_drvdata(dev);
if (up)
uart_resume_port(&serial_omap_reg, &up->port);
return 0;
}
static void serial_omap_rx_timeout(unsigned long uart_no)
{
struct uart_omap_port *up = ui[uart_no];
unsigned int curr_dma_pos, curr_transmitted_size;
int ret = 0;
curr_dma_pos = omap_get_dma_dst_pos(up->uart_dma.rx_dma_channel);
if ((curr_dma_pos == up->uart_dma.prev_rx_dma_pos) ||
(curr_dma_pos == 0)) {
if (jiffies_to_msecs(jiffies - up->port_activity) <
RX_TIMEOUT) {
mod_timer(&up->uart_dma.rx_timer, jiffies +
usecs_to_jiffies(up->uart_dma.rx_timeout));
} else {
serial_omap_stop_rxdma(up);
up->ier |= (UART_IER_RDI | UART_IER_RLSI);
serial_out(up, UART_IER, up->ier);
}
return;
}
curr_transmitted_size = curr_dma_pos -
up->uart_dma.prev_rx_dma_pos;
up->port.icount.rx += curr_transmitted_size;
tty_insert_flip_string(up->port.state->port.tty,
up->uart_dma.rx_buf +
(up->uart_dma.prev_rx_dma_pos -
up->uart_dma.rx_buf_dma_phys),
curr_transmitted_size);
tty_flip_buffer_push(up->port.state->port.tty);
up->uart_dma.prev_rx_dma_pos = curr_dma_pos;
if (up->uart_dma.rx_buf_size +
up->uart_dma.rx_buf_dma_phys == curr_dma_pos) {
ret = serial_omap_start_rxdma(up);
if (ret < 0) {
serial_omap_stop_rxdma(up);
up->ier |= (UART_IER_RDI | UART_IER_RLSI);
serial_out(up, UART_IER, up->ier);
}
} else {
mod_timer(&up->uart_dma.rx_timer, jiffies +
usecs_to_jiffies(up->uart_dma.rx_timeout));
}
up->port_activity = jiffies;
}
static void uart_rx_dma_callback(int lch, u16 ch_status, void *data)
{
return;
}
static int serial_omap_start_rxdma(struct uart_omap_port *up)
{
int ret = 0;
if (up->uart_dma.rx_dma_channel == -1) {
ret = omap_request_dma(up->uart_dma.uart_dma_rx,
"UART Rx DMA",
(void *)uart_rx_dma_callback, up,
&(up->uart_dma.rx_dma_channel));
if (ret < 0)
return ret;
omap_set_dma_src_params(up->uart_dma.rx_dma_channel, 0,
OMAP_DMA_AMODE_CONSTANT,
up->uart_dma.uart_base, 0, 0);
omap_set_dma_dest_params(up->uart_dma.rx_dma_channel, 0,
OMAP_DMA_AMODE_POST_INC,
up->uart_dma.rx_buf_dma_phys, 0, 0);
omap_set_dma_transfer_params(up->uart_dma.rx_dma_channel,
OMAP_DMA_DATA_TYPE_S8,
up->uart_dma.rx_buf_size, 1,
OMAP_DMA_SYNC_ELEMENT,
up->uart_dma.uart_dma_rx, 0);
}
up->uart_dma.prev_rx_dma_pos = up->uart_dma.rx_buf_dma_phys;
omap_start_dma(up->uart_dma.rx_dma_channel);
mod_timer(&up->uart_dma.rx_timer, jiffies +
usecs_to_jiffies(up->uart_dma.rx_timeout));
up->uart_dma.rx_dma_used = true;
return ret;
}
static void serial_omap_continue_tx(struct uart_omap_port *up)
{
struct circ_buf *xmit = &up->port.state->xmit;
unsigned int start = up->uart_dma.tx_buf_dma_phys
+ (xmit->tail & (UART_XMIT_SIZE - 1));
if (uart_circ_empty(xmit))
return;
up->uart_dma.tx_buf_size = uart_circ_chars_pending(xmit);
if (start + up->uart_dma.tx_buf_size >=
up->uart_dma.tx_buf_dma_phys + UART_XMIT_SIZE)
up->uart_dma.tx_buf_size =
(up->uart_dma.tx_buf_dma_phys + UART_XMIT_SIZE) - start;
omap_set_dma_dest_params(up->uart_dma.tx_dma_channel, 0,
OMAP_DMA_AMODE_CONSTANT,
up->uart_dma.uart_base, 0, 0);
omap_set_dma_src_params(up->uart_dma.tx_dma_channel, 0,
OMAP_DMA_AMODE_POST_INC, start, 0, 0);
omap_set_dma_transfer_params(up->uart_dma.tx_dma_channel,
OMAP_DMA_DATA_TYPE_S8,
up->uart_dma.tx_buf_size, 1,
OMAP_DMA_SYNC_ELEMENT,
up->uart_dma.uart_dma_tx, 0);
omap_start_dma(up->uart_dma.tx_dma_channel);
}
static void uart_tx_dma_callback(int lch, u16 ch_status, void *data)
{
struct uart_omap_port *up = (struct uart_omap_port *)data;
struct circ_buf *xmit = &up->port.state->xmit;
xmit->tail = (xmit->tail + up->uart_dma.tx_buf_size) & \
(UART_XMIT_SIZE - 1);
up->port.icount.tx += up->uart_dma.tx_buf_size;
if (uart_circ_chars_pending(xmit) < WAKEUP_CHARS)
uart_write_wakeup(&up->port);
if (uart_circ_empty(xmit)) {
spin_lock(&(up->uart_dma.tx_lock));
serial_omap_stop_tx(&up->port);
up->uart_dma.tx_dma_used = false;
spin_unlock(&(up->uart_dma.tx_lock));
} else {
omap_stop_dma(up->uart_dma.tx_dma_channel);
serial_omap_continue_tx(up);
}
up->port_activity = jiffies;
return;
}
static int serial_omap_probe(struct platform_device *pdev)
{
struct uart_omap_port *up;
struct resource *mem, *irq, *dma_tx, *dma_rx;
struct omap_uart_port_info *omap_up_info = pdev->dev.platform_data;
int ret = -ENOSPC;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -ENODEV;
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq) {
dev_err(&pdev->dev, "no irq resource?\n");
return -ENODEV;
}
if (!request_mem_region(mem->start, resource_size(mem),
pdev->dev.driver->name)) {
dev_err(&pdev->dev, "memory region already claimed\n");
return -EBUSY;
}
dma_rx = platform_get_resource_byname(pdev, IORESOURCE_DMA, "rx");
if (!dma_rx) {
ret = -EINVAL;
goto err;
}
dma_tx = platform_get_resource_byname(pdev, IORESOURCE_DMA, "tx");
if (!dma_tx) {
ret = -EINVAL;
goto err;
}
up = kzalloc(sizeof(*up), GFP_KERNEL);
if (up == NULL) {
ret = -ENOMEM;
goto do_release_region;
}
sprintf(up->name, "OMAP UART%d", pdev->id);
up->pdev = pdev;
up->port.dev = &pdev->dev;
up->port.type = PORT_OMAP;
up->port.iotype = UPIO_MEM;
up->port.irq = irq->start;
up->port.regshift = 2;
up->port.fifosize = 64;
up->port.ops = &serial_omap_pops;
up->port.line = pdev->id;
up->port.membase = omap_up_info->membase;
up->port.mapbase = omap_up_info->mapbase;
up->port.flags = omap_up_info->flags;
up->port.irqflags = omap_up_info->irqflags;
up->port.uartclk = omap_up_info->uartclk;
up->uart_dma.uart_base = mem->start;
if (omap_up_info->dma_enabled) {
up->uart_dma.uart_dma_tx = dma_tx->start;
up->uart_dma.uart_dma_rx = dma_rx->start;
up->use_dma = 1;
up->uart_dma.rx_buf_size = 4096;
up->uart_dma.rx_timeout = 2;
spin_lock_init(&(up->uart_dma.tx_lock));
spin_lock_init(&(up->uart_dma.rx_lock));
up->uart_dma.tx_dma_channel = OMAP_UART_DMA_CH_FREE;
up->uart_dma.rx_dma_channel = OMAP_UART_DMA_CH_FREE;
}
ui[pdev->id] = up;
serial_omap_add_console_port(up);
ret = uart_add_one_port(&serial_omap_reg, &up->port);
if (ret != 0)
goto do_release_region;
platform_set_drvdata(pdev, up);
return 0;
err:
dev_err(&pdev->dev, "[UART%d]: failure [%s]: %d\n",
pdev->id, __func__, ret);
do_release_region:
release_mem_region(mem->start, resource_size(mem));
return ret;
}
static int serial_omap_remove(struct platform_device *dev)
{
struct uart_omap_port *up = platform_get_drvdata(dev);
platform_set_drvdata(dev, NULL);
if (up) {
uart_remove_one_port(&serial_omap_reg, &up->port);
kfree(up);
}
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
