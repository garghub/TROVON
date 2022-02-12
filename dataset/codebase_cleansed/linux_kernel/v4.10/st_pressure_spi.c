static int st_press_spi_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct st_sensor_data *press_data;
int err;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*press_data));
if (indio_dev == NULL)
return -ENOMEM;
press_data = iio_priv(indio_dev);
st_sensors_spi_configure(indio_dev, spi, press_data);
err = st_press_common_probe(indio_dev);
if (err < 0)
return err;
return 0;
}
static int st_press_spi_remove(struct spi_device *spi)
{
st_press_common_remove(spi_get_drvdata(spi));
return 0;
}
