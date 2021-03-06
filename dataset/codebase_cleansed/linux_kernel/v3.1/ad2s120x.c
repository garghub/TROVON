static ssize_t ad2s120x_show_val(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret = 0;
ssize_t len = 0;
u16 pos;
s16 vel;
u8 status;
struct ad2s120x_state *st = iio_priv(dev_get_drvdata(dev));
struct iio_dev_attr *iattr = to_iio_dev_attr(attr);
mutex_lock(&st->lock);
gpio_set_value(st->sample, 0);
udelay(1);
gpio_set_value(st->sample, 1);
gpio_set_value(st->rdvel, iattr->address);
ret = spi_read(st->sdev, st->rx, 2);
if (ret < 0)
goto error_ret;
status = st->rx[1];
if (iattr->address)
pos = (((u16)(st->rx[0])) << 4) | ((st->rx[1] & 0xF0) >> 4);
else {
vel = (st->rx[0] & 0x80) ? 0xf000 : 0;
vel |= (((s16)(st->rx[0])) << 4) | ((st->rx[1] & 0xF0) >> 4);
}
len = sprintf(buf, "%d %c%c%c%c ", iattr->address ? pos : vel,
(status & 0x8) ? 'P' : 'V',
(status & 0x4) ? 'd' : '_',
(status & 0x2) ? 'l' : '_',
(status & 0x1) ? '1' : '0');
error_ret:
udelay(1);
mutex_unlock(&st->lock);
return ret ? ret : len;
}
static int __devinit ad2s120x_probe(struct spi_device *spi)
{
struct ad2s120x_state *st;
struct iio_dev *indio_dev;
int pn, ret = 0;
unsigned short *pins = spi->dev.platform_data;
for (pn = 0; pn < AD2S120X_PN; pn++)
if (gpio_request_one(pins[pn], GPIOF_DIR_OUT, DRV_NAME)) {
pr_err("%s: request gpio pin %d failed\n",
DRV_NAME, pins[pn]);
goto error_ret;
}
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
mutex_init(&st->lock);
st->sdev = spi;
st->sample = pins[0];
st->rdvel = pins[1];
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ad2s120x_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
spi->max_speed_hz = AD2S120X_HZ;
spi->mode = SPI_MODE_3;
spi_setup(spi);
return 0;
error_free_dev:
iio_free_device(indio_dev);
error_ret:
for (--pn; pn >= 0; pn--)
gpio_free(pins[pn]);
return ret;
}
static int __devexit ad2s120x_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
return 0;
}
static __init int ad2s120x_spi_init(void)
{
return spi_register_driver(&ad2s120x_driver);
}
static __exit void ad2s120x_spi_exit(void)
{
spi_unregister_driver(&ad2s120x_driver);
}
