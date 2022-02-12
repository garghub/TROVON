static void __init teton_bga_init(void)
{
mfp_config(ARRAY_AND_SIZE(teton_bga_pin_config));
pxa168_add_uart(1);
pxa168_add_keypad(&teton_bga_keypad_info);
pxa168_add_twsi(0, NULL, ARRAY_AND_SIZE(teton_bga_i2c_info));
platform_device_add_data(&pxa168_device_gpio, &pxa168_gpio_pdata,
sizeof(struct pxa_gpio_platform_data));
platform_device_register(&pxa168_device_gpio);
}
