static void __init ek_init_early(void)
{
at91_initialize(16367660);
}
static int ads7843_pendown_state(void)
{
return !at91_get_gpio_value(AT91_PIN_PA15);
}
static void __init ek_add_device_ts(void)
{
at91_set_B_periph(AT91_PIN_PA15, 1);
at91_set_gpio_input(AT91_PIN_PA31, 1);
}
static void __init ek_add_device_ts(void) {}
static void __init ek_add_device_nand(void)
{
ek_nand_data.bus_width_16 = board_have_nand_16bit();
if (ek_nand_data.bus_width_16)
ek_nand_smc_config.mode |= AT91_SMC_DBW_16;
else
ek_nand_smc_config.mode |= AT91_SMC_DBW_8;
sam9_smc_configure(0, 3, &ek_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void at91_lcdc_power_control(int on)
{
at91_set_gpio_value(AT91_PIN_PA30, on);
}
static void __init ek_add_device_buttons(void)
{
at91_set_GPIO_periph(AT91_PIN_PC5, 1);
at91_set_deglitch(AT91_PIN_PC5, 1);
at91_set_GPIO_periph(AT91_PIN_PC4, 1);
at91_set_deglitch(AT91_PIN_PC4, 1);
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void sam9263ek_transceiver_switch(int on)
{
if (on) {
at91_set_gpio_output(AT91_PIN_PA18, 1);
at91_set_gpio_output(AT91_PIN_PA19, 0);
} else {
at91_set_gpio_output(AT91_PIN_PA18, 0);
at91_set_gpio_output(AT91_PIN_PA19, 1);
}
}
static void __init ek_board_init(void)
{
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9263_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_add_device_serial();
at91_add_device_usbh(&ek_usbh_data);
at91_add_device_udc(&ek_udc_data);
at91_set_gpio_output(AT91_PIN_PE20, 1);
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
ek_add_device_ts();
at91_add_device_mmc(1, &ek_mmc_data);
at91_add_device_eth(&ek_macb_data);
ek_add_device_nand();
at91_add_device_i2c(ek_i2c_devices, ARRAY_SIZE(ek_i2c_devices));
at91_add_device_lcdc(&ek_lcdc_data);
ek_add_device_buttons();
at91_add_device_ac97(&ek_ac97_data);
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
at91_pwm_leds(ek_pwm_led, ARRAY_SIZE(ek_pwm_led));
at91_add_device_can(&ek_can_data);
}
