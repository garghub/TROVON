static int stk8312_otp_init(struct stk8312_data *data)
{
int ret;
int count = 10;
struct i2c_client *client = data->client;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_OTPADDR, 0x70);
if (ret < 0)
goto exit_err;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_OTPCTRL, 0x02);
if (ret < 0)
goto exit_err;
do {
usleep_range(1000, 5000);
ret = i2c_smbus_read_byte_data(client, STK8312_REG_OTPCTRL);
if (ret < 0)
goto exit_err;
count--;
} while (!(ret & BIT(7)) && count > 0);
if (count == 0) {
ret = -ETIMEDOUT;
goto exit_err;
}
ret = i2c_smbus_read_byte_data(client, STK8312_REG_OTPDATA);
if (ret == 0)
ret = -EINVAL;
if (ret < 0)
goto exit_err;
ret = i2c_smbus_write_byte_data(data->client, STK8312_REG_AFECTRL, ret);
if (ret < 0)
goto exit_err;
msleep(150);
return 0;
exit_err:
dev_err(&client->dev, "failed to initialize sensor\n");
return ret;
}
static int stk8312_set_mode(struct stk8312_data *data, u8 mode)
{
int ret;
struct i2c_client *client = data->client;
if (mode == data->mode)
return 0;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_MODE, mode);
if (ret < 0) {
dev_err(&client->dev, "failed to change sensor mode\n");
return ret;
}
data->mode = mode;
if (mode & STK8312_MODE_ACTIVE) {
usleep_range(1000, 5000);
ret = stk8312_otp_init(data);
}
return ret;
}
static int stk8312_set_interrupts(struct stk8312_data *data, u8 int_mask)
{
int ret;
u8 mode;
struct i2c_client *client = data->client;
mode = data->mode;
ret = stk8312_set_mode(data, STK8312_MODE_STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_INTSU, int_mask);
if (ret < 0) {
dev_err(&client->dev, "failed to set interrupts\n");
stk8312_set_mode(data, mode);
return ret;
}
return stk8312_set_mode(data, mode);
}
static int stk8312_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct stk8312_data *data = iio_priv(indio_dev);
int ret;
if (state)
ret = stk8312_set_interrupts(data, STK8312_DREADY_BIT);
else
ret = stk8312_set_interrupts(data, 0x00);
if (ret < 0) {
dev_err(&data->client->dev, "failed to set trigger state\n");
return ret;
}
data->dready_trigger_on = state;
return 0;
}
static int stk8312_set_sample_rate(struct stk8312_data *data, u8 rate)
{
int ret;
u8 masked_reg;
u8 mode;
struct i2c_client *client = data->client;
if (rate == data->sample_rate_idx)
return 0;
mode = data->mode;
ret = stk8312_set_mode(data, STK8312_MODE_STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(client, STK8312_REG_SR);
if (ret < 0)
goto err_activate;
masked_reg = (ret & (~STK8312_SR_MASK)) | rate;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_SR, masked_reg);
if (ret < 0)
goto err_activate;
data->sample_rate_idx = rate;
return stk8312_set_mode(data, mode);
err_activate:
dev_err(&client->dev, "failed to set sampling rate\n");
stk8312_set_mode(data, mode);
return ret;
}
static int stk8312_set_range(struct stk8312_data *data, u8 range)
{
int ret;
u8 masked_reg;
u8 mode;
struct i2c_client *client = data->client;
if (range != 1 && range != 2)
return -EINVAL;
else if (range == data->range)
return 0;
mode = data->mode;
ret = stk8312_set_mode(data, STK8312_MODE_STANDBY);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(client, STK8312_REG_STH);
if (ret < 0)
goto err_activate;
masked_reg = ret & (~STK8312_RNG_MASK);
masked_reg |= range << STK8312_RNG_SHIFT;
ret = i2c_smbus_write_byte_data(client, STK8312_REG_STH, masked_reg);
if (ret < 0)
goto err_activate;
data->range = range;
return stk8312_set_mode(data, mode);
err_activate:
dev_err(&client->dev, "failed to change sensor range\n");
stk8312_set_mode(data, mode);
return ret;
}
static int stk8312_read_accel(struct stk8312_data *data, u8 address)
{
int ret;
struct i2c_client *client = data->client;
if (address > 2)
return -EINVAL;
ret = i2c_smbus_read_byte_data(client, address);
if (ret < 0)
dev_err(&client->dev, "register read failed\n");
return ret;
}
static int stk8312_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct stk8312_data *data = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
mutex_lock(&data->lock);
ret = stk8312_set_mode(data, data->mode | STK8312_MODE_ACTIVE);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
}
ret = stk8312_read_accel(data, chan->address);
if (ret < 0) {
stk8312_set_mode(data,
data->mode & (~STK8312_MODE_ACTIVE));
mutex_unlock(&data->lock);
return ret;
}
*val = sign_extend32(ret, 7);
ret = stk8312_set_mode(data,
data->mode & (~STK8312_MODE_ACTIVE));
mutex_unlock(&data->lock);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = stk8312_scale_table[data->range - 1][0];
*val2 = stk8312_scale_table[data->range - 1][1];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = stk8312_samp_freq_table[data->sample_rate_idx].val;
*val2 = stk8312_samp_freq_table[data->sample_rate_idx].val2;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int stk8312_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int i;
int index = -1;
int ret;
struct stk8312_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
for (i = 0; i < ARRAY_SIZE(stk8312_scale_table); i++)
if (val == stk8312_scale_table[i][0] &&
val2 == stk8312_scale_table[i][1]) {
index = i + 1;
break;
}
if (index < 0)
return -EINVAL;
mutex_lock(&data->lock);
ret = stk8312_set_range(data, index);
mutex_unlock(&data->lock);
return ret;
case IIO_CHAN_INFO_SAMP_FREQ:
for (i = 0; i < ARRAY_SIZE(stk8312_samp_freq_table); i++)
if (val == stk8312_samp_freq_table[i].val &&
val2 == stk8312_samp_freq_table[i].val2) {
index = i;
break;
}
if (index < 0)
return -EINVAL;
mutex_lock(&data->lock);
ret = stk8312_set_sample_rate(data, index);
mutex_unlock(&data->lock);
return ret;
}
return -EINVAL;
}
static irqreturn_t stk8312_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct stk8312_data *data = iio_priv(indio_dev);
int bit, ret, i = 0;
mutex_lock(&data->lock);
if (*(indio_dev->active_scan_mask) == STK8312_ALL_CHANNEL_MASK) {
ret = i2c_smbus_read_i2c_block_data(data->client,
STK8312_REG_XOUT,
STK8312_ALL_CHANNEL_SIZE,
data->buffer);
if (ret < STK8312_ALL_CHANNEL_SIZE) {
dev_err(&data->client->dev, "register read failed\n");
mutex_unlock(&data->lock);
goto err;
}
} else {
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = stk8312_read_accel(data, bit);
if (ret < 0) {
mutex_unlock(&data->lock);
goto err;
}
data->buffer[i++] = ret;
}
}
mutex_unlock(&data->lock);
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
pf->timestamp);
err:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static irqreturn_t stk8312_data_rdy_trig_poll(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct stk8312_data *data = iio_priv(indio_dev);
if (data->dready_trigger_on)
iio_trigger_poll(data->dready_trig);
return IRQ_HANDLED;
}
static int stk8312_buffer_preenable(struct iio_dev *indio_dev)
{
struct stk8312_data *data = iio_priv(indio_dev);
return stk8312_set_mode(data, data->mode | STK8312_MODE_ACTIVE);
}
static int stk8312_buffer_postdisable(struct iio_dev *indio_dev)
{
struct stk8312_data *data = iio_priv(indio_dev);
return stk8312_set_mode(data, data->mode & (~STK8312_MODE_ACTIVE));
}
static int stk8312_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct stk8312_data *data;
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
indio_dev->info = &stk8312_info;
indio_dev->name = STK8312_DRIVER_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = stk8312_channels;
indio_dev->num_channels = ARRAY_SIZE(stk8312_channels);
ret = i2c_smbus_write_byte_data(data->client, STK8312_REG_RESET, 0x00);
if (ret < 0) {
dev_err(&client->dev, "failed to reset sensor\n");
return ret;
}
data->sample_rate_idx = STK8312_SR_400HZ_IDX;
ret = stk8312_set_range(data, STK8312_RNG_6G);
if (ret < 0)
return ret;
ret = stk8312_set_mode(data,
STK8312_MODE_INT_AH_PP | STK8312_MODE_ACTIVE);
if (ret < 0)
return ret;
if (client->irq > 0) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
stk8312_data_rdy_trig_poll,
NULL,
IRQF_TRIGGER_RISING |
IRQF_ONESHOT,
STK8312_IRQ_NAME,
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
data->dready_trig->ops = &stk8312_trigger_ops;
iio_trigger_set_drvdata(data->dready_trig, indio_dev);
ret = iio_trigger_register(data->dready_trig);
if (ret) {
dev_err(&client->dev, "iio trigger register failed\n");
goto err_power_off;
}
}
ret = iio_triggered_buffer_setup(indio_dev,
iio_pollfunc_store_time,
stk8312_trigger_handler,
&stk8312_buffer_setup_ops);
if (ret < 0) {
dev_err(&client->dev, "iio triggered buffer setup failed\n");
goto err_trigger_unregister;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&client->dev, "device_register failed\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_trigger_unregister:
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
err_power_off:
stk8312_set_mode(data, STK8312_MODE_STANDBY);
return ret;
}
static int stk8312_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct stk8312_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (data->dready_trig)
iio_trigger_unregister(data->dready_trig);
return stk8312_set_mode(data, STK8312_MODE_STANDBY);
}
static int stk8312_suspend(struct device *dev)
{
struct stk8312_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8312_set_mode(data, data->mode & (~STK8312_MODE_ACTIVE));
}
static int stk8312_resume(struct device *dev)
{
struct stk8312_data *data;
data = iio_priv(i2c_get_clientdata(to_i2c_client(dev)));
return stk8312_set_mode(data, data->mode | STK8312_MODE_ACTIVE);
}
