static inline int serial_paranoia_check(struct serial_state *info,
char *name, const char *routine)
{
#ifdef SERIAL_PARANOIA_CHECK
static const char *badmagic =
"Warning: bad magic number for serial struct (%s) in %s\n";
static const char *badinfo =
"Warning: null async_struct for (%s) in %s\n";
if (!info) {
printk(badinfo, name, routine);
return 1;
}
if (info->magic != SERIAL_MAGIC) {
printk(badmagic, name, routine);
return 1;
}
#endif
return 0;
}
static __inline__ void rtsdtr_ctrl(int bits)
{
ciab.pra = ((bits & (SER_RTS | SER_DTR)) ^ (SER_RTS | SER_DTR)) | (ciab.pra & ~(SER_RTS | SER_DTR));
}
static void rs_stop(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_stop"))
return;
local_irq_save(flags);
if (info->IER & UART_IER_THRI) {
info->IER &= ~UART_IER_THRI;
custom.intena = IF_TBE;
mb();
custom.intreq = IF_TBE;
mb();
}
local_irq_restore(flags);
}
static void rs_start(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_start"))
return;
local_irq_save(flags);
if (info->xmit.head != info->xmit.tail
&& info->xmit.buf
&& !(info->IER & UART_IER_THRI)) {
info->IER |= UART_IER_THRI;
custom.intena = IF_SETCLR | IF_TBE;
mb();
custom.intreq = IF_SETCLR | IF_TBE;
mb();
}
local_irq_restore(flags);
}
static void receive_chars(struct serial_state *info)
{
int status;
int serdatr;
unsigned char ch, flag;
struct async_icount *icount;
int oe = 0;
icount = &info->icount;
status = UART_LSR_DR;
serdatr = custom.serdatr;
mb();
custom.intreq = IF_RBF;
mb();
if((serdatr & 0x1ff) == 0)
status |= UART_LSR_BI;
if(serdatr & SDR_OVRUN)
status |= UART_LSR_OE;
ch = serdatr & 0xff;
icount->rx++;
#ifdef SERIAL_DEBUG_INTR
printk("DR%02x:%02x...", ch, status);
#endif
flag = TTY_NORMAL;
if (status & (UART_LSR_BI | UART_LSR_PE |
UART_LSR_FE | UART_LSR_OE)) {
if (status & UART_LSR_BI) {
status &= ~(UART_LSR_FE | UART_LSR_PE);
icount->brk++;
} else if (status & UART_LSR_PE)
icount->parity++;
else if (status & UART_LSR_FE)
icount->frame++;
if (status & UART_LSR_OE)
icount->overrun++;
if (status & info->ignore_status_mask)
goto out;
status &= info->read_status_mask;
if (status & (UART_LSR_BI)) {
#ifdef SERIAL_DEBUG_INTR
printk("handling break....");
#endif
flag = TTY_BREAK;
if (info->tport.flags & ASYNC_SAK)
do_SAK(info->tport.tty);
} else if (status & UART_LSR_PE)
flag = TTY_PARITY;
else if (status & UART_LSR_FE)
flag = TTY_FRAME;
if (status & UART_LSR_OE) {
oe = 1;
}
}
tty_insert_flip_char(&info->tport, ch, flag);
if (oe == 1)
tty_insert_flip_char(&info->tport, 0, TTY_OVERRUN);
tty_flip_buffer_push(&info->tport);
out:
return;
}
static void transmit_chars(struct serial_state *info)
{
custom.intreq = IF_TBE;
mb();
if (info->x_char) {
custom.serdat = info->x_char | 0x100;
mb();
info->icount.tx++;
info->x_char = 0;
return;
}
if (info->xmit.head == info->xmit.tail
|| info->tport.tty->stopped
|| info->tport.tty->hw_stopped) {
info->IER &= ~UART_IER_THRI;
custom.intena = IF_TBE;
mb();
return;
}
custom.serdat = info->xmit.buf[info->xmit.tail++] | 0x100;
mb();
info->xmit.tail = info->xmit.tail & (SERIAL_XMIT_SIZE-1);
info->icount.tx++;
if (CIRC_CNT(info->xmit.head,
info->xmit.tail,
SERIAL_XMIT_SIZE) < WAKEUP_CHARS)
tty_wakeup(info->tport.tty);
#ifdef SERIAL_DEBUG_INTR
printk("THRE...");
#endif
if (info->xmit.head == info->xmit.tail) {
custom.intena = IF_TBE;
mb();
info->IER &= ~UART_IER_THRI;
}
}
static void check_modem_status(struct serial_state *info)
{
struct tty_port *port = &info->tport;
unsigned char status = ciab.pra & (SER_DCD | SER_CTS | SER_DSR);
unsigned char dstatus;
struct async_icount *icount;
dstatus = status ^ current_ctl_bits;
current_ctl_bits = status;
if (dstatus) {
icount = &info->icount;
if (dstatus & SER_DSR)
icount->dsr++;
if (dstatus & SER_DCD) {
icount->dcd++;
}
if (dstatus & SER_CTS)
icount->cts++;
wake_up_interruptible(&port->delta_msr_wait);
}
if ((port->flags & ASYNC_CHECK_CD) && (dstatus & SER_DCD)) {
#if (defined(SERIAL_DEBUG_OPEN) || defined(SERIAL_DEBUG_INTR))
printk("ttyS%d CD now %s...", info->line,
(!(status & SER_DCD)) ? "on" : "off");
#endif
if (!(status & SER_DCD))
wake_up_interruptible(&port->open_wait);
else {
#ifdef SERIAL_DEBUG_OPEN
printk("doing serial hangup...");
#endif
if (port->tty)
tty_hangup(port->tty);
}
}
if (tty_port_cts_enabled(port)) {
if (port->tty->hw_stopped) {
if (!(status & SER_CTS)) {
#if (defined(SERIAL_DEBUG_INTR) || defined(SERIAL_DEBUG_FLOW))
printk("CTS tx start...");
#endif
port->tty->hw_stopped = 0;
info->IER |= UART_IER_THRI;
custom.intena = IF_SETCLR | IF_TBE;
mb();
custom.intreq = IF_SETCLR | IF_TBE;
mb();
tty_wakeup(port->tty);
return;
}
} else {
if ((status & SER_CTS)) {
#if (defined(SERIAL_DEBUG_INTR) || defined(SERIAL_DEBUG_FLOW))
printk("CTS tx stop...");
#endif
port->tty->hw_stopped = 1;
info->IER &= ~UART_IER_THRI;
custom.intena = IF_TBE;
mb();
custom.intreq = IF_TBE;
mb();
}
}
}
}
static irqreturn_t ser_vbl_int( int irq, void *data)
{
struct serial_state *info = data;
if(info->IER & UART_IER_MSI)
check_modem_status(info);
return IRQ_HANDLED;
}
static irqreturn_t ser_rx_int(int irq, void *dev_id)
{
struct serial_state *info = dev_id;
#ifdef SERIAL_DEBUG_INTR
printk("ser_rx_int...");
#endif
if (!info->tport.tty)
return IRQ_NONE;
receive_chars(info);
#ifdef SERIAL_DEBUG_INTR
printk("end.\n");
#endif
return IRQ_HANDLED;
}
static irqreturn_t ser_tx_int(int irq, void *dev_id)
{
struct serial_state *info = dev_id;
if (custom.serdatr & SDR_TBE) {
#ifdef SERIAL_DEBUG_INTR
printk("ser_tx_int...");
#endif
if (!info->tport.tty)
return IRQ_NONE;
transmit_chars(info);
#ifdef SERIAL_DEBUG_INTR
printk("end.\n");
#endif
}
return IRQ_HANDLED;
}
static int startup(struct tty_struct *tty, struct serial_state *info)
{
struct tty_port *port = &info->tport;
unsigned long flags;
int retval=0;
unsigned long page;
page = get_zeroed_page(GFP_KERNEL);
if (!page)
return -ENOMEM;
local_irq_save(flags);
if (port->flags & ASYNC_INITIALIZED) {
free_page(page);
goto errout;
}
if (info->xmit.buf)
free_page(page);
else
info->xmit.buf = (unsigned char *) page;
#ifdef SERIAL_DEBUG_OPEN
printk("starting up ttys%d ...", info->line);
#endif
custom.intreq = IF_RBF;
mb();
retval = request_irq(IRQ_AMIGA_VERTB, ser_vbl_int, 0, "serial status", info);
if (retval) {
if (serial_isroot()) {
set_bit(TTY_IO_ERROR, &tty->flags);
retval = 0;
}
goto errout;
}
custom.intena = IF_SETCLR | IF_RBF | IF_TBE;
mb();
info->IER = UART_IER_MSI;
current_ctl_bits = ciab.pra & (SER_DCD | SER_CTS | SER_DSR);
info->MCR = 0;
if (C_BAUD(tty))
info->MCR = SER_DTR | SER_RTS;
rtsdtr_ctrl(info->MCR);
clear_bit(TTY_IO_ERROR, &tty->flags);
info->xmit.head = info->xmit.tail = 0;
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
tty->alt_speed = 57600;
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
tty->alt_speed = 115200;
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
tty->alt_speed = 230400;
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
tty->alt_speed = 460800;
change_speed(tty, info, NULL);
port->flags |= ASYNC_INITIALIZED;
local_irq_restore(flags);
return 0;
errout:
local_irq_restore(flags);
return retval;
}
static void shutdown(struct tty_struct *tty, struct serial_state *info)
{
unsigned long flags;
struct serial_state *state;
if (!(info->tport.flags & ASYNC_INITIALIZED))
return;
state = info;
#ifdef SERIAL_DEBUG_OPEN
printk("Shutting down serial port %d ....\n", info->line);
#endif
local_irq_save(flags);
wake_up_interruptible(&info->tport.delta_msr_wait);
free_irq(IRQ_AMIGA_VERTB, info);
if (info->xmit.buf) {
free_page((unsigned long) info->xmit.buf);
info->xmit.buf = NULL;
}
info->IER = 0;
custom.intena = IF_RBF | IF_TBE;
mb();
custom.adkcon = AC_UARTBRK;
mb();
if (C_HUPCL(tty))
info->MCR &= ~(SER_DTR|SER_RTS);
rtsdtr_ctrl(info->MCR);
set_bit(TTY_IO_ERROR, &tty->flags);
info->tport.flags &= ~ASYNC_INITIALIZED;
local_irq_restore(flags);
}
static void change_speed(struct tty_struct *tty, struct serial_state *info,
struct ktermios *old_termios)
{
struct tty_port *port = &info->tport;
int quot = 0, baud_base, baud;
unsigned cflag, cval = 0;
int bits;
unsigned long flags;
cflag = tty->termios.c_cflag;
cval = 3; bits = 10;
if (cflag & CSTOPB) {
cval |= 0x04;
bits++;
}
if (cflag & PARENB) {
cval |= UART_LCR_PARITY;
bits++;
}
if (!(cflag & PARODD))
cval |= UART_LCR_EPAR;
#ifdef CMSPAR
if (cflag & CMSPAR)
cval |= UART_LCR_SPAR;
#endif
baud = tty_get_baud_rate(tty);
if (!baud)
baud = 9600;
baud_base = info->baud_base;
if (baud == 38400 && (port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST)
quot = info->custom_divisor;
else {
if (baud == 134)
quot = (2*baud_base / 269);
else if (baud)
quot = baud_base / baud;
}
if (!quot && old_termios) {
tty->termios.c_cflag &= ~CBAUD;
tty->termios.c_cflag |= (old_termios->c_cflag & CBAUD);
baud = tty_get_baud_rate(tty);
if (!baud)
baud = 9600;
if (baud == 38400 &&
(port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST)
quot = info->custom_divisor;
else {
if (baud == 134)
quot = (2*baud_base / 269);
else if (baud)
quot = baud_base / baud;
}
}
if (!quot)
quot = baud_base / 9600;
info->quot = quot;
info->timeout = ((info->xmit_fifo_size*HZ*bits*quot) / baud_base);
info->timeout += HZ/50;
info->IER &= ~UART_IER_MSI;
if (port->flags & ASYNC_HARDPPS_CD)
info->IER |= UART_IER_MSI;
if (cflag & CRTSCTS) {
port->flags |= ASYNC_CTS_FLOW;
info->IER |= UART_IER_MSI;
} else
port->flags &= ~ASYNC_CTS_FLOW;
if (cflag & CLOCAL)
port->flags &= ~ASYNC_CHECK_CD;
else {
port->flags |= ASYNC_CHECK_CD;
info->IER |= UART_IER_MSI;
}
info->read_status_mask = UART_LSR_OE | UART_LSR_DR;
if (I_INPCK(tty))
info->read_status_mask |= UART_LSR_FE | UART_LSR_PE;
if (I_BRKINT(tty) || I_PARMRK(tty))
info->read_status_mask |= UART_LSR_BI;
info->ignore_status_mask = 0;
if (I_IGNPAR(tty))
info->ignore_status_mask |= UART_LSR_PE | UART_LSR_FE;
if (I_IGNBRK(tty)) {
info->ignore_status_mask |= UART_LSR_BI;
if (I_IGNPAR(tty))
info->ignore_status_mask |= UART_LSR_OE;
}
if ((cflag & CREAD) == 0)
info->ignore_status_mask |= UART_LSR_DR;
local_irq_save(flags);
{
short serper;
serper = quot - 1;
if(cval & UART_LCR_PARITY)
serper |= (SERPER_PARENB);
custom.serper = serper;
mb();
}
local_irq_restore(flags);
}
static int rs_put_char(struct tty_struct *tty, unsigned char ch)
{
struct serial_state *info;
unsigned long flags;
info = tty->driver_data;
if (serial_paranoia_check(info, tty->name, "rs_put_char"))
return 0;
if (!info->xmit.buf)
return 0;
local_irq_save(flags);
if (CIRC_SPACE(info->xmit.head,
info->xmit.tail,
SERIAL_XMIT_SIZE) == 0) {
local_irq_restore(flags);
return 0;
}
info->xmit.buf[info->xmit.head++] = ch;
info->xmit.head &= SERIAL_XMIT_SIZE-1;
local_irq_restore(flags);
return 1;
}
static void rs_flush_chars(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_flush_chars"))
return;
if (info->xmit.head == info->xmit.tail
|| tty->stopped
|| tty->hw_stopped
|| !info->xmit.buf)
return;
local_irq_save(flags);
info->IER |= UART_IER_THRI;
custom.intena = IF_SETCLR | IF_TBE;
mb();
custom.intreq = IF_SETCLR | IF_TBE;
mb();
local_irq_restore(flags);
}
static int rs_write(struct tty_struct * tty, const unsigned char *buf, int count)
{
int c, ret = 0;
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_write"))
return 0;
if (!info->xmit.buf)
return 0;
local_irq_save(flags);
while (1) {
c = CIRC_SPACE_TO_END(info->xmit.head,
info->xmit.tail,
SERIAL_XMIT_SIZE);
if (count < c)
c = count;
if (c <= 0) {
break;
}
memcpy(info->xmit.buf + info->xmit.head, buf, c);
info->xmit.head = ((info->xmit.head + c) &
(SERIAL_XMIT_SIZE-1));
buf += c;
count -= c;
ret += c;
}
local_irq_restore(flags);
if (info->xmit.head != info->xmit.tail
&& !tty->stopped
&& !tty->hw_stopped
&& !(info->IER & UART_IER_THRI)) {
info->IER |= UART_IER_THRI;
local_irq_disable();
custom.intena = IF_SETCLR | IF_TBE;
mb();
custom.intreq = IF_SETCLR | IF_TBE;
mb();
local_irq_restore(flags);
}
return ret;
}
static int rs_write_room(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
if (serial_paranoia_check(info, tty->name, "rs_write_room"))
return 0;
return CIRC_SPACE(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static int rs_chars_in_buffer(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
if (serial_paranoia_check(info, tty->name, "rs_chars_in_buffer"))
return 0;
return CIRC_CNT(info->xmit.head, info->xmit.tail, SERIAL_XMIT_SIZE);
}
static void rs_flush_buffer(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_flush_buffer"))
return;
local_irq_save(flags);
info->xmit.head = info->xmit.tail = 0;
local_irq_restore(flags);
tty_wakeup(tty);
}
static void rs_send_xchar(struct tty_struct *tty, char ch)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_send_xchar"))
return;
info->x_char = ch;
if (ch) {
local_irq_save(flags);
if(!(custom.intenar & IF_TBE)) {
custom.intena = IF_SETCLR | IF_TBE;
mb();
custom.intreq = IF_SETCLR | IF_TBE;
mb();
}
local_irq_restore(flags);
info->IER |= UART_IER_THRI;
}
}
static void rs_throttle(struct tty_struct * tty)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
#ifdef SERIAL_DEBUG_THROTTLE
printk("throttle %s ....\n", tty_name(tty));
#endif
if (serial_paranoia_check(info, tty->name, "rs_throttle"))
return;
if (I_IXOFF(tty))
rs_send_xchar(tty, STOP_CHAR(tty));
if (C_CRTSCTS(tty))
info->MCR &= ~SER_RTS;
local_irq_save(flags);
rtsdtr_ctrl(info->MCR);
local_irq_restore(flags);
}
static void rs_unthrottle(struct tty_struct * tty)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
#ifdef SERIAL_DEBUG_THROTTLE
printk("unthrottle %s ....\n", tty_name(tty));
#endif
if (serial_paranoia_check(info, tty->name, "rs_unthrottle"))
return;
if (I_IXOFF(tty)) {
if (info->x_char)
info->x_char = 0;
else
rs_send_xchar(tty, START_CHAR(tty));
}
if (C_CRTSCTS(tty))
info->MCR |= SER_RTS;
local_irq_save(flags);
rtsdtr_ctrl(info->MCR);
local_irq_restore(flags);
}
static int get_serial_info(struct tty_struct *tty, struct serial_state *state,
struct serial_struct __user * retinfo)
{
struct serial_struct tmp;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
tty_lock(tty);
tmp.line = tty->index;
tmp.port = state->port;
tmp.flags = state->tport.flags;
tmp.xmit_fifo_size = state->xmit_fifo_size;
tmp.baud_base = state->baud_base;
tmp.close_delay = state->tport.close_delay;
tmp.closing_wait = state->tport.closing_wait;
tmp.custom_divisor = state->custom_divisor;
tty_unlock(tty);
if (copy_to_user(retinfo,&tmp,sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int set_serial_info(struct tty_struct *tty, struct serial_state *state,
struct serial_struct __user * new_info)
{
struct tty_port *port = &state->tport;
struct serial_struct new_serial;
bool change_spd;
int retval = 0;
if (copy_from_user(&new_serial,new_info,sizeof(new_serial)))
return -EFAULT;
tty_lock(tty);
change_spd = ((new_serial.flags ^ port->flags) & ASYNC_SPD_MASK) ||
new_serial.custom_divisor != state->custom_divisor;
if (new_serial.irq || new_serial.port != state->port ||
new_serial.xmit_fifo_size != state->xmit_fifo_size) {
tty_unlock(tty);
return -EINVAL;
}
if (!serial_isroot()) {
if ((new_serial.baud_base != state->baud_base) ||
(new_serial.close_delay != port->close_delay) ||
(new_serial.xmit_fifo_size != state->xmit_fifo_size) ||
((new_serial.flags & ~ASYNC_USR_MASK) !=
(port->flags & ~ASYNC_USR_MASK))) {
tty_unlock(tty);
return -EPERM;
}
port->flags = ((port->flags & ~ASYNC_USR_MASK) |
(new_serial.flags & ASYNC_USR_MASK));
state->custom_divisor = new_serial.custom_divisor;
goto check_and_exit;
}
if (new_serial.baud_base < 9600) {
tty_unlock(tty);
return -EINVAL;
}
state->baud_base = new_serial.baud_base;
port->flags = ((port->flags & ~ASYNC_FLAGS) |
(new_serial.flags & ASYNC_FLAGS));
state->custom_divisor = new_serial.custom_divisor;
port->close_delay = new_serial.close_delay * HZ/100;
port->closing_wait = new_serial.closing_wait * HZ/100;
port->low_latency = (port->flags & ASYNC_LOW_LATENCY) ? 1 : 0;
check_and_exit:
if (port->flags & ASYNC_INITIALIZED) {
if (change_spd) {
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
tty->alt_speed = 57600;
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
tty->alt_speed = 115200;
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
tty->alt_speed = 230400;
if ((port->flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
tty->alt_speed = 460800;
change_speed(tty, state, NULL);
}
} else
retval = startup(tty, state);
tty_unlock(tty);
return retval;
}
static int get_lsr_info(struct serial_state *info, unsigned int __user *value)
{
unsigned char status;
unsigned int result;
unsigned long flags;
local_irq_save(flags);
status = custom.serdatr;
mb();
local_irq_restore(flags);
result = ((status & SDR_TSRE) ? TIOCSER_TEMT : 0);
if (copy_to_user(value, &result, sizeof(int)))
return -EFAULT;
return 0;
}
static int rs_tiocmget(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
unsigned char control, status;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_ioctl"))
return -ENODEV;
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
control = info->MCR;
local_irq_save(flags);
status = ciab.pra;
local_irq_restore(flags);
return ((control & SER_RTS) ? TIOCM_RTS : 0)
| ((control & SER_DTR) ? TIOCM_DTR : 0)
| (!(status & SER_DCD) ? TIOCM_CAR : 0)
| (!(status & SER_DSR) ? TIOCM_DSR : 0)
| (!(status & SER_CTS) ? TIOCM_CTS : 0);
}
static int rs_tiocmset(struct tty_struct *tty, unsigned int set,
unsigned int clear)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_ioctl"))
return -ENODEV;
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
local_irq_save(flags);
if (set & TIOCM_RTS)
info->MCR |= SER_RTS;
if (set & TIOCM_DTR)
info->MCR |= SER_DTR;
if (clear & TIOCM_RTS)
info->MCR &= ~SER_RTS;
if (clear & TIOCM_DTR)
info->MCR &= ~SER_DTR;
rtsdtr_ctrl(info->MCR);
local_irq_restore(flags);
return 0;
}
static int rs_break(struct tty_struct *tty, int break_state)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
if (serial_paranoia_check(info, tty->name, "rs_break"))
return -EINVAL;
local_irq_save(flags);
if (break_state == -1)
custom.adkcon = AC_SETCLR | AC_UARTBRK;
else
custom.adkcon = AC_UARTBRK;
mb();
local_irq_restore(flags);
return 0;
}
static int rs_get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
struct serial_state *info = tty->driver_data;
struct async_icount cnow;
unsigned long flags;
local_irq_save(flags);
cnow = info->icount;
local_irq_restore(flags);
icount->cts = cnow.cts;
icount->dsr = cnow.dsr;
icount->rng = cnow.rng;
icount->dcd = cnow.dcd;
icount->rx = cnow.rx;
icount->tx = cnow.tx;
icount->frame = cnow.frame;
icount->overrun = cnow.overrun;
icount->parity = cnow.parity;
icount->brk = cnow.brk;
icount->buf_overrun = cnow.buf_overrun;
return 0;
}
static int rs_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct serial_state *info = tty->driver_data;
struct async_icount cprev, cnow;
void __user *argp = (void __user *)arg;
unsigned long flags;
DEFINE_WAIT(wait);
int ret;
if (serial_paranoia_check(info, tty->name, "rs_ioctl"))
return -ENODEV;
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != TIOCSERCONFIG) && (cmd != TIOCSERGSTRUCT) &&
(cmd != TIOCMIWAIT) && (cmd != TIOCGICOUNT)) {
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
}
switch (cmd) {
case TIOCGSERIAL:
return get_serial_info(tty, info, argp);
case TIOCSSERIAL:
return set_serial_info(tty, info, argp);
case TIOCSERCONFIG:
return 0;
case TIOCSERGETLSR:
return get_lsr_info(info, argp);
case TIOCSERGSTRUCT:
if (copy_to_user(argp,
info, sizeof(struct serial_state)))
return -EFAULT;
return 0;
case TIOCMIWAIT:
local_irq_save(flags);
cprev = info->icount;
local_irq_restore(flags);
while (1) {
prepare_to_wait(&info->tport.delta_msr_wait,
&wait, TASK_INTERRUPTIBLE);
local_irq_save(flags);
cnow = info->icount;
local_irq_restore(flags);
if (cnow.rng == cprev.rng && cnow.dsr == cprev.dsr &&
cnow.dcd == cprev.dcd && cnow.cts == cprev.cts) {
ret = -EIO;
break;
}
if ( ((arg & TIOCM_RNG) && (cnow.rng != cprev.rng)) ||
((arg & TIOCM_DSR) && (cnow.dsr != cprev.dsr)) ||
((arg & TIOCM_CD) && (cnow.dcd != cprev.dcd)) ||
((arg & TIOCM_CTS) && (cnow.cts != cprev.cts)) ) {
ret = 0;
break;
}
schedule();
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
cprev = cnow;
}
finish_wait(&info->tport.delta_msr_wait, &wait);
return ret;
case TIOCSERGWILD:
case TIOCSERSWILD:
printk ("TIOCSER?WILD ioctl obsolete, ignored.\n");
return 0;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static void rs_set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
struct serial_state *info = tty->driver_data;
unsigned long flags;
unsigned int cflag = tty->termios.c_cflag;
change_speed(tty, info, old_termios);
if ((old_termios->c_cflag & CBAUD) && !(cflag & CBAUD)) {
info->MCR &= ~(SER_DTR|SER_RTS);
local_irq_save(flags);
rtsdtr_ctrl(info->MCR);
local_irq_restore(flags);
}
if (!(old_termios->c_cflag & CBAUD) && (cflag & CBAUD)) {
info->MCR |= SER_DTR;
if (!C_CRTSCTS(tty) || !test_bit(TTY_THROTTLED, &tty->flags))
info->MCR |= SER_RTS;
local_irq_save(flags);
rtsdtr_ctrl(info->MCR);
local_irq_restore(flags);
}
if ((old_termios->c_cflag & CRTSCTS) && !C_CRTSCTS(tty)) {
tty->hw_stopped = 0;
rs_start(tty);
}
#if 0
if (!(old_termios->c_cflag & CLOCAL) && C_CLOCAL(tty))
wake_up_interruptible(&info->open_wait);
#endif
}
static void rs_close(struct tty_struct *tty, struct file * filp)
{
struct serial_state *state = tty->driver_data;
struct tty_port *port = &state->tport;
if (serial_paranoia_check(state, tty->name, "rs_close"))
return;
if (tty_port_close_start(port, tty, filp) == 0)
return;
state->read_status_mask &= ~UART_LSR_DR;
if (port->flags & ASYNC_INITIALIZED) {
custom.intena = IF_RBF;
mb();
custom.intreq = IF_RBF;
mb();
rs_wait_until_sent(tty, state->timeout);
}
shutdown(tty, state);
rs_flush_buffer(tty);
tty_ldisc_flush(tty);
port->tty = NULL;
tty_port_close_end(port, tty);
}
static void rs_wait_until_sent(struct tty_struct *tty, int timeout)
{
struct serial_state *info = tty->driver_data;
unsigned long orig_jiffies, char_time;
int lsr;
if (serial_paranoia_check(info, tty->name, "rs_wait_until_sent"))
return;
if (info->xmit_fifo_size == 0)
return;
orig_jiffies = jiffies;
char_time = (info->timeout - HZ/50) / info->xmit_fifo_size;
char_time = char_time / 5;
if (char_time == 0)
char_time = 1;
if (timeout)
char_time = min_t(unsigned long, char_time, timeout);
if (!timeout || timeout > 2*info->timeout)
timeout = 2*info->timeout;
#ifdef SERIAL_DEBUG_RS_WAIT_UNTIL_SENT
printk("In rs_wait_until_sent(%d) check=%lu...", timeout, char_time);
printk("jiff=%lu...", jiffies);
#endif
while(!((lsr = custom.serdatr) & SDR_TSRE)) {
#ifdef SERIAL_DEBUG_RS_WAIT_UNTIL_SENT
printk("serdatr = %d (jiff=%lu)...", lsr, jiffies);
#endif
msleep_interruptible(jiffies_to_msecs(char_time));
if (signal_pending(current))
break;
if (timeout && time_after(jiffies, orig_jiffies + timeout))
break;
}
__set_current_state(TASK_RUNNING);
#ifdef SERIAL_DEBUG_RS_WAIT_UNTIL_SENT
printk("lsr = %d (jiff=%lu)...done\n", lsr, jiffies);
#endif
}
static void rs_hangup(struct tty_struct *tty)
{
struct serial_state *info = tty->driver_data;
if (serial_paranoia_check(info, tty->name, "rs_hangup"))
return;
rs_flush_buffer(tty);
shutdown(tty, info);
info->tport.count = 0;
info->tport.flags &= ~ASYNC_NORMAL_ACTIVE;
info->tport.tty = NULL;
wake_up_interruptible(&info->tport.open_wait);
}
static int rs_open(struct tty_struct *tty, struct file * filp)
{
struct serial_state *info = rs_table + tty->index;
struct tty_port *port = &info->tport;
int retval;
port->count++;
port->tty = tty;
tty->driver_data = info;
tty->port = port;
if (serial_paranoia_check(info, tty->name, "rs_open"))
return -ENODEV;
port->low_latency = (port->flags & ASYNC_LOW_LATENCY) ? 1 : 0;
retval = startup(tty, info);
if (retval) {
return retval;
}
return tty_port_block_til_ready(port, tty, filp);
}
static inline void line_info(struct seq_file *m, int line,
struct serial_state *state)
{
char stat_buf[30], control, status;
unsigned long flags;
seq_printf(m, "%d: uart:amiga_builtin", line);
local_irq_save(flags);
status = ciab.pra;
control = (state->tport.flags & ASYNC_INITIALIZED) ? state->MCR : status;
local_irq_restore(flags);
stat_buf[0] = 0;
stat_buf[1] = 0;
if(!(control & SER_RTS))
strcat(stat_buf, "|RTS");
if(!(status & SER_CTS))
strcat(stat_buf, "|CTS");
if(!(control & SER_DTR))
strcat(stat_buf, "|DTR");
if(!(status & SER_DSR))
strcat(stat_buf, "|DSR");
if(!(status & SER_DCD))
strcat(stat_buf, "|CD");
if (state->quot)
seq_printf(m, " baud:%d", state->baud_base / state->quot);
seq_printf(m, " tx:%d rx:%d", state->icount.tx, state->icount.rx);
if (state->icount.frame)
seq_printf(m, " fe:%d", state->icount.frame);
if (state->icount.parity)
seq_printf(m, " pe:%d", state->icount.parity);
if (state->icount.brk)
seq_printf(m, " brk:%d", state->icount.brk);
if (state->icount.overrun)
seq_printf(m, " oe:%d", state->icount.overrun);
seq_printf(m, " %s\n", stat_buf+1);
}
static int rs_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "serinfo:1.0 driver:%s\n", serial_version);
line_info(m, 0, &rs_table[0]);
return 0;
}
static int rs_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, rs_proc_show, NULL);
}
static void show_serial_version(void)
{
printk(KERN_INFO "%s version %s\n", serial_name, serial_version);
}
static int amiga_carrier_raised(struct tty_port *port)
{
return !(ciab.pra & SER_DCD);
}
static void amiga_dtr_rts(struct tty_port *port, int raise)
{
struct serial_state *info = container_of(port, struct serial_state,
tport);
unsigned long flags;
if (raise)
info->MCR |= SER_DTR|SER_RTS;
else
info->MCR &= ~(SER_DTR|SER_RTS);
local_irq_save(flags);
rtsdtr_ctrl(info->MCR);
local_irq_restore(flags);
}
static int __init amiga_serial_probe(struct platform_device *pdev)
{
unsigned long flags;
struct serial_state * state;
int error;
serial_driver = alloc_tty_driver(NR_PORTS);
if (!serial_driver)
return -ENOMEM;
show_serial_version();
serial_driver->driver_name = "amiserial";
serial_driver->name = "ttyS";
serial_driver->major = TTY_MAJOR;
serial_driver->minor_start = 64;
serial_driver->type = TTY_DRIVER_TYPE_SERIAL;
serial_driver->subtype = SERIAL_TYPE_NORMAL;
serial_driver->init_termios = tty_std_termios;
serial_driver->init_termios.c_cflag =
B9600 | CS8 | CREAD | HUPCL | CLOCAL;
serial_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(serial_driver, &serial_ops);
state = rs_table;
state->port = (int)&custom.serdatr;
state->custom_divisor = 0;
state->icount.cts = state->icount.dsr =
state->icount.rng = state->icount.dcd = 0;
state->icount.rx = state->icount.tx = 0;
state->icount.frame = state->icount.parity = 0;
state->icount.overrun = state->icount.brk = 0;
tty_port_init(&state->tport);
state->tport.ops = &amiga_port_ops;
tty_port_link_device(&state->tport, serial_driver, 0);
error = tty_register_driver(serial_driver);
if (error)
goto fail_put_tty_driver;
printk(KERN_INFO "ttyS0 is the amiga builtin serial port\n");
state->baud_base = amiga_colorclock;
state->xmit_fifo_size = 1;
error = request_irq(IRQ_AMIGA_TBE, ser_tx_int, 0, "serial TX", state);
if (error)
goto fail_unregister;
error = request_irq(IRQ_AMIGA_RBF, ser_rx_int, 0,
"serial RX", state);
if (error)
goto fail_free_irq;
local_irq_save(flags);
custom.intena = IF_RBF | IF_TBE;
mb();
custom.intreq = IF_RBF | IF_TBE;
mb();
local_irq_restore(flags);
ciab.ddra |= (SER_DTR | SER_RTS);
ciab.ddra &= ~(SER_DCD | SER_CTS | SER_DSR);
platform_set_drvdata(pdev, state);
return 0;
fail_free_irq:
free_irq(IRQ_AMIGA_TBE, state);
fail_unregister:
tty_unregister_driver(serial_driver);
fail_put_tty_driver:
tty_port_destroy(&state->tport);
put_tty_driver(serial_driver);
return error;
}
static int __exit amiga_serial_remove(struct platform_device *pdev)
{
int error;
struct serial_state *state = platform_get_drvdata(pdev);
error = tty_unregister_driver(serial_driver);
if (error)
printk("SERIAL: failed to unregister serial driver (%d)\n",
error);
put_tty_driver(serial_driver);
tty_port_destroy(&state->tport);
free_irq(IRQ_AMIGA_TBE, state);
free_irq(IRQ_AMIGA_RBF, state);
return error;
}
static void amiga_serial_putc(char c)
{
custom.serdat = (unsigned char)c | 0x100;
while (!(custom.serdatr & 0x2000))
barrier();
}
static void serial_console_write(struct console *co, const char *s,
unsigned count)
{
unsigned short intena = custom.intenar;
custom.intena = IF_TBE;
while (count--) {
if (*s == '\n')
amiga_serial_putc('\r');
amiga_serial_putc(*s++);
}
custom.intena = IF_SETCLR | (intena & IF_TBE);
}
static struct tty_driver *serial_console_device(struct console *c, int *index)
{
*index = 0;
return serial_driver;
}
static int __init amiserial_console_init(void)
{
if (!MACH_IS_AMIGA)
return -ENODEV;
register_console(&sercons);
return 0;
}
