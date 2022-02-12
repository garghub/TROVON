static int ipw_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_device *udev = port->serial->dev;
struct device *dev = &port->dev;
u8 buf_flow_static[16] = IPW_BYTES_FLOWINIT;
u8 *buf_flow_init;
int result;
buf_flow_init = kmemdup(buf_flow_static, 16, GFP_KERNEL);
if (!buf_flow_init)
return -ENOMEM;
dev_dbg(dev, "%s: Sending SIO_INIT (we guess)\n", __func__);
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
IPW_SIO_INIT,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
0,
0,
NULL,
0,
100000);
if (result < 0)
dev_err(dev, "Init of modem failed (error = %d)\n", result);
usb_clear_halt(udev, usb_rcvbulkpipe(udev, port->bulk_in_endpointAddress));
usb_clear_halt(udev, usb_sndbulkpipe(udev, port->bulk_out_endpointAddress));
dev_dbg(dev, "%s: setting up bulk read callback\n", __func__);
usb_wwan_open(tty, port);
dev_dbg(dev, "%s:asking modem for RxRead (RXBULK_ON)\n", __func__);
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
IPW_SIO_RXCTL,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
IPW_RXBULK_ON,
0,
NULL,
0,
100000);
if (result < 0)
dev_err(dev, "Enabling bulk RxRead failed (error = %d)\n", result);
dev_dbg(dev, "%s:setting init flowcontrol (%s)\n", __func__, buf_flow_init);
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
IPW_SIO_HANDFLOW,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
0,
0,
buf_flow_init,
0x10,
200000);
if (result < 0)
dev_err(dev, "initial flowcontrol failed (error = %d)\n", result);
kfree(buf_flow_init);
return 0;
}
static int ipw_attach(struct usb_serial *serial)
{
struct usb_wwan_intf_private *data;
data = kzalloc(sizeof(struct usb_wwan_intf_private), GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock_init(&data->susp_lock);
usb_set_serial_data(serial, data);
return 0;
}
static void ipw_release(struct usb_serial *serial)
{
struct usb_wwan_intf_private *data = usb_get_serial_data(serial);
usb_set_serial_data(serial, NULL);
kfree(data);
}
static void ipw_dtr_rts(struct usb_serial_port *port, int on)
{
struct usb_device *udev = port->serial->dev;
struct device *dev = &port->dev;
int result;
dev_dbg(dev, "%s: on = %d\n", __func__, on);
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
IPW_SIO_SET_PIN,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
on ? IPW_PIN_SETDTR : IPW_PIN_CLRDTR,
0,
NULL,
0,
200000);
if (result < 0)
dev_err(dev, "setting dtr failed (error = %d)\n", result);
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
IPW_SIO_SET_PIN, USB_TYPE_VENDOR |
USB_RECIP_INTERFACE | USB_DIR_OUT,
on ? IPW_PIN_SETRTS : IPW_PIN_CLRRTS,
0,
NULL,
0,
200000);
if (result < 0)
dev_err(dev, "setting rts failed (error = %d)\n", result);
}
static void ipw_close(struct usb_serial_port *port)
{
struct usb_device *udev = port->serial->dev;
struct device *dev = &port->dev;
int result;
dev_dbg(dev, "%s:sending purge\n", __func__);
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
IPW_SIO_PURGE, USB_TYPE_VENDOR |
USB_RECIP_INTERFACE | USB_DIR_OUT,
0x03,
0,
NULL,
0,
200000);
if (result < 0)
dev_err(dev, "purge failed (error = %d)\n", result);
result = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
IPW_SIO_RXCTL,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
IPW_RXBULK_OFF,
0,
NULL,
0,
100000);
if (result < 0)
dev_err(dev, "Disabling bulk RxRead failed (error = %d)\n", result);
usb_wwan_close(port);
}
