static void __init nexcoder_sensorboard_init(void)
{
s3c2410_gpio_setpin(S3C2410_GPE(14), 1);
s3c_gpio_cfgpin(S3C2410_GPE(14), S3C2410_GPIO_OUTPUT);
s3c2410_gpio_setpin(S3C2410_GPE(15), 1);
s3c_gpio_cfgpin(S3C2410_GPE(15), S3C2410_GPIO_OUTPUT);
s3c2410_gpio_setpin(S3C2410_GPF(1), 1);
s3c_gpio_cfgpin(S3C2410_GPF(1), S3C2410_GPIO_OUTPUT);
s3c2410_gpio_setpin(S3C2410_GPF(2), 0);
s3c_gpio_cfgpin(S3C2410_GPF(2), S3C2410_GPIO_OUTPUT);
}
static void __init nexcoder_map_io(void)
{
s3c24xx_init_io(nexcoder_iodesc, ARRAY_SIZE(nexcoder_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(nexcoder_uartcfgs, ARRAY_SIZE(nexcoder_uartcfgs));
nexcoder_sensorboard_init();
}
static void __init nexcoder_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(nexcoder_devices, ARRAY_SIZE(nexcoder_devices));
}
