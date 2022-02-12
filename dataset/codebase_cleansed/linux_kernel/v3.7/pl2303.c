static int pl2303_vendor_read(__u16 value, __u16 index,
struct usb_serial *serial, unsigned char *buf)
{
int res = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
VENDOR_READ_REQUEST, VENDOR_READ_REQUEST_TYPE,
value, index, buf, 1, 100);
dev_dbg(&serial->dev->dev, "0x%x:0x%x:0x%x:0x%x %d - %x\n",
VENDOR_READ_REQUEST_TYPE, VENDOR_READ_REQUEST, value, index,
res, buf[0]);
return res;
}
static int pl2303_vendor_write(__u16 value, __u16 index,
struct usb_serial *serial)
{
int res = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
VENDOR_WRITE_REQUEST, VENDOR_WRITE_REQUEST_TYPE,
value, index, NULL, 0, 100);
dev_dbg(&serial->dev->dev, "0x%x:0x%x:0x%x:0x%x %d\n",
VENDOR_WRITE_REQUEST_TYPE, VENDOR_WRITE_REQUEST, value, index,
res);
return res;
}
static int pl2303_startup(struct usb_serial *serial)
{
struct pl2303_serial_private *spriv;
enum pl2303_type type = type_0;
unsigned char *buf;
spriv = kzalloc(sizeof(*spriv), GFP_KERNEL);
if (!spriv)
return -ENOMEM;
buf = kmalloc(10, GFP_KERNEL);
if (!buf) {
kfree(spriv);
return -ENOMEM;
}
if (serial->dev->descriptor.bDeviceClass == 0x02)
type = type_0;
else if (serial->dev->descriptor.bMaxPacketSize0 == 0x40)
type = HX;
else if (serial->dev->descriptor.bDeviceClass == 0x00)
type = type_1;
else if (serial->dev->descriptor.bDeviceClass == 0xFF)
type = type_1;
dev_dbg(&serial->interface->dev, "device type: %d\n", type);
spriv->type = type;
usb_set_serial_data(serial, spriv);
pl2303_vendor_read(0x8484, 0, serial, buf);
pl2303_vendor_write(0x0404, 0, serial);
pl2303_vendor_read(0x8484, 0, serial, buf);
pl2303_vendor_read(0x8383, 0, serial, buf);
pl2303_vendor_read(0x8484, 0, serial, buf);
pl2303_vendor_write(0x0404, 1, serial);
pl2303_vendor_read(0x8484, 0, serial, buf);
pl2303_vendor_read(0x8383, 0, serial, buf);
pl2303_vendor_write(0, 1, serial);
pl2303_vendor_write(1, 0, serial);
if (type == HX)
pl2303_vendor_write(2, 0x44, serial);
else
pl2303_vendor_write(2, 0x24, serial);
kfree(buf);
return 0;
}
static void pl2303_release(struct usb_serial *serial)
{
struct pl2303_serial_private *spriv;
spriv = usb_get_serial_data(serial);
kfree(spriv);
}
static int pl2303_port_probe(struct usb_serial_port *port)
{
struct pl2303_private *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
init_waitqueue_head(&priv->delta_msr_wait);
usb_set_serial_port_data(port, priv);
return 0;
}
static int pl2303_port_remove(struct usb_serial_port *port)
{
struct pl2303_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
static int set_control_lines(struct usb_device *dev, u8 value)
{
int retval;
retval = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
SET_CONTROL_REQUEST, SET_CONTROL_REQUEST_TYPE,
value, 0, NULL, 0, 100);
dev_dbg(&dev->dev, "%s - value = %d, retval = %d\n", __func__,
value, retval);
return retval;
}
static void pl2303_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct usb_serial *serial = port->serial;
struct pl2303_serial_private *spriv = usb_get_serial_data(serial);
struct pl2303_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int cflag;
unsigned char *buf;
int baud;
int i;
u8 control;
const int baud_sup[] = { 75, 150, 300, 600, 1200, 1800, 2400, 3600,
4800, 7200, 9600, 14400, 19200, 28800, 38400,
57600, 115200, 230400, 460800, 614400,
921600, 1228800, 2457600, 3000000, 6000000 };
int baud_floor, baud_ceil;
int k;
if (!tty_termios_hw_change(&tty->termios, old_termios))
return;
cflag = tty->termios.c_cflag;
buf = kzalloc(7, GFP_KERNEL);
if (!buf) {
dev_err(&port->dev, "%s - out of memory.\n", __func__);
tty->termios = *old_termios;
return;
}
i = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
GET_LINE_REQUEST, GET_LINE_REQUEST_TYPE,
0, 0, buf, 7, 100);
dev_dbg(&port->dev, "0xa1:0x21:0:0 %d - %x %x %x %x %x %x %x\n", i,
buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
if (cflag & CSIZE) {
switch (cflag & CSIZE) {
case CS5:
buf[6] = 5;
break;
case CS6:
buf[6] = 6;
break;
case CS7:
buf[6] = 7;
break;
default:
case CS8:
buf[6] = 8;
break;
}
dev_dbg(&port->dev, "data bits = %d\n", buf[6]);
}
baud = tty_get_baud_rate(tty);
dev_dbg(&port->dev, "baud requested = %d\n", baud);
if (baud) {
for (k=0; k<ARRAY_SIZE(baud_sup); k++) {
if (baud_sup[k] / baud) {
baud_ceil = baud_sup[k];
if (k==0) {
baud = baud_ceil;
} else {
baud_floor = baud_sup[k-1];
if ((baud_ceil % baud)
> (baud % baud_floor))
baud = baud_floor;
else
baud = baud_ceil;
}
break;
}
}
if (baud > 1228800) {
if (spriv->type != HX)
baud = 1228800;
else if (baud > 6000000)
baud = 6000000;
}
dev_dbg(&port->dev, "baud set = %d\n", baud);
if (baud <= 115200) {
buf[0] = baud & 0xff;
buf[1] = (baud >> 8) & 0xff;
buf[2] = (baud >> 16) & 0xff;
buf[3] = (baud >> 24) & 0xff;
} else {
unsigned tmp = 12*1000*1000*32 / baud;
buf[3] = 0x80;
buf[2] = 0;
buf[1] = (tmp >= 256);
while (tmp >= 256) {
tmp >>= 2;
buf[1] <<= 1;
}
buf[0] = tmp;
}
}
if (cflag & CSTOPB) {
if ((cflag & CSIZE) == CS5) {
buf[4] = 1;
dev_dbg(&port->dev, "stop bits = 1.5\n");
} else {
buf[4] = 2;
dev_dbg(&port->dev, "stop bits = 2\n");
}
} else {
buf[4] = 0;
dev_dbg(&port->dev, "stop bits = 1\n");
}
if (cflag & PARENB) {
if (cflag & PARODD) {
if (cflag & CMSPAR) {
buf[5] = 3;
dev_dbg(&port->dev, "parity = mark\n");
} else {
buf[5] = 1;
dev_dbg(&port->dev, "parity = odd\n");
}
} else {
if (cflag & CMSPAR) {
buf[5] = 4;
dev_dbg(&port->dev, "parity = space\n");
} else {
buf[5] = 2;
dev_dbg(&port->dev, "parity = even\n");
}
}
} else {
buf[5] = 0;
dev_dbg(&port->dev, "parity = none\n");
}
i = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
SET_LINE_REQUEST, SET_LINE_REQUEST_TYPE,
0, 0, buf, 7, 100);
dev_dbg(&port->dev, "0x21:0x20:0:0 %d\n", i);
spin_lock_irqsave(&priv->lock, flags);
control = priv->line_control;
if ((cflag & CBAUD) == B0)
priv->line_control &= ~(CONTROL_DTR | CONTROL_RTS);
else if ((old_termios->c_cflag & CBAUD) == B0)
priv->line_control |= (CONTROL_DTR | CONTROL_RTS);
if (control != priv->line_control) {
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
set_control_lines(serial->dev, control);
} else {
spin_unlock_irqrestore(&priv->lock, flags);
}
buf[0] = buf[1] = buf[2] = buf[3] = buf[4] = buf[5] = buf[6] = 0;
i = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
GET_LINE_REQUEST, GET_LINE_REQUEST_TYPE,
0, 0, buf, 7, 100);
dev_dbg(&port->dev, "0xa1:0x21:0:0 %d - %x %x %x %x %x %x %x\n", i,
buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6]);
if (cflag & CRTSCTS) {
if (spriv->type == HX)
pl2303_vendor_write(0x0, 0x61, serial);
else
pl2303_vendor_write(0x0, 0x41, serial);
} else {
pl2303_vendor_write(0x0, 0x0, serial);
}
if (baud)
tty_encode_baud_rate(tty, baud, baud);
kfree(buf);
}
static void pl2303_dtr_rts(struct usb_serial_port *port, int on)
{
struct pl2303_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 control;
spin_lock_irqsave(&priv->lock, flags);
if (on)
priv->line_control |= (CONTROL_DTR | CONTROL_RTS);
else
priv->line_control &= ~(CONTROL_DTR | CONTROL_RTS);
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
set_control_lines(port->serial->dev, control);
}
static void pl2303_close(struct usb_serial_port *port)
{
usb_serial_generic_close(port);
usb_kill_urb(port->interrupt_in_urb);
}
static int pl2303_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct ktermios tmp_termios;
struct usb_serial *serial = port->serial;
struct pl2303_serial_private *spriv = usb_get_serial_data(serial);
int result;
if (spriv->type != HX) {
usb_clear_halt(serial->dev, port->write_urb->pipe);
usb_clear_halt(serial->dev, port->read_urb->pipe);
} else {
pl2303_vendor_write(8, 0, serial);
pl2303_vendor_write(9, 0, serial);
}
if (tty)
pl2303_set_termios(tty, port, &tmp_termios);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result) {
dev_err(&port->dev, "%s - failed submitting interrupt urb,"
" error %d\n", __func__, result);
return result;
}
result = usb_serial_generic_open(tty, port);
if (result) {
usb_kill_urb(port->interrupt_in_urb);
return result;
}
port->port.drain_delay = 256;
return 0;
}
static int pl2303_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
struct pl2303_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 control;
int ret;
spin_lock_irqsave(&priv->lock, flags);
if (set & TIOCM_RTS)
priv->line_control |= CONTROL_RTS;
if (set & TIOCM_DTR)
priv->line_control |= CONTROL_DTR;
if (clear & TIOCM_RTS)
priv->line_control &= ~CONTROL_RTS;
if (clear & TIOCM_DTR)
priv->line_control &= ~CONTROL_DTR;
control = priv->line_control;
spin_unlock_irqrestore(&priv->lock, flags);
mutex_lock(&serial->disc_mutex);
if (!serial->disconnected)
ret = set_control_lines(serial->dev, control);
else
ret = -ENODEV;
mutex_unlock(&serial->disc_mutex);
return ret;
}
static int pl2303_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct pl2303_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int mcr;
unsigned int status;
unsigned int result;
spin_lock_irqsave(&priv->lock, flags);
mcr = priv->line_control;
status = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
result = ((mcr & CONTROL_DTR) ? TIOCM_DTR : 0)
| ((mcr & CONTROL_RTS) ? TIOCM_RTS : 0)
| ((status & UART_CTS) ? TIOCM_CTS : 0)
| ((status & UART_DSR) ? TIOCM_DSR : 0)
| ((status & UART_RING) ? TIOCM_RI : 0)
| ((status & UART_DCD) ? TIOCM_CD : 0);
dev_dbg(&port->dev, "%s - result = %x\n", __func__, result);
return result;
}
static int pl2303_carrier_raised(struct usb_serial_port *port)
{
struct pl2303_private *priv = usb_get_serial_port_data(port);
if (priv->line_status & UART_DCD)
return 1;
return 0;
}
static int wait_modem_info(struct usb_serial_port *port, unsigned int arg)
{
struct pl2303_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int prevstatus;
unsigned int status;
unsigned int changed;
spin_lock_irqsave(&priv->lock, flags);
prevstatus = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
while (1) {
interruptible_sleep_on(&priv->delta_msr_wait);
if (signal_pending(current))
return -ERESTARTSYS;
spin_lock_irqsave(&priv->lock, flags);
status = priv->line_status;
spin_unlock_irqrestore(&priv->lock, flags);
changed = prevstatus ^ status;
if (((arg & TIOCM_RNG) && (changed & UART_RING)) ||
((arg & TIOCM_DSR) && (changed & UART_DSR)) ||
((arg & TIOCM_CD) && (changed & UART_DCD)) ||
((arg & TIOCM_CTS) && (changed & UART_CTS))) {
return 0;
}
prevstatus = status;
}
return 0;
}
static int pl2303_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct serial_struct ser;
struct usb_serial_port *port = tty->driver_data;
dev_dbg(&port->dev, "%s cmd = 0x%04x\n", __func__, cmd);
switch (cmd) {
case TIOCGSERIAL:
memset(&ser, 0, sizeof ser);
ser.type = PORT_16654;
ser.line = port->serial->minor;
ser.port = port->number;
ser.baud_base = 460800;
if (copy_to_user((void __user *)arg, &ser, sizeof ser))
return -EFAULT;
return 0;
case TIOCMIWAIT:
dev_dbg(&port->dev, "%s TIOCMIWAIT\n", __func__);
return wait_modem_info(port, arg);
default:
dev_dbg(&port->dev, "%s not supported = 0x%04x\n", __func__, cmd);
break;
}
return -ENOIOCTLCMD;
}
static void pl2303_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
u16 state;
int result;
if (break_state == 0)
state = BREAK_OFF;
else
state = BREAK_ON;
dev_dbg(&port->dev, "%s - turning break %s\n", __func__,
state == BREAK_OFF ? "off" : "on");
result = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
BREAK_REQUEST, BREAK_REQUEST_TYPE, state,
0, NULL, 0, 100);
if (result)
dev_err(&port->dev, "error sending break = %d\n", result);
}
static void pl2303_update_line_status(struct usb_serial_port *port,
unsigned char *data,
unsigned int actual_length)
{
struct pl2303_private *priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned long flags;
u8 status_idx = UART_STATE;
u8 length = UART_STATE + 1;
u8 prev_line_status;
u16 idv, idp;
idv = le16_to_cpu(port->serial->dev->descriptor.idVendor);
idp = le16_to_cpu(port->serial->dev->descriptor.idProduct);
if (idv == SIEMENS_VENDOR_ID) {
if (idp == SIEMENS_PRODUCT_ID_X65 ||
idp == SIEMENS_PRODUCT_ID_SX1 ||
idp == SIEMENS_PRODUCT_ID_X75) {
length = 1;
status_idx = 0;
}
}
if (actual_length < length)
return;
spin_lock_irqsave(&priv->lock, flags);
prev_line_status = priv->line_status;
priv->line_status = data[status_idx];
spin_unlock_irqrestore(&priv->lock, flags);
if (priv->line_status & UART_BREAK_ERROR)
usb_serial_handle_break(port);
wake_up_interruptible(&priv->delta_msr_wait);
tty = tty_port_tty_get(&port->port);
if (!tty)
return;
if ((priv->line_status ^ prev_line_status) & UART_DCD)
usb_serial_handle_dcd_change(port, tty,
priv->line_status & UART_DCD);
tty_kref_put(tty);
}
static void pl2303_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
unsigned int actual_length = urb->actual_length;
int status = urb->status;
int retval;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&port->dev, "%s - urb shutting down with status: %d\n",
__func__, status);
return;
default:
dev_dbg(&port->dev, "%s - nonzero urb status received: %d\n",
__func__, status);
goto exit;
}
usb_serial_debug_data(&port->dev, __func__,
urb->actual_length, urb->transfer_buffer);
pl2303_update_line_status(port, data, actual_length);
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&port->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void pl2303_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct pl2303_private *priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
char tty_flag = TTY_NORMAL;
unsigned long flags;
u8 line_status;
int i;
spin_lock_irqsave(&priv->lock, flags);
line_status = priv->line_status;
priv->line_status &= ~UART_STATE_TRANSIENT_MASK;
spin_unlock_irqrestore(&priv->lock, flags);
wake_up_interruptible(&priv->delta_msr_wait);
if (!urb->actual_length)
return;
tty = tty_port_tty_get(&port->port);
if (!tty)
return;
if (line_status & UART_BREAK_ERROR)
tty_flag = TTY_BREAK;
else if (line_status & UART_PARITY_ERROR)
tty_flag = TTY_PARITY;
else if (line_status & UART_FRAME_ERROR)
tty_flag = TTY_FRAME;
dev_dbg(&port->dev, "%s - tty_flag = %d\n", __func__, tty_flag);
if (line_status & UART_OVERRUN_ERROR)
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
if (port->port.console && port->sysrq) {
for (i = 0; i < urb->actual_length; ++i)
if (!usb_serial_handle_sysrq_char(port, data[i]))
tty_insert_flip_char(tty, data[i], tty_flag);
} else {
tty_insert_flip_string_fixed_flag(tty, data, tty_flag,
urb->actual_length);
}
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
