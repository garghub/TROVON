static int bd6107_write(struct bd6107 *bd, u8 reg, u8 data)
{
return i2c_smbus_write_byte_data(bd->client, reg, data);
}
static int bd6107_backlight_update_status(struct backlight_device *backlight)
{
struct bd6107 *bd = bl_get_data(backlight);
int brightness = backlight->props.brightness;
if (backlight->props.power != FB_BLANK_UNBLANK ||
backlight->props.fb_blank != FB_BLANK_UNBLANK ||
backlight->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK))
brightness = 0;
if (brightness) {
bd6107_write(bd, BD6107_PORTSEL, BD6107_PORTSEL_LEDM(2) |
BD6107_PORTSEL_LEDM(1) | BD6107_PORTSEL_LEDM(0));
bd6107_write(bd, BD6107_MAINCNT1, brightness);
bd6107_write(bd, BD6107_LEDCNT1, BD6107_LEDCNT1_LEDONOFF1);
} else {
gpio_set_value(bd->pdata->reset, 0);
msleep(24);
gpio_set_value(bd->pdata->reset, 1);
}
return 0;
}
static int bd6107_backlight_get_brightness(struct backlight_device *backlight)
{
return backlight->props.brightness;
}
static int bd6107_backlight_check_fb(struct backlight_device *backlight,
struct fb_info *info)
{
struct bd6107 *bd = bl_get_data(backlight);
return bd->pdata->fbdev == NULL || bd->pdata->fbdev == info->dev;
}
static int bd6107_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bd6107_platform_data *pdata = client->dev.platform_data;
struct backlight_device *backlight;
struct backlight_properties props;
struct bd6107 *bd;
int ret;
if (pdata == NULL || !pdata->reset) {
dev_err(&client->dev, "No reset GPIO in platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_warn(&client->dev,
"I2C adapter doesn't support I2C_FUNC_SMBUS_BYTE\n");
return -EIO;
}
bd = devm_kzalloc(&client->dev, sizeof(*bd), GFP_KERNEL);
if (!bd)
return -ENOMEM;
bd->client = client;
bd->pdata = pdata;
ret = devm_gpio_request_one(&client->dev, pdata->reset,
GPIOF_DIR_OUT | GPIOF_INIT_LOW, "reset");
if (ret < 0) {
dev_err(&client->dev, "unable to request reset GPIO\n");
return ret;
}
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.max_brightness = 128;
props.brightness = clamp_t(unsigned int, pdata->def_value, 0,
props.max_brightness);
backlight = backlight_device_register(dev_name(&client->dev),
&bd->client->dev, bd,
&bd6107_backlight_ops, &props);
if (IS_ERR(backlight)) {
dev_err(&client->dev, "failed to register backlight\n");
return PTR_ERR(backlight);
}
backlight_update_status(backlight);
i2c_set_clientdata(client, backlight);
return 0;
}
static int bd6107_remove(struct i2c_client *client)
{
struct backlight_device *backlight = i2c_get_clientdata(client);
backlight->props.brightness = 0;
backlight_update_status(backlight);
backlight_device_unregister(backlight);
return 0;
}
