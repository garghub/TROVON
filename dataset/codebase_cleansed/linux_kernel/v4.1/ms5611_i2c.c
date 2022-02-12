static int ms5611_i2c_reset(struct device *dev)
{
struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
return i2c_smbus_write_byte(st->client, MS5611_RESET);
}
static int ms5611_i2c_read_prom_word(struct device *dev, int index, u16 *word)
{
int ret;
struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
ret = i2c_smbus_read_word_swapped(st->client,
MS5611_READ_PROM_WORD + (index << 1));
if (ret < 0)
return ret;
*word = ret;
return 0;
}
static int ms5611_i2c_read_adc(struct ms5611_state *st, s32 *val)
{
int ret;
u8 buf[3];
ret = i2c_smbus_read_i2c_block_data(st->client, MS5611_READ_ADC,
3, buf);
if (ret < 0)
return ret;
*val = (buf[0] << 16) | (buf[1] << 8) | buf[2];
return 0;
}
static int ms5611_i2c_read_adc_temp_and_pressure(struct device *dev,
s32 *temp, s32 *pressure)
{
int ret;
struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
ret = i2c_smbus_write_byte(st->client, MS5611_START_TEMP_CONV);
if (ret < 0)
return ret;
usleep_range(MS5611_CONV_TIME_MIN, MS5611_CONV_TIME_MAX);
ret = ms5611_i2c_read_adc(st, temp);
if (ret < 0)
return ret;
ret = i2c_smbus_write_byte(st->client, MS5611_START_PRESSURE_CONV);
if (ret < 0)
return ret;
usleep_range(MS5611_CONV_TIME_MIN, MS5611_CONV_TIME_MAX);
return ms5611_i2c_read_adc(st, pressure);
}
static int ms5611_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ms5611_state *st;
struct iio_dev *indio_dev;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WRITE_BYTE |
I2C_FUNC_SMBUS_READ_WORD_DATA |
I2C_FUNC_SMBUS_READ_I2C_BLOCK))
return -ENODEV;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reset = ms5611_i2c_reset;
st->read_prom_word = ms5611_i2c_read_prom_word;
st->read_adc_temp_and_pressure = ms5611_i2c_read_adc_temp_and_pressure;
st->client = client;
return ms5611_probe(indio_dev, &client->dev);
}
