static int omninet_attach(struct usb_serial *serial)
{
if (serial->num_bulk_out < 2) {
dev_err(&serial->interface->dev, "missing endpoints\n");
return -ENODEV;
}
return 0;
}
static int omninet_port_probe(struct usb_serial_port *port)
{
struct omninet_data *od;
od = kzalloc(sizeof(*od), GFP_KERNEL);
if (!od)
return -ENOMEM;
usb_set_serial_port_data(port, od);
return 0;
}
static int omninet_port_remove(struct usb_serial_port *port)
{
struct omninet_data *od;
od = usb_get_serial_port_data(port);
kfree(od);
return 0;
}
static int omninet_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct usb_serial_port *wport;
wport = serial->port[1];
tty_port_tty_set(&wport->port, tty);
return usb_serial_generic_open(tty, port);
}
static void omninet_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
const struct omninet_header *hdr = urb->transfer_buffer;
const unsigned char *data;
size_t data_len;
if (urb->actual_length <= OMNINET_HEADERLEN || !hdr->oh_len)
return;
data = (char *)urb->transfer_buffer + OMNINET_HEADERLEN;
data_len = min_t(size_t, urb->actual_length - OMNINET_HEADERLEN,
hdr->oh_len);
tty_insert_flip_string(&port->port, data, data_len);
tty_flip_buffer_push(&port->port);
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
if (count == 0) {
dev_dbg(&port->dev, "%s - write request of 0 bytes\n", __func__);
return 0;
}
if (!test_and_clear_bit(0, &port->write_urbs_free)) {
dev_dbg(&port->dev, "%s - already writing\n", __func__);
return 0;
}
count = (count > OMNINET_PAYLOADSIZE) ? OMNINET_PAYLOADSIZE : count;
memcpy(wport->write_urb->transfer_buffer + OMNINET_HEADERLEN,
buf, count);
usb_serial_debug_data(&port->dev, __func__, count,
wport->write_urb->transfer_buffer);
header->oh_seq = od->od_outseq++;
header->oh_len = count;
header->oh_xxx = 0x03;
header->oh_pad = 0x00;
wport->write_urb->transfer_buffer_length = OMNINET_BULKOUTSIZE;
result = usb_submit_urb(wport->write_urb, GFP_ATOMIC);
if (result) {
set_bit(0, &wport->write_urbs_free);
dev_err_console(port,
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
dev_dbg(&port->dev, "%s - returns %d\n", __func__, room);
return room;
}
static void omninet_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
int status = urb->status;
set_bit(0, &port->write_urbs_free);
if (status) {
dev_dbg(&port->dev, "%s - nonzero write bulk status received: %d\n",
__func__, status);
return;
}
usb_serial_port_softint(port);
}
static void omninet_disconnect(struct usb_serial *serial)
{
struct usb_serial_port *wport = serial->port[1];
usb_kill_urb(wport->write_urb);
}
