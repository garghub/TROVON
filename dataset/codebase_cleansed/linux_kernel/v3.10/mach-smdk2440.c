static void __init smdk2440_map_io(void)
{
s3c24xx_init_io(smdk2440_iodesc, ARRAY_SIZE(smdk2440_iodesc));
s3c24xx_init_clocks(16934400);
s3c24xx_init_uarts(smdk2440_uartcfgs, ARRAY_SIZE(smdk2440_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init smdk2440_machine_init(void)
{
s3c24xx_fb_set_platdata(&smdk2440_fb_info);
s3c_i2c0_set_platdata(NULL);
platform_add_devices(smdk2440_devices, ARRAY_SIZE(smdk2440_devices));
smdk_machine_init();
}
