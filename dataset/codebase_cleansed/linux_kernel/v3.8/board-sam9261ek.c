static void __init ek_init_early(void)
{
at91_initialize(18432000);
}
static void __init ek_add_device_dm9000(void)
{
struct resource *r = &dm9000_resource[2];
sam9_smc_configure(0, 2, &dm9000_smc_config);
at91_set_gpio_output(AT91_PIN_PC10, 0);
at91_set_gpio_input(AT91_PIN_PC11, 0);
r->start = r->end = gpio_to_irq(AT91_PIN_PC11);
platform_device_register(&dm9000_device);
}
static void __init ek_add_device_dm9000(void) {}
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
static int ads7843_pendown_state(void)
{
return !at91_get_gpio_value(AT91_PIN_PC2);
}
static void __init ek_add_device_ts(void)
{
at91_set_B_periph(AT91_PIN_PC2, 1);
at91_set_gpio_input(AT91_PIN_PA11, 1);
}
static void __init ek_add_device_ts(void) {}
static void __init at73c213_set_clk(struct at73c213_board_info *info)
{
struct clk *pck2;
struct clk *plla;
pck2 = clk_get(NULL, "pck2");
plla = clk_get(NULL, "plla");
at91_set_B_periph(AT91_PIN_PB31, 0);
clk_set_parent(pck2, plla);
clk_put(plla);
info->dac_clk = pck2;
}
static void __init at73c213_set_clk(struct at73c213_board_info *info) {}
static void at91_lcdc_stn_power_control(int on)
{
if (on) {
at91_set_gpio_value(AT91_PIN_PC14, 0);
at91_set_gpio_value(AT91_PIN_PC15, 0);
} else {
at91_set_gpio_value(AT91_PIN_PC14, 1);
at91_set_gpio_value(AT91_PIN_PC15, 1);
}
}
static void at91_lcdc_tft_power_control(int on)
{
if (on)
at91_set_gpio_value(AT91_PIN_PA12, 0);
else
at91_set_gpio_value(AT91_PIN_PA12, 1);
}
static void __init ek_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PA27, 1);
at91_set_deglitch(AT91_PIN_PA27, 1);
at91_set_gpio_input(AT91_PIN_PA26, 1);
at91_set_deglitch(AT91_PIN_PA26, 1);
at91_set_gpio_input(AT91_PIN_PA25, 1);
at91_set_deglitch(AT91_PIN_PA25, 1);
at91_set_gpio_input(AT91_PIN_PA24, 1);
at91_set_deglitch(AT91_PIN_PA24, 1);
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void __init ek_board_init(void)
{
at91_register_uart(0, 0, 0);
at91_add_device_serial();
at91_add_device_usbh(&ek_usbh_data);
at91_add_device_udc(&ek_udc_data);
at91_add_device_i2c(NULL, 0);
ek_add_device_nand();
ek_add_device_dm9000();
#if defined(CONFIG_SPI_ATMEL) || defined(CONFIG_SPI_ATMEL_MODULE)
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
ek_add_device_ts();
at73c213_set_clk(&at73c213_data);
at91_add_device_ssc(AT91SAM9261_ID_SSC1, ATMEL_SSC_TX);
#else
at91_add_device_mci(0, &mci0_data);
#endif
at91_add_device_lcdc(&ek_lcdc_data);
ek_add_device_buttons();
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
}
