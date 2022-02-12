static int ad7746_select_channel(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan)
{
struct ad7746_chip_info *chip = iio_priv(indio_dev);
int ret, delay;
u8 vt_setup, cap_setup;
switch (chan->type) {
case IIO_CAPACITANCE:
cap_setup = (chan->address & 0xFF) | AD7746_CAPSETUP_CAPEN;
vt_setup = chip->vt_setup & ~AD7746_VTSETUP_VTEN;
delay = ad7746_cap_filter_rate_table[(chip->config >> 3) &
0x7][1];
if (chip->capdac_set != chan->channel) {
ret = i2c_smbus_write_byte_data(chip->client,
AD7746_REG_CAPDACA,
chip->capdac[chan->channel][0]);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(chip->client,
AD7746_REG_CAPDACB,
chip->capdac[chan->channel][1]);
if (ret < 0)
return ret;
chip->capdac_set = chan->channel;
}
break;
case IIO_VOLTAGE:
case IIO_TEMP:
vt_setup = (chan->address & 0xFF) | AD7746_VTSETUP_VTEN;
cap_setup = chip->cap_setup & ~AD7746_CAPSETUP_CAPEN;
delay = ad7746_cap_filter_rate_table[(chip->config >> 6) &
0x3][1];
break;
default:
return -EINVAL;
}
if (chip->cap_setup != cap_setup) {
ret = i2c_smbus_write_byte_data(chip->client,
AD7746_REG_CAP_SETUP,
cap_setup);
if (ret < 0)
return ret;
chip->cap_setup = cap_setup;
}
if (chip->vt_setup != vt_setup) {
ret = i2c_smbus_write_byte_data(chip->client,
AD7746_REG_VT_SETUP,
vt_setup);
if (ret < 0)
return ret;
chip->vt_setup = vt_setup;
}
return delay;
}
static inline ssize_t ad7746_start_calib(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len,
u8 regval)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7746_chip_info *chip = iio_priv(indio_dev);
bool doit;
int ret, timeout = 10;
ret = strtobool(buf, &doit);
if (ret < 0)
return ret;
if (!doit)
return 0;
mutex_lock(&indio_dev->mlock);
regval |= chip->config;
ret = i2c_smbus_write_byte_data(chip->client, AD7746_REG_CFG, regval);
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
do {
msleep(20);
ret = i2c_smbus_read_byte_data(chip->client, AD7746_REG_CFG);
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
} while ((ret == regval) && timeout--);
mutex_unlock(&indio_dev->mlock);
return len;
}
static ssize_t ad7746_start_offset_calib(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
int ret = ad7746_select_channel(indio_dev,
&ad7746_channels[to_iio_dev_attr(attr)->address]);
if (ret < 0)
return ret;
return ad7746_start_calib(dev, attr, buf, len,
AD7746_CONF_MODE_OFFS_CAL);
}
static ssize_t ad7746_start_gain_calib(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
int ret = ad7746_select_channel(indio_dev,
&ad7746_channels[to_iio_dev_attr(attr)->address]);
if (ret < 0)
return ret;
return ad7746_start_calib(dev, attr, buf, len,
AD7746_CONF_MODE_GAIN_CAL);
}
static ssize_t ad7746_show_cap_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7746_chip_info *chip = iio_priv(indio_dev);
return sprintf(buf, "%d\n", ad7746_cap_filter_rate_table[
(chip->config >> 3) & 0x7][0]);
}
static ssize_t ad7746_store_cap_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7746_chip_info *chip = iio_priv(indio_dev);
u8 data;
int ret, i;
ret = kstrtou8(buf, 10, &data);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(ad7746_cap_filter_rate_table); i++)
if (data >= ad7746_cap_filter_rate_table[i][0])
break;
if (i >= ARRAY_SIZE(ad7746_cap_filter_rate_table))
i = ARRAY_SIZE(ad7746_cap_filter_rate_table) - 1;
mutex_lock(&indio_dev->mlock);
chip->config &= ~AD7746_CONF_CAPFS(0x7);
chip->config |= AD7746_CONF_CAPFS(i);
mutex_unlock(&indio_dev->mlock);
return len;
}
static ssize_t ad7746_show_vt_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7746_chip_info *chip = iio_priv(indio_dev);
return sprintf(buf, "%d\n", ad7746_vt_filter_rate_table[
(chip->config >> 6) & 0x3][0]);
}
static ssize_t ad7746_store_vt_filter_rate_setup(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7746_chip_info *chip = iio_priv(indio_dev);
u8 data;
int ret, i;
ret = kstrtou8(buf, 10, &data);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(ad7746_vt_filter_rate_table); i++)
if (data >= ad7746_vt_filter_rate_table[i][0])
break;
if (i >= ARRAY_SIZE(ad7746_vt_filter_rate_table))
i = ARRAY_SIZE(ad7746_vt_filter_rate_table) - 1;
mutex_lock(&indio_dev->mlock);
chip->config &= ~AD7746_CONF_VTFS(0x3);
chip->config |= AD7746_CONF_VTFS(i);
mutex_unlock(&indio_dev->mlock);
return len;
}
static int ad7746_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad7746_chip_info *chip = iio_priv(indio_dev);
int ret, reg;
mutex_lock(&indio_dev->mlock);
switch (mask) {
case IIO_CHAN_INFO_CALIBSCALE:
if (val != 1) {
ret = -EINVAL;
goto out;
}
val = (val2 * 1024) / 15625;
switch (chan->type) {
case IIO_CAPACITANCE:
reg = AD7746_REG_CAP_GAINH;
break;
case IIO_VOLTAGE:
reg = AD7746_REG_VOLT_GAINH;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_write_word_data(chip->client, reg, swab16(val));
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
AD7746_REG_CAP_OFFH, swab16(val));
if (ret < 0)
goto out;
ret = 0;
break;
case IIO_CHAN_INFO_OFFSET:
if ((val < 0) | (val > 43008000)) {
ret = -EINVAL;
goto out;
}
val /= 338646;
chip->capdac[chan->channel][chan->differential] = (val > 0 ?
AD7746_CAPDAC_DACP(val) | AD7746_CAPDAC_DACEN : 0);
ret = i2c_smbus_write_byte_data(chip->client,
AD7746_REG_CAPDACA,
chip->capdac[chan->channel][0]);
if (ret < 0)
goto out;
ret = i2c_smbus_write_byte_data(chip->client,
AD7746_REG_CAPDACB,
chip->capdac[chan->channel][1]);
if (ret < 0)
goto out;
chip->capdac_set = chan->channel;
ret = 0;
break;
default:
ret = -EINVAL;
}
out:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad7746_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct ad7746_chip_info *chip = iio_priv(indio_dev);
int ret, delay;
u8 regval, reg;
union {
u32 d32;
u8 d8[4];
} data;
mutex_lock(&indio_dev->mlock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
ret = ad7746_select_channel(indio_dev, chan);
if (ret < 0)
goto out;
delay = ret;
regval = chip->config | AD7746_CONF_MODE_SINGLE_CONV;
ret = i2c_smbus_write_byte_data(chip->client, AD7746_REG_CFG,
regval);
if (ret < 0)
goto out;
msleep(delay);
ret = i2c_smbus_read_i2c_block_data(chip->client,
chan->address >> 8, 3, &data.d8[1]);
if (ret < 0)
goto out;
*val = (be32_to_cpu(data.d32) & 0xFFFFFF) - 0x800000;
switch (chan->type) {
case IIO_TEMP:
*val = (*val * 125) / 256;
break;
case IIO_VOLTAGE:
if (chan->channel == 1)
*val = *val * 6;
break;
default:
break;
}
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_CALIBSCALE:
switch (chan->type) {
case IIO_CAPACITANCE:
reg = AD7746_REG_CAP_GAINH;
break;
case IIO_VOLTAGE:
reg = AD7746_REG_VOLT_GAINH;
break;
default:
ret = -EINVAL;
goto out;
}
ret = i2c_smbus_read_word_data(chip->client, reg);
if (ret < 0)
goto out;
*val = 1;
*val2 = (15625 * swab16(ret)) / 1024;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
case IIO_CHAN_INFO_CALIBBIAS:
ret = i2c_smbus_read_word_data(chip->client,
AD7746_REG_CAP_OFFH);
if (ret < 0)
goto out;
*val = swab16(ret);
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_OFFSET:
*val = AD7746_CAPDAC_DACP(chip->capdac[chan->channel]
[chan->differential]) * 338646;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_CAPACITANCE:
*val = 0;
*val2 = 488;
ret = IIO_VAL_INT_PLUS_NANO;
break;
case IIO_VOLTAGE:
*val = 1170;
*val2 = 23;
ret = IIO_VAL_FRACTIONAL_LOG2;
break;
default:
ret = -EINVAL;
break;
}
break;
default:
ret = -EINVAL;
}
out:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad7746_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ad7746_platform_data *pdata = client->dev.platform_data;
struct ad7746_chip_info *chip;
struct iio_dev *indio_dev;
int ret = 0;
unsigned char regval = 0;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
chip->client = client;
chip->capdac_set = -1;
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ad7746_info;
indio_dev->channels = ad7746_channels;
if (id->driver_data == 7746)
indio_dev->num_channels = ARRAY_SIZE(ad7746_channels);
else
indio_dev->num_channels = ARRAY_SIZE(ad7746_channels) - 2;
indio_dev->num_channels = ARRAY_SIZE(ad7746_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
if (pdata) {
if (pdata->exca_en) {
if (pdata->exca_inv_en)
regval |= AD7746_EXCSETUP_NEXCA;
else
regval |= AD7746_EXCSETUP_EXCA;
}
if (pdata->excb_en) {
if (pdata->excb_inv_en)
regval |= AD7746_EXCSETUP_NEXCB;
else
regval |= AD7746_EXCSETUP_EXCB;
}
regval |= AD7746_EXCSETUP_EXCLVL(pdata->exclvl);
} else {
dev_warn(&client->dev, "No platform data? using default\n");
regval = AD7746_EXCSETUP_EXCA | AD7746_EXCSETUP_EXCB |
AD7746_EXCSETUP_EXCLVL(3);
}
ret = i2c_smbus_write_byte_data(chip->client,
AD7746_REG_EXC_SETUP, regval);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret)
return ret;
dev_info(&client->dev, "%s capacitive sensor registered\n", id->name);
return 0;
}
static int ad7746_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return 0;
}
