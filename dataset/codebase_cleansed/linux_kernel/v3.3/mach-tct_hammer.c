static void __init tct_hammer_map_io(void)
{
s3c24xx_init_io(tct_hammer_iodesc, ARRAY_SIZE(tct_hammer_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(tct_hammer_uartcfgs, ARRAY_SIZE(tct_hammer_uartcfgs));
}
static void __init tct_hammer_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(tct_hammer_devices, ARRAY_SIZE(tct_hammer_devices));
}
