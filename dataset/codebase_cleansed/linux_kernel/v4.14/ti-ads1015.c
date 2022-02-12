static bool ads1015_event_channel_enabled(struct ads1015_data *data)
{
return (data->event_channel != ADS1015_CHANNELS);
}
static void ads1015_event_channel_enable(struct ads1015_data *data, int chan,
int comp_mode)
{
WARN_ON(ads1015_event_channel_enabled(data));
data->event_channel = chan;
data->comp_mode = comp_mode;
}
static void ads1015_event_channel_disable(struct ads1015_data *data, int chan)
{
data->event_channel = ADS1015_CHANNELS;
}
static bool ads1015_is_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case ADS1015_CFG_REG:
case ADS1015_LO_THRESH_REG:
case ADS1015_HI_THRESH_REG:
return true;
default:
return false;
}
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
return ret < 0 ? ret : 0;
}
static
int ads1015_get_adc_result(struct ads1015_data *data, int chan, int *val)
{
int ret, pga, dr, conv_time;
unsigned int old, mask, cfg;
if (chan < 0 || chan >= ADS1015_CHANNELS)
return -EINVAL;
ret = regmap_read(data->regmap, ADS1015_CFG_REG, &old);
if (ret)
return ret;
pga = data->channel_data[chan].pga;
dr = data->channel_data[chan].data_rate;
mask = ADS1015_CFG_MUX_MASK | ADS1015_CFG_PGA_MASK |
ADS1015_CFG_DR_MASK;
cfg = chan << ADS1015_CFG_MUX_SHIFT | pga << ADS1015_CFG_PGA_SHIFT |
dr << ADS1015_CFG_DR_SHIFT;
if (ads1015_event_channel_enabled(data)) {
mask |= ADS1015_CFG_COMP_QUE_MASK | ADS1015_CFG_COMP_MODE_MASK;
cfg |= data->thresh_data[chan].comp_queue <<
ADS1015_CFG_COMP_QUE_SHIFT |
data->comp_mode <<
ADS1015_CFG_COMP_MODE_SHIFT;
}
cfg = (old & ~mask) | (cfg & mask);
ret = regmap_write(data->regmap, ADS1015_CFG_REG, cfg);
if (ret)
return ret;
if (old != cfg || data->conv_invalid) {
int dr_old = (old & ADS1015_CFG_DR_MASK) >>
ADS1015_CFG_DR_SHIFT;
conv_time = DIV_ROUND_UP(USEC_PER_SEC, data->data_rate[dr_old]);
conv_time += DIV_ROUND_UP(USEC_PER_SEC, data->data_rate[dr]);
usleep_range(conv_time, conv_time + 1);
data->conv_invalid = false;
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
static int ads1015_set_scale(struct ads1015_data *data,
struct iio_chan_spec const *chan,
int scale, int uscale)
{
int i;
int fullscale = div_s64((scale * 1000000LL + uscale) <<
(chan->scan_type.realbits - 1), 1000000);
for (i = 0; i < ARRAY_SIZE(ads1015_fullscale_range); i++) {
if (ads1015_fullscale_range[i] == fullscale) {
data->channel_data[chan->address].pga = i;
return 0;
}
}
return -EINVAL;
}
static int ads1015_set_data_rate(struct ads1015_data *data, int chan, int rate)
{
int i;
for (i = 0; i < ARRAY_SIZE(ads1015_data_rate); i++) {
if (data->data_rate[i] == rate) {
data->channel_data[chan].data_rate = i;
return 0;
}
}
return -EINVAL;
}
static int ads1015_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
int ret, idx;
struct ads1015_data *data = iio_priv(indio_dev);
mutex_lock(&data->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW: {
int shift = chan->scan_type.shift;
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
break;
if (ads1015_event_channel_enabled(data) &&
data->event_channel != chan->address) {
ret = -EBUSY;
goto release_direct;
}
ret = ads1015_set_power_state(data, true);
if (ret < 0)
goto release_direct;
ret = ads1015_get_adc_result(data, chan->address, val);
if (ret < 0) {
ads1015_set_power_state(data, false);
goto release_direct;
}
*val = sign_extend32(*val >> shift, 15 - shift);
ret = ads1015_set_power_state(data, false);
if (ret < 0)
goto release_direct;
ret = IIO_VAL_INT;
release_direct:
iio_device_release_direct_mode(indio_dev);
break;
}
case IIO_CHAN_INFO_SCALE:
idx = data->channel_data[chan->address].pga;
*val = ads1015_fullscale_range[idx];
*val2 = chan->scan_type.realbits - 1;
ret = IIO_VAL_FRACTIONAL_LOG2;
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
ret = ads1015_set_scale(data, chan, val, val2);
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
static int ads1015_read_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info, int *val,
int *val2)
{
struct ads1015_data *data = iio_priv(indio_dev);
int ret;
unsigned int comp_queue;
int period;
int dr;
mutex_lock(&data->lock);
switch (info) {
case IIO_EV_INFO_VALUE:
*val = (dir == IIO_EV_DIR_RISING) ?
data->thresh_data[chan->address].high_thresh :
data->thresh_data[chan->address].low_thresh;
ret = IIO_VAL_INT;
break;
case IIO_EV_INFO_PERIOD:
dr = data->channel_data[chan->address].data_rate;
comp_queue = data->thresh_data[chan->address].comp_queue;
period = ads1015_comp_queue[comp_queue] *
USEC_PER_SEC / data->data_rate[dr];
*val = period / USEC_PER_SEC;
*val2 = period % USEC_PER_SEC;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&data->lock);
return ret;
}
static int ads1015_write_event(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info, int val,
int val2)
{
struct ads1015_data *data = iio_priv(indio_dev);
int realbits = chan->scan_type.realbits;
int ret = 0;
long long period;
int i;
int dr;
mutex_lock(&data->lock);
switch (info) {
case IIO_EV_INFO_VALUE:
if (val >= 1 << (realbits - 1) || val < -1 << (realbits - 1)) {
ret = -EINVAL;
break;
}
if (dir == IIO_EV_DIR_RISING)
data->thresh_data[chan->address].high_thresh = val;
else
data->thresh_data[chan->address].low_thresh = val;
break;
case IIO_EV_INFO_PERIOD:
dr = data->channel_data[chan->address].data_rate;
period = val * USEC_PER_SEC + val2;
for (i = 0; i < ARRAY_SIZE(ads1015_comp_queue) - 1; i++) {
if (period <= ads1015_comp_queue[i] *
USEC_PER_SEC / data->data_rate[dr])
break;
}
data->thresh_data[chan->address].comp_queue = i;
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&data->lock);
return ret;
}
static int ads1015_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir)
{
struct ads1015_data *data = iio_priv(indio_dev);
int ret = 0;
mutex_lock(&data->lock);
if (data->event_channel == chan->address) {
switch (dir) {
case IIO_EV_DIR_RISING:
ret = 1;
break;
case IIO_EV_DIR_EITHER:
ret = (data->comp_mode == ADS1015_CFG_COMP_MODE_WINDOW);
break;
default:
ret = -EINVAL;
break;
}
}
mutex_unlock(&data->lock);
return ret;
}
static int ads1015_enable_event_config(struct ads1015_data *data,
const struct iio_chan_spec *chan, int comp_mode)
{
int low_thresh = data->thresh_data[chan->address].low_thresh;
int high_thresh = data->thresh_data[chan->address].high_thresh;
int ret;
unsigned int val;
if (ads1015_event_channel_enabled(data)) {
if (data->event_channel != chan->address ||
(data->comp_mode == ADS1015_CFG_COMP_MODE_TRAD &&
comp_mode == ADS1015_CFG_COMP_MODE_WINDOW))
return -EBUSY;
return 0;
}
if (comp_mode == ADS1015_CFG_COMP_MODE_TRAD) {
low_thresh = max(-1 << (chan->scan_type.realbits - 1),
high_thresh - 1);
}
ret = regmap_write(data->regmap, ADS1015_LO_THRESH_REG,
low_thresh << chan->scan_type.shift);
if (ret)
return ret;
ret = regmap_write(data->regmap, ADS1015_HI_THRESH_REG,
high_thresh << chan->scan_type.shift);
if (ret)
return ret;
ret = ads1015_set_power_state(data, true);
if (ret < 0)
return ret;
ads1015_event_channel_enable(data, chan->address, comp_mode);
ret = ads1015_get_adc_result(data, chan->address, &val);
if (ret) {
ads1015_event_channel_disable(data, chan->address);
ads1015_set_power_state(data, false);
}
return ret;
}
static int ads1015_disable_event_config(struct ads1015_data *data,
const struct iio_chan_spec *chan, int comp_mode)
{
int ret;
if (!ads1015_event_channel_enabled(data))
return 0;
if (data->event_channel != chan->address)
return 0;
if (data->comp_mode == ADS1015_CFG_COMP_MODE_TRAD &&
comp_mode == ADS1015_CFG_COMP_MODE_WINDOW)
return 0;
ret = regmap_update_bits(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_COMP_QUE_MASK,
ADS1015_CFG_COMP_DISABLE <<
ADS1015_CFG_COMP_QUE_SHIFT);
if (ret)
return ret;
ads1015_event_channel_disable(data, chan->address);
return ads1015_set_power_state(data, false);
}
static int ads1015_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, int state)
{
struct ads1015_data *data = iio_priv(indio_dev);
int ret;
int comp_mode = (dir == IIO_EV_DIR_EITHER) ?
ADS1015_CFG_COMP_MODE_WINDOW : ADS1015_CFG_COMP_MODE_TRAD;
mutex_lock(&data->lock);
ret = iio_device_claim_direct_mode(indio_dev);
if (ret) {
mutex_unlock(&data->lock);
return ret;
}
if (state)
ret = ads1015_enable_event_config(data, chan, comp_mode);
else
ret = ads1015_disable_event_config(data, chan, comp_mode);
iio_device_release_direct_mode(indio_dev);
mutex_unlock(&data->lock);
return ret;
}
static irqreturn_t ads1015_event_handler(int irq, void *priv)
{
struct iio_dev *indio_dev = priv;
struct ads1015_data *data = iio_priv(indio_dev);
int val;
int ret;
ret = regmap_read(data->regmap, ADS1015_CONV_REG, &val);
if (ret)
return IRQ_HANDLED;
if (ads1015_event_channel_enabled(data)) {
enum iio_event_direction dir;
u64 code;
dir = data->comp_mode == ADS1015_CFG_COMP_MODE_TRAD ?
IIO_EV_DIR_RISING : IIO_EV_DIR_EITHER;
code = IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE, data->event_channel,
IIO_EV_TYPE_THRESH, dir);
iio_push_event(indio_dev, code, iio_get_time_ns(indio_dev));
}
return IRQ_HANDLED;
}
static int ads1015_buffer_preenable(struct iio_dev *indio_dev)
{
struct ads1015_data *data = iio_priv(indio_dev);
if (ads1015_event_channel_enabled(data))
return -EBUSY;
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
dev_err(&client->dev, "invalid reg on %pOF\n",
node);
continue;
}
channel = pval;
if (channel >= ADS1015_CHANNELS) {
dev_err(&client->dev,
"invalid channel index %d on %pOF\n",
channel, node);
continue;
}
if (!of_property_read_u32(node, "ti,gain", &pval)) {
pga = pval;
if (pga > 6) {
dev_err(&client->dev, "invalid gain on %pOF\n",
node);
of_node_put(node);
return -EINVAL;
}
}
if (!of_property_read_u32(node, "ti,datarate", &pval)) {
data_rate = pval;
if (data_rate > 7) {
dev_err(&client->dev,
"invalid data_rate on %pOF\n",
node);
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
static int ads1015_set_conv_mode(struct ads1015_data *data, int mode)
{
return regmap_update_bits(data->regmap, ADS1015_CFG_REG,
ADS1015_CFG_MOD_MASK,
mode << ADS1015_CFG_MOD_SHIFT);
}
static int ads1015_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct ads1015_data *data;
int ret;
enum chip_ids chip;
int i;
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
if (client->dev.of_node)
chip = (enum chip_ids)of_device_get_match_data(&client->dev);
else
chip = id->driver_data;
switch (chip) {
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
data->event_channel = ADS1015_CHANNELS;
for (i = 0; i < ADS1015_CHANNELS; i++) {
int realbits = indio_dev->channels[i].scan_type.realbits;
data->thresh_data[i].low_thresh = -1 << (realbits - 1);
data->thresh_data[i].high_thresh = (1 << (realbits - 1)) - 1;
}
ads1015_get_channels_config(client);
data->regmap = devm_regmap_init_i2c(client, &ads1015_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(&client->dev, "Failed to allocate register map\n");
return PTR_ERR(data->regmap);
}
ret = devm_iio_triggered_buffer_setup(&client->dev, indio_dev, NULL,
ads1015_trigger_handler,
&ads1015_buffer_setup_ops);
if (ret < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
return ret;
}
if (client->irq) {
unsigned long irq_trig =
irqd_get_trigger_type(irq_get_irq_data(client->irq));
unsigned int cfg_comp_mask = ADS1015_CFG_COMP_QUE_MASK |
ADS1015_CFG_COMP_LAT_MASK | ADS1015_CFG_COMP_POL_MASK;
unsigned int cfg_comp =
ADS1015_CFG_COMP_DISABLE << ADS1015_CFG_COMP_QUE_SHIFT |
1 << ADS1015_CFG_COMP_LAT_SHIFT;
switch (irq_trig) {
case IRQF_TRIGGER_LOW:
cfg_comp |= ADS1015_CFG_COMP_POL_LOW <<
ADS1015_CFG_COMP_POL_SHIFT;
break;
case IRQF_TRIGGER_HIGH:
cfg_comp |= ADS1015_CFG_COMP_POL_HIGH <<
ADS1015_CFG_COMP_POL_SHIFT;
break;
default:
return -EINVAL;
}
ret = regmap_update_bits(data->regmap, ADS1015_CFG_REG,
cfg_comp_mask, cfg_comp);
if (ret)
return ret;
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, ads1015_event_handler,
irq_trig | IRQF_ONESHOT,
client->name, indio_dev);
if (ret)
return ret;
}
ret = ads1015_set_conv_mode(data, ADS1015_CONTINUOUS);
if (ret)
return ret;
data->conv_invalid = true;
ret = pm_runtime_set_active(&client->dev);
if (ret)
return ret;
pm_runtime_set_autosuspend_delay(&client->dev, ADS1015_SLEEP_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
pm_runtime_enable(&client->dev);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "Failed to register IIO device\n");
return ret;
}
return 0;
}
static int ads1015_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ads1015_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
return ads1015_set_conv_mode(data, ADS1015_SINGLESHOT);
}
static int ads1015_runtime_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct ads1015_data *data = iio_priv(indio_dev);
return ads1015_set_conv_mode(data, ADS1015_SINGLESHOT);
}
static int ads1015_runtime_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct ads1015_data *data = iio_priv(indio_dev);
int ret;
ret = ads1015_set_conv_mode(data, ADS1015_CONTINUOUS);
if (!ret)
data->conv_invalid = true;
return ret;
}
