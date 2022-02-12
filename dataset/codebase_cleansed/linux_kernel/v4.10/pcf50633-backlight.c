int pcf50633_bl_set_brightness_limit(struct pcf50633 *pcf, unsigned int limit)
{
struct pcf50633_bl *pcf_bl = platform_get_drvdata(pcf->bl_pdev);
if (!pcf_bl)
return -ENODEV;
pcf_bl->brightness_limit = limit & 0x3f;
backlight_update_status(pcf_bl->bl);
return 0;
}
static int pcf50633_bl_update_status(struct backlight_device *bl)
{
struct pcf50633_bl *pcf_bl = bl_get_data(bl);
unsigned int new_brightness;
if (bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK) ||
bl->props.power != FB_BLANK_UNBLANK)
new_brightness = 0;
else if (bl->props.brightness < pcf_bl->brightness_limit)
new_brightness = bl->props.brightness;
else
new_brightness = pcf_bl->brightness_limit;
if (pcf_bl->brightness == new_brightness)
return 0;
if (new_brightness) {
pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDOUT,
new_brightness);
if (!pcf_bl->brightness)
pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDENA, 1);
} else {
pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDENA, 0);
}
pcf_bl->brightness = new_brightness;
return 0;
}
static int pcf50633_bl_get_brightness(struct backlight_device *bl)
{
struct pcf50633_bl *pcf_bl = bl_get_data(bl);
return pcf_bl->brightness;
}
static int pcf50633_bl_probe(struct platform_device *pdev)
{
struct pcf50633_bl *pcf_bl;
struct device *parent = pdev->dev.parent;
struct pcf50633_platform_data *pcf50633_data = dev_get_platdata(parent);
struct pcf50633_bl_platform_data *pdata = pcf50633_data->backlight_data;
struct backlight_properties bl_props;
pcf_bl = devm_kzalloc(&pdev->dev, sizeof(*pcf_bl), GFP_KERNEL);
if (!pcf_bl)
return -ENOMEM;
memset(&bl_props, 0, sizeof(bl_props));
bl_props.type = BACKLIGHT_RAW;
bl_props.max_brightness = 0x3f;
bl_props.power = FB_BLANK_UNBLANK;
if (pdata) {
bl_props.brightness = pdata->default_brightness;
pcf_bl->brightness_limit = pdata->default_brightness_limit;
} else {
bl_props.brightness = 0x3f;
pcf_bl->brightness_limit = 0x3f;
}
pcf_bl->pcf = dev_to_pcf50633(pdev->dev.parent);
pcf_bl->bl = devm_backlight_device_register(&pdev->dev, pdev->name,
&pdev->dev, pcf_bl,
&pcf50633_bl_ops, &bl_props);
if (IS_ERR(pcf_bl->bl))
return PTR_ERR(pcf_bl->bl);
platform_set_drvdata(pdev, pcf_bl);
pcf50633_reg_write(pcf_bl->pcf, PCF50633_REG_LEDDIM, pdata->ramp_time);
pcf_bl->brightness = pcf_bl->bl->props.brightness + 1;
backlight_update_status(pcf_bl->bl);
return 0;
}
