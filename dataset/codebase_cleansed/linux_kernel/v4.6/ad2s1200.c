static int ad2s1200_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret = 0;
s16 vel;
struct ad2s1200_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
gpio_set_value(st->sample, 0);
udelay(1);
gpio_set_value(st->sample, 1);
gpio_set_value(st->rdvel, !!(chan->type == IIO_ANGL));
ret = spi_read(st->sdev, st->rx, 2);
if (ret < 0) {
mutex_unlock(&st->lock);
return ret;
}
switch (chan->type) {
case IIO_ANGL:
*val = (((u16)(st->rx[0])) << 4) | ((st->rx[1] & 0xF0) >> 4);
break;
case IIO_ANGL_VEL:
vel = (((s16)(st->rx[0])) << 4) | ((st->rx[1] & 0xF0) >> 4);
vel = sign_extend32(vel, 11);
*val = vel;
break;
default:
mutex_unlock(&st->lock);
return -EINVAL;
}
udelay(1);
mutex_unlock(&st->lock);
return IIO_VAL_INT;
}
static int ad2s1200_probe(struct spi_device *spi)
{
struct ad2s1200_state *st;
struct iio_dev *indio_dev;
int pn, ret = 0;
unsigned short *pins = spi->dev.platform_data;
for (pn = 0; pn < AD2S1200_PN; pn++) {
ret = devm_gpio_request_one(&spi->dev, pins[pn], GPIOF_DIR_OUT,
DRV_NAME);
if (ret) {
dev_err(&spi->dev, "request gpio pin %d failed\n",
pins[pn]);
return ret;
}
}
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
mutex_init(&st->lock);
st->sdev = spi;
st->sample = pins[0];
st->rdvel = pins[1];
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ad2s1200_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ad2s1200_channels;
indio_dev->num_channels = ARRAY_SIZE(ad2s1200_channels);
indio_dev->name = spi_get_device_id(spi)->name;
ret = devm_iio_device_register(&spi->dev, indio_dev);
if (ret)
return ret;
spi->max_speed_hz = AD2S1200_HZ;
spi->mode = SPI_MODE_3;
spi_setup(spi);
return 0;
}
