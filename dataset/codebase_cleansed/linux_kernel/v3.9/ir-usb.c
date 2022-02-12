static inline void irda_usb_dump_class_desc(struct usb_serial *serial,
struct usb_irda_cs_descriptor *desc)
{
struct device *dev = &serial->dev->dev;
dev_dbg(dev, "bLength=%x\n", desc->bLength);
dev_dbg(dev, "bDescriptorType=%x\n", desc->bDescriptorType);
dev_dbg(dev, "bcdSpecRevision=%x\n", __le16_to_cpu(desc->bcdSpecRevision));
dev_dbg(dev, "bmDataSize=%x\n", desc->bmDataSize);
dev_dbg(dev, "bmWindowSize=%x\n", desc->bmWindowSize);
dev_dbg(dev, "bmMinTurnaroundTime=%d\n", desc->bmMinTurnaroundTime);
dev_dbg(dev, "wBaudRate=%x\n", __le16_to_cpu(desc->wBaudRate));
dev_dbg(dev, "bmAdditionalBOFs=%x\n", desc->bmAdditionalBOFs);
dev_dbg(dev, "bIrdaRateSniff=%x\n", desc->bIrdaRateSniff);
dev_dbg(dev, "bMaxUnicastList=%x\n", desc->bMaxUnicastList);
}
static struct usb_irda_cs_descriptor *
irda_usb_find_class_desc(struct usb_serial *serial, unsigned int ifnum)
{
struct usb_device *dev = serial->dev;
struct usb_irda_cs_descriptor *desc;
int ret;
desc = kzalloc(sizeof(*desc), GFP_KERNEL);
if (!desc)
return NULL;
ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),
USB_REQ_CS_IRDA_GET_CLASS_DESC,
USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, ifnum, desc, sizeof(*desc), 1000);
dev_dbg(&serial->dev->dev, "%s - ret=%d\n", __func__, ret);
if (ret < sizeof(*desc)) {
dev_dbg(&serial->dev->dev,
"%s - class descriptor read %s (%d)\n", __func__,
(ret < 0) ? "failed" : "too short", ret);
goto error;
}
if (desc->bDescriptorType != USB_DT_CS_IRDA) {
dev_dbg(&serial->dev->dev, "%s - bad class descriptor type\n",
__func__);
goto error;
}
irda_usb_dump_class_desc(serial, desc);
return desc;
error:
kfree(desc);
return NULL;
}
static u8 ir_xbof_change(u8 xbof)
{
u8 result;
switch (xbof) {
case 48:
result = 0x10;
break;
case 28:
case 24:
result = 0x20;
break;
default:
case 12:
result = 0x30;
break;
case 5:
case 6:
result = 0x40;
break;
case 3:
result = 0x50;
break;
case 2:
result = 0x60;
break;
case 1:
result = 0x70;
break;
case 0:
result = 0x80;
break;
}
return(result);
}
static int ir_startup(struct usb_serial *serial)
{
struct usb_irda_cs_descriptor *irda_desc;
irda_desc = irda_usb_find_class_desc(serial, 0);
if (!irda_desc) {
dev_err(&serial->dev->dev,
"IRDA class descriptor not found, device not bound\n");
return -ENODEV;
}
dev_dbg(&serial->dev->dev,
"%s - Baud rates supported:%s%s%s%s%s%s%s%s%s\n",
__func__,
(irda_desc->wBaudRate & USB_IRDA_BR_2400) ? " 2400" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_9600) ? " 9600" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_19200) ? " 19200" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_38400) ? " 38400" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_57600) ? " 57600" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_115200) ? " 115200" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_576000) ? " 576000" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_1152000) ? " 1152000" : "",
(irda_desc->wBaudRate & USB_IRDA_BR_4000000) ? " 4000000" : "");
switch (irda_desc->bmAdditionalBOFs) {
case USB_IRDA_AB_48:
ir_add_bof = 48;
break;
case USB_IRDA_AB_24:
ir_add_bof = 24;
break;
case USB_IRDA_AB_12:
ir_add_bof = 12;
break;
case USB_IRDA_AB_6:
ir_add_bof = 6;
break;
case USB_IRDA_AB_3:
ir_add_bof = 3;
break;
case USB_IRDA_AB_2:
ir_add_bof = 2;
break;
case USB_IRDA_AB_1:
ir_add_bof = 1;
break;
case USB_IRDA_AB_0:
ir_add_bof = 0;
break;
default:
break;
}
kfree(irda_desc);
return 0;
}
static int ir_open(struct tty_struct *tty, struct usb_serial_port *port)
{
int i;
for (i = 0; i < ARRAY_SIZE(port->write_urbs); ++i)
port->write_urbs[i]->transfer_flags = URB_ZERO_PACKET;
return usb_serial_generic_open(tty, port);
}
static int ir_prepare_write_buffer(struct usb_serial_port *port,
void *dest, size_t size)
{
unsigned char *buf = dest;
int count;
*buf = ir_xbof | ir_baud;
count = kfifo_out_locked(&port->write_fifo, buf + 1, size - 1,
&port->lock);
return count + 1;
}
static void ir_process_read_urb(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
unsigned char *data = urb->transfer_buffer;
if (!urb->actual_length)
return;
if (*data & 0x0f)
ir_baud = *data & 0x0f;
if (urb->actual_length == 1)
return;
tty_insert_flip_string(&port->port, data + 1, urb->actual_length - 1);
tty_flip_buffer_push(&port->port);
}
static void ir_set_termios_callback(struct urb *urb)
{
kfree(urb->transfer_buffer);
if (urb->status)
dev_dbg(&urb->dev->dev, "%s - non-zero urb status: %d\n",
__func__, urb->status);
}
static void ir_set_termios(struct tty_struct *tty,
struct usb_serial_port *port, struct ktermios *old_termios)
{
struct urb *urb;
unsigned char *transfer_buffer;
int result;
speed_t baud;
int ir_baud;
baud = tty_get_baud_rate(tty);
switch (baud) {
case 2400:
ir_baud = USB_IRDA_BR_2400;
break;
case 9600:
ir_baud = USB_IRDA_BR_9600;
break;
case 19200:
ir_baud = USB_IRDA_BR_19200;
break;
case 38400:
ir_baud = USB_IRDA_BR_38400;
break;
case 57600:
ir_baud = USB_IRDA_BR_57600;
break;
case 115200:
ir_baud = USB_IRDA_BR_115200;
break;
case 576000:
ir_baud = USB_IRDA_BR_576000;
break;
case 1152000:
ir_baud = USB_IRDA_BR_1152000;
break;
case 4000000:
ir_baud = USB_IRDA_BR_4000000;
break;
default:
ir_baud = USB_IRDA_BR_9600;
baud = 9600;
}
if (xbof == -1)
ir_xbof = ir_xbof_change(ir_add_bof);
else
ir_xbof = ir_xbof_change(xbof) ;
tty_termios_copy_hw(&tty->termios, old_termios);
tty_encode_baud_rate(tty, baud, baud);
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
dev_err(&port->dev, "%s - no more urbs\n", __func__);
return;
}
transfer_buffer = kmalloc(1, GFP_KERNEL);
if (!transfer_buffer) {
dev_err(&port->dev, "%s - out of memory\n", __func__);
goto err_buf;
}
*transfer_buffer = ir_xbof | ir_baud;
usb_fill_bulk_urb(
urb,
port->serial->dev,
usb_sndbulkpipe(port->serial->dev,
port->bulk_out_endpointAddress),
transfer_buffer,
1,
ir_set_termios_callback,
port);
urb->transfer_flags = URB_ZERO_PACKET;
result = usb_submit_urb(urb, GFP_KERNEL);
if (result) {
dev_err(&port->dev, "%s - failed to submit urb: %d\n",
__func__, result);
goto err_subm;
}
usb_free_urb(urb);
return;
err_subm:
kfree(transfer_buffer);
err_buf:
usb_free_urb(urb);
}
static int __init ir_init(void)
{
if (buffer_size) {
ir_device.bulk_in_size = buffer_size;
ir_device.bulk_out_size = buffer_size;
}
return usb_serial_register_drivers(serial_drivers, KBUILD_MODNAME, ir_id_table);
}
static void __exit ir_exit(void)
{
usb_serial_deregister_drivers(serial_drivers);
}
