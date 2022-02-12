static ssize_t ad9852_set_parameter(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct spi_message msg;
struct spi_transfer xfer;
int ret;
struct ad9852_config *config = (struct ad9852_config *)buf;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad9852_state *st = idev->dev_data;
xfer.len = 3;
xfer.tx_buf = &config->phajst0[0];
mutex_lock(&st->lock);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 3;
xfer.tx_buf = &config->phajst1[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 6;
xfer.tx_buf = &config->fretun1[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 6;
xfer.tx_buf = &config->fretun2[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 6;
xfer.tx_buf = &config->dltafre[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->updtclk[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 4;
xfer.tx_buf = &config->ramprat[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->control[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 3;
xfer.tx_buf = &config->outpskm[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 2;
xfer.tx_buf = &config->outpskr[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 3;
xfer.tx_buf = &config->daccntl[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static void ad9852_init(struct ad9852_state *st)
{
struct spi_message msg;
struct spi_transfer xfer;
int ret;
u8 config[5];
config[0] = addr_contrl;
config[1] = COMPPD;
config[2] = REFMULT2 | BYPPLL | PLLRANG;
config[3] = IEUPCLK;
config[4] = OSKEN;
mutex_lock(&st->lock);
xfer.len = 5;
xfer.tx_buf = &config;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
error_ret:
mutex_unlock(&st->lock);
}
static int __devinit ad9852_probe(struct spi_device *spi)
{
struct ad9852_state *st;
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
st->idev->info = &ad9852_info;
st->idev->dev_data = (void *)(st);
st->idev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->idev);
if (ret)
goto error_free_dev;
spi->max_speed_hz = 2000000;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
ad9852_init(st);
return 0;
error_free_dev:
iio_free_device(st->idev);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int __devexit ad9852_remove(struct spi_device *spi)
{
struct ad9852_state *st = spi_get_drvdata(spi);
iio_device_unregister(st->idev);
kfree(st);
return 0;
}
static __init int ad9852_spi_init(void)
{
return spi_register_driver(&ad9852_driver);
}
static __exit void ad9852_spi_exit(void)
{
spi_unregister_driver(&ad9852_driver);
}
