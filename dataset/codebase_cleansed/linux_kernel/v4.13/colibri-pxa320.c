static void __init colibri_pxa320_init_eth(void)
{
colibri_pxa3xx_init_eth(&colibri_asix_platdata);
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa320_eth_pin_config));
platform_device_register(&asix_device);
}
static inline void __init colibri_pxa320_init_eth(void) {}
static void colibri_pxa320_udc_command(int cmd)
{
if (cmd == PXA2XX_UDC_CMD_CONNECT)
UP2OCR = UP2OCR_HXOE | UP2OCR_DPPUE;
else if (cmd == PXA2XX_UDC_CMD_DISCONNECT)
UP2OCR = UP2OCR_HXOE;
}
static void __init colibri_pxa320_init_udc(void)
{
pxa_set_udc_info(&colibri_pxa320_udc_info);
platform_device_register(&colibri_pxa320_gpio_vbus);
}
static inline void colibri_pxa320_init_udc(void) {}
static void __init colibri_pxa320_init_lcd(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa320_lcd_pin_config));
}
static inline void colibri_pxa320_init_lcd(void) {}
static inline void __init colibri_pxa320_init_ac97(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa320_ac97_pin_config));
pxa_set_ac97_info(NULL);
}
static inline void colibri_pxa320_init_ac97(void) {}
void __init colibri_pxa320_init(void)
{
colibri_pxa320_init_eth();
colibri_pxa3xx_init_nand();
colibri_pxa320_init_lcd();
colibri_pxa3xx_init_lcd(mfp_to_gpio(GPIO49_GPIO));
colibri_pxa320_init_ac97();
colibri_pxa320_init_udc();
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa320_evalboard_pin_config));
colibri_evalboard_init();
}
