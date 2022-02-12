static void __init yl9200_init_early(void)
{
at91rm9200_set_type(ARCH_REVISON_9200_PQFP);
at91_initialize(18432000);
at91_init_leds(AT91_PIN_PB16, AT91_PIN_PB17);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US1, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_register_uart(AT91RM9200_ID_US0, 2, 0);
at91_register_uart(AT91RM9200_ID_US3, 3, ATMEL_UART_RTS);
at91_set_serial_console(0);
}
static void __init yl9200_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PA24, 1);
at91_set_deglitch(AT91_PIN_PA24, 1);
at91_set_gpio_input(AT91_PIN_PB1, 1);
at91_set_deglitch(AT91_PIN_PB1, 1);
at91_set_gpio_input(AT91_PIN_PB2, 1);
at91_set_deglitch(AT91_PIN_PB2, 1);
at91_set_gpio_input(AT91_PIN_PB6, 1);
at91_set_deglitch(AT91_PIN_PB6, 1);
at91_set_gpio_output(AT91_PIN_PB7, 1);
platform_device_register(&yl9200_button_device);
}
static void __init yl9200_add_device_buttons(void) {}
static int ads7843_pendown_state(void)
{
return !at91_get_gpio_value(AT91_PIN_PB11);
}
static void __init yl9200_add_device_ts(void)
{
at91_set_gpio_input(AT91_PIN_PB11, 1);
at91_set_gpio_input(AT91_PIN_PB10, 1);
}
static void __init yl9200_add_device_ts(void) {}
static void yl9200_init_video(void)
{
at91_set_A_periph(AT91_PIN_PC6, 0);
at91_sys_write(AT91_SMC_CSR(2), AT91_SMC_DBW_16
| AT91_SMC_WSEN | AT91_SMC_NWS_(0x4)
| AT91_SMC_TDF_(0x100)
);
}
void __init yl9200_add_device_video(void)
{
platform_device_register(&yl9200_s1dfb_device);
}
void __init yl9200_add_device_video(void) {}
static void __init yl9200_board_init(void)
{
at91_add_device_serial();
at91_add_device_eth(&yl9200_eth_data);
at91_add_device_usbh(&yl9200_usbh_data);
at91_add_device_udc(&yl9200_udc_data);
at91_add_device_i2c(yl9200_i2c_devices, ARRAY_SIZE(yl9200_i2c_devices));
at91_add_device_mmc(0, &yl9200_mmc_data);
at91_add_device_nand(&yl9200_nand_data);
platform_device_register(&yl9200_flash);
#if defined(CONFIG_SPI_ATMEL) || defined(CONFIG_SPI_ATMEL_MODULE)
at91_add_device_spi(yl9200_spi_devices, ARRAY_SIZE(yl9200_spi_devices));
yl9200_add_device_ts();
#endif
at91_gpio_leds(yl9200_leds, ARRAY_SIZE(yl9200_leds));
yl9200_add_device_buttons();
yl9200_add_device_video();
}
