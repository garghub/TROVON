static int sharp_ls_bl_update_status(struct backlight_device *bl)
{
struct omap_dss_device *dssdev = dev_get_drvdata(&bl->dev);
int level;
if (!dssdev->set_backlight)
return -EINVAL;
if (bl->props.fb_blank == FB_BLANK_UNBLANK &&
bl->props.power == FB_BLANK_UNBLANK)
level = bl->props.brightness;
else
level = 0;
return dssdev->set_backlight(dssdev, level);
}
static int sharp_ls_bl_get_brightness(struct backlight_device *bl)
{
if (bl->props.fb_blank == FB_BLANK_UNBLANK &&
bl->props.power == FB_BLANK_UNBLANK)
return bl->props.brightness;
return 0;
}
static int sharp_ls_panel_probe(struct omap_dss_device *dssdev)
{
struct backlight_properties props;
struct backlight_device *bl;
struct sharp_data *sd;
int r;
dssdev->panel.config = OMAP_DSS_LCD_TFT | OMAP_DSS_LCD_IVS |
OMAP_DSS_LCD_IHS;
dssdev->panel.acb = 0x28;
dssdev->panel.timings = sharp_ls_timings;
sd = kzalloc(sizeof(*sd), GFP_KERNEL);
if (!sd)
return -ENOMEM;
dev_set_drvdata(&dssdev->dev, sd);
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = dssdev->max_backlight_level;
props.type = BACKLIGHT_RAW;
bl = backlight_device_register("sharp-ls", &dssdev->dev, dssdev,
&sharp_ls_bl_ops, &props);
if (IS_ERR(bl)) {
r = PTR_ERR(bl);
kfree(sd);
return r;
}
sd->bl = bl;
bl->props.fb_blank = FB_BLANK_UNBLANK;
bl->props.power = FB_BLANK_UNBLANK;
bl->props.brightness = dssdev->max_backlight_level;
r = sharp_ls_bl_update_status(bl);
if (r < 0)
dev_err(&dssdev->dev, "failed to set lcd brightness\n");
return 0;
}
static void __exit sharp_ls_panel_remove(struct omap_dss_device *dssdev)
{
struct sharp_data *sd = dev_get_drvdata(&dssdev->dev);
struct backlight_device *bl = sd->bl;
bl->props.power = FB_BLANK_POWERDOWN;
sharp_ls_bl_update_status(bl);
backlight_device_unregister(bl);
kfree(sd);
}
static int sharp_ls_power_on(struct omap_dss_device *dssdev)
{
int r = 0;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
r = omapdss_dpi_display_enable(dssdev);
if (r)
goto err0;
msleep(50);
if (dssdev->platform_enable) {
r = dssdev->platform_enable(dssdev);
if (r)
goto err1;
}
return 0;
err1:
omapdss_dpi_display_disable(dssdev);
err0:
return r;
}
static void sharp_ls_power_off(struct omap_dss_device *dssdev)
{
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
if (dssdev->platform_disable)
dssdev->platform_disable(dssdev);
msleep(100);
omapdss_dpi_display_disable(dssdev);
}
static int sharp_ls_panel_enable(struct omap_dss_device *dssdev)
{
int r;
r = sharp_ls_power_on(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return r;
}
static void sharp_ls_panel_disable(struct omap_dss_device *dssdev)
{
sharp_ls_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static int sharp_ls_panel_suspend(struct omap_dss_device *dssdev)
{
sharp_ls_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_SUSPENDED;
return 0;
}
static int sharp_ls_panel_resume(struct omap_dss_device *dssdev)
{
int r;
r = sharp_ls_power_on(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return r;
}
static int __init sharp_ls_panel_drv_init(void)
{
return omap_dss_register_driver(&sharp_ls_driver);
}
static void __exit sharp_ls_panel_drv_exit(void)
{
omap_dss_unregister_driver(&sharp_ls_driver);
}
