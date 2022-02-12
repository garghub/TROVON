static int htcherald_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
return 0;
}
static void htcherald_panel_cleanup(struct lcd_panel *panel)
{
}
static int htcherald_panel_enable(struct lcd_panel *panel)
{
return 0;
}
static void htcherald_panel_disable(struct lcd_panel *panel)
{
}
static unsigned long htcherald_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int htcherald_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&htcherald_panel_1);
return 0;
}
static int htcherald_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int htcherald_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int htcherald_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init htcherald_panel_drv_init(void)
{
return platform_driver_register(&htcherald_panel_driver);
}
static void __exit htcherald_panel_drv_cleanup(void)
{
platform_driver_unregister(&htcherald_panel_driver);
}
