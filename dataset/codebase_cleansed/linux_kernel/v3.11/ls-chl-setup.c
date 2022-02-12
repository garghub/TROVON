static void lschl_power_off(void)
{
orion5x_restart(REBOOT_HARD, NULL);
}
static void __init lschl_init(void)
{
orion5x_init();
orion5x_mpp_conf(lschl_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&lschl_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&lschl_sata_data);
orion5x_uart0_init();
orion5x_xor_init();
mvebu_mbus_add_window("devbus-boot", LSCHL_NOR_BOOT_BASE,
LSCHL_NOR_BOOT_SIZE);
platform_device_register(&lschl_nor_flash);
platform_device_register(&lschl_leds);
platform_device_register(&lschl_button_device);
platform_device_register(&lschl_fan_device);
i2c_register_board_info(0, &lschl_i2c_rtc, 1);
gpio_set_value(LSCHL_GPIO_USB_POWER, 1);
pm_power_off = lschl_power_off;
pr_info("%s: finished\n", __func__);
}
