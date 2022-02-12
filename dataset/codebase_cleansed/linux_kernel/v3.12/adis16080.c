static int adis16080_read_sample(struct iio_dev *indio_dev,
u16 addr, int *val)
{
struct adis16080_state *st = iio_priv(indio_dev);
struct spi_message m;
int ret;
struct spi_transfer t[] = {
{
.tx_buf = &st->buf,
.len = 2,
.cs_change = 1,
}, {
.rx_buf = &st->buf,
.len = 2,
},
};
st->buf = cpu_to_be16(addr | ADIS16080_DIN_WRITE);
spi_message_init(&m);
spi_message_add_tail(&t[0], &m);
spi_message_add_tail(&t[1], &m);
ret = spi_sync(st->us, &m);
if (ret == 0)
*val = sign_extend32(be16_to_cpu(st->buf), 11);
return ret;
}
static int adis16080_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct adis16080_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
ret = adis16080_read_sample(indio_dev, chan->address, val);
mutex_unlock(&indio_dev->mlock);
return ret ? ret : IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = st->info->scale_val;
*val2 = st->info->scale_val2;
return IIO_VAL_FRACTIONAL;
case IIO_VOLTAGE:
*val = 5000;
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_TEMP:
*val = 85000 - 25000;
*val2 = 585;
return IIO_VAL_FRACTIONAL;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
switch (chan->type) {
case IIO_VOLTAGE:
*val = 2048;
return IIO_VAL_INT;
case IIO_TEMP:
*val = DIV_ROUND_CLOSEST(25 * 585, 85 - 25);
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
break;
}
return -EINVAL;
}
static int adis16080_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct adis16080_state *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
st->info = &adis16080_chip_info[id->driver_data];
indio_dev->name = spi->dev.driver->name;
indio_dev->channels = adis16080_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16080_channels);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16080_info;
indio_dev->modes = INDIO_DIRECT_MODE;
return iio_device_register(indio_dev);
}
static int adis16080_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
return 0;
}
