static int apollon_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
return 0;
}
static void apollon_panel_cleanup(struct lcd_panel *panel)
{
}
static int apollon_panel_enable(struct lcd_panel *panel)
{
return 0;
}
static void apollon_panel_disable(struct lcd_panel *panel)
{
}
static unsigned long apollon_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int apollon_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&apollon_panel);
return 0;
}
static int apollon_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int apollon_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int apollon_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init apollon_panel_drv_init(void)
{
return platform_driver_register(&apollon_panel_driver);
}
static void __exit apollon_panel_drv_exit(void)
{
platform_driver_unregister(&apollon_panel_driver);
}
