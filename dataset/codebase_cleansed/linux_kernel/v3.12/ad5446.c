static int ad5446_set_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int mode)
{
struct ad5446_state *st = iio_priv(indio_dev);
st->pwr_down_mode = mode + 1;
return 0;
}
static int ad5446_get_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct ad5446_state *st = iio_priv(indio_dev);
return st->pwr_down_mode - 1;
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
static int ad5446_probe(struct device *dev, const char *name,
const struct ad5446_chip_info *chip_info)
{
struct ad5446_state *st;
struct iio_dev *indio_dev;
struct regulator *reg;
int ret, voltage_uv = 0;
reg = devm_regulator_get(dev, "vcc");
if (!IS_ERR(reg)) {
ret = regulator_enable(reg);
if (ret)
return ret;
ret = regulator_get_voltage(reg);
if (ret < 0)
goto error_disable_reg;
voltage_uv = ret;
}
indio_dev = devm_iio_device_alloc(dev, sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_disable_reg;
}
st = iio_priv(indio_dev);
st->chip_info = chip_info;
dev_set_drvdata(dev, indio_dev);
st->reg = reg;
st->dev = dev;
indio_dev->dev.parent = dev;
indio_dev->name = name;
indio_dev->info = &ad5446_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = &st->chip_info->channel;
indio_dev->num_channels = 1;
st->pwr_down_mode = MODE_PWRDWN_1k;
if (st->chip_info->int_vref_mv)
st->vref_mv = st->chip_info->int_vref_mv;
else if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else
dev_warn(dev, "reference voltage unspecified\n");
ret = iio_device_register(indio_dev);
if (ret)
goto error_disable_reg;
return 0;
error_disable_reg:
if (!IS_ERR(reg))
regulator_disable(reg);
return ret;
}
static int ad5446_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5446_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
return 0;
}
static int ad5446_write(struct ad5446_state *st, unsigned val)
{
struct spi_device *spi = to_spi_device(st->dev);
__be16 data = cpu_to_be16(val);
return spi_write(spi, &data, sizeof(data));
}
static int ad5660_write(struct ad5446_state *st, unsigned val)
{
struct spi_device *spi = to_spi_device(st->dev);
uint8_t data[3];
data[0] = (val >> 16) & 0xFF;
data[1] = (val >> 8) & 0xFF;
data[2] = val & 0xFF;
return spi_write(spi, data, sizeof(data));
}
static int ad5446_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
return ad5446_probe(&spi->dev, id->name,
&ad5446_spi_chip_info[id->driver_data]);
}
static int ad5446_spi_remove(struct spi_device *spi)
{
return ad5446_remove(&spi->dev);
}
static int __init ad5446_spi_register_driver(void)
{
return spi_register_driver(&ad5446_spi_driver);
}
static void ad5446_spi_unregister_driver(void)
{
spi_unregister_driver(&ad5446_spi_driver);
}
static inline int ad5446_spi_register_driver(void) { return 0; }
static inline void ad5446_spi_unregister_driver(void) { }
static int ad5622_write(struct ad5446_state *st, unsigned val)
{
struct i2c_client *client = to_i2c_client(st->dev);
__be16 data = cpu_to_be16(val);
return i2c_master_send(client, (char *)&data, sizeof(data));
}
static int ad5446_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
return ad5446_probe(&i2c->dev, id->name,
&ad5446_i2c_chip_info[id->driver_data]);
}
static int ad5446_i2c_remove(struct i2c_client *i2c)
{
return ad5446_remove(&i2c->dev);
}
static int __init ad5446_i2c_register_driver(void)
{
return i2c_add_driver(&ad5446_i2c_driver);
}
static void __exit ad5446_i2c_unregister_driver(void)
{
i2c_del_driver(&ad5446_i2c_driver);
}
static inline int ad5446_i2c_register_driver(void) { return 0; }
static inline void ad5446_i2c_unregister_driver(void) { }
static int __init ad5446_init(void)
{
int ret;
ret = ad5446_spi_register_driver();
if (ret)
return ret;
ret = ad5446_i2c_register_driver();
if (ret) {
ad5446_spi_unregister_driver();
return ret;
}
return 0;
}
static void __exit ad5446_exit(void)
{
ad5446_i2c_unregister_driver();
ad5446_spi_unregister_driver();
}
