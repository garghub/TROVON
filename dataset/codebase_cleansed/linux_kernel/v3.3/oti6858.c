static void setup_line(struct work_struct *work)
{
struct oti6858_private *priv = container_of(work,
struct oti6858_private, delayed_setup_work.work);
struct usb_serial_port *port = priv->port;
struct oti6858_control_pkt *new_setup;
unsigned long flags;
int result;
dbg("%s(port = %d)", __func__, port->number);
new_setup = kmalloc(OTI6858_CTRL_PKT_SIZE, GFP_KERNEL);
if (new_setup == NULL) {
dev_err(&port->dev, "%s(): out of memory!\n", __func__);
schedule_delayed_work(&priv->delayed_setup_work,
msecs_to_jiffies(2));
return;
}
result = usb_control_msg(port->serial->dev,
usb_rcvctrlpipe(port->serial->dev, 0),
OTI6858_REQ_T_GET_STATUS,
OTI6858_REQ_GET_STATUS,
0, 0,
new_setup, OTI6858_CTRL_PKT_SIZE,
100);
if (result != OTI6858_CTRL_PKT_SIZE) {
dev_err(&port->dev, "%s(): error reading status\n", __func__);
kfree(new_setup);
schedule_delayed_work(&priv->delayed_setup_work,
msecs_to_jiffies(2));
return;
}
spin_lock_irqsave(&priv->lock, flags);
if (!OTI6858_CTRL_EQUALS_PENDING(new_setup, priv)) {
new_setup->divisor = priv->pending_setup.divisor;
new_setup->control = priv->pending_setup.control;
new_setup->frame_fmt = priv->pending_setup.frame_fmt;
spin_unlock_irqrestore(&priv->lock, flags);
result = usb_control_msg(port->serial->dev,
usb_sndctrlpipe(port->serial->dev, 0),
OTI6858_REQ_T_SET_LINE,
OTI6858_REQ_SET_LINE,
0, 0,
new_setup, OTI6858_CTRL_PKT_SIZE,
100);
} else {
spin_unlock_irqrestore(&priv->lock, flags);
result = 0;
}
kfree(new_setup);
spin_lock_irqsave(&priv->lock, flags);
if (result != OTI6858_CTRL_PKT_SIZE)
priv->transient = 0;
priv->setup_done = 1;
spin_unlock_irqrestore(&priv->lock, flags);
dbg("%s(): submitting interrupt urb", __func__);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result != 0) {
dev_err(&port->dev, "%s(): usb_submit_urb() failed"
" with error %d\n", __func__, result);
}
}
static void send_data(struct work_struct *work)
{
struct oti6858_private *priv = container_of(work,
struct oti6858_private, delayed_write_work.work);
struct usb_serial_port *port = priv->port;
int count = 0, result;
unsigned long flags;
u8 *allow;
dbg("%s(port = %d)", __func__, port->number);
spin_lock_irqsave(&priv->lock, flags);
if (priv->flags.write_urb_in_use) {
spin_unlock_irqrestore(&priv->lock, flags);
schedule_delayed_work(&priv->delayed_write_work,
msecs_to_jiffies(2));
return;
}
priv->flags.write_urb_in_use = 1;
spin_unlock_irqrestore(&priv->lock, flags);
spin_lock_irqsave(&port->lock, flags);
count = kfifo_len(&port->write_fifo);
spin_unlock_irqrestore(&port->lock, flags);
if (count > port->bulk_out_size)
count = port->bulk_out_size;
if (count != 0) {
allow = kmalloc(1, GFP_KERNEL);
if (!allow) {
dev_err(&port->dev, "%s(): kmalloc failed\n",
__func__);
return;
}
result = usb_control_msg(port->serial->dev,
usb_rcvctrlpipe(port->serial->dev, 0),
OTI6858_REQ_T_CHECK_TXBUFF,
OTI6858_REQ_CHECK_TXBUFF,
count, 0, allow, 1, 100);
if (result != 1 || *allow != 0)
count = 0;
kfree(allow);
}
if (count == 0) {
priv->flags.write_urb_in_use = 0;
dbg("%s(): submitting interrupt urb", __func__);
result = usb_submit_urb(port->interrupt_in_urb, GFP_NOIO);
if (result != 0) {
dev_err(&port->dev, "%s(): usb_submit_urb() failed"
" with error %d\n", __func__, result);
}
return;
}
count = kfifo_out_locked(&port->write_fifo,
port->write_urb->transfer_buffer,
count, &port->lock);
port->write_urb->transfer_buffer_length = count;
result = usb_submit_urb(port->write_urb, GFP_NOIO);
if (result != 0) {
dev_err(&port->dev, "%s(): usb_submit_urb() failed"
" with error %d\n", __func__, result);
priv->flags.write_urb_in_use = 0;
}
usb_serial_port_softint(port);
}
static int oti6858_startup(struct usb_serial *serial)
{
struct usb_serial_port *port = serial->port[0];
struct oti6858_private *priv;
int i;
for (i = 0; i < serial->num_ports; ++i) {
priv = kzalloc(sizeof(struct oti6858_private), GFP_KERNEL);
if (!priv)
break;
spin_lock_init(&priv->lock);
init_waitqueue_head(&priv->intr_wait);
priv->port = port;
INIT_DELAYED_WORK(&priv->delayed_setup_work, setup_line);
INIT_DELAYED_WORK(&priv->delayed_write_work, send_data);
usb_set_serial_port_data(serial->port[i], priv);
}
if (i == serial->num_ports)
return 0;
for (--i; i >= 0; --i) {
priv = usb_get_serial_port_data(serial->port[i]);
kfree(priv);
usb_set_serial_port_data(serial->port[i], NULL);
}
return -ENOMEM;
}
static int oti6858_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
dbg("%s(port = %d, count = %d)", __func__, port->number, count);
if (!count)
return count;
count = kfifo_in_locked(&port->write_fifo, buf, count, &port->lock);
return count;
}
static int oti6858_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
int room = 0;
unsigned long flags;
dbg("%s(port = %d)", __func__, port->number);
spin_lock_irqsave(&port->lock, flags);
room = kfifo_avail(&port->write_fifo);
spin_unlock_irqrestore(&port->lock, flags);
return room;
}
static int oti6858_chars_in_buffer(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
int chars = 0;
unsigned long flags;
dbg("%s(port = %d)", __func__, port->number);
spin_lock_irqsave(&port->lock, flags);
chars = kfifo_len(&port->write_fifo);
spin_unlock_irqrestore(&port->lock, flags);
return chars;
}
static void oti6858_init_termios(struct tty_struct *tty)
{
*(tty->termios) = tty_std_termios;
tty->termios->c_cflag = B38400 | CS8 | CREAD | HUPCL | CLOCAL;
tty->termios->c_ispeed = 38400;
tty->termios->c_ospeed = 38400;
}
static void oti6858_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct oti6858_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int cflag;
u8 frame_fmt, control;
__le16 divisor;
int br;
dbg("%s(port = %d)", __func__, port->number);
if (!tty) {
dbg("%s(): no tty structures", __func__);
return;
}
cflag = tty->termios->c_cflag;
spin_lock_irqsave(&priv->lock, flags);
divisor = priv->pending_setup.divisor;
frame_fmt = priv->pending_setup.frame_fmt;
control = priv->pending_setup.control;
spin_unlock_irqrestore(&priv->lock, flags);
frame_fmt &= ~FMT_DATA_BITS_MASK;
switch (cflag & CSIZE) {
case CS5:
frame_fmt |= FMT_DATA_BITS_5;
break;
case CS6:
frame_fmt |= FMT_DATA_BITS_6;
break;
case CS7:
frame_fmt |= FMT_DATA_BITS_7;
break;
default:
case CS8:
frame_fmt |= FMT_DATA_BITS_8;
break;
}
br = tty_get_baud_rate(tty);
if (br == 0) {
divisor = 0;
} else {
int real_br;
int new_divisor;
br = min(br, OTI6858_MAX_BAUD_RATE);
new_divisor = (96000000 + 8 * br) / (16 * br);
real_br = 96000000 / (16 * new_divisor);
divisor = cpu_to_le16(new_divisor);
tty_encode_baud_rate(tty, real_br, real_br);
}
frame_fmt &= ~FMT_STOP_BITS_MASK;
if ((cflag & CSTOPB) != 0)
frame_fmt |= FMT_STOP_BITS_2;
else
frame_fmt |= FMT_STOP_BITS_1;
frame_fmt &= ~FMT_PARITY_MASK;
if ((cflag & PARENB) != 0) {
if ((cflag & PARODD) != 0)
frame_fmt |= FMT_PARITY_ODD;
else
frame_fmt |= FMT_PARITY_EVEN;
} else {
frame_fmt |= FMT_PARITY_NONE;
}
control &= ~CONTROL_MASK;
if ((cflag & CRTSCTS) != 0)
control |= (CONTROL_DTR_HIGH | CONTROL_RTS_HIGH);
spin_lock_irqsave(&priv->lock, flags);
if (divisor != priv->pending_setup.divisor
|| control != priv->pending_setup.control
|| frame_fmt != priv->pending_setup.frame_fmt) {
priv->pending_setup.divisor = divisor;
priv->pending_setup.control = control;
priv->pending_setup.frame_fmt = frame_fmt;
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static int oti6858_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct oti6858_private *priv = usb_get_serial_port_data(port);
struct ktermios tmp_termios;
struct usb_serial *serial = port->serial;
struct oti6858_control_pkt *buf;
unsigned long flags;
int result;
dbg("%s(port = %d)", __func__, port->number);
usb_clear_halt(serial->dev, port->write_urb->pipe);
usb_clear_halt(serial->dev, port->read_urb->pipe);
buf = kmalloc(OTI6858_CTRL_PKT_SIZE, GFP_KERNEL);
if (buf == NULL) {
dev_err(&port->dev, "%s(): out of memory!\n", __func__);
return -ENOMEM;
}
result = usb_control_msg(serial->dev, usb_rcvctrlpipe(serial->dev, 0),
OTI6858_REQ_T_GET_STATUS,
OTI6858_REQ_GET_STATUS,
0, 0,
buf, OTI6858_CTRL_PKT_SIZE,
100);
if (result != OTI6858_CTRL_PKT_SIZE) {
buf->divisor = cpu_to_le16(0x009c);
buf->frame_fmt = 0x03;
buf->something = 0x43;
buf->control = 0x4c;
buf->tx_status = 0x00;
buf->pin_state = 0x5b;
buf->rx_bytes_avail = 0x00;
}
spin_lock_irqsave(&priv->lock, flags);
memcpy(&priv->status, buf, OTI6858_CTRL_PKT_SIZE);
priv->pending_setup.divisor = buf->divisor;
priv->pending_setup.frame_fmt = buf->frame_fmt;
priv->pending_setup.control = buf->control;
spin_unlock_irqrestore(&priv->lock, flags);
kfree(buf);
dbg("%s(): submitting interrupt urb", __func__);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result != 0) {
dev_err(&port->dev, "%s(): usb_submit_urb() failed"
" with error %d\n", __func__, result);
oti6858_close(port);
return result;
}
if (tty)
oti6858_set_termios(tty, port, &tmp_termios);
port->port.drain_delay = 256;
return 0;
}
static void oti6858_close(struct usb_serial_port *port)
{
struct oti6858_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
dbg("%s(port = %d)", __func__, port->number);
spin_lock_irqsave(&port->lock, flags);
kfifo_reset_out(&port->write_fifo);
spin_unlock_irqrestore(&port->lock, flags);
dbg("%s(): after buf_clear()", __func__);
cancel_delayed_work_sync(&priv->delayed_setup_work);
cancel_delayed_work_sync(&priv->delayed_write_work);
dbg("%s(): shutting down urbs", __func__);
usb_kill_urb(port->write_urb);
usb_kill_urb(port->read_urb);
usb_kill_urb(port->interrupt_in_urb);
}
static int oti6858_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct oti6858_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
u8 control;
dbg("%s(port = %d, set = 0x%08x, clear = 0x%08x)",
__func__, port->number, set, clear);
if (!usb_get_intfdata(port->serial->interface))
return -ENODEV;
spin_lock_irqsave(&priv->lock, flags);
control = priv->pending_setup.control;
if ((set & TIOCM_RTS) != 0)
control |= CONTROL_RTS_HIGH;
if ((set & TIOCM_DTR) != 0)
control |= CONTROL_DTR_HIGH;
if ((clear & TIOCM_RTS) != 0)
control &= ~CONTROL_RTS_HIGH;
if ((clear & TIOCM_DTR) != 0)
control &= ~CONTROL_DTR_HIGH;
if (control != priv->pending_setup.control)
priv->pending_setup.control = control;
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int oti6858_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct oti6858_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned pin_state;
unsigned result = 0;
dbg("%s(port = %d)", __func__, port->number);
if (!usb_get_intfdata(port->serial->interface))
return -ENODEV;
spin_lock_irqsave(&priv->lock, flags);
pin_state = priv->status.pin_state & PIN_MASK;
spin_unlock_irqrestore(&priv->lock, flags);
if ((pin_state & PIN_RTS) != 0)
result |= TIOCM_RTS;
if ((pin_state & PIN_CTS) != 0)
result |= TIOCM_CTS;
if ((pin_state & PIN_DSR) != 0)
result |= TIOCM_DSR;
if ((pin_state & PIN_DTR) != 0)
result |= TIOCM_DTR;
if ((pin_state & PIN_RI) != 0)
result |= TIOCM_RI;
if ((pin_state & PIN_DCD) != 0)
result |= TIOCM_CD;
dbg("%s() = 0x%08x", __func__, result);
return result;
}
static int wait_modem_info(struct usb_serial_port *port, unsigned int arg)
{
struct oti6858_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
unsigned int prev, status;
unsigned int changed;
spin_lock_irqsave(&priv->lock, flags);
prev = priv->status.pin_state;
spin_unlock_irqrestore(&priv->lock, flags);
while (1) {
wait_event_interruptible(priv->intr_wait,
priv->status.pin_state != prev);
if (signal_pending(current))
return -ERESTARTSYS;
spin_lock_irqsave(&priv->lock, flags);
status = priv->status.pin_state & PIN_MASK;
spin_unlock_irqrestore(&priv->lock, flags);
changed = prev ^ status;
if (((arg & TIOCM_RNG) && (changed & PIN_RI)) ||
((arg & TIOCM_DSR) && (changed & PIN_DSR)) ||
((arg & TIOCM_CD) && (changed & PIN_DCD)) ||
((arg & TIOCM_CTS) && (changed & PIN_CTS)))
return 0;
prev = status;
}
return 0;
}
static int oti6858_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct usb_serial_port *port = tty->driver_data;
dbg("%s(port = %d, cmd = 0x%04x, arg = 0x%08lx)",
__func__, port->number, cmd, arg);
switch (cmd) {
case TIOCMIWAIT:
dbg("%s(): TIOCMIWAIT", __func__);
return wait_modem_info(port, arg);
default:
dbg("%s(): 0x%04x not supported", __func__, cmd);
break;
}
return -ENOIOCTLCMD;
}
static void oti6858_release(struct usb_serial *serial)
{
int i;
dbg("%s()", __func__);
for (i = 0; i < serial->num_ports; ++i)
kfree(usb_get_serial_port_data(serial->port[i]));
}
static void oti6858_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct oti6858_private *priv = usb_get_serial_port_data(port);
int transient = 0, can_recv = 0, resubmit = 1;
int status = urb->status;
dbg("%s(port = %d, status = %d)",
__func__, port->number, status);
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s(): urb shutting down with status: %d",
__func__, status);
return;
default:
dbg("%s(): nonzero urb status received: %d",
__func__, status);
break;
}
if (status == 0 && urb->actual_length == OTI6858_CTRL_PKT_SIZE) {
struct oti6858_control_pkt *xs = urb->transfer_buffer;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (!priv->transient) {
if (!OTI6858_CTRL_EQUALS_PENDING(xs, priv)) {
if (xs->rx_bytes_avail == 0) {
priv->transient = 4;
priv->setup_done = 0;
resubmit = 0;
dbg("%s(): scheduling setup_line()",
__func__);
schedule_delayed_work(&priv->delayed_setup_work, 0);
}
}
} else {
if (OTI6858_CTRL_EQUALS_PENDING(xs, priv)) {
priv->transient = 0;
} else if (!priv->setup_done) {
resubmit = 0;
} else if (--priv->transient == 0) {
if (xs->rx_bytes_avail == 0) {
priv->transient = 4;
priv->setup_done = 0;
resubmit = 0;
dbg("%s(): scheduling setup_line()",
__func__);
schedule_delayed_work(&priv->delayed_setup_work, 0);
}
}
}
if (!priv->transient) {
if (xs->pin_state != priv->status.pin_state)
wake_up_interruptible(&priv->intr_wait);
memcpy(&priv->status, xs, OTI6858_CTRL_PKT_SIZE);
}
if (!priv->transient && xs->rx_bytes_avail != 0) {
can_recv = xs->rx_bytes_avail;
priv->flags.read_urb_in_use = 1;
}
transient = priv->transient;
spin_unlock_irqrestore(&priv->lock, flags);
}
if (can_recv) {
int result;
result = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (result != 0) {
priv->flags.read_urb_in_use = 0;
dev_err(&port->dev, "%s(): usb_submit_urb() failed,"
" error %d\n", __func__, result);
} else {
resubmit = 0;
}
} else if (!transient) {
unsigned long flags;
int count;
spin_lock_irqsave(&port->lock, flags);
count = kfifo_len(&port->write_fifo);
spin_unlock_irqrestore(&port->lock, flags);
spin_lock_irqsave(&priv->lock, flags);
if (priv->flags.write_urb_in_use == 0 && count != 0) {
schedule_delayed_work(&priv->delayed_write_work, 0);
resubmit = 0;
}
spin_unlock_irqrestore(&priv->lock, flags);
}
if (resubmit) {
int result;
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result != 0) {
dev_err(&urb->dev->dev,
"%s(): usb_submit_urb() failed with"
" error %d\n", __func__, result);
}
}
}
static void oti6858_read_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct oti6858_private *priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
unsigned long flags;
int status = urb->status;
int result;
dbg("%s(port = %d, status = %d)",
__func__, port->number, status);
spin_lock_irqsave(&priv->lock, flags);
priv->flags.read_urb_in_use = 0;
spin_unlock_irqrestore(&priv->lock, flags);
if (status != 0) {
dbg("%s(): unable to handle the error, exiting", __func__);
return;
}
tty = tty_port_tty_get(&port->port);
if (tty != NULL && urb->actual_length > 0) {
tty_insert_flip_string(tty, data, urb->actual_length);
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result != 0 && result != -EPERM) {
dev_err(&port->dev, "%s(): usb_submit_urb() failed,"
" error %d\n", __func__, result);
}
}
static void oti6858_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct oti6858_private *priv = usb_get_serial_port_data(port);
int status = urb->status;
int result;
dbg("%s(port = %d, status = %d)",
__func__, port->number, status);
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s(): urb shutting down with status: %d",
__func__, status);
priv->flags.write_urb_in_use = 0;
return;
default:
dbg("%s(): nonzero write bulk status received: %d",
__func__, status);
dbg("%s(): overflow in write", __func__);
port->write_urb->transfer_buffer_length = 1;
result = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (result) {
dev_err(&port->dev, "%s(): usb_submit_urb() failed,"
" error %d\n", __func__, result);
} else {
return;
}
}
priv->flags.write_urb_in_use = 0;
dbg("%s(): submitting interrupt urb", __func__);
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result != 0) {
dev_err(&port->dev, "%s(): failed submitting int urb,"
" error %d\n", __func__, result);
}
}
static int __init oti6858_init(void)
{
int retval;
retval = usb_serial_register(&oti6858_device);
if (retval == 0) {
retval = usb_register(&oti6858_driver);
if (retval)
usb_serial_deregister(&oti6858_device);
}
return retval;
}
static void __exit oti6858_exit(void)
{
usb_deregister(&oti6858_driver);
usb_serial_deregister(&oti6858_device);
}
