static int dmard09_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct dmard09_data *data = iio_priv(indio_dev);
u8 buf[DMARD09_BUF_LEN];
int ret;
s16 accel;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_i2c_block_data(data->client,
DMARD09_REG_STAT,
DMARD09_BUF_LEN, buf);
if (ret < 0) {
dev_err(&data->client->dev, "Error reading reg %d\n",
DMARD09_REG_STAT);
return ret;
}
accel = get_unaligned_le16(&buf[chan->address]);
accel <<= 4;
accel >>= 7;
*val = accel;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int dmard09_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct dmard09_data *data;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev) {
dev_err(&client->dev, "iio allocation failed\n");
return -ENOMEM;
}
data = iio_priv(indio_dev);
data->client = client;
ret = i2c_smbus_read_byte_data(data->client, DMARD09_REG_CHIPID);
if (ret < 0) {
dev_err(&client->dev, "Error reading chip id %d\n", ret);
return ret;
}
if (ret != DMARD09_CHIPID) {
dev_err(&client->dev, "Invalid chip id %d\n", ret);
return -ENODEV;
}
i2c_set_clientdata(client, indio_dev);
indio_dev->dev.parent = &client->dev;
indio_dev->name = DMARD09_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = dmard09_channels;
indio_dev->num_channels = ARRAY_SIZE(dmard09_channels);
indio_dev->info = &dmard09_info;
return devm_iio_device_register(&client->dev, indio_dev);
}
