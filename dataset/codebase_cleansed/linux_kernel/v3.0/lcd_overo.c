static int overo_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
if ((gpio_request(LCD_ENABLE, "LCD_ENABLE") == 0) &&
(gpio_direction_output(LCD_ENABLE, 1) == 0))
gpio_export(LCD_ENABLE, 0);
else
printk(KERN_ERR "could not obtain gpio for LCD_ENABLE\n");
return 0;
}
static void overo_panel_cleanup(struct lcd_panel *panel)
{
gpio_free(LCD_ENABLE);
}
static int overo_panel_enable(struct lcd_panel *panel)
{
gpio_set_value(LCD_ENABLE, 1);
return 0;
}
static void overo_panel_disable(struct lcd_panel *panel)
{
gpio_set_value(LCD_ENABLE, 0);
}
static unsigned long overo_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int overo_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&overo_panel);
return 0;
}
static int overo_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int __init overo_panel_drv_init(void)
{
return platform_driver_register(&overo_panel_driver);
}
static void __exit overo_panel_drv_exit(void)
{
platform_driver_unregister(&overo_panel_driver);
}
