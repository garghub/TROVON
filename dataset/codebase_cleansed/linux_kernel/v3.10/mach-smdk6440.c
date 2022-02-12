static void smdk6440_lte480_reset_power(struct plat_lcd_data *pd,
unsigned int power)
{
int err;
if (power) {
err = gpio_request(S5P6440_GPN(5), "GPN");
if (err) {
printk(KERN_ERR "failed to request GPN for lcd reset\n");
return;
}
gpio_direction_output(S5P6440_GPN(5), 1);
gpio_set_value(S5P6440_GPN(5), 0);
gpio_set_value(S5P6440_GPN(5), 1);
gpio_free(S5P6440_GPN(5));
}
}
static void __init smdk6440_map_io(void)
{
s5p64x0_init_io(NULL, 0);
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(smdk6440_uartcfgs, ARRAY_SIZE(smdk6440_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void s5p6440_set_lcd_interface(void)
{
unsigned int cfg;
cfg = __raw_readl(S5P64X0_SPCON0);
cfg &= ~S5P64X0_SPCON0_LCD_SEL_MASK;
cfg |= S5P64X0_SPCON0_LCD_SEL_RGB;
__raw_writel(cfg, S5P64X0_SPCON0);
}
static void __init smdk6440_machine_init(void)
{
s3c24xx_ts_set_platdata(NULL);
s3c_i2c0_set_platdata(&s5p6440_i2c0_data);
s3c_i2c1_set_platdata(&s5p6440_i2c1_data);
i2c_register_board_info(0, smdk6440_i2c_devs0,
ARRAY_SIZE(smdk6440_i2c_devs0));
i2c_register_board_info(1, smdk6440_i2c_devs1,
ARRAY_SIZE(smdk6440_i2c_devs1));
samsung_bl_set(&smdk6440_bl_gpio_info, &smdk6440_bl_data);
s5p6440_set_lcd_interface();
s3c_fb_set_platdata(&smdk6440_lcd_pdata);
s3c_sdhci0_set_platdata(&smdk6440_hsmmc0_pdata);
s3c_sdhci1_set_platdata(&smdk6440_hsmmc1_pdata);
s3c_sdhci2_set_platdata(&smdk6440_hsmmc2_pdata);
platform_add_devices(smdk6440_devices, ARRAY_SIZE(smdk6440_devices));
}
