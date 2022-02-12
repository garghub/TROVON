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
struct spi_message m;
int ret;
spi_message_init(&m);
spi_message_add_tail(&t[0], &m);
spi_message_add_tail(&t[1], &m);
st->data[0].d32 = cpu_to_be32(AD5686_CMD(AD5686_CMD_READBACK_ENABLE) |
AD5686_ADDR(addr));
st->data[1].d32 = cpu_to_be32(AD5686_CMD(AD5686_CMD_NOOP));
ret = spi_sync(st->spi, &m);
if (ret < 0)
return ret;
return be32_to_cpu(st->data[2].d32);
}
static ssize_t ad5686_read_powerdown_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5686_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
char mode[][15] = {"", "1kohm_to_gnd", "100kohm_to_gnd", "three_state"};
return sprintf(buf, "%s\n", mode[(st->pwr_down_mode >>
(this_attr->address * 2)) & 0x3]);
}
static ssize_t ad5686_write_powerdown_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5686_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
unsigned mode;
if (sysfs_streq(buf, "1kohm_to_gnd"))
mode = AD5686_LDAC_PWRDN_1K;
else if (sysfs_streq(buf, "100kohm_to_gnd"))
mode = AD5686_LDAC_PWRDN_100K;
else if (sysfs_streq(buf, "three_state"))
mode = AD5686_LDAC_PWRDN_3STATE;
else
return -EINVAL;
st->pwr_down_mode &= ~(0x3 << (this_attr->address * 2));
st->pwr_down_mode |= (mode << (this_attr->address * 2));
return len;
}
static ssize_t ad5686_read_dac_powerdown(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5686_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
return sprintf(buf, "%d\n", !!(st->pwr_down_mask &
(0x3 << (this_attr->address * 2))));
}
static ssize_t ad5686_write_dac_powerdown(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
bool readin;
int ret;
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct ad5686_state *st = iio_priv(indio_dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
ret = strtobool(buf, &readin);
if (ret)
return ret;
if (readin == true)
st->pwr_down_mask |= (0x3 << (this_attr->address * 2));
else
st->pwr_down_mask &= ~(0x3 << (this_attr->address * 2));
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
case 0:
mutex_lock(&indio_dev->mlock);
ret = ad5686_spi_read(st, chan->address);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
break;
case (1 << IIO_CHAN_INFO_SCALE_SHARED):
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
case 0:
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
static int __devinit ad5686_probe(struct spi_device *spi)
{
struct ad5686_state *st;
struct iio_dev *indio_dev;
int ret, regdone = 0, voltage_uv = 0;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
st->chip_info =
&ad5686_chip_info_tbl[spi_get_device_id(spi)->driver_data];
if (voltage_uv)
st->vref_mv = voltage_uv / 1000;
else
st->vref_mv = st->chip_info->int_vref_mv;
st->spi = spi;
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
iio_free_device(indio_dev);
return ret;
}
static int __devexit ad5686_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5686_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_free_device(indio_dev);
return 0;
}
static __init int ad5686_spi_init(void)
{
return spi_register_driver(&ad5686_driver);
}
static __exit void ad5686_spi_exit(void)
{
spi_unregister_driver(&ad5686_driver);
}
