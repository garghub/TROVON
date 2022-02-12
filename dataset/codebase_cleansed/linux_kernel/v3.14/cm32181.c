static int cm32181_reg_init(struct cm32181_chip *cm32181)
{
struct i2c_client *client = cm32181->client;
int i;
s32 ret;
ret = i2c_smbus_read_word_data(client, CM32181_REG_ADDR_ID);
if (ret < 0)
return ret;
if ((ret & 0xFF) != 0x81)
return -ENODEV;
cm32181->conf_regs[CM32181_REG_ADDR_CMD] = CM32181_CMD_ALS_ENABLE |
CM32181_CMD_ALS_IT_DEFAULT | CM32181_CMD_ALS_SM_DEFAULT;
cm32181->calibscale = CM32181_CALIBSCALE_DEFAULT;
for (i = 0; i < CM32181_CONF_REG_NUM; i++) {
ret = i2c_smbus_write_word_data(client, cm32181_reg[i],
cm32181->conf_regs[i]);
if (ret < 0)
return ret;
}
return 0;
}
static int cm32181_read_als_it(struct cm32181_chip *cm32181, int *val2)
{
u16 als_it;
int i;
als_it = cm32181->conf_regs[CM32181_REG_ADDR_CMD];
als_it &= CM32181_CMD_ALS_IT_MASK;
als_it >>= CM32181_CMD_ALS_IT_SHIFT;
for (i = 0; i < ARRAY_SIZE(als_it_bits); i++) {
if (als_it == als_it_bits[i]) {
*val2 = als_it_value[i];
return IIO_VAL_INT_PLUS_MICRO;
}
}
return -EINVAL;
}
static int cm32181_write_als_it(struct cm32181_chip *cm32181, int val)
{
struct i2c_client *client = cm32181->client;
u16 als_it;
int ret, i, n;
n = ARRAY_SIZE(als_it_value);
for (i = 0; i < n; i++)
if (val <= als_it_value[i])
break;
if (i >= n)
i = n - 1;
als_it = als_it_bits[i];
als_it <<= CM32181_CMD_ALS_IT_SHIFT;
mutex_lock(&cm32181->lock);
cm32181->conf_regs[CM32181_REG_ADDR_CMD] &=
~CM32181_CMD_ALS_IT_MASK;
cm32181->conf_regs[CM32181_REG_ADDR_CMD] |=
als_it;
ret = i2c_smbus_write_word_data(client, CM32181_REG_ADDR_CMD,
cm32181->conf_regs[CM32181_REG_ADDR_CMD]);
mutex_unlock(&cm32181->lock);
return ret;
}
static int cm32181_get_lux(struct cm32181_chip *cm32181)
{
struct i2c_client *client = cm32181->client;
int ret;
int als_it;
unsigned long lux;
ret = cm32181_read_als_it(cm32181, &als_it);
if (ret < 0)
return -EINVAL;
lux = CM32181_MLUX_PER_BIT;
lux *= CM32181_MLUX_PER_BIT_BASE_IT;
lux /= als_it;
ret = i2c_smbus_read_word_data(client, CM32181_REG_ADDR_ALS);
if (ret < 0)
return ret;
lux *= ret;
lux *= cm32181->calibscale;
lux /= CM32181_CALIBSCALE_RESOLUTION;
lux /= MLUX_PER_LUX;
if (lux > 0xFFFF)
lux = 0xFFFF;
return lux;
}
static int cm32181_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct cm32181_chip *cm32181 = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
ret = cm32181_get_lux(cm32181);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBSCALE:
*val = cm32181->calibscale;
return IIO_VAL_INT;
case IIO_CHAN_INFO_INT_TIME:
ret = cm32181_read_als_it(cm32181, val2);
return ret;
}
return -EINVAL;
}
static int cm32181_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct cm32181_chip *cm32181 = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_CALIBSCALE:
cm32181->calibscale = val;
return val;
case IIO_CHAN_INFO_INT_TIME:
ret = cm32181_write_als_it(cm32181, val2);
return ret;
}
return -EINVAL;
}
static ssize_t cm32181_get_it_available(struct device *dev,
struct device_attribute *attr, char *buf)
{
int i, n, len;
n = ARRAY_SIZE(als_it_value);
for (i = 0, len = 0; i < n; i++)
len += sprintf(buf + len, "0.%06u ", als_it_value[i]);
return len + sprintf(buf + len, "\n");
}
static int cm32181_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct cm32181_chip *cm32181;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*cm32181));
if (!indio_dev) {
dev_err(&client->dev, "devm_iio_device_alloc failed\n");
return -ENOMEM;
}
cm32181 = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
cm32181->client = client;
mutex_init(&cm32181->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = cm32181_channels;
indio_dev->num_channels = ARRAY_SIZE(cm32181_channels);
indio_dev->info = &cm32181_info;
indio_dev->name = id->name;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = cm32181_reg_init(cm32181);
if (ret) {
dev_err(&client->dev,
"%s: register init failed\n",
__func__);
return ret;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&client->dev,
"%s: regist device failed\n",
__func__);
return ret;
}
return 0;
}
static int cm32181_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
return 0;
}
