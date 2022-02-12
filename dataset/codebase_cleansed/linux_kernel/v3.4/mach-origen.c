static void __init origen_ehci_init(void)
{
struct s5p_ehci_platdata *pdata = &origen_ehci_pdata;
s5p_ehci_set_platdata(pdata);
}
static void __init origen_ohci_init(void)
{
struct exynos4_ohci_platdata *pdata = &origen_ohci_pdata;
exynos4_ohci_set_platdata(pdata);
}
static void lcd_hv070wsa_set_power(struct plat_lcd_data *pd, unsigned int power)
{
int ret;
if (power)
ret = gpio_request_one(EXYNOS4_GPE3(4),
GPIOF_OUT_INIT_HIGH, "GPE3_4");
else
ret = gpio_request_one(EXYNOS4_GPE3(4),
GPIOF_OUT_INIT_LOW, "GPE3_4");
gpio_free(EXYNOS4_GPE3(4));
if (ret)
pr_err("failed to request gpio for LCD power: %d\n", ret);
}
static void __init origen_bt_setup(void)
{
gpio_request(EXYNOS4_GPA0(0), "GPIO BT_UART");
s3c_gpio_cfgrange_nopull(EXYNOS4_GPA0(0), 4, S3C_GPIO_SFN(2));
s3c_gpio_cfgpin(EXYNOS4_GPX2(2), S3C_GPIO_OUTPUT);
s3c_gpio_setpull(EXYNOS4_GPX2(2), S3C_GPIO_PULL_NONE);
}
static void s5p_tv_setup(void)
{
gpio_request_one(EXYNOS4_GPX3(7), GPIOF_IN, "hpd-plug");
s3c_gpio_cfgpin(EXYNOS4_GPX3(7), S3C_GPIO_SFN(0x3));
s3c_gpio_setpull(EXYNOS4_GPX3(7), S3C_GPIO_PULL_NONE);
}
static void __init origen_map_io(void)
{
exynos_init_io(NULL, 0);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(origen_uartcfgs, ARRAY_SIZE(origen_uartcfgs));
}
static void __init origen_power_init(void)
{
gpio_request(EXYNOS4_GPX0(4), "PMIC_IRQ");
s3c_gpio_cfgpin(EXYNOS4_GPX0(4), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(EXYNOS4_GPX0(4), S3C_GPIO_PULL_NONE);
}
static void __init origen_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init origen_machine_init(void)
{
origen_power_init();
s3c_i2c0_set_platdata(NULL);
i2c_register_board_info(0, i2c0_devs, ARRAY_SIZE(i2c0_devs));
s3c_sdhci2_set_platdata(&origen_hsmmc2_pdata);
s3c_sdhci0_set_platdata(&origen_hsmmc0_pdata);
origen_ehci_init();
origen_ohci_init();
clk_xusbxti.rate = 24000000;
s5p_tv_setup();
s5p_i2c_hdmiphy_set_platdata(NULL);
s5p_fimd0_set_platdata(&origen_lcd_pdata);
platform_add_devices(origen_devices, ARRAY_SIZE(origen_devices));
samsung_bl_set(&origen_bl_gpio_info, &origen_bl_data);
origen_bt_setup();
}
