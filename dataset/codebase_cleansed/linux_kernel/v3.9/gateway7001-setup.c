static void __init gateway7001_init(void)
{
ixp4xx_sys_init();
gateway7001_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
gateway7001_flash_resource.end = IXP4XX_EXP_BUS_BASE(0) + SZ_32M - 1;
*IXP4XX_EXP_CS0 |= IXP4XX_FLASH_WRITABLE;
*IXP4XX_EXP_CS1 = *IXP4XX_EXP_CS0;
platform_add_devices(gateway7001_devices, ARRAY_SIZE(gateway7001_devices));
}
