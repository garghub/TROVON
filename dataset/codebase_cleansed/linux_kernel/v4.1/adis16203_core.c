static int adis16203_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct adis *st = iio_priv(indio_dev);
u8 addr = adis16203_addresses[chan->scan_index];
return adis_write_reg_16(st, addr, val & 0x3FFF);
}
static int adis16203_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct adis *st = iio_priv(indio_dev);
int ret;
int bits;
u8 addr;
s16 val16;
switch (mask) {
case IIO_CHAN_INFO_RAW:
return adis_single_conversion(indio_dev, chan,
ADIS16203_ERROR_ACTIVE, val);
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
if (chan->channel == 0) {
*val = 1;
*val2 = 220000;
} else {
*val = 0;
*val2 = 610000;
}
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = -470;
*val2 = 0;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_INCLI:
*val = 0;
*val2 = 25000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
*val = 25000 / -470 - 1278;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
bits = 14;
mutex_lock(&indio_dev->mlock);
addr = adis16203_addresses[chan->scan_index];
ret = adis_read_reg_16(st, addr, &val16);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
val16 &= (1 << bits) - 1;
val16 = (s16)(val16 << (16 - bits)) >> (16 - bits);
*val = val16;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int adis16203_probe(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev;
struct adis *st;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->channels = adis16203_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16203_channels);
indio_dev->info = &adis16203_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis_init(st, indio_dev, spi, &adis16203_data);
if (ret)
return ret;
ret = adis_setup_buffer_and_trigger(st, indio_dev, NULL);
if (ret)
return ret;
ret = adis_initial_startup(st);
if (ret)
goto error_cleanup_buffer_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_buffer_trigger;
return 0;
error_cleanup_buffer_trigger:
adis_cleanup_buffer_and_trigger(st, indio_dev);
return ret;
}
static int adis16203_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adis *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
adis_cleanup_buffer_and_trigger(st, indio_dev);
return 0;
}
