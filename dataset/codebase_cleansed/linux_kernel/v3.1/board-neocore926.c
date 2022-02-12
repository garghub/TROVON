static void __init neocore926_init_early(void)
{
at91_initialize(20000000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9263_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_set_serial_console(0);
}
static int ads7843_pendown_state(void)
{
return !at91_get_gpio_value(AT91_PIN_PA15);
}
static void __init neocore926_add_device_ts(void)
{
at91_set_B_periph(AT91_PIN_PA15, 1);
at91_set_gpio_input(AT91_PIN_PC13, 1);
}
static void __init neocore926_add_device_ts(void) {}
static struct mtd_partition * __init nand_partitions(int size, int *num_partitions)
{
*num_partitions = ARRAY_SIZE(neocore926_nand_partition);
return neocore926_nand_partition;
}
static void __init neocore926_add_device_nand(void)
{
sam9_smc_configure(3, &neocore926_nand_smc_config);
at91_add_device_nand(&neocore926_nand_data);
}
static void at91_lcdc_power_control(int on)
{
at91_set_gpio_value(AT91_PIN_PA30, on);
}
static void __init neocore926_add_device_buttons(void)
{
at91_set_GPIO_periph(AT91_PIN_PC5, 0);
at91_set_deglitch(AT91_PIN_PC5, 1);
at91_set_GPIO_periph(AT91_PIN_PC4, 0);
at91_set_deglitch(AT91_PIN_PC4, 1);
platform_device_register(&neocore926_button_device);
}
static void __init neocore926_add_device_buttons(void) {}
static void __init neocore926_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&neocore926_usbh_data);
at91_add_device_udc(&neocore926_udc_data);
at91_set_gpio_output(AT91_PIN_PE20, 1);
at91_add_device_spi(neocore926_spi_devices, ARRAY_SIZE(neocore926_spi_devices));
neocore926_add_device_ts();
at91_add_device_mmc(1, &neocore926_mmc_data);
at91_add_device_eth(&neocore926_macb_data);
neocore926_add_device_nand();
at91_add_device_i2c(NULL, 0);
at91_add_device_lcdc(&neocore926_lcdc_data);
neocore926_add_device_buttons();
at91_add_device_ac97(&neocore926_ac97_data);
}
