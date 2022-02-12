static void __init tavorevb_init(void)
{
mfp_config(ARRAY_AND_SIZE(tavorevb_pin_config));
pxa910_add_uart(1);
platform_device_add_data(&pxa910_device_gpio, &pxa910_gpio_pdata,
sizeof(struct pxa_gpio_platform_data));
platform_device_register(&pxa910_device_gpio);
platform_device_register(&smc91x_device);
}
