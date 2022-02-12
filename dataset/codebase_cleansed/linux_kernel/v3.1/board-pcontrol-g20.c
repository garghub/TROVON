static void __init pcontrol_g20_init_early(void)
{
stamp9g20_init_early();
at91_register_uart(AT91SAM9260_ID_US0, 1, ATMEL_UART_CTS
| ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US1, 2, ATMEL_UART_CTS
| ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US4, 3, 0);
}
static void __init add_device_pcontrol(void)
{
sam9_smc_configure(4, &pcontrol_smc_config[0]);
sam9_smc_configure(7, &pcontrol_smc_config[1]);
}
static void __init pcontrol_g20_board_init(void)
{
stamp9g20_board_init();
at91_add_device_usbh(&usbh_data);
at91_add_device_eth(&macb_data);
at91_add_device_i2c(pcontrol_g20_i2c_devices,
ARRAY_SIZE(pcontrol_g20_i2c_devices));
add_device_pcontrol();
at91_add_device_spi(pcontrol_g20_spi_devices,
ARRAY_SIZE(pcontrol_g20_spi_devices));
at91_add_device_udc(&pcontrol_g20_udc_data);
at91_gpio_leds(pcontrol_g20_leds,
ARRAY_SIZE(pcontrol_g20_leds));
at91_set_gpio_output(AT91_PIN_PB31, 1);
}
