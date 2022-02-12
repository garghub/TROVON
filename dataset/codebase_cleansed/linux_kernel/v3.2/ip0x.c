static int __init ip0x_init(void)
{
printk(KERN_INFO "%s(): registering device resources\n", __func__);
platform_add_devices(ip0x_devices, ARRAY_SIZE(ip0x_devices));
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(ip0x_early_devices,
ARRAY_SIZE(ip0x_early_devices));
}
