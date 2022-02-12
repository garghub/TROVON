static int stk8ba50_read_accel(struct stk8ba50_data *data, u8 reg)
{
int ret;
struct i2c_client *client = data->client;
ret = i2c_smbus_read_word_data(client, reg);
if (ret < 0) {
dev_err(&client->dev, "register read failed\n");
return ret;
}
return ret;
}
static int stk8ba50_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct stk8ba50_data *data = iio_priv(indio_dev);
int ret;
if (state)
ret = i2c_smbus_write_byte_data(data->client,
STK8BA50_REG_INTEN2, STK8BA50_DREADY_INT_MASK);
else
ret = i2c_smbus_write_byte_data(data->client,
STK8BA50_REG_INTEN2, 0x00);
if (ret < 0)
dev_err(&data->client->dev, "failed to set trigger state\n");
else
data->dready_trigger_on = state;
return ret;
}
static int stk8ba50_set_power(struct stk8ba50_data *data, bool mode)
{
int ret;
u8 masked_reg;
struct i2c_client *client = data->client;
ret = i2c_smbus_read_byte_data(client, STK8BA50_REG_POWMODE);
if (ret < 0)
goto exit_err;
if (mode)
masked_reg = ret | STK8BA50_MODE_POWERBIT;
else
masked_reg = ret & (~STK8BA50_MODE_POWERBIT);
ret = i2c_smbus_write_byte_data(client, STK8BA50_REG_POWMODE,
masked_reg);
if (ret < 0)
goto exit_err;
return ret;
exit_err:
dev_err(&client->dev, "failed to change sensor mode\n");
return ret;
}
static int stk8ba50_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct stk8ba50_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
mutex_lock(&data->lock);
ret = stk8ba50_set_power(data, STK8BA50_MODE_NORMAL);
if (ret < 0) {
mutex_unlock(&data->lock);
return -EINVAL;
}
ret = stk8ba50_read_accel(data, chan->address);
if (ret < 0) {
stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
mutex_unlock(&data->lock);
return -EINVAL;
}
*val = sign_extend32(ret >> STK8BA50_DATA_SHIFT, 9);
stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
mutex_unlock(&data->lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = stk8ba50_scale_table[data->range].scale_val;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = stk8ba50_samp_freq_table
[data->sample_rate_idx].samp_freq;
*val2 = 0;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int stk8ba50_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int ret;
int i;
int index = -1;
struct stk8ba50_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
if (val != 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(stk8ba50_scale_table); i++)
if (val2 == stk8ba50_scale_table[i].scale_val) {
index = i;
break;
}
if (index < 0)
return -EINVAL;
ret = i2c_smbus_write_byte_data(data->client,
STK8BA50_REG_RANGE,
stk8ba50_scale_table[index].reg_val);
if (ret < 0)
dev_err(&data->client->dev,
"failed to set measurement range\n");
else
data->range = index;
return ret;
case IIO_CHAN_INFO_SAMP_FREQ:
for (i = 0; i < ARRAY_SIZE(stk8ba50_samp_freq_table); i++)
if (val == stk8ba50_samp_freq_table[i].samp_freq) {
index = i;
break;
}
if (index < 0)
return -EINVAL;
ret = i2c_smbus_write_byte_data(data->client,
STK8BA50_REG_BWSEL,
stk8ba50_samp_freq_table[index].reg_val);
if (ret < 0)
dev_err(&data->client->dev,
"failed to set sampling rate\n");
else
data->sample_rate_idx = index;
return ret;
}
return -EINVAL;
}
static irqreturn_t stk8ba50_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct stk8ba50_data *data = iio_priv(indio_dev);
int bit, ret, i = 0;
mutex_lock(&data->lock);
if (*(indio_dev->active_scan_mask) == STK8BA50_ALL_CHANNEL_MASK) {
ret = i2c_smbus_read_i2c_block_data(data->client,
STK8BA50_REG_XOUT,
STK8BA50_ALL_CHANNEL_SIZE,
(u8 *)data->buffer);
if (ret < STK8BA50_ALL_CHANNEL_SIZE) {
dev_err(&data->client->dev, "register read failed\n");
goto err;
}
} else {
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = stk8ba50_read_accel(data,
stk8ba50_channel_table[bit]);
if (ret < 0)
goto err;
data->buffer[i++] = ret;
}
}
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
pf->timestamp);
err:
mutex_unlock(&data->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static irqreturn_t stk8ba50_data_rdy_trig_poll(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct stk8ba50_data *data = iio_priv(indio_dev);
if (data->dready_trigger_on)
iio_trigger_poll(data->dready_trig);
return IRQ_HANDLED;
}
static int stk8ba50_buffer_preenable(struct iio_dev *indio_dev)
{
struct stk8ba50_data *data = iio_priv(indio_dev);
return stk8ba50_set_power(data, STK8BA50_MODE_NORMAL);
}
static int stk8ba50_buffer_postdisable(struct iio_dev *indio_dev)
{
struct stk8ba50_data *data = iio_priv(indio_dev);
return stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
}
static int stk8ba50_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct stk8ba50_data *data;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev) {
dev_err(&client->dev, "iio allocation failed!\n");
return -ENOMEM;
}
data = iio_priv(indio_dev);
data->client = client;
i2c_set_clientdata(client, indio_dev);
mutex_init(&data->lock);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &stk8ba50_info;
indio_dev->name = STK8BA50_DRIVER_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = stk8ba50_channels;
indio_dev->num_channels = ARRAY_SIZE(stk8ba50_channels);
ret = i2c_smbus_write_byte_data(client,
STK8BA50_REG_SWRST, STK8BA50_RESET_CMD);
if (ret < 0) {
dev_err(&client->dev, "failed to reset sensor\n");
goto err_power_off;
}
data->range = 0;
data->sample_rate_idx = STK8BA50_SR_1792HZ_IDX;
ret = i2c_smbus_write_byte_data(client,
STK8BA50_REG_INTEN2, STK8BA50_DREADY_INT_MASK);
if (ret < 0) {
dev_err(&client->dev, "failed to set up interrupts\n");
goto err_power_off;
}
ret = i2c_smbus_write_byte_data(client,
STK8BA50_REG_INTMAP2, STK8BA50_DREADY_INT_MAP);
if (ret < 0) {
dev_err(&client->dev, "failed to set up interrupts\n");
goto err_power_off;
}
if (client->irq > 0) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
stk8ba50_data_rdy_trig_poll,
NULL,
IRQF_TRIGGER_RISING |
IRQF_ONESHOT,
STK8BA50_IRQ_NAME,
indio_dev);
if (ret < 0) {
dev_err(&client->dev, "request irq %d failed\n",
client->irq);
goto err_power_off;
}
data->dready_trig = devm_iio_trigger_alloc(&client->dev,
"%s-dev%d",
indio_dev->name,
indio_dev->id);
if (!data->dready_trig) {
ret = -ENOMEM;
goto err_power_off;
}
data->dready_trig->dev.parent = &client->dev;
data->dready_trig->ops = &stk8ba50_trigger_ops;
iio_trigger_set_drvdata(data->dready_trig, indio_dev);
ret = iio_trigger_register(data->dready_trig);
if (ret) {
dev_err(&client->dev, "iio trigger register failed\n");
goto err_power_off;
}
}
ret = iio_triggered_buffer_setup(indio_dev,
iio_pollfunc_store_time,
stk8ba50_trigger_handler,
&stk8ba50_buffer_setup_ops);
if (ret < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
goto err_trigger_unregister;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
goto err_buffer_cleanup;
}
return ret;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
err_power_off:
stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
return ret;
}
static int stk8ba50_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct stk8ba50_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
return stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
}
static int stk8ba50_suspend(struct device *dev)
{
struct stk8ba50_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8ba50_set_power(data, STK8BA50_MODE_SUSPEND);
}
static int stk8ba50_resume(struct device *dev)
{
struct stk8ba50_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8ba50_set_power(data, STK8BA50_MODE_NORMAL);
}
