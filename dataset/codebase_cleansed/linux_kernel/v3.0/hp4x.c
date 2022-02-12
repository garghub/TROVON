static int __init hp49gp_init(void)
{
int retval;
retval = usb_serial_register(&hp49gp_device);
if (retval)
goto failed_usb_serial_register;
retval = usb_register(&hp49gp_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO KBUILD_MODNAME ": " DRIVER_VERSION ":"
DRIVER_DESC "\n");
return 0;
failed_usb_register:
usb_serial_deregister(&hp49gp_device);
failed_usb_serial_register:
return retval;
}
static void __exit hp49gp_exit(void)
{
usb_deregister(&hp49gp_driver);
usb_serial_deregister(&hp49gp_device);
}
