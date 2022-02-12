static int omap3beagle_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
gpio_request(LCD_PANEL_ENABLE_GPIO, "LCD enable");
return 0;
}
static void omap3beagle_panel_cleanup(struct lcd_panel *panel)
{
gpio_free(LCD_PANEL_ENABLE_GPIO);
}
static int omap3beagle_panel_enable(struct lcd_panel *panel)
{
gpio_set_value(LCD_PANEL_ENABLE_GPIO, 1);
return 0;
}
static void omap3beagle_panel_disable(struct lcd_panel *panel)
{
gpio_set_value(LCD_PANEL_ENABLE_GPIO, 0);
}
static unsigned long omap3beagle_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int omap3beagle_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&omap3beagle_panel);
return 0;
}
static int omap3beagle_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int omap3beagle_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int omap3beagle_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init omap3beagle_panel_drv_init(void)
{
return platform_driver_register(&omap3beagle_panel_driver);
}
static void __exit omap3beagle_panel_drv_exit(void)
{
platform_driver_unregister(&omap3beagle_panel_driver);
}
