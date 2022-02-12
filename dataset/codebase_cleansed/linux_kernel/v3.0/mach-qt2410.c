static void spi_gpio_cs(struct s3c2410_spigpio_info *spi, int cs)
{
switch (cs) {
case BITBANG_CS_ACTIVE:
gpio_set_value(S3C2410_GPB(5), 0);
break;
case BITBANG_CS_INACTIVE:
gpio_set_value(S3C2410_GPB(5), 1);
break;
}
}
static int __init qt2410_tft_setup(char *str)
{
tft_type = str[0];
return 1;
}
static void __init qt2410_map_io(void)
{
s3c24xx_init_io(qt2410_iodesc, ARRAY_SIZE(qt2410_iodesc));
s3c24xx_init_clocks(12*1000*1000);
s3c24xx_init_uarts(smdk2410_uartcfgs, ARRAY_SIZE(smdk2410_uartcfgs));
}
static void __init qt2410_machine_init(void)
{
s3c_nand_set_platdata(&qt2410_nand_info);
switch (tft_type) {
case 'p':
qt2410_fb_info.default_display = 1;
break;
case 'b':
qt2410_fb_info.default_display = 0;
break;
case 's':
default:
qt2410_fb_info.default_display = 2;
break;
}
s3c24xx_fb_set_platdata(&qt2410_fb_info);
s3c_gpio_cfgpin(S3C2410_GPB(0), S3C2410_GPIO_OUTPUT);
s3c2410_gpio_setpin(S3C2410_GPB(0), 1);
s3c24xx_udc_set_platdata(&qt2410_udc_cfg);
s3c_i2c0_set_platdata(NULL);
WARN_ON(gpio_request(S3C2410_GPB(5), "spi cs"));
gpio_direction_output(S3C2410_GPB(5), 1);
platform_add_devices(qt2410_devices, ARRAY_SIZE(qt2410_devices));
s3c_pm_init();
}
