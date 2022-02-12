static void __init palmtreo_kpc_init(void)
{
static struct pxa27x_keypad_platform_data *data = &treo680_keypad_pdata;
if (machine_is_centro())
data->matrix_keymap_data = &centro_matrix_keymap_data;
pxa_set_keypad_info(&treo680_keypad_pdata);
}
static inline void palmtreo_kpc_init(void) {}
static void __init palmtreo_uhc_init(void)
{
if (machine_is_treo680())
pxa_set_ohci_info(&treo680_ohci_info);
}
static inline void palmtreo_uhc_init(void) {}
static void __init palmtreo_leds_init(void)
{
if (machine_is_centro())
palmtreo_leds.dev.platform_data = &centro_gpio_led_info;
else if (machine_is_treo680())
palmtreo_leds.dev.platform_data = &treo680_gpio_led_info;
platform_device_register(&palmtreo_leds);
}
static void __init treo680_docg4_flash_init(void)
{
platform_device_register(&treo680_docg4_flash);
}
static inline void treo680_docg4_flash_init(void) {}
static void __init treo_reserve(void)
{
memblock_reserve(0xa0000000, 0x1000);
memblock_reserve(0xa2000000, 0x1000);
}
static void __init palmphone_common_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(treo_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
palm27x_pm_init(TREO_STR_BASE);
palm27x_lcd_init(GPIO_NR_TREO_BL_POWER, &palm_320x320_new_lcd_mode);
palm27x_udc_init(GPIO_NR_TREO_USB_DETECT, GPIO_NR_TREO_USB_PULLUP, 1);
palm27x_irda_init(GPIO_NR_TREO_IR_EN);
palm27x_ac97_init(-1, -1, -1, 95);
palm27x_pwm_init(GPIO_NR_TREO_BL_POWER, -1);
palm27x_power_init(GPIO_NR_TREO_POWER_DETECT, -1);
palm27x_pmic_init();
palmtreo_kpc_init();
palmtreo_uhc_init();
palmtreo_leds_init();
}
void __init treo680_gpio_init(void)
{
unsigned int gpio;
const unsigned long lcd_flags = GPIOF_INIT_HIGH | GPIOF_DIR_OUT;
gpio = GPIO_NR_TREO680_LCD_POWER;
if (gpio_request_one(gpio, lcd_flags, "LCD power") < 0)
goto fail;
gpio = GPIO_NR_TREO680_LCD_EN;
if (gpio_request_one(gpio, lcd_flags, "LCD enable") < 0)
goto fail;
gpio = GPIO_NR_TREO680_LCD_EN_N;
if (gpio_request_one(gpio, lcd_flags, "LCD enable_n") < 0)
goto fail;
gpio_set_value(GPIO_NR_TREO680_LCD_EN_N, 0);
return;
fail:
pr_err("gpio %d initialization failed\n", gpio);
gpio_free(GPIO_NR_TREO680_LCD_POWER);
gpio_free(GPIO_NR_TREO680_LCD_EN);
gpio_free(GPIO_NR_TREO680_LCD_EN_N);
}
static void __init treo680_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(treo680_pin_config));
palmphone_common_init();
treo680_gpio_init();
palm27x_mmc_init(GPIO_NR_TREO_SD_DETECT_N, GPIO_NR_TREO680_SD_READONLY,
GPIO_NR_TREO680_SD_POWER, 0);
treo680_docg4_flash_init();
}
static void __init centro_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(centro685_pin_config));
palmphone_common_init();
palm27x_mmc_init(GPIO_NR_TREO_SD_DETECT_N, -1,
GPIO_NR_CENTRO_SD_POWER, 1);
}
