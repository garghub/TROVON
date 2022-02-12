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
struct tty_struct *tty;
__u16 fcs;
if (!length)
return;
tty = tty_port_tty_get(&port->port);
if (!tty)
return;
if (!safe)
goto out;
fcs = fcs_compute10(data, length, CRC10_INITFCS);
if (fcs) {
dev_err(&port->dev, "%s - bad CRC %x\n", __func__, fcs);
goto err;
}
actual_length = data[length - 2] >> 2;
if (actual_length > (length - 2)) {
dev_err(&port->dev, "%s - inconsistent lengths %d:%d\n",
__func__, actual_length, length);
goto err;
}
dev_info(&urb->dev->dev, "%s - actual: %d\n", __func__, actual_length);
length = actual_length;
out:
tty_insert_flip_string(tty, data, length);
tty_flip_buffer_push(tty);
err:
tty_kref_put(tty);
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
switch (serial->interface->cur_altsetting->desc.bInterfaceProtocol) {
case LINEO_SAFESERIAL_CRC:
break;
case LINEO_SAFESERIAL_CRC_PADDED:
padded = 1;
break;
default:
return -EINVAL;
}
return 0;
}
static int __init safe_init(void)
{
int i, retval;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
if (vendor || product) {
printk(KERN_INFO KBUILD_MODNAME ": vendor: %x product: %x\n",
vendor, product);
for (i = 0; i < ARRAY_SIZE(id_table); i++) {
if (!id_table[i].idVendor && !id_table[i].idProduct) {
id_table[i].idVendor = vendor;
id_table[i].idProduct = product;
break;
}
}
}
retval = usb_serial_register(&safe_device);
if (retval)
goto failed_usb_serial_register;
retval = usb_register(&safe_driver);
if (retval)
goto failed_usb_register;
return 0;
failed_usb_register:
usb_serial_deregister(&safe_device);
failed_usb_serial_register:
return retval;
}
static void __exit safe_exit(void)
{
usb_deregister(&safe_driver);
usb_serial_deregister(&safe_device);
}
