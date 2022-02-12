static int adis16080_spi_write(struct iio_dev *indio_dev,
u16 val)
{
int ret;
struct adis16080_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->buf[0] = val >> 8;
st->buf[1] = val;
ret = spi_write(st->us, st->buf, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16080_spi_read(struct iio_dev *indio_dev,
u16 *val)
{
int ret;
struct adis16080_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
ret = spi_read(st->us, st->buf, 2);
if (ret == 0)
*val = ((st->buf[0] & 0xF) << 8) | st->buf[1];
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16080_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
int ret = -EINVAL;
u16 ut;
mutex_lock(&indio_dev->mlock);
switch (mask) {
case 0:
ret = adis16080_spi_write(indio_dev,
chan->address |
ADIS16080_DIN_WRITE);
if (ret < 0)
break;
ret = adis16080_spi_read(indio_dev, &ut);
if (ret < 0)
break;
*val = ut;
ret = IIO_VAL_INT;
break;
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int __devinit adis16080_probe(struct spi_device *spi)
{
int ret;
struct adis16080_state *st;
struct iio_dev *indio_dev;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us = spi;
mutex_init(&st->buf_lock);
indio_dev->name = spi->dev.driver->name;
indio_dev->channels = adis16080_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16080_channels);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16080_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
return 0;
error_free_dev:
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int adis16080_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
iio_free_device(spi_get_drvdata(spi));
return 0;
}
static __init int adis16080_init(void)
{
return spi_register_driver(&adis16080_driver);
}
static __exit void adis16080_exit(void)
{
spi_unregister_driver(&adis16080_driver);
}
