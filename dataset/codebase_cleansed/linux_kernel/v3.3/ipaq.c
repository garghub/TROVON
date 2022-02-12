static int ipaq_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
int result = 0;
int retries = connect_retries;
dbg("%s - port %d", __func__, port->number);
msleep(1000*initial_wait);
while (retries--) {
result = usb_control_msg(serial->dev,
usb_sndctrlpipe(serial->dev, 0), 0x22, 0x21,
0x1, 0, NULL, 0, 100);
if (!result)
break;
msleep(1000);
}
if (!retries && result) {
dev_err(&port->dev, "%s - failed doing control urb, error %d\n",
__func__, result);
return result;
}
return usb_serial_generic_open(tty, port);
}
static int ipaq_calc_num_ports(struct usb_serial *serial)
{
int ipaq_num_ports = 1;
dbg("%s - numberofendpoints: %d", __FUNCTION__,
(int)serial->interface->cur_altsetting->desc.bNumEndpoints);
if (serial->interface->cur_altsetting->desc.bNumEndpoints > 3) {
ipaq_num_ports = 2;
}
return ipaq_num_ports;
}
static int ipaq_startup(struct usb_serial *serial)
{
dbg("%s", __func__);
if (serial->num_bulk_in < serial->num_ports ||
serial->num_bulk_out < serial->num_ports)
return -ENODEV;
if (serial->dev->actconfig->desc.bConfigurationValue != 1) {
dev_err(&serial->dev->dev, "active config #%d != 1 ??\n",
serial->dev->actconfig->desc.bConfigurationValue);
return -ENODEV;
}
dbg("%s - iPAQ module configured for %d ports",
__FUNCTION__, serial->num_ports);
return usb_reset_configuration(serial->dev);
}
static int __init ipaq_init(void)
{
int retval;
retval = usb_serial_register(&ipaq_device);
if (retval)
goto failed_usb_serial_register;
if (vendor) {
ipaq_id_table[0].idVendor = vendor;
ipaq_id_table[0].idProduct = product;
}
retval = usb_register(&ipaq_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
failed_usb_register:
usb_serial_deregister(&ipaq_device);
failed_usb_serial_register:
return retval;
}
static void __exit ipaq_exit(void)
{
usb_deregister(&ipaq_driver);
usb_serial_deregister(&ipaq_device);
}
