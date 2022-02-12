static void hp680bl_send_intensity(struct backlight_device *bd)
{
unsigned long flags;
u16 v;
int intensity = bd->props.brightness;
if (bd->props.power != FB_BLANK_UNBLANK)
intensity = 0;
if (bd->props.fb_blank != FB_BLANK_UNBLANK)
intensity = 0;
if (hp680bl_suspended)
intensity = 0;
spin_lock_irqsave(&bl_lock, flags);
if (intensity && current_intensity == 0) {
sh_dac_enable(DAC_LCD_BRIGHTNESS);
v = inw(HD64461_GPBDR);
v &= ~HD64461_GPBDR_LCDOFF;
outw(v, HD64461_GPBDR);
sh_dac_output(255-(u8)intensity, DAC_LCD_BRIGHTNESS);
} else if (intensity == 0 && current_intensity != 0) {
sh_dac_output(255-(u8)intensity, DAC_LCD_BRIGHTNESS);
sh_dac_disable(DAC_LCD_BRIGHTNESS);
v = inw(HD64461_GPBDR);
v |= HD64461_GPBDR_LCDOFF;
outw(v, HD64461_GPBDR);
} else if (intensity) {
sh_dac_output(255-(u8)intensity, DAC_LCD_BRIGHTNESS);
}
spin_unlock_irqrestore(&bl_lock, flags);
current_intensity = intensity;
}
static int hp680bl_suspend(struct device *dev)
{
struct backlight_device *bd = dev_get_drvdata(dev);
hp680bl_suspended = 1;
hp680bl_send_intensity(bd);
return 0;
}
static int hp680bl_resume(struct device *dev)
{
struct backlight_device *bd = dev_get_drvdata(dev);
hp680bl_suspended = 0;
hp680bl_send_intensity(bd);
return 0;
}
static int hp680bl_set_intensity(struct backlight_device *bd)
{
hp680bl_send_intensity(bd);
return 0;
}
static int hp680bl_get_intensity(struct backlight_device *bd)
{
return current_intensity;
}
static int hp680bl_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct backlight_device *bd;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = HP680_MAX_INTENSITY;
bd = devm_backlight_device_register(&pdev->dev, "hp680-bl", &pdev->dev,
NULL, &hp680bl_ops, &props);
if (IS_ERR(bd))
return PTR_ERR(bd);
platform_set_drvdata(pdev, bd);
bd->props.brightness = HP680_DEFAULT_INTENSITY;
hp680bl_send_intensity(bd);
return 0;
}
static int hp680bl_remove(struct platform_device *pdev)
{
struct backlight_device *bd = platform_get_drvdata(pdev);
bd->props.brightness = 0;
bd->props.power = 0;
hp680bl_send_intensity(bd);
return 0;
}
static int __init hp680bl_init(void)
{
int ret;
ret = platform_driver_register(&hp680bl_driver);
if (ret)
return ret;
hp680bl_device = platform_device_register_simple("hp680-bl", -1,
NULL, 0);
if (IS_ERR(hp680bl_device)) {
platform_driver_unregister(&hp680bl_driver);
return PTR_ERR(hp680bl_device);
}
return 0;
}
static void __exit hp680bl_exit(void)
{
platform_device_unregister(hp680bl_device);
platform_driver_unregister(&hp680bl_driver);
}
