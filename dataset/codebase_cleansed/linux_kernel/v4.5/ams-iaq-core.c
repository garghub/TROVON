static int ams_iaqcore_read_measurement(struct ams_iaqcore_data *data)
{
struct i2c_client *client = data->client;
int ret;
struct i2c_msg msg = {
.addr = client->addr,
.flags = client->flags | I2C_M_RD,
.len = AMS_IAQCORE_DATA_SIZE,
.buf = (char *) &data->buffer,
};
ret = i2c_transfer(client->adapter, &msg, 1);
return (ret == AMS_IAQCORE_DATA_SIZE) ? 0 : ret;
}
static int ams_iaqcore_get_measurement(struct ams_iaqcore_data *data)
{
int ret;
if (!time_after(jiffies, data->last_update + HZ))
return 0;
ret = ams_iaqcore_read_measurement(data);
if (ret < 0)
return ret;
data->last_update = jiffies;
return 0;
}
static int ams_iaqcore_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct ams_iaqcore_data *data = iio_priv(indio_dev);
int ret;
if (mask != IIO_CHAN_INFO_PROCESSED)
return -EINVAL;
mutex_lock(&data->lock);
ret = ams_iaqcore_get_measurement(data);
if (ret)
goto err_out;
switch (chan->address) {
case AMS_IAQCORE_VOC_CO2_IDX:
*val = 0;
*val2 = be16_to_cpu(data->buffer.co2_ppm);
ret = IIO_VAL_INT_PLUS_MICRO;
break;
case AMS_IAQCORE_VOC_RESISTANCE_IDX:
*val = be32_to_cpu(data->buffer.resistance);
ret = IIO_VAL_INT;
break;
case AMS_IAQCORE_VOC_TVOC_IDX:
*val = 0;
*val2 = be16_to_cpu(data->buffer.voc_ppb);
ret = IIO_VAL_INT_PLUS_NANO;
break;
default:
ret = -EINVAL;
}
err_out:
mutex_unlock(&data->lock);
return ret;
}
static int ams_iaqcore_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ams_iaqcore_data *data;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->last_update = jiffies - HZ;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ams_iaqcore_info,
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ams_iaqcore_channels;
indio_dev->num_channels = ARRAY_SIZE(ams_iaqcore_channels);
return devm_iio_device_register(&client->dev, indio_dev);
}
