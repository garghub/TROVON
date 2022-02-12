static void __init foxg20_init_early(void)
{
at91sam9260_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9260_ID_US0, 1,
ATMEL_UART_CTS
| ATMEL_UART_RTS
| ATMEL_UART_DTR
| ATMEL_UART_DSR
| ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_register_uart(AT91SAM9260_ID_US1, 2,
ATMEL_UART_CTS
| ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US2, 3, 0);
at91_register_uart(AT91SAM9260_ID_US3, 4,
ATMEL_UART_CTS
| ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US4, 5, 0);
at91_register_uart(AT91SAM9260_ID_US5, 6, 0);
at91_set_serial_console(0);
at91_set_A_periph(AT91_PIN_PB14, 1);
}
static void __init foxg20_init_irq(void)
{
at91sam9260_init_interrupts(NULL);
}
static void __init foxg20_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PC4, 1);
at91_set_deglitch(AT91_PIN_PC4, 1);
platform_device_register(&foxg20_button_device);
}
static void __init foxg20_add_device_buttons(void) {}
static void __init at91_add_device_w1(void)
{
at91_set_GPIO_periph(w1_gpio_pdata.pin, 1);
at91_set_multi_drive(w1_gpio_pdata.pin, 1);
platform_device_register(&w1_device);
}
static void __init foxg20_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&foxg20_usbh_data);
at91_add_device_udc(&foxg20_udc_data);
at91_add_device_spi(foxg20_spi_devices, ARRAY_SIZE(foxg20_spi_devices));
at91_add_device_eth(&foxg20_macb_data);
at91_add_device_mmc(0, &foxg20_mmc_data);
at91_add_device_i2c(foxg20_i2c_devices, ARRAY_SIZE(foxg20_i2c_devices));
at91_gpio_leds(foxg20_leds, ARRAY_SIZE(foxg20_leds));
foxg20_add_device_buttons();
#if defined(CONFIG_W1_MASTER_GPIO) || defined(CONFIG_W1_MASTER_GPIO_MODULE)
at91_add_device_w1();
#endif
}
