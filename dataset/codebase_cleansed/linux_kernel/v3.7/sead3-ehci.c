static int __init ehci_init(void)
{
return platform_device_register(&ehci_device);
}
