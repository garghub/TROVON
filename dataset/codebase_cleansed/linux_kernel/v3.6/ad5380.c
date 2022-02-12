static ssize_t ad5380_read_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
struct ad5380_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", st->pwr_down);
}
static ssize_t ad5380_write_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
struct ad5380_state *st = iio_priv(indio_dev);
bool pwr_down;
int ret;
ret = strtobool(buf, &pwr_down);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
if (pwr_down)
ret = regmap_write(st->regmap, AD5380_REG_SF_PWR_DOWN, 0);
else
ret = regmap_write(st->regmap, AD5380_REG_SF_PWR_UP, 0);
st->pwr_down = pwr_down;
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int ad5380_get_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct ad5380_state *st = iio_priv(indio_dev);
unsigned int mode;
int ret;
ret = regmap_read(st->regmap, AD5380_REG_SF_CTRL, &mode);
if (ret)
return ret;
mode = (mode >> AD5380_CTRL_PWR_DOWN_MODE_OFFSET) & 1;
return mode;
}
static int ad5380_set_powerdown_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, unsigned int mode)
{
struct ad5380_state *st = iio_priv(indio_dev);
int ret;
ret = regmap_update_bits(st->regmap, AD5380_REG_SF_CTRL,
1 << AD5380_CTRL_PWR_DOWN_MODE_OFFSET,
mode << AD5380_CTRL_PWR_DOWN_MODE_OFFSET);
return ret;
}
static unsigned int ad5380_info_to_reg(struct iio_chan_spec const *chan,
long info)
{
switch (info) {
case 0:
return AD5380_REG_DATA(chan->address);
case IIO_CHAN_INFO_CALIBBIAS:
return AD5380_REG_OFFSET(chan->address);
case IIO_CHAN_INFO_CALIBSCALE:
return AD5380_REG_GAIN(chan->address);
default:
break;
}
return 0;
}
static int ad5380_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long info)
{
const unsigned int max_val = (1 << chan->scan_type.realbits);
struct ad5380_state *st = iio_priv(indio_dev);
switch (info) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_CALIBSCALE:
if (val >= max_val || val < 0)
return -EINVAL;
return regmap_write(st->regmap,
ad5380_info_to_reg(chan, info),
val << chan->scan_type.shift);
case IIO_CHAN_INFO_CALIBBIAS:
val += (1 << chan->scan_type.realbits) / 2;
if (val >= max_val || val < 0)
return -EINVAL;
return regmap_write(st->regmap,
AD5380_REG_OFFSET(chan->address),
val << chan->scan_type.shift);
default:
break;
}
return -EINVAL;
}
static int ad5380_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
struct ad5380_state *st = iio_priv(indio_dev);
unsigned long scale_uv;
int ret;
switch (info) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_CALIBSCALE:
ret = regmap_read(st->regmap, ad5380_info_to_reg(chan, info),
val);
if (ret)
return ret;
*val >>= chan->scan_type.shift;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
ret = regmap_read(st->regmap, AD5380_REG_OFFSET(chan->address),
val);
if (ret)
return ret;
*val >>= chan->scan_type.shift;
val -= (1 << chan->scan_type.realbits) / 2;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
scale_uv = ((2 * st->vref) >> chan->scan_type.realbits) * 100;
*val = scale_uv / 100000;
*val2 = (scale_uv % 100000) * 10;
return IIO_VAL_INT_PLUS_MICRO;
default:
break;
}
return -EINVAL;
}
static int __devinit ad5380_alloc_channels(struct iio_dev *indio_dev)
{
struct ad5380_state *st = iio_priv(indio_dev);
struct iio_chan_spec *channels;
unsigned int i;
channels = kcalloc(st->chip_info->num_channels,
sizeof(struct iio_chan_spec), GFP_KERNEL);
if (!channels)
return -ENOMEM;
for (i = 0; i < st->chip_info->num_channels; ++i) {
channels[i] = st->chip_info->channel_template;
channels[i].channel = i;
channels[i].address = i;
}
indio_dev->channels = channels;
return 0;
}
static int __devinit ad5380_probe(struct device *dev, struct regmap *regmap,
enum ad5380_type type, const char *name)
{
struct iio_dev *indio_dev;
struct ad5380_state *st;
unsigned int ctrl = 0;
int ret;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
dev_err(dev, "Failed to allocate iio device\n");
ret = -ENOMEM;
goto error_out;
}
st = iio_priv(indio_dev);
dev_set_drvdata(dev, indio_dev);
st->chip_info = &ad5380_chip_info_tbl[type];
st->regmap = regmap;
indio_dev->dev.parent = dev;
indio_dev->name = name;
indio_dev->info = &ad5380_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->num_channels = st->chip_info->num_channels;
ret = ad5380_alloc_channels(indio_dev);
if (ret) {
dev_err(dev, "Failed to allocate channel spec: %d\n", ret);
goto error_free;
}
if (st->chip_info->int_vref == 2500000)
ctrl |= AD5380_CTRL_INT_VREF_2V5;
st->vref_reg = regulator_get(dev, "vref");
if (!IS_ERR(st->vref_reg)) {
ret = regulator_enable(st->vref_reg);
if (ret) {
dev_err(dev, "Failed to enable vref regulators: %d\n",
ret);
goto error_free_reg;
}
st->vref = regulator_get_voltage(st->vref_reg);
} else {
st->vref = st->chip_info->int_vref;
ctrl |= AD5380_CTRL_INT_VREF_EN;
}
ret = regmap_write(st->regmap, AD5380_REG_SF_CTRL, ctrl);
if (ret) {
dev_err(dev, "Failed to write to device: %d\n", ret);
goto error_disable_reg;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(dev, "Failed to register iio device: %d\n", ret);
goto error_disable_reg;
}
return 0;
error_disable_reg:
if (!IS_ERR(st->vref_reg))
regulator_disable(st->vref_reg);
error_free_reg:
if (!IS_ERR(st->vref_reg))
regulator_put(st->vref_reg);
kfree(indio_dev->channels);
error_free:
iio_device_free(indio_dev);
error_out:
return ret;
}
static int __devexit ad5380_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5380_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
kfree(indio_dev->channels);
if (!IS_ERR(st->vref_reg)) {
regulator_disable(st->vref_reg);
regulator_put(st->vref_reg);
}
iio_device_free(indio_dev);
return 0;
}
static bool ad5380_reg_false(struct device *dev, unsigned int reg)
{
return false;
}
static int __devinit ad5380_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct regmap *regmap;
regmap = devm_regmap_init_spi(spi, &ad5380_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return ad5380_probe(&spi->dev, regmap, id->driver_data, id->name);
}
static int __devexit ad5380_spi_remove(struct spi_device *spi)
{
return ad5380_remove(&spi->dev);
}
static inline int ad5380_spi_register_driver(void)
{
return spi_register_driver(&ad5380_spi_driver);
}
static inline void ad5380_spi_unregister_driver(void)
{
spi_unregister_driver(&ad5380_spi_driver);
}
static inline int ad5380_spi_register_driver(void)
{
return 0;
}
static inline void ad5380_spi_unregister_driver(void)
{
}
static int __devinit ad5380_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *regmap;
regmap = devm_regmap_init_i2c(i2c, &ad5380_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return ad5380_probe(&i2c->dev, regmap, id->driver_data, id->name);
}
static int __devexit ad5380_i2c_remove(struct i2c_client *i2c)
{
return ad5380_remove(&i2c->dev);
}
static inline int ad5380_i2c_register_driver(void)
{
return i2c_add_driver(&ad5380_i2c_driver);
}
static inline void ad5380_i2c_unregister_driver(void)
{
i2c_del_driver(&ad5380_i2c_driver);
}
static inline int ad5380_i2c_register_driver(void)
{
return 0;
}
static inline void ad5380_i2c_unregister_driver(void)
{
}
static int __init ad5380_spi_init(void)
{
int ret;
ret = ad5380_spi_register_driver();
if (ret)
return ret;
ret = ad5380_i2c_register_driver();
if (ret) {
ad5380_spi_unregister_driver();
return ret;
}
return 0;
}
static void __exit ad5380_spi_exit(void)
{
ad5380_i2c_unregister_driver();
ad5380_spi_unregister_driver();
}
