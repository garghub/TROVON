static int dibusb_mc_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf, &dibusb_mc_properties, THIS_MODULE,
NULL, adapter_nr);
}
