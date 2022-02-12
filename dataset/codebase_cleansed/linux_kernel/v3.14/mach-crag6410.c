static void crag6410_lcd_power_set(struct plat_lcd_data *pd, unsigned int power)
{
pr_debug("%s: setting power %d\n", __func__, power);
if (power) {
gpio_set_value(S3C64XX_GPB(0), 1);
msleep(1);
s3c_gpio_cfgpin(S3C64XX_GPF(14), S3C_GPIO_SFN(2));
} else {
gpio_direction_output(S3C64XX_GPF(14), 0);
gpio_set_value(S3C64XX_GPB(0), 0);
}
}
static void __init crag6410_map_io(void)
{
s3c64xx_init_io(NULL, 0);
s3c64xx_set_xtal_freq(12000000);
s3c24xx_init_uarts(crag6410_uartcfgs, ARRAY_SIZE(crag6410_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void crag6410_cfg_sdhci0(struct platform_device *dev, int width)
{
s3c_gpio_cfgrange_nopull(S3C64XX_GPG(0), 2 + width, S3C_GPIO_SFN(2));
s3c_gpio_setpull(S3C64XX_GPG(6), S3C_GPIO_PULL_DOWN);
}
static void __init crag6410_machine_init(void)
{
s3c_gpio_setpull(S3C64XX_GPM(0), S3C_GPIO_PULL_UP);
s3c_gpio_setpull(S3C64XX_GPN(0), S3C_GPIO_PULL_UP);
gpio_request(S3C64XX_GPB(0), "LCD power");
gpio_direction_output(S3C64XX_GPB(0), 0);
gpio_request(S3C64XX_GPF(14), "LCD PWM");
gpio_direction_output(S3C64XX_GPF(14), 0);
gpio_request(S3C64XX_GPB(1), "SD power");
gpio_direction_output(S3C64XX_GPB(1), 0);
gpio_request(S3C64XX_GPF(10), "nRESETSEL");
gpio_direction_output(S3C64XX_GPF(10), 1);
s3c_sdhci0_set_platdata(&crag6410_hsmmc0_pdata);
s3c_sdhci2_set_platdata(&crag6410_hsmmc2_pdata);
s3c_i2c0_set_platdata(&i2c0_pdata);
s3c_i2c1_set_platdata(&i2c1_pdata);
s3c_fb_set_platdata(&crag6410_lcd_pdata);
s3c_hsotg_set_platdata(&crag6410_hsotg_pdata);
i2c_register_board_info(0, i2c_devs0, ARRAY_SIZE(i2c_devs0));
i2c_register_board_info(1, i2c_devs1, ARRAY_SIZE(i2c_devs1));
samsung_keypad_set_platdata(&crag6410_keypad_data);
s3c64xx_spi0_set_platdata(NULL, 0, 2);
platform_add_devices(crag6410_devices, ARRAY_SIZE(crag6410_devices));
gpio_led_register_device(-1, &gpio_leds_pdata);
regulator_has_full_constraints();
s3c64xx_pm_init();
}
