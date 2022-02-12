static int adc0831_adc_conversion(struct adc0832 *adc)
{
struct spi_device *spi = adc->spi;
int ret;
ret = spi_read(spi, &adc->rx_buf, 2);
if (ret)
return ret;
return (adc->rx_buf[0] << 2 & 0xff) | (adc->rx_buf[1] >> 6);
}
static int adc0832_adc_conversion(struct adc0832 *adc, int channel,
bool differential)
{
struct spi_device *spi = adc->spi;
struct spi_transfer xfer = {
.tx_buf = adc->tx_buf,
.rx_buf = adc->rx_buf,
.len = 2,
};
int ret;
if (!adc->mux_bits)
return adc0831_adc_conversion(adc);
adc->tx_buf[0] = 1 << (adc->mux_bits + 1);
adc->tx_buf[0] |= differential ? 0 : (1 << adc->mux_bits);
adc->tx_buf[0] |= (channel % 2) << (adc->mux_bits - 1);
if (adc->mux_bits > 1)
adc->tx_buf[0] |= channel / 2;
adc->tx_buf[0] <<= 1;
ret = spi_sync_transfer(spi, &xfer, 1);
if (ret)
return ret;
return adc->rx_buf[1];
}
static int adc0832_read_raw(struct iio_dev *iio,
struct iio_chan_spec const *channel, int *value,
int *shift, long mask)
{
struct adc0832 *adc = iio_priv(iio);
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&adc->lock);
*value = adc0832_adc_conversion(adc, channel->channel,
channel->differential);
mutex_unlock(&adc->lock);
if (*value < 0)
return *value;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*value = regulator_get_voltage(adc->reg);
if (*value < 0)
return *value;
*value /= 1000;
*shift = 8;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int adc0832_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct adc0832 *adc;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->spi = spi;
mutex_init(&adc->lock);
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->info = &adc0832_info;
indio_dev->modes = INDIO_DIRECT_MODE;
switch (spi_get_device_id(spi)->driver_data) {
case adc0831:
adc->mux_bits = 0;
indio_dev->channels = adc0831_channels;
indio_dev->num_channels = ARRAY_SIZE(adc0831_channels);
break;
case adc0832:
adc->mux_bits = 1;
indio_dev->channels = adc0832_channels;
indio_dev->num_channels = ARRAY_SIZE(adc0832_channels);
break;
case adc0834:
adc->mux_bits = 2;
indio_dev->channels = adc0834_channels;
indio_dev->num_channels = ARRAY_SIZE(adc0834_channels);
break;
case adc0838:
adc->mux_bits = 3;
indio_dev->channels = adc0838_channels;
indio_dev->num_channels = ARRAY_SIZE(adc0838_channels);
break;
default:
return -EINVAL;
}
adc->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(adc->reg))
return PTR_ERR(adc->reg);
ret = regulator_enable(adc->reg);
if (ret)
return ret;
spi_set_drvdata(spi, indio_dev);
ret = iio_device_register(indio_dev);
if (ret)
regulator_disable(adc->reg);
return ret;
}
static int adc0832_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adc0832 *adc = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(adc->reg);
return 0;
}
