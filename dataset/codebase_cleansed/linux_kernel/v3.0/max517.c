static ssize_t max517_set_value(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count, int channel)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct max517_data *data = iio_dev_get_devdata(dev_info);
struct i2c_client *client = data->client;
u8 outbuf[4];
int outbuf_size = 0;
int res;
long val;
res = strict_strtol(buf, 10, &val);
if (res)
return res;
if (val < 0 || val > 255)
return -EINVAL;
if (channel & 1) {
outbuf[outbuf_size++] = COMMAND_CHANNEL0;
outbuf[outbuf_size++] = val;
}
if (channel & 2) {
outbuf[outbuf_size++] = COMMAND_CHANNEL1;
outbuf[outbuf_size++] = val;
}
res = i2c_master_send(client, outbuf, outbuf_size);
if (res < 0)
return res;
return count;
}
static ssize_t max517_set_value_1(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return max517_set_value(dev, attr, buf, count, 1);
}
static ssize_t max517_set_value_2(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return max517_set_value(dev, attr, buf, count, 2);
}
static ssize_t max517_set_value_both(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
return max517_set_value(dev, attr, buf, count, 3);
}
static ssize_t max517_show_scale(struct device *dev,
struct device_attribute *attr,
char *buf, int channel)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct max517_data *data = iio_dev_get_devdata(dev_info);
unsigned int scale_uv = (data->vref_mv[channel - 1] * 1000) >> 8;
return sprintf(buf, "%d.%03d\n", scale_uv / 1000, scale_uv % 1000);
}
static ssize_t max517_show_scale1(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return max517_show_scale(dev, attr, buf, 1);
}
static ssize_t max517_show_scale2(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return max517_show_scale(dev, attr, buf, 2);
}
static int max517_suspend(struct i2c_client *client, pm_message_t mesg)
{
u8 outbuf = COMMAND_PD;
return i2c_master_send(client, &outbuf, 1);
}
static int max517_resume(struct i2c_client *client)
{
u8 outbuf = 0;
return i2c_master_send(client, &outbuf, 1);
}
static int max517_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max517_data *data;
struct max517_platform_data *platform_data = client->dev.platform_data;
int err;
data = kzalloc(sizeof(struct max517_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
data->client = client;
data->indio_dev = iio_allocate_device(0);
if (data->indio_dev == NULL) {
err = -ENOMEM;
goto exit_free_data;
}
data->indio_dev->dev.parent = &client->dev;
if (id->driver_data == ID_MAX517)
data->indio_dev->info = &max517_info;
else
data->indio_dev->info = &max518_info;
data->indio_dev->dev_data = (void *)(data);
data->indio_dev->modes = INDIO_DIRECT_MODE;
if (id->driver_data == ID_MAX518 || !platform_data) {
data->vref_mv[0] = data->vref_mv[1] = 5000;
} else {
data->vref_mv[0] = platform_data->vref_mv[0];
data->vref_mv[1] = platform_data->vref_mv[1];
}
err = iio_device_register(data->indio_dev);
if (err)
goto exit_free_device;
dev_info(&client->dev, "DAC registered\n");
return 0;
exit_free_device:
iio_free_device(data->indio_dev);
exit_free_data:
kfree(data);
exit:
return err;
}
static int max517_remove(struct i2c_client *client)
{
struct max517_data *data = i2c_get_clientdata(client);
iio_free_device(data->indio_dev);
kfree(data);
return 0;
}
static int __init max517_init(void)
{
return i2c_add_driver(&max517_driver);
}
static void __exit max517_exit(void)
{
i2c_del_driver(&max517_driver);
}
