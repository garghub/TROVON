static int __init zio_init(void)
{
int retval;
retval = usb_serial_register(&zio_device);
if (retval)
return retval;
retval = usb_register(&zio_driver);
if (retval)
usb_serial_deregister(&zio_device);
return retval;
}
static void __exit zio_exit(void)
{
usb_deregister(&zio_driver);
usb_serial_deregister(&zio_device);
}
