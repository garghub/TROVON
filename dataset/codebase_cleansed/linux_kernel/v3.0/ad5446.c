static void ad5446_store_sample(struct ad5446_state *st, unsigned val)
{
st->data.d16 = cpu_to_be16(AD5446_LOAD |
(val << st->chip_info->left_shift));
}
static void ad5542_store_sample(struct ad5446_state *st, unsigned val)
{
st->data.d16 = cpu_to_be16(val << st->chip_info->left_shift);
}
static void ad5620_store_sample(struct ad5446_state *st, unsigned val)
{
st->data.d16 = cpu_to_be16(AD5620_LOAD |
(val << st->chip_info->left_shift));
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
static ssize_t ad5446_write(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad5446_state *st = dev_info->dev_data;
int ret;
long val;
ret = strict_strtol(buf, 10, &val);
if (ret)
goto error_ret;
if (val > RES_MASK(st->chip_info->bits)) {
ret = -EINVAL;
goto error_ret;
}
mutex_lock(&dev_info->mlock);
st->cached_val = val;
st->chip_info->store_sample(st, val);
ret = spi_sync(st->spi, &st->msg);
mutex_unlock(&dev_info->mlock);
error_ret:
return ret ? ret : len;
}
static ssize_t ad5446_show_scale(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad5446_state *st = iio_dev_get_devdata(dev_info);
unsigned int scale_uv = (st->vref_mv * 1000) >> st->chip_info->bits;
return sprintf(buf, "%d.%03d\n", scale_uv / 1000, scale_uv % 1000);
}
static ssize_t ad5446_write_powerdown_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad5446_state *st = dev_info->dev_data;
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
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad5446_state *st = dev_info->dev_data;
char mode[][15] = {"", "1kohm_to_gnd", "100kohm_to_gnd", "three_state"};
return sprintf(buf, "%s\n", mode[st->pwr_down_mode]);
}
static ssize_t ad5446_read_dac_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad5446_state *st = dev_info->dev_data;
return sprintf(buf, "%d\n", st->pwr_down);
}
static ssize_t ad5446_write_dac_powerdown(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad5446_state *st = dev_info->dev_data;
unsigned long readin;
int ret;
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
if (readin > 1)
ret = -EINVAL;
mutex_lock(&dev_info->mlock);
st->pwr_down = readin;
if (st->pwr_down)
st->chip_info->store_pwr_down(st, st->pwr_down_mode);
else
st->chip_info->store_sample(st, st->cached_val);
ret = spi_sync(st->spi, &st->msg);
mutex_unlock(&dev_info->mlock);
return ret ? ret : len;
}
static mode_t ad5446_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct iio_dev *dev_info = dev_get_drvdata(dev);
struct ad5446_state *st = iio_dev_get_devdata(dev_info);
mode_t mode = attr->mode;
if (!st->chip_info->store_pwr_down &&
(attr == &iio_dev_attr_out0_powerdown.dev_attr.attr ||
attr == &iio_dev_attr_out_powerdown_mode.dev_attr.attr ||
attr ==
&iio_const_attr_out_powerdown_mode_available.dev_attr.attr))
mode = 0;
return mode;
}
static int __devinit ad5446_probe(struct spi_device *spi)
{
struct ad5446_state *st;
int ret, voltage_uv = 0;
st = kzalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
st->chip_info =
&ad5446_chip_info_tbl[spi_get_device_id(spi)->driver_data];
spi_set_drvdata(spi, st);
st->spi = spi;
st->indio_dev = iio_allocate_device(0);
if (st->indio_dev == NULL) {
ret = -ENOMEM;
goto error_disable_reg;
}
st->indio_dev->dev.parent = &spi->dev;
st->indio_dev->name = spi_get_device_id(spi)->name;
st->indio_dev->info = &ad5446_info;
st->indio_dev->dev_data = (void *)(st);
st->indio_dev->modes = INDIO_DIRECT_MODE;
st->xfer.tx_buf = &st->data;
st->xfer.len = st->chip_info->storagebits / 8;
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
ret = iio_device_register(st->indio_dev);
if (ret)
goto error_free_device;
return 0;
error_free_device:
iio_free_device(st->indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
kfree(st);
error_ret:
return ret;
}
static int ad5446_remove(struct spi_device *spi)
{
struct ad5446_state *st = spi_get_drvdata(spi);
struct iio_dev *indio_dev = st->indio_dev;
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
kfree(st);
return 0;
}
static int __init ad5446_init(void)
{
return spi_register_driver(&ad5446_driver);
}
static void __exit ad5446_exit(void)
{
spi_unregister_driver(&ad5446_driver);
}
