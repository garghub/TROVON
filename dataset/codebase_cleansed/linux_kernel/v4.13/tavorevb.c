static void __init tavorevb_init_keypad(void)
{
pxa_set_keypad_info(&tavorevb_keypad_info);
}
static inline void tavorevb_init_keypad(void) {}
static void ltm020d550_lcd_power(int on, struct fb_var_screeninfo *var)
{
struct fb_info *info = container_of(var, struct fb_info, var);
if (on) {
pxafb_smart_queue(info, ARRAY_AND_SIZE(panel_init));
pxafb_smart_queue(info, ARRAY_AND_SIZE(panel_on));
} else {
pxafb_smart_queue(info, ARRAY_AND_SIZE(panel_off));
}
if (pxafb_smart_flush(info))
pr_err("%s: timed out\n", __func__);
}
static void ltm020d550_update(struct fb_info *info)
{
pxafb_smart_queue(info, ARRAY_AND_SIZE(update_framedata));
pxafb_smart_flush(info);
}
static void __init tavorevb_init_lcd(void)
{
pwm_add_table(tavorevb_pwm_lookup, ARRAY_SIZE(tavorevb_pwm_lookup));
platform_device_register(&tavorevb_backlight_devices[0]);
platform_device_register(&tavorevb_backlight_devices[1]);
pxa_set_fb_info(NULL, &tavorevb_lcd_info);
}
static inline void tavorevb_init_lcd(void) {}
static void __init tavorevb_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(tavorevb_mfp_cfg));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_device_register(&smc91x_device);
tavorevb_init_lcd();
tavorevb_init_keypad();
}
