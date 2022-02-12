static void __init universal_tsp_init(void)
{
int gpio;
gpio = EXYNOS4_GPE2(3);
gpio_request(gpio, "TSP_LDO_ON");
gpio_direction_output(gpio, 1);
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
gpio_request(gpio, "3_TOUCH_EN");
gpio_direction_output(gpio, 1);
}
static void __init universal_sdhci_init(void)
{
s3c_sdhci0_set_platdata(&universal_hsmmc0_data);
s3c_sdhci2_set_platdata(&universal_hsmmc2_data);
s3c_sdhci3_set_platdata(&universal_hsmmc3_data);
}
static void __init universal_map_io(void)
{
s5p_init_io(NULL, 0, S5P_VA_CHIPID);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(universal_uartcfgs, ARRAY_SIZE(universal_uartcfgs));
}
static void __init universal_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init universal_machine_init(void)
{
universal_sdhci_init();
i2c_register_board_info(0, i2c0_devs, ARRAY_SIZE(i2c0_devs));
i2c_register_board_info(1, i2c1_devs, ARRAY_SIZE(i2c1_devs));
universal_tsp_init();
s3c_i2c3_set_platdata(NULL);
i2c_register_board_info(3, i2c3_devs, ARRAY_SIZE(i2c3_devs));
s3c_i2c5_set_platdata(NULL);
i2c_register_board_info(5, i2c5_devs, ARRAY_SIZE(i2c5_devs));
universal_touchkey_init();
i2c_register_board_info(I2C_GPIO_BUS_12, i2c_gpio12_devs,
ARRAY_SIZE(i2c_gpio12_devs));
platform_add_devices(universal_devices, ARRAY_SIZE(universal_devices));
s5p_device_mfc.dev.parent = &exynos4_device_pd[PD_MFC].dev;
}
