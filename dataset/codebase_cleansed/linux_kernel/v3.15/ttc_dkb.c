static void dkb_tpo_panel_power(int on)
{
int err;
u32 spi_reset = mfp_to_gpio(MFP_PIN_GPIO106);
if (on) {
err = gpio_request(spi_reset, "TPO_LCD_SPI_RESET");
if (err) {
pr_err("failed to request GPIO for TPO LCD RESET\n");
return;
}
gpio_direction_output(spi_reset, 0);
udelay(100);
gpio_set_value(spi_reset, 1);
gpio_free(spi_reset);
} else {
err = gpio_request(spi_reset, "TPO_LCD_SPI_RESET");
if (err) {
pr_err("failed to request LCD RESET gpio\n");
return;
}
gpio_set_value(spi_reset, 0);
gpio_free(spi_reset);
}
}
static void __init add_disp(void)
{
pxa_register_device(&pxa910_device_disp,
&dkb_disp_info, sizeof(dkb_disp_info));
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
pxa_register_device(&pxa910_device_fb,
&dkb_fb_info, sizeof(dkb_fb_info));
pxa_register_device(&pxa910_device_panel,
&dkb_tpo_panel_info, sizeof(dkb_tpo_panel_info));
}
static void __init ttc_dkb_init(void)
{
mfp_config(ARRAY_AND_SIZE(ttc_dkb_pin_config));
pxa910_add_uart(1);
#if IS_ENABLED(CONFIG_MTD_NAND_PXA3xx)
pxa910_add_nand(&dkb_nand_info);
#endif
pxa910_add_twsi(0, NULL, ARRAY_AND_SIZE(ttc_dkb_i2c_info));
platform_device_add_data(&pxa910_device_gpio, &pxa910_gpio_pdata,
sizeof(struct pxa_gpio_platform_data));
platform_add_devices(ARRAY_AND_SIZE(ttc_dkb_devices));
#if IS_ENABLED(CONFIG_USB_MV_UDC)
pxa168_device_u2o.dev.platform_data = &ttc_usb_pdata;
platform_device_register(&pxa168_device_u2o);
#endif
#if IS_ENABLED(CONFIG_USB_EHCI_MV_U2O)
pxa168_device_u2oehci.dev.platform_data = &ttc_usb_pdata;
platform_device_register(&pxa168_device_u2oehci);
#endif
#if IS_ENABLED(CONFIG_USB_MV_OTG)
pxa168_device_u2ootg.dev.platform_data = &ttc_usb_pdata;
platform_device_register(&pxa168_device_u2ootg);
#endif
#if IS_ENABLED(CONFIG_MMP_DISP)
add_disp();
#endif
}
