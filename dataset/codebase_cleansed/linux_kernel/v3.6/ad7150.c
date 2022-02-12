static int ad7150_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
int ret;
struct ad7150_chip_info *chip = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = i2c_smbus_read_word_data(chip->client,
ad7150_addresses[chan->channel][0]);
if (ret < 0)
return ret;
*val = swab16(ret);
return IIO_VAL_INT;
case IIO_CHAN_INFO_AVERAGE_RAW:
ret = i2c_smbus_read_word_data(chip->client,
ad7150_addresses[chan->channel][1]);
if (ret < 0)
return ret;
*val = swab16(ret);
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int ad7150_read_event_config(struct iio_dev *indio_dev, u64 event_code)
{
int ret;
u8 threshtype;
bool adaptive;
struct ad7150_chip_info *chip = iio_priv(indio_dev);
int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING);
ret = i2c_smbus_read_byte_data(chip->client, AD7150_CFG);
if (ret < 0)
return ret;
threshtype = (ret >> 5) & 0x03;
adaptive = !!(ret & 0x80);
switch (IIO_EVENT_CODE_EXTRACT_TYPE(event_code)) {
case IIO_EV_TYPE_MAG_ADAPTIVE:
if (rising)
return adaptive && (threshtype == 0x1);
else
return adaptive && (threshtype == 0x0);
case IIO_EV_TYPE_THRESH_ADAPTIVE:
if (rising)
return adaptive && (threshtype == 0x3);
else
return adaptive && (threshtype == 0x2);
case IIO_EV_TYPE_THRESH:
if (rising)
return !adaptive && (threshtype == 0x1);
else
return !adaptive && (threshtype == 0x0);
};
return -EINVAL;
}
static int ad7150_write_event_params(struct iio_dev *indio_dev, u64 event_code)
{
int ret;
u16 value;
u8 sens, timeout;
struct ad7150_chip_info *chip = iio_priv(indio_dev);
int chan = IIO_EVENT_CODE_EXTRACT_CHAN(event_code);
int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING);
if (event_code != chip->current_event)
return 0;
switch (IIO_EVENT_CODE_EXTRACT_TYPE(event_code)) {
case IIO_EV_TYPE_THRESH:
value = chip->threshold[rising][chan];
ret = i2c_smbus_write_word_data(chip->client,
ad7150_addresses[chan][3],
swab16(value));
if (ret < 0)
return ret;
return 0;
case IIO_EV_TYPE_MAG_ADAPTIVE:
sens = chip->mag_sensitivity[rising][chan];
timeout = chip->mag_timeout[rising][chan];
break;
case IIO_EV_TYPE_THRESH_ADAPTIVE:
sens = chip->thresh_sensitivity[rising][chan];
timeout = chip->thresh_timeout[rising][chan];
break;
default:
return -EINVAL;
};
ret = i2c_smbus_write_byte_data(chip->client,
ad7150_addresses[chan][4],
sens);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte_data(chip->client,
ad7150_addresses[chan][5],
timeout);
if (ret < 0)
return ret;
return 0;
}
static int ad7150_write_event_config(struct iio_dev *indio_dev,
u64 event_code, int state)
{
u8 thresh_type, cfg, adaptive;
int ret;
struct ad7150_chip_info *chip = iio_priv(indio_dev);
int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING);
if (state == 0)
return -EINVAL;
if (event_code == chip->current_event)
return 0;
mutex_lock(&chip->state_lock);
ret = i2c_smbus_read_byte_data(chip->client, AD7150_CFG);
if (ret < 0)
goto error_ret;
cfg = ret & ~((0x03 << 5) | (0x1 << 7));
switch (IIO_EVENT_CODE_EXTRACT_TYPE(event_code)) {
case IIO_EV_TYPE_MAG_ADAPTIVE:
adaptive = 1;
if (rising)
thresh_type = 0x1;
else
thresh_type = 0x0;
break;
case IIO_EV_TYPE_THRESH_ADAPTIVE:
adaptive = 1;
if (rising)
thresh_type = 0x3;
else
thresh_type = 0x2;
break;
case IIO_EV_TYPE_THRESH:
adaptive = 0;
if (rising)
thresh_type = 0x1;
else
thresh_type = 0x0;
break;
default:
ret = -EINVAL;
goto error_ret;
};
cfg |= (!adaptive << 7) | (thresh_type << 5);
ret = i2c_smbus_write_byte_data(chip->client, AD7150_CFG, cfg);
if (ret < 0)
goto error_ret;
chip->current_event = event_code;
ret = ad7150_write_event_params(indio_dev, event_code);
error_ret:
mutex_unlock(&chip->state_lock);
return 0;
}
static int ad7150_read_event_value(struct iio_dev *indio_dev,
u64 event_code,
int *val)
{
int chan = IIO_EVENT_CODE_EXTRACT_CHAN(event_code);
struct ad7150_chip_info *chip = iio_priv(indio_dev);
int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING);
switch (IIO_EVENT_CODE_EXTRACT_TYPE(event_code)) {
case IIO_EV_TYPE_MAG_ADAPTIVE:
*val = chip->mag_sensitivity[rising][chan];
return 0;
case IIO_EV_TYPE_THRESH_ADAPTIVE:
*val = chip->thresh_sensitivity[rising][chan];
return 0;
case IIO_EV_TYPE_THRESH:
*val = chip->threshold[rising][chan];
return 0;
default:
return -EINVAL;
};
}
static int ad7150_write_event_value(struct iio_dev *indio_dev,
u64 event_code,
int val)
{
int ret;
struct ad7150_chip_info *chip = iio_priv(indio_dev);
int chan = IIO_EVENT_CODE_EXTRACT_CHAN(event_code);
int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(event_code) ==
IIO_EV_DIR_RISING);
mutex_lock(&chip->state_lock);
switch (IIO_EVENT_CODE_EXTRACT_TYPE(event_code)) {
case IIO_EV_TYPE_MAG_ADAPTIVE:
chip->mag_sensitivity[rising][chan] = val;
break;
case IIO_EV_TYPE_THRESH_ADAPTIVE:
chip->thresh_sensitivity[rising][chan] = val;
break;
case IIO_EV_TYPE_THRESH:
chip->threshold[rising][chan] = val;
break;
default:
ret = -EINVAL;
goto error_ret;
};
ret = ad7150_write_event_params(indio_dev, event_code);
error_ret:
mutex_unlock(&chip->state_lock);
return ret;
}
static ssize_t ad7150_show_timeout(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7150_chip_info *chip = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
u8 value;
int chan = IIO_EVENT_CODE_EXTRACT_CHAN(this_attr->address);
int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(this_attr->address)
== IIO_EV_DIR_RISING);
switch (IIO_EVENT_CODE_EXTRACT_TYPE(this_attr->address)) {
case IIO_EV_TYPE_MAG_ADAPTIVE:
value = chip->mag_timeout[rising][chan];
break;
case IIO_EV_TYPE_THRESH_ADAPTIVE:
value = chip->thresh_timeout[rising][chan];
break;
default:
return -EINVAL;
};
return sprintf(buf, "%d\n", value);
}
static ssize_t ad7150_store_timeout(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct ad7150_chip_info *chip = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int chan = IIO_EVENT_CODE_EXTRACT_CHAN(this_attr->address);
int rising = !!(IIO_EVENT_CODE_EXTRACT_DIR(this_attr->address) ==
IIO_EV_DIR_RISING);
u8 data;
int ret;
ret = kstrtou8(buf, 10, &data);
if (ret < 0)
return ret;
mutex_lock(&chip->state_lock);
switch (IIO_EVENT_CODE_EXTRACT_TYPE(this_attr->address)) {
case IIO_EV_TYPE_MAG_ADAPTIVE:
chip->mag_timeout[rising][chan] = data;
break;
case IIO_EV_TYPE_THRESH_ADAPTIVE:
chip->thresh_timeout[rising][chan] = data;
break;
default:
ret = -EINVAL;
goto error_ret;
};
ret = ad7150_write_event_params(indio_dev, this_attr->address);
error_ret:
mutex_unlock(&chip->state_lock);
if (ret < 0)
return ret;
return len;
}
static irqreturn_t ad7150_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct ad7150_chip_info *chip = iio_priv(indio_dev);
u8 int_status;
s64 timestamp = iio_get_time_ns();
int ret;
ret = i2c_smbus_read_byte_data(chip->client, AD7150_STATUS);
if (ret < 0)
return IRQ_HANDLED;
int_status = ret;
if ((int_status & AD7150_STATUS_OUT1) &&
!(chip->old_state & AD7150_STATUS_OUT1))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
else if ((!(int_status & AD7150_STATUS_OUT1)) &&
(chip->old_state & AD7150_STATUS_OUT1))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
0,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
if ((int_status & AD7150_STATUS_OUT2) &&
!(chip->old_state & AD7150_STATUS_OUT2))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
1,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_RISING),
timestamp);
else if ((!(int_status & AD7150_STATUS_OUT2)) &&
(chip->old_state & AD7150_STATUS_OUT2))
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(IIO_CAPACITANCE,
1,
IIO_EV_TYPE_THRESH,
IIO_EV_DIR_FALLING),
timestamp);
chip->old_state = int_status;
return IRQ_HANDLED;
}
static int __devinit ad7150_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct ad7150_chip_info *chip;
struct iio_dev *indio_dev;
indio_dev = iio_device_alloc(sizeof(*chip));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
chip = iio_priv(indio_dev);
mutex_init(&chip->state_lock);
i2c_set_clientdata(client, indio_dev);
chip->client = client;
indio_dev->name = id->name;
indio_dev->channels = ad7150_channels;
indio_dev->num_channels = ARRAY_SIZE(ad7150_channels);
indio_dev->dev.parent = &client->dev;
indio_dev->info = &ad7150_info;
indio_dev->modes = INDIO_DIRECT_MODE;
if (client->irq) {
ret = request_threaded_irq(client->irq,
NULL,
&ad7150_event_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
"ad7150_irq1",
indio_dev);
if (ret)
goto error_free_dev;
}
if (client->dev.platform_data) {
ret = request_threaded_irq(*(unsigned int *)
client->dev.platform_data,
NULL,
&ad7150_event_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
"ad7150_irq2",
indio_dev);
if (ret)
goto error_free_irq;
}
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_irq2;
dev_info(&client->dev, "%s capacitive sensor registered,irq: %d\n",
id->name, client->irq);
return 0;
error_free_irq2:
if (client->dev.platform_data)
free_irq(*(unsigned int *)client->dev.platform_data,
indio_dev);
error_free_irq:
if (client->irq)
free_irq(client->irq, indio_dev);
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int __devexit ad7150_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
if (client->irq)
free_irq(client->irq, indio_dev);
if (client->dev.platform_data)
free_irq(*(unsigned int *)client->dev.platform_data, indio_dev);
iio_device_free(indio_dev);
return 0;
}
