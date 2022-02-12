static int max5487_write_cmd(struct spi_device *spi, u16 cmd)
{
return spi_write(spi, (const void *) &cmd, sizeof(u16));
}
static int max5487_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct max5487_data *data = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_SCALE)
return -EINVAL;
*val = 1000 * data->kohms;
*val2 = MAX5487_MAX_POS;
return IIO_VAL_FRACTIONAL;
}
static int max5487_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct max5487_data *data = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
if (val < 0 || val > MAX5487_MAX_POS)
return -EINVAL;
return max5487_write_cmd(data->spi, chan->address | val);
}
static int max5487_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct max5487_data *data;
const struct spi_device_id *id = spi_get_device_id(spi);
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
dev_set_drvdata(&spi->dev, indio_dev);
data = iio_priv(indio_dev);
data->spi = spi;
data->kohms = id->driver_data;
indio_dev->info = &max5487_info;
indio_dev->name = id->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = max5487_channels;
indio_dev->num_channels = ARRAY_SIZE(max5487_channels);
ret = max5487_write_cmd(data->spi, MAX5487_COPY_NV_TO_AB);
if (ret < 0)
return ret;
return iio_device_register(indio_dev);
}
static int max5487_spi_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = dev_get_drvdata(&spi->dev);
iio_device_unregister(indio_dev);
return max5487_write_cmd(spi, MAX5487_COPY_AB_TO_NV);
}
