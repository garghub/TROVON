static int __init funsoft_init(void)
{
int retval;
retval = usb_serial_register(&funsoft_device);
if (retval)
return retval;
retval = usb_register(&funsoft_driver);
if (retval)
usb_serial_deregister(&funsoft_device);
return retval;
}
static void __exit funsoft_exit(void)
{
usb_deregister(&funsoft_driver);
usb_serial_deregister(&funsoft_device);
}
