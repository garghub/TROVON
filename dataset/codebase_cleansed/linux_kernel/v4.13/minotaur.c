static int __init minotaur_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
platform_add_devices(minotaur_devices, ARRAY_SIZE(minotaur_devices));
#if IS_ENABLED(CONFIG_SPI_BFIN5XX)
spi_register_board_info(bfin_spi_board_info,
ARRAY_SIZE(bfin_spi_board_info));
#endif
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(minotaur_early_devices,
ARRAY_SIZE(minotaur_early_devices));
}
void native_machine_restart(char *cmd)
{
if ((bfin_read_SYSCR() & 0x7) == 0x3)
bfin_reset_boot_spi_cs(P_DEFAULT_BOOT_SPI_CS);
}
