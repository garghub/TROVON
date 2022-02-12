static int tcs3414_req_data(struct tcs3414_data *data)
{
int tries = 25;
int ret;
ret = i2c_smbus_write_byte_data(data->client, TCS3414_CONTROL,
data->control | TCS3414_CONTROL_ADC_EN);
if (ret < 0)
return ret;
while (tries--) {
ret = i2c_smbus_read_byte_data(data->client, TCS3414_CONTROL);
if (ret < 0)
return ret;
if (ret & TCS3414_CONTROL_ADC_VALID)
break;
msleep(20);
}
ret = i2c_smbus_write_byte_data(data->client, TCS3414_CONTROL,
data->control);
if (ret < 0)
return ret;
if (tries < 0) {
dev_err(&data->client->dev, "data not ready\n");
return -EIO;
}
return 0;
}
static int tcs3414_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct tcs3414_data *data = iio_priv(indio_dev);
int i, ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = tcs3414_req_data(data);
if (ret < 0) {
iio_device_release_direct_mode(indio_dev);
return ret;
}
ret = i2c_smbus_read_word_data(data->client, chan->address);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
i = (data->gain & TCS3414_GAIN_MASK) >> TCS3414_GAIN_SHIFT;
*val = tcs3414_scales[i][0];
*val2 = tcs3414_scales[i][1];
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_INT_TIME:
*val = 0;
*val2 = tcs3414_times[data->timing & TCS3414_INTEG_MASK] * 1000;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int tcs3414_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct tcs3414_data *data = iio_priv(indio_dev);
int i;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
for (i = 0; i < ARRAY_SIZE(tcs3414_scales); i++) {
if (val == tcs3414_scales[i][0] &&
val2 == tcs3414_scales[i][1]) {
data->gain &= ~TCS3414_GAIN_MASK;
data->gain |= i << TCS3414_GAIN_SHIFT;
return i2c_smbus_write_byte_data(
data->client, TCS3414_GAIN,
data->gain);
}
}
return -EINVAL;
case IIO_CHAN_INFO_INT_TIME:
if (val != 0)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(tcs3414_times); i++) {
if (val2 == tcs3414_times[i] * 1000) {
data->timing &= ~TCS3414_INTEG_MASK;
data->timing |= i;
return i2c_smbus_write_byte_data(
data->client, TCS3414_TIMING,
data->timing);
}
}
return -EINVAL;
default:
return -EINVAL;
}
}
static irqreturn_t tcs3414_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct tcs3414_data *data = iio_priv(indio_dev);
int i, j = 0;
for_each_set_bit(i, indio_dev->active_scan_mask,
indio_dev->masklength) {
int ret = i2c_smbus_read_word_data(data->client,
TCS3414_DATA_GREEN + 2*i);
if (ret < 0)
goto done;
data->buffer[j++] = ret;
}
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int tcs3414_buffer_preenable(struct iio_dev *indio_dev)
{
struct tcs3414_data *data = iio_priv(indio_dev);
data->control |= TCS3414_CONTROL_ADC_EN;
return i2c_smbus_write_byte_data(data->client, TCS3414_CONTROL,
data->control);
}
static int tcs3414_buffer_predisable(struct iio_dev *indio_dev)
{
struct tcs3414_data *data = iio_priv(indio_dev);
int ret;
ret = iio_triggered_buffer_predisable(indio_dev);
if (ret < 0)
return ret;
data->control &= ~TCS3414_CONTROL_ADC_EN;
return i2c_smbus_write_byte_data(data->client, TCS3414_CONTROL,
data->control);
}
static int tcs3414_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tcs3414_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*data));
if (indio_dev == NULL)
return -ENOMEM;
data = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
data->client = client;
indio_dev->dev.parent = &client->dev;
indio_dev->info = &tcs3414_info;
indio_dev->name = TCS3414_DRV_NAME;
indio_dev->channels = tcs3414_channels;
indio_dev->num_channels = ARRAY_SIZE(tcs3414_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = i2c_smbus_read_byte_data(data->client, TCS3414_ID);
if (ret < 0)
return ret;
switch (ret & 0xf0) {
case 0x00:
dev_info(&client->dev, "TCS3404 found\n");
break;
case 0x10:
dev_info(&client->dev, "TCS3413/14/15/16 found\n");
break;
default:
return -ENODEV;
}
data->control = TCS3414_CONTROL_POWER;
ret = i2c_smbus_write_byte_data(data->client, TCS3414_CONTROL,
data->control);
if (ret < 0)
return ret;
data->timing = TCS3414_INTEG_12MS;
ret = i2c_smbus_write_byte_data(data->client, TCS3414_TIMING,
data->timing);
if (ret < 0)
return ret;
ret = i2c_smbus_read_byte_data(data->client, TCS3414_GAIN);
if (ret < 0)
return ret;
data->gain = ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
tcs3414_trigger_handler, &tcs3414_buffer_setup_ops);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto buffer_cleanup;
return 0;
buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int tcs3414_powerdown(struct tcs3414_data *data)
{
return i2c_smbus_write_byte_data(data->client, TCS3414_CONTROL,
data->control & ~(TCS3414_CONTROL_POWER |
TCS3414_CONTROL_ADC_EN));
}
static int tcs3414_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
tcs3414_powerdown(iio_priv(indio_dev));
return 0;
}
static int tcs3414_suspend(struct device *dev)
{
struct tcs3414_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return tcs3414_powerdown(data);
}
static int tcs3414_resume(struct device *dev)
{
struct tcs3414_data *data = iio_priv(i2c_get_clientdata(
to_i2c_client(dev)));
return i2c_smbus_write_byte_data(data->client, TCS3414_CONTROL,
data->control);
}
