static void __init nexcoder_sensorboard_init(void)
{
gpio_request_one(S3C2410_GPE(14), GPIOF_OUT_INIT_HIGH, NULL);
gpio_free(S3C2410_GPE(14));
gpio_request_one(S3C2410_GPE(15), GPIOF_OUT_INIT_HIGH, NULL);
gpio_free(S3C2410_GPE(15));
gpio_request_one(S3C2410_GPF(1), GPIOF_OUT_INIT_HIGH, NULL);
gpio_free(S3C2410_GPF(1));
gpio_request_one(S3C2410_GPF(2), GPIOF_OUT_INIT_LOW, NULL);
gpio_free(S3C2410_GPF(2));
}
static void __init nexcoder_map_io(void)
{
s3c24xx_init_io(nexcoder_iodesc, ARRAY_SIZE(nexcoder_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(nexcoder_uartcfgs, ARRAY_SIZE(nexcoder_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
nexcoder_sensorboard_init();
}
static void __init nexcoder_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(nexcoder_devices, ARRAY_SIZE(nexcoder_devices));
}
