static int lmp91000_read(struct lmp91000_data *data, int channel, int *val)
{
int state, ret;
ret = regmap_read(data->regmap, LMP91000_REG_MODECN, &state);
if (ret)
return -EINVAL;
ret = regmap_write(data->regmap, LMP91000_REG_MODECN, channel);
if (ret)
return -EINVAL;
if ((state != channel) && (channel == LMP91000_REG_MODECN_TEMP))
usleep_range(3000, 4000);
data->chan_select = channel != LMP91000_REG_MODECN_3LEAD;
iio_trigger_poll_chained(data->trig);
ret = wait_for_completion_timeout(&data->completion, HZ);
reinit_completion(&data->completion);
if (!ret)
return -ETIMEDOUT;
*val = data->buffer[data->chan_select];
return 0;
}
static irqreturn_t lmp91000_buffer_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *indio_dev = pf->indio_dev;
struct lmp91000_data *data = iio_priv(indio_dev);
int ret, val;
memset(data->buffer, 0, sizeof(data->buffer));
ret = lmp91000_read(data, LMP91000_REG_MODECN_3LEAD, &val);
if (!ret) {
data->buffer[0] = val;
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns(indio_dev));
}
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int lmp91000_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct lmp91000_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED: {
int ret = iio_channel_start_all_cb(data->cb_buffer);
if (ret)
return ret;
ret = lmp91000_read(data, chan->address, val);
iio_channel_stop_all_cb(data->cb_buffer);
if (ret)
return ret;
if (mask == IIO_CHAN_INFO_PROCESSED) {
int tmp, i;
ret = iio_convert_raw_to_processed(data->adc_chan,
*val, &tmp, 1);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(lmp91000_temp_lut); i++)
if (lmp91000_temp_lut[i] < tmp)
break;
*val = (LMP91000_TEMP_BASE + i) * 1000;
}
return IIO_VAL_INT;
}
case IIO_CHAN_INFO_OFFSET:
return iio_read_channel_offset(data->adc_chan, val, val2);
case IIO_CHAN_INFO_SCALE:
return iio_read_channel_scale(data->adc_chan, val, val2);
}
return -EINVAL;
}
static int lmp91000_read_config(struct lmp91000_data *data)
{
struct device *dev = data->dev;
struct device_node *np = dev->of_node;
unsigned int reg, val;
int i, ret;
ret = of_property_read_u32(np, "ti,tia-gain-ohm", &val);
if (ret) {
if (of_property_read_bool(np, "ti,external-tia-resistor"))
val = 0;
else {
dev_err(dev, "no ti,tia-gain-ohm defined");
return ret;
}
}
ret = -EINVAL;
for (i = 0; i < ARRAY_SIZE(lmp91000_tia_gain); i++) {
if (lmp91000_tia_gain[i] == val) {
reg = i << LMP91000_REG_TIACN_GAIN_SHIFT;
ret = 0;
break;
}
}
if (ret) {
dev_err(dev, "invalid ti,tia-gain-ohm %d\n", val);
return ret;
}
ret = of_property_read_u32(np, "ti,rload-ohm", &val);
if (ret) {
val = 100;
dev_info(dev, "no ti,rload-ohm defined, default to %d\n", val);
}
ret = -EINVAL;
for (i = 0; i < ARRAY_SIZE(lmp91000_rload); i++) {
if (lmp91000_rload[i] == val) {
reg |= i;
ret = 0;
break;
}
}
if (ret) {
dev_err(dev, "invalid ti,rload-ohm %d\n", val);
return ret;
}
regmap_write(data->regmap, LMP91000_REG_LOCK, 0);
regmap_write(data->regmap, LMP91000_REG_TIACN, reg);
regmap_write(data->regmap, LMP91000_REG_REFCN, LMP91000_REG_REFCN_EXT_REF
| LMP91000_REG_REFCN_50_ZERO);
regmap_write(data->regmap, LMP91000_REG_LOCK, 1);
return 0;
}
static int lmp91000_buffer_cb(const void *val, void *private)
{
struct iio_dev *indio_dev = private;
struct lmp91000_data *data = iio_priv(indio_dev);
data->buffer[data->chan_select] = *((int *)val);
complete_all(&data->completion);
return 0;
}
static int lmp91000_buffer_preenable(struct iio_dev *indio_dev)
{
struct lmp91000_data *data = iio_priv(indio_dev);
return iio_channel_start_all_cb(data->cb_buffer);
}
static int lmp91000_buffer_predisable(struct iio_dev *indio_dev)
{
struct lmp91000_data *data = iio_priv(indio_dev);
iio_channel_stop_all_cb(data->cb_buffer);
return 0;
}
static int lmp91000_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct lmp91000_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
indio_dev->info = &lmp91000_info;
indio_dev->channels = lmp91000_channels;
indio_dev->num_channels = ARRAY_SIZE(lmp91000_channels);
indio_dev->name = LMP91000_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
i2c_set_clientdata(client, indio_dev);
data = iio_priv(indio_dev);
data->dev = dev;
data->regmap = devm_regmap_init_i2c(client, &lmp91000_regmap_config);
if (IS_ERR(data->regmap)) {
dev_err(dev, "regmap initialization failed.\n");
return PTR_ERR(data->regmap);
}
data->trig = devm_iio_trigger_alloc(data->dev, "%s-mux%d",
indio_dev->name, indio_dev->id);
if (!data->trig) {
dev_err(dev, "cannot allocate iio trigger.\n");
return -ENOMEM;
}
data->trig->ops = &lmp91000_trigger_ops;
data->trig->dev.parent = dev;
init_completion(&data->completion);
ret = lmp91000_read_config(data);
if (ret)
return ret;
ret = iio_trigger_set_immutable(iio_channel_cb_get_iio_dev(data->cb_buffer),
data->trig);
if (ret) {
dev_err(dev, "cannot set immutable trigger.\n");
return ret;
}
ret = iio_trigger_register(data->trig);
if (ret) {
dev_err(dev, "cannot register iio trigger.\n");
return ret;
}
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&lmp91000_buffer_handler,
&lmp91000_buffer_setup_ops);
if (ret)
goto error_unreg_trigger;
data->cb_buffer = iio_channel_get_all_cb(dev, &lmp91000_buffer_cb,
indio_dev);
if (IS_ERR(data->cb_buffer)) {
if (PTR_ERR(data->cb_buffer) == -ENODEV)
ret = -EPROBE_DEFER;
else
ret = PTR_ERR(data->cb_buffer);
goto error_unreg_buffer;
}
data->adc_chan = iio_channel_cb_get_channels(data->cb_buffer);
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_cb_buffer;
return 0;
error_unreg_cb_buffer:
iio_channel_release_all_cb(data->cb_buffer);
error_unreg_buffer:
iio_triggered_buffer_cleanup(indio_dev);
error_unreg_trigger:
iio_trigger_unregister(data->trig);
return ret;
}
static int lmp91000_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct lmp91000_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_channel_stop_all_cb(data->cb_buffer);
iio_channel_release_all_cb(data->cb_buffer);
iio_triggered_buffer_cleanup(indio_dev);
iio_trigger_unregister(data->trig);
return 0;
}
