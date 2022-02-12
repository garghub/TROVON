static int ad5446_write(struct ad5446_state *st, unsigned val)
{
__be16 data = cpu_to_be16(val);
return spi_write(st->spi, &data, sizeof(data));
}
static int ad5660_write(struct ad5446_state *st, unsigned val)
{
uint8_t data[3];
data[0] = (val >> 16) & 0xFF;
data[1] = (val >> 8) & 0xFF;
data[2] = val & 0xFF;
return spi_write(st->spi, data, sizeof(data));
}
static ssize_t ad5446_read_powerdown_mode_available(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
return sprintf(buf, "%s %s %s\n", ad5446_powerdown_modes[1],
ad5446_powerdown_modes[2], ad5446_powerdown_modes[3]);
}
static ssize_t ad5446_write_powerdown_mode(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
const char *buf, size_t len)
{
struct ad5446_state *st = iio_priv(indio_dev);
int i;
for (i = 1; i < ARRAY_SIZE(ad5446_powerdown_modes); i++) {
if (sysfs_streq(buf, ad5446_powerdown_modes[i])) {
st->pwr_down_mode = i;
break;
}
}
if (i == ARRAY_SIZE(ad5446_powerdown_modes))
return -EINVAL;
return len;
}
static ssize_t ad5446_read_powerdown_mode(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
char *buf)
{
struct ad5446_state *st = iio_priv(indio_dev);
return sprintf(buf, "%s\n", ad5446_powerdown_modes[st->pwr_down_mode]);
}
static ssize_t ad5446_read_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
char *buf)
{
struct ad5446_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", st->pwr_down);
}
static ssize_t ad5446_write_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private,
const struct iio_chan_spec *chan,
const char *buf, size_t len)
{
struct ad5446_state *st = iio_priv(indio_dev);
unsigned int shift;
unsigned int val;
bool powerdown;
int ret;
ret = strtobool(buf, &powerdown);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
st->pwr_down = powerdown;
if (st->pwr_down) {
shift = chan->scan_type.realbits + chan->scan_type.shift;
val = st->pwr_down_mode << shift;
} else {
val = st->cached_val;
}
ret = st->chip_info->write(st, val);
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int ad5446_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad5446_state *st = iio_priv(indio_dev);
unsigned long scale_uv;
switch (m) {
case IIO_CHAN_INFO_RAW:
*val = st->cached_val;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
scale_uv = (st->vref_mv * 1000) >> chan->scan_type.realbits;
*val = scale_uv / 1000;
*val2 = (scale_uv % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int ad5446_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad5446_state *st = iio_priv(indio_dev);
int ret = 0;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val >= (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
val <<= chan->scan_type.shift;
mutex_lock(&indio_dev->mlock);
st->cached_val = val;
if (!st->pwr_down)
ret = st->chip_info->write(st, val);
mutex_unlock(&indio_dev->mlock);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int __devinit ad5446_probe(struct spi_device *spi)
{
struct ad5446_state *st;
struct iio_dev *indio_dev;
struct regulator *reg;
int ret, voltage_uv = 0;
reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(reg)) {
ret = regulator_enable(reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(reg);
}
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_disable_reg;
}
st = iio_priv(indio_dev);
st->chip_info =
&ad5446_chip_info_tbl[spi_get_device_id(spi)->driver_data];
spi_set_drvdata(spi, indio_dev);
st->reg = reg;
st->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad5446_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = &st->chip_info->channel;
indio_dev->num_channels = 1;
if (st->chip_info->int_vref_mv)
st->vref_mv = st->chip_info->int_vref_mv;
else if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_device;
return 0;
error_free_device:
iio_device_free(indio_dev);
error_disable_reg:
if (!IS_ERR(reg))
regulator_disable(reg);
error_put_reg:
if (!IS_ERR(reg))
regulator_put(reg);
return ret;
}
static int ad5446_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5446_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_free(indio_dev);
return 0;
}
