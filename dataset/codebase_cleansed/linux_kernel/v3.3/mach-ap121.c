static void __init ap121_setup(void)
{
u8 *cal_data = (u8 *) KSEG1ADDR(AP121_CAL_DATA_ADDR);
ath79_register_leds_gpio(-1, ARRAY_SIZE(ap121_leds_gpio),
ap121_leds_gpio);
ath79_register_gpio_keys_polled(-1, AP121_KEYS_POLL_INTERVAL,
ARRAY_SIZE(ap121_gpio_keys),
ap121_gpio_keys);
ath79_register_spi(&ap121_spi_data, ap121_spi_info,
ARRAY_SIZE(ap121_spi_info));
ath79_register_usb();
ath79_register_wmac(cal_data);
}
