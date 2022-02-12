static void __init eb9200_init_early(void)
{
at91_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US1, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_register_uart(AT91RM9200_ID_US2, 2, 0);
at91_set_serial_console(0);
}
static void __init eb9200_board_init(void)
{
at91_add_device_serial();
at91_add_device_eth(&eb9200_eth_data);
at91_add_device_usbh(&eb9200_usbh_data);
at91_add_device_udc(&eb9200_udc_data);
at91_add_device_i2c(eb9200_i2c_devices, ARRAY_SIZE(eb9200_i2c_devices));
at91_add_device_cf(&eb9200_cf_data);
at91_add_device_spi(NULL, 0);
at91_add_device_mmc(0, &eb9200_mmc_data);
}
