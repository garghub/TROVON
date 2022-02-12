static void smdk6450_lte480_reset_power(struct plat_lcd_data *pd,
unsigned int power)
{
int err;
if (power) {
err = gpio_request(S5P6450_GPN(5), "GPN");
if (err) {
printk(KERN_ERR "failed to request GPN for lcd reset\n");
return;
}
gpio_direction_output(S5P6450_GPN(5), 1);
gpio_set_value(S5P6450_GPN(5), 0);
gpio_set_value(S5P6450_GPN(5), 1);
gpio_free(S5P6450_GPN(5));
}
}
static void __init smdk6450_map_io(void)
{
s5p_init_io(NULL, 0, S5P64X0_SYS_ID);
s3c24xx_init_clocks(19200000);
s3c24xx_init_uarts(smdk6450_uartcfgs, ARRAY_SIZE(smdk6450_uartcfgs));
s5p_set_timer_source(S5P_PWM3, S5P_PWM4);
}
static void s5p6450_set_lcd_interface(void)
{
unsigned int cfg;
cfg = __raw_readl(S5P64X0_SPCON0);
cfg &= ~S5P64X0_SPCON0_LCD_SEL_MASK;
cfg |= S5P64X0_SPCON0_LCD_SEL_RGB;
__raw_writel(cfg, S5P64X0_SPCON0);
}
static void __init smdk6450_machine_init(void)
{
s3c24xx_ts_set_platdata(NULL);
s3c_i2c0_set_platdata(&s5p6450_i2c0_data);
s3c_i2c1_set_platdata(&s5p6450_i2c1_data);
i2c_register_board_info(0, smdk6450_i2c_devs0,
ARRAY_SIZE(smdk6450_i2c_devs0));
i2c_register_board_info(1, smdk6450_i2c_devs1,
ARRAY_SIZE(smdk6450_i2c_devs1));
samsung_bl_set(&smdk6450_bl_gpio_info, &smdk6450_bl_data);
s5p6450_set_lcd_interface();
s3c_fb_set_platdata(&smdk6450_lcd_pdata);
platform_add_devices(smdk6450_devices, ARRAY_SIZE(smdk6450_devices));
}
