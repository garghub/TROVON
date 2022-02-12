static int dmard10_reset(struct i2c_client *client)
{
unsigned char buffer[7];
int ret;
ret = i2c_smbus_write_byte_data(client, DMARD10_REG_PD,
DMARD10_VALUE_PD_RST);
if (ret < 0)
return ret;
buffer[0] = DMARD10_REG_ACTR;
buffer[1] = DMARD10_MODE_STANDBY;
buffer[2] = DMARD10_MODE_READ_OTP;
buffer[3] = DMARD10_MODE_STANDBY;
buffer[4] = DMARD10_MODE_RESET_DATA_PATH;
buffer[5] = DMARD10_MODE_STANDBY;
ret = i2c_master_send(client, buffer, 6);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, DMARD10_REG_MISC2,
DMARD10_VALUE_MISC2_OSCA_EN);
if (ret < 0)
return ret;
buffer[0] = DMARD10_REG_AFEM;
buffer[1] = DMARD10_VALUE_AFEM_AFEN_NORMAL;
buffer[2] = DMARD10_VALUE_CKSEL_ODR_100_204;
buffer[3] = DMARD10_VALUE_INTC;
buffer[4] = DMARD10_VALUE_TAPNS_AVE_2;
buffer[5] = 0x00;
buffer[6] = 0x07;
ret = i2c_master_send(client, buffer, 7);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, DMARD10_REG_ACTR,
DMARD10_MODE_ACTIVE);
if (ret < 0)
return ret;
return 0;
}
static int dmard10_shutdown(struct i2c_client *client)
{
unsigned char buffer[3];
buffer[0] = DMARD10_REG_ACTR;
buffer[1] = DMARD10_MODE_STANDBY;
buffer[2] = DMARD10_MODE_OFF;
return i2c_master_send(client, buffer, 3);
}
static int dmard10_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct dmard10_data *data = iio_priv(indio_dev);
__le16 buf[4];
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_i2c_block_data(data->client,
DMARD10_REG_STADR,
sizeof(buf), (u8 *)buf);
if (ret < 0)
return ret;
ret = le16_to_cpu(buf[chan->address]);
*val = sign_extend32(ret, 12);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = dmard10_nscale;
return IIO_VAL_INT_PLUS_NANO;
default:
return -EINVAL;
}
}
static int dmard10_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct dmard10_data *data;
ret = i2c_smbus_read_byte_data(client, DMARD10_REG_STADR);
if (ret != DMARD10_VALUE_STADR)
return (ret < 0) ? ret : -ENODEV;
ret = i2c_smbus_read_byte_data(client, DMARD10_REG_STAINT);
if (ret != DMARD10_VALUE_STAINT)
return (ret < 0) ? ret : -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev) {
dev_err(&client->dev, "iio allocation failed!\n");
return -ENOMEM;
}
data = iio_priv(indio_dev);
data->client = client;
i2c_set_clientdata(client, indio_dev);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &dmard10_info;
indio_dev->name = "dmard10";
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = dmard10_channels;
indio_dev->num_channels = ARRAY_SIZE(dmard10_channels);
ret = dmard10_reset(client);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
dmard10_shutdown(client);
}
return ret;
}
static int dmard10_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return dmard10_shutdown(client);
}
static int dmard10_suspend(struct device *dev)
{
return dmard10_shutdown(to_i2c_client(dev));
}
static int dmard10_resume(struct device *dev)
{
return dmard10_reset(to_i2c_client(dev));
}
