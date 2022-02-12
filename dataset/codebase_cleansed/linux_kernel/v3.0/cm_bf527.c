static int __init cm_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
i2c_register_board_info(0, bfin_i2c_board_info,
ARRAY_SIZE(bfin_i2c_board_info));
platform_add_devices(cmbf527_devices, ARRAY_SIZE(cmbf527_devices));
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(cmbf527_early_devices,
ARRAY_SIZE(cmbf527_early_devices));
}
void native_machine_restart(char *cmd)
{
if ((bfin_read_SYSCR() & 0x7) == 0x3)
bfin_reset_boot_spi_cs(P_DEFAULT_BOOT_SPI_CS);
}
void bfin_get_ether_addr(char *addr)
{
random_ether_addr(addr);
printk(KERN_WARNING "%s:%s: Setting Ethernet MAC to a random one\n", __FILE__, __func__);
}
