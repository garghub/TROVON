static int st_gyro_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct st_sensor_data *gdata;
int err;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*gdata));
if (!indio_dev)
return -ENOMEM;
gdata = iio_priv(indio_dev);
st_sensors_spi_configure(indio_dev, spi, gdata);
err = st_gyro_common_probe(indio_dev);
if (err < 0)
return err;
return 0;
}
static int st_gyro_spi_remove(struct spi_device *spi)
{
st_gyro_common_remove(spi_get_drvdata(spi));
return 0;
}
