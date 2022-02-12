static int adx_backlight_update_status(struct backlight_device *bldev)
{
struct adxbl *bl = bl_get_data(bldev);
u32 value;
value = bldev->props.brightness;
writel(value, bl->base + ADX_BACKLIGHT_BRIGHTNESS);
value = readl(bl->base + ADX_BACKLIGHT_CONTROL);
if (bldev->props.state & BL_CORE_FBBLANK)
value &= ~ADX_BACKLIGHT_CONTROL_ENABLE;
else
value |= ADX_BACKLIGHT_CONTROL_ENABLE;
writel(value, bl->base + ADX_BACKLIGHT_CONTROL);
return 0;
}
static int adx_backlight_get_brightness(struct backlight_device *bldev)
{
struct adxbl *bl = bl_get_data(bldev);
u32 brightness;
brightness = readl(bl->base + ADX_BACKLIGHT_BRIGHTNESS);
return brightness & 0xff;
}
static int adx_backlight_check_fb(struct backlight_device *bldev, struct fb_info *fb)
{
return 1;
}
static int __devinit adx_backlight_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct backlight_device *bldev;
struct resource *res;
struct adxbl *bl;
int ret = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENXIO;
goto out;
}
res = devm_request_mem_region(&pdev->dev, res->start,
resource_size(res), res->name);
if (!res) {
ret = -ENXIO;
goto out;
}
bl = devm_kzalloc(&pdev->dev, sizeof(*bl), GFP_KERNEL);
if (!bl) {
ret = -ENOMEM;
goto out;
}
bl->base = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!bl->base) {
ret = -ENXIO;
goto out;
}
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = 0xff;
bldev = backlight_device_register(dev_name(&pdev->dev), &pdev->dev,
bl, &adx_backlight_ops, &props);
if (IS_ERR(bldev)) {
ret = PTR_ERR(bldev);
goto out;
}
bldev->props.brightness = 0xff;
bldev->props.power = FB_BLANK_UNBLANK;
platform_set_drvdata(pdev, bldev);
out:
return ret;
}
static int __devexit adx_backlight_remove(struct platform_device *pdev)
{
struct backlight_device *bldev;
int ret = 0;
bldev = platform_get_drvdata(pdev);
bldev->props.power = FB_BLANK_UNBLANK;
bldev->props.brightness = 0xff;
backlight_update_status(bldev);
backlight_device_unregister(bldev);
platform_set_drvdata(pdev, NULL);
return ret;
}
static int adx_backlight_suspend(struct platform_device *pdev,
pm_message_t state)
{
return 0;
}
static int adx_backlight_resume(struct platform_device *pdev)
{
return 0;
}
static int __init adx_backlight_init(void)
{
return platform_driver_register(&adx_backlight_driver);
}
static void __exit adx_backlight_exit(void)
{
platform_driver_unregister(&adx_backlight_driver);
}
