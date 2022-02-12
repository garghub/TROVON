static int bma180_get_data_reg(struct bma180_data *data, enum bma180_chan chan)
{
int ret;
if (data->sleep_state)
return -EBUSY;
switch (chan) {
case TEMP:
ret = i2c_smbus_read_byte_data(data->client, BMA180_TEMP);
if (ret < 0)
dev_err(&data->client->dev, "failed to read temp register\n");
break;
default:
ret = i2c_smbus_read_word_data(data->client,
BMA180_ACC_X_LSB + chan * 2);
if (ret < 0)
dev_err(&data->client->dev,
"failed to read accel_%c register\n",
'x' + chan);
}
return ret;
}
static int bma180_set_bits(struct bma180_data *data, u8 reg, u8 mask, u8 val)
{
int ret = i2c_smbus_read_byte_data(data->client, reg);
u8 reg_val = (ret & ~mask) | (val << (ffs(mask) - 1));
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(data->client, reg, reg_val);
}
static int bma180_reset_intr(struct bma180_data *data)
{
int ret = bma180_set_bits(data, data->part_info->int_reset_reg,
data->part_info->int_reset_mask, 1);
if (ret)
dev_err(&data->client->dev, "failed to reset interrupt\n");
return ret;
}
static int bma180_set_new_data_intr_state(struct bma180_data *data, bool state)
{
int ret = bma180_set_bits(data, data->part_info->int_enable_reg,
data->part_info->int_enable_mask, state);
if (ret)
goto err;
ret = bma180_reset_intr(data);
if (ret)
goto err;
return 0;
err:
dev_err(&data->client->dev,
"failed to set new data interrupt state %d\n", state);
return ret;
}
static int bma180_set_sleep_state(struct bma180_data *data, bool state)
{
int ret = bma180_set_bits(data, data->part_info->sleep_reg,
data->part_info->sleep_mask, state);
if (ret) {
dev_err(&data->client->dev,
"failed to set sleep state %d\n", state);
return ret;
}
data->sleep_state = state;
return 0;
}
static int bma180_set_ee_writing_state(struct bma180_data *data, bool state)
{
int ret = bma180_set_bits(data, BMA180_CTRL_REG0, BMA180_EE_W, state);
if (ret)
dev_err(&data->client->dev,
"failed to set ee writing state %d\n", state);
return ret;
}
static int bma180_set_bw(struct bma180_data *data, int val)
{
int ret, i;
if (data->sleep_state)
return -EBUSY;
for (i = 0; i < data->part_info->num_bw; ++i) {
if (data->part_info->bw_table[i] == val) {
ret = bma180_set_bits(data, data->part_info->bw_reg,
data->part_info->bw_mask, i);
if (ret) {
dev_err(&data->client->dev,
"failed to set bandwidth\n");
return ret;
}
data->bw = val;
return 0;
}
}
return -EINVAL;
}
static int bma180_set_scale(struct bma180_data *data, int val)
{
int ret, i;
if (data->sleep_state)
return -EBUSY;
for (i = 0; i < data->part_info->num_scales; ++i)
if (data->part_info->scale_table[i] == val) {
ret = bma180_set_bits(data, data->part_info->scale_reg,
data->part_info->scale_mask, i);
if (ret) {
dev_err(&data->client->dev,
"failed to set scale\n");
return ret;
}
data->scale = val;
return 0;
}
return -EINVAL;
}
static int bma180_set_pmode(struct bma180_data *data, bool mode)
{
u8 reg_val = mode ? data->part_info->lowpower_val : 0;
int ret = bma180_set_bits(data, data->part_info->power_reg,
data->part_info->power_mask, reg_val);
if (ret) {
dev_err(&data->client->dev, "failed to set power mode\n");
return ret;
}
data->pmode = mode;
return 0;
}
static int bma180_soft_reset(struct bma180_data *data)
{
int ret = i2c_smbus_write_byte_data(data->client,
data->part_info->softreset_reg, BMA180_RESET_VAL);
if (ret)
dev_err(&data->client->dev, "failed to reset the chip\n");
return ret;
}
static int bma180_chip_init(struct bma180_data *data)
{
int ret = i2c_smbus_read_byte_data(data->client, BMA180_CHIP_ID);
if (ret < 0)
return ret;
if (ret != BMA180_ID_REG_VAL)
return -ENODEV;
ret = bma180_soft_reset(data);
if (ret)
return ret;
msleep(20);
ret = bma180_set_new_data_intr_state(data, false);
if (ret)
return ret;
return bma180_set_pmode(data, false);
}
static int bma180_chip_config(struct bma180_data *data)
{
int ret = bma180_chip_init(data);
if (ret)
goto err;
ret = bma180_set_bits(data, BMA180_CTRL_REG0, BMA180_DIS_WAKE_UP, 1);
if (ret)
goto err;
ret = bma180_set_ee_writing_state(data, true);
if (ret)
goto err;
ret = bma180_set_bits(data, BMA180_OFFSET_LSB1, BMA180_SMP_SKIP, 1);
if (ret)
goto err;
ret = bma180_set_bw(data, 20);
if (ret)
goto err;
ret = bma180_set_scale(data, 2452);
if (ret)
goto err;
return 0;
err:
dev_err(&data->client->dev, "failed to config the chip\n");
return ret;
}
static int bma250_chip_config(struct bma180_data *data)
{
int ret = bma180_chip_init(data);
if (ret)
goto err;
ret = bma180_set_bw(data, 16);
if (ret)
goto err;
ret = bma180_set_scale(data, 38344);
if (ret)
goto err;
ret = bma180_set_bits(data, BMA250_INT_MAP_REG,
BMA250_INT1_DATA_MASK, 1);
if (ret)
goto err;
return 0;
err:
dev_err(&data->client->dev, "failed to config the chip\n");
return ret;
}
static void bma180_chip_disable(struct bma180_data *data)
{
if (bma180_set_new_data_intr_state(data, false))
goto err;
if (bma180_set_ee_writing_state(data, false))
goto err;
if (bma180_set_sleep_state(data, true))
goto err;
return;
err:
dev_err(&data->client->dev, "failed to disable the chip\n");
}
static void bma250_chip_disable(struct bma180_data *data)
{
if (bma180_set_new_data_intr_state(data, false))
goto err;
if (bma180_set_sleep_state(data, true))
goto err;
return;
err:
dev_err(&data->client->dev, "failed to disable the chip\n");
}
static ssize_t bma180_show_avail(char *buf, const int *vals, unsigned n,
bool micros)
{
size_t len = 0;
int i;
for (i = 0; i < n; i++) {
if (!vals[i])
continue;
len += scnprintf(buf + len, PAGE_SIZE - len,
micros ? "0.%06d " : "%d ", vals[i]);
}
buf[len - 1] = '\n';
return len;
}
static ssize_t bma180_show_filter_freq_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bma180_data *data = iio_priv(dev_to_iio_dev(dev));
return bma180_show_avail(buf, data->part_info->bw_table,
data->part_info->num_bw, false);
}
static ssize_t bma180_show_scale_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bma180_data *data = iio_priv(dev_to_iio_dev(dev));
return bma180_show_avail(buf, data->part_info->scale_table,
data->part_info->num_scales, true);
}
static int bma180_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2,
long mask)
{
struct bma180_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->mutex);
if (iio_buffer_enabled(indio_dev)) {
mutex_unlock(&data->mutex);
return -EBUSY;
}
ret = bma180_get_data_reg(data, chan->scan_index);
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
*val = sign_extend32(ret >> chan->scan_type.shift,
chan->scan_type.realbits - 1);
return IIO_VAL_INT;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
*val = data->bw;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ACCEL:
*val = 0;
*val2 = data->scale;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 500;
return IIO_VAL_INT;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
*val = 48;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int bma180_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
struct bma180_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bma180_set_scale(data, val2);
mutex_unlock(&data->mutex);
return ret;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
if (val2)
return -EINVAL;
mutex_lock(&data->mutex);
ret = bma180_set_bw(data, val);
mutex_unlock(&data->mutex);
return ret;
default:
return -EINVAL;
}
}
static int bma180_get_power_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct bma180_data *data = iio_priv(indio_dev);
return data->pmode;
}
static int bma180_set_power_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int mode)
{
struct bma180_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bma180_set_pmode(data, mode);
mutex_unlock(&data->mutex);
return ret;
}
static irqreturn_t bma180_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct bma180_data *data = iio_priv(indio_dev);
int64_t time_ns = iio_get_time_ns();
int bit, ret, i = 0;
mutex_lock(&data->mutex);
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = bma180_get_data_reg(data, bit);
if (ret < 0) {
mutex_unlock(&data->mutex);
goto err;
}
((s16 *)data->buff)[i++] = ret;
}
mutex_unlock(&data->mutex);
iio_push_to_buffers_with_timestamp(indio_dev, data->buff, time_ns);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int bma180_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bma180_data *data = iio_priv(indio_dev);
return bma180_set_new_data_intr_state(data, state);
}
static int bma180_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct bma180_data *data = iio_priv(indio_dev);
return bma180_reset_intr(data);
}
static int bma180_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bma180_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
data->part_info = &bma180_part_info[id->driver_data];
ret = data->part_info->chip_config(data);
if (ret < 0)
goto err_chip_disable;
mutex_init(&data->mutex);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = data->part_info->channels;
indio_dev->num_channels = data->part_info->num_channels;
indio_dev->name = id->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &bma180_info;
if (client->irq > 0) {
data->trig = iio_trigger_alloc("%s-dev%d", indio_dev->name,
indio_dev->id);
if (!data->trig) {
ret = -ENOMEM;
goto err_chip_disable;
}
ret = devm_request_irq(&client->dev, client->irq,
iio_trigger_generic_data_rdy_poll, IRQF_TRIGGER_RISING,
"bma180_event", data->trig);
if (ret) {
dev_err(&client->dev, "unable to request IRQ\n");
goto err_trigger_free;
}
data->trig->dev.parent = &client->dev;
data->trig->ops = &bma180_trigger_ops;
iio_trigger_set_drvdata(data->trig, indio_dev);
indio_dev->trig = iio_trigger_get(data->trig);
ret = iio_trigger_register(data->trig);
if (ret)
goto err_trigger_free;
}
ret = iio_triggered_buffer_setup(indio_dev, NULL,
bma180_trigger_handler, NULL);
if (ret < 0) {
dev_err(&client->dev, "unable to setup iio triggered buffer\n");
goto err_trigger_unregister;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "unable to register iio device\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
if (data->trig)
iio_trigger_unregister(data->trig);
err_trigger_free:
iio_trigger_free(data->trig);
err_chip_disable:
data->part_info->chip_disable(data);
return ret;
}
static int bma180_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct bma180_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (data->trig) {
iio_trigger_unregister(data->trig);
iio_trigger_free(data->trig);
}
mutex_lock(&data->mutex);
data->part_info->chip_disable(data);
mutex_unlock(&data->mutex);
return 0;
}
static int bma180_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bma180_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bma180_set_sleep_state(data, true);
mutex_unlock(&data->mutex);
return ret;
}
static int bma180_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bma180_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bma180_set_sleep_state(data, false);
mutex_unlock(&data->mutex);
return ret;
}
