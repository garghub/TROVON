static void __init kb9202_init_early(void)
{
at91rm9200_set_type(ARCH_REVISON_9200_PQFP);
at91_initialize(10000000);
}
static void __init kb9202_board_init(void)
{
at91_init_leds(AT91_PIN_PC19, AT91_PIN_PC18);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US0, 1, 0);
at91_register_uart(AT91RM9200_ID_US1, 2, 0);
at91_register_uart(AT91RM9200_ID_US3, 3, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_add_device_serial();
at91_add_device_eth(&kb9202_eth_data);
at91_add_device_usbh(&kb9202_usbh_data);
at91_add_device_udc(&kb9202_udc_data);
at91_add_device_mmc(0, &kb9202_mmc_data);
at91_add_device_i2c(NULL, 0);
at91_add_device_spi(NULL, 0);
at91_add_device_nand(&kb9202_nand_data);
}
