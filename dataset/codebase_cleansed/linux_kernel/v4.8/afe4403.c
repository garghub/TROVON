static ssize_t afe440x_show_register(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4403_data *afe = iio_priv(indio_dev);
struct afe440x_attr *afe440x_attr = to_afe440x_attr(attr);
unsigned int reg_val;
int vals[2];
int ret;
ret = regmap_field_read(afe->fields[afe440x_attr->field], &reg_val);
if (ret)
return ret;
if (reg_val >= afe440x_attr->table_size)
return -EINVAL;
vals[0] = afe440x_attr->val_table[reg_val].integer;
vals[1] = afe440x_attr->val_table[reg_val].fract;
return iio_format_value(buf, IIO_VAL_INT_PLUS_MICRO, 2, vals);
}
static ssize_t afe440x_store_register(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4403_data *afe = iio_priv(indio_dev);
struct afe440x_attr *afe440x_attr = to_afe440x_attr(attr);
int val, integer, fract, ret;
ret = iio_str_to_fixpoint(buf, 100000, &integer, &fract);
if (ret)
return ret;
for (val = 0; val < afe440x_attr->table_size; val++)
if (afe440x_attr->val_table[val].integer == integer &&
afe440x_attr->val_table[val].fract == fract)
break;
if (val == afe440x_attr->table_size)
return -EINVAL;
ret = regmap_field_write(afe->fields[afe440x_attr->field], val);
if (ret)
return ret;
return count;
}
static int afe4403_read(struct afe4403_data *afe, unsigned int reg, u32 *val)
{
u8 tx[4] = {AFE440X_CONTROL0, 0x0, 0x0, AFE440X_CONTROL0_READ};
u8 rx[3];
int ret;
ret = spi_write_then_read(afe->spi, tx, 4, NULL, 0);
if (ret)
return ret;
ret = spi_write_then_read(afe->spi, &reg, 1, rx, 3);
if (ret)
return ret;
*val = (rx[0] << 16) |
(rx[1] << 8) |
(rx[2]);
tx[3] = AFE440X_CONTROL0_WRITE;
ret = spi_write_then_read(afe->spi, tx, 4, NULL, 0);
if (ret)
return ret;
return 0;
}
static int afe4403_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct afe4403_data *afe = iio_priv(indio_dev);
unsigned int reg = afe4403_channel_values[chan->address];
unsigned int field = afe4403_channel_leds[chan->address];
int ret;
switch (chan->type) {
case IIO_INTENSITY:
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = afe4403_read(afe, reg, val);
if (ret)
return ret;
return IIO_VAL_INT;
}
break;
case IIO_CURRENT:
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = regmap_field_read(afe->fields[field], val);
if (ret)
return ret;
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
static int afe4403_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct afe4403_data *afe = iio_priv(indio_dev);
unsigned int field = afe4403_channel_leds[chan->address];
switch (chan->type) {
case IIO_CURRENT:
switch (mask) {
case IIO_CHAN_INFO_RAW:
return regmap_field_write(afe->fields[field], val);
}
break;
default:
break;
}
return -EINVAL;
}
static irqreturn_t afe4403_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *indio_dev = pf->indio_dev;
struct afe4403_data *afe = iio_priv(indio_dev);
int ret, bit, i = 0;
s32 buffer[8];
u8 tx[4] = {AFE440X_CONTROL0, 0x0, 0x0, AFE440X_CONTROL0_READ};
u8 rx[3];
ret = spi_write_then_read(afe->spi, tx, 4, NULL, 0);
if (ret)
goto err;
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = spi_write_then_read(afe->spi,
&afe4403_channel_values[bit], 1,
rx, 3);
if (ret)
goto err;
buffer[i++] = (rx[0] << 16) |
(rx[1] << 8) |
(rx[2]);
}
tx[3] = AFE440X_CONTROL0_WRITE;
ret = spi_write_then_read(afe->spi, tx, 4, NULL, 0);
if (ret)
goto err;
iio_push_to_buffers_with_timestamp(indio_dev, buffer, pf->timestamp);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int __maybe_unused afe4403_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4403_data *afe = iio_priv(indio_dev);
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
static int __maybe_unused afe4403_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct afe4403_data *afe = iio_priv(indio_dev);
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
static int afe4403_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct afe4403_data *afe;
int i, ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*afe));
if (!indio_dev)
return -ENOMEM;
afe = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
afe->dev = &spi->dev;
afe->spi = spi;
afe->irq = spi->irq;
afe->regmap = devm_regmap_init_spi(spi, &afe4403_regmap_config);
if (IS_ERR(afe->regmap)) {
dev_err(afe->dev, "Unable to allocate register map\n");
return PTR_ERR(afe->regmap);
}
for (i = 0; i < F_MAX_FIELDS; i++) {
afe->fields[i] = devm_regmap_field_alloc(afe->dev, afe->regmap,
afe4403_reg_fields[i]);
if (IS_ERR(afe->fields[i])) {
dev_err(afe->dev, "Unable to allocate regmap fields\n");
return PTR_ERR(afe->fields[i]);
}
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
goto err_disable_reg;
}
ret = regmap_multi_reg_write(afe->regmap, afe4403_reg_sequences,
ARRAY_SIZE(afe4403_reg_sequences));
if (ret) {
dev_err(afe->dev, "Unable to set register defaults\n");
goto err_disable_reg;
}
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->dev.parent = afe->dev;
indio_dev->channels = afe4403_channels;
indio_dev->num_channels = ARRAY_SIZE(afe4403_channels);
indio_dev->name = AFE4403_DRIVER_NAME;
indio_dev->info = &afe4403_iio_info;
if (afe->irq > 0) {
afe->trig = devm_iio_trigger_alloc(afe->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!afe->trig) {
dev_err(afe->dev, "Unable to allocate IIO trigger\n");
ret = -ENOMEM;
goto err_disable_reg;
}
iio_trigger_set_drvdata(afe->trig, indio_dev);
afe->trig->ops = &afe4403_trigger_ops;
afe->trig->dev.parent = afe->dev;
ret = iio_trigger_register(afe->trig);
if (ret) {
dev_err(afe->dev, "Unable to register IIO trigger\n");
goto err_disable_reg;
}
ret = devm_request_threaded_irq(afe->dev, afe->irq,
iio_trigger_generic_data_rdy_poll,
NULL, IRQF_ONESHOT,
AFE4403_DRIVER_NAME,
afe->trig);
if (ret) {
dev_err(afe->dev, "Unable to request IRQ\n");
goto err_trig;
}
}
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
afe4403_trigger_handler, NULL);
if (ret) {
dev_err(afe->dev, "Unable to setup buffer\n");
goto err_trig;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(afe->dev, "Unable to register IIO device\n");
goto err_buff;
}
return 0;
err_buff:
iio_triggered_buffer_cleanup(indio_dev);
err_trig:
if (afe->irq > 0)
iio_trigger_unregister(afe->trig);
err_disable_reg:
regulator_disable(afe->regulator);
return ret;
}
static int afe4403_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct afe4403_data *afe = iio_priv(indio_dev);
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
