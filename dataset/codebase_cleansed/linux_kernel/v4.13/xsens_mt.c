static int xsens_mt_probe(struct usb_serial *serial,
const struct usb_device_id *id)
{
if (serial->interface->cur_altsetting->desc.bInterfaceNumber == 1)
return 0;
return -ENODEV;
}
