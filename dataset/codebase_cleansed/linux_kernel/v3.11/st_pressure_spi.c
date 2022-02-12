static int st_press_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct st_sensor_data *pdata;
int err;
indio_dev = iio_device_alloc(sizeof(*pdata));
if (indio_dev == NULL) {
err = -ENOMEM;
goto iio_device_alloc_error;
}
pdata = iio_priv(indio_dev);
pdata->dev = &spi->dev;
st_sensors_spi_configure(indio_dev, spi, pdata);
err = st_press_common_probe(indio_dev);
if (err < 0)
goto st_press_common_probe_error;
return 0;
st_press_common_probe_error:
iio_device_free(indio_dev);
iio_device_alloc_error:
return err;
}
static int st_press_spi_remove(struct spi_device *spi)
{
st_press_common_remove(spi_get_drvdata(spi));
return 0;
}
