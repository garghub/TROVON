static void __init ek_init_early(void)
{
at91rm9200_initialize(18432000);
at91_init_leds(AT91_PIN_PB1, AT91_PIN_PB2);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US1, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_set_serial_console(0);
}
static void __init ek_init_irq(void)
{
at91rm9200_init_interrupts(NULL);
}
static void __init ek_board_init(void)
{
at91_add_device_serial();
at91_add_device_eth(&ek_eth_data);
at91_add_device_usbh(&ek_usbh_data);
at91_add_device_udc(&ek_udc_data);
at91_set_multi_drive(ek_udc_data.pullup_pin, 1);
at91_add_device_i2c(ek_i2c_devices, ARRAY_SIZE(ek_i2c_devices));
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
#ifdef CONFIG_MTD_AT91_DATAFLASH_CARD
at91_set_gpio_output(AT91_PIN_PB22, 0);
#else
at91_set_gpio_output(AT91_PIN_PB22, 1);
at91_add_device_mmc(0, &ek_mmc_data);
#endif
platform_device_register(&ek_flash);
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
}
