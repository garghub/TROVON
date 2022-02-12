static void __init flexibity_init_early(void)
{
at91sam9260_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_set_serial_console(0);
}
static void __init flexibity_init_irq(void)
{
at91sam9260_init_interrupts(NULL);
}
static void __init flexibity_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&flexibity_usbh_data);
at91_add_device_udc(&flexibity_udc_data);
at91_add_device_spi(flexibity_spi_devices,
ARRAY_SIZE(flexibity_spi_devices));
at91_add_device_mmc(0, &flexibity_mmc_data);
at91_gpio_leds(flexibity_leds, ARRAY_SIZE(flexibity_leds));
}
