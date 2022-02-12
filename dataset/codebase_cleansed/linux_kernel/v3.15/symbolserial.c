static void symbol_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct symbol_private *priv = usb_get_serial_port_data(port);
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
int result;
int data_length;
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
if (urb->actual_length > 1) {
data_length = urb->actual_length - 1;
tty_insert_flip_string(&port->port, &data[1], data_length);
tty_flip_buffer_push(&port->port);
} else {
dev_dbg(&port->dev, "%s - short packet\n", __func__);
}
exit:
spin_lock(&priv->lock);
if (!priv->throttled) {
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result)
dev_err(&port->dev,
"%s - failed resubmitting read urb, error %d\n",
__func__, result);
} else
priv->actually_throttled = true;
spin_unlock(&priv->lock);
}
static int symbol_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct symbol_private *priv = usb_get_serial_data(port->serial);
unsigned long flags;
int result = 0;
spin_lock_irqsave(&priv->lock, flags);
priv->throttled = false;
priv->actually_throttled = false;
spin_unlock_irqrestore(&priv->lock, flags);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev,
"%s - failed resubmitting read urb, error %d\n",
__func__, result);
return result;
}
static void symbol_close(struct usb_serial_port *port)
{
usb_kill_urb(port->interrupt_in_urb);
}
static void symbol_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct symbol_private *priv = usb_get_serial_data(port->serial);
spin_lock_irq(&priv->lock);
priv->throttled = true;
spin_unlock_irq(&priv->lock);
}
static void symbol_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct symbol_private *priv = usb_get_serial_data(port->serial);
int result;
bool was_throttled;
spin_lock_irq(&priv->lock);
priv->throttled = false;
was_throttled = priv->actually_throttled;
priv->actually_throttled = false;
spin_unlock_irq(&priv->lock);
if (was_throttled) {
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev,
"%s - failed submitting read urb, error %d\n",
__func__, result);
}
}
static int symbol_startup(struct usb_serial *serial)
{
if (!serial->num_interrupt_in) {
dev_err(&serial->dev->dev, "no interrupt-in endpoint\n");
return -ENODEV;
}
return 0;
}
static int symbol_port_probe(struct usb_serial_port *port)
{
struct symbol_private *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
usb_set_serial_port_data(port, priv);
return 0;
}
static int symbol_port_remove(struct usb_serial_port *port)
{
struct symbol_private *priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
