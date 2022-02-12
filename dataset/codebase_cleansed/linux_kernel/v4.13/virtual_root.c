static void virtual_eisa_release (struct device *dev)
{
}
static int __init virtual_eisa_root_init (void)
{
int r;
if ((r = platform_device_register (&eisa_root_dev))) {
return r;
}
eisa_bus_root.force_probe = force_probe;
dev_set_drvdata(&eisa_root_dev.dev, &eisa_bus_root);
if (eisa_root_register (&eisa_bus_root)) {
platform_device_unregister (&eisa_root_dev);
return -1;
}
return 0;
}
