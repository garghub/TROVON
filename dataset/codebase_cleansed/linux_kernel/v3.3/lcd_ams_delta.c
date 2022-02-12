static int ams_delta_lcd_set_power(struct lcd_device *dev, int power)
{
if (power == FB_BLANK_UNBLANK) {
if (!(ams_delta_lcd & AMS_DELTA_LCD_POWER)) {
omap_writeb(ams_delta_lcd & AMS_DELTA_MAX_CONTRAST,
OMAP_PWL_ENABLE);
omap_writeb(1, OMAP_PWL_CLK_ENABLE);
ams_delta_lcd |= AMS_DELTA_LCD_POWER;
}
} else {
if (ams_delta_lcd & AMS_DELTA_LCD_POWER) {
omap_writeb(0, OMAP_PWL_ENABLE);
omap_writeb(0, OMAP_PWL_CLK_ENABLE);
ams_delta_lcd &= ~AMS_DELTA_LCD_POWER;
}
}
return 0;
}
static int ams_delta_lcd_set_contrast(struct lcd_device *dev, int value)
{
if ((value >= 0) && (value <= AMS_DELTA_MAX_CONTRAST)) {
omap_writeb(value, OMAP_PWL_ENABLE);
ams_delta_lcd &= ~AMS_DELTA_MAX_CONTRAST;
ams_delta_lcd |= value;
}
return 0;
}
static int ams_delta_lcd_get_power(struct lcd_device *dev)
{
if (ams_delta_lcd & AMS_DELTA_LCD_POWER)
return FB_BLANK_UNBLANK;
else
return FB_BLANK_POWERDOWN;
}
static int ams_delta_lcd_get_contrast(struct lcd_device *dev)
{
if (!(ams_delta_lcd & AMS_DELTA_LCD_POWER))
return 0;
return ams_delta_lcd & AMS_DELTA_MAX_CONTRAST;
}
static int ams_delta_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
return 0;
}
static void ams_delta_panel_cleanup(struct lcd_panel *panel)
{
}
static int ams_delta_panel_enable(struct lcd_panel *panel)
{
ams_delta_latch2_write(AMS_DELTA_LATCH2_LCD_NDISP,
AMS_DELTA_LATCH2_LCD_NDISP);
ams_delta_latch2_write(AMS_DELTA_LATCH2_LCD_VBLEN,
AMS_DELTA_LATCH2_LCD_VBLEN);
return 0;
}
static void ams_delta_panel_disable(struct lcd_panel *panel)
{
ams_delta_latch2_write(AMS_DELTA_LATCH2_LCD_VBLEN, 0);
ams_delta_latch2_write(AMS_DELTA_LATCH2_LCD_NDISP, 0);
}
static unsigned long ams_delta_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int ams_delta_panel_probe(struct platform_device *pdev)
{
struct lcd_device *lcd_device = NULL;
#ifdef CONFIG_LCD_CLASS_DEVICE
int ret;
lcd_device = lcd_device_register("omapfb", &pdev->dev, NULL,
&ams_delta_lcd_ops);
if (IS_ERR(lcd_device)) {
ret = PTR_ERR(lcd_device);
dev_err(&pdev->dev, "failed to register device\n");
return ret;
}
platform_set_drvdata(pdev, lcd_device);
lcd_device->props.max_contrast = AMS_DELTA_MAX_CONTRAST;
#endif
ams_delta_lcd_set_contrast(lcd_device, AMS_DELTA_DEFAULT_CONTRAST);
ams_delta_lcd_set_power(lcd_device, FB_BLANK_UNBLANK);
omapfb_register_panel(&ams_delta_panel);
return 0;
}
static int ams_delta_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int ams_delta_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int ams_delta_panel_resume(struct platform_device *pdev)
{
return 0;
}
