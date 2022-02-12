static int ad5686_spi_write(struct ad5686_state *st,
u8 cmd, u8 addr, u16 val, u8 shift)
{
val <<= shift;
st->data[0].d32 = cpu_to_be32(AD5686_CMD(cmd) |
AD5686_ADDR(addr) |
val);
return spi_write(st->spi, &st->data[0].d8[1], 3);
}
static int ad5686_spi_read(struct ad5686_state *st, u8 addr)
{
struct spi_transfer t[] = {
{
.tx_buf = &st->data[0].d8[1],
.len = 3,
.cs_change = 1,
}, {
.tx_buf = &st->data[1].d8[1],
.rx_buf = &st->data[2].d8[1],
.len = 3,
},
};
int ret;
st->data[0].d32 = cpu_to_be32(AD5686_CMD(AD5686_CMD_READBACK_ENABLE) |
AD5686_ADDR(addr));
st->data[1].d32 = cpu_to_be32(AD5686_CMD(AD5686_CMD_NOOP));
ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
if (ret < 0)
return ret;
return be32_to_cpu(st->data[2].d32);
}
static int ad5686_get_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct ad5686_state *st = iio_priv(indio_dev);
return ((st->pwr_down_mode >> (chan->channel * 2)) & 0x3) - 1;
}
static int ad5686_set_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int mode)
{
struct ad5686_state *st = iio_priv(indio_dev);
st->pwr_down_mode &= ~(0x3 << (chan->channel * 2));
st->pwr_down_mode |= ((mode + 1) << (chan->channel * 2));
return 0;
}
static ssize_t ad5686_read_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
struct ad5686_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", !!(st->pwr_down_mask &
(0x3 << (chan->channel * 2))));
}
static ssize_t ad5686_write_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
bool readin;
int ret;
struct ad5686_state *st = iio_priv(indio_dev);
ret = strtobool(buf, &readin);
if (ret)
return ret;
if (readin)
st->pwr_down_mask |= (0x3 << (chan->channel * 2));
else
st->pwr_down_mask &= ~(0x3 << (chan->channel * 2));
ret = ad5686_spi_write(st, AD5686_CMD_POWERDOWN_DAC, 0,
st->pwr_down_mask & st->pwr_down_mode, 0);
return ret ? ret : len;
}
static int ad5686_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad5686_state *st = iio_priv(indio_dev);
unsigned long scale_uv;
int ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
ret = ad5686_spi_read(st, chan->address);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
scale_uv = (st->vref_mv * 100000)
>> (chan->scan_type.realbits);
*val = scale_uv / 100000;
*val2 = (scale_uv % 100000) * 10;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int ad5686_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad5686_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val > (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
ret = ad5686_spi_write(st,
AD5686_CMD_WRITE_INPUT_N_UPDATE_N,
chan->address,
val,
chan->scan_type.shift);
mutex_unlock(&indio_dev->mlock);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int ad5686_probe(struct spi_device *spi)
{
struct ad5686_state *st;
struct iio_dev *indio_dev;
int ret, regdone = 0, voltage_uv = 0;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
ret = regulator_get_voltage(st->reg);
if (ret < 0)
goto error_disable_reg;
voltage_uv = ret;
}
st->chip_info =
&ad5686_chip_info_tbl[spi_get_device_id(spi)->driver_data];
if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else
st->vref_mv = st->chip_info->int_vref_mv;
st->spi = spi;
st->pwr_down_mode = 0x55;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad5686_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channel;
indio_dev->num_channels = AD5686_DAC_CHANNELS;
regdone = 1;
ret = ad5686_spi_write(st, AD5686_CMD_INTERNAL_REFER_SETUP, 0,
!!voltage_uv, 0);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_disable_reg;
return 0;
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
iio_device_free(indio_dev);
return ret;
}
static int ad5686_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5686_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_free(indio_dev);
return 0;
}
