static void __init flexibity_init_early(void)
{
at91_initialize(18432000);
}
static void __init flexibity_board_init(void)
{
at91_register_uart(0, 0, 0);
at91_add_device_serial();
at91_add_device_usbh(&flexibity_usbh_data);
at91_add_device_udc(&flexibity_udc_data);
at91_add_device_i2c(flexibity_i2c_devices,
ARRAY_SIZE(flexibity_i2c_devices));
at91_add_device_spi(flexibity_spi_devices,
ARRAY_SIZE(flexibity_spi_devices));
at91_add_device_mci(0, &flexibity_mci0_data);
at91_gpio_leds(flexibity_leds, ARRAY_SIZE(flexibity_leds));
}
