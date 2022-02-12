static void __init flint_init(void)
{
mfp_config(ARRAY_AND_SIZE(flint_pin_config));
mmp2_add_uart(1);
mmp2_add_uart(2);
platform_device_add_data(&mmp2_device_gpio, &mmp2_gpio_pdata,
sizeof(struct pxa_gpio_platform_data));
platform_device_register(&mmp2_device_gpio);
platform_device_register(&smc91x_device);
}
