static void __init palmt5_kpc_init(void)
{
pxa_set_keypad_info(&palmt5_keypad_platform_data);
}
static inline void palmt5_kpc_init(void) {}
static void __init palmt5_keys_init(void)
{
platform_device_register(&palmt5_pxa_keys);
}
static inline void palmt5_keys_init(void) {}
static void __init palmt5_reserve(void)
{
memblock_reserve(0xa0200000, 0x1000);
}
static void __init palmt5_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(palmt5_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
palm27x_mmc_init(GPIO_NR_PALMT5_SD_DETECT_N, GPIO_NR_PALMT5_SD_READONLY,
GPIO_NR_PALMT5_SD_POWER, 0);
palm27x_pm_init(PALMT5_STR_BASE);
palm27x_lcd_init(-1, &palm_320x480_lcd_mode);
palm27x_udc_init(GPIO_NR_PALMT5_USB_DETECT_N,
GPIO_NR_PALMT5_USB_PULLUP, 1);
palm27x_irda_init(GPIO_NR_PALMT5_IR_DISABLE);
palm27x_ac97_init(PALMT5_BAT_MIN_VOLTAGE, PALMT5_BAT_MAX_VOLTAGE,
GPIO_NR_PALMT5_EARPHONE_DETECT, 95);
palm27x_pwm_init(GPIO_NR_PALMT5_BL_POWER, GPIO_NR_PALMT5_LCD_POWER);
palm27x_power_init(GPIO_NR_PALMT5_POWER_DETECT, -1);
palm27x_pmic_init();
palmt5_kpc_init();
palmt5_keys_init();
}
