static void __init palmld_nor_init(void)
{
platform_device_register(&palmld_flash);
}
static inline void palmld_nor_init(void) {}
static void __init palmld_kpc_init(void)
{
pxa_set_keypad_info(&palmld_keypad_platform_data);
}
static inline void palmld_kpc_init(void) {}
static void __init palmld_keys_init(void)
{
platform_device_register(&palmld_pxa_keys);
}
static inline void palmld_keys_init(void) {}
static void __init palmld_leds_init(void)
{
platform_device_register(&palmld_leds);
}
static inline void palmld_leds_init(void) {}
static void __init palmld_ide_init(void)
{
platform_device_register(&palmld_ide_device);
}
static inline void palmld_ide_init(void) {}
static void __init palmld_map_io(void)
{
pxa27x_map_io();
iotable_init(palmld_io_desc, ARRAY_SIZE(palmld_io_desc));
}
static void __init palmld_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(palmld_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
palm27x_mmc_init(GPIO_NR_PALMLD_SD_DETECT_N, GPIO_NR_PALMLD_SD_READONLY,
GPIO_NR_PALMLD_SD_POWER, 0);
palm27x_pm_init(PALMLD_STR_BASE);
palm27x_lcd_init(-1, &palm_320x480_lcd_mode);
palm27x_irda_init(GPIO_NR_PALMLD_IR_DISABLE);
palm27x_ac97_init(PALMLD_BAT_MIN_VOLTAGE, PALMLD_BAT_MAX_VOLTAGE,
GPIO_NR_PALMLD_EARPHONE_DETECT, 95);
palm27x_pwm_init(GPIO_NR_PALMLD_BL_POWER, GPIO_NR_PALMLD_LCD_POWER);
palm27x_power_init(GPIO_NR_PALMLD_POWER_DETECT,
GPIO_NR_PALMLD_USB_DETECT_N);
palm27x_pmic_init();
palmld_kpc_init();
palmld_keys_init();
palmld_nor_init();
palmld_leds_init();
palmld_ide_init();
}
