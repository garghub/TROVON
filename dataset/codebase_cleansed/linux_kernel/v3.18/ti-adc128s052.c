static int adc128_adc_conversion(struct adc128 *adc, u8 channel)
{
int ret;
mutex_lock(&adc->lock);
adc->buffer[0] = channel << 3;
adc->buffer[1] = 0;
ret = spi_write(adc->spi, &adc->buffer, 2);
if (ret < 0) {
mutex_unlock(&adc->lock);
return ret;
}
ret = spi_read(adc->spi, &adc->buffer, 2);
mutex_unlock(&adc->lock);
if (ret < 0)
return ret;
return ((adc->buffer[0] << 8 | adc->buffer[1]) & 0xFFF);
}
static int adc128_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
struct adc128 *adc = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = adc128_adc_conversion(adc, channel->channel);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(adc->reg);
if (ret < 0)
return ret;
*val = ret / 1000;
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static int adc128_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct adc128 *adc;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->spi = spi;
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &adc128_info;
indio_dev->channels = adc128_channels;
indio_dev->num_channels = ARRAY_SIZE(adc128_channels);
adc->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(adc->reg))
return PTR_ERR(adc->reg);
ret = regulator_enable(adc->reg);
if (ret < 0)
return ret;
mutex_init(&adc->lock);
ret = iio_device_register(indio_dev);
return ret;
}
static int adc128_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adc128 *adc = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(adc->reg);
return 0;
}
