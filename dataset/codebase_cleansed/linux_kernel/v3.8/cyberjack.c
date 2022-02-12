static int cyberjack_port_probe(struct usb_serial_port *port)
{
struct cyberjack_private *priv;
int result;
priv = kmalloc(sizeof(struct cyberjack_private), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spin_lock_init(&priv->lock);
priv->rdtodo = 0;
priv->wrfilled = 0;
priv->wrsent = 0;
usb_set_serial_port_data(port, priv);
result = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev, "usb_submit_urb(read int) failed\n");
return 0;
}
static int cyberjack_port_remove(struct usb_serial_port *port)
{
struct cyberjack_private *priv;
priv = usb_get_serial_port_data(port);
kfree(priv);
return 0;
}
static void cyberjack_disconnect(struct usb_serial *serial)
{
int i;
for (i = 0; i < serial->num_ports; ++i)
usb_kill_urb(serial->port[i]->interrupt_in_urb);
}
static int cyberjack_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
struct cyberjack_private *priv;
unsigned long flags;
int result = 0;
dev_dbg(&port->dev, "%s - usb_clear_halt\n", __func__);
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
if (port->serial->dev) {
usb_kill_urb(port->write_urb);
usb_kill_urb(port->read_urb);
}
}
static int cyberjack_write(struct tty_struct *tty,
struct usb_serial_port *port, const unsigned char *buf, int count)
{
struct device *dev = &port->dev;
struct cyberjack_private *priv = usb_get_serial_port_data(port);
unsigned long flags;
int result;
int wrexpected;
if (count == 0) {
dev_dbg(dev, "%s - write request of 0 bytes\n", __func__);
return 0;
}
if (!test_and_clear_bit(0, &port->write_urbs_free)) {
dev_dbg(dev, "%s - already writing\n", __func__);
return 0;
}
spin_lock_irqsave(&priv->lock, flags);
if (count+priv->wrfilled > sizeof(priv->wrbuf)) {
priv->wrfilled = 0;
spin_unlock_irqrestore(&priv->lock, flags);
set_bit(0, &port->write_urbs_free);
return 0;
}
memcpy(priv->wrbuf + priv->wrfilled, buf, count);
usb_serial_debug_data(dev, __func__, count, priv->wrbuf + priv->wrfilled);
priv->wrfilled += count;
if (priv->wrfilled >= 3) {
wrexpected = ((int)priv->wrbuf[2]<<8)+priv->wrbuf[1]+3;
dev_dbg(dev, "%s - expected data: %d\n", __func__, wrexpected);
} else
wrexpected = sizeof(priv->wrbuf);
if (priv->wrfilled >= wrexpected) {
int length;
dev_dbg(dev, "%s - transmitting data (frame 1)\n", __func__);
length = (wrexpected > port->bulk_out_size) ?
port->bulk_out_size : wrexpected;
memcpy(port->write_urb->transfer_buffer, priv->wrbuf, length);
priv->wrsent = length;
port->write_urb->transfer_buffer_length = length;
result = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (result) {
dev_err(&port->dev,
"%s - failed submitting write urb, error %d",
__func__, result);
priv->wrfilled = 0;
priv->wrsent = 0;
spin_unlock_irqrestore(&priv->lock, flags);
set_bit(0, &port->write_urbs_free);
return 0;
}
dev_dbg(dev, "%s - priv->wrsent=%d\n", __func__, priv->wrsent);
dev_dbg(dev, "%s - priv->wrfilled=%d\n", __func__, priv->wrfilled);
if (priv->wrsent >= priv->wrfilled) {
dev_dbg(dev, "%s - buffer cleaned\n", __func__);
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
struct device *dev = &port->dev;
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
int result;
if (status)
return;
usb_serial_debug_data(dev, __func__, urb->actual_length, data);
if (urb->actual_length == 4 && data[0] == 0x01) {
short old_rdtodo;
unsigned short size = ((unsigned short)data[3]<<8)+data[2]+3;
spin_lock(&priv->lock);
old_rdtodo = priv->rdtodo;
if (old_rdtodo + size < old_rdtodo) {
dev_dbg(dev, "To many bulk_in urbs to do.\n");
spin_unlock(&priv->lock);
goto resubmit;
}
priv->rdtodo += size;
dev_dbg(dev, "%s - rdtodo: %d\n", __func__, priv->rdtodo);
spin_unlock(&priv->lock);
if (!old_rdtodo) {
result = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (result)
dev_err(dev, "%s - failed resubmitting read urb, error %d\n",
__func__, result);
dev_dbg(dev, "%s - usb_submit_urb(read urb)\n", __func__);
}
}
resubmit:
result = usb_submit_urb(port->interrupt_in_urb, GFP_ATOMIC);
if (result)
dev_err(&port->dev, "usb_submit_urb(read int) failed\n");
dev_dbg(dev, "%s - usb_submit_urb(int urb)\n", __func__);
}
static void cyberjack_read_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct cyberjack_private *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
struct tty_struct *tty;
unsigned char *data = urb->transfer_buffer;
short todo;
int result;
int status = urb->status;
usb_serial_debug_data(dev, __func__, urb->actual_length, data);
if (status) {
dev_dbg(dev, "%s - nonzero read bulk status received: %d\n",
__func__, status);
return;
}
tty = tty_port_tty_get(&port->port);
if (!tty) {
dev_dbg(dev, "%s - ignoring since device not open\n", __func__);
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
dev_dbg(dev, "%s - rdtodo: %d\n", __func__, todo);
if (todo ) {
result = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (result)
dev_err(dev, "%s - failed resubmitting read urb, error %d\n",
__func__, result);
dev_dbg(dev, "%s - usb_submit_urb(read urb)\n", __func__);
}
}
static void cyberjack_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
struct cyberjack_private *priv = usb_get_serial_port_data(port);
struct device *dev = &port->dev;
int status = urb->status;
set_bit(0, &port->write_urbs_free);
if (status) {
dev_dbg(dev, "%s - nonzero write bulk status received: %d\n",
__func__, status);
return;
}
spin_lock(&priv->lock);
if (priv->wrfilled) {
int length, blksize, result;
dev_dbg(dev, "%s - transmitting data (frame n)\n", __func__);
length = ((priv->wrfilled - priv->wrsent) > port->bulk_out_size) ?
port->bulk_out_size : (priv->wrfilled - priv->wrsent);
memcpy(port->write_urb->transfer_buffer,
priv->wrbuf + priv->wrsent, length);
priv->wrsent += length;
port->write_urb->transfer_buffer_length = length;
result = usb_submit_urb(port->write_urb, GFP_ATOMIC);
if (result) {
dev_err(dev, "%s - failed submitting write urb, error %d\n",
__func__, result);
priv->wrfilled = 0;
priv->wrsent = 0;
goto exit;
}
dev_dbg(dev, "%s - priv->wrsent=%d\n", __func__, priv->wrsent);
dev_dbg(dev, "%s - priv->wrfilled=%d\n", __func__, priv->wrfilled);
blksize = ((int)priv->wrbuf[2]<<8)+priv->wrbuf[1]+3;
if (priv->wrsent >= priv->wrfilled ||
priv->wrsent >= blksize) {
dev_dbg(dev, "%s - buffer cleaned\n", __func__);
memset(priv->wrbuf, 0, sizeof(priv->wrbuf));
priv->wrfilled = 0;
priv->wrsent = 0;
}
}
exit:
spin_unlock(&priv->lock);
usb_serial_port_softint(port);
}
