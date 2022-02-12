static void __init rsi_ews_init_early(void)
{
at91_initialize(18432000);
at91_init_leds(AT91_PIN_PB6, AT91_PIN_PB9);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US1, 2, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_register_uart(AT91RM9200_ID_US3, 4, ATMEL_UART_RTS);
at91_set_serial_console(0);
}
static void __init rsi_ews_board_init(void)
{
at91_add_device_serial();
at91_set_gpio_output(AT91_PIN_PA21, 0);
at91_add_device_eth(&rsi_ews_eth_data);
at91_add_device_usbh(&rsi_ews_usbh_data);
at91_add_device_i2c(rsi_ews_i2c_devices,
ARRAY_SIZE(rsi_ews_i2c_devices));
at91_add_device_spi(rsi_ews_spi_devices,
ARRAY_SIZE(rsi_ews_spi_devices));
at91_add_device_mmc(0, &rsi_ews_mmc_data);
platform_device_register(&rsiews_nor_flash);
at91_gpio_leds(rsi_ews_leds, ARRAY_SIZE(rsi_ews_leds));
}
