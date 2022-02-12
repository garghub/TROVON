static int cyberjack_startup(struct usb_serial *serial)
{
struct cyberjack_private *priv;
int i;
dbg("%s", __func__);
priv = kmalloc(sizeof(struct cyberjack_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
priv->rdtodo = 0;
priv->wrfilled = 0;
priv->wrsent = 0;
usb_set_serial_port_data(serial->port[0], priv);
init_waitqueue_head(&serial->port[0]->write_wait);
for (i = 0; i < serial->num_ports; ++i) {
int result;
serial->port[i]->interrupt_in_urb->dev = serial->dev;
result = usb_submit_urb(serial->port[i]->interrupt_in_urb,
GFP_KERNEL);
if (result)
dev_err(&serial->dev->dev,
"usb_submit_urb(read int) failed\n");
dbg("%s - usb_submit_urb(int urb)", __func__);
}
return 0;
}
static void cyberjack_disconnect(struct usb_serial *serial)
{
int i;
dbg("%s", __func__);
for (i = 0; i < serial->num_ports; ++i)
usb_kill_urb(serial->port[i]->interrupt_in_urb);
}
static void cyberjack_release(struct usb_serial *serial)
{
int i;
dbg("%s", __func__);
for (i = 0; i < serial->num_ports; ++i) {
kfree(usb_get_serial_port_data(serial->port[i]));
}
}
static int cyberjack_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
struct cyberjack_private *priv;
unsigned long flags;
int result = 0;
dbg("%s - port %d", __func__, port->number);
dbg("%s - usb_clear_halt", __func__);
usb_clear_halt(port->serial->dev, port->write_urb->pipe);
priv = usb_get_serial_port_data(port);
spin_lock_irqsave(&priv->lock, flags);
priv->rdtodo = 0;
priv->wrfilled = 0;
priv->wrsent = 0;
spin_unlock_irqrestore(&priv->lock, flags);
return result;
}
static void cyberjack_close(struct usb_serial_port *port)
{
dbg("%s - port %d", __func__, port->number);
if (port->serial->dev) {
usb_kill_urb(port->write_urb);
usb_kill_urb(port->read_urb);
}
}
static int cyberjack_write(struct tty_struct *tty,
struct usb_serial_port *port, const unsigned char *buf, int count)
{
struct usb_serial *serial = port->serial;
struct cyberjack_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
int result;
int wrexpected;
dbg("%s - port %d", __func__, port->number);
if (count == 0) {
dbg("%s - write request of 0 bytes", __func__);
return 0;
}
spin_lock_bh(&port->lock);
if (port->write_urb_busy) {
spin_unlock_bh(&port->lock);
dbg("%s - already writing", __func__);
return 0;
}
port->write_urb_busy = 1;
spin_unlock_bh(&port->lock);
spin_lock_irqsave(&priv->lock, flags);
if (count+priv->wrfilled > sizeof(priv->wrbuf)) {
priv->wrfilled = 0;
port->write_urb_busy = 0;
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
memcpy(priv->wrbuf + priv->wrfilled, buf, count);
usb_serial_debug_data(debug, &port->dev, __func__, count,
priv->wrbuf + priv->wrfilled);
priv->wrfilled += count;
if (priv->wrfilled >= 3) {
wrexpected = ((int)priv->wrbuf[2]<<8)+priv->wrbuf[1]+3;
dbg("%s - expected data: %d", __func__, wrexpected);
} else
wrexpected = sizeof(priv->wrbuf);
if (priv->wrfilled >= wrexpected) {
int length;
dbg("%s - transmitting data (frame 1)", __func__);
length = (wrexpected > port->bulk_out_size) ?
port->bulk_out_size : wrexpected;
memcpy(port->write_urb->transfer_buffer, priv->wrbuf, length);
priv->wrsent = length;
usb_fill_bulk_urb(port->write_urb, serial->dev,
usb_sndbulkpipe(serial->dev, port->bulk_out_endpointAddress),
port->write_urb->transfer_buffer, length,
((serial->type->write_bulk_callback) ?
serial->type->write_bulk_callback :
cyberjack_write_bulk_callback),
port);
result = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (result) {
dev_err(&port->dev,
"%s - failed submitting write urb, error %d",
__func__, result);
priv->wrfilled = 0;
priv->wrsent = 0;
spin_unlock_irqrestore(&priv->lock, flags);
port->write_urb_busy = 0;
return 0;
}
dbg("%s - priv->wrsent=%d", __func__, priv->wrsent);
dbg("%s - priv->wrfilled=%d", __func__, priv->wrfilled);
if (priv->wrsent >= priv->wrfilled) {
dbg("%s - buffer cleaned", __func__);
memset(priv->wrbuf, 0, sizeof(priv->wrbuf));
priv->wrfilled = 0;
priv->wrsent = 0;
}
}
spin_unlock_irqrestore(&priv->lock, flags);
return count;
}
static int cyberjack_write_room(struct tty_struct *tty)
{
return CYBERJACK_LOCAL_BUF_SIZE;
}
static void cyberjack_read_int_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct cyberjack_private *priv = usb_get_serial_port_data(port);
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
int result;
dbg("%s - port %d", __func__, port->number);
if (status)
return;
usb_serial_debug_data(debug, &port->dev, __func__,
urb->actual_length, data);
if (urb->actual_length == 4 && data[0] == 0x01) {
short old_rdtodo;
unsigned short size = ((unsigned short)data[3]<<8)+data[2]+3;
spin_lock(&priv->lock);
old_rdtodo = priv->rdtodo;
if (old_rdtodo + size < old_rdtodo) {
dbg("To many bulk_in urbs to do.");
spin_unlock(&priv->lock);
goto resubmit;
}
priv->rdtodo += size;
dbg("%s - rdtodo: %d", __func__, priv->rdtodo);
spin_unlock(&priv->lock);
if (!old_rdtodo) {
port->read_urb->dev = port->serial->dev;
result = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (result)
dev_err(&port->dev, "%s - failed resubmitting "
"read urb, error %d\n",
__func__, result);
dbg("%s - usb_submit_urb(read urb)", __func__);
}
}
resubmit:
port->interrupt_in_urb->dev = port->serial->dev;
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result)
dev_err(&port->dev, "usb_submit_urb(read int) failed\n");
dbg("%s - usb_submit_urb(int urb)", __func__);
}
static void cyberjack_read_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct cyberjack_private *priv = usb_get_serial_port_data(port);
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
short todo;
int result;
int status = urb->status;
dbg("%s - port %d", __func__, port->number);
usb_serial_debug_data(debug, &port->dev, __func__,
urb->actual_length, data);
if (status) {
dbg("%s - nonzero read bulk status received: %d",
__func__, status);
return;
}
tty = tty_port_tty_get(&port->port);
if (!tty) {
dbg("%s - ignoring since device not open", __func__);
return;
}
if (urb->actual_length) {
tty_insert_flip_string(tty, data, urb->actual_length);
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
spin_lock(&priv->lock);
priv->rdtodo -= urb->actual_length;
if (priv->rdtodo < 0)
priv->rdtodo = 0;
todo = priv->rdtodo;
spin_unlock(&priv->lock);
dbg("%s - rdtodo: %d", __func__, todo);
if (todo ) {
port->read_urb->dev = port->serial->dev;
result = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (result)
dev_err(&port->dev, "%s - failed resubmitting read "
"urb, error %d\n", __func__, result);
dbg("%s - usb_submit_urb(read urb)", __func__);
}
}
static void cyberjack_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct cyberjack_private *priv = usb_get_serial_port_data(port);
int status = urb->status;
dbg("%s - port %d", __func__, port->number);
port->write_urb_busy = 0;
if (status) {
dbg("%s - nonzero write bulk status received: %d",
__func__, status);
return;
}
spin_lock(&priv->lock);
if (priv->wrfilled) {
int length, blksize, result;
dbg("%s - transmitting data (frame n)", __func__);
length = ((priv->wrfilled - priv->wrsent) > port->bulk_out_size) ?
port->bulk_out_size : (priv->wrfilled - priv->wrsent);
memcpy(port->write_urb->transfer_buffer,
priv->wrbuf + priv->wrsent, length);
priv->wrsent += length;
usb_fill_bulk_urb(port->write_urb, port->serial->dev,
usb_sndbulkpipe(port->serial->dev, port->bulk_out_endpointAddress),
port->write_urb->transfer_buffer, length,
((port->serial->type->write_bulk_callback) ?
port->serial->type->write_bulk_callback :
cyberjack_write_bulk_callback),
port);
result = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (result) {
dev_err(&port->dev,
"%s - failed submitting write urb, error %d\n",
__func__, result);
priv->wrfilled = 0;
priv->wrsent = 0;
goto exit;
}
dbg("%s - priv->wrsent=%d", __func__, priv->wrsent);
dbg("%s - priv->wrfilled=%d", __func__, priv->wrfilled);
blksize = ((int)priv->wrbuf[2]<<8)+priv->wrbuf[1]+3;
if (priv->wrsent >= priv->wrfilled ||
priv->wrsent >= blksize) {
dbg("%s - buffer cleaned", __func__);
memset(priv->wrbuf, 0, sizeof(priv->wrbuf));
priv->wrfilled = 0;
priv->wrsent = 0;
}
}
exit:
spin_unlock(&priv->lock);
usb_serial_port_softint(port);
}
static int __init cyberjack_init(void)
{
int retval;
retval = usb_serial_register(&cyberjack_device);
if (retval)
goto failed_usb_serial_register;
retval = usb_register(&cyberjack_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION " "
DRIVER_AUTHOR "\n");
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_DESC "\n");
return 0;
failed_usb_register:
usb_serial_deregister(&cyberjack_device);
failed_usb_serial_register:
return retval;
}
static void __exit cyberjack_exit(void)
{
usb_deregister(&cyberjack_driver);
usb_serial_deregister(&cyberjack_device);
}
