static void __init cpu9krea_init_early(void)
{
at91sam9260_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9260_ID_US0, 1, ATMEL_UART_CTS |
ATMEL_UART_RTS | ATMEL_UART_DTR | ATMEL_UART_DSR |
ATMEL_UART_DCD | ATMEL_UART_RI);
at91_register_uart(AT91SAM9260_ID_US1, 2, ATMEL_UART_CTS |
ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US2, 3, ATMEL_UART_CTS |
ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US3, 4, 0);
at91_register_uart(AT91SAM9260_ID_US4, 5, 0);
at91_register_uart(AT91SAM9260_ID_US5, 6, 0);
at91_set_serial_console(0);
}
static void __init cpu9krea_init_irq(void)
{
at91sam9260_init_interrupts(NULL);
}
static void __init cpu9krea_add_device_nand(void)
{
sam9_smc_configure(3, &cpu9krea_nand_smc_config);
at91_add_device_nand(&cpu9krea_nand_data);
}
static __init void cpu9krea_add_device_nor(void)
{
unsigned long csa;
csa = at91_sys_read(AT91_MATRIX_EBICSA);
at91_sys_write(AT91_MATRIX_EBICSA, csa | AT91_MATRIX_VDDIOMSEL_3_3V);
sam9_smc_configure(0, &cpu9krea_nor_smc_config);
platform_device_register(&cpu9krea_nor_flash);
}
static void __init cpu9krea_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PC3, 1);
at91_set_deglitch(AT91_PIN_PC3, 1);
at91_set_gpio_input(AT91_PIN_PB20, 1);
at91_set_deglitch(AT91_PIN_PB20, 1);
platform_device_register(&cpu9krea_button_device);
}
static void __init cpu9krea_add_device_buttons(void)
{
}
static void __init cpu9krea_board_init(void)
{
cpu9krea_add_device_nor();
at91_add_device_serial();
at91_add_device_usbh(&cpu9krea_usbh_data);
at91_add_device_udc(&cpu9krea_udc_data);
cpu9krea_add_device_nand();
at91_add_device_eth(&cpu9krea_macb_data);
at91_add_device_mmc(0, &cpu9krea_mmc_data);
at91_add_device_i2c(cpu9krea_i2c_devices,
ARRAY_SIZE(cpu9krea_i2c_devices));
at91_gpio_leds(cpu9krea_leds, ARRAY_SIZE(cpu9krea_leds));
cpu9krea_add_device_buttons();
}
