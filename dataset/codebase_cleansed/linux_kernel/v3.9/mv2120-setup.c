static void mv2120_power_off(void)
{
pr_info("%s: triggering power-off...\n", __func__);
gpio_set_value(MV2120_GPIO_POWER_OFF, 0);
}
static void __init mv2120_init(void)
{
orion5x_init();
orion5x_mpp_conf(mv2120_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&mv2120_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&mv2120_sata_data);
orion5x_uart0_init();
orion5x_xor_init();
orion5x_setup_dev_boot_win(MV2120_NOR_BOOT_BASE, MV2120_NOR_BOOT_SIZE);
platform_device_register(&mv2120_nor_flash);
platform_device_register(&mv2120_button_device);
if (gpio_request(MV2120_GPIO_RTC_IRQ, "rtc") == 0) {
if (gpio_direction_input(MV2120_GPIO_RTC_IRQ) == 0)
mv2120_i2c_rtc.irq = gpio_to_irq(MV2120_GPIO_RTC_IRQ);
else
gpio_free(MV2120_GPIO_RTC_IRQ);
}
i2c_register_board_info(0, &mv2120_i2c_rtc, 1);
platform_device_register(&mv2120_leds);
if (gpio_request(MV2120_GPIO_POWER_OFF, "POWEROFF") != 0 ||
gpio_direction_output(MV2120_GPIO_POWER_OFF, 1) != 0)
pr_err("mv2120: failed to setup power-off GPIO\n");
pm_power_off = mv2120_power_off;
}
