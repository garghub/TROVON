static int omninet_attach(struct usb_serial *serial)
{
struct omninet_data *od;
struct usb_serial_port *port = serial->port[0];
od = kmalloc(sizeof(struct omninet_data), GFP_KERNEL);
if (!od) {
dev_err(&port->dev, "%s- kmalloc(%Zd) failed.\n",
__func__, sizeof(struct omninet_data));
return -ENOMEM;
}
usb_set_serial_port_data(port, od);
return 0;
}
static int omninet_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct usb_serial_port *wport;
int result = 0;
dbg("%s - port %d", __func__, port->number);
wport = serial->port[1];
tty_port_tty_set(&wport->port, tty);
result = usb_submit_urb(port->read_urb, GFP_KERNEL);
if (result)
dev_err(&port->dev,
"%s - failed submitting read urb, error %d\n",
__func__, result);
return result;
}
static void omninet_close(struct usb_serial_port *port)
{
dbg("%s - port %d", __func__, port->number);
usb_kill_urb(port->read_urb);
}
static void omninet_read_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
struct omninet_header *header = (struct omninet_header *) &data[0];
int status = urb->status;
int result;
int i;
dbg("%s - port %d", __func__, port->number);
if (status) {
dbg("%s - nonzero read bulk status received: %d",
__func__, status);
return;
}
if (debug && header->oh_xxx != 0x30) {
if (urb->actual_length) {
printk(KERN_DEBUG "%s: omninet_read %d: ",
__FILE__, header->oh_len);
for (i = 0; i < (header->oh_len +
OMNINET_HEADERLEN); i++)
printk("%.2x ", data[i]);
printk("\n");
}
}
if (urb->actual_length && header->oh_len) {
struct tty_struct *tty = tty_port_tty_get(&port->port);
tty_insert_flip_string(tty, data + OMNINET_DATAOFFSET,
header->oh_len);
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result)
dev_err(&port->dev,
"%s - failed resubmitting read urb, error %d\n",
__func__, result);
}
static int omninet_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
struct usb_serial *serial = port->serial;
struct usb_serial_port *wport = serial->port[1];
struct omninet_data *od = usb_get_serial_port_data(port);
struct omninet_header *header = (struct omninet_header *)
wport->write_urb->transfer_buffer;
int result;
dbg("%s - port %d", __func__, port->number);
if (count == 0) {
dbg("%s - write request of 0 bytes", __func__);
return 0;
}
if (!test_and_clear_bit(0, &port->write_urbs_free)) {
dbg("%s - already writing", __func__);
return 0;
}
count = (count > OMNINET_BULKOUTSIZE) ? OMNINET_BULKOUTSIZE : count;
memcpy(wport->write_urb->transfer_buffer + OMNINET_DATAOFFSET,
buf, count);
usb_serial_debug_data(debug, &port->dev, __func__, count,
wport->write_urb->transfer_buffer);
header->oh_seq = od->od_outseq++;
header->oh_len = count;
header->oh_xxx = 0x03;
header->oh_pad = 0x00;
wport->write_urb->transfer_buffer_length = 64;
result = usb_submit_urb(wport->write_urb, GFP_ATOMIC);
if (result) {
set_bit(0, &wport->write_urbs_free);
dev_err(&port->dev,
"%s - failed submitting write urb, error %d\n",
__func__, result);
} else
result = count;
return result;
}
static int omninet_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct usb_serial *serial = port->serial;
struct usb_serial_port *wport = serial->port[1];
int room = 0;
if (test_bit(0, &wport->write_urbs_free))
room = wport->bulk_out_size - OMNINET_HEADERLEN;
dbg("%s - returns %d", __func__, room);
return room;
}
static void omninet_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
int status = urb->status;
dbg("%s - port %0x", __func__, port->number);
set_bit(0, &port->write_urbs_free);
if (status) {
dbg("%s - nonzero write bulk status received: %d",
__func__, status);
return;
}
usb_serial_port_softint(port);
}
static void omninet_disconnect(struct usb_serial *serial)
{
struct usb_serial_port *wport = serial->port[1];
dbg("%s", __func__);
usb_kill_urb(wport->write_urb);
}
static void omninet_release(struct usb_serial *serial)
{
struct usb_serial_port *port = serial->port[0];
dbg("%s", __func__);
kfree(usb_get_serial_port_data(port));
}
static int __init omninet_init(void)
{
int retval;
retval = usb_serial_register(&zyxel_omninet_device);
if (retval)
goto failed_usb_serial_register;
retval = usb_register(&omninet_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
failed_usb_register:
usb_serial_deregister(&zyxel_omninet_device);
failed_usb_serial_register:
return retval;
}
static void __exit omninet_exit(void)
{
usb_deregister(&omninet_driver);
usb_serial_deregister(&zyxel_omninet_device);
}
