static int veml6070_read(struct veml6070_data *data)
{
int ret;
u8 msb, lsb;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte(data->client1,
data->config & ~VEML6070_COMMAND_SD);
if (ret < 0)
goto out;
msleep(125 + 10);
ret = i2c_smbus_read_byte(data->client2);
if (ret < 0)
goto out;
msb = ret;
ret = i2c_smbus_read_byte(data->client1);
if (ret < 0)
goto out;
lsb = ret;
ret = i2c_smbus_write_byte(data->client1, data->config);
if (ret < 0)
goto out;
ret = (msb << 8) | lsb;
out:
mutex_unlock(&data->lock);
return ret;
}
static int veml6070_to_uv_index(unsigned val)
{
unsigned uvi[11] = {
187, 373, 560,
746, 933, 1120,
1308, 1494,
1681, 1868, 2054};
int i;
for (i = 0; i < ARRAY_SIZE(uvi); i++)
if (val <= uvi[i])
return i;
return 11;
}
static int veml6070_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct veml6070_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
ret = veml6070_read(data);
if (ret < 0)
return ret;
if (mask == IIO_CHAN_INFO_PROCESSED)
*val = veml6070_to_uv_index(ret);
else
*val = ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int veml6070_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct veml6070_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client1 = client;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &veml6070_info;
indio_dev->channels = veml6070_channels;
indio_dev->num_channels = ARRAY_SIZE(veml6070_channels);
indio_dev->name = VEML6070_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
data->client2 = i2c_new_dummy(client->adapter, VEML6070_ADDR_DATA_LSB);
if (!data->client2) {
dev_err(&client->dev, "i2c device for second chip address failed\n");
return -ENODEV;
}
data->config = VEML6070_IT_10 | VEML6070_COMMAND_RSRVD |
VEML6070_COMMAND_SD;
ret = i2c_smbus_write_byte(data->client1, data->config);
if (ret < 0)
goto fail;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto fail;
return ret;
fail:
i2c_unregister_device(data->client2);
return ret;
}
static int veml6070_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct veml6070_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
i2c_unregister_device(data->client2);
return 0;
}
