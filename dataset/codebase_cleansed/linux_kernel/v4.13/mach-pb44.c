static void __init pb44_init(void)
{
i2c_register_board_info(0, pb44_i2c_board_info,
ARRAY_SIZE(pb44_i2c_board_info));
platform_device_register(&pb44_i2c_gpio_device);
ath79_register_leds_gpio(-1, ARRAY_SIZE(pb44_leds_gpio),
pb44_leds_gpio);
ath79_register_gpio_keys_polled(-1, PB44_KEYS_POLL_INTERVAL,
ARRAY_SIZE(pb44_gpio_keys),
pb44_gpio_keys);
ath79_register_spi(&pb44_spi_data, pb44_spi_info,
ARRAY_SIZE(pb44_spi_info));
ath79_register_usb();
ath79_register_pci();
}
