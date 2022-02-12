static int jsa1212_als_enable(struct jsa1212_data *data, u8 status)
{
int ret;
ret = regmap_update_bits(data->regmap, JSA1212_CONF_REG,
JSA1212_CONF_ALS_MASK,
status);
if (ret < 0)
return ret;
data->als_en = !!status;
return 0;
}
static int jsa1212_pxs_enable(struct jsa1212_data *data, u8 status)
{
int ret;
ret = regmap_update_bits(data->regmap, JSA1212_CONF_REG,
JSA1212_CONF_PXS_MASK,
status);
if (ret < 0)
return ret;
data->pxs_en = !!status;
return 0;
}
static int jsa1212_read_als_data(struct jsa1212_data *data,
unsigned int *val)
{
int ret;
__le16 als_data;
ret = jsa1212_als_enable(data, JSA1212_CONF_ALS_ENABLE);
if (ret < 0)
return ret;
msleep(JSA1212_ALS_DELAY_MS);
ret = regmap_bulk_read(data->regmap, JSA1212_ALS_DT1_REG, &als_data, 2);
if (ret < 0) {
dev_err(&data->client->dev, "als data read err\n");
goto als_data_read_err;
}
*val = le16_to_cpu(als_data);
als_data_read_err:
return jsa1212_als_enable(data, JSA1212_CONF_ALS_DISABLE);
}
static int jsa1212_read_pxs_data(struct jsa1212_data *data,
unsigned int *val)
{
int ret;
unsigned int pxs_data;
ret = jsa1212_pxs_enable(data, JSA1212_CONF_PXS_ENABLE);
if (ret < 0)
return ret;
msleep(JSA1212_PXS_DELAY_MS);
ret = regmap_read(data->regmap, JSA1212_PXS_DATA_REG, &pxs_data);
if (ret < 0) {
dev_err(&data->client->dev, "pxs data read err\n");
goto pxs_data_read_err;
}
*val = pxs_data & JSA1212_PXS_DATA_MASK;
pxs_data_read_err:
return jsa1212_pxs_enable(data, JSA1212_CONF_PXS_DISABLE);
}
static int jsa1212_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
struct jsa1212_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->lock);
switch (chan->type) {
case IIO_LIGHT:
ret = jsa1212_read_als_data(data, val);
break;
case IIO_PROXIMITY:
ret = jsa1212_read_pxs_data(data, val);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&data->lock);
return ret < 0 ? ret : IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_LIGHT:
*val = jsa1212_als_range_val[data->als_rng_idx];
*val2 = BIT(12);
return IIO_VAL_FRACTIONAL;
default:
break;
}
break;
default:
break;
}
return -EINVAL;
}
static int jsa1212_chip_init(struct jsa1212_data *data)
{
int ret;
ret = regmap_write(data->regmap, JSA1212_CONF_REG,
(JSA1212_CONF_PXS_SLP_50MS |
JSA1212_CONF_IRDR_200MA));
if (ret < 0)
return ret;
ret = regmap_write(data->regmap, JSA1212_INT_REG,
JSA1212_INT_ALS_PRST_4CONV);
if (ret < 0)
return ret;
data->als_rng_idx = JSA1212_ALS_RNG_0_2048;
return 0;
}
static bool jsa1212_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case JSA1212_PXS_DATA_REG:
case JSA1212_ALS_DT1_REG:
case JSA1212_ALS_DT2_REG:
case JSA1212_INT_REG:
return true;
default:
return false;
}
}
static int jsa1212_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct jsa1212_data *data;
struct iio_dev *indio_dev;
struct regmap *regmap;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
regmap = devm_regmap_init_i2c(client, &jsa1212_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Regmap initialization failed.\n");
return PTR_ERR(regmap);
}
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->regmap = regmap;
mutex_init(&data->lock);
ret = jsa1212_chip_init(data);
if (ret < 0)
return ret;
indio_dev->dev.parent = &client->dev;
indio_dev->channels = jsa1212_channels;
indio_dev->num_channels = ARRAY_SIZE(jsa1212_channels);
indio_dev->name = JSA1212_DRIVER_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &jsa1212_info;
ret = iio_device_register(indio_dev);
if (ret < 0)
dev_err(&client->dev, "%s: register device failed\n", __func__);
return ret;
}
static int jsa1212_power_off(struct jsa1212_data *data)
{
int ret;
mutex_lock(&data->lock);
ret = regmap_update_bits(data->regmap, JSA1212_CONF_REG,
JSA1212_CONF_ALS_MASK |
JSA1212_CONF_PXS_MASK,
JSA1212_CONF_ALS_DISABLE |
JSA1212_CONF_PXS_DISABLE);
if (ret < 0)
dev_err(&data->client->dev, "power off cmd failed\n");
mutex_unlock(&data->lock);
return ret;
}
static int jsa1212_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct jsa1212_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
return jsa1212_power_off(data);
}
static int jsa1212_suspend(struct device *dev)
{
struct jsa1212_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return jsa1212_power_off(data);
}
static int jsa1212_resume(struct device *dev)
{
int ret = 0;
struct jsa1212_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
mutex_lock(&data->lock);
if (data->als_en) {
ret = jsa1212_als_enable(data, JSA1212_CONF_ALS_ENABLE);
if (ret < 0) {
dev_err(dev, "als resume failed\n");
goto unlock_and_ret;
}
}
if (data->pxs_en) {
ret = jsa1212_pxs_enable(data, JSA1212_CONF_PXS_ENABLE);
if (ret < 0)
dev_err(dev, "pxs resume failed\n");
}
unlock_and_ret:
mutex_unlock(&data->lock);
return ret;
}
