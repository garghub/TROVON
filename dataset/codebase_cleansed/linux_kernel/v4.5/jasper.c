static void __init jasper_init(void)
{
mfp_config(ARRAY_AND_SIZE(jasper_pin_config));
mmp2_add_uart(1);
mmp2_add_uart(3);
mmp2_add_twsi(1, NULL, ARRAY_AND_SIZE(jasper_twsi1_info));
platform_device_add_data(&mmp2_device_gpio, &mmp2_gpio_pdata,
sizeof(struct pxa_gpio_platform_data));
platform_device_register(&mmp2_device_gpio);
mmp2_add_sdhost(0, &mmp2_sdh_platdata_mmc0);
regulator_has_full_constraints();
}
