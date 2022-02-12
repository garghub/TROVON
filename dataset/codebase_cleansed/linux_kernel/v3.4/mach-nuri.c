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
return gpio_request_one(EXYNOS4_GPE2(3), GPIOF_OUT_INIT_LOW,
"LCD_LD0_EN");
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
static void __init nuri_power_init(void)
{
int gpio;
int irq_base = IRQ_GPIO_END + 1;
int ta_en = 0;
nuri_max8997_pdata.irq_base = irq_base;
irq_base += MAX8997_IRQ_NR;
gpio = EXYNOS4_GPX0(7);
gpio_request(gpio, "AP_PMIC_IRQ");
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_NONE);
gpio = EXYNOS4_GPX2(3);
gpio_request(gpio, "FUEL_ALERT");
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_NONE);
gpio = nuri_max8903.dok;
gpio_request(gpio, "TA_nCONNECTED");
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_NONE);
ta_en = gpio_get_value(gpio) ? 0 : 1;
gpio = nuri_max8903.chg;
gpio_request(gpio, "TA_nCHG");
gpio_direction_input(gpio);
gpio = nuri_max8903.dcm;
gpio_request(gpio, "CURR_ADJ");
gpio_direction_output(gpio, ta_en);
}
static void __init nuri_ehci_init(void)
{
struct s5p_ehci_platdata *pdata = &nuri_ehci_pdata;
s5p_ehci_set_platdata(pdata);
}
static void __init nuri_camera_init(void)
{
s3c_set_platdata(&mipi_csis_platdata, sizeof(mipi_csis_platdata),
&s5p_device_mipi_csis0);
s3c_set_platdata(&fimc_md_platdata, sizeof(fimc_md_platdata),
&s5p_device_fimc_md);
if (gpio_request_array(nuri_camera_gpios,
ARRAY_SIZE(nuri_camera_gpios))) {
pr_err("%s: GPIO request failed\n", __func__);
return;
}
m5mols_board_info.irq = s5p_register_gpio_interrupt(GPIO_CAM_8M_ISP_INT);
if (!IS_ERR_VALUE(m5mols_board_info.irq))
s3c_gpio_cfgpin(GPIO_CAM_8M_ISP_INT, S3C_GPIO_SFN(0xF));
else
pr_err("%s: Failed to configure 8M_ISP_INT GPIO\n", __func__);
gpio_free(GPIO_CAM_VT_NRST);
gpio_free(GPIO_CAM_VT_NSTBY);
gpio_free(GPIO_CAM_MEGA_RST);
if (exynos4_fimc_setup_gpio(S5P_CAMPORT_A)) {
pr_err("%s: Camera port A setup failed\n", __func__);
return;
}
s5p_gpio_set_drvstr(EXYNOS4_GPJ1(3), S5P_GPIO_DRVSTR_LV4);
}
static void __init nuri_map_io(void)
{
clk_xusbxti.rate = 24000000;
exynos_init_io(NULL, 0);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(nuri_uartcfgs, ARRAY_SIZE(nuri_uartcfgs));
}
static void __init nuri_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init nuri_machine_init(void)
{
nuri_sdhci_init();
nuri_tsp_init();
nuri_power_init();
s3c_i2c0_set_platdata(&nuri_i2c0_platdata);
i2c_register_board_info(1, i2c1_devs, ARRAY_SIZE(i2c1_devs));
s3c_i2c3_set_platdata(&i2c3_data);
i2c_register_board_info(3, i2c3_devs, ARRAY_SIZE(i2c3_devs));
s3c_i2c5_set_platdata(NULL);
i2c5_devs[I2C5_MAX8997].irq = gpio_to_irq(EXYNOS4_GPX0(7));
i2c_register_board_info(5, i2c5_devs, ARRAY_SIZE(i2c5_devs));
i2c9_devs[I2C9_MAX17042].irq = gpio_to_irq(EXYNOS4_GPX2(3));
i2c_register_board_info(9, i2c9_devs, ARRAY_SIZE(i2c9_devs));
s3c_i2c6_set_platdata(&nuri_i2c6_platdata);
s5p_fimd0_set_platdata(&nuri_fb_pdata);
nuri_camera_init();
nuri_ehci_init();
platform_add_devices(nuri_devices, ARRAY_SIZE(nuri_devices));
}
