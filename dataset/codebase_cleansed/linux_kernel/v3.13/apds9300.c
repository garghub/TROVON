static unsigned long apds9300_calculate_lux(u16 ch0, u16 ch1)
{
unsigned long lux, tmp;
if (ch0 == 0)
return 0;
tmp = DIV_ROUND_UP(ch1 * 100, ch0);
if (tmp <= 52) {
lux = 3150 * ch0 - (unsigned long)DIV_ROUND_UP_ULL(ch0
* apds9300_lux_ratio[tmp] * 5930ull, 1000);
} else if (tmp <= 65) {
lux = 2290 * ch0 - 2910 * ch1;
} else if (tmp <= 80) {
lux = 1570 * ch0 - 1800 * ch1;
} else if (tmp <= 130) {
lux = 338 * ch0 - 260 * ch1;
} else {
lux = 0;
}
return lux / 100000;
}
static int apds9300_get_adc_val(struct apds9300_data *data, int adc_number)
{
int ret;
u8 flags = APDS9300_CMD | APDS9300_WORD;
if (!data->power_state)
return -EBUSY;
flags |= adc_number ? APDS9300_DATA1LOW : APDS9300_DATA0LOW;
ret = i2c_smbus_read_word_data(data->client, flags);
if (ret < 0)
dev_err(&data->client->dev,
"failed to read ADC%d value\n", adc_number);
return ret;
}
static int apds9300_set_thresh_low(struct apds9300_data *data, int value)
{
int ret;
if (!data->power_state)
return -EBUSY;
if (value > APDS9300_THRESH_MAX)
return -EINVAL;
ret = i2c_smbus_write_word_data(data->client, APDS9300_THRESHLOWLOW
| APDS9300_CMD | APDS9300_WORD, value);
if (ret) {
dev_err(&data->client->dev, "failed to set thresh_low\n");
return ret;
}
data->thresh_low = value;
return 0;
}
static int apds9300_set_thresh_hi(struct apds9300_data *data, int value)
{
int ret;
if (!data->power_state)
return -EBUSY;
if (value > APDS9300_THRESH_MAX)
return -EINVAL;
ret = i2c_smbus_write_word_data(data->client, APDS9300_THRESHHIGHLOW
| APDS9300_CMD | APDS9300_WORD, value);
if (ret) {
dev_err(&data->client->dev, "failed to set thresh_hi\n");
return ret;
}
data->thresh_hi = value;
return 0;
}
static int apds9300_set_intr_state(struct apds9300_data *data, int state)
{
int ret;
u8 cmd;
if (!data->power_state)
return -EBUSY;
cmd = state ? APDS9300_INTR_ENABLE | APDS9300_THRESH_INTR : 0x00;
ret = i2c_smbus_write_byte_data(data->client,
APDS9300_INTERRUPT | APDS9300_CMD, cmd);
if (ret) {
dev_err(&data->client->dev,
"failed to set interrupt state %d\n", state);
return ret;
}
data->intr_en = state;
return 0;
}
static int apds9300_set_power_state(struct apds9300_data *data, int state)
{
int ret;
u8 cmd;
cmd = state ? APDS9300_POWER_ON : APDS9300_POWER_OFF;
ret = i2c_smbus_write_byte_data(data->client,
APDS9300_CONTROL | APDS9300_CMD, cmd);
if (ret) {
dev_err(&data->client->dev,
"failed to set power state %d\n", state);
return ret;
}
data->power_state = state;
return 0;
}
static void apds9300_clear_intr(struct apds9300_data *data)
{
int ret;
ret = i2c_smbus_write_byte(data->client, APDS9300_CLEAR | APDS9300_CMD);
if (ret < 0)
dev_err(&data->client->dev, "failed to clear interrupt\n");
}
static int apds9300_chip_init(struct apds9300_data *data)
{
int ret;
ret = apds9300_set_power_state(data, 0);
if (ret < 0)
goto err;
ret = apds9300_set_power_state(data, 1);
if (ret < 0)
goto err;
ret = i2c_smbus_read_byte_data(data->client,
APDS9300_CONTROL | APDS9300_CMD);
if (ret != APDS9300_POWER_ON) {
ret = -ENODEV;
goto err;
}
ret = apds9300_set_intr_state(data, 0);
if (ret < 0)
goto err;
return 0;
err:
dev_err(&data->client->dev, "failed to init the chip\n");
return ret;
}
static int apds9300_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2,
long mask)
{
int ch0, ch1, ret = -EINVAL;
struct apds9300_data *data = iio_priv(indio_dev);
mutex_lock(&data->mutex);
switch (chan->type) {
case IIO_LIGHT:
ch0 = apds9300_get_adc_val(data, 0);
if (ch0 < 0) {
ret = ch0;
break;
}
ch1 = apds9300_get_adc_val(data, 1);
if (ch1 < 0) {
ret = ch1;
break;
}
*val = apds9300_calculate_lux(ch0, ch1);
ret = IIO_VAL_INT;
break;
case IIO_INTENSITY:
ret = apds9300_get_adc_val(data, chan->channel);
if (ret < 0)
break;
*val = ret;
ret = IIO_VAL_INT;
break;
default:
break;
}
mutex_unlock(&data->mutex);
return ret;
}
static int apds9300_read_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info,
int *val, int *val2)
{
struct apds9300_data *data = iio_priv(indio_dev);
switch (dir) {
case IIO_EV_DIR_RISING:
*val = data->thresh_hi;
break;
case IIO_EV_DIR_FALLING:
*val = data->thresh_low;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static int apds9300_write_thresh(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info, int val,
int val2)
{
struct apds9300_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
if (dir == IIO_EV_DIR_RISING)
ret = apds9300_set_thresh_hi(data, val);
else
ret = apds9300_set_thresh_low(data, val);
mutex_unlock(&data->mutex);
return ret;
}
static int apds9300_read_interrupt_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct apds9300_data *data = iio_priv(indio_dev);
return data->intr_en;
}
static int apds9300_write_interrupt_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, int state)
{
struct apds9300_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = apds9300_set_intr_state(data, state);
mutex_unlock(&data->mutex);
return ret;
}
static irqreturn_t apds9300_interrupt_handler(int irq, void *private)
{
struct iio_dev *dev_info = private;
struct apds9300_data *data = iio_priv(dev_info);
iio_push_event(dev_info,
IIO_UNMOD_EVENT_CODE(IIO_INTENSITY, 0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_EITHER),
iio_get_time_ns());
apds9300_clear_intr(data);
return IRQ_HANDLED;
}
static int apds9300_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct apds9300_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
ret = apds9300_chip_init(data);
if (ret < 0)
goto err;
mutex_init(&data->mutex);
indio_dev->dev.parent = &client->dev;
indio_dev->channels = apds9300_channels;
indio_dev->num_channels = ARRAY_SIZE(apds9300_channels);
indio_dev->name = APDS9300_DRV_NAME;
indio_dev->modes = INDIO_DIRECT_MODE;
if (client->irq)
indio_dev->info = &apds9300_info;
else
indio_dev->info = &apds9300_info_no_irq;
if (client->irq) {
ret = devm_request_threaded_irq(&client->dev, client->irq,
NULL, apds9300_interrupt_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
APDS9300_IRQ_NAME, indio_dev);
if (ret) {
dev_err(&client->dev, "irq request error %d\n", -ret);
goto err;
}
}
ret = iio_device_register(indio_dev);
if (ret < 0)
goto err;
return 0;
err:
apds9300_set_power_state(data, 0);
return ret;
}
static int apds9300_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct apds9300_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
apds9300_set_intr_state(data, 0);
apds9300_set_power_state(data, 0);
return 0;
}
static int apds9300_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct apds9300_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = apds9300_set_power_state(data, 0);
mutex_unlock(&data->mutex);
return ret;
}
static int apds9300_resume(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct apds9300_data *data = iio_priv(indio_dev);
int ret;
mutex_lock(&data->mutex);
ret = apds9300_set_power_state(data, 1);
mutex_unlock(&data->mutex);
return ret;
}
