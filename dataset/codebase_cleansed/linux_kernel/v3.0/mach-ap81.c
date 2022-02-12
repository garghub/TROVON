static void __init ap81_setup(void)
{
u8 *cal_data = (u8 *) KSEG1ADDR(AP81_CAL_DATA_ADDR);
ath79_register_leds_gpio(-1, ARRAY_SIZE(ap81_leds_gpio),
ap81_leds_gpio);
ath79_register_gpio_keys_polled(-1, AP81_KEYS_POLL_INTERVAL,
ARRAY_SIZE(ap81_gpio_keys),
ap81_gpio_keys);
ath79_register_spi(&ap81_spi_data, ap81_spi_info,
ARRAY_SIZE(ap81_spi_info));
ath79_register_ar913x_wmac(cal_data);
}
