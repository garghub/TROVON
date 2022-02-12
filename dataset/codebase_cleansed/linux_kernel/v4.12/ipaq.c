static int ipaq_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
int result = 0;
int retries = connect_retries;
msleep(1000*initial_wait);
while (retries) {
retries--;
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
static int ipaq_calc_num_ports(struct usb_serial *serial,
struct usb_serial_endpoints *epds)
{
if (epds->num_bulk_in == 0 || epds->num_bulk_out == 0)
return -ENODEV;
if (epds->num_bulk_in > 1 && epds->num_bulk_out > 1) {
epds->bulk_in[0] = epds->bulk_in[1];
epds->bulk_out[0] = epds->bulk_out[1];
}
epds->num_bulk_in = 1;
epds->num_bulk_out = 1;
return 1;
}
static int ipaq_startup(struct usb_serial *serial)
{
if (serial->dev->actconfig->desc.bConfigurationValue != 1) {
dev_err(&serial->dev->dev, "active config #%d != 1 ??\n",
serial->dev->actconfig->desc.bConfigurationValue);
return -ENODEV;
}
return usb_reset_configuration(serial->dev);
}
