static void __init colibri_pxa300_init_eth(void)
{
colibri_pxa3xx_init_eth(&colibri_asix_platdata);
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa300_eth_pin_config));
platform_device_register(&asix_device);
}
static inline void __init colibri_pxa300_init_eth(void) {}
static void __init colibri_pxa300_init_lcd(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa300_lcd_pin_config));
}
static inline void colibri_pxa300_init_lcd(void) {}
static inline void __init colibri_pxa310_init_ac97(void)
{
if (!cpu_is_pxa310())
return;
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa310_ac97_pin_config));
pxa_set_ac97_info(NULL);
}
static inline void colibri_pxa310_init_ac97(void) {}
void __init colibri_pxa300_init(void)
{
colibri_pxa300_init_eth();
colibri_pxa3xx_init_nand();
colibri_pxa300_init_lcd();
colibri_pxa3xx_init_lcd(mfp_to_gpio(GPIO39_GPIO));
colibri_pxa310_init_ac97();
pxa3xx_mfp_config(ARRAY_AND_SIZE(colibri_pxa300_evalboard_pin_config));
colibri_evalboard_init();
}
