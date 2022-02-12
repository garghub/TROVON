static int ad5064_spi_write(struct ad5064_state *st, unsigned int cmd,
unsigned int addr, unsigned int val, unsigned int shift)
{
val <<= shift;
st->data = cpu_to_be32(AD5064_CMD(cmd) | AD5064_ADDR(addr) | val);
return spi_write(st->spi, &st->data, sizeof(st->data));
}
static int ad5064_sync_powerdown_mode(struct ad5064_state *st,
unsigned int channel)
{
unsigned int val;
int ret;
val = (0x1 << channel);
if (st->pwr_down[channel])
val |= st->pwr_down_mode[channel] << 8;
ret = ad5064_spi_write(st, AD5064_CMD_POWERDOWN_DAC, 0, val, 0);
return ret;
}
static ssize_t ad5064_read_powerdown_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5064_state *st = iio_priv(indio_dev);
return sprintf(buf, "%s\n",
ad5064_powerdown_modes[st->pwr_down_mode[this_attr->address]]);
}
static ssize_t ad5064_write_powerdown_mode(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5064_state *st = iio_priv(indio_dev);
unsigned int mode, i;
int ret;
mode = 0;
for (i = 1; i < ARRAY_SIZE(ad5064_powerdown_modes); ++i) {
if (sysfs_streq(buf, ad5064_powerdown_modes[i])) {
mode = i;
break;
}
}
if (mode == 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
st->pwr_down_mode[this_attr->address] = mode;
ret = ad5064_sync_powerdown_mode(st, this_attr->address);
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static ssize_t ad5064_read_dac_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5064_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
return sprintf(buf, "%d\n", st->pwr_down[this_attr->address]);
}
static ssize_t ad5064_write_dac_powerdown(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5064_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
bool pwr_down;
int ret;
ret = strtobool(buf, &pwr_down);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
st->pwr_down[this_attr->address] = pwr_down;
ret = ad5064_sync_powerdown_mode(st, this_attr->address);
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int ad5064_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad5064_state *st = iio_priv(indio_dev);
unsigned int vref;
int scale_uv;
switch (m) {
case 0:
*val = st->dac_cache[chan->channel];
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
vref = st->chip_info->shared_vref ? 0 : chan->channel;
scale_uv = regulator_get_voltage(st->vref_reg[vref].consumer);
if (scale_uv < 0)
return scale_uv;
scale_uv = (scale_uv * 100) >> chan->scan_type.realbits;
*val = scale_uv / 100000;
*val2 = (scale_uv % 100000) * 10;
return IIO_VAL_INT_PLUS_MICRO;
default:
break;
}
return -EINVAL;
}
static int ad5064_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
struct ad5064_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case 0:
if (val > (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
ret = ad5064_spi_write(st, AD5064_CMD_WRITE_INPUT_N_UPDATE_N,
chan->address, val, chan->scan_type.shift);
if (ret == 0)
st->dac_cache[chan->channel] = val;
mutex_unlock(&indio_dev->mlock);
break;
default:
ret = -EINVAL;
}
return ret;
}
static inline unsigned int ad5064_num_vref(struct ad5064_state *st)
{
return st->chip_info->shared_vref ? 1 : AD5064_DAC_CHANNELS;
}
static const char * const ad5064_vref_name(struct ad5064_state *st,
unsigned int vref)
{
return st->chip_info->shared_vref ? "vref" : ad5064_vref_names[vref];
}
static int __devinit ad5064_probe(struct spi_device *spi)
{
enum ad5064_type type = spi_get_device_id(spi)->driver_data;
struct iio_dev *indio_dev;
struct ad5064_state *st;
unsigned int i;
int ret;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->chip_info = &ad5064_chip_info_tbl[type];
st->spi = spi;
for (i = 0; i < ad5064_num_vref(st); ++i)
st->vref_reg[i].supply = ad5064_vref_name(st, i);
ret = regulator_bulk_get(&st->spi->dev, ad5064_num_vref(st),
st->vref_reg);
if (ret)
goto error_free;
ret = regulator_bulk_enable(ad5064_num_vref(st), st->vref_reg);
if (ret)
goto error_free_reg;
for (i = 0; i < AD5064_DAC_CHANNELS; ++i) {
st->pwr_down_mode[i] = AD5064_LDAC_PWRDN_1K;
st->dac_cache[i] = 0x8000;
}
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad5064_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channel;
indio_dev->num_channels = AD5064_DAC_CHANNELS;
ret = iio_device_register(indio_dev);
if (ret)
goto error_disable_reg;
return 0;
error_disable_reg:
regulator_bulk_disable(ad5064_num_vref(st), st->vref_reg);
error_free_reg:
regulator_bulk_free(ad5064_num_vref(st), st->vref_reg);
error_free:
iio_free_device(indio_dev);
return ret;
}
static int __devexit ad5064_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5064_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_bulk_disable(ad5064_num_vref(st), st->vref_reg);
regulator_bulk_free(ad5064_num_vref(st), st->vref_reg);
iio_free_device(indio_dev);
return 0;
}
