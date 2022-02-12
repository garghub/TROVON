static int ad2s90_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret;
struct ad2s90_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
ret = spi_read(st->sdev, st->rx, 2);
if (ret)
goto error_ret;
*val = (((u16)(st->rx[0])) << 4) | ((st->rx[1] & 0xF0) >> 4);
error_ret:
mutex_unlock(&st->lock);
return IIO_VAL_INT;
}
static int ad2s90_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct ad2s90_state *st;
int ret = 0;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
mutex_init(&st->lock);
st->sdev = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ad2s90_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = &ad2s90_chan;
indio_dev->num_channels = 1;
indio_dev->name = spi_get_device_id(spi)->name;
ret = devm_iio_device_register(indio_dev->dev.parent, indio_dev);
if (ret)
return ret;
spi->max_speed_hz = 830000;
spi->mode = SPI_MODE_3;
spi_setup(spi);
return 0;
}
