static int bast_pm_suspend(void)
{
gpio_direction_output(S3C2410_GPA(21), 1);
return 0;
}
static void bast_pm_resume(void)
{
s3c_gpio_cfgpin(S3C2410_GPA(21), S3C2410_GPA21_nRSTOUT);
}
static void bast_nand_select(struct s3c2410_nand_set *set, int slot)
{
unsigned int tmp;
slot = set->nr_map[slot] & 3;
pr_debug("bast_nand: selecting slot %d (set %p,%p)\n",
slot, set, set->nr_map);
tmp = __raw_readb(BAST_VA_CTRL2);
tmp &= BAST_CPLD_CTLR2_IDERST;
tmp |= slot;
tmp |= BAST_CPLD_CTRL2_WNAND;
pr_debug("bast_nand: ctrl2 now %02x\n", tmp);
__raw_writeb(tmp, BAST_VA_CTRL2);
}
static void __init bast_map_io(void)
{
s3c24xx_dclk0.parent = &clk_upll;
s3c24xx_dclk0.rate = 12*1000*1000;
s3c24xx_dclk1.parent = &clk_upll;
s3c24xx_dclk1.rate = 24*1000*1000;
s3c24xx_clkout0.parent = &s3c24xx_dclk0;
s3c24xx_clkout1.parent = &s3c24xx_dclk1;
s3c24xx_uclk.parent = &s3c24xx_clkout1;
s3c24xx_register_clocks(bast_clocks, ARRAY_SIZE(bast_clocks));
s3c_hwmon_set_platdata(&bast_hwmon_info);
s3c24xx_init_io(bast_iodesc, ARRAY_SIZE(bast_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(bast_uartcfgs, ARRAY_SIZE(bast_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init bast_init(void)
{
register_syscore_ops(&bast_pm_syscore_ops);
s3c_i2c0_set_platdata(&bast_i2c_info);
s3c_nand_set_platdata(&bast_nand_info);
s3c24xx_fb_set_platdata(&bast_fb_info);
platform_add_devices(bast_devices, ARRAY_SIZE(bast_devices));
i2c_register_board_info(0, bast_i2c_devs,
ARRAY_SIZE(bast_i2c_devs));
usb_simtec_init();
nor_simtec_init();
simtec_audio_add(NULL, true, &bast_audio);
WARN_ON(gpio_request(S3C2410_GPA(21), "bast nreset"));
s3c_cpufreq_setboard(&bast_cpufreq);
}
