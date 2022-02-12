static void __init avengers_lite_init(void)
{
mfp_config(ARRAY_AND_SIZE(avengers_lite_pin_config_V16F));
pxa168_add_uart(2);
platform_device_register(&pxa168_device_gpio);
}
