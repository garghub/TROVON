static int ipw_open(struct tty_struct *tty, struct usb_serial_port *port)
{
struct usb_device *dev = port->serial->dev;
u8 buf_flow_static[16] = IPW_BYTES_FLOWINIT;
u8 *buf_flow_init;
int result;
dbg("%s", __func__);
buf_flow_init = kmemdup(buf_flow_static, 16, GFP_KERNEL);
if (!buf_flow_init)
return -ENOMEM;
dbg("%s: Sending SIO_INIT (we guess)", __func__);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
IPW_SIO_INIT,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
0,
0,
NULL,
0,
100000);
if (result < 0)
dev_err(&port->dev,
"Init of modem failed (error = %d)\n", result);
usb_clear_halt(dev,
usb_rcvbulkpipe(dev, port->bulk_in_endpointAddress));
usb_clear_halt(dev,
usb_sndbulkpipe(dev, port->bulk_out_endpointAddress));
dbg("%s: setting up bulk read callback", __func__);
usb_wwan_open(tty, port);
dbg("%s:asking modem for RxRead (RXBULK_ON)", __func__);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
IPW_SIO_RXCTL,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
IPW_RXBULK_ON,
0,
NULL,
0,
100000);
if (result < 0)
dev_err(&port->dev,
"Enabling bulk RxRead failed (error = %d)\n", result);
dbg("%s:setting init flowcontrol (%s)", __func__, buf_flow_init);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
IPW_SIO_HANDFLOW,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
0,
0,
buf_flow_init,
0x10,
200000);
if (result < 0)
dev_err(&port->dev,
"initial flowcontrol failed (error = %d)\n", result);
kfree(buf_flow_init);
return 0;
}
static int ipw_probe(struct usb_serial *serial, const struct usb_device_id *id)
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
usb_wwan_release(serial);
usb_set_serial_data(serial, NULL);
kfree(data);
}
static void ipw_dtr_rts(struct usb_serial_port *port, int on)
{
struct usb_device *dev = port->serial->dev;
int result;
dbg("%s: on = %d", __func__, on);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
IPW_SIO_SET_PIN,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
on ? IPW_PIN_SETDTR : IPW_PIN_CLRDTR,
0,
NULL,
0,
200000);
if (result < 0)
dev_err(&port->dev, "setting dtr failed (error = %d)\n",
result);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
IPW_SIO_SET_PIN, USB_TYPE_VENDOR |
USB_RECIP_INTERFACE | USB_DIR_OUT,
on ? IPW_PIN_SETRTS : IPW_PIN_CLRRTS,
0,
NULL,
0,
200000);
if (result < 0)
dev_err(&port->dev, "setting rts failed (error = %d)\n",
result);
}
static void ipw_close(struct usb_serial_port *port)
{
struct usb_device *dev = port->serial->dev;
int result;
dbg("%s:sending purge", __func__);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
IPW_SIO_PURGE, USB_TYPE_VENDOR |
USB_RECIP_INTERFACE | USB_DIR_OUT,
0x03,
0,
NULL,
0,
200000);
if (result < 0)
dev_err(&port->dev, "purge failed (error = %d)\n", result);
result = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
IPW_SIO_RXCTL,
USB_TYPE_VENDOR | USB_RECIP_INTERFACE | USB_DIR_OUT,
IPW_RXBULK_OFF,
0,
NULL,
0,
100000);
if (result < 0)
dev_err(&port->dev,
"Disabling bulk RxRead failed (error = %d)\n", result);
usb_wwan_close(port);
}
static int __init usb_ipw_init(void)
{
int retval;
retval = usb_serial_register(&ipw_device);
if (retval)
return retval;
retval = usb_register(&usb_ipw_driver);
if (retval) {
usb_serial_deregister(&ipw_device);
return retval;
}
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
}
static void __exit usb_ipw_exit(void)
{
usb_deregister(&usb_ipw_driver);
usb_serial_deregister(&ipw_device);
}
