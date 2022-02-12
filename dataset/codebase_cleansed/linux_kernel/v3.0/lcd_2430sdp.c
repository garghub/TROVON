static int sdp2430_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
if (machine_is_omap_3430sdp()) {
enable_gpio = SDP3430_LCD_PANEL_ENABLE_GPIO;
backlight_gpio = SDP3430_LCD_PANEL_BACKLIGHT_GPIO;
} else {
enable_gpio = SDP2430_LCD_PANEL_ENABLE_GPIO;
backlight_gpio = SDP2430_LCD_PANEL_BACKLIGHT_GPIO;
}
gpio_request(enable_gpio, "LCD enable");
gpio_request(backlight_gpio, "LCD bl");
gpio_direction_output(enable_gpio, 0);
gpio_direction_output(backlight_gpio, 0);
return 0;
}
static void sdp2430_panel_cleanup(struct lcd_panel *panel)
{
gpio_free(backlight_gpio);
gpio_free(enable_gpio);
}
static int sdp2430_panel_enable(struct lcd_panel *panel)
{
u8 ded_val, ded_reg;
u8 grp_val, grp_reg;
if (machine_is_omap_3430sdp()) {
ded_reg = TWL4030_VAUX3_DEDICATED;
ded_val = ENABLE_VAUX3_DEDICATED;
grp_reg = TWL4030_VAUX3_DEV_GRP;
grp_val = ENABLE_VAUX3_DEV_GRP;
if (omap_rev() > OMAP3430_REV_ES1_0) {
t2_out(PM_RECEIVER, ENABLE_VPLL2_DEDICATED,
TWL4030_VPLL2_DEDICATED);
t2_out(PM_RECEIVER, ENABLE_VPLL2_DEV_GRP,
TWL4030_VPLL2_DEV_GRP);
}
} else {
ded_reg = TWL4030_VAUX2_DEDICATED;
ded_val = ENABLE_VAUX2_DEDICATED;
grp_reg = TWL4030_VAUX2_DEV_GRP;
grp_val = ENABLE_VAUX2_DEV_GRP;
}
gpio_set_value(enable_gpio, 1);
gpio_set_value(backlight_gpio, 1);
if (0 != t2_out(PM_RECEIVER, ded_val, ded_reg))
return -EIO;
if (0 != t2_out(PM_RECEIVER, grp_val, grp_reg))
return -EIO;
return 0;
}
static void sdp2430_panel_disable(struct lcd_panel *panel)
{
gpio_set_value(enable_gpio, 0);
gpio_set_value(backlight_gpio, 0);
if (omap_rev() > OMAP3430_REV_ES1_0) {
t2_out(PM_RECEIVER, 0x0, TWL4030_VPLL2_DEDICATED);
t2_out(PM_RECEIVER, 0x0, TWL4030_VPLL2_DEV_GRP);
msleep(4);
}
}
static unsigned long sdp2430_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int sdp2430_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&sdp2430_panel);
return 0;
}
static int sdp2430_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int sdp2430_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int sdp2430_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init sdp2430_panel_drv_init(void)
{
return platform_driver_register(&sdp2430_panel_driver);
}
static void __exit sdp2430_panel_drv_exit(void)
{
platform_driver_unregister(&sdp2430_panel_driver);
}
