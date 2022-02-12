static int __init blackstamp_init(void)
{
int ret;
printk(KERN_INFO "%s(): registering device resources\n", __func__);
i2c_register_board_info(0, bfin_i2c_board_info,
ARRAY_SIZE(bfin_i2c_board_info));
ret = platform_add_devices(stamp_devices, ARRAY_SIZE(stamp_devices));
if (ret < 0)
return ret;
#if defined(CONFIG_SMC91X) || defined(CONFIG_SMC91X_MODULE)
ret = gpio_request(GPIO_PF0, "enet_cpld");
if (!ret) {
gpio_direction_output(GPIO_PF0, 1);
gpio_free(GPIO_PF0);
}
#endif
spi_register_board_info(bfin_spi_board_info, ARRAY_SIZE(bfin_spi_board_info));
return 0;
}
void __init native_machine_early_platform_add_devices(void)
{
printk(KERN_INFO "register early platform devices\n");
early_platform_add_devices(stamp_early_devices,
ARRAY_SIZE(stamp_early_devices));
}
