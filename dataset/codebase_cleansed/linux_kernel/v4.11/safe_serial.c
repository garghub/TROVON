static __u16 __inline__ fcs_compute10(unsigned char *sp, int len, __u16 fcs)
{
for (; len-- > 0; fcs = CRC10_FCS(fcs, *sp++));
return fcs;
}
static void safe_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
unsigned char length = urb->actual_length;
int actual_length;
__u16 fcs;
if (!length)
return;
if (!safe)
goto out;
if (length < 2) {
dev_err(&port->dev, "malformed packet\n");
return;
}
fcs = fcs_compute10(data, length, CRC10_INITFCS);
if (fcs) {
dev_err(&port->dev, "%s - bad CRC %x\n", __func__, fcs);
return;
}
actual_length = data[length - 2] >> 2;
if (actual_length > (length - 2)) {
dev_err(&port->dev, "%s - inconsistent lengths %d:%d\n",
__func__, actual_length, length);
return;
}
dev_info(&urb->dev->dev, "%s - actual: %d\n", __func__, actual_length);
length = actual_length;
out:
tty_insert_flip_string(&port->port, data, length);
tty_flip_buffer_push(&port->port);
}
static int safe_prepare_write_buffer(struct usb_serial_port *port,
void *dest, size_t size)
{
unsigned char *buf = dest;
int count;
int trailer_len;
int pkt_len;
__u16 fcs;
trailer_len = safe ? 2 : 0;
count = kfifo_out_locked(&port->write_fifo, buf, size - trailer_len,
&port->lock);
if (!safe)
return count;
if (padded) {
pkt_len = size;
memset(buf + count, '0', pkt_len - count - trailer_len);
} else {
pkt_len = count + trailer_len;
}
buf[pkt_len - 2] = count << 2;
buf[pkt_len - 1] = 0;
fcs = fcs_compute10(buf, pkt_len, CRC10_INITFCS);
buf[pkt_len - 2] |= fcs >> 8;
buf[pkt_len - 1] |= fcs & 0xff;
return pkt_len;
}
static int safe_startup(struct usb_serial *serial)
{
struct usb_interface_descriptor *desc;
if (serial->dev->descriptor.bDeviceClass != CDC_DEVICE_CLASS)
return -ENODEV;
desc = &serial->interface->cur_altsetting->desc;
if (desc->bInterfaceClass != LINEO_INTERFACE_CLASS)
return -ENODEV;
if (desc->bInterfaceSubClass != LINEO_INTERFACE_SUBCLASS_SAFESERIAL)
return -ENODEV;
switch (desc->bInterfaceProtocol) {
case LINEO_SAFESERIAL_CRC:
break;
case LINEO_SAFESERIAL_CRC_PADDED:
padded = true;
break;
default:
return -EINVAL;
}
return 0;
}
