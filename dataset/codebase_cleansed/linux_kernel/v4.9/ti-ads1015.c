static bool ads1015_is_writeable_reg(struct device *dev, unsigned int reg)
{
return (reg == ADS1015_CFG_REG);
}
static int ads1015_set_power_state(struct ads1015_data *data, bool on)
{
int ret;
struct device *dev = regmap_get_device(data->regmap);
if (on) {
ret = pm_runtime_get_sync(dev);
if (ret < 0)
pm_runtime_put_noidle(dev);
} else {
pm_runtime_mark_last_busy(dev);
ret = pm_runtime_put_autosuspend(dev);
}
return ret;
}
static
int ads1015_get_adc_result(struct ads1015_data *data, int chan, int *val)
{
int ret, pga, dr, conv_time;
bool change;
if (chan < 0 || chan >= ADS1015_CHANNELS)
return -EINVAL;
pga = data->channel_data[chan].pga;
dr = data->channel_data[chan].data_rate;
ret = regmap_update_bits_check(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_MUX_MASK |
ADS1015_CFG_PGA_MASK,
chan << ADS1015_CFG_MUX_SHIFT |
pga << ADS1015_CFG_PGA_SHIFT,
&change);
if (ret < 0)
return ret;
if (change) {
conv_time = DIV_ROUND_UP(USEC_PER_SEC, data->data_rate[dr]);
usleep_range(conv_time, conv_time + 1);
}
return regmap_read(data->regmap, ADS1015_CONV_REG, val);
}
static irqreturn_t ads1015_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ads1015_data *data = iio_priv(indio_dev);
s16 buf[8];
int chan, ret, res;
memset(buf, 0, sizeof(buf));
mutex_lock(&data->lock);
chan = find_first_bit(indio_dev->active_scan_mask,
indio_dev->masklength);
ret = ads1015_get_adc_result(data, chan, &res);
if (ret < 0) {
mutex_unlock(&data->lock);
goto err;
}
buf[0] = res;
mutex_unlock(&data->lock);
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns(indio_dev));
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ads1015_set_scale(struct ads1015_data *data, int chan,
int scale, int uscale)
{
int i, ret, rindex = -1;
for (i = 0; i < ARRAY_SIZE(ads1015_scale); i++)
if (ads1015_scale[i].scale == scale &&
ads1015_scale[i].uscale == uscale) {
rindex = i;
break;
}
if (rindex < 0)
return -EINVAL;
ret = regmap_update_bits(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_PGA_MASK,
rindex << ADS1015_CFG_PGA_SHIFT);
if (ret < 0)
return ret;
data->channel_data[chan].pga = rindex;
return 0;
}
static int ads1015_set_data_rate(struct ads1015_data *data, int chan, int rate)
{
int i, ret, rindex = -1;
for (i = 0; i < ARRAY_SIZE(ads1015_data_rate); i++)
if (data->data_rate[i] == rate) {
rindex = i;
break;
}
if (rindex < 0)
return -EINVAL;
ret = regmap_update_bits(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_DR_MASK,
rindex << ADS1015_CFG_DR_SHIFT);
if (ret < 0)
return ret;
data->channel_data[chan].data_rate = rindex;
return 0;
}
static int ads1015_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
int ret, idx;
struct ads1015_data *data = iio_priv(indio_dev);
mutex_lock(&indio_dev->mlock);
mutex_lock(&data->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW: {
int shift = chan->scan_type.shift;
if (iio_buffer_enabled(indio_dev)) {
ret = -EBUSY;
break;
}
ret = ads1015_set_power_state(data, true);
if (ret < 0)
break;
ret = ads1015_get_adc_result(data, chan->address, val);
if (ret < 0) {
ads1015_set_power_state(data, false);
break;
}
*val = sign_extend32(*val >> shift, 15 - shift);
ret = ads1015_set_power_state(data, false);
if (ret < 0)
break;
ret = IIO_VAL_INT;
break;
}
case IIO_CHAN_INFO_SCALE:
idx = data->channel_data[chan->address].pga;
*val = ads1015_scale[idx].scale;
*val2 = ads1015_scale[idx].uscale;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
case IIO_CHAN_INFO_SAMP_FREQ:
idx = data->channel_data[chan->address].data_rate;
*val = data->data_rate[idx];
ret = IIO_VAL_INT;
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&data->lock);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ads1015_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val,
int val2, long mask)
{
struct ads1015_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->lock);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
ret = ads1015_set_scale(data, chan->address, val, val2);
break;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = ads1015_set_data_rate(data, chan->address, val);
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&data->lock);
return ret;
}
static int ads1015_buffer_preenable(struct iio_dev *indio_dev)
{
return ads1015_set_power_state(iio_priv(indio_dev), true);
}
static int ads1015_buffer_postdisable(struct iio_dev *indio_dev)
{
return ads1015_set_power_state(iio_priv(indio_dev), false);
}
static int ads1015_get_channels_config_of(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ads1015_data *data = iio_priv(indio_dev);
struct device_node *node;
if (!client->dev.of_node ||
!of_get_next_child(client->dev.of_node, NULL))
return -EINVAL;
for_each_child_of_node(client->dev.of_node, node) {
u32 pval;
unsigned int channel;
unsigned int pga = ADS1015_DEFAULT_PGA;
unsigned int data_rate = ADS1015_DEFAULT_DATA_RATE;
if (of_property_read_u32(node, "reg", &pval)) {
dev_err(&client->dev, "invalid reg on %s\n",
node->full_name);
continue;
}
channel = pval;
if (channel >= ADS1015_CHANNELS) {
dev_err(&client->dev,
"invalid channel index %d on %s\n",
channel, node->full_name);
continue;
}
if (!of_property_read_u32(node, "ti,gain", &pval)) {
pga = pval;
if (pga > 6) {
dev_err(&client->dev, "invalid gain on %s\n",
node->full_name);
of_node_put(node);
return -EINVAL;
}
}
if (!of_property_read_u32(node, "ti,datarate", &pval)) {
data_rate = pval;
if (data_rate > 7) {
dev_err(&client->dev,
"invalid data_rate on %s\n",
node->full_name);
of_node_put(node);
return -EINVAL;
}
}
data->channel_data[channel].pga = pga;
data->channel_data[channel].data_rate = data_rate;
}
return 0;
}
static void ads1015_get_channels_config(struct i2c_client *client)
{
unsigned int k;
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ads1015_data *data = iio_priv(indio_dev);
struct ads1015_platform_data *pdata = dev_get_platdata(&client->dev);
if (pdata) {
memcpy(data->channel_data, pdata->channel_data,
sizeof(data->channel_data));
return;
}
#ifdef CONFIG_OF
if (!ads1015_get_channels_config_of(client))
return;
#endif
for (k = 0; k < ADS1015_CHANNELS; ++k) {
data->channel_data[k].pga = ADS1015_DEFAULT_PGA;
data->channel_data[k].data_rate = ADS1015_DEFAULT_DATA_RATE;
}
}
static int ads1015_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ads1015_data *data;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->dev.of_node = client->dev.of_node;
indio_dev->name = ADS1015_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
switch (id->driver_data) {
case ADS1015:
indio_dev->channels = ads1015_channels;
indio_dev->num_channels = ARRAY_SIZE(ads1015_channels);
indio_dev->info = &ads1015_info;
data->data_rate = (unsigned int *) &ads1015_data_rate;
break;
case ADS1115:
indio_dev->channels = ads1115_channels;
indio_dev->num_channels = ARRAY_SIZE(ads1115_channels);
indio_dev->info = &ads1115_info;
data->data_rate = (unsigned int *) &ads1115_data_rate;
break;
}
ads1015_get_channels_config(client);
data->regmap = devm_regmap_init_i2c(client, &ads1015_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "Failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
ret = iio_triggered_buffer_setup(indio_dev, NULL,
ads1015_trigger_handler,
&ads1015_buffer_setup_ops);
if (ret < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
return ret;
}
ret = pm_runtime_set_active(&client->dev);
if (ret)
goto err_buffer_cleanup;
pm_runtime_set_autosuspend_delay(&client->dev, ADS1015_SLEEP_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
pm_runtime_enable(&client->dev);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "Failed to register IIO device\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int ads1015_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ads1015_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
iio_triggered_buffer_cleanup(indio_dev);
return regmap_update_bits(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_MOD_MASK,
ADS1015_SINGLESHOT << ADS1015_CFG_MOD_SHIFT);
}
static int ads1015_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct ads1015_data *data = iio_priv(indio_dev);
return regmap_update_bits(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_MOD_MASK,
ADS1015_SINGLESHOT << ADS1015_CFG_MOD_SHIFT);
}
static int ads1015_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct ads1015_data *data = iio_priv(indio_dev);
return regmap_update_bits(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_MOD_MASK,
ADS1015_CONTINUOUS << ADS1015_CFG_MOD_SHIFT);
}
