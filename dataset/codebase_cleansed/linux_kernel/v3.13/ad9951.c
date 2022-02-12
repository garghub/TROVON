static ssize_t ad9951_set_parameter(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct spi_transfer xfer;
int ret;
struct ad9951_config *config = (struct ad9951_config *)buf;
struct iio_dev *idev = dev_to_iio_dev(dev);
struct ad9951_state *st = iio_priv(idev);
xfer.len = 3;
xfer.tx_buf = &config->asf[0];
mutex_lock(&st->lock);
ret = spi_sync_transfer(st->sdev, &xfer, 1);
if (ret)
goto error_ret;
xfer.len = 2;
xfer.tx_buf = &config->arr[0];
ret = spi_sync_transfer(st->sdev, &xfer, 1);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->ftw0[0];
ret = spi_sync_transfer(st->sdev, &xfer, 1);
if (ret)
goto error_ret;
xfer.len = 3;
xfer.tx_buf = &config->ftw1[0];
ret = spi_sync_transfer(st->sdev, &xfer, 1);
if (ret)
goto error_ret;
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static void ad9951_init(struct ad9951_state *st)
{
struct spi_transfer xfer;
int ret;
u8 cfr[5];
cfr[0] = CFR1;
cfr[1] = 0;
cfr[2] = LSB_FST | CLR_PHA | SINE_OPT | ACLR_PHA;
cfr[3] = AUTO_OSK | OSKEN | LOAD_ARR;
cfr[4] = 0;
mutex_lock(&st->lock);
xfer.len = 5;
xfer.tx_buf = &cfr;
ret = spi_sync_transfer(st->sdev, &xfer, 1);
if (ret)
goto error_ret;
cfr[0] = CFR2;
cfr[1] = VCO_RANGE;
cfr[2] = HSPD_SYNC;
cfr[3] = 0;
xfer.len = 4;
xfer.tx_buf = &cfr;
ret = spi_sync_transfer(st->sdev, &xfer, 1);
if (ret)
goto error_ret;
error_ret:
mutex_unlock(&st->lock);
}
static int ad9951_probe(struct spi_device *spi)
{
struct ad9951_state *st;
struct iio_dev *idev;
int ret = 0;
idev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!idev)
return -ENOMEM;
spi_set_drvdata(spi, idev);
st = iio_priv(idev);
mutex_init(&st->lock);
st->sdev = spi;
idev->dev.parent = &spi->dev;
idev->info = &ad9951_info;
idev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(idev);
if (ret)
return ret;
spi->max_speed_hz = 2000000;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
ad9951_init(st);
return 0;
}
static int ad9951_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
return 0;
}
