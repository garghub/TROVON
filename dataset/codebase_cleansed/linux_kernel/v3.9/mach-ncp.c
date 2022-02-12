static void __init ncp_map_io(void)
{
s3c64xx_init_io(ncp_iodesc, ARRAY_SIZE(ncp_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(ncp_uartcfgs, ARRAY_SIZE(ncp_uartcfgs));
}
static void __init ncp_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(ncp_devices, ARRAY_SIZE(ncp_devices));
}
