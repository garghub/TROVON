static int __init rsk7264_devices_setup(void)
{
return platform_add_devices(rsk7264_devices,
ARRAY_SIZE(rsk7264_devices));
}
