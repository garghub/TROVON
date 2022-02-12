static void __init csb337_init_early(void)
{
at91rm9200_initialize(3686400);
at91_init_leds(AT91_PIN_PB0, AT91_PIN_PB1);
at91_register_uart(0, 0, 0);
at91_set_serial_console(0);
}
static void __init csb337_init_irq(void)
{
at91rm9200_init_interrupts(NULL);
}
static void __init csb300_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PB29, 1);
at91_set_deglitch(AT91_PIN_PB29, 1);
at91_set_gpio_input(AT91_PIN_PB28, 1);
at91_set_deglitch(AT91_PIN_PB28, 1);
at91_set_gpio_input(AT91_PIN_PA21, 1);
at91_set_deglitch(AT91_PIN_PA21, 1);
platform_device_register(&csb300_button_device);
}
static void __init csb300_add_device_buttons(void) {}
static void __init csb337_board_init(void)
{
at91_add_device_serial();
at91_add_device_eth(&csb337_eth_data);
at91_add_device_usbh(&csb337_usbh_data);
at91_add_device_udc(&csb337_udc_data);
at91_add_device_i2c(csb337_i2c_devices, ARRAY_SIZE(csb337_i2c_devices));
at91_set_gpio_input(AT91_PIN_PB22, 1);
at91_add_device_cf(&csb337_cf_data);
at91_add_device_spi(csb337_spi_devices, ARRAY_SIZE(csb337_spi_devices));
at91_add_device_mmc(0, &csb337_mmc_data);
platform_device_register(&csb_flash);
at91_gpio_leds(csb_leds, ARRAY_SIZE(csb_leds));
csb300_add_device_buttons();
}
