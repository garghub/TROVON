static void __init gtwx5715_init(void)
{
ixp4xx_sys_init();
gtwx5715_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
gtwx5715_flash_resource.end = IXP4XX_EXP_BUS_BASE(0) + SZ_8M - 1;
platform_add_devices(gtwx5715_devices, ARRAY_SIZE(gtwx5715_devices));
}
