static int bma180_get_acc_reg(struct bma180_data *data, enum bma180_axis axis)
{
u8 reg = BMA180_ACC_X_LSB + axis * 2;
int ret;
if (data->sleep_state)
return -EBUSY;
ret = i2c_smbus_read_word_data(data->client, reg);
if (ret < 0)
dev_err(&data->client->dev,
"failed to read accel_%c registers\n", 'x' + axis);
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
int ret = bma180_set_bits(data, BMA180_CTRL_REG0, BMA180_RESET_INT, 1);
if (ret)
dev_err(&data->client->dev, "failed to reset interrupt\n");
return ret;
}
static int bma180_set_new_data_intr_state(struct bma180_data *data, int state)
{
u8 reg_val = state ? BMA180_NEW_DATA_INT : 0x00;
int ret = i2c_smbus_write_byte_data(data->client, BMA180_CTRL_REG3,
reg_val);
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
static int bma180_set_sleep_state(struct bma180_data *data, int state)
{
int ret = bma180_set_bits(data, BMA180_CTRL_REG0, BMA180_SLEEP, state);
if (ret) {
dev_err(&data->client->dev,
"failed to set sleep state %d\n", state);
return ret;
}
data->sleep_state = state;
return 0;
}
static int bma180_set_ee_writing_state(struct bma180_data *data, int state)
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
for (i = 0; i < ARRAY_SIZE(bw_table); ++i) {
if (bw_table[i] == val) {
ret = bma180_set_bits(data,
BMA180_BW_TCS, BMA180_BW, i);
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
for (i = 0; i < ARRAY_SIZE(scale_table); ++i)
if (scale_table[i] == val) {
ret = bma180_set_bits(data,
BMA180_OFFSET_LSB1, BMA180_RANGE, i);
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
static int bma180_set_pmode(struct bma180_data *data, int mode)
{
u8 reg_val = mode ? BMA180_LOW_POWER : BMA180_LOW_NOISE;
int ret = bma180_set_bits(data, BMA180_TCO_Z, BMA180_MODE_CONFIG,
reg_val);
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
BMA180_RESET, BMA180_RESET_VAL);
if (ret)
dev_err(&data->client->dev, "failed to reset the chip\n");
return ret;
}
static int bma180_chip_init(struct bma180_data *data)
{
int ret = i2c_smbus_read_byte_data(data->client, BMA180_CHIP_ID);
if (ret < 0)
goto err;
if (ret != BMA_180_ID_REG_VAL) {
ret = -ENODEV;
goto err;
}
ret = bma180_soft_reset(data);
if (ret)
goto err;
msleep(20);
ret = bma180_set_bits(data, BMA180_CTRL_REG0, BMA180_DIS_WAKE_UP, 1);
if (ret)
goto err;
ret = bma180_set_ee_writing_state(data, 1);
if (ret)
goto err;
ret = bma180_set_new_data_intr_state(data, 0);
if (ret)
goto err;
ret = bma180_set_bits(data, BMA180_OFFSET_LSB1, BMA180_SMP_SKIP, 1);
if (ret)
goto err;
ret = bma180_set_pmode(data, BMA180_DEF_PMODE);
if (ret)
goto err;
ret = bma180_set_bw(data, BMA180_DEF_BW);
if (ret)
goto err;
ret = bma180_set_scale(data, BMA180_DEF_SCALE);
if (ret)
goto err;
return 0;
err:
dev_err(&data->client->dev, "failed to init the chip\n");
return ret;
}
static void bma180_chip_disable(struct bma180_data *data)
{
if (bma180_set_new_data_intr_state(data, 0))
goto err;
if (bma180_set_ee_writing_state(data, 0))
goto err;
if (bma180_set_sleep_state(data, 1))
goto err;
return;
err:
dev_err(&data->client->dev, "failed to disable the chip\n");
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
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else
ret = bma180_get_acc_reg(data, chan->scan_index);
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
*val = (s16)ret >> chan->scan_type.shift;
return IIO_VAL_INT;
case IIO_CHAN_INFO_LOW_PASS_FILTER_3DB_FREQUENCY:
*val = data->bw;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = data->scale;
return IIO_VAL_INT_PLUS_MICRO;
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
static int bma180_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct bma180_data *data = iio_priv(indio_dev);
if (data->buff)
devm_kfree(&indio_dev->dev, data->buff);
data->buff = devm_kzalloc(&indio_dev->dev,
indio_dev->scan_bytes, GFP_KERNEL);
if (!data->buff)
return -ENOMEM;
return 0;
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
for_each_set_bit(bit, indio_dev->buffer->scan_mask,
indio_dev->masklength) {
ret = bma180_get_acc_reg(data, bit);
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
struct iio_trigger *trig;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
ret = bma180_chip_init(data);
if (ret < 0)
goto err_chip_disable;
mutex_init(&data->mutex);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = bma180_channels;
indio_dev->num_channels = ARRAY_SIZE(bma180_channels);
indio_dev->name = BMA180_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &bma180_info;
trig = iio_trigger_alloc("%s-dev%d", indio_dev->name, indio_dev->id);
if (!trig) {
ret = -ENOMEM;
goto err_chip_disable;
}
ret = devm_request_irq(&client->dev, client->irq,
iio_trigger_generic_data_rdy_poll,
IRQF_TRIGGER_RISING, BMA180_IRQ_NAME, trig);
if (ret) {
dev_err(&client->dev, "unable to request IRQ\n");
goto err_trigger_free;
}
trig->dev.parent = &client->dev;
trig->ops = &bma180_trigger_ops;
iio_trigger_set_drvdata(trig, indio_dev);
data->trig = trig;
indio_dev->trig = iio_trigger_get(trig);
ret = iio_trigger_register(trig);
if (ret)
goto err_trigger_free;
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
iio_trigger_unregister(trig);
err_trigger_free:
iio_trigger_free(trig);
err_chip_disable:
bma180_chip_disable(data);
return ret;
}
static int bma180_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct bma180_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
iio_trigger_unregister(data->trig);
iio_trigger_free(data->trig);
mutex_lock(&data->mutex);
bma180_chip_disable(data);
mutex_unlock(&data->mutex);
return 0;
}
static int bma180_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bma180_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bma180_set_sleep_state(data, 1);
mutex_unlock(&data->mutex);
return ret;
}
static int bma180_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct bma180_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = bma180_set_sleep_state(data, 0);
mutex_unlock(&data->mutex);
return ret;
}
