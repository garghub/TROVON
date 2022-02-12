static int da9052_adjust_wled_brightness(struct da9052_bl *wleds)
{
unsigned char boost_en;
unsigned char i_sink;
int ret;
boost_en = 0x3F;
i_sink = 0xFF;
if (wleds->state == DA9052_WLEDS_OFF) {
boost_en = 0x00;
i_sink = 0x00;
}
ret = da9052_reg_write(wleds->da9052, DA9052_BOOST_REG, boost_en);
if (ret < 0)
return ret;
ret = da9052_reg_write(wleds->da9052, DA9052_LED_CONT_REG, i_sink);
if (ret < 0)
return ret;
ret = da9052_reg_write(wleds->da9052, wled_bank[wleds->led_reg], 0x0);
if (ret < 0)
return ret;
usleep_range(10000, 11000);
if (wleds->brightness) {
ret = da9052_reg_write(wleds->da9052, wled_bank[wleds->led_reg],
wleds->brightness);
if (ret < 0)
return ret;
}
return 0;
}
static int da9052_backlight_update_status(struct backlight_device *bl)
{
int brightness = bl->props.brightness;
struct da9052_bl *wleds = bl_get_data(bl);
wleds->brightness = brightness;
wleds->state = DA9052_WLEDS_ON;
return da9052_adjust_wled_brightness(wleds);
}
static int da9052_backlight_get_brightness(struct backlight_device *bl)
{
struct da9052_bl *wleds = bl_get_data(bl);
return wleds->brightness;
}
static int da9052_backlight_probe(struct platform_device *pdev)
{
struct backlight_device *bl;
struct backlight_properties props;
struct da9052_bl *wleds;
wleds = devm_kzalloc(&pdev->dev, sizeof(struct da9052_bl), GFP_KERNEL);
if (!wleds)
return -ENOMEM;
wleds->da9052 = dev_get_drvdata(pdev->dev.parent);
wleds->brightness = 0;
wleds->led_reg = platform_get_device_id(pdev)->driver_data;
wleds->state = DA9052_WLEDS_OFF;
props.type = BACKLIGHT_RAW;
props.max_brightness = DA9052_MAX_BRIGHTNESS;
bl = backlight_device_register(pdev->name, wleds->da9052->dev, wleds,
&da9052_backlight_ops, &props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "Failed to register backlight\n");
return PTR_ERR(bl);
}
bl->props.max_brightness = DA9052_MAX_BRIGHTNESS;
bl->props.brightness = 0;
platform_set_drvdata(pdev, bl);
return da9052_adjust_wled_brightness(wleds);
}
static int da9052_backlight_remove(struct platform_device *pdev)
{
struct backlight_device *bl = platform_get_drvdata(pdev);
struct da9052_bl *wleds = bl_get_data(bl);
wleds->brightness = 0;
wleds->state = DA9052_WLEDS_OFF;
da9052_adjust_wled_brightness(wleds);
backlight_device_unregister(bl);
return 0;
}
