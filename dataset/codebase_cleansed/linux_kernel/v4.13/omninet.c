static int omninet_calc_num_ports(struct usb_serial *serial,
struct usb_serial_endpoints *epds)
{
epds->bulk_out[0] = epds->bulk_out[1];
epds->num_bulk_out = 1;
return 1;
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
static int omninet_prepare_write_buffer(struct usb_serial_port *port,
void *buf, size_t count)
{
struct omninet_data *od = usb_get_serial_port_data(port);
struct omninet_header *header = buf;
count = min_t(size_t, count, OMNINET_PAYLOADSIZE);
count = kfifo_out_locked(&port->write_fifo, buf + OMNINET_HEADERLEN,
count, &port->lock);
header->oh_seq = od->od_outseq++;
header->oh_len = count;
header->oh_xxx = 0x03;
header->oh_pad = 0x00;
return OMNINET_BULKOUTSIZE;
}
