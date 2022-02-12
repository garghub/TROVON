static int adis16130_spi_write(struct device *dev, u8 reg_addr,
u8 val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16130_state *st = iio_dev_get_devdata(indio_dev);
mutex_lock(&st->buf_lock);
st->buf[0] = reg_addr;
st->buf[1] = val;
ret = spi_write(st->us, st->buf, 2);
mutex_unlock(&st->buf_lock);
return ret;
}
static int adis16130_spi_read(struct device *dev, u8 reg_addr,
u32 *val)
{
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16130_state *st = iio_dev_get_devdata(indio_dev);
mutex_lock(&st->buf_lock);
st->buf[0] = ADIS16130_CON_RD | reg_addr;
if (st->mode)
ret = spi_read(st->us, st->buf, 4);
else
ret = spi_read(st->us, st->buf, 3);
if (ret == 0) {
if (st->mode)
*val = (st->buf[1] << 16) |
(st->buf[2] << 8) |
st->buf[3];
else
*val = (st->buf[1] << 8) | st->buf[2];
}
mutex_unlock(&st->buf_lock);
return ret;
}
static ssize_t adis16130_val_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
u32 val;
ssize_t ret;
mutex_lock(&indio_dev->mlock);
ret = adis16130_spi_read(dev, this_attr->address, &val);
mutex_unlock(&indio_dev->mlock);
if (ret == 0)
return sprintf(buf, "%d\n", val);
else
return ret;
}
static ssize_t adis16130_bitsmode_read(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct adis16130_state *st = iio_dev_get_devdata(indio_dev);
if (st->mode == 1)
return sprintf(buf, "s24\n");
else
return sprintf(buf, "s16\n");
}
static ssize_t adis16130_bitsmode_write(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
int ret;
u8 val;
if (sysfs_streq(buf, "s16"))
val = 0;
else if (sysfs_streq(buf, "s24"))
val = 1;
else
return -EINVAL;
ret = adis16130_spi_write(dev, ADIS16130_MODE, val);
return ret ? ret : len;
}
static int __devinit adis16130_probe(struct spi_device *spi)
{
int ret;
struct adis16130_state *st = kzalloc(sizeof *st, GFP_KERNEL);
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
st->indio_dev->info = &adis16130_info;
st->indio_dev->dev_data = (void *)(st);
st->indio_dev->modes = INDIO_DIRECT_MODE;
st->mode = 1;
ret = iio_device_register(st->indio_dev);
if (ret)
goto error_free_dev;
return 0;
error_free_dev:
iio_free_device(st->indio_dev);
error_free_st:
kfree(st);
error_ret:
return ret;
}
static int adis16130_remove(struct spi_device *spi)
{
struct adis16130_state *st = spi_get_drvdata(spi);
struct iio_dev *indio_dev = st->indio_dev;
iio_device_unregister(indio_dev);
kfree(st);
return 0;
}
static __init int adis16130_init(void)
{
return spi_register_driver(&adis16130_driver);
}
static __exit void adis16130_exit(void)
{
spi_unregister_driver(&adis16130_driver);
}
