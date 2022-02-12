static int tsys01_read_temperature(struct iio_dev *indio_dev,
s32 *temperature)
{
int ret, i;
u32 adc;
s64 temp = 0;
struct tsys01_dev *dev_data = iio_priv(indio_dev);
mutex_lock(&dev_data->lock);
ret = dev_data->convert_and_read(dev_data->client,
TSYS01_CONVERSION_START,
TSYS01_ADC_READ, 9000, &adc);
mutex_unlock(&dev_data->lock);
if (ret)
return ret;
adc >>= 8;
for (i = 4; i > 0; i--) {
temp += coeff_mul[i] *
(s64)dev_data->prom[5 - i];
temp *= (s64)adc;
temp = div64_s64(temp, 100000);
}
temp *= 10;
temp += coeff_mul[0] * (s64)dev_data->prom[5];
temp = div64_s64(temp, 100000);
*temperature = temp;
return 0;
}
static int tsys01_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
int ret;
s32 temperature;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
switch (channel->type) {
case IIO_TEMP:
ret = tsys01_read_temperature(indio_dev, &temperature);
if (ret)
return ret;
*val = temperature;
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static bool tsys01_crc_valid(u16 *n_prom)
{
u8 cnt;
u8 sum = 0;
for (cnt = 0; cnt < TSYS01_PROM_WORDS_NB; cnt++)
sum += ((n_prom[0] >> 8) + (n_prom[0] & 0xFF));
return (sum == 0);
}
static int tsys01_read_prom(struct iio_dev *indio_dev)
{
int i, ret;
struct tsys01_dev *dev_data = iio_priv(indio_dev);
char buf[7 * TSYS01_PROM_WORDS_NB + 1];
char *ptr = buf;
for (i = 0; i < TSYS01_PROM_WORDS_NB; i++) {
ret = dev_data->read_prom_word(dev_data->client,
TSYS01_PROM_READ + (i << 1),
&dev_data->prom[i]);
if (ret)
return ret;
ret = sprintf(ptr, "0x%04x ", dev_data->prom[i]);
ptr += ret;
}
if (!tsys01_crc_valid(dev_data->prom)) {
dev_err(&indio_dev->dev, "prom crc check error\n");
return -ENODEV;
}
*ptr = 0;
dev_info(&indio_dev->dev, "PROM coefficients : %s\n", buf);
return 0;
}
static int tsys01_probe(struct iio_dev *indio_dev, struct device *dev)
{
int ret;
struct tsys01_dev *dev_data = iio_priv(indio_dev);
mutex_init(&dev_data->lock);
indio_dev->info = &tsys01_info;
indio_dev->name = dev->driver->name;
indio_dev->dev.parent = dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = tsys01_channels;
indio_dev->num_channels = ARRAY_SIZE(tsys01_channels);
ret = dev_data->reset(dev_data->client, TSYS01_RESET, 3000);
if (ret)
return ret;
ret = tsys01_read_prom(indio_dev);
if (ret)
return ret;
return devm_iio_device_register(dev, indio_dev);
}
static int tsys01_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tsys01_dev *dev_data;
struct iio_dev *indio_dev;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_WRITE_BYTE |
I2C_FUNC_SMBUS_READ_I2C_BLOCK)) {
dev_err(&client->dev,
"Adapter does not support some i2c transaction\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*dev_data));
if (!indio_dev)
return -ENOMEM;
dev_data = iio_priv(indio_dev);
dev_data->client = client;
dev_data->reset = ms_sensors_reset;
dev_data->read_prom_word = ms_sensors_read_prom_word;
dev_data->convert_and_read = ms_sensors_convert_and_read;
i2c_set_clientdata(client, indio_dev);
return tsys01_probe(indio_dev, &client->dev);
}
