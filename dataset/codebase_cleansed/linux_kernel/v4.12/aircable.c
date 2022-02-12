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
static int aircable_calc_num_ports(struct usb_serial *serial,
struct usb_serial_endpoints *epds)
{
if (epds->num_bulk_out == 0) {
dev_dbg(&serial->interface->dev,
"ignoring interface with no bulk-out endpoints\n");
return -ENODEV;
}
return 1;
}
static int aircable_process_packet(struct usb_serial_port *port,
int has_headers, char *packet, int len)
{
if (has_headers) {
len -= HCI_HEADER_LENGTH;
packet += HCI_HEADER_LENGTH;
}
if (len <= 0) {
dev_dbg(&port->dev, "%s - malformed packet\n", __func__);
return 0;
}
tty_insert_flip_string(&port->port, packet, len);
return len;
}
static void aircable_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
char *data = (char *)urb->transfer_buffer;
int has_headers;
int count;
int len;
int i;
has_headers = (urb->actual_length > 2 && data[0] == RX_HEADER_0);
count = 0;
for (i = 0; i < urb->actual_length; i += HCI_COMPLETE_FRAME) {
len = min_t(int, urb->actual_length - i, HCI_COMPLETE_FRAME);
count += aircable_process_packet(port, has_headers,
&data[i], len);
}
if (count)
tty_flip_buffer_push(&port->port);
}
