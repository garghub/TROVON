static int st_accel_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct st_sensor_data *adata;
int err;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adata));
if (!indio_dev)
return -ENOMEM;
adata = iio_priv(indio_dev);
st_sensors_spi_configure(indio_dev, spi, adata);
err = st_accel_common_probe(indio_dev);
if (err < 0)
return err;
return 0;
}
static int st_accel_spi_remove(struct spi_device *spi)
{
st_accel_common_remove(spi_get_drvdata(spi));
return 0;
}
