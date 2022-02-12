static int innovator1510_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
return 0;
}
static void innovator1510_panel_cleanup(struct lcd_panel *panel)
{
}
static int innovator1510_panel_enable(struct lcd_panel *panel)
{
fpga_write(0x7, OMAP1510_FPGA_LCD_PANEL_CONTROL);
return 0;
}
static void innovator1510_panel_disable(struct lcd_panel *panel)
{
fpga_write(0x0, OMAP1510_FPGA_LCD_PANEL_CONTROL);
}
static unsigned long innovator1510_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int innovator1510_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&innovator1510_panel);
return 0;
}
static int innovator1510_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int innovator1510_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int innovator1510_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init innovator1510_panel_drv_init(void)
{
return platform_driver_register(&innovator1510_panel_driver);
}
static void __exit innovator1510_panel_drv_cleanup(void)
{
platform_driver_unregister(&innovator1510_panel_driver);
}
