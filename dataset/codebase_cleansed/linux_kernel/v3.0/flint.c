static void __init flint_init(void)
{
mfp_config(ARRAY_AND_SIZE(flint_pin_config));
mmp2_add_uart(1);
mmp2_add_uart(2);
platform_device_register(&smc91x_device);
}
