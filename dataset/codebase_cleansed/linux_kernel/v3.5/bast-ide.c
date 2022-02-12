static __init int bast_ide_init(void)
{
if (machine_is_bast() || machine_is_vr1000())
return platform_add_devices(bast_ide_devices,
ARRAY_SIZE(bast_ide_devices));
return 0;
}
