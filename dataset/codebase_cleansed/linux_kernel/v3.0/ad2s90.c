static ssize_t ad2s90_show_angular(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct spi_message msg;
struct spi_transfer xfer;
int ret;
ssize_t len = 0;
u16 val;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad2s90_state *st = idev->dev_data;
xfer.len = 1;
xfer.tx_buf = st->tx;
xfer.rx_buf = st->rx;
mutex_lock(&st->lock);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
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
struct ad2s90_state *st;
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
st->idev->info = &ad2s90_info;
st->idev->dev_data = (void *)(st);
st->idev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->idev);
if (ret)
goto error_free_dev;
spi->max_speed_hz = 830000;
spi->mode = SPI_MODE_3;
spi_setup(spi);
return 0;
error_free_dev:
iio_free_device(st->idev);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int __devexit ad2s90_remove(struct spi_device *spi)
{
struct ad2s90_state *st = spi_get_drvdata(spi);
iio_device_unregister(st->idev);
kfree(st);
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
