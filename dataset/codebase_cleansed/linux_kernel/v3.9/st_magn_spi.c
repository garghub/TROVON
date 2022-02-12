static int st_magn_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct st_sensor_data *mdata;
int err;
indio_dev = iio_device_alloc(sizeof(*mdata));
if (indio_dev == NULL) {
err = -ENOMEM;
goto iio_device_alloc_error;
}
mdata = iio_priv(indio_dev);
mdata->dev = &spi->dev;
st_sensors_spi_configure(indio_dev, spi, mdata);
err = st_magn_common_probe(indio_dev);
if (err < 0)
goto st_magn_common_probe_error;
return 0;
st_magn_common_probe_error:
iio_device_free(indio_dev);
iio_device_alloc_error:
return err;
}
static int st_magn_spi_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
st_magn_common_remove(indio_dev);
return 0;
}
