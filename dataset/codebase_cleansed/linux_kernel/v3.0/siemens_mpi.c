static int __init siemens_usb_mpi_init(void)
{
int retval;
retval = usb_serial_register(&siemens_usb_mpi_device);
if (retval)
goto failed_usb_serial_register;
retval = usb_register(&siemens_usb_mpi_driver);
if (retval)
goto failed_usb_register;
printk(KERN_INFO DRIVER_DESC "\n");
printk(KERN_INFO DRIVER_VERSION " " DRIVER_AUTHOR "\n");
return retval;
failed_usb_register:
usb_serial_deregister(&siemens_usb_mpi_device);
failed_usb_serial_register:
return retval;
}
static void __exit siemens_usb_mpi_exit(void)
{
usb_deregister(&siemens_usb_mpi_driver);
usb_serial_deregister(&siemens_usb_mpi_device);
}
