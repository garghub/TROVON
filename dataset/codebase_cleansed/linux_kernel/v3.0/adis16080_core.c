static int adis16080_spi_write(struct device *dev,
u16 val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16080_state *st = iio_dev_get_devdata(indio_dev);
mutex_lock(&st->buf_lock);
st->buf[0] = val >> 8;
st->buf[1] = val;
ret = spi_write(st->us, st->buf, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16080_spi_read(struct device *dev,
u16 *val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16080_state *st = iio_dev_get_devdata(indio_dev);
mutex_lock(&st->buf_lock);
ret = spi_read(st->us, st->buf, 2);
if (ret == 0)
*val = ((st->buf[0] & 0xF) << 8) | st->buf[1];
mutex_unlock(&st->buf_lock);
return ret;
}
static ssize_t adis16080_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
u16 val = 0;
ssize_t ret;
mutex_lock(&indio_dev->mlock);
ret = adis16080_spi_write(dev,
this_attr->address | ADIS16080_DIN_WRITE);
if (ret < 0)
goto error_ret;
ret = adis16080_spi_read(dev, &val);
error_ret:
mutex_unlock(&indio_dev->mlock);
if (ret == 0)
return sprintf(buf, "%d\n", val);
else
return ret;
}
static int __devinit adis16080_probe(struct spi_device *spi)
{
int ret, regdone = 0;
struct adis16080_state *st = kzalloc(sizeof *st, GFP_KERNEL);
if (!st) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, st);
st->us = spi;
mutex_init(&st->buf_lock);
st->indio_dev = iio_allocate_device(0);
if (st->indio_dev == NULL) {
ret = -ENOMEM;
goto error_free_st;
}
st->indio_dev->name = spi->dev.driver->name;
st->indio_dev->dev.parent = &spi->dev;
st->indio_dev->info = &adis16080_info;
st->indio_dev->dev_data = (void *)(st);
st->indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(st->indio_dev);
if (ret)
goto error_free_dev;
regdone = 1;
return 0;
error_free_dev:
if (regdone)
iio_device_unregister(st->indio_dev);
else
iio_free_device(st->indio_dev);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int adis16080_remove(struct spi_device *spi)
{
struct adis16080_state *st = spi_get_drvdata(spi);
struct iio_dev *indio_dev = st->indio_dev;
iio_device_unregister(indio_dev);
kfree(st);
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
