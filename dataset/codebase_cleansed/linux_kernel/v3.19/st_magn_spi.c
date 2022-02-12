static int st_magn_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct st_sensor_data *mdata;
int err;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*mdata));
if (!indio_dev)
return -ENOMEM;
mdata = iio_priv(indio_dev);
st_sensors_spi_configure(indio_dev, spi, mdata);
err = st_magn_common_probe(indio_dev);
if (err < 0)
return err;
return 0;
}
static int st_magn_spi_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
st_magn_common_remove(indio_dev);
return 0;
}
