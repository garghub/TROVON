static void __init universal_tsp_init(void)
{
int gpio;
gpio = EXYNOS4_GPE2(3);
gpio_request_one(gpio, GPIOF_OUT_INIT_HIGH, "TSP_LDO_ON");
gpio_export(gpio, 0);
gpio = EXYNOS4_GPE1(7);
gpio_request(gpio, "TSP_INT");
s5p_register_gpio_interrupt(gpio);
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_UP);
i2c3_devs[0].irq = gpio_to_irq(gpio);
}
static void __init universal_touchkey_init(void)
{
int gpio;
gpio = EXYNOS4_GPE3(7);
gpio_request(gpio, "3_TOUCH_INT");
s5p_register_gpio_interrupt(gpio);
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(0xf));
i2c_gpio12_devs[0].irq = gpio_to_irq(gpio);
gpio = EXYNOS4_GPE3(3);
gpio_request_one(gpio, GPIOF_OUT_INIT_HIGH, "3_TOUCH_EN");
}
static void __init universal_sdhci_init(void)
{
s3c_sdhci0_set_platdata(&universal_hsmmc0_data);
s3c_sdhci2_set_platdata(&universal_hsmmc2_data);
s3c_sdhci3_set_platdata(&universal_hsmmc3_data);
}
static int s5k6aa_set_power(int on)
{
gpio_set_value(GPIO_CAM_LEVEL_EN(2), !!on);
return 0;
}
static int m5mols_set_power(struct device *dev, int on)
{
gpio_set_value(GPIO_CAM_LEVEL_EN(1), !on);
gpio_set_value(GPIO_CAM_LEVEL_EN(2), !!on);
return 0;
}
static void __init universal_camera_init(void)
{
s3c_set_platdata(&mipi_csis_platdata, sizeof(mipi_csis_platdata),
&s5p_device_mipi_csis0);
s3c_set_platdata(&fimc_md_platdata, sizeof(fimc_md_platdata),
&s5p_device_fimc_md);
if (gpio_request_array(universal_camera_gpios,
ARRAY_SIZE(universal_camera_gpios))) {
pr_err("%s: GPIO request failed\n", __func__);
return;
}
if (!s3c_gpio_cfgpin(GPIO_CAM_8M_ISP_INT, S3C_GPIO_SFN(0xf)))
m5mols_board_info.irq = gpio_to_irq(GPIO_CAM_8M_ISP_INT);
else
pr_err("Failed to configure 8M_ISP_INT GPIO\n");
gpio_free(GPIO_CAM_MEGA_nRST);
gpio_free(GPIO_CAM_8M_ISP_INT);
gpio_free(GPIO_CAM_VGA_NRST);
gpio_free(GPIO_CAM_VGA_NSTBY);
if (exynos4_fimc_setup_gpio(S5P_CAMPORT_A))
pr_err("Camera port A setup failed\n");
}
static void __init universal_map_io(void)
{
exynos_init_io(NULL, 0);
s3c24xx_init_clocks(clk_xusbxti.rate);
s3c24xx_init_uarts(universal_uartcfgs, ARRAY_SIZE(universal_uartcfgs));
s5p_set_timer_source(S5P_PWM2, S5P_PWM4);
}
static void s5p_tv_setup(void)
{
gpio_request_one(EXYNOS4_GPX3(7), GPIOF_IN, "hpd-plug");
s3c_gpio_cfgpin(EXYNOS4_GPX3(7), S3C_GPIO_SFN(0x3));
s3c_gpio_setpull(EXYNOS4_GPX3(7), S3C_GPIO_PULL_NONE);
}
static void __init universal_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init universal_machine_init(void)
{
universal_sdhci_init();
s5p_tv_setup();
s3c_i2c0_set_platdata(&universal_i2c0_platdata);
i2c_register_board_info(1, i2c1_devs, ARRAY_SIZE(i2c1_devs));
universal_tsp_init();
s3c_i2c3_set_platdata(NULL);
i2c_register_board_info(3, i2c3_devs, ARRAY_SIZE(i2c3_devs));
s3c_i2c5_set_platdata(NULL);
s5p_i2c_hdmiphy_set_platdata(NULL);
i2c_register_board_info(5, i2c5_devs, ARRAY_SIZE(i2c5_devs));
#ifdef CONFIG_DRM_EXYNOS
s5p_device_fimd0.dev.platform_data = &drm_fimd_pdata;
exynos4_fimd0_gpio_setup_24bpp();
#else
s5p_fimd0_set_platdata(&universal_lcd_pdata);
#endif
universal_touchkey_init();
i2c_register_board_info(I2C_GPIO_BUS_12, i2c_gpio12_devs,
ARRAY_SIZE(i2c_gpio12_devs));
s3c_hsotg_set_platdata(&universal_hsotg_pdata);
universal_camera_init();
platform_add_devices(universal_devices, ARRAY_SIZE(universal_devices));
}
