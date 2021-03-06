static int sdio_uart_add_port(struct sdio_uart_port *port)
{
int index, ret = -EBUSY;
kref_init(&port->kref);
mutex_init(&port->func_lock);
spin_lock_init(&port->write_lock);
if (kfifo_alloc(&port->xmit_fifo, FIFO_SIZE, GFP_KERNEL))
return -ENOMEM;
spin_lock(&sdio_uart_table_lock);
for (index = 0; index < UART_NR; index++) {
if (!sdio_uart_table[index]) {
port->index = index;
sdio_uart_table[index] = port;
ret = 0;
break;
}
}
spin_unlock(&sdio_uart_table_lock);
return ret;
}
static struct sdio_uart_port *sdio_uart_port_get(unsigned index)
{
struct sdio_uart_port *port;
if (index >= UART_NR)
return NULL;
spin_lock(&sdio_uart_table_lock);
port = sdio_uart_table[index];
if (port)
kref_get(&port->kref);
spin_unlock(&sdio_uart_table_lock);
return port;
}
static void sdio_uart_port_destroy(struct kref *kref)
{
struct sdio_uart_port *port =
container_of(kref, struct sdio_uart_port, kref);
kfifo_free(&port->xmit_fifo);
kfree(port);
}
static void sdio_uart_port_put(struct sdio_uart_port *port)
{
kref_put(&port->kref, sdio_uart_port_destroy);
}
static void sdio_uart_port_remove(struct sdio_uart_port *port)
{
struct sdio_func *func;
struct tty_struct *tty;
BUG_ON(sdio_uart_table[port->index] != port);
spin_lock(&sdio_uart_table_lock);
sdio_uart_table[port->index] = NULL;
spin_unlock(&sdio_uart_table_lock);
mutex_lock(&port->port.mutex);
mutex_lock(&port->func_lock);
func = port->func;
sdio_claim_host(func);
port->func = NULL;
mutex_unlock(&port->func_lock);
tty = tty_port_tty_get(&port->port);
if (tty) {
tty_hangup(tty);
tty_kref_put(tty);
}
mutex_unlock(&port->port.mutex);
sdio_release_irq(func);
sdio_disable_func(func);
sdio_release_host(func);
sdio_uart_port_put(port);
}
static int sdio_uart_claim_func(struct sdio_uart_port *port)
{
mutex_lock(&port->func_lock);
if (unlikely(!port->func)) {
mutex_unlock(&port->func_lock);
return -ENODEV;
}
if (likely(port->in_sdio_uart_irq != current))
sdio_claim_host(port->func);
mutex_unlock(&port->func_lock);
return 0;
}
static inline void sdio_uart_release_func(struct sdio_uart_port *port)
{
if (likely(port->in_sdio_uart_irq != current))
sdio_release_host(port->func);
}
static inline unsigned int sdio_in(struct sdio_uart_port *port, int offset)
{
unsigned char c;
c = sdio_readb(port->func, port->regs_offset + offset, NULL);
return c;
}
static inline void sdio_out(struct sdio_uart_port *port, int offset, int value)
{
sdio_writeb(port->func, value, port->regs_offset + offset, NULL);
}
static unsigned int sdio_uart_get_mctrl(struct sdio_uart_port *port)
{
unsigned char status;
unsigned int ret;
status = sdio_in(port, UART_MSR);
ret = 0;
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
static void sdio_uart_write_mctrl(struct sdio_uart_port *port,
unsigned int mctrl)
{
unsigned char mcr = 0;
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
sdio_out(port, UART_MCR, mcr);
}
static inline void sdio_uart_update_mctrl(struct sdio_uart_port *port,
unsigned int set, unsigned int clear)
{
unsigned int old;
old = port->mctrl;
port->mctrl = (old & ~clear) | set;
if (old != port->mctrl)
sdio_uart_write_mctrl(port, port->mctrl);
}
static void sdio_uart_change_speed(struct sdio_uart_port *port,
struct ktermios *termios,
struct ktermios *old)
{
unsigned char cval, fcr = 0;
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
for (;;) {
baud = tty_termios_baud_rate(termios);
if (baud == 0)
baud = 9600;
if (baud <= port->uartclk)
break;
termios->c_cflag &= ~CBAUD;
if (old) {
termios->c_cflag |= old->c_cflag & CBAUD;
old = NULL;
} else
termios->c_cflag |= B9600;
}
quot = (2 * port->uartclk + baud) / (2 * baud);
if (baud < 2400)
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_TRIGGER_1;
else
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_R_TRIG_10;
port->read_status_mask = UART_LSR_OE | UART_LSR_THRE | UART_LSR_DR;
if (termios->c_iflag & INPCK)
port->read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (termios->c_iflag & (BRKINT | PARMRK))
port->read_status_mask |= UART_LSR_BI;
port->ignore_status_mask = 0;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= UART_LSR_PE | UART_LSR_FE;
if (termios->c_iflag & IGNBRK) {
port->ignore_status_mask |= UART_LSR_BI;
if (termios->c_iflag & IGNPAR)
port->ignore_status_mask |= UART_LSR_OE;
}
if ((termios->c_cflag & CREAD) == 0)
port->ignore_status_mask |= UART_LSR_DR;
port->ier &= ~UART_IER_MSI;
if ((termios->c_cflag & CRTSCTS) || !(termios->c_cflag & CLOCAL))
port->ier |= UART_IER_MSI;
port->lcr = cval;
sdio_out(port, UART_IER, port->ier);
sdio_out(port, UART_LCR, cval | UART_LCR_DLAB);
sdio_out(port, UART_DLL, quot & 0xff);
sdio_out(port, UART_DLM, quot >> 8);
sdio_out(port, UART_LCR, cval);
sdio_out(port, UART_FCR, fcr);
sdio_uart_write_mctrl(port, port->mctrl);
}
static void sdio_uart_start_tx(struct sdio_uart_port *port)
{
if (!(port->ier & UART_IER_THRI)) {
port->ier |= UART_IER_THRI;
sdio_out(port, UART_IER, port->ier);
}
}
static void sdio_uart_stop_tx(struct sdio_uart_port *port)
{
if (port->ier & UART_IER_THRI) {
port->ier &= ~UART_IER_THRI;
sdio_out(port, UART_IER, port->ier);
}
}
static void sdio_uart_stop_rx(struct sdio_uart_port *port)
{
port->ier &= ~UART_IER_RLSI;
port->read_status_mask &= ~UART_LSR_DR;
sdio_out(port, UART_IER, port->ier);
}
static void sdio_uart_receive_chars(struct sdio_uart_port *port,
unsigned int *status)
{
struct tty_struct *tty = tty_port_tty_get(&port->port);
unsigned int ch, flag;
int max_count = 256;
do {
ch = sdio_in(port, UART_RX);
flag = TTY_NORMAL;
port->icount.rx++;
if (unlikely(*status & (UART_LSR_BI | UART_LSR_PE |
UART_LSR_FE | UART_LSR_OE))) {
if (*status & UART_LSR_BI) {
*status &= ~(UART_LSR_FE | UART_LSR_PE);
port->icount.brk++;
} else if (*status & UART_LSR_PE)
port->icount.parity++;
else if (*status & UART_LSR_FE)
port->icount.frame++;
if (*status & UART_LSR_OE)
port->icount.overrun++;
*status &= port->read_status_mask;
if (*status & UART_LSR_BI)
flag = TTY_BREAK;
else if (*status & UART_LSR_PE)
flag = TTY_PARITY;
else if (*status & UART_LSR_FE)
flag = TTY_FRAME;
}
if ((*status & port->ignore_status_mask & ~UART_LSR_OE) == 0)
if (tty)
tty_insert_flip_char(tty, ch, flag);
if (*status & ~port->ignore_status_mask & UART_LSR_OE)
if (tty)
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
*status = sdio_in(port, UART_LSR);
} while ((*status & UART_LSR_DR) && (max_count-- > 0));
if (tty) {
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
}
static void sdio_uart_transmit_chars(struct sdio_uart_port *port)
{
struct kfifo *xmit = &port->xmit_fifo;
int count;
struct tty_struct *tty;
u8 iobuf[16];
int len;
if (port->x_char) {
sdio_out(port, UART_TX, port->x_char);
port->icount.tx++;
port->x_char = 0;
return;
}
tty = tty_port_tty_get(&port->port);
if (tty == NULL || !kfifo_len(xmit) ||
tty->stopped || tty->hw_stopped) {
sdio_uart_stop_tx(port);
tty_kref_put(tty);
return;
}
len = kfifo_out_locked(xmit, iobuf, 16, &port->write_lock);
for (count = 0; count < len; count++) {
sdio_out(port, UART_TX, iobuf[count]);
port->icount.tx++;
}
len = kfifo_len(xmit);
if (len < WAKEUP_CHARS) {
tty_wakeup(tty);
if (len == 0)
sdio_uart_stop_tx(port);
}
tty_kref_put(tty);
}
static void sdio_uart_check_modem_status(struct sdio_uart_port *port)
{
int status;
struct tty_struct *tty;
status = sdio_in(port, UART_MSR);
if ((status & UART_MSR_ANY_DELTA) == 0)
return;
if (status & UART_MSR_TERI)
port->icount.rng++;
if (status & UART_MSR_DDSR)
port->icount.dsr++;
if (status & UART_MSR_DDCD) {
port->icount.dcd++;
if (status & UART_MSR_DCD)
wake_up_interruptible(&port->port.open_wait);
else {
tty = tty_port_tty_get(&port->port);
if (tty) {
tty_hangup(tty);
tty_kref_put(tty);
}
}
}
if (status & UART_MSR_DCTS) {
port->icount.cts++;
tty = tty_port_tty_get(&port->port);
if (tty && (tty->termios->c_cflag & CRTSCTS)) {
int cts = (status & UART_MSR_CTS);
if (tty->hw_stopped) {
if (cts) {
tty->hw_stopped = 0;
sdio_uart_start_tx(port);
tty_wakeup(tty);
}
} else {
if (!cts) {
tty->hw_stopped = 1;
sdio_uart_stop_tx(port);
}
}
}
tty_kref_put(tty);
}
}
static void sdio_uart_irq(struct sdio_func *func)
{
struct sdio_uart_port *port = sdio_get_drvdata(func);
unsigned int iir, lsr;
if (unlikely(port->in_sdio_uart_irq == current))
return;
iir = sdio_in(port, UART_IIR);
if (iir & UART_IIR_NO_INT)
return;
port->in_sdio_uart_irq = current;
lsr = sdio_in(port, UART_LSR);
if (lsr & UART_LSR_DR)
sdio_uart_receive_chars(port, &lsr);
sdio_uart_check_modem_status(port);
if (lsr & UART_LSR_THRE)
sdio_uart_transmit_chars(port);
port->in_sdio_uart_irq = NULL;
}
static int uart_carrier_raised(struct tty_port *tport)
{
struct sdio_uart_port *port =
container_of(tport, struct sdio_uart_port, port);
unsigned int ret = sdio_uart_claim_func(port);
if (ret)
return 1;
ret = sdio_uart_get_mctrl(port);
sdio_uart_release_func(port);
if (ret & TIOCM_CAR)
return 1;
return 0;
}
static void uart_dtr_rts(struct tty_port *tport, int onoff)
{
struct sdio_uart_port *port =
container_of(tport, struct sdio_uart_port, port);
int ret = sdio_uart_claim_func(port);
if (ret)
return;
if (onoff == 0)
sdio_uart_clear_mctrl(port, TIOCM_DTR | TIOCM_RTS);
else
sdio_uart_set_mctrl(port, TIOCM_DTR | TIOCM_RTS);
sdio_uart_release_func(port);
}
static int sdio_uart_activate(struct tty_port *tport, struct tty_struct *tty)
{
struct sdio_uart_port *port =
container_of(tport, struct sdio_uart_port, port);
int ret;
set_bit(TTY_IO_ERROR, &tty->flags);
kfifo_reset(&port->xmit_fifo);
ret = sdio_uart_claim_func(port);
if (ret)
return ret;
ret = sdio_enable_func(port->func);
if (ret)
goto err1;
ret = sdio_claim_irq(port->func, sdio_uart_irq);
if (ret)
goto err2;
sdio_out(port, UART_FCR, UART_FCR_ENABLE_FIFO);
sdio_out(port, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT);
sdio_out(port, UART_FCR, 0);
(void) sdio_in(port, UART_LSR);
(void) sdio_in(port, UART_RX);
(void) sdio_in(port, UART_IIR);
(void) sdio_in(port, UART_MSR);
sdio_out(port, UART_LCR, UART_LCR_WLEN8);
port->ier = UART_IER_RLSI|UART_IER_RDI|UART_IER_RTOIE|UART_IER_UUE;
port->mctrl = TIOCM_OUT2;
sdio_uart_change_speed(port, tty->termios, NULL);
if (tty->termios->c_cflag & CBAUD)
sdio_uart_set_mctrl(port, TIOCM_RTS | TIOCM_DTR);
if (tty->termios->c_cflag & CRTSCTS)
if (!(sdio_uart_get_mctrl(port) & TIOCM_CTS))
tty->hw_stopped = 1;
clear_bit(TTY_IO_ERROR, &tty->flags);
sdio_uart_irq(port->func);
sdio_uart_release_func(port);
return 0;
err2:
sdio_disable_func(port->func);
err1:
sdio_uart_release_func(port);
return ret;
}
static void sdio_uart_shutdown(struct tty_port *tport)
{
struct sdio_uart_port *port =
container_of(tport, struct sdio_uart_port, port);
int ret;
ret = sdio_uart_claim_func(port);
if (ret)
return;
sdio_uart_stop_rx(port);
sdio_release_irq(port->func);
port->ier = 0;
sdio_out(port, UART_IER, 0);
sdio_uart_clear_mctrl(port, TIOCM_OUT2);
port->lcr &= ~UART_LCR_SBC;
sdio_out(port, UART_LCR, port->lcr);
sdio_out(port, UART_FCR, UART_FCR_ENABLE_FIFO |
UART_FCR_CLEAR_RCVR |
UART_FCR_CLEAR_XMIT);
sdio_out(port, UART_FCR, 0);
sdio_disable_func(port->func);
sdio_uart_release_func(port);
}
static int sdio_uart_install(struct tty_driver *driver, struct tty_struct *tty)
{
int idx = tty->index;
struct sdio_uart_port *port = sdio_uart_port_get(idx);
int ret = tty_init_termios(tty);
if (ret == 0) {
tty_driver_kref_get(driver);
tty->count++;
tty->driver_data = port;
driver->ttys[idx] = tty;
} else
sdio_uart_port_put(port);
return ret;
}
static void sdio_uart_cleanup(struct tty_struct *tty)
{
struct sdio_uart_port *port = tty->driver_data;
tty->driver_data = NULL;
sdio_uart_port_put(port);
}
static int sdio_uart_open(struct tty_struct *tty, struct file *filp)
{
struct sdio_uart_port *port = tty->driver_data;
return tty_port_open(&port->port, tty, filp);
}
static void sdio_uart_close(struct tty_struct *tty, struct file * filp)
{
struct sdio_uart_port *port = tty->driver_data;
tty_port_close(&port->port, tty, filp);
}
static void sdio_uart_hangup(struct tty_struct *tty)
{
struct sdio_uart_port *port = tty->driver_data;
tty_port_hangup(&port->port);
}
static int sdio_uart_write(struct tty_struct *tty, const unsigned char *buf,
int count)
{
struct sdio_uart_port *port = tty->driver_data;
int ret;
if (!port->func)
return -ENODEV;
ret = kfifo_in_locked(&port->xmit_fifo, buf, count, &port->write_lock);
if (!(port->ier & UART_IER_THRI)) {
int err = sdio_uart_claim_func(port);
if (!err) {
sdio_uart_start_tx(port);
sdio_uart_irq(port->func);
sdio_uart_release_func(port);
} else
ret = err;
}
return ret;
}
static int sdio_uart_write_room(struct tty_struct *tty)
{
struct sdio_uart_port *port = tty->driver_data;
return FIFO_SIZE - kfifo_len(&port->xmit_fifo);
}
static int sdio_uart_chars_in_buffer(struct tty_struct *tty)
{
struct sdio_uart_port *port = tty->driver_data;
return kfifo_len(&port->xmit_fifo);
}
static void sdio_uart_send_xchar(struct tty_struct *tty, char ch)
{
struct sdio_uart_port *port = tty->driver_data;
port->x_char = ch;
if (ch && !(port->ier & UART_IER_THRI)) {
if (sdio_uart_claim_func(port) != 0)
return;
sdio_uart_start_tx(port);
sdio_uart_irq(port->func);
sdio_uart_release_func(port);
}
}
static void sdio_uart_throttle(struct tty_struct *tty)
{
struct sdio_uart_port *port = tty->driver_data;
if (!I_IXOFF(tty) && !(tty->termios->c_cflag & CRTSCTS))
return;
if (sdio_uart_claim_func(port) != 0)
return;
if (I_IXOFF(tty)) {
port->x_char = STOP_CHAR(tty);
sdio_uart_start_tx(port);
}
if (tty->termios->c_cflag & CRTSCTS)
sdio_uart_clear_mctrl(port, TIOCM_RTS);
sdio_uart_irq(port->func);
sdio_uart_release_func(port);
}
static void sdio_uart_unthrottle(struct tty_struct *tty)
{
struct sdio_uart_port *port = tty->driver_data;
if (!I_IXOFF(tty) && !(tty->termios->c_cflag & CRTSCTS))
return;
if (sdio_uart_claim_func(port) != 0)
return;
if (I_IXOFF(tty)) {
if (port->x_char) {
port->x_char = 0;
} else {
port->x_char = START_CHAR(tty);
sdio_uart_start_tx(port);
}
}
if (tty->termios->c_cflag & CRTSCTS)
sdio_uart_set_mctrl(port, TIOCM_RTS);
sdio_uart_irq(port->func);
sdio_uart_release_func(port);
}
static void sdio_uart_set_termios(struct tty_struct *tty,
struct ktermios *old_termios)
{
struct sdio_uart_port *port = tty->driver_data;
unsigned int cflag = tty->termios->c_cflag;
if (sdio_uart_claim_func(port) != 0)
return;
sdio_uart_change_speed(port, tty->termios, old_termios);
if ((old_termios->c_cflag & CBAUD) && !(cflag & CBAUD))
sdio_uart_clear_mctrl(port, TIOCM_RTS | TIOCM_DTR);
if (!(old_termios->c_cflag & CBAUD) && (cflag & CBAUD)) {
unsigned int mask = TIOCM_DTR;
if (!(cflag & CRTSCTS) || !test_bit(TTY_THROTTLED, &tty->flags))
mask |= TIOCM_RTS;
sdio_uart_set_mctrl(port, mask);
}
if ((old_termios->c_cflag & CRTSCTS) && !(cflag & CRTSCTS)) {
tty->hw_stopped = 0;
sdio_uart_start_tx(port);
}
if (!(old_termios->c_cflag & CRTSCTS) && (cflag & CRTSCTS)) {
if (!(sdio_uart_get_mctrl(port) & TIOCM_CTS)) {
tty->hw_stopped = 1;
sdio_uart_stop_tx(port);
}
}
sdio_uart_release_func(port);
}
static int sdio_uart_break_ctl(struct tty_struct *tty, int break_state)
{
struct sdio_uart_port *port = tty->driver_data;
int result;
result = sdio_uart_claim_func(port);
if (result != 0)
return result;
if (break_state == -1)
port->lcr |= UART_LCR_SBC;
else
port->lcr &= ~UART_LCR_SBC;
sdio_out(port, UART_LCR, port->lcr);
sdio_uart_release_func(port);
return 0;
}
static int sdio_uart_tiocmget(struct tty_struct *tty)
{
struct sdio_uart_port *port = tty->driver_data;
int result;
result = sdio_uart_claim_func(port);
if (!result) {
result = port->mctrl | sdio_uart_get_mctrl(port);
sdio_uart_release_func(port);
}
return result;
}
static int sdio_uart_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct sdio_uart_port *port = tty->driver_data;
int result;
result = sdio_uart_claim_func(port);
if (!result) {
sdio_uart_update_mctrl(port, set, clear);
sdio_uart_release_func(port);
}
return result;
}
static int sdio_uart_proc_show(struct seq_file *m, void *v)
{
int i;
seq_printf(m, "serinfo:1.0 driver%s%s revision:%s\n",
"", "", "");
for (i = 0; i < UART_NR; i++) {
struct sdio_uart_port *port = sdio_uart_port_get(i);
if (port) {
seq_printf(m, "%d: uart:SDIO", i);
if (capable(CAP_SYS_ADMIN)) {
seq_printf(m, " tx:%d rx:%d",
port->icount.tx, port->icount.rx);
if (port->icount.frame)
seq_printf(m, " fe:%d",
port->icount.frame);
if (port->icount.parity)
seq_printf(m, " pe:%d",
port->icount.parity);
if (port->icount.brk)
seq_printf(m, " brk:%d",
port->icount.brk);
if (port->icount.overrun)
seq_printf(m, " oe:%d",
port->icount.overrun);
if (port->icount.cts)
seq_printf(m, " cts:%d",
port->icount.cts);
if (port->icount.dsr)
seq_printf(m, " dsr:%d",
port->icount.dsr);
if (port->icount.rng)
seq_printf(m, " rng:%d",
port->icount.rng);
if (port->icount.dcd)
seq_printf(m, " dcd:%d",
port->icount.dcd);
}
sdio_uart_port_put(port);
seq_putc(m, '\n');
}
}
return 0;
}
static int sdio_uart_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, sdio_uart_proc_show, NULL);
}
static int sdio_uart_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
struct sdio_uart_port *port;
int ret;
port = kzalloc(sizeof(struct sdio_uart_port), GFP_KERNEL);
if (!port)
return -ENOMEM;
if (func->class == SDIO_CLASS_UART) {
pr_warning("%s: need info on UART class basic setup\n",
sdio_func_id(func));
kfree(port);
return -ENOSYS;
} else if (func->class == SDIO_CLASS_GPS) {
struct sdio_func_tuple *tpl;
for (tpl = func->tuples; tpl; tpl = tpl->next) {
if (tpl->code != 0x91)
continue;
if (tpl->size < 10)
continue;
if (tpl->data[1] == 0)
break;
}
if (!tpl) {
pr_warning(
"%s: can't find tuple 0x91 subtuple 0 (SUBTPL_SIOREG) for GPS class\n",
sdio_func_id(func));
kfree(port);
return -EINVAL;
}
pr_debug("%s: Register ID = 0x%02x, Exp ID = 0x%02x\n",
sdio_func_id(func), tpl->data[2], tpl->data[3]);
port->regs_offset = (tpl->data[4] << 0) |
(tpl->data[5] << 8) |
(tpl->data[6] << 16);
pr_debug("%s: regs offset = 0x%x\n",
sdio_func_id(func), port->regs_offset);
port->uartclk = tpl->data[7] * 115200;
if (port->uartclk == 0)
port->uartclk = 115200;
pr_debug("%s: clk %d baudcode %u 4800-div %u\n",
sdio_func_id(func), port->uartclk,
tpl->data[7], tpl->data[8] | (tpl->data[9] << 8));
} else {
kfree(port);
return -EINVAL;
}
port->func = func;
sdio_set_drvdata(func, port);
tty_port_init(&port->port);
port->port.ops = &sdio_uart_port_ops;
ret = sdio_uart_add_port(port);
if (ret) {
kfree(port);
} else {
struct device *dev;
dev = tty_register_device(sdio_uart_tty_driver,
port->index, &func->dev);
if (IS_ERR(dev)) {
sdio_uart_port_remove(port);
ret = PTR_ERR(dev);
}
}
return ret;
}
static void sdio_uart_remove(struct sdio_func *func)
{
struct sdio_uart_port *port = sdio_get_drvdata(func);
tty_unregister_device(sdio_uart_tty_driver, port->index);
sdio_uart_port_remove(port);
}
static int __init sdio_uart_init(void)
{
int ret;
struct tty_driver *tty_drv;
sdio_uart_tty_driver = tty_drv = alloc_tty_driver(UART_NR);
if (!tty_drv)
return -ENOMEM;
tty_drv->owner = THIS_MODULE;
tty_drv->driver_name = "sdio_uart";
tty_drv->name = "ttySDIO";
tty_drv->major = 0;
tty_drv->minor_start = 0;
tty_drv->type = TTY_DRIVER_TYPE_SERIAL;
tty_drv->subtype = SERIAL_TYPE_NORMAL;
tty_drv->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty_drv->init_termios = tty_std_termios;
tty_drv->init_termios.c_cflag = B4800 | CS8 | CREAD | HUPCL | CLOCAL;
tty_drv->init_termios.c_ispeed = 4800;
tty_drv->init_termios.c_ospeed = 4800;
tty_set_operations(tty_drv, &sdio_uart_ops);
ret = tty_register_driver(tty_drv);
if (ret)
goto err1;
ret = sdio_register_driver(&sdio_uart_driver);
if (ret)
goto err2;
return 0;
err2:
tty_unregister_driver(tty_drv);
err1:
put_tty_driver(tty_drv);
return ret;
}
static void __exit sdio_uart_exit(void)
{
sdio_unregister_driver(&sdio_uart_driver);
tty_unregister_driver(sdio_uart_tty_driver);
put_tty_driver(sdio_uart_tty_driver);
}
