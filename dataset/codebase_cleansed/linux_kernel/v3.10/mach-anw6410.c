static void __init anw6410_lcd_mode_set(void)
{
u32 tmp;
tmp = __raw_readl(S3C64XX_SPCON);
tmp &= ~S3C64XX_SPCON_LCD_SEL_MASK;
tmp |= S3C64XX_SPCON_LCD_SEL_RGB;
__raw_writel(tmp, S3C64XX_SPCON);
tmp = __raw_readl(S3C64XX_MODEM_MIFPCON);
tmp &= ~MIFPCON_LCD_BYPASS;
__raw_writel(tmp, S3C64XX_MODEM_MIFPCON);
}
static void anw6410_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power) {
anw6410_extdev_status |= (ANW6410_EN_LCD << 16);
__raw_writel(anw6410_extdev_status, ANW6410_VA_EXTDEV);
gpio_direction_output(S3C64XX_GPF(1), 1);
gpio_direction_output(S3C64XX_GPF(4), 1);
} else {
anw6410_extdev_status &= ~(ANW6410_EN_LCD << 16);
__raw_writel(anw6410_extdev_status, ANW6410_VA_EXTDEV);
gpio_direction_output(S3C64XX_GPF(1), 0);
gpio_direction_output(S3C64XX_GPF(4), 0);
}
}
static void __init anw6410_dm9000_enable(void)
{
anw6410_extdev_status |= (ANW6410_EN_DM9000 << 16);
__raw_writel(anw6410_extdev_status, ANW6410_VA_EXTDEV);
}
static void __init anw6410_map_io(void)
{
s3c64xx_init_io(anw6410_iodesc, ARRAY_SIZE(anw6410_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(anw6410_uartcfgs, ARRAY_SIZE(anw6410_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
anw6410_lcd_mode_set();
}
static void __init anw6410_machine_init(void)
{
s3c_fb_set_platdata(&anw6410_lcd_pdata);
gpio_request(S3C64XX_GPF(1), "panel power");
gpio_request(S3C64XX_GPF(4), "LCD backlight");
anw6410_dm9000_enable();
platform_add_devices(anw6410_devices, ARRAY_SIZE(anw6410_devices));
}
