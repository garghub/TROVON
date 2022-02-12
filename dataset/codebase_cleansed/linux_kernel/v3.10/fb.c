void __init omapfb_set_lcd_config(const struct omap_lcd_config *config)
{
omapfb_config.lcd = *config;
omapfb_lcd_configured = true;
}
static int __init omap_init_fb(void)
{
if (!omapfb_lcd_configured)
return 0;
return platform_device_register(&omap_fb_device);
}
void __init omapfb_set_lcd_config(const struct omap_lcd_config *config)
{
}
