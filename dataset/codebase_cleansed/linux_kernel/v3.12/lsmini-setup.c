static void lsmini_power_off(void)
{
orion5x_restart(REBOOT_HARD, NULL);
}
static void __init lsmini_init(void)
{
orion5x_init();
orion5x_mpp_conf(lsmini_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&lsmini_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&lsmini_sata_data);
orion5x_uart0_init();
orion5x_xor_init();
mvebu_mbus_add_window_by_id(ORION_MBUS_DEVBUS_BOOT_TARGET,
ORION_MBUS_DEVBUS_BOOT_ATTR,
LSMINI_NOR_BOOT_BASE,
LSMINI_NOR_BOOT_SIZE);
platform_device_register(&lsmini_nor_flash);
platform_device_register(&lsmini_button_device);
platform_device_register(&lsmini_leds);
i2c_register_board_info(0, &lsmini_i2c_rtc, 1);
gpio_set_value(LSMINI_GPIO_USB_POWER, 1);
pm_power_off = lsmini_power_off;
pr_info("%s: finished\n", __func__);
}
