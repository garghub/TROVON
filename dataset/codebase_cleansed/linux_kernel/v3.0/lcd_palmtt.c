static int palmtt_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
return 0;
}
static void palmtt_panel_cleanup(struct lcd_panel *panel)
{
}
static int palmtt_panel_enable(struct lcd_panel *panel)
{
return 0;
}
static void palmtt_panel_disable(struct lcd_panel *panel)
{
}
static unsigned long palmtt_panel_get_caps(struct lcd_panel *panel)
{
return OMAPFB_CAPS_SET_BACKLIGHT;
}
static int palmtt_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&palmtt_panel);
return 0;
}
static int palmtt_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int palmtt_panel_suspend(struct platform_device *pdev, pm_message_t mesg)
{
return 0;
}
static int palmtt_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init palmtt_panel_drv_init(void)
{
return platform_driver_register(&palmtt_panel_driver);
}
static void __exit palmtt_panel_drv_cleanup(void)
{
platform_driver_unregister(&palmtt_panel_driver);
}
