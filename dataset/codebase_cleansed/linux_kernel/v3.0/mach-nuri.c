static void __init nuri_sdhci_init(void)
{
s3c_sdhci0_set_platdata(&nuri_hsmmc0_data);
s3c_sdhci2_set_platdata(&nuri_hsmmc2_data);
s3c_sdhci3_set_platdata(&nuri_hsmmc3_data);
}
static void nuri_lcd_power_on(struct plat_lcd_data *pd, unsigned int power)
{
int gpio = EXYNOS4_GPE1(5);
gpio_request(gpio, "LVDS_nSHDN");
gpio_direction_output(gpio, power);
gpio_free(gpio);
}
static int nuri_bl_init(struct device *dev)
{
int ret, gpio = EXYNOS4_GPE2(3);
ret = gpio_request(gpio, "LCD_LDO_EN");
if (!ret)
gpio_direction_output(gpio, 0);
return ret;
}
static int nuri_bl_notify(struct device *dev, int brightness)
{
if (brightness < 1)
brightness = 0;
gpio_set_value(EXYNOS4_GPE2(3), 1);
return brightness;
}
static void nuri_bl_exit(struct device *dev)
{
gpio_free(EXYNOS4_GPE2(3));
}
static void __init nuri_tsp_init(void)
{
int gpio;
gpio = EXYNOS4_GPX0(4);
gpio_request(gpio, "TOUCH_INT");
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_UP);
}
static void __init nuri_ehci_init(void)
{
struct s5p_ehci_platdata *pdata = &nuri_ehci_pdata;
s5p_ehci_set_platdata(pdata);
}
static void __init nuri_map_io(void)
{
s5p_init_io(NULL, 0, S5P_VA_CHIPID);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(nuri_uartcfgs, ARRAY_SIZE(nuri_uartcfgs));
}
static void __init nuri_machine_init(void)
{
nuri_sdhci_init();
nuri_tsp_init();
i2c_register_board_info(1, i2c1_devs, ARRAY_SIZE(i2c1_devs));
s3c_i2c3_set_platdata(&i2c3_data);
i2c_register_board_info(3, i2c3_devs, ARRAY_SIZE(i2c3_devs));
i2c_register_board_info(5, i2c5_devs, ARRAY_SIZE(i2c5_devs));
nuri_ehci_init();
clk_xusbxti.rate = 24000000;
platform_add_devices(nuri_devices, ARRAY_SIZE(nuri_devices));
}
