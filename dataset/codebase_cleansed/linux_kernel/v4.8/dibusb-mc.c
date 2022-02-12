static int dibusb_mc_probe(struct usb_interface *intf,\r\nconst struct usb_device_id *id)\r\n{\r\nreturn dvb_usb_device_init(intf, &dibusb_mc_properties, THIS_MODULE,\r\nNULL, adapter_nr);\r\n}
