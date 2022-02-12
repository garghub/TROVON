static void inline omapbl_send_intensity(int intensity)
{
omap_writeb(intensity, OMAP_PWL_ENABLE);
}
static void inline omapbl_send_enable(int enable)
{
omap_writeb(enable, OMAP_PWL_CLK_ENABLE);
}
static void omapbl_blank(struct omap_backlight *bl, int mode)
{
if (bl->pdata->set_power)
bl->pdata->set_power(bl->dev, mode);
switch (mode) {
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
omapbl_send_intensity(0);
omapbl_send_enable(0);
break;
case FB_BLANK_UNBLANK:
omapbl_send_intensity(bl->current_intensity);
omapbl_send_enable(1);
break;
}
}
static int omapbl_suspend(struct platform_device *pdev, pm_message_t state)
{
struct backlight_device *dev = platform_get_drvdata(pdev);
struct omap_backlight *bl = dev_get_drvdata(&dev->dev);
omapbl_blank(bl, FB_BLANK_POWERDOWN);
return 0;
}
static int omapbl_resume(struct platform_device *pdev)
{
struct backlight_device *dev = platform_get_drvdata(pdev);
struct omap_backlight *bl = dev_get_drvdata(&dev->dev);
omapbl_blank(bl, bl->powermode);
return 0;
}
static int omapbl_set_power(struct backlight_device *dev, int state)
{
struct omap_backlight *bl = dev_get_drvdata(&dev->dev);
omapbl_blank(bl, state);
bl->powermode = state;
return 0;
}
static int omapbl_update_status(struct backlight_device *dev)
{
struct omap_backlight *bl = dev_get_drvdata(&dev->dev);
if (bl->current_intensity != dev->props.brightness) {
if (bl->powermode == FB_BLANK_UNBLANK)
omapbl_send_intensity(dev->props.brightness);
bl->current_intensity = dev->props.brightness;
}
if (dev->props.fb_blank != bl->powermode)
omapbl_set_power(dev, dev->props.fb_blank);
return 0;
}
static int omapbl_get_intensity(struct backlight_device *dev)
{
struct omap_backlight *bl = dev_get_drvdata(&dev->dev);
return bl->current_intensity;
}
static int omapbl_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct backlight_device *dev;
struct omap_backlight *bl;
struct omap_backlight_config *pdata = pdev->dev.platform_data;
if (!pdata)
return -ENXIO;
bl = kzalloc(sizeof(struct omap_backlight), GFP_KERNEL);
if (unlikely(!bl))
return -ENOMEM;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = OMAPBL_MAX_INTENSITY;
dev = backlight_device_register("omap-bl", &pdev->dev, bl, &omapbl_ops,
&props);
if (IS_ERR(dev)) {
kfree(bl);
return PTR_ERR(dev);
}
bl->powermode = FB_BLANK_POWERDOWN;
bl->current_intensity = 0;
bl->pdata = pdata;
bl->dev = &pdev->dev;
platform_set_drvdata(pdev, dev);
omap_cfg_reg(PWL);
dev->props.fb_blank = FB_BLANK_UNBLANK;
dev->props.brightness = pdata->default_intensity;
omapbl_update_status(dev);
printk(KERN_INFO "OMAP LCD backlight initialised\n");
return 0;
}
static int omapbl_remove(struct platform_device *pdev)
{
struct backlight_device *dev = platform_get_drvdata(pdev);
struct omap_backlight *bl = dev_get_drvdata(&dev->dev);
backlight_device_unregister(dev);
kfree(bl);
return 0;
}
