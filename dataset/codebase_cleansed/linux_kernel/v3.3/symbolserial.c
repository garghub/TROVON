static void symbol_int_callback(struct urb *urb)
{
struct symbol_private *priv = urb->context;
unsigned char *data = urb->transfer_buffer;
struct usb_serial_port *port = priv->port;
int status = urb->status;
struct tty_struct *tty;
int result;
int data_length;
dbg("%s - port %d", __func__, port->number);
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
usb_serial_debug_data(debug, &port->dev, __func__, urb->actual_length,
data);
if (urb->actual_length > 1) {
data_length = urb->actual_length - 1;
tty = tty_port_tty_get(&port->port);
if (tty) {
tty_insert_flip_string(tty, &data[1], data_length);
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
} else {
dev_dbg(&priv->udev->dev,
"Improper amount of data received from the device, "
"%d bytes", urb->actual_length);
}
exit:
spin_lock(&priv->lock);
if (!priv->throttled) {
usb_fill_int_urb(priv->int_urb, priv->udev,
usb_rcvintpipe(priv->udev,
priv->int_address),
priv->int_buffer, priv->buffer_size,
symbol_int_callback, priv, priv->bInterval);
result = usb_submit_urb(priv->int_urb, GFP_ATOMIC);
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
dbg("%s - port %d", __func__, port->number);
spin_lock_irqsave(&priv->lock, flags);
priv->throttled = false;
priv->actually_throttled = false;
priv->port = port;
spin_unlock_irqrestore(&priv->lock, flags);
usb_fill_int_urb(priv->int_urb, priv->udev,
usb_rcvintpipe(priv->udev, priv->int_address),
priv->int_buffer, priv->buffer_size,
symbol_int_callback, priv, priv->bInterval);
result = usb_submit_urb(priv->int_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev,
"%s - failed resubmitting read urb, error %d\n",
__func__, result);
return result;
}
static void symbol_close(struct usb_serial_port *port)
{
struct symbol_private *priv = usb_get_serial_data(port->serial);
dbg("%s - port %d", __func__, port->number);
usb_kill_urb(priv->int_urb);
}
static void symbol_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct symbol_private *priv = usb_get_serial_data(port->serial);
dbg("%s - port %d", __func__, port->number);
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
dbg("%s - port %d", __func__, port->number);
spin_lock_irq(&priv->lock);
priv->throttled = false;
was_throttled = priv->actually_throttled;
priv->actually_throttled = false;
spin_unlock_irq(&priv->lock);
if (was_throttled) {
result = usb_submit_urb(priv->int_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev,
"%s - failed submitting read urb, error %d\n",
__func__, result);
}
}
static int symbol_startup(struct usb_serial *serial)
{
struct symbol_private *priv;
struct usb_host_interface *intf;
int i;
int retval = -ENOMEM;
bool int_in_found = false;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL) {
dev_err(&serial->dev->dev, "%s - Out of memory\n", __func__);
return -ENOMEM;
}
spin_lock_init(&priv->lock);
priv->serial = serial;
priv->port = serial->port[0];
priv->udev = serial->dev;
intf = serial->interface->altsetting;
for (i = 0; i < intf->desc.bNumEndpoints; ++i) {
struct usb_endpoint_descriptor *endpoint;
endpoint = &intf->endpoint[i].desc;
if (!usb_endpoint_is_int_in(endpoint))
continue;
priv->int_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!priv->int_urb) {
dev_err(&priv->udev->dev, "out of memory\n");
goto error;
}
priv->buffer_size = usb_endpoint_maxp(endpoint) * 2;
priv->int_buffer = kmalloc(priv->buffer_size, GFP_KERNEL);
if (!priv->int_buffer) {
dev_err(&priv->udev->dev, "out of memory\n");
goto error;
}
priv->int_address = endpoint->bEndpointAddress;
priv->bInterval = endpoint->bInterval;
usb_fill_int_urb(priv->int_urb, priv->udev,
usb_rcvintpipe(priv->udev,
endpoint->bEndpointAddress),
priv->int_buffer, priv->buffer_size,
symbol_int_callback, priv, priv->bInterval);
int_in_found = true;
break;
}
if (!int_in_found) {
dev_err(&priv->udev->dev,
"Error - the proper endpoints were not found!\n");
goto error;
}
usb_set_serial_data(serial, priv);
return 0;
error:
usb_free_urb(priv->int_urb);
kfree(priv->int_buffer);
kfree(priv);
return retval;
}
static void symbol_disconnect(struct usb_serial *serial)
{
struct symbol_private *priv = usb_get_serial_data(serial);
dbg("%s", __func__);
usb_kill_urb(priv->int_urb);
usb_free_urb(priv->int_urb);
}
static void symbol_release(struct usb_serial *serial)
{
struct symbol_private *priv = usb_get_serial_data(serial);
dbg("%s", __func__);
kfree(priv->int_buffer);
kfree(priv);
}
static int __init symbol_init(void)
{
int retval;
retval = usb_serial_register(&symbol_device);
if (retval)
return retval;
retval = usb_register(&symbol_driver);
if (retval)
usb_serial_deregister(&symbol_device);
return retval;
}
static void __exit symbol_exit(void)
{
usb_deregister(&symbol_driver);
usb_serial_deregister(&symbol_device);
}
