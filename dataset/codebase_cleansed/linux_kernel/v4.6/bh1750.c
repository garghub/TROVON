static int bh1750_change_int_time(struct bh1750_data *data, int usec)
{
int ret;
u16 val;
u8 regval;
const struct bh1750_chip_info *chip_info = data->chip_info;
if ((usec % chip_info->mtreg_to_usec) != 0)
return -EINVAL;
val = usec / chip_info->mtreg_to_usec;
if (val < chip_info->mtreg_min || val > chip_info->mtreg_max)
return -EINVAL;
ret = i2c_smbus_write_byte(data->client, BH1750_POWER_DOWN);
if (ret < 0)
return ret;
regval = (val & chip_info->int_time_high_mask) >> 5;
ret = i2c_smbus_write_byte(data->client,
BH1750_CHANGE_INT_TIME_H_BIT | regval);
if (ret < 0)
return ret;
regval = val & chip_info->int_time_low_mask;
ret = i2c_smbus_write_byte(data->client,
BH1750_CHANGE_INT_TIME_L_BIT | regval);
if (ret < 0)
return ret;
data->mtreg = val;
return 0;
}
static int bh1750_read(struct bh1750_data *data, int *val)
{
int ret;
__be16 result;
const struct bh1750_chip_info *chip_info = data->chip_info;
unsigned long delay = chip_info->mtreg_to_usec * data->mtreg;
ret = i2c_smbus_write_byte(data->client, BH1750_ONE_TIME_H_RES_MODE);
if (ret < 0)
return ret;
usleep_range(delay + 15000, delay + 40000);
ret = i2c_master_recv(data->client, (char *)&result, 2);
if (ret < 0)
return ret;
*val = be16_to_cpu(result);
return 0;
}
static int bh1750_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret, tmp;
struct bh1750_data *data = iio_priv(indio_dev);
const struct bh1750_chip_info *chip_info = data->chip_info;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_LIGHT:
mutex_lock(&data->lock);
ret = bh1750_read(data, val);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_SCALE:
tmp = chip_info->mtreg_to_scale / data->mtreg;
*val = tmp / 1000000;
*val2 = tmp % 1000000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_INT_TIME:
*val = 0;
*val2 = chip_info->mtreg_to_usec * data->mtreg;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int bh1750_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int ret;
struct bh1750_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_INT_TIME:
if (val != 0)
return -EINVAL;
mutex_lock(&data->lock);
ret = bh1750_change_int_time(data, val2);
mutex_unlock(&data->lock);
return ret;
default:
return -EINVAL;
}
}
static ssize_t bh1750_show_int_time_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
int i;
size_t len = 0;
struct bh1750_data *data = iio_priv(dev_to_iio_dev(dev));
const struct bh1750_chip_info *chip_info = data->chip_info;
for (i = chip_info->mtreg_min; i <= chip_info->mtreg_max; i += chip_info->inc)
len += scnprintf(buf + len, PAGE_SIZE - len, "0.%06d ",
chip_info->mtreg_to_usec * i);
buf[len - 1] = '\n';
return len;
}
static int bh1750_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret, usec;
struct bh1750_data *data;
struct iio_dev *indio_dev;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
I2C_FUNC_SMBUS_WRITE_BYTE))
return -EOPNOTSUPP;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->chip_info = &bh1750_chip_info_tbl[id->driver_data];
usec = data->chip_info->mtreg_to_usec * data->chip_info->mtreg_default;
ret = bh1750_change_int_time(data, usec);
if (ret < 0)
return ret;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &bh1750_info;
indio_dev->name = id->name;
indio_dev->channels = bh1750_channels;
indio_dev->num_channels = ARRAY_SIZE(bh1750_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
return iio_device_register(indio_dev);
}
static int bh1750_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct bh1750_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
mutex_lock(&data->lock);
i2c_smbus_write_byte(client, BH1750_POWER_DOWN);
mutex_unlock(&data->lock);
return 0;
}
static int bh1750_suspend(struct device *dev)
{
int ret;
struct bh1750_data *data =
iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
mutex_lock(&data->lock);
ret = i2c_smbus_write_byte(data->client, BH1750_POWER_DOWN);
mutex_unlock(&data->lock);
return ret;
}
