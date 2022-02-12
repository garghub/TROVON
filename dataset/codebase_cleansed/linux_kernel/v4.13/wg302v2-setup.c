static void __init wg302v2_init(void)
{
ixp4xx_sys_init();
wg302v2_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
wg302v2_flash_resource.end = IXP4XX_EXP_BUS_BASE(0) + SZ_32M - 1;
*IXP4XX_EXP_CS0 |= IXP4XX_FLASH_WRITABLE;
*IXP4XX_EXP_CS1 = *IXP4XX_EXP_CS0;
platform_add_devices(wg302v2_devices, ARRAY_SIZE(wg302v2_devices));
}
