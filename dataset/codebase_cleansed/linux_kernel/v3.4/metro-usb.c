static void metrousb_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct metrousb_private *metro_priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
int throttled = 0;
int result = 0;
unsigned long flags = 0;
dev_dbg(&port->dev, "%s\n", __func__);
switch (urb->status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dev_dbg(&port->dev,
"%s - urb shutting down, error code=%d\n",
__func__, result);
return;
default:
dev_dbg(&port->dev,
"%s - non-zero urb received, error code=%d\n",
__func__, result);
goto exit;
}
tty = tty_port_tty_get(&port->port);
if (!tty) {
dev_dbg(&port->dev, "%s - bad tty pointer - exiting\n",
__func__);
return;
}
if (tty && urb->actual_length) {
tty_insert_flip_string(tty, data, urb->actual_length);
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
spin_lock_irqsave(&metro_priv->lock, flags);
throttled = metro_priv->throttled;
spin_unlock_irqrestore(&metro_priv->lock, flags);
if (!throttled) {
usb_fill_int_urb(port->interrupt_in_urb, port->serial->dev,
usb_rcvintpipe(port->serial->dev, port->interrupt_in_endpointAddress),
port->interrupt_in_urb->transfer_buffer,
port->interrupt_in_urb->transfer_buffer_length,
metrousb_read_int_callback, port, 1);
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result)
dev_dbg(&port->dev,
"%s - failed submitting interrupt in urb, error code=%d\n",
__func__, result);
}
return;
exit:
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result)
dev_dbg(&port->dev,
"%s - failed submitting interrupt in urb, error code=%d\n",
__func__, result);
}
static void metrousb_cleanup(struct usb_serial_port *port)
{
dev_dbg(&port->dev, "%s\n", __func__);
if (port->serial->dev) {
if (port->interrupt_in_urb) {
usb_unlink_urb(port->interrupt_in_urb);
usb_kill_urb(port->interrupt_in_urb);
}
}
}
static int metrousb_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct metrousb_private *metro_priv = usb_get_serial_port_data(port);
unsigned long flags = 0;
int result = 0;
dev_dbg(&port->dev, "%s\n", __func__);
if (!port->interrupt_in_urb) {
dev_dbg(&port->dev, "%s - interrupt urb not initialized\n",
__func__);
return -ENODEV;
}
spin_lock_irqsave(&metro_priv->lock, flags);
metro_priv->control_state = 0;
metro_priv->throttled = 0;
spin_unlock_irqrestore(&metro_priv->lock, flags);
if (tty)
tty->low_latency = 1;
usb_clear_halt(serial->dev, port->interrupt_in_urb->pipe);
usb_fill_int_urb(port->interrupt_in_urb, serial->dev,
usb_rcvintpipe(serial->dev, port->interrupt_in_endpointAddress),
port->interrupt_in_urb->transfer_buffer,
port->interrupt_in_urb->transfer_buffer_length,
metrousb_read_int_callback, port, 1);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result) {
dev_dbg(&port->dev,
"%s - failed submitting interrupt in urb, error code=%d\n",
__func__, result);
goto exit;
}
dev_dbg(&port->dev, "%s - port open\n", __func__);
exit:
return result;
}
static int metrousb_set_modem_ctrl(struct usb_serial *serial, unsigned int control_state)
{
int retval = 0;
unsigned char mcr = METROUSB_MCR_NONE;
dev_dbg(&serial->dev->dev, "%s - control state = %d\n",
__func__, control_state);
if (control_state & TIOCM_DTR)
mcr |= METROUSB_MCR_DTR;
if (control_state & TIOCM_RTS)
mcr |= METROUSB_MCR_RTS;
retval = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),
METROUSB_SET_REQUEST_TYPE, METROUSB_SET_MODEM_CTRL_REQUEST,
control_state, 0, NULL, 0, WDR_TIMEOUT);
if (retval < 0)
dev_dbg(&serial->dev->dev,
"%s - set modem ctrl=0x%x failed, error code=%d\n",
__func__, mcr, retval);
return retval;
}
static void metrousb_shutdown(struct usb_serial *serial)
{
int i = 0;
dev_dbg(&serial->dev->dev, "%s\n", __func__);
for (i = 0; i < serial->num_ports; ++i) {
metrousb_cleanup(serial->port[i]);
kfree(usb_get_serial_port_data(serial->port[i]));
usb_set_serial_port_data(serial->port[i], NULL);
dev_dbg(&serial->dev->dev, "%s - freed port number=%d\n",
__func__, serial->port[i]->number);
}
}
static int metrousb_startup(struct usb_serial *serial)
{
struct metrousb_private *metro_priv;
struct usb_serial_port *port;
int i = 0;
dev_dbg(&serial->dev->dev, "%s\n", __func__);
for (i = 0; i < serial->num_ports; ++i) {
port = serial->port[i];
metro_priv = kzalloc(sizeof(struct metrousb_private), GFP_KERNEL);
if (!metro_priv)
return -ENOMEM;
spin_lock_init(&metro_priv->lock);
usb_set_serial_port_data(port, metro_priv);
dev_dbg(&serial->dev->dev, "%s - port number=%d\n ",
__func__, port->number);
}
return 0;
}
static void metrousb_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct metrousb_private *metro_priv = usb_get_serial_port_data(port);
unsigned long flags = 0;
dev_dbg(tty->dev, "%s\n", __func__);
spin_lock_irqsave(&metro_priv->lock, flags);
metro_priv->throttled = 1;
spin_unlock_irqrestore(&metro_priv->lock, flags);
}
static int metrousb_tiocmget(struct tty_struct *tty)
{
unsigned long control_state = 0;
struct usb_serial_port *port = tty->driver_data;
struct metrousb_private *metro_priv = usb_get_serial_port_data(port);
unsigned long flags = 0;
dev_dbg(tty->dev, "%s\n", __func__);
spin_lock_irqsave(&metro_priv->lock, flags);
control_state = metro_priv->control_state;
spin_unlock_irqrestore(&metro_priv->lock, flags);
return control_state;
}
static int metrousb_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
struct metrousb_private *metro_priv = usb_get_serial_port_data(port);
unsigned long flags = 0;
unsigned long control_state = 0;
dev_dbg(tty->dev, "%s - set=%d, clear=%d\n", __func__, set, clear);
spin_lock_irqsave(&metro_priv->lock, flags);
control_state = metro_priv->control_state;
if (set & TIOCM_RTS)
control_state |= TIOCM_RTS;
if (set & TIOCM_DTR)
control_state |= TIOCM_DTR;
if (clear & TIOCM_RTS)
control_state &= ~TIOCM_RTS;
if (clear & TIOCM_DTR)
control_state &= ~TIOCM_DTR;
metro_priv->control_state = control_state;
spin_unlock_irqrestore(&metro_priv->lock, flags);
return metrousb_set_modem_ctrl(serial, control_state);
}
static void metrousb_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct metrousb_private *metro_priv = usb_get_serial_port_data(port);
unsigned long flags = 0;
int result = 0;
dev_dbg(tty->dev, "%s\n", __func__);
spin_lock_irqsave(&metro_priv->lock, flags);
metro_priv->throttled = 0;
spin_unlock_irqrestore(&metro_priv->lock, flags);
port->interrupt_in_urb->dev = port->serial->dev;
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result)
dev_dbg(tty->dev,
"failed submitting interrupt in urb error code=%d\n",
result);
}
