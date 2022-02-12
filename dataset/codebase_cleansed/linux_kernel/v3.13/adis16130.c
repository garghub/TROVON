static int adis16130_spi_read(struct iio_dev *indio_dev, u8 reg_addr, u32 *val)
{
int ret;
struct adis16130_state *st = iio_priv(indio_dev);
struct spi_transfer xfer = {
.tx_buf = st->buf,
.rx_buf = st->buf,
.len = 4,
};
mutex_lock(&st->buf_lock);
st->buf[0] = ADIS16130_CON_RD | reg_addr;
st->buf[1] = st->buf[2] = st->buf[3] = 0;
ret = spi_sync_transfer(st->us, &xfer, 1);
if (ret == 0)
*val = (st->buf[1] << 16) | (st->buf[2] << 8) | st->buf[3];
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16130_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
int ret;
u32 temp;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
ret = adis16130_spi_read(indio_dev, chan->address, &temp);
mutex_unlock(&indio_dev->mlock);
if (ret)
return ret;
*val = temp;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = 250;
*val2 = 336440817;
return IIO_VAL_FRACTIONAL;
case IIO_TEMP:
*val = 105000;
*val2 = 9516048 - 8036283;
return IIO_VAL_FRACTIONAL;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = -8388608;
return IIO_VAL_INT;
case IIO_TEMP:
*val = -8036283;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
return -EINVAL;
}
static int adis16130_probe(struct spi_device *spi)
{
struct adis16130_state *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
indio_dev->name = spi->dev.driver->name;
indio_dev->channels = adis16130_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16130_channels);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16130_info;
indio_dev->modes = INDIO_DIRECT_MODE;
return iio_device_register(indio_dev);
}
static int adis16130_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
return 0;
}
