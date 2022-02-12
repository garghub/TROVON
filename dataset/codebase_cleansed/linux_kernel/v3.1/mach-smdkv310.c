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
static void __init smdkv310_map_io(void)
{
s5p_init_io(NULL, 0, S5P_VA_CHIPID);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(smdkv310_uartcfgs, ARRAY_SIZE(smdkv310_uartcfgs));
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
samsung_keypad_set_platdata(&smdkv310_keypad_data);
samsung_bl_set(&smdkv310_bl_gpio_info, &smdkv310_bl_data);
platform_add_devices(smdkv310_devices, ARRAY_SIZE(smdkv310_devices));
}
