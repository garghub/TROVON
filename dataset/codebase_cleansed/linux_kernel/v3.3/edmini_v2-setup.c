static void __init edmini_v2_init(void)
{
orion5x_init();
orion5x_mpp_conf(edminiv2_mpp_modes);
orion5x_ehci0_init();
orion5x_eth_init(&edmini_v2_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&edmini_v2_sata_data);
orion5x_uart0_init();
orion5x_setup_dev_boot_win(EDMINI_V2_NOR_BOOT_BASE,
EDMINI_V2_NOR_BOOT_SIZE);
platform_device_register(&edmini_v2_nor_flash);
platform_device_register(&edmini_v2_gpio_leds);
platform_device_register(&edmini_v2_gpio_buttons);
pr_notice("edmini_v2: USB device port, flash write and power-off "
"are not yet supported.\n");
if (gpio_request(EDMINIV2_RTC_GPIO, "rtc") == 0) {
if (gpio_direction_input(EDMINIV2_RTC_GPIO) == 0)
edmini_v2_i2c_rtc.irq = gpio_to_irq(EDMINIV2_RTC_GPIO);
else
gpio_free(EDMINIV2_RTC_GPIO);
}
if (edmini_v2_i2c_rtc.irq == 0)
pr_warning("edmini_v2: failed to get RTC IRQ\n");
i2c_register_board_info(0, &edmini_v2_i2c_rtc, 1);
}
