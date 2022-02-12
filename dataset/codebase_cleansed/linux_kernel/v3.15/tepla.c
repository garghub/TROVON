static int __init tepla_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
return platform_add_devices(tepla_devices, ARRAY_SIZE(tepla_devices));
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(tepla_early_devices,
ARRAY_SIZE(tepla_early_devices));
}
