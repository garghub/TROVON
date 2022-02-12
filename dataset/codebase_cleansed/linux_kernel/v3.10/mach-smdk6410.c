static void smdk6410_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power) {
gpio_direction_output(S3C64XX_GPF(13), 1);
gpio_direction_output(S3C64XX_GPN(5), 0);
msleep(10);
gpio_direction_output(S3C64XX_GPN(5), 1);
msleep(1);
} else {
gpio_direction_output(S3C64XX_GPF(13), 0);
}
}
static int __init smdk6410_wm8350_init(struct wm8350 *wm8350)
{
int i;
s3c_gpio_setpull(S3C64XX_GPN(12), S3C_GPIO_PULL_UP);
for (i = 0; i < ARRAY_SIZE(wm1190_regulators); i++)
wm8350_register_regulator(wm8350,
wm1190_regulators[i].regulator,
wm1190_regulators[i].initdata);
return 0;
}
static int wm1192_pre_init(struct wm831x *wm831x)
{
int ret;
s3c_gpio_setpull(S3C64XX_GPN(12), S3C_GPIO_PULL_UP);
ret = platform_device_register(&wm1192_pmic_led_dev);
if (ret != 0)
dev_err(wm831x->dev, "Failed to add PMIC LED: %d\n", ret);
return 0;
}
static void __init smdk6410_map_io(void)
{
u32 tmp;
s3c64xx_init_io(smdk6410_iodesc, ARRAY_SIZE(smdk6410_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(smdk6410_uartcfgs, ARRAY_SIZE(smdk6410_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
tmp = __raw_readl(S3C64XX_SPCON);
tmp &= ~S3C64XX_SPCON_LCD_SEL_MASK;
tmp |= S3C64XX_SPCON_LCD_SEL_RGB;
__raw_writel(tmp, S3C64XX_SPCON);
tmp = __raw_readl(S3C64XX_MODEM_MIFPCON);
tmp &= ~MIFPCON_LCD_BYPASS;
__raw_writel(tmp, S3C64XX_MODEM_MIFPCON);
}
static void __init smdk6410_machine_init(void)
{
u32 cs1;
s3c_i2c0_set_platdata(NULL);
s3c_i2c1_set_platdata(NULL);
s3c_fb_set_platdata(&smdk6410_lcd_pdata);
s3c_hsotg_set_platdata(&smdk6410_hsotg_pdata);
samsung_keypad_set_platdata(&smdk6410_keypad_data);
s3c24xx_ts_set_platdata(NULL);
cs1 = __raw_readl(S3C64XX_SROM_BW) &
~(S3C64XX_SROM_BW__CS_MASK << S3C64XX_SROM_BW__NCS1__SHIFT);
cs1 |= ((1 << S3C64XX_SROM_BW__DATAWIDTH__SHIFT) |
(1 << S3C64XX_SROM_BW__WAITENABLE__SHIFT) |
(1 << S3C64XX_SROM_BW__BYTEENABLE__SHIFT)) <<
S3C64XX_SROM_BW__NCS1__SHIFT;
__raw_writel(cs1, S3C64XX_SROM_BW);
__raw_writel((0 << S3C64XX_SROM_BCX__PMC__SHIFT) |
(6 << S3C64XX_SROM_BCX__TACP__SHIFT) |
(4 << S3C64XX_SROM_BCX__TCAH__SHIFT) |
(1 << S3C64XX_SROM_BCX__TCOH__SHIFT) |
(0xe << S3C64XX_SROM_BCX__TACC__SHIFT) |
(4 << S3C64XX_SROM_BCX__TCOS__SHIFT) |
(0 << S3C64XX_SROM_BCX__TACS__SHIFT), S3C64XX_SROM_BC1);
gpio_request(S3C64XX_GPN(5), "LCD power");
gpio_request(S3C64XX_GPF(13), "LCD power");
i2c_register_board_info(0, i2c_devs0, ARRAY_SIZE(i2c_devs0));
i2c_register_board_info(1, i2c_devs1, ARRAY_SIZE(i2c_devs1));
s3c_ide_set_platdata(&smdk6410_ide_pdata);
samsung_bl_set(&smdk6410_bl_gpio_info, &smdk6410_bl_data);
platform_add_devices(smdk6410_devices, ARRAY_SIZE(smdk6410_devices));
}
