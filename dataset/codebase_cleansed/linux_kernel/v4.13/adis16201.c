static int adis16201_read_raw(struct iio_dev *indio_dev,
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
ADIS16201_ERROR_ACTIVE, val);
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
case IIO_ACCEL:
*val = 0;
*val2 = IIO_G_TO_M_S_2(462400);
return IIO_VAL_INT_PLUS_NANO;
case IIO_INCLI:
*val = 0;
*val2 = 100000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_OFFSET:
*val = 25000 / -470 - 1278;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
switch (chan->type) {
case IIO_ACCEL:
bits = 12;
break;
case IIO_INCLI:
bits = 9;
break;
default:
return -EINVAL;
}
addr = adis16201_addresses[chan->scan_index];
ret = adis_read_reg_16(st, addr, &val16);
if (ret)
return ret;
val16 &= (1 << bits) - 1;
val16 = (s16)(val16 << (16 - bits)) >> (16 - bits);
*val = val16;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int adis16201_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct adis *st = iio_priv(indio_dev);
int bits;
s16 val16;
u8 addr;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
switch (chan->type) {
case IIO_ACCEL:
bits = 12;
break;
case IIO_INCLI:
bits = 9;
break;
default:
return -EINVAL;
}
val16 = val & ((1 << bits) - 1);
addr = adis16201_addresses[chan->scan_index];
return adis_write_reg_16(st, addr, val16);
}
return -EINVAL;
}
static int adis16201_probe(struct spi_device *spi)
{
int ret;
struct adis *st;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
indio_dev->name = spi->dev.driver->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16201_info;
indio_dev->channels = adis16201_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16201_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis_init(st, indio_dev, spi, &adis16201_data);
if (ret)
return ret;
ret = adis_setup_buffer_and_trigger(st, indio_dev, NULL);
if (ret)
return ret;
ret = adis_initial_startup(st);
if (ret)
goto error_cleanup_buffer_trigger;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto error_cleanup_buffer_trigger;
return 0;
error_cleanup_buffer_trigger:
adis_cleanup_buffer_and_trigger(st, indio_dev);
return ret;
}
static int adis16201_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adis *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
adis_cleanup_buffer_and_trigger(st, indio_dev);
return 0;
}
