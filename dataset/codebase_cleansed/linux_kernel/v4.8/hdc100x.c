static int hdc100x_update_config(struct hdc100x_data *data, int mask, int val)
{
int tmp = (~mask & data->config) | val;
int ret;
ret = i2c_smbus_write_word_swapped(data->client,
HDC100X_REG_CONFIG, tmp);
if (!ret)
data->config = tmp;
return ret;
}
static int hdc100x_set_it_time(struct hdc100x_data *data, int chan, int val2)
{
int shift = hdc100x_resolution_shift[chan].shift;
int ret = -EINVAL;
int i;
for (i = 0; i < ARRAY_SIZE(hdc100x_int_time[chan]); i++) {
if (val2 && val2 == hdc100x_int_time[chan][i]) {
ret = hdc100x_update_config(data,
hdc100x_resolution_shift[chan].mask << shift,
i << shift);
if (!ret)
data->adc_int_us[chan] = val2;
break;
}
}
return ret;
}
static int hdc100x_get_measurement(struct hdc100x_data *data,
struct iio_chan_spec const *chan)
{
struct i2c_client *client = data->client;
int delay = data->adc_int_us[chan->address];
int ret;
__be16 val;
ret = i2c_smbus_write_byte(client, chan->address);
if (ret < 0) {
dev_err(&client->dev, "cannot start measurement");
return ret;
}
usleep_range(delay, delay + 1000);
ret = i2c_master_recv(data->client, (char *)&val, sizeof(val));
if (ret < 0) {
dev_err(&client->dev, "cannot read sensor data\n");
return ret;
}
return be16_to_cpu(val);
}
static int hdc100x_get_heater_status(struct hdc100x_data *data)
{
return !!(data->config & HDC100X_REG_CONFIG_HEATER_EN);
}
static int hdc100x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct hdc100x_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW: {
int ret;
mutex_lock(&data->lock);
if (chan->type == IIO_CURRENT) {
*val = hdc100x_get_heater_status(data);
ret = IIO_VAL_INT;
} else {
ret = hdc100x_get_measurement(data, chan);
if (ret >= 0) {
*val = ret;
ret = IIO_VAL_INT;
}
}
mutex_unlock(&data->lock);
return ret;
}
case IIO_CHAN_INFO_INT_TIME:
*val = 0;
*val2 = data->adc_int_us[chan->address];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_TEMP) {
*val = 165000;
*val2 = 65536;
return IIO_VAL_FRACTIONAL;
} else {
*val = 100;
*val2 = 65536;
return IIO_VAL_FRACTIONAL;
}
break;
case IIO_CHAN_INFO_OFFSET:
*val = -15887;
*val2 = 515151;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int hdc100x_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct hdc100x_data *data = iio_priv(indio_dev);
int ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_INT_TIME:
if (val != 0)
return -EINVAL;
mutex_lock(&data->lock);
ret = hdc100x_set_it_time(data, chan->address, val2);
mutex_unlock(&data->lock);
return ret;
case IIO_CHAN_INFO_RAW:
if (chan->type != IIO_CURRENT || val2 != 0)
return -EINVAL;
mutex_lock(&data->lock);
ret = hdc100x_update_config(data, HDC100X_REG_CONFIG_HEATER_EN,
val ? HDC100X_REG_CONFIG_HEATER_EN : 0);
mutex_unlock(&data->lock);
return ret;
default:
return -EINVAL;
}
}
static int hdc100x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct hdc100x_data *data;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BYTE | I2C_FUNC_I2C))
return -EOPNOTSUPP;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->name = dev_name(&client->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &hdc100x_info;
indio_dev->channels = hdc100x_channels;
indio_dev->num_channels = ARRAY_SIZE(hdc100x_channels);
hdc100x_set_it_time(data, 0, hdc100x_int_time[0][0]);
hdc100x_set_it_time(data, 1, hdc100x_int_time[1][0]);
return devm_iio_device_register(&client->dev, indio_dev);
}
