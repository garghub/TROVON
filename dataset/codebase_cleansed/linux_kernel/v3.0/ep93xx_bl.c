static int ep93xxbl_set(struct backlight_device *bl, int brightness)
{
struct ep93xxbl *ep93xxbl = bl_get_data(bl);
__raw_writel((brightness << 8) | EP93XX_MAX_COUNT, ep93xxbl->mmio);
ep93xxbl->brightness = brightness;
return 0;
}
static int ep93xxbl_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
if (bl->props.power != FB_BLANK_UNBLANK ||
bl->props.fb_blank != FB_BLANK_UNBLANK)
brightness = 0;
return ep93xxbl_set(bl, brightness);
}
static int ep93xxbl_get_brightness(struct backlight_device *bl)
{
struct ep93xxbl *ep93xxbl = bl_get_data(bl);
return ep93xxbl->brightness;
}
static int __init ep93xxbl_probe(struct platform_device *dev)
{
struct ep93xxbl *ep93xxbl;
struct backlight_device *bl;
struct backlight_properties props;
ep93xxbl = devm_kzalloc(&dev->dev, sizeof(*ep93xxbl), GFP_KERNEL);
if (!ep93xxbl)
return -ENOMEM;
ep93xxbl->mmio = EP93XX_RASTER_BRIGHTNESS;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = EP93XX_MAX_BRIGHT;
bl = backlight_device_register(dev->name, &dev->dev, ep93xxbl,
&ep93xxbl_ops, &props);
if (IS_ERR(bl))
return PTR_ERR(bl);
bl->props.brightness = EP93XX_DEF_BRIGHT;
platform_set_drvdata(dev, bl);
ep93xxbl_update_status(bl);
return 0;
}
static int ep93xxbl_remove(struct platform_device *dev)
{
struct backlight_device *bl = platform_get_drvdata(dev);
backlight_device_unregister(bl);
platform_set_drvdata(dev, NULL);
return 0;
}
static int ep93xxbl_suspend(struct platform_device *dev, pm_message_t state)
{
struct backlight_device *bl = platform_get_drvdata(dev);
return ep93xxbl_set(bl, 0);
}
static int ep93xxbl_resume(struct platform_device *dev)
{
struct backlight_device *bl = platform_get_drvdata(dev);
backlight_update_status(bl);
return 0;
}
static int __init ep93xxbl_init(void)
{
return platform_driver_register(&ep93xxbl_driver);
}
static void __exit ep93xxbl_exit(void)
{
platform_driver_unregister(&ep93xxbl_driver);
}
