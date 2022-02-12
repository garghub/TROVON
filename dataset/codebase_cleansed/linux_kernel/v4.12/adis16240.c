static ssize_t adis16240_spi_read_signed(struct device *dev,
struct device_attribute *attr,
char *buf,
unsigned int bits)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct adis *st = iio_priv(indio_dev);
int ret;
s16 val = 0;
unsigned int shift = 16 - bits;
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = adis_read_reg_16(st,
this_attr->address, (u16 *)&val);
if (ret)
return ret;
if (val & ADIS16240_ERROR_ACTIVE)
adis_check_status(st);
val = (s16)(val << shift) >> shift;
return sprintf(buf, "%d\n", val);
}
static ssize_t adis16240_read_12bit_signed(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return adis16240_spi_read_signed(dev, attr, buf, 12);
}
static int adis16240_read_raw(struct iio_dev *indio_dev,
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
ADIS16240_ERROR_ACTIVE, val);
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
if (chan->channel == 0) {
*val = 4;
*val2 = 880000;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
case IIO_TEMP:
*val = 244;
*val2 = 0;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_ACCEL:
*val = 0;
*val2 = IIO_G_TO_M_S_2(51400);
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
break;
case IIO_CHAN_INFO_PEAK_SCALE:
*val = 0;
*val2 = IIO_G_TO_M_S_2(51400);
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_OFFSET:
*val = 25000 / 244 - 0x133;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
bits = 10;
addr = adis16240_addresses[chan->scan_index][0];
ret = adis_read_reg_16(st, addr, &val16);
if (ret)
return ret;
val16 &= (1 << bits) - 1;
val16 = (s16)(val16 << (16 - bits)) >> (16 - bits);
*val = val16;
return IIO_VAL_INT;
case IIO_CHAN_INFO_PEAK:
bits = 10;
addr = adis16240_addresses[chan->scan_index][1];
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
static int adis16240_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct adis *st = iio_priv(indio_dev);
int bits = 10;
s16 val16;
u8 addr;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
val16 = val & ((1 << bits) - 1);
addr = adis16240_addresses[chan->scan_index][0];
return adis_write_reg_16(st, addr, val16);
}
return -EINVAL;
}
static int adis16240_probe(struct spi_device *spi)
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
indio_dev->info = &adis16240_info;
indio_dev->channels = adis16240_channels;
indio_dev->num_channels = ARRAY_SIZE(adis16240_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis_init(st, indio_dev, spi, &adis16240_data);
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
static int adis16240_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adis *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
adis_cleanup_buffer_and_trigger(st, indio_dev);
return 0;
}
