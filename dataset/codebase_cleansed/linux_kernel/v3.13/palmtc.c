static void __init palmtc_mmc_init(void)
{
pxa_set_mci_info(&palmtc_mci_platform_data);
}
static inline void palmtc_mmc_init(void) {}
static void __init palmtc_keys_init(void)
{
platform_device_register(&palmtc_pxa_keys);
}
static inline void palmtc_keys_init(void) {}
static void __init palmtc_pwm_init(void)
{
platform_device_register(&palmtc_backlight);
}
static inline void palmtc_pwm_init(void) {}
static void __init palmtc_irda_init(void)
{
pxa_set_ficp_info(&palmtc_ficp_platform_data);
}
static inline void palmtc_irda_init(void) {}
static void __init palmtc_mkp_init(void)
{
platform_device_register(&palmtc_keyboard);
}
static inline void palmtc_mkp_init(void) {}
static void __init palmtc_udc_init(void)
{
platform_device_register(&palmtc_gpio_vbus);
}
static inline void palmtc_udc_init(void) {}
static void __init palmtc_ts_init(void)
{
pxa_set_ac97_info(NULL);
platform_device_register(&palmtc_ucb1400_device);
}
static inline void palmtc_ts_init(void) {}
static void __init palmtc_leds_init(void)
{
platform_device_register(&palmtc_leds);
}
static inline void palmtc_leds_init(void) {}
static void __init palmtc_nor_init(void)
{
platform_device_register(&palmtc_flash);
}
static inline void palmtc_nor_init(void) {}
static void __init palmtc_lcd_init(void)
{
pxa_set_fb_info(NULL, &palmtc_lcd_screen);
}
static inline void palmtc_lcd_init(void) {}
static void __init palmtc_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(palmtc_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_hwuart_info(NULL);
palmtc_mmc_init();
palmtc_keys_init();
palmtc_pwm_init();
palmtc_irda_init();
palmtc_mkp_init();
palmtc_udc_init();
palmtc_ts_init();
palmtc_nor_init();
palmtc_lcd_init();
palmtc_leds_init();
}
