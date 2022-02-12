static int usb_gsi_openclose(struct usb_serial_port *port, int value)
{
struct usb_device *dev = port->serial->dev;
return usb_control_msg(
dev,
usb_sndctrlpipe(dev, 0),
GSI_VENDOR_OPENCLOSE,
USB_DIR_OUT|USB_TYPE_VENDOR|USB_RECIP_INTERFACE,
value,
port->serial->interface->cur_altsetting->desc.bInterfaceNumber,
NULL, 0,
5000);
}
static int wishbone_serial_open(struct tty_struct *tty,
struct usb_serial_port *port)
{
int retval;
retval = usb_gsi_openclose(port, 1);
if (retval) {
dev_err(&port->serial->dev->dev,
"Could not mark device as open (%d)\n",
retval);
return retval;
}
retval = usb_serial_generic_open(tty, port);
if (retval)
usb_gsi_openclose(port, 0);
return retval;
}
static void wishbone_serial_close(struct usb_serial_port *port)
{
usb_serial_generic_close(port);
usb_gsi_openclose(port, 0);
}
