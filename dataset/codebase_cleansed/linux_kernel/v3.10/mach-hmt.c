static int hmt_bl_init(struct device *dev)
{
int ret;
ret = gpio_request(S3C64XX_GPB(4), "lcd backlight enable");
if (!ret)
ret = gpio_direction_output(S3C64XX_GPB(4), 0);
return ret;
}
static int hmt_bl_notify(struct device *dev, int brightness)
{
if (brightness < 0x800) {
brightness = (100*256 * brightness + 231245/2) / 231245;
} else {
int t = (brightness*4 + 16*1024 + 58)/116;
brightness = 25 * ((t * t * t + 0x100000/2) / 0x100000);
}
gpio_set_value(S3C64XX_GPB(4), brightness);
return brightness;
}
static void hmt_bl_exit(struct device *dev)
{
gpio_free(S3C64XX_GPB(4));
}
static void __init hmt_map_io(void)
{
s3c64xx_init_io(hmt_iodesc, ARRAY_SIZE(hmt_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(hmt_uartcfgs, ARRAY_SIZE(hmt_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init hmt_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
s3c_fb_set_platdata(&hmt_lcd_pdata);
s3c_nand_set_platdata(&hmt_nand_info);
gpio_request(S3C64XX_GPC(7), "usb power");
gpio_direction_output(S3C64XX_GPC(7), 0);
gpio_request(S3C64XX_GPM(0), "usb power");
gpio_direction_output(S3C64XX_GPM(0), 1);
gpio_request(S3C64XX_GPK(7), "usb power");
gpio_direction_output(S3C64XX_GPK(7), 1);
gpio_request(S3C64XX_GPF(13), "usb power");
gpio_direction_output(S3C64XX_GPF(13), 1);
platform_add_devices(hmt_devices, ARRAY_SIZE(hmt_devices));
}
