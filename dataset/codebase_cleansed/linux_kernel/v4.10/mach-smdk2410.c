static void __init smdk2410_map_io(void)
{
s3c24xx_init_io(smdk2410_iodesc, ARRAY_SIZE(smdk2410_iodesc));
s3c24xx_init_uarts(smdk2410_uartcfgs, ARRAY_SIZE(smdk2410_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init smdk2410_init_time(void)
{
s3c2410_init_clocks(12000000);
samsung_timer_init();
}
static void __init smdk2410_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(smdk2410_devices, ARRAY_SIZE(smdk2410_devices));
smdk_machine_init();
}
