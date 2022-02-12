static int __init platform_devices_setup(void)
{
return platform_add_devices(devices, ARRAY_SIZE(devices));
}
