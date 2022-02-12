static void __init ek_init_early(void)
{
at91_initialize(18432000);
}
static void __init ek_add_device_nand(void)
{
sam9_smc_configure(0, 3, &ek_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void __init ek_board_init(void)
{
at91_init_leds(AT91_PIN_PA9, AT91_PIN_PA6);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9260_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_register_uart(AT91SAM9260_ID_US1, 2, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_add_device_serial();
at91_add_device_usbh(&ek_usbh_data);
at91_add_device_udc(&ek_udc_data);
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
ek_add_device_nand();
at91_add_device_eth(&ek_macb_data);
at91_add_device_mmc(0, &ek_mmc_data);
at91_add_device_i2c(NULL, 0);
}
