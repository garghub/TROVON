static int gpio_backlight_update_status(struct backlight_device *bl)
{
struct gpio_backlight *gbl = bl_get_data(bl);
int brightness = bl->props.brightness;
if (bl->props.power != FB_BLANK_UNBLANK ||
bl->props.fb_blank != FB_BLANK_UNBLANK ||
bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK))
brightness = 0;
gpio_set_value(gbl->gpio, brightness ? gbl->active : !gbl->active);
return 0;
}
static int gpio_backlight_get_brightness(struct backlight_device *bl)
{
return bl->props.brightness;
}
static int gpio_backlight_check_fb(struct backlight_device *bl,
struct fb_info *info)
{
struct gpio_backlight *gbl = bl_get_data(bl);
return gbl->fbdev == NULL || gbl->fbdev == info->dev;
}
static int gpio_backlight_probe(struct platform_device *pdev)
{
struct gpio_backlight_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct backlight_properties props;
struct backlight_device *bl;
struct gpio_backlight *gbl;
int ret;
if (!pdata) {
dev_err(&pdev->dev, "failed to find platform data\n");
return -ENODEV;
}
gbl = devm_kzalloc(&pdev->dev, sizeof(*gbl), GFP_KERNEL);
if (gbl == NULL)
return -ENOMEM;
gbl->dev = &pdev->dev;
gbl->fbdev = pdata->fbdev;
gbl->gpio = pdata->gpio;
gbl->active = pdata->active_low ? 0 : 1;
ret = devm_gpio_request_one(gbl->dev, gbl->gpio, GPIOF_DIR_OUT |
(gbl->active ? GPIOF_INIT_LOW
: GPIOF_INIT_HIGH),
pdata->name);
if (ret < 0) {
dev_err(&pdev->dev, "unable to request GPIO\n");
return ret;
}
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.max_brightness = 1;
bl = devm_backlight_device_register(&pdev->dev, dev_name(&pdev->dev),
&pdev->dev, gbl, &gpio_backlight_ops,
&props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "failed to register backlight\n");
return PTR_ERR(bl);
}
bl->props.brightness = pdata->def_value;
backlight_update_status(bl);
platform_set_drvdata(pdev, bl);
return 0;
}
