static void __init onearm_init_early(void)
{
at91rm9200_set_type(ARCH_REVISON_9200_PQFP);
at91_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_register_uart(AT91RM9200_ID_US1, 2, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_set_serial_console(0);
}
static void __init onearm_board_init(void)
{
at91_add_device_serial();
at91_add_device_eth(&onearm_eth_data);
at91_add_device_usbh(&onearm_usbh_data);
at91_add_device_udc(&onearm_udc_data);
}
