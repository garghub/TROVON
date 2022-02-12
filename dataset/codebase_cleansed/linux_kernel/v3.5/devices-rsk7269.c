static int __init rsk7269_devices_setup(void)
{
return platform_add_devices(rsk7269_devices,
ARRAY_SIZE(rsk7269_devices));
}
