static int belkin_sa_startup(struct usb_serial *serial)
{
struct usb_device *dev = serial->dev;
struct belkin_sa_private *priv;
priv = kmalloc(sizeof(struct belkin_sa_private), GFP_KERNEL);
if (!priv)
return -1;
spin_lock_init(&priv->lock);
priv->control_state = 0;
priv->last_lsr = 0;
priv->last_msr = 0;
priv->bad_flow_control =
(le16_to_cpu(dev->descriptor.bcdDevice) <= 0x0206) ? 1 : 0;
dev_info(&dev->dev, "bcdDevice: %04x, bfc: %d\n",
le16_to_cpu(dev->descriptor.bcdDevice),
priv->bad_flow_control);
init_waitqueue_head(&serial->port[0]->write_wait);
usb_set_serial_port_data(serial->port[0], priv);
return 0;
}
static void belkin_sa_release(struct usb_serial *serial)
{
int i;
dbg("%s", __func__);
for (i = 0; i < serial->num_ports; ++i)
kfree(usb_get_serial_port_data(serial->port[i]));
}
static int belkin_sa_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
int retval;
dbg("%s port %d", __func__, port->number);
retval = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (retval) {
dev_err(&port->dev, "usb_submit_urb(read int) failed\n");
return retval;
}
retval = usb_serial_generic_open(tty, port);
if (retval)
usb_kill_urb(port->interrupt_in_urb);
return retval;
}
static void belkin_sa_close(struct usb_serial_port *port)
{
dbg("%s port %d", __func__, port->number);
usb_serial_generic_close(port);
usb_kill_urb(port->interrupt_in_urb);
}
static void belkin_sa_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct belkin_sa_private *priv;
unsigned char *data = urb->transfer_buffer;
int retval;
int status = urb->status;
unsigned long flags;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s - urb shutting down with status: %d",
__func__, status);
return;
default:
dbg("%s - nonzero urb status received: %d",
__func__, status);
goto exit;
}
usb_serial_debug_data(debug, &port->dev, __func__,
urb->actual_length, data);
priv = usb_get_serial_port_data(port);
spin_lock_irqsave(&priv->lock, flags);
priv->last_msr = data[BELKIN_SA_MSR_INDEX];
if (priv->last_msr & BELKIN_SA_MSR_DSR)
priv->control_state |= TIOCM_DSR;
else
priv->control_state &= ~TIOCM_DSR;
if (priv->last_msr & BELKIN_SA_MSR_CTS)
priv->control_state |= TIOCM_CTS;
else
priv->control_state &= ~TIOCM_CTS;
if (priv->last_msr & BELKIN_SA_MSR_RI)
priv->control_state |= TIOCM_RI;
else
priv->control_state &= ~TIOCM_RI;
if (priv->last_msr & BELKIN_SA_MSR_CD)
priv->control_state |= TIOCM_CD;
else
priv->control_state &= ~TIOCM_CD;
priv->last_lsr = data[BELKIN_SA_LSR_INDEX];
spin_unlock_irqrestore(&priv->lock, flags);
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&port->dev, "%s - usb_submit_urb failed with "
"result %d\n", __func__, retval);
}
static void belkin_sa_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct belkin_sa_private *priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
unsigned long flags;
unsigned char status;
char tty_flag;
tty_flag = TTY_NORMAL;
spin_lock_irqsave(&priv->lock, flags);
status = priv->last_lsr;
priv->last_lsr &= ~BELKIN_SA_LSR_ERR;
spin_unlock_irqrestore(&priv->lock, flags);
if (!urb->actual_length)
return;
tty = tty_port_tty_get(&port->port);
if (!tty)
return;
if (status & BELKIN_SA_LSR_ERR) {
if (status & BELKIN_SA_LSR_BI)
tty_flag = TTY_BREAK;
else if (status & BELKIN_SA_LSR_PE)
tty_flag = TTY_PARITY;
else if (status & BELKIN_SA_LSR_FE)
tty_flag = TTY_FRAME;
dev_dbg(&port->dev, "tty_flag = %d\n", tty_flag);
if (status & BELKIN_SA_LSR_OE)
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
}
tty_insert_flip_string_fixed_flag(tty, data, tty_flag,
urb->actual_length);
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
static void belkin_sa_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct usb_serial *serial = port->serial;
struct belkin_sa_private *priv = usb_get_serial_port_data(port);
unsigned int iflag;
unsigned int cflag;
unsigned int old_iflag = 0;
unsigned int old_cflag = 0;
__u16 urb_value = 0;
unsigned long flags;
unsigned long control_state;
int bad_flow_control;
speed_t baud;
struct ktermios *termios = tty->termios;
iflag = termios->c_iflag;
cflag = termios->c_cflag;
termios->c_cflag &= ~CMSPAR;
spin_lock_irqsave(&priv->lock, flags);
control_state = priv->control_state;
bad_flow_control = priv->bad_flow_control;
spin_unlock_irqrestore(&priv->lock, flags);
old_iflag = old_termios->c_iflag;
old_cflag = old_termios->c_cflag;
if ((cflag & CBAUD) != (old_cflag & CBAUD)) {
if ((old_cflag & CBAUD) == B0) {
control_state |= (TIOCM_DTR|TIOCM_RTS);
if (BSA_USB_CMD(BELKIN_SA_SET_DTR_REQUEST, 1) < 0)
dev_err(&port->dev, "Set DTR error\n");
if (!(old_cflag & CRTSCTS))
if (BSA_USB_CMD(BELKIN_SA_SET_RTS_REQUEST
, 1) < 0)
dev_err(&port->dev, "Set RTS error\n");
}
}
baud = tty_get_baud_rate(tty);
if (baud) {
urb_value = BELKIN_SA_BAUD(baud);
if (urb_value == 0)
urb_value = 1;
baud = BELKIN_SA_BAUD(urb_value);
tty_encode_baud_rate(tty, baud, baud);
if (BSA_USB_CMD(BELKIN_SA_SET_BAUDRATE_REQUEST, urb_value) < 0)
dev_err(&port->dev, "Set baudrate error\n");
} else {
if (BSA_USB_CMD(BELKIN_SA_SET_FLOW_CTRL_REQUEST,
BELKIN_SA_FLOW_NONE) < 0)
dev_err(&port->dev, "Disable flowcontrol error\n");
control_state &= ~(TIOCM_DTR | TIOCM_RTS);
if (BSA_USB_CMD(BELKIN_SA_SET_DTR_REQUEST, 0) < 0)
dev_err(&port->dev, "DTR LOW error\n");
if (BSA_USB_CMD(BELKIN_SA_SET_RTS_REQUEST, 0) < 0)
dev_err(&port->dev, "RTS LOW error\n");
}
if ((cflag ^ old_cflag) & (PARENB | PARODD)) {
if (cflag & PARENB)
urb_value = (cflag & PARODD) ? BELKIN_SA_PARITY_ODD
: BELKIN_SA_PARITY_EVEN;
else
urb_value = BELKIN_SA_PARITY_NONE;
if (BSA_USB_CMD(BELKIN_SA_SET_PARITY_REQUEST, urb_value) < 0)
dev_err(&port->dev, "Set parity error\n");
}
if ((cflag & CSIZE) != (old_cflag & CSIZE)) {
switch (cflag & CSIZE) {
case CS5:
urb_value = BELKIN_SA_DATA_BITS(5);
break;
case CS6:
urb_value = BELKIN_SA_DATA_BITS(6);
break;
case CS7:
urb_value = BELKIN_SA_DATA_BITS(7);
break;
case CS8:
urb_value = BELKIN_SA_DATA_BITS(8);
break;
default: dbg("CSIZE was not CS5-CS8, using default of 8");
urb_value = BELKIN_SA_DATA_BITS(8);
break;
}
if (BSA_USB_CMD(BELKIN_SA_SET_DATA_BITS_REQUEST, urb_value) < 0)
dev_err(&port->dev, "Set data bits error\n");
}
if ((cflag & CSTOPB) != (old_cflag & CSTOPB)) {
urb_value = (cflag & CSTOPB) ? BELKIN_SA_STOP_BITS(2)
: BELKIN_SA_STOP_BITS(1);
if (BSA_USB_CMD(BELKIN_SA_SET_STOP_BITS_REQUEST,
urb_value) < 0)
dev_err(&port->dev, "Set stop bits error\n");
}
if (((iflag ^ old_iflag) & (IXOFF | IXON)) ||
((cflag ^ old_cflag) & CRTSCTS)) {
urb_value = 0;
if ((iflag & IXOFF) || (iflag & IXON))
urb_value |= (BELKIN_SA_FLOW_OXON | BELKIN_SA_FLOW_IXON);
else
urb_value &= ~(BELKIN_SA_FLOW_OXON | BELKIN_SA_FLOW_IXON);
if (cflag & CRTSCTS)
urb_value |= (BELKIN_SA_FLOW_OCTS | BELKIN_SA_FLOW_IRTS);
else
urb_value &= ~(BELKIN_SA_FLOW_OCTS | BELKIN_SA_FLOW_IRTS);
if (bad_flow_control)
urb_value &= ~(BELKIN_SA_FLOW_IRTS);
if (BSA_USB_CMD(BELKIN_SA_SET_FLOW_CTRL_REQUEST, urb_value) < 0)
dev_err(&port->dev, "Set flow control error\n");
}
spin_lock_irqsave(&priv->lock, flags);
priv->control_state = control_state;
spin_unlock_irqrestore(&priv->lock, flags);
}
static void belkin_sa_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
if (BSA_USB_CMD(BELKIN_SA_SET_BREAK_REQUEST, break_state ? 1 : 0) < 0)
dev_err(&port->dev, "Set break_ctl %d\n", break_state);
}
static int belkin_sa_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct belkin_sa_private *priv = usb_get_serial_port_data(port);
unsigned long control_state;
unsigned long flags;
dbg("%s", __func__);
spin_lock_irqsave(&priv->lock, flags);
control_state = priv->control_state;
spin_unlock_irqrestore(&priv->lock, flags);
return control_state;
}
static int belkin_sa_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
struct belkin_sa_private *priv = usb_get_serial_port_data(port);
unsigned long control_state;
unsigned long flags;
int retval;
int rts = 0;
int dtr = 0;
dbg("%s", __func__);
spin_lock_irqsave(&priv->lock, flags);
control_state = priv->control_state;
if (set & TIOCM_RTS) {
control_state |= TIOCM_RTS;
rts = 1;
}
if (set & TIOCM_DTR) {
control_state |= TIOCM_DTR;
dtr = 1;
}
if (clear & TIOCM_RTS) {
control_state &= ~TIOCM_RTS;
rts = 0;
}
if (clear & TIOCM_DTR) {
control_state &= ~TIOCM_DTR;
dtr = 0;
}
priv->control_state = control_state;
spin_unlock_irqrestore(&priv->lock, flags);
retval = BSA_USB_CMD(BELKIN_SA_SET_RTS_REQUEST, rts);
if (retval < 0) {
dev_err(&port->dev, "Set RTS error %d\n", retval);
goto exit;
}
retval = BSA_USB_CMD(BELKIN_SA_SET_DTR_REQUEST, dtr);
if (retval < 0) {
dev_err(&port->dev, "Set DTR error %d\n", retval);
goto exit;
}
exit:
return retval;
}
