static void __init picotux200_init_early(void)
{
at91_initialize(18432000);
}
static void __init picotux200_board_init(void)
{
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US1, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_add_device_serial();
at91_add_device_eth(&picotux200_eth_data);
at91_add_device_usbh(&picotux200_usbh_data);
at91_add_device_i2c(NULL, 0);
at91_set_gpio_output(AT91_PIN_PB22, 1);
at91_add_device_mci(0, &picotux200_mci0_data);
platform_device_register(&picotux200_flash);
}
