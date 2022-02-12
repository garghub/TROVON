static void __init carmeva_init_early(void)
{
at91_initialize(20000000);
}
static void __init carmeva_board_init(void)
{
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US1, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_add_device_serial();
at91_add_device_eth(&carmeva_eth_data);
at91_add_device_usbh(&carmeva_usbh_data);
at91_add_device_udc(&carmeva_udc_data);
at91_add_device_i2c(NULL, 0);
at91_add_device_spi(carmeva_spi_devices, ARRAY_SIZE(carmeva_spi_devices));
at91_add_device_mci(0, &carmeva_mci0_data);
at91_gpio_leds(carmeva_leds, ARRAY_SIZE(carmeva_leds));
}
