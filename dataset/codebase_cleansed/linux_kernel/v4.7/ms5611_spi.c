static int ms5611_spi_reset(struct device *dev)
{
u8 cmd = MS5611_RESET;
struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
return spi_write_then_read(st->client, &cmd, 1, NULL, 0);
}
static int ms5611_spi_read_prom_word(struct device *dev, int index, u16 *word)
{
int ret;
struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
ret = spi_w8r16be(st->client, MS5611_READ_PROM_WORD + (index << 1));
if (ret < 0)
return ret;
*word = ret;
return 0;
}
static int ms5611_spi_read_adc(struct device *dev, s32 *val)
{
int ret;
u8 buf[3] = { MS5611_READ_ADC };
struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
ret = spi_write_then_read(st->client, buf, 1, buf, 3);
if (ret < 0)
return ret;
*val = (buf[0] << 16) | (buf[1] << 8) | buf[2];
return 0;
}
static int ms5611_spi_read_adc_temp_and_pressure(struct device *dev,
s32 *temp, s32 *pressure)
{
int ret;
struct ms5611_state *st = iio_priv(dev_to_iio_dev(dev));
const struct ms5611_osr *osr = st->temp_osr;
ret = spi_write_then_read(st->client, &osr->cmd, 1, NULL, 0);
if (ret < 0)
return ret;
usleep_range(osr->conv_usec, osr->conv_usec + (osr->conv_usec / 10UL));
ret = ms5611_spi_read_adc(dev, temp);
if (ret < 0)
return ret;
osr = st->pressure_osr;
ret = spi_write_then_read(st->client, &osr->cmd, 1, NULL, 0);
if (ret < 0)
return ret;
usleep_range(osr->conv_usec, osr->conv_usec + (osr->conv_usec / 10UL));
return ms5611_spi_read_adc(dev, pressure);
}
static int ms5611_spi_probe(struct spi_device *spi)
{
int ret;
struct ms5611_state *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
spi_set_drvdata(spi, indio_dev);
spi->mode = SPI_MODE_0;
spi->max_speed_hz = 20000000;
spi->bits_per_word = 8;
ret = spi_setup(spi);
if (ret < 0)
return ret;
st = iio_priv(indio_dev);
st->reset = ms5611_spi_reset;
st->read_prom_word = ms5611_spi_read_prom_word;
st->read_adc_temp_and_pressure = ms5611_spi_read_adc_temp_and_pressure;
st->client = spi;
return ms5611_probe(indio_dev, &spi->dev, spi_get_device_id(spi)->name,
spi_get_device_id(spi)->driver_data);
}
static int ms5611_spi_remove(struct spi_device *spi)
{
return ms5611_remove(spi_get_drvdata(spi));
}
