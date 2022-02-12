static int always_connected (struct usbnet *dev)
{
return 0;
}
static int __init cdc_subset_init(void)
{
return usb_register(&cdc_subset_driver);
}
static void __exit cdc_subset_exit(void)
{
usb_deregister(&cdc_subset_driver);
}
