static ssize_t afe440x_show_register(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4404_data *afe = iio_priv(indio_dev);
struct afe440x_attr *afe440x_attr = to_afe440x_attr(attr);
unsigned int reg_val, type;
int vals[2];
int ret, val_len;
ret = regmap_read(afe->regmap, afe440x_attr->reg, &reg_val);
if (ret)
return ret;
reg_val &= afe440x_attr->mask;
reg_val >>= afe440x_attr->shift;
switch (afe440x_attr->type) {
case SIMPLE:
type = IIO_VAL_INT;
val_len = 1;
vals[0] = reg_val;
break;
case RESISTANCE:
case CAPACITANCE:
type = IIO_VAL_INT_PLUS_MICRO;
val_len = 2;
if (reg_val < afe440x_attr->table_size) {
vals[0] = afe440x_attr->val_table[reg_val].integer;
vals[1] = afe440x_attr->val_table[reg_val].fract;
break;
}
return -EINVAL;
default:
return -EINVAL;
}
return iio_format_value(buf, type, val_len, vals);
}
static ssize_t afe440x_store_register(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4404_data *afe = iio_priv(indio_dev);
struct afe440x_attr *afe440x_attr = to_afe440x_attr(attr);
int val, integer, fract, ret;
ret = iio_str_to_fixpoint(buf, 100000, &integer, &fract);
if (ret)
return ret;
switch (afe440x_attr->type) {
case SIMPLE:
val = integer;
break;
case RESISTANCE:
case CAPACITANCE:
for (val = 0; val < afe440x_attr->table_size; val++)
if (afe440x_attr->val_table[val].integer == integer &&
afe440x_attr->val_table[val].fract == fract)
break;
if (val == afe440x_attr->table_size)
return -EINVAL;
break;
default:
return -EINVAL;
}
ret = regmap_update_bits(afe->regmap, afe440x_attr->reg,
afe440x_attr->mask,
(val << afe440x_attr->shift));
if (ret)
return ret;
return count;
}
static int afe4404_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct afe4404_data *afe = iio_priv(indio_dev);
const struct afe440x_reg_info reg_info = afe4404_reg_info[chan->address];
int ret;
switch (chan->type) {
case IIO_INTENSITY:
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = regmap_read(afe->regmap, reg_info.reg, val);
if (ret)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_OFFSET:
ret = regmap_read(afe->regmap, reg_info.offreg,
val);
if (ret)
return ret;
*val &= reg_info.mask;
*val >>= reg_info.shift;
return IIO_VAL_INT;
}
break;
case IIO_CURRENT:
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = regmap_read(afe->regmap, reg_info.reg, val);
if (ret)
return ret;
*val &= reg_info.mask;
*val >>= reg_info.shift;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = 800000;
return IIO_VAL_INT_PLUS_MICRO;
}
break;
default:
break;
}
return -EINVAL;
}
static int afe4404_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct afe4404_data *afe = iio_priv(indio_dev);
const struct afe440x_reg_info reg_info = afe4404_reg_info[chan->address];
switch (chan->type) {
case IIO_INTENSITY:
switch (mask) {
case IIO_CHAN_INFO_OFFSET:
return regmap_update_bits(afe->regmap,
reg_info.offreg,
reg_info.mask,
(val << reg_info.shift));
}
break;
case IIO_CURRENT:
switch (mask) {
case IIO_CHAN_INFO_RAW:
return regmap_update_bits(afe->regmap,
reg_info.reg,
reg_info.mask,
(val << reg_info.shift));
}
break;
default:
break;
}
return -EINVAL;
}
static irqreturn_t afe4404_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *indio_dev = pf->indio_dev;
struct afe4404_data *afe = iio_priv(indio_dev);
int ret, bit, i = 0;
s32 buffer[10];
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = regmap_read(afe->regmap, afe4404_reg_info[bit].reg,
&buffer[i++]);
if (ret)
goto err;
}
iio_push_to_buffers_with_timestamp(indio_dev, buffer, pf->timestamp);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int __maybe_unused afe4404_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4404_data *afe = iio_priv(indio_dev);
int ret;
ret = regmap_update_bits(afe->regmap, AFE440X_CONTROL2,
AFE440X_CONTROL2_PDN_AFE,
AFE440X_CONTROL2_PDN_AFE);
if (ret)
return ret;
ret = regulator_disable(afe->regulator);
if (ret) {
dev_err(dev, "Unable to disable regulator\n");
return ret;
}
return 0;
}
static int __maybe_unused afe4404_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4404_data *afe = iio_priv(indio_dev);
int ret;
ret = regulator_enable(afe->regulator);
if (ret) {
dev_err(dev, "Unable to enable regulator\n");
return ret;
}
ret = regmap_update_bits(afe->regmap, AFE440X_CONTROL2,
AFE440X_CONTROL2_PDN_AFE, 0);
if (ret)
return ret;
return 0;
}
static int afe4404_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct afe4404_data *afe;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*afe));
if (!indio_dev)
return -ENOMEM;
afe = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
afe->dev = &client->dev;
afe->irq = client->irq;
afe->regmap = devm_regmap_init_i2c(client, &afe4404_regmap_config);
if (IS_ERR(afe->regmap)) {
dev_err(afe->dev, "Unable to allocate register map\n");
return PTR_ERR(afe->regmap);
}
afe->regulator = devm_regulator_get(afe->dev, "tx_sup");
if (IS_ERR(afe->regulator)) {
dev_err(afe->dev, "Unable to get regulator\n");
return PTR_ERR(afe->regulator);
}
ret = regulator_enable(afe->regulator);
if (ret) {
dev_err(afe->dev, "Unable to enable regulator\n");
return ret;
}
ret = regmap_write(afe->regmap, AFE440X_CONTROL0,
AFE440X_CONTROL0_SW_RESET);
if (ret) {
dev_err(afe->dev, "Unable to reset device\n");
goto disable_reg;
}
ret = regmap_multi_reg_write(afe->regmap, afe4404_reg_sequences,
ARRAY_SIZE(afe4404_reg_sequences));
if (ret) {
dev_err(afe->dev, "Unable to set register defaults\n");
goto disable_reg;
}
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->dev.parent = afe->dev;
indio_dev->channels = afe4404_channels;
indio_dev->num_channels = ARRAY_SIZE(afe4404_channels);
indio_dev->name = AFE4404_DRIVER_NAME;
indio_dev->info = &afe4404_iio_info;
if (afe->irq > 0) {
afe->trig = devm_iio_trigger_alloc(afe->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!afe->trig) {
dev_err(afe->dev, "Unable to allocate IIO trigger\n");
ret = -ENOMEM;
goto disable_reg;
}
iio_trigger_set_drvdata(afe->trig, indio_dev);
afe->trig->ops = &afe4404_trigger_ops;
afe->trig->dev.parent = afe->dev;
ret = iio_trigger_register(afe->trig);
if (ret) {
dev_err(afe->dev, "Unable to register IIO trigger\n");
goto disable_reg;
}
ret = devm_request_threaded_irq(afe->dev, afe->irq,
iio_trigger_generic_data_rdy_poll,
NULL, IRQF_ONESHOT,
AFE4404_DRIVER_NAME,
afe->trig);
if (ret) {
dev_err(afe->dev, "Unable to request IRQ\n");
goto disable_reg;
}
}
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
afe4404_trigger_handler, NULL);
if (ret) {
dev_err(afe->dev, "Unable to setup buffer\n");
goto unregister_trigger;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(afe->dev, "Unable to register IIO device\n");
goto unregister_triggered_buffer;
}
return 0;
unregister_triggered_buffer:
iio_triggered_buffer_cleanup(indio_dev);
unregister_trigger:
if (afe->irq > 0)
iio_trigger_unregister(afe->trig);
disable_reg:
regulator_disable(afe->regulator);
return ret;
}
static int afe4404_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct afe4404_data *afe = iio_priv(indio_dev);
int ret;
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (afe->irq > 0)
iio_trigger_unregister(afe->trig);
ret = regulator_disable(afe->regulator);
if (ret) {
dev_err(afe->dev, "Unable to disable regulator\n");
return ret;
}
return 0;
}
