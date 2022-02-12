static void __init income_mmc_init(void)
{
pxa_set_mci_info(&income_mci_platform_data);
}
static inline void income_mmc_init(void) {}
static void __init income_uhc_init(void)
{
pxa_set_ohci_info(&income_ohci_info);
}
static inline void income_uhc_init(void) {}
static void __init income_led_init(void)
{
platform_device_register(&income_leds);
}
static inline void income_led_init(void) {}
static void __init income_i2c_init(void)
{
pxa_set_i2c_info(NULL);
pxa27x_set_i2c_power_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(income_i2c_devs));
}
static inline void income_i2c_init(void) {}
static void __init income_lcd_init(void)
{
pxa_set_fb_info(NULL, &income_lcd_screen);
}
static inline void income_lcd_init(void) {}
static void __init income_pwm_init(void)
{
pwm_add_table(income_pwm_lookup, ARRAY_SIZE(income_pwm_lookup));
platform_device_register(&income_backlight);
}
static inline void income_pwm_init(void) {}
void __init colibri_pxa270_income_boardinit(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
income_mmc_init();
income_uhc_init();
income_led_init();
income_i2c_init();
income_lcd_init();
income_pwm_init();
}
