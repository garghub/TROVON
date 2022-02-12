static void __init zylonite_init_wm9713_audio(void)
{
platform_device_register(&pxa_device_wm9713_audio);
}
static void __init zylonite_init_leds(void)
{
zylonite_debug_leds[0].gpio = gpio_debug_led1;
zylonite_debug_leds[1].gpio = gpio_debug_led2;
platform_device_register(&zylonite_device_leds);
}
static inline void zylonite_init_leds(void) {}
static void __init zylonite_init_lcd(void)
{
pwm_add_table(zylonite_pwm_lookup, ARRAY_SIZE(zylonite_pwm_lookup));
platform_device_register(&zylonite_backlight_device);
if (lcd_id & 0x20) {
pxa_set_fb_info(NULL, &zylonite_sharp_lcd_info);
return;
}
if (1)
zylonite_toshiba_lcd_info.modes = &toshiba_ltm035a776c_mode;
else
zylonite_toshiba_lcd_info.modes = &toshiba_ltm04c380k_mode;
pxa_set_fb_info(NULL, &zylonite_toshiba_lcd_info);
}
static inline void zylonite_init_lcd(void) {}
static void __init zylonite_init_mmc(void)
{
pxa_set_mci_info(&zylonite_mci_platform_data);
pxa3xx_set_mci2_info(&zylonite_mci2_platform_data);
if (cpu_is_pxa310())
pxa3xx_set_mci3_info(&zylonite_mci3_platform_data);
}
static inline void zylonite_init_mmc(void) {}
static void __init zylonite_init_keypad(void)
{
pxa_set_keypad_info(&zylonite_keypad_info);
}
static inline void zylonite_init_keypad(void) {}
static void __init zylonite_init_nand(void)
{
pxa3xx_set_nand_info(&zylonite_nand_info);
}
static inline void zylonite_init_nand(void) {}
static void __init zylonite_init_ohci(void)
{
pxa_set_ohci_info(&zylonite_ohci_info);
}
static inline void zylonite_init_ohci(void) {}
static void __init zylonite_init(void)
{
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
zylonite_pxa300_init();
zylonite_pxa320_init();
smc91x_resources[1].start = PXA_GPIO_TO_IRQ(gpio_eth_irq);
smc91x_resources[1].end = PXA_GPIO_TO_IRQ(gpio_eth_irq);
platform_device_register(&smc91x_device);
pxa_set_ac97_info(NULL);
zylonite_init_lcd();
zylonite_init_mmc();
zylonite_init_keypad();
zylonite_init_nand();
zylonite_init_leds();
zylonite_init_ohci();
zylonite_init_wm9713_audio();
}
