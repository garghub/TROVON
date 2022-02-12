static int ad799x_write_config(struct ad799x_state *st, u16 val)
{
switch (st->id) {
case ad7997:
case ad7998:
return i2c_smbus_write_word_swapped(st->client, AD7998_CONF_REG,
val);
default:
return i2c_smbus_write_byte_data(st->client, AD7998_CONF_REG,
val);
}
}
static int ad799x_read_config(struct ad799x_state *st)
{
switch (st->id) {
case ad7997:
case ad7998:
return i2c_smbus_read_word_swapped(st->client, AD7998_CONF_REG);
default:
return i2c_smbus_read_byte_data(st->client, AD7998_CONF_REG);
}
}
static irqreturn_t ad799x_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad799x_state *st = iio_priv(indio_dev);
int b_sent;
u8 cmd;
switch (st->id) {
case ad7991:
case ad7995:
case ad7999:
cmd = st->config |
(*indio_dev->active_scan_mask << AD799X_CHANNEL_SHIFT);
break;
case ad7992:
case ad7993:
case ad7994:
cmd = (*indio_dev->active_scan_mask << AD799X_CHANNEL_SHIFT) |
AD7998_CONV_RES_REG;
break;
case ad7997:
case ad7998:
cmd = AD7997_8_READ_SEQUENCE | AD7998_CONV_RES_REG;
break;
default:
cmd = 0;
}
b_sent = i2c_smbus_read_i2c_block_data(st->client,
cmd, st->transfer_size, st->rx_buf);
if (b_sent < 0)
goto out;
iio_push_to_buffers_with_timestamp(indio_dev, st->rx_buf,
iio_get_time_ns());
out:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ad799x_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct ad799x_state *st = iio_priv(indio_dev);
kfree(st->rx_buf);
st->rx_buf = kmalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (!st->rx_buf)
return -ENOMEM;
st->transfer_size = bitmap_weight(scan_mask, indio_dev->masklength) * 2;
switch (st->id) {
case ad7992:
case ad7993:
case ad7994:
case ad7997:
case ad7998:
st->config &= ~(GENMASK(7, 0) << AD799X_CHANNEL_SHIFT);
st->config |= (*scan_mask << AD799X_CHANNEL_SHIFT);
return ad799x_write_config(st, st->config);
default:
return 0;
}
}
static int ad799x_scan_direct(struct ad799x_state *st, unsigned ch)
{
u8 cmd;
switch (st->id) {
case ad7991:
case ad7995:
case ad7999:
cmd = st->config | (BIT(ch) << AD799X_CHANNEL_SHIFT);
break;
case ad7992:
case ad7993:
case ad7994:
cmd = BIT(ch) << AD799X_CHANNEL_SHIFT;
break;
case ad7997:
case ad7998:
cmd = (ch << AD799X_CHANNEL_SHIFT) | AD7997_8_READ_SINGLE;
break;
default:
return -EINVAL;
}
return i2c_smbus_read_word_swapped(st->client, cmd);
}
static int ad799x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret;
struct ad799x_state *st = iio_priv(indio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else
ret = ad799x_scan_direct(st, chan->scan_index);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
*val = (ret >> chan->scan_type.shift) &
GENMASK(chan->scan_type.realbits - 1, 0);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(st->vref);
if (ret < 0)
return ret;
*val = ret / 1000;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static ssize_t ad799x_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad799x_state *st = iio_priv(indio_dev);
int ret = i2c_smbus_read_byte_data(st->client, AD7998_CYCLE_TMR_REG);
if (ret < 0)
return ret;
return sprintf(buf, "%u\n", ad7998_frequencies[ret & AD7998_CYC_MASK]);
}
static ssize_t ad799x_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad799x_state *st = iio_priv(indio_dev);
long val;
int ret, i;
ret = kstrtol(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
ret = i2c_smbus_read_byte_data(st->client, AD7998_CYCLE_TMR_REG);
if (ret < 0)
goto error_ret_mutex;
ret &= ~AD7998_CYC_MASK;
for (i = 0; i < ARRAY_SIZE(ad7998_frequencies); i++)
if (val == ad7998_frequencies[i])
break;
if (i == ARRAY_SIZE(ad7998_frequencies)) {
ret = -EINVAL;
goto error_ret_mutex;
}
ret = i2c_smbus_write_byte_data(st->client, AD7998_CYCLE_TMR_REG,
ret | i);
if (ret < 0)
goto error_ret_mutex;
ret = len;
error_ret_mutex:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad799x_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct ad799x_state *st = iio_priv(indio_dev);
if (!(st->config & AD7998_ALERT_EN))
return 0;
if ((st->config >> AD799X_CHANNEL_SHIFT) & BIT(chan->scan_index))
return 1;
return 0;
}
static int ad799x_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct ad799x_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev)) {
ret = -EBUSY;
goto done;
}
if (state)
st->config |= BIT(chan->scan_index) << AD799X_CHANNEL_SHIFT;
else
st->config &= ~(BIT(chan->scan_index) << AD799X_CHANNEL_SHIFT);
if (st->config >> AD799X_CHANNEL_SHIFT)
st->config |= AD7998_ALERT_EN;
else
st->config &= ~AD7998_ALERT_EN;
ret = ad799x_write_config(st, st->config);
done:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static unsigned int ad799x_threshold_reg(const struct iio_chan_spec *chan,
enum iio_event_direction dir,
enum iio_event_info info)
{
switch (info) {
case IIO_EV_INFO_VALUE:
if (dir == IIO_EV_DIR_FALLING)
return AD7998_DATALOW_REG(chan->channel);
else
return AD7998_DATAHIGH_REG(chan->channel);
case IIO_EV_INFO_HYSTERESIS:
return AD7998_HYST_REG(chan->channel);
default:
return -EINVAL;
}
return 0;
}
static int ad799x_write_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
int ret;
struct ad799x_state *st = iio_priv(indio_dev);
if (val < 0 || val > GENMASK(chan->scan_type.realbits - 1, 0))
return -EINVAL;
mutex_lock(&indio_dev->mlock);
ret = i2c_smbus_write_word_swapped(st->client,
ad799x_threshold_reg(chan, dir, info),
val << chan->scan_type.shift);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad799x_read_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
int ret;
struct ad799x_state *st = iio_priv(indio_dev);
mutex_lock(&indio_dev->mlock);
ret = i2c_smbus_read_word_swapped(st->client,
ad799x_threshold_reg(chan, dir, info));
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
*val = (ret >> chan->scan_type.shift) &
GENMASK(chan->scan_type.realbits - 1 , 0);
return IIO_VAL_INT;
}
static irqreturn_t ad799x_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct ad799x_state *st = iio_priv(private);
int i, ret;
ret = i2c_smbus_read_byte_data(st->client, AD7998_ALERT_STAT_REG);
if (ret <= 0)
goto done;
if (i2c_smbus_write_byte_data(st->client, AD7998_ALERT_STAT_REG,
AD7998_ALERT_STAT_CLEAR) < 0)
goto done;
for (i = 0; i < 8; i++) {
if (ret & BIT(i))
iio_push_event(indio_dev,
i & 0x1 ?
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE,
(i >> 1),
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING) :
IIO_UNMOD_EVENT_CODE(IIO_VOLTAGE,
(i >> 1),
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
iio_get_time_ns());
}
done:
return IRQ_HANDLED;
}
static int ad799x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct ad799x_state *st;
struct iio_dev *indio_dev;
const struct ad799x_chip_info *chip_info =
&ad799x_chip_info_tbl[id->driver_data];
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
st->id = id->driver_data;
if (client->irq > 0 && chip_info->irq_config.info)
st->chip_config = &chip_info->irq_config;
else
st->chip_config = &chip_info->noirq_config;
st->reg = devm_regulator_get(&client->dev, "vcc");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
ret = regulator_enable(st->reg);
if (ret)
return ret;
st->vref = devm_regulator_get(&client->dev, "vref");
if (IS_ERR(st->vref)) {
ret = PTR_ERR(st->vref);
goto error_disable_reg;
}
ret = regulator_enable(st->vref);
if (ret)
goto error_disable_reg;
st->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->name = id->name;
indio_dev->info = st->chip_config->info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_config->channel;
indio_dev->num_channels = chip_info->num_channels;
ret = ad799x_write_config(st, st->chip_config->default_config);
if (ret < 0)
goto error_disable_reg;
ret = ad799x_read_config(st);
if (ret < 0)
goto error_disable_reg;
st->config = ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&ad799x_trigger_handler, NULL);
if (ret)
goto error_disable_vref;
if (client->irq > 0) {
ret = devm_request_threaded_irq(&client->dev,
client->irq,
NULL,
ad799x_event_handler,
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
client->name,
indio_dev);
if (ret)
goto error_cleanup_ring;
}
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_ring;
return 0;
error_cleanup_ring:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_vref:
regulator_disable(st->vref);
error_disable_reg:
regulator_disable(st->reg);
return ret;
}
static int ad799x_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct ad799x_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
regulator_disable(st->vref);
regulator_disable(st->reg);
kfree(st->rx_buf);
return 0;
}
