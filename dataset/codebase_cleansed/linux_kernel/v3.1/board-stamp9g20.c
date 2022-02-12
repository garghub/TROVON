void __init stamp9g20_init_early(void)
{
at91_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_set_serial_console(0);
}
static void __init stamp9g20evb_init_early(void)
{
stamp9g20_init_early();
at91_register_uart(AT91SAM9260_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR
| ATMEL_UART_DCD | ATMEL_UART_RI);
}
static void __init portuxg20_init_early(void)
{
stamp9g20_init_early();
at91_register_uart(AT91SAM9260_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR
| ATMEL_UART_DCD | ATMEL_UART_RI);
at91_register_uart(AT91SAM9260_ID_US1, 2, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US2, 3, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US4, 5, 0);
at91_register_uart(AT91SAM9260_ID_US5, 6, 0);
}
static void __init add_device_nand(void)
{
sam9_smc_configure(3, &nand_smc_config);
at91_add_device_nand(&nand_data);
}
void add_w1(void)
{
at91_set_GPIO_periph(w1_gpio_pdata.pin, 1);
at91_set_multi_drive(w1_gpio_pdata.pin, 1);
platform_device_register(&w1_device);
}
void __init stamp9g20_board_init(void)
{
at91_add_device_serial();
add_device_nand();
#if defined(CONFIG_MMC_ATMELMCI) || defined(CONFIG_MMC_ATMELMCI_MODULE)
at91_add_device_mci(0, &mmc_data);
#else
at91_add_device_mmc(0, &mmc_data);
#endif
add_w1();
}
static void __init portuxg20_board_init(void)
{
stamp9g20_board_init();
at91_add_device_usbh(&usbh_data);
at91_add_device_udc(&portuxg20_udc_data);
at91_add_device_eth(&macb_data);
at91_add_device_i2c(NULL, 0);
at91_add_device_spi(portuxg20_spi_devices, ARRAY_SIZE(portuxg20_spi_devices));
at91_gpio_leds(portuxg20_leds, ARRAY_SIZE(portuxg20_leds));
}
static void __init stamp9g20evb_board_init(void)
{
stamp9g20_board_init();
at91_add_device_usbh(&usbh_data);
at91_add_device_udc(&stamp9g20evb_udc_data);
at91_add_device_eth(&macb_data);
at91_add_device_i2c(NULL, 0);
at91_gpio_leds(stamp9g20evb_leds, ARRAY_SIZE(stamp9g20evb_leds));
}
