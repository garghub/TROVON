static void ssu100_release(struct usb_serial *serial)
{
struct ssu100_port_private *priv = usb_get_serial_port_data(*serial->port);
kfree(priv);
}
static inline int ssu100_control_msg(struct usb_device *dev,
u8 request, u16 data, u16 index)
{
return usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
request, 0x40, data, index,
NULL, 0, 300);
}
static inline int ssu100_setdevice(struct usb_device *dev, u8 *data)
{
u16 x = ((u16)(data[1] << 8) | (u16)(data[0]));
return ssu100_control_msg(dev, QT_SET_GET_DEVICE, x, 0);
}
static inline int ssu100_getdevice(struct usb_device *dev, u8 *data)
{
return usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
QT_SET_GET_DEVICE, 0xc0, 0, 0,
data, 3, 300);
}
static inline int ssu100_getregister(struct usb_device *dev,
unsigned short uart,
unsigned short reg,
u8 *data)
{
return usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
QT_SET_GET_REGISTER, 0xc0, reg,
uart, data, sizeof(*data), 300);
}
static inline int ssu100_setregister(struct usb_device *dev,
unsigned short uart,
unsigned short reg,
u16 data)
{
u16 value = (data << 8) | reg;
return usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
QT_SET_GET_REGISTER, 0x40, value, uart,
NULL, 0, 300);
}
static inline int update_mctrl(struct usb_device *dev, unsigned int set,
unsigned int clear)
{
unsigned urb_value;
int result;
if (((set | clear) & (TIOCM_DTR | TIOCM_RTS)) == 0) {
dbg("%s - DTR|RTS not being set|cleared", __func__);
return 0;
}
clear &= ~set;
urb_value = 0;
if (set & TIOCM_DTR)
urb_value |= UART_MCR_DTR;
if (set & TIOCM_RTS)
urb_value |= UART_MCR_RTS;
result = ssu100_setregister(dev, 0, UART_MCR, urb_value);
if (result < 0)
dbg("%s Error from MODEM_CTRL urb", __func__);
return result;
}
static int ssu100_initdevice(struct usb_device *dev)
{
u8 *data;
int result = 0;
data = kzalloc(3, GFP_KERNEL);
if (!data)
return -ENOMEM;
result = ssu100_getdevice(dev, data);
if (result < 0) {
dbg("%s - get_device failed %i", __func__, result);
goto out;
}
data[1] &= ~FULLPWRBIT;
result = ssu100_setdevice(dev, data);
if (result < 0) {
dbg("%s - setdevice failed %i", __func__, result);
goto out;
}
result = ssu100_control_msg(dev, QT_GET_SET_PREBUF_TRIG_LVL, 128, 0);
if (result < 0) {
dbg("%s - set prebuffer level failed %i", __func__, result);
goto out;
}
result = ssu100_control_msg(dev, QT_SET_ATF, ATC_DISABLED, 0);
if (result < 0) {
dbg("%s - set ATFprebuffer level failed %i", __func__, result);
goto out;
}
result = ssu100_getdevice(dev, data);
if (result < 0) {
dbg("%s - get_device failed %i", __func__, result);
goto out;
}
data[0] &= ~(RR_BITS | DUPMODE_BITS);
data[0] |= CLKS_X4;
data[1] &= ~(LOOPMODE_BITS);
data[1] |= RS232_MODE;
result = ssu100_setdevice(dev, data);
if (result < 0) {
dbg("%s - setdevice failed %i", __func__, result);
goto out;
}
out: kfree(data);
return result;
}
static void ssu100_set_termios(struct tty_struct *tty,
struct usb_serial_port *port,
struct ktermios *old_termios)
{
struct usb_device *dev = port->serial->dev;
struct ktermios *termios = tty->termios;
u16 baud, divisor, remainder;
unsigned int cflag = termios->c_cflag;
u16 urb_value = 0;
int result;
if (cflag & PARENB) {
if (cflag & PARODD)
urb_value |= UART_LCR_PARITY;
else
urb_value |= SERIAL_EVEN_PARITY;
}
switch (cflag & CSIZE) {
case CS5:
urb_value |= UART_LCR_WLEN5;
break;
case CS6:
urb_value |= UART_LCR_WLEN6;
break;
case CS7:
urb_value |= UART_LCR_WLEN7;
break;
default:
case CS8:
urb_value |= UART_LCR_WLEN8;
break;
}
baud = tty_get_baud_rate(tty);
if (!baud)
baud = 9600;
dbg("%s - got baud = %d\n", __func__, baud);
divisor = MAX_BAUD_RATE / baud;
remainder = MAX_BAUD_RATE % baud;
if (((remainder * 2) >= baud) && (baud != 110))
divisor++;
urb_value = urb_value << 8;
result = ssu100_control_msg(dev, QT_GET_SET_UART, divisor, urb_value);
if (result < 0)
dbg("%s - set uart failed", __func__);
if (cflag & CRTSCTS)
result = ssu100_control_msg(dev, QT_HW_FLOW_CONTROL_MASK,
SERIAL_CRTSCTS, 0);
else
result = ssu100_control_msg(dev, QT_HW_FLOW_CONTROL_MASK,
0, 0);
if (result < 0)
dbg("%s - set HW flow control failed", __func__);
if (I_IXOFF(tty) || I_IXON(tty)) {
u16 x = ((u16)(START_CHAR(tty) << 8) | (u16)(STOP_CHAR(tty)));
result = ssu100_control_msg(dev, QT_SW_FLOW_CONTROL_MASK,
x, 0);
} else
result = ssu100_control_msg(dev, QT_SW_FLOW_CONTROL_MASK,
0, 0);
if (result < 0)
dbg("%s - set SW flow control failed", __func__);
}
static int ssu100_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_device *dev = port->serial->dev;
struct ssu100_port_private *priv = usb_get_serial_port_data(port);
u8 *data;
int result;
unsigned long flags;
data = kzalloc(2, GFP_KERNEL);
if (!data)
return -ENOMEM;
result = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
QT_OPEN_CLOSE_CHANNEL,
QT_TRANSFER_IN, 0x01,
0, data, 2, 300);
if (result < 0) {
dbg("%s - open failed %i", __func__, result);
kfree(data);
return result;
}
spin_lock_irqsave(&priv->status_lock, flags);
priv->shadowLSR = data[0];
priv->shadowMSR = data[1];
spin_unlock_irqrestore(&priv->status_lock, flags);
kfree(data);
result = ssu100_control_msg(dev, QT_GET_SET_UART, 0x30, 0x0300);
if (result < 0)
dbg("%s - set uart failed", __func__);
if (tty)
ssu100_set_termios(tty, port, tty->termios);
return usb_serial_generic_open(tty, port);
}
static void ssu100_close(struct usb_serial_port *port)
{
usb_serial_generic_close(port);
}
static int get_serial_info(struct usb_serial_port *port,
struct serial_struct __user *retinfo)
{
struct serial_struct tmp;
if (!retinfo)
return -EFAULT;
memset(&tmp, 0, sizeof(tmp));
tmp.line = port->serial->minor;
tmp.port = 0;
tmp.irq = 0;
tmp.flags = ASYNC_SKIP_TEST | ASYNC_AUTO_IRQ;
tmp.xmit_fifo_size = port->bulk_out_size;
tmp.baud_base = 9600;
tmp.close_delay = 5*HZ;
tmp.closing_wait = 30*HZ;
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return -EFAULT;
return 0;
}
static int wait_modem_info(struct usb_serial_port *port, unsigned int arg)
{
struct ssu100_port_private *priv = usb_get_serial_port_data(port);
struct async_icount prev, cur;
unsigned long flags;
spin_lock_irqsave(&priv->status_lock, flags);
prev = priv->icount;
spin_unlock_irqrestore(&priv->status_lock, flags);
while (1) {
wait_event_interruptible(priv->delta_msr_wait,
((priv->icount.rng != prev.rng) ||
(priv->icount.dsr != prev.dsr) ||
(priv->icount.dcd != prev.dcd) ||
(priv->icount.cts != prev.cts)));
if (signal_pending(current))
return -ERESTARTSYS;
spin_lock_irqsave(&priv->status_lock, flags);
cur = priv->icount;
spin_unlock_irqrestore(&priv->status_lock, flags);
if ((prev.rng == cur.rng) &&
(prev.dsr == cur.dsr) &&
(prev.dcd == cur.dcd) &&
(prev.cts == cur.cts))
return -EIO;
if ((arg & TIOCM_RNG && (prev.rng != cur.rng)) ||
(arg & TIOCM_DSR && (prev.dsr != cur.dsr)) ||
(arg & TIOCM_CD && (prev.dcd != cur.dcd)) ||
(arg & TIOCM_CTS && (prev.cts != cur.cts)))
return 0;
}
return 0;
}
static int ssu100_get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
struct usb_serial_port *port = tty->driver_data;
struct ssu100_port_private *priv = usb_get_serial_port_data(port);
struct async_icount cnow = priv->icount;
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
static int ssu100_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
dbg("%s cmd 0x%04x", __func__, cmd);
switch (cmd) {
case TIOCGSERIAL:
return get_serial_info(port,
(struct serial_struct __user *) arg);
case TIOCMIWAIT:
return wait_modem_info(port, arg);
default:
break;
}
dbg("%s arg not supported", __func__);
return -ENOIOCTLCMD;
}
static int ssu100_attach(struct usb_serial *serial)
{
struct ssu100_port_private *priv;
struct usb_serial_port *port = *serial->port;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&port->dev, "%s- kmalloc(%Zd) failed.\n", __func__,
sizeof(*priv));
return -ENOMEM;
}
spin_lock_init(&priv->status_lock);
init_waitqueue_head(&priv->delta_msr_wait);
usb_set_serial_port_data(port, priv);
return ssu100_initdevice(serial->dev);
}
static int ssu100_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_device *dev = port->serial->dev;
u8 *d;
int r;
d = kzalloc(2, GFP_KERNEL);
if (!d)
return -ENOMEM;
r = ssu100_getregister(dev, 0, UART_MCR, d);
if (r < 0)
goto mget_out;
r = ssu100_getregister(dev, 0, UART_MSR, d+1);
if (r < 0)
goto mget_out;
r = (d[0] & UART_MCR_DTR ? TIOCM_DTR : 0) |
(d[0] & UART_MCR_RTS ? TIOCM_RTS : 0) |
(d[1] & UART_MSR_CTS ? TIOCM_CTS : 0) |
(d[1] & UART_MSR_DCD ? TIOCM_CAR : 0) |
(d[1] & UART_MSR_RI ? TIOCM_RI : 0) |
(d[1] & UART_MSR_DSR ? TIOCM_DSR : 0);
mget_out:
kfree(d);
return r;
}
static int ssu100_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_device *dev = port->serial->dev;
return update_mctrl(dev, set, clear);
}
static void ssu100_dtr_rts(struct usb_serial_port *port, int on)
{
struct usb_device *dev = port->serial->dev;
mutex_lock(&port->serial->disc_mutex);
if (!port->serial->disconnected) {
if (!on &&
ssu100_setregister(dev, 0, UART_MCR, 0) < 0)
dev_err(&port->dev, "error from flowcontrol urb\n");
if (on)
set_mctrl(dev, TIOCM_DTR | TIOCM_RTS);
else
clear_mctrl(dev, TIOCM_DTR | TIOCM_RTS);
}
mutex_unlock(&port->serial->disc_mutex);
}
static void ssu100_update_msr(struct usb_serial_port *port, u8 msr)
{
struct ssu100_port_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->status_lock, flags);
priv->shadowMSR = msr;
spin_unlock_irqrestore(&priv->status_lock, flags);
if (msr & UART_MSR_ANY_DELTA) {
if (msr & UART_MSR_DCTS)
priv->icount.cts++;
if (msr & UART_MSR_DDSR)
priv->icount.dsr++;
if (msr & UART_MSR_DDCD)
priv->icount.dcd++;
if (msr & UART_MSR_TERI)
priv->icount.rng++;
wake_up_interruptible(&priv->delta_msr_wait);
}
}
static void ssu100_update_lsr(struct usb_serial_port *port, u8 lsr,
char *tty_flag)
{
struct ssu100_port_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
spin_lock_irqsave(&priv->status_lock, flags);
priv->shadowLSR = lsr;
spin_unlock_irqrestore(&priv->status_lock, flags);
*tty_flag = TTY_NORMAL;
if (lsr & UART_LSR_BRK_ERROR_BITS) {
if (lsr & UART_LSR_BI) {
priv->icount.brk++;
*tty_flag = TTY_BREAK;
usb_serial_handle_break(port);
}
if (lsr & UART_LSR_PE) {
priv->icount.parity++;
if (*tty_flag == TTY_NORMAL)
*tty_flag = TTY_PARITY;
}
if (lsr & UART_LSR_FE) {
priv->icount.frame++;
if (*tty_flag == TTY_NORMAL)
*tty_flag = TTY_FRAME;
}
if (lsr & UART_LSR_OE){
priv->icount.overrun++;
if (*tty_flag == TTY_NORMAL)
*tty_flag = TTY_OVERRUN;
}
}
}
static int ssu100_process_packet(struct urb *urb,
struct tty_struct *tty)
{
struct usb_serial_port *port = urb->context;
char *packet = (char *)urb->transfer_buffer;
char flag = TTY_NORMAL;
u32 len = urb->actual_length;
int i;
char *ch;
if ((len >= 4) &&
(packet[0] == 0x1b) && (packet[1] == 0x1b) &&
((packet[2] == 0x00) || (packet[2] == 0x01))) {
if (packet[2] == 0x00) {
ssu100_update_lsr(port, packet[3], &flag);
if (flag == TTY_OVERRUN)
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
}
if (packet[2] == 0x01)
ssu100_update_msr(port, packet[3]);
len -= 4;
ch = packet + 4;
} else
ch = packet;
if (!len)
return 0;
if (port->port.console && port->sysrq) {
for (i = 0; i < len; i++, ch++) {
if (!usb_serial_handle_sysrq_char(port, *ch))
tty_insert_flip_char(tty, *ch, flag);
}
} else
tty_insert_flip_string_fixed_flag(tty, ch, flag, len);
return len;
}
static void ssu100_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct tty_struct *tty;
int count;
tty = tty_port_tty_get(&port->port);
if (!tty)
return;
count = ssu100_process_packet(urb, tty);
if (count)
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
