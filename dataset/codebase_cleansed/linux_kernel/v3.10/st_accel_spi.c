static int st_accel_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct st_sensor_data *adata;
int err;
indio_dev = iio_device_alloc(sizeof(*adata));
if (indio_dev == NULL) {
err = -ENOMEM;
goto iio_device_alloc_error;
}
adata = iio_priv(indio_dev);
adata->dev = &spi->dev;
st_sensors_spi_configure(indio_dev, spi, adata);
err = st_accel_common_probe(indio_dev);
if (err < 0)
goto st_accel_common_probe_error;
return 0;
st_accel_common_probe_error:
iio_device_free(indio_dev);
iio_device_alloc_error:
return err;
}
static int st_accel_spi_remove(struct spi_device *spi)
{
st_accel_common_remove(spi_get_drvdata(spi));
return 0;
}
