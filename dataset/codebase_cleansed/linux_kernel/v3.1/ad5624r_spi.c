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
static ssize_t ad5624r_write_dac(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
long readin;
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5624r_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
ret = ad5624r_spi_write(st->us, AD5624R_CMD_WRITE_INPUT_N_UPDATE_N,
this_attr->address, readin,
st->chip_info->bits);
return ret ? ret : len;
}
static ssize_t ad5624r_read_powerdown_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5624r_state *st = iio_priv(indio_dev);
char mode[][15] = {"", "1kohm_to_gnd", "100kohm_to_gnd", "three_state"};
return sprintf(buf, "%s\n", mode[st->pwr_down_mode]);
}
static ssize_t ad5624r_write_powerdown_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5624r_state *st = iio_priv(indio_dev);
int ret;
if (sysfs_streq(buf, "1kohm_to_gnd"))
st->pwr_down_mode = AD5624R_LDAC_PWRDN_1K;
else if (sysfs_streq(buf, "100kohm_to_gnd"))
st->pwr_down_mode = AD5624R_LDAC_PWRDN_100K;
else if (sysfs_streq(buf, "three_state"))
st->pwr_down_mode = AD5624R_LDAC_PWRDN_3STATE;
else
ret = -EINVAL;
return ret ? ret : len;
}
static ssize_t ad5624r_read_dac_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5624r_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
return sprintf(buf, "%d\n",
!!(st->pwr_down_mask & (1 << this_attr->address)));
}
static ssize_t ad5624r_write_dac_powerdown(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
long readin;
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5624r_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
if (readin == 1)
st->pwr_down_mask |= (1 << this_attr->address);
else if (!readin)
st->pwr_down_mask &= ~(1 << this_attr->address);
else
ret = -EINVAL;
ret = ad5624r_spi_write(st->us, AD5624R_CMD_POWERDOWN_DAC, 0,
(st->pwr_down_mode << 4) |
st->pwr_down_mask, 16);
return ret ? ret : len;
}
static ssize_t ad5624r_show_scale(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5624r_state *st = iio_priv(indio_dev);
unsigned int scale_uv = (st->vref_mv * 1000) >> st->chip_info->bits;
return sprintf(buf, "%d.%03d\n", scale_uv / 1000, scale_uv % 1000);
}
static int __devinit ad5624r_probe(struct spi_device *spi)
{
struct ad5624r_state *st;
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
st->reg = reg;
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
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
ret = ad5624r_spi_write(spi, AD5624R_CMD_INTERNAL_REFER_SETUP, 0,
!!voltage_uv, 16);
if (ret)
goto error_free_dev;
return 0;
error_free_dev:
iio_free_device(indio_dev);
error_disable_reg:
if (!IS_ERR(reg))
regulator_disable(reg);
error_put_reg:
if (!IS_ERR(reg))
regulator_put(reg);
return ret;
}
static int __devexit ad5624r_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5624r_state *st = iio_priv(indio_dev);
struct regulator *reg = st->reg;
iio_device_unregister(indio_dev);
if (!IS_ERR(reg)) {
regulator_disable(reg);
regulator_put(reg);
}
return 0;
}
static __init int ad5624r_spi_init(void)
{
return spi_register_driver(&ad5624r_driver);
}
static __exit void ad5624r_spi_exit(void)
{
spi_unregister_driver(&ad5624r_driver);
}
