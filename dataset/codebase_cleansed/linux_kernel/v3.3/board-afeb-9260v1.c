static void __init afeb9260_init_early(void)
{
at91_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9260_ID_US0, 1,
ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR
| ATMEL_UART_DCD | ATMEL_UART_RI);
at91_register_uart(AT91SAM9260_ID_US1, 2,
ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_set_serial_console(0);
}
static void __init afeb9260_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&afeb9260_usbh_data);
at91_add_device_udc(&afeb9260_udc_data);
at91_add_device_spi(afeb9260_spi_devices,
ARRAY_SIZE(afeb9260_spi_devices));
at91_add_device_nand(&afeb9260_nand_data);
at91_add_device_eth(&afeb9260_macb_data);
at91_set_B_periph(AT91_PIN_PA10, 0);
at91_set_B_periph(AT91_PIN_PA11, 0);
at91_add_device_mmc(0, &afeb9260_mmc_data);
at91_add_device_i2c(afeb9260_i2c_devices,
ARRAY_SIZE(afeb9260_i2c_devices));
at91_add_device_ssc(AT91SAM9260_ID_SSC, ATMEL_SSC_TX);
at91_add_device_cf(&afeb9260_cf_data);
}
