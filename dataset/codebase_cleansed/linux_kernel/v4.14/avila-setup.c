static void __init avila_init(void)
{
ixp4xx_sys_init();
avila_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
avila_flash_resource.end =
IXP4XX_EXP_BUS_BASE(0) + ixp4xx_exp_bus_size - 1;
platform_add_devices(avila_devices, ARRAY_SIZE(avila_devices));
avila_pata_resources[0].start = IXP4XX_EXP_BUS_BASE(1);
avila_pata_resources[0].end = IXP4XX_EXP_BUS_END(1);
avila_pata_resources[1].start = IXP4XX_EXP_BUS_BASE(2);
avila_pata_resources[1].end = IXP4XX_EXP_BUS_END(2);
avila_pata_data.cs0_cfg = IXP4XX_EXP_CS1;
avila_pata_data.cs1_cfg = IXP4XX_EXP_CS2;
platform_device_register(&avila_pata);
}
