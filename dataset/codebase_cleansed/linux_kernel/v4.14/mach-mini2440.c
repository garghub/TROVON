static void __init mini2440_map_io(void)
{
s3c24xx_init_io(mini2440_iodesc, ARRAY_SIZE(mini2440_iodesc));
s3c24xx_init_uarts(mini2440_uartcfgs, ARRAY_SIZE(mini2440_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init mini2440_init_time(void)
{
s3c2440_init_clocks(12000000);
samsung_timer_init();
}
static int __init mini2440_features_setup(char *str)
{
if (str)
strlcpy(mini2440_features_str, str, sizeof(mini2440_features_str));
return 1;
}
static void __init mini2440_parse_features(
struct mini2440_features_t * features,
const char * features_str )
{
const char * fp = features_str;
features->count = 0;
features->done = 0;
features->lcd_index = -1;
while (*fp) {
char f = *fp++;
switch (f) {
case '0'...'9':
if (features->done & FEATURE_SCREEN) {
printk(KERN_INFO "MINI2440: '%c' ignored, "
"screen type already set\n", f);
} else {
int li = f - '0';
if (li >= ARRAY_SIZE(mini2440_lcd_cfg))
printk(KERN_INFO "MINI2440: "
"'%c' out of range LCD mode\n", f);
else {
features->optional[features->count++] =
&s3c_device_lcd;
features->lcd_index = li;
}
}
features->done |= FEATURE_SCREEN;
break;
case 'b':
if (features->done & FEATURE_BACKLIGHT)
printk(KERN_INFO "MINI2440: '%c' ignored, "
"backlight already set\n", f);
else {
features->optional[features->count++] =
&mini2440_led_backlight;
}
features->done |= FEATURE_BACKLIGHT;
break;
case 't':
printk(KERN_INFO "MINI2440: '%c' ignored, "
"touchscreen not compiled in\n", f);
break;
case 'c':
if (features->done & FEATURE_CAMERA)
printk(KERN_INFO "MINI2440: '%c' ignored, "
"camera already registered\n", f);
else
features->optional[features->count++] =
&s3c_device_camif;
features->done |= FEATURE_CAMERA;
break;
}
}
}
static void __init mini2440_init(void)
{
struct mini2440_features_t features = { 0 };
int i;
printk(KERN_INFO "MINI2440: Option string mini2440=%s\n",
mini2440_features_str);
mini2440_parse_features(&features, mini2440_features_str);
s3c_gpio_cfgpin(S3C2410_GPC(0), S3C2410_GPC0_LEND);
WARN_ON(gpio_request_one(S3C2410_GPG(4), GPIOF_OUT_INIT_HIGH, NULL));
gpio_free(S3C2410_GPG(4));
gpio_request_one(S3C2410_GPB(1), GPIOF_IN, NULL);
s3c_gpio_setpull(S3C2410_GPB(1), S3C_GPIO_PULL_UP);
gpio_free(S3C2410_GPB(1));
for (i = 0; i < ARRAY_SIZE(mini2440_buttons); i++) {
s3c_gpio_setpull(mini2440_buttons[i].gpio, S3C_GPIO_PULL_UP);
s3c_gpio_cfgpin(mini2440_buttons[i].gpio, S3C2410_GPIO_INPUT);
}
if (features.lcd_index != -1) {
int li;
mini2440_fb_info.displays =
&mini2440_lcd_cfg[features.lcd_index];
printk(KERN_INFO "MINI2440: LCD");
for (li = 0; li < ARRAY_SIZE(mini2440_lcd_cfg); li++)
if (li == features.lcd_index)
printk(" [%d:%dx%d]", li,
mini2440_lcd_cfg[li].width,
mini2440_lcd_cfg[li].height);
else
printk(" %d:%dx%d", li,
mini2440_lcd_cfg[li].width,
mini2440_lcd_cfg[li].height);
printk("\n");
s3c24xx_fb_set_platdata(&mini2440_fb_info);
}
s3c24xx_udc_set_platdata(&mini2440_udc_cfg);
s3c24xx_mci_set_platdata(&mini2440_mmc_cfg);
s3c_nand_set_platdata(&mini2440_nand_info);
s3c_i2c0_set_platdata(NULL);
i2c_register_board_info(0, mini2440_i2c_devs,
ARRAY_SIZE(mini2440_i2c_devs));
platform_add_devices(mini2440_devices, ARRAY_SIZE(mini2440_devices));
if (features.count)
platform_add_devices(features.optional, features.count);
}
