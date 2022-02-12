static int ltc2632_spi_write(struct spi_device *spi,
u8 cmd, u8 addr, u16 val, u8 shift)
{
u32 data;
u8 msg[3];
data = (cmd << 20) | (addr << 16) | (val << shift);
msg[0] = data >> 16;
msg[1] = data >> 8;
msg[2] = data;
return spi_write(spi, msg, sizeof(msg));
}
static int ltc2632_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ltc2632_chip_info *chip_info;
const struct ltc2632_state *st = iio_priv(indio_dev);
const struct spi_device_id *spi_dev_id = spi_get_device_id(st->spi_dev);
chip_info = (struct ltc2632_chip_info *)spi_dev_id->driver_data;
switch (m) {
case IIO_CHAN_INFO_SCALE:
*val = chip_info->vref_mv;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int ltc2632_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ltc2632_state *st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val >= (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
return ltc2632_spi_write(st->spi_dev,
LTC2632_CMD_WRITE_INPUT_N_UPDATE_N,
chan->address, val,
chan->scan_type.shift);
default:
return -EINVAL;
}
}
static ssize_t ltc2632_read_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
char *buf)
{
struct ltc2632_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n",
!!(st->powerdown_cache_mask & (1 << chan->channel)));
}
static ssize_t ltc2632_write_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
const char *buf,
size_t len)
{
bool pwr_down;
int ret;
struct ltc2632_state *st = iio_priv(indio_dev);
ret = strtobool(buf, &pwr_down);
if (ret)
return ret;
if (pwr_down)
st->powerdown_cache_mask |= (1 << chan->channel);
else
st->powerdown_cache_mask &= ~(1 << chan->channel);
ret = ltc2632_spi_write(st->spi_dev,
LTC2632_CMD_POWERDOWN_DAC_N,
chan->channel, 0, 0);
return ret ? ret : len;
}
static int ltc2632_probe(struct spi_device *spi)
{
struct ltc2632_state *st;
struct iio_dev *indio_dev;
struct ltc2632_chip_info *chip_info;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->spi_dev = spi;
chip_info = (struct ltc2632_chip_info *)
spi_get_device_id(spi)->driver_data;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = dev_of_node(&spi->dev) ? dev_of_node(&spi->dev)->name
: spi_get_device_id(spi)->name;
indio_dev->info = &ltc2632_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = chip_info->channels;
indio_dev->num_channels = LTC2632_DAC_CHANNELS;
ret = ltc2632_spi_write(spi, LTC2632_CMD_INTERNAL_REFER, 0, 0, 0);
if (ret) {
dev_err(&spi->dev,
"Set internal reference command failed, %d\n", ret);
return ret;
}
return devm_iio_device_register(&spi->dev, indio_dev);
}
