static void __init common_init(void)
{
mfp_config(ARRAY_AND_SIZE(common_pin_config));
pxa168_add_uart(1);
pxa168_add_twsi(1, NULL, ARRAY_AND_SIZE(aspenite_i2c_info));
pxa168_add_ssp(1);
pxa168_add_nand(&aspenite_nand_info);
pxa168_add_fb(&aspenite_lcd_info);
pxa168_add_keypad(&aspenite_keypad_info);
platform_device_add_data(&pxa168_device_gpio, &pxa168_gpio_pdata,
sizeof(struct pxa_gpio_platform_data));
platform_device_register(&pxa168_device_gpio);
platform_device_register(&smc91x_device);
#if defined(CONFIG_USB_EHCI_MV)
pxa168_add_usb_host(&pxa168_sph_pdata);
#endif
}
