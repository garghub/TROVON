static ssize_t ad9850_set_parameter(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct spi_message msg;
struct spi_transfer xfer;
int ret;
struct ad9850_config *config = (struct ad9850_config *)buf;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad9850_state *st = idev->dev_data;
xfer.len = len;
xfer.tx_buf = config;
mutex_lock(&st->lock);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static int __devinit ad9850_probe(struct spi_device *spi)
{
struct ad9850_state *st;
int ret = 0;
st = kzalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, st);
mutex_init(&st->lock);
st->sdev = spi;
st->idev = iio_allocate_device(0);
if (st->idev == NULL) {
ret = -ENOMEM;
goto error_free_st;
}
st->idev->dev.parent = &spi->dev;
st->idev->info = &ad9850_info;
st->idev->dev_data = (void *)(st);
st->idev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->idev);
if (ret)
goto error_free_dev;
spi->max_speed_hz = 2000000;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 16;
spi_setup(spi);
return 0;
error_free_dev:
iio_free_device(st->idev);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int __devexit ad9850_remove(struct spi_device *spi)
{
struct ad9850_state *st = spi_get_drvdata(spi);
iio_device_unregister(st->idev);
kfree(st);
return 0;
}
static __init int ad9850_spi_init(void)
{
return spi_register_driver(&ad9850_driver);
}
static __exit void ad9850_spi_exit(void)
{
spi_unregister_driver(&ad9850_driver);
}
