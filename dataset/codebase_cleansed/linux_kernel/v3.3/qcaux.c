static int __init qcaux_init(void)
{
int retval;
retval = usb_serial_register(&qcaux_device);
if (retval)
return retval;
retval = usb_register(&qcaux_driver);
if (retval)
usb_serial_deregister(&qcaux_device);
return retval;
}
static void __exit qcaux_exit(void)
{
usb_deregister(&qcaux_driver);
usb_serial_deregister(&qcaux_device);
}
