static void __init real6410_map_io(void)
{
u32 tmp;
s3c64xx_init_io(NULL, 0);
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(real6410_uartcfgs, ARRAY_SIZE(real6410_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
tmp = __raw_readl(S3C64XX_SPCON);
tmp &= ~S3C64XX_SPCON_LCD_SEL_MASK;
tmp |= S3C64XX_SPCON_LCD_SEL_RGB;
__raw_writel(tmp, S3C64XX_SPCON);
tmp = __raw_readl(S3C64XX_MODEM_MIFPCON);
tmp &= ~MIFPCON_LCD_BYPASS;
__raw_writel(tmp, S3C64XX_MODEM_MIFPCON);
}
static int __init real6410_features_setup(char *str)
{
if (str)
strlcpy(real6410_features_str, str,
sizeof(real6410_features_str));
return 1;
}
static void real6410_parse_features(
struct real6410_features_t *features,
const char *features_str)
{
const char *fp = features_str;
features->done = 0;
features->lcd_index = 0;
while (*fp) {
char f = *fp++;
switch (f) {
case '0'...'9':
if (features->done & FEATURE_SCREEN) {
printk(KERN_INFO "REAL6410: '%c' ignored, "
"screen type already set\n", f);
} else {
int li = f - '0';
if (li >= ARRAY_SIZE(real6410_lcd_pdata))
printk(KERN_INFO "REAL6410: '%c' out "
"of range LCD mode\n", f);
else {
features->lcd_index = li;
}
}
features->done |= FEATURE_SCREEN;
break;
}
}
}
static void __init real6410_machine_init(void)
{
u32 cs1;
struct real6410_features_t features = { 0 };
printk(KERN_INFO "REAL6410: Option string real6410=%s\n",
real6410_features_str);
real6410_parse_features(&features, real6410_features_str);
printk(KERN_INFO "REAL6410: selected LCD display is %dx%d\n",
real6410_lcd_pdata[features.lcd_index].win[0]->xres,
real6410_lcd_pdata[features.lcd_index].win[0]->yres);
s3c_fb_set_platdata(&real6410_lcd_pdata[features.lcd_index]);
s3c_nand_set_platdata(&real6410_nand_info);
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
(13 << S3C64XX_SROM_BCX__TACC__SHIFT) |
(4 << S3C64XX_SROM_BCX__TCOS__SHIFT) |
(0 << S3C64XX_SROM_BCX__TACS__SHIFT), S3C64XX_SROM_BC1);
gpio_request(S3C64XX_GPF(15), "LCD power");
platform_add_devices(real6410_devices, ARRAY_SIZE(real6410_devices));
}
