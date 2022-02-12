static void mini6410_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power)
gpio_direction_output(S3C64XX_GPE(0), 1);
else
gpio_direction_output(S3C64XX_GPE(0), 0);
}
static void __init mini6410_map_io(void)
{
u32 tmp;
s3c64xx_init_io(NULL, 0);
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(mini6410_uartcfgs, ARRAY_SIZE(mini6410_uartcfgs));
tmp = __raw_readl(S3C64XX_SPCON);
tmp &= ~S3C64XX_SPCON_LCD_SEL_MASK;
tmp |= S3C64XX_SPCON_LCD_SEL_RGB;
__raw_writel(tmp, S3C64XX_SPCON);
tmp = __raw_readl(S3C64XX_MODEM_MIFPCON);
tmp &= ~MIFPCON_LCD_BYPASS;
__raw_writel(tmp, S3C64XX_MODEM_MIFPCON);
}
static int __init mini6410_features_setup(char *str)
{
if (str)
strlcpy(mini6410_features_str, str,
sizeof(mini6410_features_str));
return 1;
}
static void mini6410_parse_features(
struct mini6410_features_t *features,
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
printk(KERN_INFO "MINI6410: '%c' ignored, "
"screen type already set\n", f);
} else {
int li = f - '0';
if (li >= ARRAY_SIZE(mini6410_fb_win))
printk(KERN_INFO "MINI6410: '%c' out "
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
static void __init mini6410_machine_init(void)
{
u32 cs1;
struct mini6410_features_t features = { 0 };
printk(KERN_INFO "MINI6410: Option string mini6410=%s\n",
mini6410_features_str);
mini6410_parse_features(&features, mini6410_features_str);
mini6410_lcd_pdata.win[0] = &mini6410_fb_win[features.lcd_index];
printk(KERN_INFO "MINI6410: selected LCD display is %dx%d\n",
mini6410_lcd_pdata.win[0]->win_mode.xres,
mini6410_lcd_pdata.win[0]->win_mode.yres);
s3c_nand_set_platdata(&mini6410_nand_info);
s3c_fb_set_platdata(&mini6410_lcd_pdata);
s3c24xx_ts_set_platdata(&s3c_ts_platform);
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
gpio_request(S3C64XX_GPE(0), "LCD power");
platform_add_devices(mini6410_devices, ARRAY_SIZE(mini6410_devices));
}
