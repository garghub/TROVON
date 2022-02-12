static int mct_u232_calculate_baud_rate(struct usb_serial *serial,
speed_t value, speed_t *result)
{
*result = value;
if (le16_to_cpu(serial->dev->descriptor.idProduct) == MCT_U232_SITECOM_PID
|| le16_to_cpu(serial->dev->descriptor.idProduct) == MCT_U232_BELKIN_F5U109_PID) {
switch (value) {
case 300:
return 0x01;
case 600:
return 0x02;
case 1200:
return 0x03;
case 2400:
return 0x04;
case 4800:
return 0x06;
case 9600:
return 0x08;
case 19200:
return 0x09;
case 38400:
return 0x0a;
case 57600:
return 0x0b;
case 115200:
return 0x0c;
default:
*result = 9600;
return 0x08;
}
} else {
switch (value) {
case 300: break;
case 600: break;
case 1200: break;
case 2400: break;
case 4800: break;
case 9600: break;
case 19200: break;
case 38400: break;
case 57600: break;
case 115200: break;
default:
value = 9600;
*result = 9600;
}
return 115200/value;
}
}
static int mct_u232_set_baud_rate(struct tty_struct *tty,
struct usb_serial *serial, struct usb_serial_port *port, speed_t value)
{
unsigned int divisor;
int rc;
unsigned char *buf;
unsigned char cts_enable_byte = 0;
speed_t speed;
buf = kmalloc(MCT_U232_MAX_SIZE, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
divisor = mct_u232_calculate_baud_rate(serial, value, &speed);
put_unaligned_le32(cpu_to_le32(divisor), buf);
rc = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
MCT_U232_SET_BAUD_RATE_REQUEST,
MCT_U232_SET_REQUEST_TYPE,
0, 0, buf, MCT_U232_SET_BAUD_RATE_SIZE,
WDR_TIMEOUT);
if (rc < 0)
dev_err(&port->dev, "Set BAUD RATE %d failed (error = %d)\n",
value, rc);
else
tty_encode_baud_rate(tty, speed, speed);
dev_dbg(&port->dev, "set_baud_rate: value: 0x%x, divisor: 0x%x\n", value, divisor);
buf[0] = 0;
rc = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
MCT_U232_SET_UNKNOWN1_REQUEST,
MCT_U232_SET_REQUEST_TYPE,
0, 0, buf, MCT_U232_SET_UNKNOWN1_SIZE,
WDR_TIMEOUT);
if (rc < 0)
dev_err(&port->dev, "Sending USB device request code %d "
"failed (error = %d)\n", MCT_U232_SET_UNKNOWN1_REQUEST,
rc);
if (port && C_CRTSCTS(tty))
cts_enable_byte = 1;
dev_dbg(&port->dev, "set_baud_rate: send second control message, data = %02X\n",
cts_enable_byte);
buf[0] = cts_enable_byte;
rc = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
MCT_U232_SET_CTS_REQUEST,
MCT_U232_SET_REQUEST_TYPE,
0, 0, buf, MCT_U232_SET_CTS_SIZE,
WDR_TIMEOUT);
if (rc < 0)
dev_err(&port->dev, "Sending USB device request code %d "
"failed (error = %d)\n", MCT_U232_SET_CTS_REQUEST, rc);
kfree(buf);
return rc;
}
static int mct_u232_set_line_ctrl(struct usb_serial_port *port,
unsigned char lcr)
{
int rc;
unsigned char *buf;
buf = kmalloc(MCT_U232_MAX_SIZE, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
buf[0] = lcr;
rc = usb_control_msg(port->serial->dev, usb_sndctrlpipe(port->serial->dev, 0),
MCT_U232_SET_LINE_CTRL_REQUEST,
MCT_U232_SET_REQUEST_TYPE,
0, 0, buf, MCT_U232_SET_LINE_CTRL_SIZE,
WDR_TIMEOUT);
if (rc < 0)
dev_err(&port->dev, "Set LINE CTRL 0x%x failed (error = %d)\n", lcr, rc);
dev_dbg(&port->dev, "set_line_ctrl: 0x%x\n", lcr);
kfree(buf);
return rc;
}
static int mct_u232_set_modem_ctrl(struct usb_serial_port *port,
unsigned int control_state)
{
int rc;
unsigned char mcr;
unsigned char *buf;
buf = kmalloc(MCT_U232_MAX_SIZE, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
mcr = MCT_U232_MCR_NONE;
if (control_state & TIOCM_DTR)
mcr |= MCT_U232_MCR_DTR;
if (control_state & TIOCM_RTS)
mcr |= MCT_U232_MCR_RTS;
buf[0] = mcr;
rc = usb_control_msg(port->serial->dev, usb_sndctrlpipe(port->serial->dev, 0),
MCT_U232_SET_MODEM_CTRL_REQUEST,
MCT_U232_SET_REQUEST_TYPE,
0, 0, buf, MCT_U232_SET_MODEM_CTRL_SIZE,
WDR_TIMEOUT);
kfree(buf);
dev_dbg(&port->dev, "set_modem_ctrl: state=0x%x ==> mcr=0x%x\n", control_state, mcr);
if (rc < 0) {
dev_err(&port->dev, "Set MODEM CTRL 0x%x failed (error = %d)\n", mcr, rc);
return rc;
}
return 0;
}
static int mct_u232_get_modem_stat(struct usb_serial_port *port,
unsigned char *msr)
{
int rc;
unsigned char *buf;
buf = kmalloc(MCT_U232_MAX_SIZE, GFP_KERNEL);
if (buf == NULL) {
*msr = 0;
return -ENOMEM;
}
rc = usb_control_msg(port->serial->dev, usb_rcvctrlpipe(port->serial->dev, 0),
MCT_U232_GET_MODEM_STAT_REQUEST,
MCT_U232_GET_REQUEST_TYPE,
0, 0, buf, MCT_U232_GET_MODEM_STAT_SIZE,
WDR_TIMEOUT);
if (rc < MCT_U232_GET_MODEM_STAT_SIZE) {
dev_err(&port->dev, "Get MODEM STATus failed (error = %d)\n", rc);
if (rc >= 0)
rc = -EIO;
*msr = 0;
} else {
*msr = buf[0];
}
dev_dbg(&port->dev, "get_modem_stat: 0x%x\n", *msr);
kfree(buf);
return rc;
}
static void mct_u232_msr_to_icount(struct async_icount *icount,
unsigned char msr)
{
if (msr & MCT_U232_MSR_DDSR)
icount->dsr++;
if (msr & MCT_U232_MSR_DCTS)
icount->cts++;
if (msr & MCT_U232_MSR_DRI)
icount->rng++;
if (msr & MCT_U232_MSR_DCD)
icount->dcd++;
}
static void mct_u232_msr_to_state(struct usb_serial_port *port,
unsigned int *control_state, unsigned char msr)
{
if (msr & MCT_U232_MSR_DSR)
*control_state |= TIOCM_DSR;
else
*control_state &= ~TIOCM_DSR;
if (msr & MCT_U232_MSR_CTS)
*control_state |= TIOCM_CTS;
else
*control_state &= ~TIOCM_CTS;
if (msr & MCT_U232_MSR_RI)
*control_state |= TIOCM_RI;
else
*control_state &= ~TIOCM_RI;
if (msr & MCT_U232_MSR_CD)
*control_state |= TIOCM_CD;
else
*control_state &= ~TIOCM_CD;
dev_dbg(&port->dev, "msr_to_state: msr=0x%x ==> state=0x%x\n", msr, *control_state);
}
static int mct_u232_port_probe(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct mct_u232_private *priv;
if (!serial->port[1] || !serial->port[1]->interrupt_in_urb) {
dev_err(&port->dev, "expected endpoint missing\n");
return -ENODEV;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->read_urb = serial->port[1]->interrupt_in_urb;
priv->read_urb->context = port;
spin_lock_init(&priv->lock);
usb_set_serial_port_data(port, priv);
return 0;
}
static int mct_u232_port_remove(struct usb_serial_port *port)
{
struct mct_u232_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
static int mct_u232_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
int retval = 0;
unsigned int control_state;
unsigned long flags;
unsigned char last_lcr;
unsigned char last_msr;
if (le16_to_cpu(serial->dev->descriptor.idProduct)
== MCT_U232_SITECOM_PID)
port->bulk_out_size = 16;
spin_lock_irqsave(&priv->lock, flags);
if (tty && C_BAUD(tty))
priv->control_state = TIOCM_DTR | TIOCM_RTS;
else
priv->control_state = 0;
priv->last_lcr = (MCT_U232_DATA_BITS_8 |
MCT_U232_PARITY_NONE |
MCT_U232_STOP_BITS_1);
control_state = priv->control_state;
last_lcr = priv->last_lcr;
spin_unlock_irqrestore(&priv->lock, flags);
mct_u232_set_modem_ctrl(port, control_state);
mct_u232_set_line_ctrl(port, last_lcr);
mct_u232_get_modem_stat(port, &last_msr);
spin_lock_irqsave(&priv->lock, flags);
priv->last_msr = last_msr;
mct_u232_msr_to_state(port, &priv->control_state, priv->last_msr);
spin_unlock_irqrestore(&priv->lock, flags);
retval = usb_submit_urb(priv->read_urb, GFP_KERNEL);
if (retval) {
dev_err(&port->dev,
"usb_submit_urb(read) failed pipe 0x%x err %d\n",
port->read_urb->pipe, retval);
goto error;
}
retval = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (retval) {
usb_kill_urb(priv->read_urb);
dev_err(&port->dev,
"usb_submit_urb(read int) failed pipe 0x%x err %d",
port->interrupt_in_urb->pipe, retval);
goto error;
}
return 0;
error:
return retval;
}
static void mct_u232_dtr_rts(struct usb_serial_port *port, int on)
{
unsigned int control_state;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
spin_lock_irq(&priv->lock);
if (on)
priv->control_state |= TIOCM_DTR | TIOCM_RTS;
else
priv->control_state &= ~(TIOCM_DTR | TIOCM_RTS);
control_state = priv->control_state;
spin_unlock_irq(&priv->lock);
mct_u232_set_modem_ctrl(port, control_state);
}
static void mct_u232_close(struct usb_serial_port *port)
{
struct mct_u232_private *priv = usb_get_serial_port_data(port);
usb_kill_urb(priv->read_urb);
usb_kill_urb(port->interrupt_in_urb);
usb_serial_generic_close(port);
}
static void mct_u232_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
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
dev_dbg(&port->dev, "%s - urb shutting down with status: %d\n",
__func__, status);
return;
default:
dev_dbg(&port->dev, "%s - nonzero urb status received: %d\n",
__func__, status);
goto exit;
}
usb_serial_debug_data(&port->dev, __func__, urb->actual_length, data);
if (urb->transfer_buffer_length > 2) {
if (urb->actual_length) {
tty_insert_flip_string(&port->port, data,
urb->actual_length);
tty_flip_buffer_push(&port->port);
}
goto exit;
}
spin_lock_irqsave(&priv->lock, flags);
priv->last_msr = data[MCT_U232_MSR_INDEX];
mct_u232_msr_to_state(port, &priv->control_state, priv->last_msr);
mct_u232_msr_to_icount(&port->icount, priv->last_msr);
#if 0
priv->last_lsr = data[MCT_U232_LSR_INDEX];
if (priv->last_lsr & MCT_U232_LSR_ERR) {
tty = tty_port_tty_get(&port->port);
if (priv->last_lsr & MCT_U232_LSR_OE) {
}
if (priv->last_lsr & MCT_U232_LSR_PE) {
}
if (priv->last_lsr & MCT_U232_LSR_FE) {
}
if (priv->last_lsr & MCT_U232_LSR_BI) {
}
tty_kref_put(tty);
}
#endif
wake_up_interruptible(&port->port.delta_msr_wait);
spin_unlock_irqrestore(&priv->lock, flags);
exit:
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&port->dev,
"%s - usb_submit_urb failed with result %d\n",
__func__, retval);
}
static void mct_u232_set_termios(struct tty_struct *tty,
struct usb_serial_port *port,
struct ktermios *old_termios)
{
struct usb_serial *serial = port->serial;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
struct ktermios *termios = &tty->termios;
unsigned int cflag = termios->c_cflag;
unsigned int old_cflag = old_termios->c_cflag;
unsigned long flags;
unsigned int control_state;
unsigned char last_lcr;
spin_lock_irqsave(&priv->lock, flags);
control_state = priv->control_state;
spin_unlock_irqrestore(&priv->lock, flags);
last_lcr = 0;
if ((old_cflag & CBAUD) == B0) {
dev_dbg(&port->dev, "%s: baud was B0\n", __func__);
control_state |= TIOCM_DTR | TIOCM_RTS;
mct_u232_set_modem_ctrl(port, control_state);
}
mct_u232_set_baud_rate(tty, serial, port, tty_get_baud_rate(tty));
if ((cflag & CBAUD) == B0) {
dev_dbg(&port->dev, "%s: baud is B0\n", __func__);
control_state &= ~(TIOCM_DTR | TIOCM_RTS);
mct_u232_set_modem_ctrl(port, control_state);
}
if (cflag & PARENB)
last_lcr |= (cflag & PARODD) ?
MCT_U232_PARITY_ODD : MCT_U232_PARITY_EVEN;
else
last_lcr |= MCT_U232_PARITY_NONE;
switch (cflag & CSIZE) {
case CS5:
last_lcr |= MCT_U232_DATA_BITS_5; break;
case CS6:
last_lcr |= MCT_U232_DATA_BITS_6; break;
case CS7:
last_lcr |= MCT_U232_DATA_BITS_7; break;
case CS8:
last_lcr |= MCT_U232_DATA_BITS_8; break;
default:
dev_err(&port->dev,
"CSIZE was not CS5-CS8, using default of 8\n");
last_lcr |= MCT_U232_DATA_BITS_8;
break;
}
termios->c_cflag &= ~CMSPAR;
last_lcr |= (cflag & CSTOPB) ?
MCT_U232_STOP_BITS_2 : MCT_U232_STOP_BITS_1;
mct_u232_set_line_ctrl(port, last_lcr);
spin_lock_irqsave(&priv->lock, flags);
priv->control_state = control_state;
priv->last_lcr = last_lcr;
spin_unlock_irqrestore(&priv->lock, flags);
}
static void mct_u232_break_ctl(struct tty_struct *tty, int break_state)
{
struct usb_serial_port *port = tty->driver_data;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
unsigned char lcr;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
lcr = priv->last_lcr;
if (break_state)
lcr |= MCT_U232_SET_BREAK;
spin_unlock_irqrestore(&priv->lock, flags);
mct_u232_set_line_ctrl(port, lcr);
}
static int mct_u232_tiocmget(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
unsigned int control_state;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
control_state = priv->control_state;
spin_unlock_irqrestore(&priv->lock, flags);
return control_state;
}
static int mct_u232_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
unsigned int control_state;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
control_state = priv->control_state;
if (set & TIOCM_RTS)
control_state |= TIOCM_RTS;
if (set & TIOCM_DTR)
control_state |= TIOCM_DTR;
if (clear & TIOCM_RTS)
control_state &= ~TIOCM_RTS;
if (clear & TIOCM_DTR)
control_state &= ~TIOCM_DTR;
priv->control_state = control_state;
spin_unlock_irqrestore(&priv->lock, flags);
return mct_u232_set_modem_ctrl(port, control_state);
}
static void mct_u232_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
unsigned int control_state;
spin_lock_irq(&priv->lock);
priv->rx_flags |= THROTTLED;
if (C_CRTSCTS(tty)) {
priv->control_state &= ~TIOCM_RTS;
control_state = priv->control_state;
spin_unlock_irq(&priv->lock);
mct_u232_set_modem_ctrl(port, control_state);
} else {
spin_unlock_irq(&priv->lock);
}
}
static void mct_u232_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct mct_u232_private *priv = usb_get_serial_port_data(port);
unsigned int control_state;
spin_lock_irq(&priv->lock);
if ((priv->rx_flags & THROTTLED) && C_CRTSCTS(tty)) {
priv->rx_flags &= ~THROTTLED;
priv->control_state |= TIOCM_RTS;
control_state = priv->control_state;
spin_unlock_irq(&priv->lock);
mct_u232_set_modem_ctrl(port, control_state);
} else {
spin_unlock_irq(&priv->lock);
}
}
