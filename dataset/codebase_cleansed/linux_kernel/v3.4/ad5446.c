static void ad5446_store_sample(struct ad5446_state *st, unsigned val)
{
st->data.d16 = cpu_to_be16(AD5446_LOAD | val);
}
static void ad5542_store_sample(struct ad5446_state *st, unsigned val)
{
st->data.d16 = cpu_to_be16(val);
}
static void ad5620_store_sample(struct ad5446_state *st, unsigned val)
{
st->data.d16 = cpu_to_be16(AD5620_LOAD | val);
}
static void ad5660_store_sample(struct ad5446_state *st, unsigned val)
{
val |= AD5660_LOAD;
st->data.d24[0] = (val >> 16) & 0xFF;
st->data.d24[1] = (val >> 8) & 0xFF;
st->data.d24[2] = val & 0xFF;
}
static void ad5620_store_pwr_down(struct ad5446_state *st, unsigned mode)
{
st->data.d16 = cpu_to_be16(mode << 14);
}
static void ad5660_store_pwr_down(struct ad5446_state *st, unsigned mode)
{
unsigned val = mode << 16;
st->data.d24[0] = (val >> 16) & 0xFF;
st->data.d24[1] = (val >> 8) & 0xFF;
st->data.d24[2] = val & 0xFF;
}
static ssize_t ad5446_write_powerdown_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5446_state *st = iio_priv(indio_dev);
if (sysfs_streq(buf, "1kohm_to_gnd"))
st->pwr_down_mode = MODE_PWRDWN_1k;
else if (sysfs_streq(buf, "100kohm_to_gnd"))
st->pwr_down_mode = MODE_PWRDWN_100k;
else if (sysfs_streq(buf, "three_state"))
st->pwr_down_mode = MODE_PWRDWN_TRISTATE;
else
return -EINVAL;
return len;
}
static ssize_t ad5446_read_powerdown_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5446_state *st = iio_priv(indio_dev);
char mode[][15] = {"", "1kohm_to_gnd", "100kohm_to_gnd", "three_state"};
return sprintf(buf, "%s\n", mode[st->pwr_down_mode]);
}
static ssize_t ad5446_read_dac_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5446_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", st->pwr_down);
}
static ssize_t ad5446_write_dac_powerdown(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5446_state *st = iio_priv(indio_dev);
unsigned long readin;
int ret;
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
if (readin > 1)
ret = -EINVAL;
mutex_lock(&indio_dev->mlock);
st->pwr_down = readin;
if (st->pwr_down)
st->chip_info->store_pwr_down(st, st->pwr_down_mode);
else
st->chip_info->store_sample(st, st->cached_val);
ret = spi_sync(st->spi, &st->msg);
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
int ret;
switch (mask) {
case 0:
if (val >= (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
val <<= chan->scan_type.shift;
mutex_lock(&indio_dev->mlock);
st->cached_val = val;
st->chip_info->store_sample(st, val);
ret = spi_sync(st->spi, &st->msg);
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
indio_dev = iio_allocate_device(sizeof(*st));
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
if (st->chip_info->store_pwr_down)
indio_dev->info = &ad5446_info;
else
indio_dev->info = &ad5446_info_no_pwr_down;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = &st->chip_info->channel;
indio_dev->num_channels = 1;
st->xfer.tx_buf = &st->data;
st->xfer.len = st->chip_info->channel.scan_type.storagebits / 8;
spi_message_init(&st->msg);
spi_message_add_tail(&st->xfer, &st->msg);
switch (spi_get_device_id(spi)->driver_data) {
case ID_AD5620_2500:
case ID_AD5620_1250:
case ID_AD5640_2500:
case ID_AD5640_1250:
case ID_AD5660_2500:
case ID_AD5660_1250:
st->vref_mv = st->chip_info->int_vref_mv;
break;
default:
if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev,
"reference voltage unspecified\n");
}
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_device;
return 0;
error_free_device:
iio_free_device(indio_dev);
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
iio_free_device(indio_dev);
return 0;
}
