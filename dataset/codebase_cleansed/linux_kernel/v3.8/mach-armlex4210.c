static void __init armlex4210_sdhci_init(void)
{
s3c_sdhci0_set_platdata(&armlex4210_hsmmc0_pdata);
s3c_sdhci2_set_platdata(&armlex4210_hsmmc2_pdata);
s3c_sdhci3_set_platdata(&armlex4210_hsmmc3_pdata);
}
static void __init armlex4210_wlan_init(void)
{
s3c_gpio_cfgpin(EXYNOS4_GPX2(0), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(EXYNOS4_GPX2(0), S3C_GPIO_PULL_UP);
s3c_gpio_cfgpin(EXYNOS4_GPX1(6), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(EXYNOS4_GPX1(6), S3C_GPIO_PULL_UP);
s3c_gpio_cfgpin(EXYNOS4_GPX1(5), S3C_GPIO_SFN(0xf));
s3c_gpio_setpull(EXYNOS4_GPX1(5), S3C_GPIO_PULL_UP);
}
static void __init armlex4210_smsc911x_init(void)
{
u32 cs1;
cs1 = __raw_readl(S5P_SROM_BW) &
~(S5P_SROM_BW__CS_MASK << S5P_SROM_BW__NCS1__SHIFT);
cs1 |= ((1 << S5P_SROM_BW__DATAWIDTH__SHIFT) |
(0 << S5P_SROM_BW__WAITENABLE__SHIFT) |
(1 << S5P_SROM_BW__ADDRMODE__SHIFT) |
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
static void __init armlex4210_map_io(void)
{
exynos_init_io(NULL, 0);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(armlex4210_uartcfgs,
ARRAY_SIZE(armlex4210_uartcfgs));
}
static void __init armlex4210_machine_init(void)
{
armlex4210_smsc911x_init();
armlex4210_sdhci_init();
armlex4210_wlan_init();
platform_add_devices(armlex4210_devices,
ARRAY_SIZE(armlex4210_devices));
}
