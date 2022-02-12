static void __init cpuat91_init_early(void)
{
at91rm9200_set_type(ARCH_REVISON_9200_PQFP);
at91_initialize(18432000);
}
static void __init cpuat91_board_init(void)
{
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US0, 1, ATMEL_UART_CTS |
ATMEL_UART_RTS);
at91_register_uart(AT91RM9200_ID_US1, 2, ATMEL_UART_CTS |
ATMEL_UART_RTS | ATMEL_UART_DTR | ATMEL_UART_DSR |
ATMEL_UART_DCD | ATMEL_UART_RI);
at91_register_uart(AT91RM9200_ID_US2, 3, 0);
at91_register_uart(AT91RM9200_ID_US3, 4, ATMEL_UART_CTS |
ATMEL_UART_RTS);
at91_add_device_serial();
at91_gpio_leds(cpuat91_leds, ARRAY_SIZE(cpuat91_leds));
at91_add_device_eth(&cpuat91_eth_data);
at91_add_device_usbh(&cpuat91_usbh_data);
at91_add_device_udc(&cpuat91_udc_data);
at91_add_device_mmc(0, &cpuat91_mmc_data);
at91_add_device_i2c(NULL, 0);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
}
