static void __init z2_nor_init(void)
{
platform_device_register(&z2_flash);
}
static inline void z2_nor_init(void) {}
static void __init z2_pwm_init(void)
{
platform_device_register(&z2_backlight_devices[0]);
platform_device_register(&z2_backlight_devices[1]);
}
static inline void z2_pwm_init(void) {}
static void __init z2_lcd_init(void)
{
pxa_set_fb_info(NULL, &z2_lcd_screen);
}
static inline void z2_lcd_init(void) {}
static void __init z2_mmc_init(void)
{
pxa_set_mci_info(&z2_mci_platform_data);
}
static inline void z2_mmc_init(void) {}
static void __init z2_leds_init(void)
{
platform_device_register(&z2_leds);
}
static inline void z2_leds_init(void) {}
static void __init z2_mkp_init(void)
{
pxa_set_keypad_info(&z2_keypad_platform_data);
}
static inline void z2_mkp_init(void) {}
static void __init z2_keys_init(void)
{
platform_device_register(&z2_pxa_keys);
}
static inline void z2_keys_init(void) {}
static void __init z2_i2c_init(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(z2_i2c_board_info));
}
static inline void z2_i2c_init(void) {}
static int z2_lbs_spi_setup(struct spi_device *spi)
{
int ret = 0;
ret = gpio_request(GPIO14_ZIPITZ2_WIFI_POWER, "WiFi Power");
if (ret)
goto err;
ret = gpio_direction_output(GPIO14_ZIPITZ2_WIFI_POWER, 1);
if (ret)
goto err2;
mdelay(180);
spi->bits_per_word = 16;
spi->mode = SPI_MODE_2,
spi_setup(spi);
return 0;
err2:
gpio_free(GPIO14_ZIPITZ2_WIFI_POWER);
err:
return ret;
}
static int z2_lbs_spi_teardown(struct spi_device *spi)
{
gpio_set_value(GPIO14_ZIPITZ2_WIFI_POWER, 0);
gpio_free(GPIO14_ZIPITZ2_WIFI_POWER);
return 0;
}
static void __init z2_spi_init(void)
{
pxa2xx_set_spi_info(1, &pxa_ssp1_master_info);
pxa2xx_set_spi_info(2, &pxa_ssp2_master_info);
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
}
static inline void z2_spi_init(void) {}
static void __init z2_pmic_init(void)
{
pxa27x_set_i2c_power_info(NULL);
i2c_register_board_info(1, ARRAY_AND_SIZE(z2_pi2c_board_info));
}
static inline void z2_pmic_init(void) {}
static void z2_power_off(void)
{
PSPR = 0x0;
local_irq_disable();
pxa27x_set_pwrmode(PWRMODE_DEEPSLEEP);
pxa27x_cpu_pm_enter(PM_SUSPEND_MEM);
}
static void __init z2_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(z2_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
z2_lcd_init();
z2_mmc_init();
z2_mkp_init();
z2_i2c_init();
z2_spi_init();
z2_nor_init();
z2_pwm_init();
z2_leds_init();
z2_keys_init();
z2_pmic_init();
pm_power_off = z2_power_off;
}
