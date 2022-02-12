static void __init otom11_map_io(void)
{
s3c24xx_init_io(otom11_iodesc, ARRAY_SIZE(otom11_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(otom11_uartcfgs, ARRAY_SIZE(otom11_uartcfgs));
}
static void __init otom11_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(otom11_devices, ARRAY_SIZE(otom11_devices));
}
