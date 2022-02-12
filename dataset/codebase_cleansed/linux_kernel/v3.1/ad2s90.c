static ssize_t ad2s90_show_angular(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
ssize_t len = 0;
u16 val;
struct ad2s90_state *st = iio_priv(dev_get_drvdata(dev));
mutex_lock(&st->lock);
ret = spi_read(st->sdev, st->rx, 2);
if (ret)
goto error_ret;
val = (((u16)(st->rx[0])) << 4) | ((st->rx[1] & 0xF0) >> 4);
len = sprintf(buf, "%d\n", val);
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static int __devinit ad2s90_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct ad2s90_state *st;
int ret = 0;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
mutex_init(&st->lock);
st->sdev = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ad2s90_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->idev);
if (ret)
goto error_free_dev;
spi->max_speed_hz = 830000;
spi->mode = SPI_MODE_3;
spi_setup(spi);
return 0;
error_free_dev:
iio_free_device(st->idev);
error_ret:
return ret;
}
static int __devexit ad2s90_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
return 0;
}
static __init int ad2s90_spi_init(void)
{
return spi_register_driver(&ad2s90_driver);
}
static __exit void ad2s90_spi_exit(void)
{
spi_unregister_driver(&ad2s90_driver);
}
