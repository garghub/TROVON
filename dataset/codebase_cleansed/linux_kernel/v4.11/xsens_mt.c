static int xsens_mt_probe(struct usb_serial *serial,\r\nconst struct usb_device_id *id)\r\n{\r\nif (serial->interface->cur_altsetting->desc.bInterfaceNumber == 1)\r\nreturn 0;\r\nreturn -ENODEV;\r\n}
