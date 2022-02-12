static void __init omixp_init(void)
{
ixp4xx_sys_init();
omixp_flash_resources[0].start = IXP4XX_EXP_BUS_BASE(0);
omixp_flash_resources[0].end = IXP4XX_EXP_BUS_END(0);
omixp_flash_resources[1].start = IXP4XX_EXP_BUS_BASE(2);
omixp_flash_resources[1].end = IXP4XX_EXP_BUS_END(2);
if (machine_is_devixp())
platform_add_devices(devixp_pldev, ARRAY_SIZE(devixp_pldev));
else if (machine_is_miccpt())
platform_add_devices(miccpt_pldev, ARRAY_SIZE(miccpt_pldev));
else if (machine_is_mic256())
platform_add_devices(mic256_pldev, ARRAY_SIZE(mic256_pldev));
}
