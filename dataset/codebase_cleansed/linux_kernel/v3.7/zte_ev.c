static void debug_data(struct device *dev, const char *function, int len,
const unsigned char *data, int result)
{
dev_dbg(dev, "result = %d\n", result);
if (result == len)
dev_dbg(dev, "%s - length = %d, data = %*ph\n", function,
len, len, data);
}
static int zte_ev_usb_serial_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
struct usb_device *udev = port->serial->dev;
struct device *dev = &port->dev;
int result = 0;
int len;
unsigned char *buf;
if (port->number != 0)
return -ENODEV;
buf = kmalloc(MAX_SETUP_DATA_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
len = 0;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x22, 0x21,
0x0001, 0x0000, NULL, len,
HZ * USB_CTRL_GET_TIMEOUT);
dev_dbg(dev, "result = %d\n", result);
len = 0x0007;
result = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
0x21, 0xa1,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
len = 0x0007;
buf[0] = 0x80;
buf[1] = 0x25;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x00;
buf[5] = 0x00;
buf[6] = 0x08;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x20, 0x21,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
len = 0;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x22, 0x21,
0x0003, 0x0000, NULL, len,
HZ * USB_CTRL_GET_TIMEOUT);
dev_dbg(dev, "result = %d\n", result);
len = 0x0007;
result = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
0x21, 0xa1,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
len = 0x0007;
buf[0] = 0x80;
buf[1] = 0x25;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x00;
buf[5] = 0x00;
buf[6] = 0x08;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x20, 0x21,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
kfree(buf);
return usb_serial_generic_open(tty, port);
}
static void zte_ev_usb_serial_close(struct usb_serial_port *port)
{
struct usb_device *udev = port->serial->dev;
struct device *dev = &port->dev;
int result = 0;
int len;
unsigned char *buf;
if (port->number != 0)
return;
buf = kmalloc(MAX_SETUP_DATA_SIZE, GFP_KERNEL);
if (!buf)
return;
len = 0;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x22, 0x21,
0x0002, 0x0000, NULL, len,
HZ * USB_CTRL_GET_TIMEOUT);
dev_dbg(dev, "result = %d\n", result);
len = 0;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x22, 0x21,
0x0003, 0x0000, NULL, len,
HZ * USB_CTRL_GET_TIMEOUT);
dev_dbg(dev, "result = %d\n", result);
len = 0x0007;
result = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
0x21, 0xa1,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
len = 0x0007;
buf[0] = 0x00;
buf[1] = 0xc2;
buf[2] = 0x01;
buf[3] = 0x00;
buf[4] = 0x00;
buf[5] = 0x00;
buf[6] = 0x08;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x20, 0x21,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
len = 0;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x22, 0x21,
0x0003, 0x0000, NULL, len,
HZ * USB_CTRL_GET_TIMEOUT);
dev_dbg(dev, "result = %d\n", result);
len = 0x0007;
result = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
0x21, 0xa1,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
len = 0x0007;
buf[0] = 0x00;
buf[1] = 0xc2;
buf[2] = 0x01;
buf[3] = 0x00;
buf[4] = 0x00;
buf[5] = 0x00;
buf[6] = 0x08;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x20, 0x21,
0x0000, 0x0000, buf, len,
HZ * USB_CTRL_GET_TIMEOUT);
debug_data(dev, __func__, len, buf, result);
len = 0;
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
0x22, 0x21,
0x0003, 0x0000, NULL, len,
HZ * USB_CTRL_GET_TIMEOUT);
dev_dbg(dev, "result = %d\n", result);
kfree(buf);
usb_serial_generic_close(port);
}
