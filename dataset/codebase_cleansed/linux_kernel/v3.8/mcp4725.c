static int mcp4725_suspend(struct device *dev)
{
u8 outbuf[2];
outbuf[0] = 0x3 << 4;
outbuf[1] = 0;
return i2c_master_send(to_i2c_client(dev), outbuf, 2);
}
static int mcp4725_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct mcp4725_data *data = iio_priv(indio_dev);
u8 outbuf[2];
outbuf[0] = (data->dac_value >> 8) & 0xf;
outbuf[1] = data->dac_value & 0xff;
return i2c_master_send(to_i2c_client(dev), outbuf, 2);
}
static int mcp4725_set_value(struct iio_dev *indio_dev, int val)
{
struct mcp4725_data *data = iio_priv(indio_dev);
u8 outbuf[2];
int ret;
if (val >= (1 << 12) || val < 0)
return -EINVAL;
outbuf[0] = (val >> 8) & 0xf;
outbuf[1] = val & 0xff;
ret = i2c_master_send(data->client, outbuf, 2);
if (ret < 0)
return ret;
else if (ret != 2)
return -EIO;
else
return 0;
}
static int mcp4725_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mcp4725_data *data = iio_priv(indio_dev);
unsigned long scale_uv;
switch (mask) {
case IIO_CHAN_INFO_RAW:
*val = data->dac_value;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
scale_uv = (data->vref_mv * 1000) >> 12;
*val = scale_uv / 1000000;
*val2 = scale_uv % 1000000;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int mcp4725_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct mcp4725_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = mcp4725_set_value(indio_dev, val);
data->dac_value = val;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int mcp4725_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mcp4725_data *data;
struct iio_dev *indio_dev;
struct mcp4725_platform_data *platform_data = client->dev.platform_data;
u8 inbuf[3];
int err;
if (!platform_data || !platform_data->vref_mv) {
dev_err(&client->dev, "invalid platform data");
err = -EINVAL;
goto exit;
}
indio_dev = iio_device_alloc(sizeof(*data));
if (indio_dev == NULL) {
err = -ENOMEM;
goto exit;
}
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &mcp4725_info;
indio_dev->channels = &mcp4725_channel;
indio_dev->num_channels = 1;
indio_dev->modes = INDIO_DIRECT_MODE;
data->vref_mv = platform_data->vref_mv;
err = i2c_master_recv(client, inbuf, 3);
if (err < 0) {
dev_err(&client->dev, "failed to read DAC value");
goto exit_free_device;
}
data->dac_value = (inbuf[1] << 4) | (inbuf[2] >> 4);
err = iio_device_register(indio_dev);
if (err)
goto exit_free_device;
dev_info(&client->dev, "MCP4725 DAC registered\n");
return 0;
exit_free_device:
iio_device_free(indio_dev);
exit:
return err;
}
static int mcp4725_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_device_free(indio_dev);
return 0;
}
