static int __init vivopay_serial_init(void)
{
int retval;
retval = usb_serial_register(&vivopay_serial_device);
if (retval)
goto failed_usb_serial_register;
retval = usb_register(&vivopay_serial_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
failed_usb_register:
usb_serial_deregister(&vivopay_serial_device);
failed_usb_serial_register:
return retval;
}
static void __exit vivopay_serial_exit(void)
{
usb_deregister(&vivopay_serial_driver);
usb_serial_deregister(&vivopay_serial_device);
}
