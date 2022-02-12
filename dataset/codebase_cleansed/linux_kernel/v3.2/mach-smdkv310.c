static void lcd_lte480wv_set_power(struct plat_lcd_data *pd,
unsigned int power)
{
if (power) {
#if !defined(CONFIG_BACKLIGHT_PWM)
gpio_request_one(EXYNOS4_GPD0(1), GPIOF_OUT_INIT_HIGH, "GPD0");
gpio_free(EXYNOS4_GPD0(1));
#endif
gpio_request(EXYNOS4_GPX0(6), "GPX0");
gpio_direction_output(EXYNOS4_GPX0(6), 1);
mdelay(100);
gpio_set_value(EXYNOS4_GPX0(6), 0);
mdelay(10);
gpio_set_value(EXYNOS4_GPX0(6), 1);
mdelay(10);
gpio_free(EXYNOS4_GPX0(6));
} else {
#if !defined(CONFIG_BACKLIGHT_PWM)
gpio_request_one(EXYNOS4_GPD0(1), GPIOF_OUT_INIT_LOW, "GPD0");
gpio_free(EXYNOS4_GPD0(1));
#endif
}
}
static void __init smdkv310_ehci_init(void)
{
struct s5p_ehci_platdata *pdata = &smdkv310_ehci_pdata;
s5p_ehci_set_platdata(pdata);
}
static void __init smdkv310_smsc911x_init(void)
{
u32 cs1;
cs1 = __raw_readl(S5P_SROM_BW) &
~(S5P_SROM_BW__CS_MASK << S5P_SROM_BW__NCS1__SHIFT);
cs1 |= ((1 << S5P_SROM_BW__DATAWIDTH__SHIFT) |
(1 << S5P_SROM_BW__WAITENABLE__SHIFT) |
(1 << S5P_SROM_BW__BYTEENABLE__SHIFT)) <<
S5P_SROM_BW__NCS1__SHIFT;
__raw_writel(cs1, S5P_SROM_BW);
__raw_writel((0x1 << S5P_SROM_BCX__PMC__SHIFT) |
(0x9 << S5P_SROM_BCX__TACP__SHIFT) |
(0xc << S5P_SROM_BCX__TCAH__SHIFT) |
(0x1 << S5P_SROM_BCX__TCOH__SHIFT) |
(0x6 << S5P_SROM_BCX__TACC__SHIFT) |
(0x1 << S5P_SROM_BCX__TCOS__SHIFT) |
(0x1 << S5P_SROM_BCX__TACS__SHIFT), S5P_SROM_BC1);
}
static void s5p_tv_setup(void)
{
WARN_ON(gpio_request_one(EXYNOS4_GPX3(7), GPIOF_IN, "hpd-plug"));
s3c_gpio_cfgpin(EXYNOS4_GPX3(7), S3C_GPIO_SFN(0x3));
s3c_gpio_setpull(EXYNOS4_GPX3(7), S3C_GPIO_PULL_NONE);
s5p_device_hdmi.dev.parent = &exynos4_device_pd[PD_TV].dev;
s5p_device_mixer.dev.parent = &exynos4_device_pd[PD_TV].dev;
}
static void __init smdkv310_map_io(void)
{
s5p_init_io(NULL, 0, S5P_VA_CHIPID);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(smdkv310_uartcfgs, ARRAY_SIZE(smdkv310_uartcfgs));
}
static void __init smdkv310_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init smdkv310_machine_init(void)
{
s3c_i2c1_set_platdata(NULL);
i2c_register_board_info(1, i2c_devs1, ARRAY_SIZE(i2c_devs1));
smdkv310_smsc911x_init();
s3c_sdhci0_set_platdata(&smdkv310_hsmmc0_pdata);
s3c_sdhci1_set_platdata(&smdkv310_hsmmc1_pdata);
s3c_sdhci2_set_platdata(&smdkv310_hsmmc2_pdata);
s3c_sdhci3_set_platdata(&smdkv310_hsmmc3_pdata);
s5p_tv_setup();
s5p_i2c_hdmiphy_set_platdata(NULL);
samsung_keypad_set_platdata(&smdkv310_keypad_data);
samsung_bl_set(&smdkv310_bl_gpio_info, &smdkv310_bl_data);
s5p_fimd0_set_platdata(&smdkv310_lcd0_pdata);
smdkv310_ehci_init();
clk_xusbxti.rate = 24000000;
platform_add_devices(smdkv310_devices, ARRAY_SIZE(smdkv310_devices));
s5p_device_mfc.dev.parent = &exynos4_device_pd[PD_MFC].dev;
}
