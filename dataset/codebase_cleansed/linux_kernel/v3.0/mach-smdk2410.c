static void __init smdk2410_map_io(void)
{
s3c24xx_init_io(smdk2410_iodesc, ARRAY_SIZE(smdk2410_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(smdk2410_uartcfgs, ARRAY_SIZE(smdk2410_uartcfgs));
}
static void __init smdk2410_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(smdk2410_devices, ARRAY_SIZE(smdk2410_devices));
smdk_machine_init();
}
