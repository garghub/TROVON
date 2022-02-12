static int __init sh5_devices_setup(void)
{
int ret;
ret = platform_add_devices(sh5_early_devices,
ARRAY_SIZE(sh5_early_devices));
if (unlikely(ret != 0))
return ret;
return platform_add_devices(sh5_devices,
ARRAY_SIZE(sh5_devices));
}
void __init plat_early_device_setup(void)
{
early_platform_add_devices(sh5_early_devices,
ARRAY_SIZE(sh5_early_devices));
}
