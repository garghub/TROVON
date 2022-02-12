static int h4_panel_init(struct lcd_panel *panel, struct omapfb_device *fbdev)
{
return 0;
}
static void h4_panel_cleanup(struct lcd_panel *panel)
{
}
static int h4_panel_enable(struct lcd_panel *panel)
{
return 0;
}
static void h4_panel_disable(struct lcd_panel *panel)
{
}
static unsigned long h4_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int h4_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&h4_panel);
return 0;
}
static int h4_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int h4_panel_suspend(struct platform_device *pdev, pm_message_t mesg)
{
return 0;
}
static int h4_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init h4_panel_drv_init(void)
{
return platform_driver_register(&h4_panel_driver);
}
static void __exit h4_panel_drv_cleanup(void)
{
platform_driver_unregister(&h4_panel_driver);
}
