static int mpl115_request(struct mpl115_data *data)
{
int ret = i2c_smbus_write_byte_data(data->client, MPL115_CONVERT, 0);
if (ret < 0)
return ret;
usleep_range(3000, 4000);
return 0;
}
static int mpl115_comp_pressure(struct mpl115_data *data, int *val, int *val2)
{
int ret;
u16 padc, tadc;
int a1, y1, pcomp;
unsigned kpa;
mutex_lock(&data->lock);
ret = mpl115_request(data);
if (ret < 0)
goto done;
ret = i2c_smbus_read_word_swapped(data->client, MPL115_PADC);
if (ret < 0)
goto done;
padc = ret >> 6;
ret = i2c_smbus_read_word_swapped(data->client, MPL115_TADC);
if (ret < 0)
goto done;
tadc = ret >> 6;
a1 = data->b1 + ((data->c12 * tadc) >> 11);
y1 = (data->a0 << 10) + a1 * padc;
pcomp = (y1 + ((data->b2 * (int) tadc) >> 1)) >> 9;
kpa = pcomp * (115 - 50) / 1023 + (50 << 4);
*val = kpa >> 4;
*val2 = (kpa & 15) * (1000000 >> 4);
done:
mutex_unlock(&data->lock);
return ret;
}
static int mpl115_read_temp(struct mpl115_data *data)
{
int ret;
mutex_lock(&data->lock);
ret = mpl115_request(data);
if (ret < 0)
goto done;
ret = i2c_smbus_read_word_swapped(data->client, MPL115_TADC);
done:
mutex_unlock(&data->lock);
return ret;
}
static int mpl115_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct mpl115_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
ret = mpl115_comp_pressure(data, val, val2);
if (ret < 0)
return ret;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_RAW:
ret = mpl115_read_temp(data);
if (ret < 0)
return ret;
*val = ret >> 6;
return IIO_VAL_INT;
case IIO_CHAN_INFO_OFFSET:
*val = -605;
*val2 = 750000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SCALE:
*val = -186;
*val2 = 915888;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int mpl115_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mpl115_data *data;
struct iio_dev *indio_dev;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
mutex_init(&data->lock);
i2c_set_clientdata(client, indio_dev);
indio_dev->info = &mpl115_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = mpl115_channels;
indio_dev->num_channels = ARRAY_SIZE(mpl115_channels);
ret = i2c_smbus_read_word_swapped(data->client, MPL115_A0);
if (ret < 0)
return ret;
data->a0 = ret;
ret = i2c_smbus_read_word_swapped(data->client, MPL115_B1);
if (ret < 0)
return ret;
data->b1 = ret;
ret = i2c_smbus_read_word_swapped(data->client, MPL115_B2);
if (ret < 0)
return ret;
data->b2 = ret;
ret = i2c_smbus_read_word_swapped(data->client, MPL115_C12);
if (ret < 0)
return ret;
data->c12 = ret;
return devm_iio_device_register(&client->dev, indio_dev);
}
