static void __init smdk2443_map_io(void)
{
s3c24xx_init_io(smdk2443_iodesc, ARRAY_SIZE(smdk2443_iodesc));
s3c24xx_init_uarts(smdk2443_uartcfgs, ARRAY_SIZE(smdk2443_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init smdk2443_init_time(void)
{
s3c2443_init_clocks(12000000);
samsung_timer_init();
}
static void __init smdk2443_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(smdk2443_devices, ARRAY_SIZE(smdk2443_devices));
smdk_machine_init();
}
