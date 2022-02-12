static int adis16060_spi_write(struct device *dev,
u8 val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16060_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
st->buf[2] = val;
ret = spi_write(st->us_w, st->buf, 3);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16060_spi_read(struct device *dev,
u16 *val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16060_state *st = iio_priv(indio_dev);
mutex_lock(&st->buf_lock);
ret = spi_read(st->us_r, st->buf, 3);
if (ret == 0)
*val = ((st->buf[0] & 0x3) << 12) |
(st->buf[1] << 4) |
((st->buf[2] >> 4) & 0xF);
mutex_unlock(&st->buf_lock);
return ret;
}
static ssize_t adis16060_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
u16 val = 0;
ssize_t ret;
mutex_lock(&indio_dev->mlock);
ret = adis16060_spi_write(dev, this_attr->address);
if (ret < 0)
goto error_ret;
ret = adis16060_spi_read(dev, &val);
error_ret:
mutex_unlock(&indio_dev->mlock);
if (ret == 0)
return sprintf(buf, "%d\n", val);
else
return ret;
}
static int __devinit adis16060_r_probe(struct spi_device *spi)
{
int ret, regdone = 0;
struct adis16060_state *st;
struct iio_dev *indio_dev;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
st->us_r = spi;
mutex_init(&st->buf_lock);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16060_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
regdone = 1;
adis16060_iio_dev = indio_dev;
return 0;
error_free_dev:
if (regdone)
iio_device_unregister(indio_dev);
else
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int adis16060_r_remove(struct spi_device *spi)
{
iio_device_unregister(spi_get_drvdata(spi));
return 0;
}
static int __devinit adis16060_w_probe(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev = adis16060_iio_dev;
struct adis16060_state *st;
if (!indio_dev) {
ret = -ENODEV;
goto error_ret;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->us_w = spi;
return 0;
error_ret:
return ret;
}
static int adis16060_w_remove(struct spi_device *spi)
{
return 0;
}
static __init int adis16060_init(void)
{
int ret;
ret = spi_register_driver(&adis16060_r_driver);
if (ret < 0)
return ret;
ret = spi_register_driver(&adis16060_w_driver);
if (ret < 0) {
spi_unregister_driver(&adis16060_r_driver);
return ret;
}
return 0;
}
static __exit void adis16060_exit(void)
{
spi_unregister_driver(&adis16060_w_driver);
spi_unregister_driver(&adis16060_r_driver);
}
