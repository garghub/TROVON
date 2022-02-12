static int __init csb701_init(void)
{
if (!machine_is_csb726())
return -ENODEV;
return platform_add_devices(devices, ARRAY_SIZE(devices));
}
