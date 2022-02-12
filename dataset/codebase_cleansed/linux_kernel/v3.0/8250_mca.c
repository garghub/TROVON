static int __init mca_init(void)
{
if (!MCA_bus)
return -ENODEV;
return platform_device_register(&mca_device);
}
