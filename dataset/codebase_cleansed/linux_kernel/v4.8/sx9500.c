static int sx9500_inc_users(struct sx9500_data *data, int *counter,
unsigned int reg, unsigned int bitmask)
{
(*counter)++;
if (*counter != 1)
return 0;
return regmap_update_bits(data->regmap, reg, bitmask, bitmask);
}
static int sx9500_dec_users(struct sx9500_data *data, int *counter,
unsigned int reg, unsigned int bitmask)
{
(*counter)--;
if (*counter != 0)
return 0;
return regmap_update_bits(data->regmap, reg, bitmask, 0);
}
static int sx9500_inc_chan_users(struct sx9500_data *data, int chan)
{
return sx9500_inc_users(data, &data->channel_users[chan],
SX9500_REG_PROX_CTRL0, BIT(chan));
}
static int sx9500_dec_chan_users(struct sx9500_data *data, int chan)
{
return sx9500_dec_users(data, &data->channel_users[chan],
SX9500_REG_PROX_CTRL0, BIT(chan));
}
static int sx9500_inc_data_rdy_users(struct sx9500_data *data)
{
return sx9500_inc_users(data, &data->data_rdy_users,
SX9500_REG_IRQ_MSK, SX9500_CONVDONE_IRQ);
}
static int sx9500_dec_data_rdy_users(struct sx9500_data *data)
{
return sx9500_dec_users(data, &data->data_rdy_users,
SX9500_REG_IRQ_MSK, SX9500_CONVDONE_IRQ);
}
static int sx9500_inc_close_far_users(struct sx9500_data *data)
{
return sx9500_inc_users(data, &data->close_far_users,
SX9500_REG_IRQ_MSK,
SX9500_CLOSE_IRQ | SX9500_FAR_IRQ);
}
static int sx9500_dec_close_far_users(struct sx9500_data *data)
{
return sx9500_dec_users(data, &data->close_far_users,
SX9500_REG_IRQ_MSK,
SX9500_CLOSE_IRQ | SX9500_FAR_IRQ);
}
static int sx9500_read_prox_data(struct sx9500_data *data,
const struct iio_chan_spec *chan,
int *val)
{
int ret;
__be16 regval;
ret = regmap_write(data->regmap, SX9500_REG_SENSOR_SEL, chan->channel);
if (ret < 0)
return ret;
ret = regmap_bulk_read(data->regmap, SX9500_REG_USE_MSB, &regval, 2);
if (ret < 0)
return ret;
*val = be16_to_cpu(regval);
return IIO_VAL_INT;
}
static int sx9500_wait_for_sample(struct sx9500_data *data)
{
int ret;
unsigned int val;
ret = regmap_read(data->regmap, SX9500_REG_PROX_CTRL0, &val);
if (ret < 0)
return ret;
val = (val & SX9500_SCAN_PERIOD_MASK) >> SX9500_SCAN_PERIOD_SHIFT;
msleep(sx9500_scan_period_table[val]);
return 0;
}
static int sx9500_read_proximity(struct sx9500_data *data,
const struct iio_chan_spec *chan,
int *val)
{
int ret;
mutex_lock(&data->mutex);
ret = sx9500_inc_chan_users(data, chan->channel);
if (ret < 0)
goto out;
ret = sx9500_inc_data_rdy_users(data);
if (ret < 0)
goto out_dec_chan;
mutex_unlock(&data->mutex);
if (data->client->irq > 0)
ret = wait_for_completion_interruptible(&data->completion);
else
ret = sx9500_wait_for_sample(data);
mutex_lock(&data->mutex);
if (ret < 0)
goto out_dec_data_rdy;
ret = sx9500_read_prox_data(data, chan, val);
if (ret < 0)
goto out_dec_data_rdy;
ret = sx9500_dec_data_rdy_users(data);
if (ret < 0)
goto out_dec_chan;
ret = sx9500_dec_chan_users(data, chan->channel);
if (ret < 0)
goto out;
ret = IIO_VAL_INT;
goto out;
out_dec_data_rdy:
sx9500_dec_data_rdy_users(data);
out_dec_chan:
sx9500_dec_chan_users(data, chan->channel);
out:
mutex_unlock(&data->mutex);
reinit_completion(&data->completion);
return ret;
}
static int sx9500_read_samp_freq(struct sx9500_data *data,
int *val, int *val2)
{
int ret;
unsigned int regval;
mutex_lock(&data->mutex);
ret = regmap_read(data->regmap, SX9500_REG_PROX_CTRL0, &regval);
mutex_unlock(&data->mutex);
if (ret < 0)
return ret;
regval = (regval & SX9500_SCAN_PERIOD_MASK) >> SX9500_SCAN_PERIOD_SHIFT;
*val = sx9500_samp_freq_table[regval].val;
*val2 = sx9500_samp_freq_table[regval].val2;
return IIO_VAL_INT_PLUS_MICRO;
}
static int sx9500_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long mask)
{
struct sx9500_data *data = iio_priv(indio_dev);
switch (chan->type) {
case IIO_PROXIMITY:
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
return sx9500_read_proximity(data, chan, val);
case IIO_CHAN_INFO_SAMP_FREQ:
return sx9500_read_samp_freq(data, val, val2);
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int sx9500_set_samp_freq(struct sx9500_data *data,
int val, int val2)
{
int i, ret;
for (i = 0; i < ARRAY_SIZE(sx9500_samp_freq_table); i++)
if (val == sx9500_samp_freq_table[i].val &&
val2 == sx9500_samp_freq_table[i].val2)
break;
if (i == ARRAY_SIZE(sx9500_samp_freq_table))
return -EINVAL;
mutex_lock(&data->mutex);
ret = regmap_update_bits(data->regmap, SX9500_REG_PROX_CTRL0,
SX9500_SCAN_PERIOD_MASK,
i << SX9500_SCAN_PERIOD_SHIFT);
mutex_unlock(&data->mutex);
return ret;
}
static int sx9500_write_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int val, int val2, long mask)
{
struct sx9500_data *data = iio_priv(indio_dev);
switch (chan->type) {
case IIO_PROXIMITY:
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
return sx9500_set_samp_freq(data, val, val2);
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static irqreturn_t sx9500_irq_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct sx9500_data *data = iio_priv(indio_dev);
if (data->trigger_enabled)
iio_trigger_poll(data->trig);
return IRQ_WAKE_THREAD;
}
static void sx9500_push_events(struct iio_dev *indio_dev)
{
int ret;
unsigned int val, chan;
struct sx9500_data *data = iio_priv(indio_dev);
ret = regmap_read(data->regmap, SX9500_REG_STAT, &val);
if (ret < 0) {
dev_err(&data->client->dev, "i2c transfer error in irq\n");
return;
}
val >>= SX9500_PROXSTAT_SHIFT;
for (chan = 0; chan < SX9500_NUM_CHANNELS; chan++) {
int dir;
u64 ev;
bool new_prox = val & BIT(chan);
if (!data->event_enabled[chan])
continue;
if (new_prox == data->prox_stat[chan])
continue;
dir = new_prox ? IIO_EV_DIR_FALLING : IIO_EV_DIR_RISING;
ev = IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY, chan,
IIO_EV_TYPE_THRESH, dir);
iio_push_event(indio_dev, ev, iio_get_time_ns(indio_dev));
data->prox_stat[chan] = new_prox;
}
}
static irqreturn_t sx9500_irq_thread_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct sx9500_data *data = iio_priv(indio_dev);
int ret;
unsigned int val;
mutex_lock(&data->mutex);
ret = regmap_read(data->regmap, SX9500_REG_IRQ_SRC, &val);
if (ret < 0) {
dev_err(&data->client->dev, "i2c transfer error in irq\n");
goto out;
}
if (val & (SX9500_CLOSE_IRQ | SX9500_FAR_IRQ))
sx9500_push_events(indio_dev);
if (val & SX9500_CONVDONE_IRQ)
complete_all(&data->completion);
out:
mutex_unlock(&data->mutex);
return IRQ_HANDLED;
}
static int sx9500_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct sx9500_data *data = iio_priv(indio_dev);
if (chan->type != IIO_PROXIMITY || type != IIO_EV_TYPE_THRESH ||
dir != IIO_EV_DIR_EITHER)
return -EINVAL;
return data->event_enabled[chan->channel];
}
static int sx9500_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct sx9500_data *data = iio_priv(indio_dev);
int ret;
if (chan->type != IIO_PROXIMITY || type != IIO_EV_TYPE_THRESH ||
dir != IIO_EV_DIR_EITHER)
return -EINVAL;
mutex_lock(&data->mutex);
if (state == 1) {
ret = sx9500_inc_chan_users(data, chan->channel);
if (ret < 0)
goto out_unlock;
ret = sx9500_inc_close_far_users(data);
if (ret < 0)
goto out_undo_chan;
} else {
ret = sx9500_dec_chan_users(data, chan->channel);
if (ret < 0)
goto out_unlock;
ret = sx9500_dec_close_far_users(data);
if (ret < 0)
goto out_undo_chan;
}
data->event_enabled[chan->channel] = state;
goto out_unlock;
out_undo_chan:
if (state == 1)
sx9500_dec_chan_users(data, chan->channel);
else
sx9500_inc_chan_users(data, chan->channel);
out_unlock:
mutex_unlock(&data->mutex);
return ret;
}
static int sx9500_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct sx9500_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
kfree(data->buffer);
data->buffer = kzalloc(indio_dev->scan_bytes, GFP_KERNEL);
mutex_unlock(&data->mutex);
if (data->buffer == NULL)
return -ENOMEM;
return 0;
}
static int sx9500_set_trigger_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct sx9500_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
if (state)
ret = sx9500_inc_data_rdy_users(data);
else
ret = sx9500_dec_data_rdy_users(data);
if (ret < 0)
goto out;
data->trigger_enabled = state;
out:
mutex_unlock(&data->mutex);
return ret;
}
static irqreturn_t sx9500_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *indio_dev = pf->indio_dev;
struct sx9500_data *data = iio_priv(indio_dev);
int val, bit, ret, i = 0;
mutex_lock(&data->mutex);
for_each_set_bit(bit, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = sx9500_read_prox_data(data, &indio_dev->channels[bit],
&val);
if (ret < 0)
goto out;
data->buffer[i++] = val;
}
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns(indio_dev));
out:
mutex_unlock(&data->mutex);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int sx9500_buffer_preenable(struct iio_dev *indio_dev)
{
struct sx9500_data *data = iio_priv(indio_dev);
int ret = 0, i;
mutex_lock(&data->mutex);
for (i = 0; i < SX9500_NUM_CHANNELS; i++)
if (test_bit(i, indio_dev->active_scan_mask)) {
ret = sx9500_inc_chan_users(data, i);
if (ret)
break;
}
if (ret)
for (i = i - 1; i >= 0; i--)
if (test_bit(i, indio_dev->active_scan_mask))
sx9500_dec_chan_users(data, i);
mutex_unlock(&data->mutex);
return ret;
}
static int sx9500_buffer_predisable(struct iio_dev *indio_dev)
{
struct sx9500_data *data = iio_priv(indio_dev);
int ret = 0, i;
iio_triggered_buffer_predisable(indio_dev);
mutex_lock(&data->mutex);
for (i = 0; i < SX9500_NUM_CHANNELS; i++)
if (test_bit(i, indio_dev->active_scan_mask)) {
ret = sx9500_dec_chan_users(data, i);
if (ret)
break;
}
if (ret)
for (i = i - 1; i >= 0; i--)
if (test_bit(i, indio_dev->active_scan_mask))
sx9500_inc_chan_users(data, i);
mutex_unlock(&data->mutex);
return ret;
}
static int sx9500_init_compensation(struct iio_dev *indio_dev)
{
struct sx9500_data *data = iio_priv(indio_dev);
int i, ret;
unsigned int val;
ret = regmap_update_bits(data->regmap, SX9500_REG_PROX_CTRL0,
SX9500_CHAN_MASK, SX9500_CHAN_MASK);
if (ret < 0)
return ret;
for (i = 10; i >= 0; i--) {
usleep_range(10000, 20000);
ret = regmap_read(data->regmap, SX9500_REG_STAT, &val);
if (ret < 0)
goto out;
if (!(val & SX9500_COMPSTAT_MASK))
break;
}
if (i < 0) {
dev_err(&data->client->dev, "initial compensation timed out");
ret = -ETIMEDOUT;
}
out:
regmap_update_bits(data->regmap, SX9500_REG_PROX_CTRL0,
SX9500_CHAN_MASK, 0);
return ret;
}
static int sx9500_init_device(struct iio_dev *indio_dev)
{
struct sx9500_data *data = iio_priv(indio_dev);
int ret, i;
unsigned int val;
if (data->gpiod_rst) {
gpiod_set_value_cansleep(data->gpiod_rst, 0);
usleep_range(1000, 2000);
gpiod_set_value_cansleep(data->gpiod_rst, 1);
usleep_range(1000, 2000);
}
ret = regmap_write(data->regmap, SX9500_REG_IRQ_MSK, 0);
if (ret < 0)
return ret;
ret = regmap_write(data->regmap, SX9500_REG_RESET,
SX9500_SOFT_RESET);
if (ret < 0)
return ret;
ret = regmap_read(data->regmap, SX9500_REG_IRQ_SRC, &val);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(sx9500_default_regs); i++) {
ret = regmap_write(data->regmap,
sx9500_default_regs[i].reg,
sx9500_default_regs[i].def);
if (ret < 0)
return ret;
}
return sx9500_init_compensation(indio_dev);
}
static void sx9500_gpio_probe(struct i2c_client *client,
struct sx9500_data *data)
{
struct device *dev;
if (!client)
return;
dev = &client->dev;
data->gpiod_rst = devm_gpiod_get_index(dev, SX9500_GPIO_RESET,
0, GPIOD_OUT_HIGH);
if (IS_ERR(data->gpiod_rst)) {
dev_warn(dev, "gpio get reset pin failed\n");
data->gpiod_rst = NULL;
}
}
static int sx9500_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct iio_dev *indio_dev;
struct sx9500_data *data;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
data->client = client;
mutex_init(&data->mutex);
init_completion(&data->completion);
data->trigger_enabled = false;
data->regmap = devm_regmap_init_i2c(client, &sx9500_regmap_config);
if (IS_ERR(data->regmap))
return PTR_ERR(data->regmap);
indio_dev->dev.parent = &client->dev;
indio_dev->name = SX9500_DRIVER_NAME;
indio_dev->channels = sx9500_channels;
indio_dev->num_channels = ARRAY_SIZE(sx9500_channels);
indio_dev->info = &sx9500_info;
indio_dev->modes = INDIO_DIRECT_MODE;
i2c_set_clientdata(client, indio_dev);
sx9500_gpio_probe(client, data);
ret = sx9500_init_device(indio_dev);
if (ret < 0)
return ret;
if (client->irq <= 0)
dev_warn(&client->dev, "no valid irq found\n");
else {
ret = devm_request_threaded_irq(&client->dev, client->irq,
sx9500_irq_handler, sx9500_irq_thread_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
SX9500_IRQ_NAME, indio_dev);
if (ret < 0)
return ret;
data->trig = devm_iio_trigger_alloc(&client->dev,
"%s-dev%d", indio_dev->name, indio_dev->id);
if (!data->trig)
return -ENOMEM;
data->trig->dev.parent = &client->dev;
data->trig->ops = &sx9500_trigger_ops;
iio_trigger_set_drvdata(data->trig, indio_dev);
ret = iio_trigger_register(data->trig);
if (ret)
return ret;
}
ret = iio_triggered_buffer_setup(indio_dev, NULL,
sx9500_trigger_handler,
&sx9500_buffer_setup_ops);
if (ret < 0)
goto out_trigger_unregister;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto out_buffer_cleanup;
return 0;
out_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
out_trigger_unregister:
if (client->irq > 0)
iio_trigger_unregister(data->trig);
return ret;
}
static int sx9500_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct sx9500_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (client->irq > 0)
iio_trigger_unregister(data->trig);
kfree(data->buffer);
return 0;
}
static int sx9500_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct sx9500_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = regmap_read(data->regmap, SX9500_REG_PROX_CTRL0,
&data->suspend_ctrl0);
if (ret < 0)
goto out;
ret = regmap_write(data->regmap, SX9500_REG_PROX_CTRL0, 0);
out:
mutex_unlock(&data->mutex);
return ret;
}
static int sx9500_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct sx9500_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = regmap_write(data->regmap, SX9500_REG_PROX_CTRL0,
data->suspend_ctrl0);
mutex_unlock(&data->mutex);
return ret;
}
