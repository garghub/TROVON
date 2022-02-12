static int __init H8606_init(void)
{
printk(KERN_INFO "HV Sistemas H8606 board support by http://www.hvsistemas.com\n");
printk(KERN_INFO "%s(): registering device resources\n", __func__);
platform_add_devices(h8606_devices, ARRAY_SIZE(h8606_devices));
#if defined(CONFIG_SPI_BFIN5XX) || defined(CONFIG_SPI_BFIN5XX_MODULE)
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
#endif
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(H8606_early_devices,
ARRAY_SIZE(H8606_early_devices));
}
