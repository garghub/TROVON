static void smdk2416_hsudc_gpio_init(void)
{
s3c_gpio_setpull(S3C2410_GPH(14), S3C_GPIO_PULL_UP);
s3c_gpio_setpull(S3C2410_GPF(2), S3C_GPIO_PULL_NONE);
s3c_gpio_cfgpin(S3C2410_GPH(14), S3C_GPIO_SFN(1));
s3c2410_modify_misccr(S3C2416_MISCCR_SEL_SUSPND, 0);
}
static void smdk2416_hsudc_gpio_uninit(void)
{
s3c2410_modify_misccr(S3C2416_MISCCR_SEL_SUSPND, 1);
s3c_gpio_setpull(S3C2410_GPH(14), S3C_GPIO_PULL_NONE);
s3c_gpio_cfgpin(S3C2410_GPH(14), S3C_GPIO_SFN(0));
}
static void s3c2416_fb_gpio_setup_24bpp(void)
{
unsigned int gpio;
for (gpio = S3C2410_GPC(1); gpio <= S3C2410_GPC(4); gpio++) {
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(2));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_NONE);
}
for (gpio = S3C2410_GPC(8); gpio <= S3C2410_GPC(15); gpio++) {
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(2));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_NONE);
}
for (gpio = S3C2410_GPD(0); gpio <= S3C2410_GPD(15); gpio++) {
s3c_gpio_cfgpin(gpio, S3C_GPIO_SFN(2));
s3c_gpio_setpull(gpio, S3C_GPIO_PULL_NONE);
}
}
static void __init smdk2416_init_time(void)
{
s3c2416_init_clocks(12000000);
samsung_timer_init();
}
static void __init smdk2416_map_io(void)
{
s3c24xx_init_io(smdk2416_iodesc, ARRAY_SIZE(smdk2416_iodesc));
s3c24xx_init_uarts(smdk2416_uartcfgs, ARRAY_SIZE(smdk2416_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init smdk2416_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
s3c_fb_set_platdata(&smdk2416_fb_platdata);
s3c_sdhci0_set_platdata(&smdk2416_hsmmc0_pdata);
s3c_sdhci1_set_platdata(&smdk2416_hsmmc1_pdata);
s3c24xx_hsudc_set_platdata(&smdk2416_hsudc_platdata);
gpio_request(S3C2410_GPB(4), "USBHost Power");
gpio_direction_output(S3C2410_GPB(4), 1);
gpio_request(S3C2410_GPB(3), "Display Power");
gpio_direction_output(S3C2410_GPB(3), 1);
gpio_request(S3C2410_GPB(1), "Display Reset");
gpio_direction_output(S3C2410_GPB(1), 1);
platform_add_devices(smdk2416_devices, ARRAY_SIZE(smdk2416_devices));
smdk_machine_init();
}
