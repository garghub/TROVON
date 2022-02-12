static ssize_t ad9910_set_parameter(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct spi_message msg;
struct spi_transfer xfer;
int ret;
struct ad9910_config *config = (struct ad9910_config *)buf;
struct iio_dev *idev = dev_get_drvdata(dev);
struct ad9910_state *st = idev->dev_data;
xfer.len = 5;
xfer.tx_buf = &config->auxdac[0];
mutex_lock(&st->lock);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->ioupd[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->ftw[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 3;
xfer.tx_buf = &config->pow[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->asf[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->multc[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->dig_rampl[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->dig_ramps[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 5;
xfer.tx_buf = &config->dig_rampr[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep0[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep1[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep2[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep3[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep4[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep5[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep6[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
xfer.len = 9;
xfer.tx_buf = &config->sin_tonep7[0];
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
error_ret:
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static void ad9910_init(struct ad9910_state *st)
{
struct spi_message msg;
struct spi_transfer xfer;
int ret;
u8 cfr[5];
cfr[0] = CFR1;
cfr[1] = 0;
cfr[2] = MANUAL_OSK | INVSIC | DDS_SINEOP;
cfr[3] = AUTO_OSK | OSKEN | ACLR_PHA | ACLR_DIG | LOAD_LRR;
cfr[4] = 0;
mutex_lock(&st->lock);
xfer.len = 5;
xfer.tx_buf = &cfr;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
cfr[0] = CFR2;
cfr[1] = ENA_AMP;
cfr[2] = READ_FTW | DIGR_ENA | ITER_IOUPD;
cfr[3] = TX_ENA | PDCLK_INV | PDCLK_ENB;
cfr[4] = PARA_ENA;
xfer.len = 5;
xfer.tx_buf = &cfr;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
cfr[0] = CFR3;
cfr[1] = PLL_ENA;
cfr[2] = 0;
cfr[3] = REFCLK_RST | REFCLK_BYP;
cfr[4] = 0;
xfer.len = 5;
xfer.tx_buf = &cfr;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
ret = spi_sync(st->sdev, &msg);
if (ret)
goto error_ret;
error_ret:
mutex_unlock(&st->lock);
}
static int __devinit ad9910_probe(struct spi_device *spi)
{
struct ad9910_state *st;
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
st->idev->info = &ad9910_info;
st->idev->dev_data = (void *)(st);
st->idev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->idev);
if (ret)
goto error_free_dev;
spi->max_speed_hz = 2000000;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
ad9910_init(st);
return 0;
error_free_dev:
iio_free_device(st->idev);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int __devexit ad9910_remove(struct spi_device *spi)
{
struct ad9910_state *st = spi_get_drvdata(spi);
iio_device_unregister(st->idev);
kfree(st);
return 0;
}
static __init int ad9910_spi_init(void)
{
return spi_register_driver(&ad9910_driver);
}
static __exit void ad9910_spi_exit(void)
{
spi_unregister_driver(&ad9910_driver);
}
