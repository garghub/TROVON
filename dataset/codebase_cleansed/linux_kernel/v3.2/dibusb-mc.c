static int dibusb_mc_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
return dvb_usb_device_init(intf, &dibusb_mc_properties, THIS_MODULE,
NULL, adapter_nr);
}
static int __init dibusb_mc_module_init(void)
{
int result;
if ((result = usb_register(&dibusb_mc_driver))) {
err("usb_register failed. Error number %d",result);
return result;
}
return 0;
}
static void __exit dibusb_mc_module_exit(void)
{
usb_deregister(&dibusb_mc_driver);
}
