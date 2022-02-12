static inline ssize_t ad7152_start_calib(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len,
u8 regval)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
bool doit;
int ret, timeout = 10;
ret = strtobool(buf, &doit);
if (ret < 0)
return ret;
if (!doit)
return 0;
if (this_attr->address == 0)
regval |= AD7152_CONF_CH1EN;
else
regval |= AD7152_CONF_CH2EN;
mutex_lock(&indio_dev->mlock);
ret = i2c_smbus_write_byte_data(chip->client, AD7152_REG_CFG, regval);
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
do {
mdelay(20);
ret = i2c_smbus_read_byte_data(chip->client, AD7152_REG_CFG);
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
} while ((ret == regval) && timeout--);
mutex_unlock(&indio_dev->mlock);
return len;
}
static ssize_t ad7152_start_offset_calib(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
return ad7152_start_calib(dev, attr, buf, len,
AD7152_CONF_MODE_OFFS_CAL);
}
static ssize_t ad7152_start_gain_calib(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
return ad7152_start_calib(dev, attr, buf, len,
AD7152_CONF_MODE_GAIN_CAL);
}
static ssize_t ad7152_show_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(indio_dev);
return sprintf(buf, "%d\n",
ad7152_filter_rate_table[chip->filter_rate_setup][0]);
}
static ssize_t ad7152_store_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad7152_chip_info *chip = iio_priv(indio_dev);
u8 data;
int ret, i;
ret = kstrtou8(buf, 10, &data);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(ad7152_filter_rate_table); i++)
if (data >= ad7152_filter_rate_table[i][0])
break;
if (i >= ARRAY_SIZE(ad7152_filter_rate_table))
i = ARRAY_SIZE(ad7152_filter_rate_table) - 1;
mutex_lock(&indio_dev->mlock);
ret = i2c_smbus_write_byte_data(chip->client,
AD7152_REG_CFG2, AD7152_CFG2_OSR(i));
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
chip->filter_rate_setup = i;
mutex_unlock(&indio_dev->mlock);
return len;
}
static int ad7152_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad7152_chip_info *chip = iio_priv(indio_dev);
int ret, i;
mutex_lock(&indio_dev->mlock);
switch (mask) {
case IIO_CHAN_INFO_CALIBSCALE:
if (val != 1) {
ret = -EINVAL;
goto out;
}
val = (val2 * 1024) / 15625;
ret = i2c_smbus_write_word_data(chip->client,
ad7152_addresses[chan->channel][AD7152_GAIN],
swab16(val));
if (ret < 0)
goto out;
ret = 0;
break;
case IIO_CHAN_INFO_CALIBBIAS:
if ((val < 0) | (val > 0xFFFF)) {
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_word_data(chip->client,
ad7152_addresses[chan->channel][AD7152_OFFS],
swab16(val));
if (ret < 0)
goto out;
ret = 0;
break;
case IIO_CHAN_INFO_SCALE:
if (val != 0) {
ret = -EINVAL;
goto out;
}
for (i = 0; i < ARRAY_SIZE(ad7152_scale_table); i++)
if (val2 == ad7152_scale_table[i])
break;
chip->setup[chan->channel] &= ~AD7152_SETUP_RANGE_4pF;
chip->setup[chan->channel] |= AD7152_SETUP_RANGE(i);
ret = i2c_smbus_write_byte_data(chip->client,
ad7152_addresses[chan->channel][AD7152_SETUP],
chip->setup[chan->channel]);
if (ret < 0)
goto out;
ret = 0;
break;
default:
ret = -EINVAL;
}
out:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad7152_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct ad7152_chip_info *chip = iio_priv(indio_dev);
int ret;
u8 regval = 0;
mutex_lock(&indio_dev->mlock);
switch (mask) {
case 0:
regval = chip->setup[chan->channel];
if (chan->differential)
chip->setup[chan->channel] |= AD7152_SETUP_CAPDIFF;
else
chip->setup[chan->channel] &= ~AD7152_SETUP_CAPDIFF;
if (regval != chip->setup[chan->channel]) {
ret = i2c_smbus_write_byte_data(chip->client,
ad7152_addresses[chan->channel][AD7152_SETUP],
chip->setup[chan->channel]);
if (ret < 0)
goto out;
}
if (chan->channel == 0)
regval = AD7152_CONF_CH1EN;
else
regval = AD7152_CONF_CH2EN;
regval |= AD7152_CONF_MODE_SINGLE_CONV;
ret = i2c_smbus_write_byte_data(chip->client, AD7152_REG_CFG,
regval);
if (ret < 0)
goto out;
msleep(ad7152_filter_rate_table[chip->filter_rate_setup][1]);
ret = i2c_smbus_read_word_data(chip->client,
ad7152_addresses[chan->channel][AD7152_DATA]);
if (ret < 0)
goto out;
*val = swab16(ret);
if (chan->differential)
*val -= 0x8000;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_CALIBSCALE:
ret = i2c_smbus_read_word_data(chip->client,
ad7152_addresses[chan->channel][AD7152_GAIN]);
if (ret < 0)
goto out;
*val = 1;
*val2 = (15625 * swab16(ret)) / 1024;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
case IIO_CHAN_INFO_CALIBBIAS:
ret = i2c_smbus_read_word_data(chip->client,
ad7152_addresses[chan->channel][AD7152_OFFS]);
if (ret < 0)
goto out;
*val = swab16(ret);
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
ret = i2c_smbus_read_byte_data(chip->client,
ad7152_addresses[chan->channel][AD7152_SETUP]);
if (ret < 0)
goto out;
*val = 0;
*val2 = ad7152_scale_table[ret >> 6];
ret = IIO_VAL_INT_PLUS_NANO;
break;
default:
ret = -EINVAL;
};
out:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad7152_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
switch (mask) {
case IIO_CHAN_INFO_SCALE:
return IIO_VAL_INT_PLUS_NANO;
default:
return IIO_VAL_INT_PLUS_MICRO;
}
}
static int __devinit ad7152_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret = 0;
struct ad7152_chip_info *chip;
struct iio_dev *indio_dev;
indio_dev = iio_allocate_device(sizeof(*chip));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
chip->client = client;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ad7152_info;
indio_dev->channels = ad7152_channels;
if (id->driver_data == 0)
indio_dev->num_channels = ARRAY_SIZE(ad7152_channels);
else
indio_dev->num_channels = 2;
indio_dev->num_channels = ARRAY_SIZE(ad7152_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
dev_err(&client->dev, "%s capacitive sensor registered\n", id->name);
return 0;
error_free_dev:
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int __devexit ad7152_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_free_device(indio_dev);
return 0;
}
