static void __init tavorevb_init(void)
{
mfp_config(ARRAY_AND_SIZE(tavorevb_pin_config));
pxa910_add_uart(1);
platform_device_register(&smc91x_device);
}
