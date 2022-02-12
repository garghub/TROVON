static int rpr0521_als_enable(struct rpr0521_data *data, u8 status)
{
int ret;
ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
RPR0521_MODE_ALS_MASK,
status);
if (ret < 0)
return ret;
if (status & RPR0521_MODE_ALS_MASK)
data->als_dev_en = true;
else
data->als_dev_en = false;
return 0;
}
static int rpr0521_pxs_enable(struct rpr0521_data *data, u8 status)
{
int ret;
ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
RPR0521_MODE_PXS_MASK,
status);
if (ret < 0)
return ret;
if (status & RPR0521_MODE_PXS_MASK)
data->pxs_dev_en = true;
else
data->pxs_dev_en = false;
return 0;
}
static int rpr0521_set_power_state(struct rpr0521_data *data, bool on,
u8 device_mask)
{
#ifdef CONFIG_PM
int ret;
if (device_mask & RPR0521_MODE_ALS_MASK) {
data->als_ps_need_en = on;
data->als_need_dis = !on;
}
if (device_mask & RPR0521_MODE_PXS_MASK) {
data->pxs_ps_need_en = on;
data->pxs_need_dis = !on;
}
if (on) {
ret = pm_runtime_get_sync(&data->client->dev);
} else {
pm_runtime_mark_last_busy(&data->client->dev);
ret = pm_runtime_put_autosuspend(&data->client->dev);
}
if (ret < 0) {
dev_err(&data->client->dev,
"Failed: rpr0521_set_power_state for %d, ret %d\n",
on, ret);
if (on)
pm_runtime_put_noidle(&data->client->dev);
return ret;
}
if (on) {
if (data->als_ps_need_en) {
ret = rpr0521_als_enable(data, RPR0521_MODE_ALS_ENABLE);
if (ret)
return ret;
data->als_ps_need_en = false;
}
if (data->pxs_ps_need_en) {
ret = rpr0521_pxs_enable(data, RPR0521_MODE_PXS_ENABLE);
if (ret)
return ret;
data->pxs_ps_need_en = false;
}
}
#endif
return 0;
}
static int rpr0521_get_gain(struct rpr0521_data *data, int chan,
int *val, int *val2)
{
int ret, reg, idx;
ret = regmap_read(data->regmap, rpr0521_gain[chan].reg, &reg);
if (ret < 0)
return ret;
idx = (rpr0521_gain[chan].mask & reg) >> rpr0521_gain[chan].shift;
*val = rpr0521_gain[chan].gain[idx].scale;
*val2 = rpr0521_gain[chan].gain[idx].uscale;
return 0;
}
static int rpr0521_set_gain(struct rpr0521_data *data, int chan,
int val, int val2)
{
int i, idx = -EINVAL;
for (i = 0; i < rpr0521_gain[chan].size; i++)
if (val == rpr0521_gain[chan].gain[i].scale &&
val2 == rpr0521_gain[chan].gain[i].uscale) {
idx = i;
break;
}
if (idx < 0)
return idx;
return regmap_update_bits(data->regmap, rpr0521_gain[chan].reg,
rpr0521_gain[chan].mask,
idx << rpr0521_gain[chan].shift);
}
static int rpr0521_read_samp_freq(struct rpr0521_data *data,
enum iio_chan_type chan_type,
int *val, int *val2)
{
int reg, ret;
ret = regmap_read(data->regmap, RPR0521_REG_MODE_CTRL, &reg);
if (ret < 0)
return ret;
reg &= RPR0521_MODE_MEAS_TIME_MASK;
if (reg >= ARRAY_SIZE(rpr0521_samp_freq_i))
return -EINVAL;
switch (chan_type) {
case IIO_INTENSITY:
*val = rpr0521_samp_freq_i[reg].als_hz;
*val2 = rpr0521_samp_freq_i[reg].als_uhz;
return 0;
case IIO_PROXIMITY:
*val = rpr0521_samp_freq_i[reg].pxs_hz;
*val2 = rpr0521_samp_freq_i[reg].pxs_uhz;
return 0;
default:
return -EINVAL;
}
}
static int rpr0521_write_samp_freq_common(struct rpr0521_data *data,
enum iio_chan_type chan_type,
int val, int val2)
{
int i;
switch (val) {
case 0:
i = 0;
break;
case 2:
if (val2 != 500000)
return -EINVAL;
i = 11;
break;
case 10:
i = 6;
break;
default:
return -EINVAL;
}
return regmap_update_bits(data->regmap,
RPR0521_REG_MODE_CTRL,
RPR0521_MODE_MEAS_TIME_MASK,
i);
}
static int rpr0521_read_ps_offset(struct rpr0521_data *data, int *offset)
{
int ret;
__le16 buffer;
ret = regmap_bulk_read(data->regmap,
RPR0521_REG_PS_OFFSET_LSB, &buffer, sizeof(buffer));
if (ret < 0) {
dev_err(&data->client->dev, "Failed to read PS OFFSET register\n");
return ret;
}
*offset = le16_to_cpu(buffer);
return ret;
}
static int rpr0521_write_ps_offset(struct rpr0521_data *data, int offset)
{
int ret;
__le16 buffer;
buffer = cpu_to_le16(offset & 0x3ff);
ret = regmap_raw_write(data->regmap,
RPR0521_REG_PS_OFFSET_LSB, &buffer, sizeof(buffer));
if (ret < 0) {
dev_err(&data->client->dev, "Failed to write PS OFFSET register\n");
return ret;
}
return ret;
}
static int rpr0521_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct rpr0521_data *data = iio_priv(indio_dev);
int ret;
u8 device_mask;
__le16 raw_data;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type != IIO_INTENSITY && chan->type != IIO_PROXIMITY)
return -EINVAL;
device_mask = rpr0521_data_reg[chan->address].device_mask;
mutex_lock(&data->lock);
ret = rpr0521_set_power_state(data, true, device_mask);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
}
ret = regmap_bulk_read(data->regmap,
rpr0521_data_reg[chan->address].address,
&raw_data, sizeof(raw_data));
if (ret < 0) {
rpr0521_set_power_state(data, false, device_mask);
mutex_unlock(&data->lock);
return ret;
}
ret = rpr0521_set_power_state(data, false, device_mask);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
*val = le16_to_cpu(raw_data);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
mutex_lock(&data->lock);
ret = rpr0521_get_gain(data, chan->address, val, val2);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->lock);
ret = rpr0521_read_samp_freq(data, chan->type, val, val2);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_OFFSET:
mutex_lock(&data->lock);
ret = rpr0521_read_ps_offset(data, val);
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int rpr0521_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
struct rpr0521_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
mutex_lock(&data->lock);
ret = rpr0521_set_gain(data, chan->address, val, val2);
mutex_unlock(&data->lock);
return ret;
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&data->lock);
ret = rpr0521_write_samp_freq_common(data, chan->type,
val, val2);
mutex_unlock(&data->lock);
return ret;
case IIO_CHAN_INFO_OFFSET:
mutex_lock(&data->lock);
ret = rpr0521_write_ps_offset(data, val);
mutex_unlock(&data->lock);
return ret;
default:
return -EINVAL;
}
}
static int rpr0521_init(struct rpr0521_data *data)
{
int ret;
int id;
ret = regmap_read(data->regmap, RPR0521_REG_ID, &id);
if (ret < 0) {
dev_err(&data->client->dev, "Failed to read REG_ID register\n");
return ret;
}
if (id != RPR0521_MANUFACT_ID) {
dev_err(&data->client->dev, "Wrong id, got %x, expected %x\n",
id, RPR0521_MANUFACT_ID);
return -ENODEV;
}
ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
RPR0521_MODE_MEAS_TIME_MASK,
RPR0521_DEFAULT_MEAS_TIME);
if (ret) {
pr_err("regmap_update_bits returned %d\n", ret);
return ret;
}
#ifndef CONFIG_PM
ret = rpr0521_als_enable(data, RPR0521_MODE_ALS_ENABLE);
if (ret < 0)
return ret;
ret = rpr0521_pxs_enable(data, RPR0521_MODE_PXS_ENABLE);
if (ret < 0)
return ret;
#endif
return 0;
}
static int rpr0521_poweroff(struct rpr0521_data *data)
{
int ret;
ret = regmap_update_bits(data->regmap, RPR0521_REG_MODE_CTRL,
RPR0521_MODE_ALS_MASK |
RPR0521_MODE_PXS_MASK,
RPR0521_MODE_ALS_DISABLE |
RPR0521_MODE_PXS_DISABLE);
if (ret < 0)
return ret;
data->als_dev_en = false;
data->pxs_dev_en = false;
return 0;
}
static bool rpr0521_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case RPR0521_REG_MODE_CTRL:
case RPR0521_REG_ALS_CTRL:
case RPR0521_REG_PXS_CTRL:
return false;
default:
return true;
}
}
static int rpr0521_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rpr0521_data *data;
struct iio_dev *indio_dev;
struct regmap *regmap;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
regmap = devm_regmap_init_i2c(client, &rpr0521_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "regmap_init failed!\n");
return PTR_ERR(regmap);
}
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->regmap = regmap;
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &rpr0521_info;
indio_dev->name = RPR0521_DRV_NAME;
indio_dev->channels = rpr0521_channels;
indio_dev->num_channels = ARRAY_SIZE(rpr0521_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = rpr0521_init(data);
if (ret < 0) {
dev_err(&client->dev, "rpr0521 chip init failed\n");
return ret;
}
ret = pm_runtime_set_active(&client->dev);
if (ret < 0)
goto err_poweroff;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev, RPR0521_SLEEP_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
ret = iio_device_register(indio_dev);
if (ret)
goto err_pm_disable;
return 0;
err_pm_disable:
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
err_poweroff:
rpr0521_poweroff(data);
return ret;
}
static int rpr0521_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
rpr0521_poweroff(iio_priv(indio_dev));
return 0;
}
static int rpr0521_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct rpr0521_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->lock);
if (!data->als_need_dis)
data->als_ps_need_en = data->als_dev_en;
if (!data->pxs_need_dis)
data->pxs_ps_need_en = data->pxs_dev_en;
ret = rpr0521_poweroff(data);
regcache_mark_dirty(data->regmap);
mutex_unlock(&data->lock);
return ret;
}
static int rpr0521_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct rpr0521_data *data = iio_priv(indio_dev);
int ret;
regcache_sync(data->regmap);
if (data->als_ps_need_en) {
ret = rpr0521_als_enable(data, RPR0521_MODE_ALS_ENABLE);
if (ret < 0)
return ret;
data->als_ps_need_en = false;
}
if (data->pxs_ps_need_en) {
ret = rpr0521_pxs_enable(data, RPR0521_MODE_PXS_ENABLE);
if (ret < 0)
return ret;
data->pxs_ps_need_en = false;
}
msleep(100);
return 0;
}
