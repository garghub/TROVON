static inline int pa12203001_als_enable(struct pa12203001_data *data, u8 enable)
{
int ret;
ret = regmap_update_bits(data->map, PA12203001_REG_CFG0,
PA12203001_ALS_EN_MASK, enable);
if (ret < 0)
return ret;
data->als_enabled = !!enable;
return 0;
}
static inline int pa12203001_px_enable(struct pa12203001_data *data, u8 enable)
{
int ret;
ret = regmap_update_bits(data->map, PA12203001_REG_CFG0,
PA12203001_PX_EN_MASK, enable);
if (ret < 0)
return ret;
data->px_enabled = !!enable;
return 0;
}
static int pa12203001_set_power_state(struct pa12203001_data *data, bool on,
u8 mask)
{
#ifdef CONFIG_PM
int ret;
if (on && (mask & PA12203001_ALS_EN_MASK)) {
mutex_lock(&data->lock);
if (data->px_enabled) {
ret = pa12203001_als_enable(data,
PA12203001_ALS_EN_MASK);
if (ret < 0)
goto err;
} else {
data->als_needs_enable = true;
}
mutex_unlock(&data->lock);
}
if (on && (mask & PA12203001_PX_EN_MASK)) {
mutex_lock(&data->lock);
if (data->als_enabled) {
ret = pa12203001_px_enable(data, PA12203001_PX_EN_MASK);
if (ret < 0)
goto err;
} else {
data->px_needs_enable = true;
}
mutex_unlock(&data->lock);
}
if (on) {
ret = pm_runtime_get_sync(&data->client->dev);
if (ret < 0)
pm_runtime_put_noidle(&data->client->dev);
} else {
pm_runtime_mark_last_busy(&data->client->dev);
ret = pm_runtime_put_autosuspend(&data->client->dev);
}
return ret;
err:
mutex_unlock(&data->lock);
return ret;
#endif
return 0;
}
static int pa12203001_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct pa12203001_data *data = iio_priv(indio_dev);
int ret;
u8 dev_mask;
unsigned int reg_byte;
__le16 reg_word;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_LIGHT:
dev_mask = PA12203001_ALS_EN_MASK;
ret = pa12203001_set_power_state(data, true, dev_mask);
if (ret < 0)
return ret;
ret = regmap_bulk_read(data->map, PA12203001_REG_ADL,
&reg_word, 2);
if (ret < 0)
goto reg_err;
*val = le16_to_cpu(reg_word);
ret = pa12203001_set_power_state(data, false, dev_mask);
if (ret < 0)
return ret;
break;
case IIO_PROXIMITY:
dev_mask = PA12203001_PX_EN_MASK;
ret = pa12203001_set_power_state(data, true, dev_mask);
if (ret < 0)
return ret;
ret = regmap_read(data->map, PA12203001_REG_PDH,
&reg_byte);
if (ret < 0)
goto reg_err;
*val = reg_byte;
ret = pa12203001_set_power_state(data, false, dev_mask);
if (ret < 0)
return ret;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = regmap_read(data->map, PA12203001_REG_CFG0, &reg_byte);
if (ret < 0)
return ret;
*val = 0;
reg_byte = (reg_byte & PA12203001_AFSR_MASK);
*val2 = pa12203001_scales[reg_byte >> 4];
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
reg_err:
pa12203001_set_power_state(data, false, dev_mask);
return ret;
}
static int pa12203001_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
struct pa12203001_data *data = iio_priv(indio_dev);
int i, ret, new_val;
unsigned int reg_byte;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
ret = regmap_read(data->map, PA12203001_REG_CFG0, &reg_byte);
if (val != 0 || ret < 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(pa12203001_scales); i++) {
if (val2 == pa12203001_scales[i]) {
new_val = i << PA12203001_AFSR_SHIFT;
return regmap_update_bits(data->map,
PA12203001_REG_CFG0,
PA12203001_AFSR_MASK,
new_val);
}
}
break;
default:
break;
}
return -EINVAL;
}
static int pa12203001_init(struct iio_dev *indio_dev)
{
struct pa12203001_data *data = iio_priv(indio_dev);
int i, ret;
for (i = 0; i < ARRAY_SIZE(regvals); i++) {
ret = regmap_write(data->map, regvals[i].reg, regvals[i].val);
if (ret < 0)
return ret;
}
return 0;
}
static int pa12203001_power_chip(struct iio_dev *indio_dev, u8 state)
{
struct pa12203001_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->lock);
ret = pa12203001_als_enable(data, state);
if (ret < 0)
goto out;
ret = pa12203001_px_enable(data, state);
out:
mutex_unlock(&data->lock);
return ret;
}
static int pa12203001_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pa12203001_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev,
sizeof(struct pa12203001_data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->map = devm_regmap_init_i2c(client, &pa12203001_regmap_config);
if (IS_ERR(data->map))
return PTR_ERR(data->map);
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &pa12203001_info;
indio_dev->name = PA12203001_DRIVER_NAME;
indio_dev->channels = pa12203001_channels;
indio_dev->num_channels = ARRAY_SIZE(pa12203001_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = pa12203001_init(indio_dev);
if (ret < 0)
return ret;
ret = pa12203001_power_chip(indio_dev, PA12203001_CHIP_ENABLE);
if (ret < 0)
return ret;
ret = pm_runtime_set_active(&client->dev);
if (ret < 0)
goto out_err;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
PA12203001_SLEEP_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
ret = iio_device_register(indio_dev);
if (ret < 0)
goto out_err;
return 0;
out_err:
pa12203001_power_chip(indio_dev, PA12203001_CHIP_DISABLE);
return ret;
}
static int pa12203001_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
return pa12203001_power_chip(indio_dev, PA12203001_CHIP_DISABLE);
}
static int pa12203001_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
return pa12203001_power_chip(indio_dev, PA12203001_CHIP_DISABLE);
}
static int pa12203001_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
return pa12203001_power_chip(indio_dev, PA12203001_CHIP_ENABLE);
}
static int pa12203001_runtime_resume(struct device *dev)
{
struct pa12203001_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
mutex_lock(&data->lock);
if (data->als_needs_enable) {
pa12203001_als_enable(data, PA12203001_ALS_EN_MASK);
data->als_needs_enable = false;
}
if (data->px_needs_enable) {
pa12203001_px_enable(data, PA12203001_PX_EN_MASK);
data->px_needs_enable = false;
}
mutex_unlock(&data->lock);
return 0;
}
