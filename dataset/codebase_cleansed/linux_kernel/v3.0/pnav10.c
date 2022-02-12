static int __init pnav_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
platform_add_devices(stamp_devices, ARRAY_SIZE(stamp_devices));
#if defined(CONFIG_SPI_BFIN) || defined(CONFIG_SPI_BFIN_MODULE)
spi_register_board_info(bfin_spi_board_info,
ARRAY_SIZE(bfin_spi_board_info));
#endif
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(stamp_early_devices,
ARRAY_SIZE(stamp_early_devices));
}
void bfin_get_ether_addr(char *addr)
{
random_ether_addr(addr);
printk(KERN_WARNING "%s:%s: Setting Ethernet MAC to a random one\n", __FILE__, __func__);
}
