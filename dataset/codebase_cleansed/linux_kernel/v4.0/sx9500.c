static int sx9500_read_proximity(struct sx9500_data *data,
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
*val = 32767 - (s16)be16_to_cpu(regval);
return IIO_VAL_INT;
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
int ret;
switch (chan->type) {
case IIO_PROXIMITY:
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
mutex_lock(&data->mutex);
ret = sx9500_read_proximity(data, chan, val);
mutex_unlock(&data->mutex);
return ret;
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
static irqreturn_t sx9500_irq_thread_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct sx9500_data *data = iio_priv(indio_dev);
int ret;
unsigned int val, chan;
mutex_lock(&data->mutex);
ret = regmap_read(data->regmap, SX9500_REG_IRQ_SRC, &val);
if (ret < 0) {
dev_err(&data->client->dev, "i2c transfer error in irq\n");
goto out;
}
if (!(val & (SX9500_CLOSE_IRQ | SX9500_FAR_IRQ)))
goto out;
ret = regmap_read(data->regmap, SX9500_REG_STAT, &val);
if (ret < 0) {
dev_err(&data->client->dev, "i2c transfer error in irq\n");
goto out;
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
dir = new_prox ? IIO_EV_DIR_FALLING :
IIO_EV_DIR_RISING;
ev = IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY,
chan,
IIO_EV_TYPE_THRESH,
dir);
iio_push_event(indio_dev, ev, iio_get_time_ns());
data->prox_stat[chan] = new_prox;
}
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
int ret, i;
bool any_active = false;
unsigned int irqmask;
if (chan->type != IIO_PROXIMITY || type != IIO_EV_TYPE_THRESH ||
dir != IIO_EV_DIR_EITHER)
return -EINVAL;
mutex_lock(&data->mutex);
data->event_enabled[chan->channel] = state;
for (i = 0; i < SX9500_NUM_CHANNELS; i++)
if (data->event_enabled[i]) {
any_active = true;
break;
}
irqmask = SX9500_CLOSE_IRQ | SX9500_FAR_IRQ;
if (any_active)
ret = regmap_update_bits(data->regmap, SX9500_REG_IRQ_MSK,
irqmask, irqmask);
else
ret = regmap_update_bits(data->regmap, SX9500_REG_IRQ_MSK,
irqmask, 0);
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
ret = regmap_update_bits(data->regmap, SX9500_REG_IRQ_MSK,
SX9500_CONVDONE_IRQ,
state ? SX9500_CONVDONE_IRQ : 0);
if (ret == 0)
data->trigger_enabled = state;
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
ret = sx9500_read_proximity(data, &indio_dev->channels[bit],
&val);
if (ret < 0)
goto out;
data->buffer[i++] = val;
}
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns());
out:
mutex_unlock(&data->mutex);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int sx9500_init_device(struct iio_dev *indio_dev)
{
struct sx9500_data *data = iio_priv(indio_dev);
int ret, i;
unsigned int val;
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
return 0;
}
static int sx9500_gpio_probe(struct i2c_client *client,
struct sx9500_data *data)
{
struct device *dev;
struct gpio_desc *gpio;
int ret;
if (!client)
return -EINVAL;
dev = &client->dev;
gpio = devm_gpiod_get_index(dev, SX9500_GPIO_NAME, 0);
if (IS_ERR(gpio)) {
dev_err(dev, "acpi gpio get index failed\n");
return PTR_ERR(gpio);
}
ret = gpiod_direction_input(gpio);
if (ret)
return ret;
ret = gpiod_to_irq(gpio);
dev_dbg(dev, "GPIO resource, no:%d irq:%d\n", desc_to_gpio(gpio), ret);
return ret;
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
data->trigger_enabled = false;
data->regmap = devm_regmap_init_i2c(client, &sx9500_regmap_config);
if (IS_ERR(data->regmap))
return PTR_ERR(data->regmap);
sx9500_init_device(indio_dev);
indio_dev->dev.parent = &client->dev;
indio_dev->name = SX9500_DRIVER_NAME;
indio_dev->channels = sx9500_channels;
indio_dev->num_channels = ARRAY_SIZE(sx9500_channels);
indio_dev->info = &sx9500_info;
indio_dev->modes = INDIO_DIRECT_MODE;
i2c_set_clientdata(client, indio_dev);
if (client->irq <= 0)
client->irq = sx9500_gpio_probe(client, data);
if (client->irq > 0) {
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
sx9500_trigger_handler, NULL);
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
