static void __init vpac270_nor_init(void)
{
platform_device_register(&vpac270_flash);
}
static inline void vpac270_nor_init(void) {}
static void __init vpac270_onenand_init(void)
{
platform_device_register(&vpac270_onenand);
}
static void __init vpac270_onenand_init(void) {}
static void __init vpac270_mmc_init(void)
{
pxa_set_mci_info(&vpac270_mci_platform_data);
}
static inline void vpac270_mmc_init(void) {}
static void __init vpac270_keys_init(void)
{
platform_device_register(&vpac270_pxa_keys);
}
static inline void vpac270_keys_init(void) {}
static void __init vpac270_leds_init(void)
{
platform_device_register(&vpac270_leds);
}
static inline void vpac270_leds_init(void) {}
static int vpac270_ohci_init(struct device *dev)
{
UP2OCR = UP2OCR_HXS | UP2OCR_HXOE | UP2OCR_DPPDE | UP2OCR_DMPDE;
return 0;
}
static void __init vpac270_uhc_init(void)
{
pxa_set_ohci_info(&vpac270_ohci_info);
}
static inline void vpac270_uhc_init(void) {}
static void vpac270_udc_command(int cmd)
{
if (cmd == PXA2XX_UDC_CMD_CONNECT)
UP2OCR = UP2OCR_HXOE | UP2OCR_DPPUE;
else if (cmd == PXA2XX_UDC_CMD_DISCONNECT)
UP2OCR = UP2OCR_HXOE;
}
static void __init vpac270_udc_init(void)
{
pxa_set_udc_info(&vpac270_udc_info);
platform_device_register(&vpac270_gpio_vbus);
}
static inline void vpac270_udc_init(void) {}
static void __init vpac270_eth_init(void)
{
platform_device_register(&vpac270_dm9000_device);
}
static inline void vpac270_eth_init(void) {}
static void __init vpac270_ts_init(void)
{
pxa_set_ac97_info(&vpac270_ac97_pdata);
platform_device_register(&vpac270_ucb1400_device);
}
static inline void vpac270_ts_init(void) {}
static void __init vpac270_rtc_init(void)
{
i2c_register_board_info(0, ARRAY_AND_SIZE(vpac270_i2c_devs));
}
static inline void vpac270_rtc_init(void) {}
static void vpac270_lcd_power(int on, struct fb_var_screeninfo *info)
{
gpio_set_value(GPIO81_VPAC270_BKL_ON, on);
}
static void __init vpac270_lcd_init(void)
{
int ret;
ret = gpio_request(GPIO81_VPAC270_BKL_ON, "BKL-ON");
if (ret) {
pr_err("Requesting BKL-ON GPIO failed!\n");
goto err;
}
ret = gpio_direction_output(GPIO81_VPAC270_BKL_ON, 1);
if (ret) {
pr_err("Setting BKL-ON GPIO direction failed!\n");
goto err2;
}
vpac270_lcd_screen.pxafb_lcd_power = vpac270_lcd_power;
pxa_set_fb_info(NULL, &vpac270_lcd_screen);
return;
err2:
gpio_free(GPIO81_VPAC270_BKL_ON);
err:
return;
}
static inline void vpac270_lcd_init(void) {}
static void __init vpac270_ide_init(void)
{
platform_device_register(&vpac270_ide_device);
}
static inline void vpac270_ide_init(void) {}
static void __init vpac270_pmic_init(void)
{
i2c_register_board_info(1, ARRAY_AND_SIZE(vpac270_pi2c_board_info));
}
static inline void vpac270_pmic_init(void) {}
static void __init vpac270_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(vpac270_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
pxa_set_i2c_info(NULL);
pxa27x_set_i2c_power_info(NULL);
vpac270_pmic_init();
vpac270_lcd_init();
vpac270_mmc_init();
vpac270_nor_init();
vpac270_onenand_init();
vpac270_leds_init();
vpac270_keys_init();
vpac270_uhc_init();
vpac270_udc_init();
vpac270_eth_init();
vpac270_ts_init();
vpac270_rtc_init();
vpac270_ide_init();
}
