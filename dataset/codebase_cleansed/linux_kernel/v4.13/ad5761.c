static int _ad5761_spi_write(struct ad5761_state *st, u8 addr, u16 val)
{
st->data[0].d32 = cpu_to_be32(AD5761_ADDR(addr) | val);
return spi_write(st->spi, &st->data[0].d8[1], 3);
}
static int ad5761_spi_write(struct iio_dev *indio_dev, u8 addr, u16 val)
{
struct ad5761_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&indio_dev->mlock);
ret = _ad5761_spi_write(st, addr, val);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int _ad5761_spi_read(struct ad5761_state *st, u8 addr, u16 *val)
{
int ret;
struct spi_transfer xfers[] = {
{
.tx_buf = &st->data[0].d8[1],
.bits_per_word = 8,
.len = 3,
.cs_change = true,
}, {
.tx_buf = &st->data[1].d8[1],
.rx_buf = &st->data[2].d8[1],
.bits_per_word = 8,
.len = 3,
},
};
st->data[0].d32 = cpu_to_be32(AD5761_ADDR(addr));
st->data[1].d32 = cpu_to_be32(AD5761_ADDR(AD5761_ADDR_NOOP));
ret = spi_sync_transfer(st->spi, xfers, ARRAY_SIZE(xfers));
*val = be32_to_cpu(st->data[2].d32);
return ret;
}
static int ad5761_spi_read(struct iio_dev *indio_dev, u8 addr, u16 *val)
{
struct ad5761_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&indio_dev->mlock);
ret = _ad5761_spi_read(st, addr, val);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5761_spi_set_range(struct ad5761_state *st,
enum ad5761_voltage_range range)
{
u16 aux;
int ret;
aux = (range & 0x7) | AD5761_CTRL_ETS;
if (st->use_intref)
aux |= AD5761_CTRL_USE_INTVREF;
ret = _ad5761_spi_write(st, AD5761_ADDR_SW_FULL_RESET, 0);
if (ret)
return ret;
ret = _ad5761_spi_write(st, AD5761_ADDR_CTRL_WRITE_REG, aux);
if (ret)
return ret;
st->range = range;
return 0;
}
static int ad5761_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct ad5761_state *st;
int ret;
u16 aux;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = ad5761_spi_read(indio_dev, AD5761_ADDR_DAC_READ, &aux);
if (ret)
return ret;
*val = aux >> chan->scan_type.shift;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
st = iio_priv(indio_dev);
*val = st->vref * ad5761_range_params[st->range].m;
*val /= 10;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_OFFSET:
st = iio_priv(indio_dev);
*val = -(1 << chan->scan_type.realbits);
*val *= ad5761_range_params[st->range].c;
*val /= ad5761_range_params[st->range].m;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int ad5761_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
u16 aux;
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
if (val2 || (val << chan->scan_type.shift) > 0xffff || val < 0)
return -EINVAL;
aux = val << chan->scan_type.shift;
return ad5761_spi_write(indio_dev, AD5761_ADDR_DAC_WRITE, aux);
}
static int ad5761_get_vref(struct ad5761_state *st,
const struct ad5761_chip_info *chip_info)
{
int ret;
st->vref_reg = devm_regulator_get_optional(&st->spi->dev, "vref");
if (PTR_ERR(st->vref_reg) == -ENODEV) {
if (!chip_info->int_vref) {
dev_err(&st->spi->dev,
"Voltage reference not found\n");
return -EIO;
}
st->use_intref = true;
st->vref = chip_info->int_vref;
return 0;
}
if (IS_ERR(st->vref_reg)) {
dev_err(&st->spi->dev,
"Error getting voltage reference regulator\n");
return PTR_ERR(st->vref_reg);
}
ret = regulator_enable(st->vref_reg);
if (ret) {
dev_err(&st->spi->dev,
"Failed to enable voltage reference\n");
return ret;
}
ret = regulator_get_voltage(st->vref_reg);
if (ret < 0) {
dev_err(&st->spi->dev,
"Failed to get voltage reference value\n");
goto disable_regulator_vref;
}
if (ret < 2000000 || ret > 3000000) {
dev_warn(&st->spi->dev,
"Invalid external voltage ref. value %d uV\n", ret);
ret = -EIO;
goto disable_regulator_vref;
}
st->vref = ret / 1000;
st->use_intref = false;
return 0;
disable_regulator_vref:
regulator_disable(st->vref_reg);
st->vref_reg = NULL;
return ret;
}
static int ad5761_probe(struct spi_device *spi)
{
struct iio_dev *iio_dev;
struct ad5761_state *st;
int ret;
const struct ad5761_chip_info *chip_info =
&ad5761_chip_infos[spi_get_device_id(spi)->driver_data];
enum ad5761_voltage_range voltage_range = AD5761_VOLTAGE_RANGE_0V_5V;
struct ad5761_platform_data *pdata = dev_get_platdata(&spi->dev);
iio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!iio_dev)
return -ENOMEM;
st = iio_priv(iio_dev);
st->spi = spi;
spi_set_drvdata(spi, iio_dev);
ret = ad5761_get_vref(st, chip_info);
if (ret)
return ret;
if (pdata)
voltage_range = pdata->voltage_range;
ret = ad5761_spi_set_range(st, voltage_range);
if (ret)
goto disable_regulator_err;
iio_dev->dev.parent = &spi->dev;
iio_dev->info = &ad5761_info;
iio_dev->modes = INDIO_DIRECT_MODE;
iio_dev->channels = &chip_info->channel;
iio_dev->num_channels = 1;
iio_dev->name = spi_get_device_id(st->spi)->name;
ret = iio_device_register(iio_dev);
if (ret)
goto disable_regulator_err;
return 0;
disable_regulator_err:
if (!IS_ERR_OR_NULL(st->vref_reg))
regulator_disable(st->vref_reg);
return ret;
}
static int ad5761_remove(struct spi_device *spi)
{
struct iio_dev *iio_dev = spi_get_drvdata(spi);
struct ad5761_state *st = iio_priv(iio_dev);
iio_device_unregister(iio_dev);
if (!IS_ERR_OR_NULL(st->vref_reg))
regulator_disable(st->vref_reg);
return 0;
}
