static int adis16260_stop_device(struct iio_dev *indio_dev)
{
struct adis16260 *adis16260 = iio_priv(indio_dev);
int ret;
u16 val = ADIS16260_SLP_CNT_POWER_OFF;
ret = adis_write_reg_16(&adis16260->adis, ADIS16260_SLP_CNT, val);
if (ret)
dev_err(&indio_dev->dev, "problem with turning device off: SLP_CNT");
return ret;
}
static int adis16260_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2,
long mask)
{
struct adis16260 *adis16260 = iio_priv(indio_dev);
const struct adis16260_chip_info *info = adis16260->info;
struct adis *adis = &adis16260->adis;
int ret;
u8 addr;
s16 val16;
switch (mask) {
case IIO_CHAN_INFO_RAW:
return adis_single_conversion(indio_dev, chan,
ADIS16260_ERROR_ACTIVE, val);
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_ANGL_VEL:
*val = info->gyro_max_scale;
*val2 = info->gyro_max_val;
return IIO_VAL_FRACTIONAL;
case IIO_INCLI:
*val = 0;
*val2 = IIO_DEGREE_TO_RAD(36630);
return IIO_VAL_INT_PLUS_MICRO;
case IIO_VOLTAGE:
if (chan->channel == 0) {
*val = 1;
*val2 = 831500;
} else {
*val = 0;
*val2 = 610500;
}
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 145;
*val2 = 300000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
*val = 250000 / 1453;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
addr = adis16260_addresses[chan->scan_index][0];
ret = adis_read_reg_16(adis, addr, &val16);
if (ret)
return ret;
*val = sign_extend32(val16, 11);
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBSCALE:
addr = adis16260_addresses[chan->scan_index][1];
ret = adis_read_reg_16(adis, addr, &val16);
if (ret)
return ret;
*val = val16;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = adis_read_reg_16(adis, ADIS16260_SMPL_PRD, &val16);
if (ret)
return ret;
if (spi_get_device_id(adis->spi)->driver_data)
*val = (val16 & ADIS16260_SMPL_PRD_TIME_BASE) ?
8 : 256;
else
*val = (val16 & ADIS16260_SMPL_PRD_TIME_BASE) ?
66 : 2048;
*val /= (val16 & ADIS16260_SMPL_PRD_DIV_MASK) + 1;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int adis16260_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct adis16260 *adis16260 = iio_priv(indio_dev);
struct adis *adis = &adis16260->adis;
int ret;
u8 addr;
u8 t;
switch (mask) {
case IIO_CHAN_INFO_CALIBBIAS:
if (val < -2048 || val >= 2048)
return -EINVAL;
addr = adis16260_addresses[chan->scan_index][0];
return adis_write_reg_16(adis, addr, val);
case IIO_CHAN_INFO_CALIBSCALE:
if (val < 0 || val >= 4096)
return -EINVAL;
addr = adis16260_addresses[chan->scan_index][1];
return adis_write_reg_16(adis, addr, val);
case IIO_CHAN_INFO_SAMP_FREQ:
mutex_lock(&indio_dev->mlock);
if (spi_get_device_id(adis->spi)->driver_data)
t = 256 / val;
else
t = 2048 / val;
if (t > ADIS16260_SMPL_PRD_DIV_MASK)
t = ADIS16260_SMPL_PRD_DIV_MASK;
else if (t > 0)
t--;
if (t >= 0x0A)
adis->spi->max_speed_hz = ADIS16260_SPI_SLOW;
else
adis->spi->max_speed_hz = ADIS16260_SPI_FAST;
ret = adis_write_reg_8(adis, ADIS16260_SMPL_PRD, t);
mutex_unlock(&indio_dev->mlock);
return ret;
}
return -EINVAL;
}
static int adis16260_probe(struct spi_device *spi)
{
const struct spi_device_id *id;
struct adis16260 *adis16260;
struct iio_dev *indio_dev;
int ret;
id = spi_get_device_id(spi);
if (!id)
return -ENODEV;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adis16260));
if (!indio_dev)
return -ENOMEM;
adis16260 = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
adis16260->info = &adis16260_chip_info_table[id->driver_data];
indio_dev->name = id->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &adis16260_info;
indio_dev->channels = adis16260->info->channels;
indio_dev->num_channels = adis16260->info->num_channels;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = adis_init(&adis16260->adis, indio_dev, spi, &adis16260_data);
if (ret)
return ret;
ret = adis_setup_buffer_and_trigger(&adis16260->adis, indio_dev, NULL);
if (ret)
return ret;
ret = adis_initial_startup(&adis16260->adis);
if (ret)
goto error_cleanup_buffer_trigger;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_buffer_trigger;
return 0;
error_cleanup_buffer_trigger:
adis_cleanup_buffer_and_trigger(&adis16260->adis, indio_dev);
return ret;
}
static int adis16260_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adis16260 *adis16260 = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
adis16260_stop_device(indio_dev);
adis_cleanup_buffer_and_trigger(&adis16260->adis, indio_dev);
return 0;
}
