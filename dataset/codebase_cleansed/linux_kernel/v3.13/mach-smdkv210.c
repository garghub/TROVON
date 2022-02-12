static void smdkv210_lte480wv_set_power(struct plat_lcd_data *pd,
unsigned int power)
{
if (power) {
#if !defined(CONFIG_BACKLIGHT_PWM)
gpio_request_one(S5PV210_GPD0(3), GPIOF_OUT_INIT_HIGH, "GPD0");
gpio_free(S5PV210_GPD0(3));
#endif
gpio_request_one(S5PV210_GPH0(6), GPIOF_OUT_INIT_HIGH, "GPH0");
gpio_set_value(S5PV210_GPH0(6), 0);
mdelay(10);
gpio_set_value(S5PV210_GPH0(6), 1);
mdelay(10);
gpio_free(S5PV210_GPH0(6));
} else {
#if !defined(CONFIG_BACKLIGHT_PWM)
gpio_request_one(S5PV210_GPD0(3), GPIOF_OUT_INIT_LOW, "GPD0");
gpio_free(S5PV210_GPD0(3));
#endif
}
}
static void __init smdkv210_dm9000_init(void)
{
unsigned int tmp;
gpio_request(S5PV210_MP01(5), "nCS5");
s3c_gpio_cfgpin(S5PV210_MP01(5), S3C_GPIO_SFN(2));
gpio_free(S5PV210_MP01(5));
tmp = (5 << S5P_SROM_BCX__TACC__SHIFT);
__raw_writel(tmp, S5P_SROM_BC5);
tmp = __raw_readl(S5P_SROM_BW);
tmp &= (S5P_SROM_BW__CS_MASK << S5P_SROM_BW__NCS5__SHIFT);
tmp |= (1 << S5P_SROM_BW__NCS5__SHIFT);
__raw_writel(tmp, S5P_SROM_BW);
}
static void __init smdkv210_map_io(void)
{
s5pv210_init_io(NULL, 0);
s3c24xx_init_clocks(clk_xusbxti.rate);
s3c24xx_init_uarts(smdkv210_uartcfgs, ARRAY_SIZE(smdkv210_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM2, SAMSUNG_PWM4);
}
static void __init smdkv210_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init smdkv210_machine_init(void)
{
s3c_pm_init();
smdkv210_dm9000_init();
samsung_keypad_set_platdata(&smdkv210_keypad_data);
s3c24xx_ts_set_platdata(NULL);
s3c_i2c0_set_platdata(NULL);
s3c_i2c1_set_platdata(NULL);
s3c_i2c2_set_platdata(NULL);
i2c_register_board_info(0, smdkv210_i2c_devs0,
ARRAY_SIZE(smdkv210_i2c_devs0));
i2c_register_board_info(1, smdkv210_i2c_devs1,
ARRAY_SIZE(smdkv210_i2c_devs1));
i2c_register_board_info(2, smdkv210_i2c_devs2,
ARRAY_SIZE(smdkv210_i2c_devs2));
s3c_ide_set_platdata(&smdkv210_ide_pdata);
s3c_fb_set_platdata(&smdkv210_lcd0_pdata);
s3c_hsotg_set_platdata(&smdkv210_hsotg_pdata);
platform_add_devices(smdkv210_devices, ARRAY_SIZE(smdkv210_devices));
samsung_bl_set(&smdkv210_bl_gpio_info, &smdkv210_bl_data);
}
