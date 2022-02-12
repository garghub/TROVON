static int __init cm_bf548_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
platform_add_devices(cm_bf548_devices, ARRAY_SIZE(cm_bf548_devices));
#if IS_ENABLED(CONFIG_SPI_BFIN5XX)
spi_register_board_info(bf54x_spi_board_info,
ARRAY_SIZE(bf54x_spi_board_info));
#endif
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(cm_bf548_early_devices,
ARRAY_SIZE(cm_bf548_early_devices));
}
