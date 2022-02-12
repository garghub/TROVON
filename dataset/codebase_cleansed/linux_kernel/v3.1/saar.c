static void ltm022a97a_lcd_power(int on, struct fb_var_screeninfo *var)
{
static int pin_requested = 0;
struct fb_info *info = container_of(var, struct fb_info, var);
int err;
if (!pin_requested) {
err = gpio_request(GPIO_LCD_RESET, "lcd reset");
if (err) {
pr_err("failed to request gpio for LCD reset\n");
return;
}
gpio_direction_output(GPIO_LCD_RESET, 0);
pin_requested = 1;
}
if (on) {
gpio_set_value(GPIO_LCD_RESET, 0); msleep(100);
gpio_set_value(GPIO_LCD_RESET, 1); msleep(10);
pxafb_smart_queue(info, ARRAY_AND_SIZE(lcd_power_on));
pxafb_smart_queue(info, ARRAY_AND_SIZE(lcd_panel_on));
} else {
pxafb_smart_queue(info, ARRAY_AND_SIZE(lcd_panel_off));
pxafb_smart_queue(info, ARRAY_AND_SIZE(lcd_power_off));
}
err = pxafb_smart_flush(info);
if (err)
pr_err("%s: timed out\n", __func__);
}
static void ltm022a97a_update(struct fb_info *info)
{
pxafb_smart_queue(info, ARRAY_AND_SIZE(update_framedata));
pxafb_smart_flush(info);
}
static void __init saar_init_lcd(void)
{
pxa_set_fb_info(NULL, &saar_lcd_info);
}
static inline void saar_init_lcd(void) {}
static void __init saar_init_i2c(void)
{
pxa_set_i2c_info(NULL);
i2c_register_board_info(0, ARRAY_AND_SIZE(saar_i2c_info));
}
static inline void saar_init_i2c(void) {}
static void __init saar_init_onenand(void)
{
platform_device_register(&saar_device_onenand);
}
static void __init saar_init_onenand(void) {}
static void __init saar_init(void)
{
pxa3xx_mfp_config(ARRAY_AND_SIZE(saar_mfp_cfg));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_device_register(&smc91x_device);
saar_init_onenand();
saar_init_i2c();
saar_init_lcd();
}
