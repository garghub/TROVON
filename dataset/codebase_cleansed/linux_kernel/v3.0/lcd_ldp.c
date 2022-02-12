static int ldp_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
gpio_request(LCD_PANEL_RESET_GPIO, "lcd reset");
gpio_request(LCD_PANEL_QVGA_GPIO, "lcd qvga");
gpio_request(LCD_PANEL_ENABLE_GPIO, "lcd panel");
gpio_request(LCD_PANEL_BACKLIGHT_GPIO, "lcd backlight");
gpio_direction_output(LCD_PANEL_QVGA_GPIO, 0);
gpio_direction_output(LCD_PANEL_RESET_GPIO, 0);
gpio_direction_output(LCD_PANEL_ENABLE_GPIO, 0);
gpio_direction_output(LCD_PANEL_BACKLIGHT_GPIO, 0);
#ifdef CONFIG_FB_OMAP_LCD_VGA
gpio_set_value(LCD_PANEL_QVGA_GPIO, 0);
#else
gpio_set_value(LCD_PANEL_QVGA_GPIO, 1);
#endif
gpio_set_value(LCD_PANEL_RESET_GPIO, 1);
return 0;
}
static void ldp_panel_cleanup(struct lcd_panel *panel)
{
gpio_free(LCD_PANEL_BACKLIGHT_GPIO);
gpio_free(LCD_PANEL_ENABLE_GPIO);
gpio_free(LCD_PANEL_QVGA_GPIO);
gpio_free(LCD_PANEL_RESET_GPIO);
}
static int ldp_panel_enable(struct lcd_panel *panel)
{
if (0 != t2_out(PM_RECEIVER, ENABLE_VPLL2_DEDICATED,
TWL4030_VPLL2_DEDICATED))
return -EIO;
if (0 != t2_out(PM_RECEIVER, ENABLE_VPLL2_DEV_GRP,
TWL4030_VPLL2_DEV_GRP))
return -EIO;
gpio_direction_output(LCD_PANEL_ENABLE_GPIO, 1);
gpio_direction_output(LCD_PANEL_BACKLIGHT_GPIO, 1);
if (0 != t2_out(PM_RECEIVER, ENABLE_VAUX3_DEDICATED,
TWL4030_VAUX3_DEDICATED))
return -EIO;
if (0 != t2_out(PM_RECEIVER, ENABLE_VAUX3_DEV_GRP,
TWL4030_VAUX3_DEV_GRP))
return -EIO;
return 0;
}
static void ldp_panel_disable(struct lcd_panel *panel)
{
gpio_direction_output(LCD_PANEL_ENABLE_GPIO, 0);
gpio_direction_output(LCD_PANEL_BACKLIGHT_GPIO, 0);
t2_out(PM_RECEIVER, 0x0, TWL4030_VPLL2_DEDICATED);
t2_out(PM_RECEIVER, 0x0, TWL4030_VPLL2_DEV_GRP);
msleep(4);
}
static unsigned long ldp_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int ldp_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&ldp_panel);
return 0;
}
static int ldp_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int ldp_panel_suspend(struct platform_device *pdev, pm_message_t mesg)
{
return 0;
}
static int ldp_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init ldp_panel_drv_init(void)
{
return platform_driver_register(&ldp_panel_driver);
}
static void __exit ldp_panel_drv_exit(void)
{
platform_driver_unregister(&ldp_panel_driver);
}
