static void __init ek_init_early(void)
{
at91sam9rl_initialize(12000000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9RL_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_set_serial_console(0);
}
static void __init ek_init_irq(void)
{
at91sam9rl_init_interrupts(NULL);
}
static struct mtd_partition * __init nand_partitions(int size, int *num_partitions)
{
*num_partitions = ARRAY_SIZE(ek_nand_partition);
return ek_nand_partition;
}
static void __init ek_add_device_nand(void)
{
sam9_smc_configure(3, &ek_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void at91_lcdc_power_control(int on)
{
if (on)
at91_set_gpio_value(AT91_PIN_PC1, 0);
else
at91_set_gpio_value(AT91_PIN_PC1, 1);
}
static void __init ek_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PB1, 1);
at91_set_deglitch(AT91_PIN_PB1, 1);
at91_set_gpio_input(AT91_PIN_PB0, 1);
at91_set_deglitch(AT91_PIN_PB0, 1);
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void __init ek_board_init(void)
{
at91_add_device_serial();
at91_add_device_usba(&ek_usba_udc_data);
at91_add_device_i2c(NULL, 0);
ek_add_device_nand();
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
at91_add_device_mmc(0, &ek_mmc_data);
at91_add_device_lcdc(&ek_lcdc_data);
at91_add_device_ac97(&ek_ac97_data);
at91_add_device_tsadcc(&ek_tsadcc_data);
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
ek_add_device_buttons();
}
