static void tosa_bl_set_backlight(struct tosa_bl_data *data, int brightness)
{
struct spi_device *spi = data->i2c->dev.platform_data;
i2c_smbus_write_byte_data(data->i2c, DAC_CH1, data->comadj);
i2c_smbus_write_byte_data(data->i2c, DAC_CH2, (u8)(brightness & 0xff));
gpio_set_value(TOSA_GPIO_BL_C20MA, brightness & 0x100);
tosa_bl_enable(spi, brightness);
}
static int tosa_bl_update_status(struct backlight_device *dev)
{
struct backlight_properties *props = &dev->props;
struct tosa_bl_data *data = bl_get_data(dev);
int power = max(props->power, props->fb_blank);
int brightness = props->brightness;
if (power)
brightness = 0;
tosa_bl_set_backlight(data, brightness);
return 0;
}
static int tosa_bl_get_brightness(struct backlight_device *dev)
{
struct backlight_properties *props = &dev->props;
return props->brightness;
}
static int tosa_bl_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct backlight_properties props;
struct tosa_bl_data *data;
int ret = 0;
data = devm_kzalloc(&client->dev, sizeof(struct tosa_bl_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->comadj = sharpsl_param.comadj == -1 ? COMADJ_DEFAULT : sharpsl_param.comadj;
ret = devm_gpio_request_one(&client->dev, TOSA_GPIO_BL_C20MA,
GPIOF_OUT_INIT_LOW, "backlight");
if (ret) {
dev_dbg(&data->bl->dev, "Unable to request gpio!\n");
return ret;
}
i2c_set_clientdata(client, data);
data->i2c = client;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = 512 - 1;
data->bl = backlight_device_register("tosa-bl", &client->dev, data,
&bl_ops, &props);
if (IS_ERR(data->bl)) {
ret = PTR_ERR(data->bl);
goto err_reg;
}
data->bl->props.brightness = 69;
data->bl->props.power = FB_BLANK_UNBLANK;
backlight_update_status(data->bl);
return 0;
err_reg:
data->bl = NULL;
return ret;
}
static int tosa_bl_remove(struct i2c_client *client)
{
struct tosa_bl_data *data = i2c_get_clientdata(client);
backlight_device_unregister(data->bl);
data->bl = NULL;
return 0;
}
static int tosa_bl_suspend(struct device *dev)
{
struct tosa_bl_data *data = dev_get_drvdata(dev);
tosa_bl_set_backlight(data, 0);
return 0;
}
static int tosa_bl_resume(struct device *dev)
{
struct tosa_bl_data *data = dev_get_drvdata(dev);
backlight_update_status(data->bl);
return 0;
}
