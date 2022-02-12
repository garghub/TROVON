static void __init ttc_dkb_init(void)
{
mfp_config(ARRAY_AND_SIZE(ttc_dkb_pin_config));
pxa910_add_uart(1);
pxa910_add_twsi(0, NULL, ARRAY_AND_SIZE(ttc_dkb_i2c_info));
platform_add_devices(ARRAY_AND_SIZE(ttc_dkb_devices));
#ifdef CONFIG_USB_MV_UDC
pxa168_device_u2o.dev.platform_data = &ttc_usb_pdata;
platform_device_register(&pxa168_device_u2o);
#endif
#ifdef CONFIG_USB_EHCI_MV_U2O
pxa168_device_u2oehci.dev.platform_data = &ttc_usb_pdata;
platform_device_register(&pxa168_device_u2oehci);
#endif
#ifdef CONFIG_USB_MV_OTG
pxa168_device_u2ootg.dev.platform_data = &ttc_usb_pdata;
platform_device_register(&pxa168_device_u2ootg);
#endif
}
