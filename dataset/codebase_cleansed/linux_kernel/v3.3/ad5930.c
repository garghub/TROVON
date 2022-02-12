static ssize_t ad5930_set_parameter(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct spi_message msg;
struct spi_transfer xfer;
int ret;
struct ad5903_config *config = (struct ad5903_config *)buf;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad5930_state *st = iio_priv(idev);
config->control = (config->control & ~value_mask);
config->incnum = (config->control & ~value_mask) | (1 << addr_shift);
config->frqdelt[0] = (config->control & ~value_mask) | (2 << addr_shift);
config->frqdelt[1] = (config->control & ~value_mask) | 3 << addr_shift;
config->incitvl = (config->control & ~value_mask) | 4 << addr_shift;
config->buritvl = (config->control & ~value_mask) | 8 << addr_shift;
config->strtfrq[0] = (config->control & ~value_mask) | 0xc << addr_shift;
config->strtfrq[1] = (config->control & ~value_mask) | 0xd << addr_shift;
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
static int __devinit ad5930_probe(struct spi_device *spi)
{
struct ad5930_state *st;
struct iio_dev *idev;
int ret = 0;
idev = iio_allocate_device(sizeof(*st));
if (idev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, idev);
st = iio_priv(idev);
mutex_init(&st->lock);
st->sdev = spi;
idev->dev.parent = &spi->dev;
idev->info = &ad5930_info;
idev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(idev);
if (ret)
goto error_free_dev;
spi->max_speed_hz = 2000000;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 16;
spi_setup(spi);
return 0;
error_free_dev:
iio_free_device(idev);
error_ret:
return ret;
}
static int __devexit ad5930_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
iio_free_device(spi_get_drvdata(spi));
return 0;
}
