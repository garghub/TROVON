static int vcnl4000_measure(struct vcnl4000_data *data, u8 req_mask,
u8 rdy_mask, u8 data_reg, int *val)
{
int tries = 20;
__be16 buf;
int ret;
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte_data(data->client, VCNL4000_COMMAND,
req_mask);
if (ret < 0)
goto fail;
while (tries--) {
ret = i2c_smbus_read_byte_data(data->client, VCNL4000_COMMAND);
if (ret < 0)
goto fail;
if (ret & rdy_mask)
break;
msleep(20);
}
if (tries < 0) {
dev_err(&data->client->dev,
"vcnl4000_measure() failed, data not ready\n");
ret = -EIO;
goto fail;
}
ret = i2c_smbus_read_i2c_block_data(data->client,
data_reg, sizeof(buf), (u8 *) &buf);
if (ret < 0)
goto fail;
mutex_unlock(&data->lock);
*val = be16_to_cpu(buf);
return 0;
fail:
mutex_unlock(&data->lock);
return ret;
}
static int vcnl4000_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
struct vcnl4000_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_LIGHT:
ret = vcnl4000_measure(data,
VCNL4000_AL_OD, VCNL4000_AL_RDY,
VCNL4000_AL_RESULT_HI, val);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_PROXIMITY:
ret = vcnl4000_measure(data,
VCNL4000_PS_OD, VCNL4000_PS_RDY,
VCNL4000_PS_RESULT_HI, val);
if (ret < 0)
return ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
if (chan->type != IIO_LIGHT)
return -EINVAL;
*val = 0;
*val2 = 250000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int vcnl4000_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct vcnl4000_data *data;
struct iio_dev *indio_dev;
int ret, prod_id;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
ret = i2c_smbus_read_byte_data(data->client, VCNL4000_PROD_REV);
if (ret < 0)
return ret;
prod_id = ret >> 4;
if (prod_id != VCNL4010_ID && prod_id != VCNL4000_ID)
return -ENODEV;
dev_dbg(&client->dev, "%s Ambient light/proximity sensor, Rev: %02x\n",
(prod_id == VCNL4010_ID) ? "VCNL4010/4020" : "VCNL4000",
ret & 0xf);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &vcnl4000_info;
indio_dev->channels = vcnl4000_channels;
indio_dev->num_channels = ARRAY_SIZE(vcnl4000_channels);
indio_dev->name = VCNL4000_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
return devm_iio_device_register(&client->dev, indio_dev);
}
