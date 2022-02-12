static int ad5624r_spi_write(struct spi_device *spi,
u8 cmd, u8 addr, u16 val, u8 len)
{
u32 data;
u8 msg[3];
data = (0 << 22) | (cmd << 19) | (addr << 16) | (val << (16 - len));
msg[0] = data >> 16;
msg[1] = data >> 8;
msg[2] = data;
return spi_write(spi, msg, 3);
}
static int ad5624r_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad5624r_state *st = iio_priv(indio_dev);
switch (m) {
case IIO_CHAN_INFO_SCALE:
*val = st->vref_mv;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int ad5624r_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad5624r_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val >= (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
return ad5624r_spi_write(st->us,
AD5624R_CMD_WRITE_INPUT_N_UPDATE_N,
chan->address, val,
chan->scan_type.shift);
default:
ret = -EINVAL;
}
return -EINVAL;
}
static int ad5624r_get_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct ad5624r_state *st = iio_priv(indio_dev);
return st->pwr_down_mode;
}
static int ad5624r_set_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int mode)
{
struct ad5624r_state *st = iio_priv(indio_dev);
st->pwr_down_mode = mode;
return 0;
}
static ssize_t ad5624r_read_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
struct ad5624r_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n",
!!(st->pwr_down_mask & (1 << chan->channel)));
}
static ssize_t ad5624r_write_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
bool pwr_down;
int ret;
struct ad5624r_state *st = iio_priv(indio_dev);
ret = strtobool(buf, &pwr_down);
if (ret)
return ret;
if (pwr_down)
st->pwr_down_mask |= (1 << chan->channel);
else
st->pwr_down_mask &= ~(1 << chan->channel);
ret = ad5624r_spi_write(st->us, AD5624R_CMD_POWERDOWN_DAC, 0,
(st->pwr_down_mode << 4) |
st->pwr_down_mask, 16);
return ret ? ret : len;
}
static int ad5624r_probe(struct spi_device *spi)
{
struct ad5624r_state *st;
struct iio_dev *indio_dev;
int ret, voltage_uv = 0;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = devm_regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
return ret;
ret = regulator_get_voltage(st->reg);
if (ret < 0)
goto error_disable_reg;
voltage_uv = ret;
}
spi_set_drvdata(spi, indio_dev);
st->chip_info =
&ad5624r_chip_info_tbl[spi_get_device_id(spi)->driver_data];
if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else
st->vref_mv = st->chip_info->int_vref_mv;
st->us = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad5624r_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channels;
indio_dev->num_channels = AD5624R_DAC_CHANNELS;
ret = ad5624r_spi_write(spi, AD5624R_CMD_INTERNAL_REFER_SETUP, 0,
!!voltage_uv, 16);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_disable_reg;
return 0;
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return ret;
}
static int ad5624r_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5624r_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return 0;
}
