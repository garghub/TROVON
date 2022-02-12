static int __init qt2410_tft_setup(char *str)
{
tft_type = str[0];
return 1;
}
static void __init qt2410_map_io(void)
{
s3c24xx_init_io(qt2410_iodesc, ARRAY_SIZE(qt2410_iodesc));
s3c24xx_init_uarts(smdk2410_uartcfgs, ARRAY_SIZE(smdk2410_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init qt2410_init_time(void)
{
s3c2410_init_clocks(12000000);
samsung_timer_init();
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
WARN_ON(gpio_request_one(S3C2410_GPB(0), GPIOF_OUT_INIT_HIGH, NULL));
gpio_free(S3C2410_GPB(0));
s3c24xx_udc_set_platdata(&qt2410_udc_cfg);
s3c_i2c0_set_platdata(NULL);
WARN_ON(gpio_request(S3C2410_GPB(5), "spi cs"));
gpio_direction_output(S3C2410_GPB(5), 1);
platform_add_devices(qt2410_devices, ARRAY_SIZE(qt2410_devices));
s3c_pm_init();
}
