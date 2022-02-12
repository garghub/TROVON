static void __init aquila_pmic_init(void)
{
s3c_gpio_cfgpin(S5PV210_GPH0(7), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(S5PV210_GPH0(7), S3C_GPIO_PULL_UP);
s3c_gpio_cfgpin(S5PV210_GPH2(6), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(S5PV210_GPH2(6), S3C_GPIO_PULL_UP);
}
static void aquila_setup_sdhci(void)
{
gpio_request_one(AQUILA_EXT_FLASH_EN, GPIOF_OUT_INIT_HIGH, "FLASH_EN");
s3c_sdhci0_set_platdata(&aquila_hsmmc0_data);
s3c_sdhci1_set_platdata(&aquila_hsmmc1_data);
s3c_sdhci2_set_platdata(&aquila_hsmmc2_data);
}
static void __init aquila_sound_init(void)
{
unsigned int gpio;
gpio = S5PV210_GPH3(2);
gpio_request(gpio, "CODEC_XTAL_EN");
s3c_gpio_cfgpin(gpio, S3C_GPIO_OUTPUT);
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_NONE);
__raw_writel(__raw_readl(S5P_OTHERS) | (0x3 << 8), S5P_OTHERS);
}
static void __init aquila_map_io(void)
{
s5pv210_init_io(NULL, 0);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(aquila_uartcfgs, ARRAY_SIZE(aquila_uartcfgs));
s5p_set_timer_source(S5P_PWM3, S5P_PWM4);
}
static void __init aquila_machine_init(void)
{
aquila_pmic_init();
i2c_register_board_info(AP_I2C_GPIO_PMIC_BUS_4, i2c_gpio_pmic_devs,
ARRAY_SIZE(i2c_gpio_pmic_devs));
aquila_setup_sdhci();
s3c_fimc_setname(0, "s5p-fimc");
s3c_fimc_setname(1, "s5p-fimc");
s3c_fimc_setname(2, "s5p-fimc");
aquila_sound_init();
i2c_register_board_info(AP_I2C_GPIO_BUS_5, i2c_gpio5_devs,
ARRAY_SIZE(i2c_gpio5_devs));
s3c_fb_set_platdata(&aquila_lcd_pdata);
platform_add_devices(aquila_devices, ARRAY_SIZE(aquila_devices));
}
