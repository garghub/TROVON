static int lcd_power_on(struct lcd_device *ld, int enable)
{
return 1;
}
static int reset_lcd(struct lcd_device *ld)
{
static unsigned int first = 1;
int reset_gpio = -1;
reset_gpio = S5PV210_MP05(5);
if (first) {
gpio_request(reset_gpio, "MLCD_RST");
first = 0;
}
gpio_direction_output(reset_gpio, 1);
return 1;
}
static void __init goni_radio_init(void)
{
int gpio;
gpio = S5PV210_GPJ2(4);
gpio_request(gpio, "FM_INT");
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
i2c1_devs[0].irq = gpio_to_irq(gpio);
gpio = S5PV210_GPJ2(5);
gpio_request_one(gpio, GPIOF_OUT_INIT_HIGH, "FM_RST");
}
static void __init goni_tsp_init(void)
{
int gpio;
gpio = S5PV210_GPJ1(3);
gpio_request_one(gpio, GPIOF_OUT_INIT_HIGH, "TSP_LDO_ON");
gpio_export(gpio, 0);
gpio = S5PV210_GPJ0(5);
gpio_request(gpio, "TSP_INT");
s5p_register_gpio_interrupt(gpio);
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_UP);
i2c2_devs[0].irq = gpio_to_irq(gpio);
}
static void goni_camera_init(void)
{
s5pv210_fimc_setup_gpio(S5P_CAMPORT_A);
s5p_gpio_set_drvstr(S5PV210_GPE1(3), S5P_GPIO_DRVSTR_LV4);
}
static void __init goni_pmic_init(void)
{
s3c_gpio_cfgpin(S5PV210_GPH0(7), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(S5PV210_GPH0(7), S3C_GPIO_PULL_UP);
s3c_gpio_cfgpin(S5PV210_GPH2(6), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(S5PV210_GPH2(6), S3C_GPIO_PULL_UP);
}
static void goni_setup_sdhci(void)
{
s3c_sdhci0_set_platdata(&goni_hsmmc0_data);
s3c_sdhci1_set_platdata(&goni_hsmmc1_data);
s3c_sdhci2_set_platdata(&goni_hsmmc2_data);
}
static void __init goni_sound_init(void)
{
__raw_writel(__raw_readl(S5P_OTHERS) | (0x3 << 8), S5P_OTHERS);
}
static void __init goni_map_io(void)
{
s5pv210_init_io(NULL, 0);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(goni_uartcfgs, ARRAY_SIZE(goni_uartcfgs));
s5p_set_timer_source(S5P_PWM3, S5P_PWM4);
}
static void __init goni_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init goni_machine_init(void)
{
goni_radio_init();
s3c_i2c0_set_platdata(NULL);
s3c_i2c1_set_platdata(NULL);
i2c_register_board_info(1, i2c1_devs, ARRAY_SIZE(i2c1_devs));
goni_tsp_init();
s3c_i2c2_set_platdata(&i2c2_data);
i2c_register_board_info(2, i2c2_devs, ARRAY_SIZE(i2c2_devs));
goni_pmic_init();
i2c_register_board_info(AP_I2C_GPIO_PMIC_BUS_4, i2c_gpio_pmic_devs,
ARRAY_SIZE(i2c_gpio_pmic_devs));
goni_setup_sdhci();
goni_sound_init();
i2c_register_board_info(AP_I2C_GPIO_BUS_5, i2c_gpio5_devs,
ARRAY_SIZE(i2c_gpio5_devs));
s3c_fb_set_platdata(&goni_lcd_pdata);
s3c_set_platdata(&goni_fimc_md_platdata, sizeof(goni_fimc_md_platdata),
&s5p_device_fimc_md);
s3c_hsotg_set_platdata(&goni_hsotg_pdata);
goni_camera_init();
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
samsung_keypad_set_platdata(&keypad_data);
clk_xusbxti.rate = 24000000;
platform_add_devices(goni_devices, ARRAY_SIZE(goni_devices));
}
