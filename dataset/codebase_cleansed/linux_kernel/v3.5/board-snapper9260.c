static void __init snapper9260_init_early(void)
{
at91_initialize(18432000);
}
static void __init snapper9260_add_device_nand(void)
{
at91_set_A_periph(AT91_PIN_PC14, 0);
sam9_smc_configure(0, 3, &snapper9260_nand_smc_config);
at91_add_device_nand(&snapper9260_nand_data);
}
static void __init snapper9260_board_init(void)
{
at91_add_device_i2c(snapper9260_i2c_devices,
ARRAY_SIZE(snapper9260_i2c_devices));
snapper9260_i2c_isl1208.irq = gpio_to_irq(AT91_PIN_PA31);
i2c_register_board_info(0, &snapper9260_i2c_isl1208, 1);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9260_ID_US0, 1,
ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US1, 2,
ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US2, 3, 0);
at91_add_device_serial();
at91_add_device_usbh(&snapper9260_usbh_data);
at91_add_device_udc(&snapper9260_udc_data);
at91_add_device_eth(&snapper9260_macb_data);
at91_add_device_ssc(AT91SAM9260_ID_SSC, (ATMEL_SSC_TF | ATMEL_SSC_TK |
ATMEL_SSC_TD | ATMEL_SSC_RD));
snapper9260_add_device_nand();
}
