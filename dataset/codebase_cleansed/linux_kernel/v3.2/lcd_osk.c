static int osk_panel_init(struct lcd_panel *panel, struct omapfb_device *fbdev)
{
return 0;
}
static void osk_panel_cleanup(struct lcd_panel *panel)
{
}
static int osk_panel_enable(struct lcd_panel *panel)
{
omap_cfg_reg(PWL);
omap_writeb(0x01, OMAP_PWL_CLK_ENABLE);
omap_writeb(0xFF, OMAP_PWL_ENABLE);
gpio_set_value(2, 1);
return 0;
}
static void osk_panel_disable(struct lcd_panel *panel)
{
omap_writeb(0x00, OMAP_PWL_ENABLE);
omap_writeb(0x00, OMAP_PWL_CLK_ENABLE);
gpio_set_value(2, 0);
}
static unsigned long osk_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int osk_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&osk_panel);
return 0;
}
static int osk_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int osk_panel_suspend(struct platform_device *pdev, pm_message_t mesg)
{
return 0;
}
static int osk_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init osk_panel_drv_init(void)
{
return platform_driver_register(&osk_panel_driver);
}
static void __exit osk_panel_drv_cleanup(void)
{
platform_driver_unregister(&osk_panel_driver);
}
