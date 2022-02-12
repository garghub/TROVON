static void __init kafa_init_early(void)
{
at91rm9200_set_type(ARCH_REVISON_9200_PQFP);
at91_initialize(18432000);
}
static void __init kafa_board_init(void)
{
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_add_device_serial();
at91_add_device_eth(&kafa_eth_data);
at91_add_device_usbh(&kafa_usbh_data);
at91_add_device_udc(&kafa_udc_data);
at91_add_device_i2c(NULL, 0);
at91_add_device_spi(NULL, 0);
at91_gpio_leds(kafa_leds, ARRAY_SIZE(kafa_leds));
}
