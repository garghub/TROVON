static int __init moto_init(void)
{
int retval;
retval = usb_serial_register(&moto_device);
if (retval)
return retval;
retval = usb_register(&moto_driver);
if (retval)
usb_serial_deregister(&moto_device);
return retval;
}
static void __exit moto_exit(void)
{
usb_deregister(&moto_driver);
usb_serial_deregister(&moto_device);
}
