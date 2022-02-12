static int __init espt_devices_setup(void)
{
return platform_add_devices(espt_devices,
ARRAY_SIZE(espt_devices));
}
