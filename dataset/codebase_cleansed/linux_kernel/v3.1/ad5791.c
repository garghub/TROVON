static int ad5791_spi_write(struct spi_device *spi, u8 addr, u32 val)
{
union {
u32 d32;
u8 d8[4];
} data;
data.d32 = cpu_to_be32(AD5791_CMD_WRITE |
AD5791_ADDR(addr) |
(val & AD5791_DAC_MASK));
return spi_write(spi, &data.d8[1], 3);
}
static int ad5791_spi_read(struct spi_device *spi, u8 addr, u32 *val)
{
union {
u32 d32;
u8 d8[4];
} data[3];
int ret;
struct spi_message msg;
struct spi_transfer xfers[] = {
{
.tx_buf = &data[0].d8[1],
.bits_per_word = 8,
.len = 3,
.cs_change = 1,
}, {
.tx_buf = &data[1].d8[1],
.rx_buf = &data[2].d8[1],
.bits_per_word = 8,
.len = 3,
},
};
data[0].d32 = cpu_to_be32(AD5791_CMD_READ |
AD5791_ADDR(addr));
data[1].d32 = cpu_to_be32(AD5791_ADDR(AD5791_ADDR_NOOP));
spi_message_init(&msg);
spi_message_add_tail(&xfers[0], &msg);
spi_message_add_tail(&xfers[1], &msg);
ret = spi_sync(spi, &msg);
*val = be32_to_cpu(data[2].d32);
return ret;
}
static ssize_t ad5791_write_dac(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
long readin;
int ret;
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
readin += (1 << (st->chip_info->bits - 1));
readin &= AD5791_RES_MASK(st->chip_info->bits);
readin <<= st->chip_info->left_shift;
ret = ad5791_spi_write(st->spi, this_attr->address, readin);
return ret ? ret : len;
}
static ssize_t ad5791_read_dac(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
int val;
ret = ad5791_spi_read(st->spi, this_attr->address, &val);
if (ret)
return ret;
val &= AD5791_DAC_MASK;
val >>= st->chip_info->left_shift;
val -= (1 << (st->chip_info->bits - 1));
return sprintf(buf, "%d\n", val);
}
static ssize_t ad5791_read_powerdown_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
const char mode[][14] = {"6kohm_to_gnd", "three_state"};
return sprintf(buf, "%s\n", mode[st->pwr_down_mode]);
}
static ssize_t ad5791_write_powerdown_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
int ret;
if (sysfs_streq(buf, "6kohm_to_gnd"))
st->pwr_down_mode = AD5791_DAC_PWRDN_6K;
else if (sysfs_streq(buf, "three_state"))
st->pwr_down_mode = AD5791_DAC_PWRDN_3STATE;
else
ret = -EINVAL;
return ret ? ret : len;
}
static ssize_t ad5791_read_dac_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", st->pwr_down);
}
static ssize_t ad5791_write_dac_powerdown(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
long readin;
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
ret = strict_strtol(buf, 10, &readin);
if (ret)
return ret;
if (readin == 0) {
st->pwr_down = false;
st->ctrl &= ~(AD5791_CTRL_OPGND | AD5791_CTRL_DACTRI);
} else if (readin == 1) {
st->pwr_down = true;
if (st->pwr_down_mode == AD5791_DAC_PWRDN_6K)
st->ctrl |= AD5791_CTRL_OPGND;
else if (st->pwr_down_mode == AD5791_DAC_PWRDN_3STATE)
st->ctrl |= AD5791_CTRL_DACTRI;
} else
ret = -EINVAL;
ret = ad5791_spi_write(st->spi, AD5791_ADDR_CTRL, st->ctrl);
return ret ? ret : len;
}
static ssize_t ad5791_show_scale(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
unsigned int scale_uv = (st->vref_mv * 1000) >> st->chip_info->bits;
return sprintf(buf, "%d.%03d\n", scale_uv / 1000, scale_uv % 1000);
}
static ssize_t ad5791_show_name(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5791_state *st = iio_priv(indio_dev);
return sprintf(buf, "%s\n", spi_get_device_id(st->spi)->name);
}
static int ad5791_get_lin_comp(unsigned int span)
{
if (span <= 10000)
return AD5791_LINCOMP_0_10;
else if (span <= 12000)
return AD5791_LINCOMP_10_12;
else if (span <= 16000)
return AD5791_LINCOMP_12_16;
else if (span <= 19000)
return AD5791_LINCOMP_16_19;
else
return AD5791_LINCOMP_19_20;
}
static int ad5780_get_lin_comp(unsigned int span)
{
if (span <= 10000)
return AD5780_LINCOMP_0_10;
else
return AD5780_LINCOMP_10_20;
}
static int __devinit ad5791_probe(struct spi_device *spi)
{
struct ad5791_platform_data *pdata = spi->dev.platform_data;
struct iio_dev *indio_dev;
struct regulator *reg_vdd, *reg_vss;
struct ad5791_state *st;
int ret, pos_voltage_uv = 0, neg_voltage_uv = 0;
reg_vdd = regulator_get(&spi->dev, "vdd");
if (!IS_ERR(reg_vdd)) {
ret = regulator_enable(reg_vdd);
if (ret)
goto error_put_reg_pos;
pos_voltage_uv = regulator_get_voltage(reg_vdd);
}
reg_vss = regulator_get(&spi->dev, "vss");
if (!IS_ERR(reg_vss)) {
ret = regulator_enable(reg_vss);
if (ret)
goto error_put_reg_neg;
neg_voltage_uv = regulator_get_voltage(reg_vss);
}
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_disable_reg_neg;
}
st = iio_priv(indio_dev);
st->pwr_down = true;
st->spi = spi;
if (!IS_ERR(reg_vss) && !IS_ERR(reg_vdd))
st->vref_mv = (pos_voltage_uv - neg_voltage_uv) / 1000;
else if (pdata)
st->vref_mv = pdata->vref_pos_mv - pdata->vref_neg_mv;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
ret = ad5791_spi_write(spi, AD5791_ADDR_SW_CTRL, AD5791_SWCTRL_RESET);
if (ret)
goto error_free_dev;
st->chip_info =
&ad5791_chip_info_tbl[spi_get_device_id(spi)->driver_data];
st->ctrl = AD5761_CTRL_LINCOMP(st->chip_info->get_lin_comp(st->vref_mv))
| ((pdata && pdata->use_rbuf_gain2) ? 0 : AD5791_CTRL_RBUF) |
AD5791_CTRL_BIN2SC;
ret = ad5791_spi_write(spi, AD5791_ADDR_CTRL, st->ctrl |
AD5791_CTRL_OPGND | AD5791_CTRL_DACTRI);
if (ret)
goto error_free_dev;
st->reg_vdd = reg_vdd;
st->reg_vss = reg_vss;
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &ad5791_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto error_free_dev;
return 0;
error_free_dev:
iio_free_device(indio_dev);
error_disable_reg_neg:
if (!IS_ERR(reg_vss))
regulator_disable(reg_vss);
error_put_reg_neg:
if (!IS_ERR(reg_vss))
regulator_put(reg_vss);
if (!IS_ERR(reg_vdd))
regulator_disable(reg_vdd);
error_put_reg_pos:
if (!IS_ERR(reg_vdd))
regulator_put(reg_vdd);
error_ret:
return ret;
}
static int __devexit ad5791_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5791_state *st = iio_priv(indio_dev);
struct regulator *reg_vdd = st->reg_vdd;
struct regulator *reg_vss = st->reg_vss;
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg_vdd)) {
regulator_disable(reg_vdd);
regulator_put(reg_vdd);
}
if (!IS_ERR(st->reg_vss)) {
regulator_disable(reg_vss);
regulator_put(reg_vss);
}
return 0;
}
static __init int ad5791_spi_init(void)
{
return spi_register_driver(&ad5791_driver);
}
static __exit void ad5791_spi_exit(void)
{
spi_unregister_driver(&ad5791_driver);
}
