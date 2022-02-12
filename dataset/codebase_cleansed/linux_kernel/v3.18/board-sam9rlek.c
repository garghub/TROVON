static void __init ek_init_early(void)
{
at91_initialize(12000000);
}
static void __init ek_add_device_nand(void)
{
sam9_smc_configure(0, 3, &ek_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void at91_lcdc_power_control(struct atmel_lcdfb_pdata *pdata, int on)
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
at91_register_devices();
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9RL_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_add_device_serial();
at91_add_device_usba(&ek_usba_udc_data);
at91_add_device_i2c(NULL, 0);
ek_add_device_nand();
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
at91_add_device_mci(0, &mci0_data);
at91_add_device_lcdc(&ek_lcdc_data);
at91_add_device_ac97(&ek_ac97_data);
at91_add_device_adc(&ek_adc_data);
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
ek_add_device_buttons();
}
