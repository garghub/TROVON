static int aircable_prepare_write_buffer(struct usb_serial_port *port,
void *dest, size_t size)
{
int count;
unsigned char *buf = dest;
count = kfifo_out_locked(&port->write_fifo, buf + HCI_HEADER_LENGTH,
size - HCI_HEADER_LENGTH, &port->lock);
buf[0] = TX_HEADER_0;
buf[1] = TX_HEADER_1;
put_unaligned_le16(count, &buf[2]);
return count + HCI_HEADER_LENGTH;
}
static int aircable_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
struct usb_host_interface *iface_desc = serial->interface->
cur_altsetting;
struct usb_endpoint_descriptor *endpoint;
int num_bulk_out = 0;
int i;
for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
endpoint = &iface_desc->endpoint[i].desc;
if (usb_endpoint_is_bulk_out(endpoint)) {
dev_dbg(&serial->dev->dev,
"found bulk out on endpoint %d\n", i);
++num_bulk_out;
}
}
if (num_bulk_out == 0) {
dev_dbg(&serial->dev->dev, "Invalid interface, discarding\n");
return -ENODEV;
}
return 0;
}
static int aircable_process_packet(struct tty_struct *tty,
struct usb_serial_port *port, int has_headers,
char *packet, int len)
{
if (has_headers) {
len -= HCI_HEADER_LENGTH;
packet += HCI_HEADER_LENGTH;
}
if (len <= 0) {
dev_dbg(&port->dev, "%s - malformed packet\n", __func__);
return 0;
}
tty_insert_flip_string(tty, packet, len);
return len;
}
static void aircable_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
char *data = (char *)urb->transfer_buffer;
struct tty_struct *tty;
int has_headers;
int count;
int len;
int i;
tty = tty_port_tty_get(&port->port);
if (!tty)
return;
has_headers = (urb->actual_length > 2 && data[0] == RX_HEADER_0);
count = 0;
for (i = 0; i < urb->actual_length; i += HCI_COMPLETE_FRAME) {
len = min_t(int, urb->actual_length - i, HCI_COMPLETE_FRAME);
count += aircable_process_packet(tty, port, has_headers,
&data[i], len);
}
if (count)
tty_flip_buffer_push(tty);
tty_kref_put(tty);
}
