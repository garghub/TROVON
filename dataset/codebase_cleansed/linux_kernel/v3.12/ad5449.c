static int ad5449_write(struct iio_dev *indio_dev, unsigned int addr,
unsigned int val)
{
struct ad5449 *st = iio_priv(indio_dev);
int ret;
mutex_lock(&indio_dev->mlock);
st->data[0] = cpu_to_be16((addr << 12) | val);
ret = spi_write(st->spi, st->data, 2);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5449_read(struct iio_dev *indio_dev, unsigned int addr,
unsigned int *val)
{
struct ad5449 *st = iio_priv(indio_dev);
int ret;
struct spi_message msg;
struct spi_transfer t[] = {
{
.tx_buf = &st->data[0],
.len = 2,
.cs_change = 1,
}, {
.tx_buf = &st->data[1],
.rx_buf = &st->data[1],
.len = 2,
},
};
spi_message_init(&msg);
spi_message_add_tail(&t[0], &msg);
spi_message_add_tail(&t[1], &msg);
mutex_lock(&indio_dev->mlock);
st->data[0] = cpu_to_be16(addr << 12);
st->data[1] = cpu_to_be16(AD5449_CMD_NOOP);
ret = spi_sync(st->spi, &msg);
if (ret < 0)
goto out_unlock;
*val = be16_to_cpu(st->data[1]);
out_unlock:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5449_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
struct ad5449 *st = iio_priv(indio_dev);
struct regulator_bulk_data *reg;
int scale_uv;
int ret;
switch (info) {
case IIO_CHAN_INFO_RAW:
if (st->has_sdo) {
ret = ad5449_read(indio_dev,
AD5449_CMD_READ(chan->address), val);
if (ret)
return ret;
*val &= 0xfff;
} else {
*val = st->dac_cache[chan->address];
}
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
reg = &st->vref_reg[chan->channel];
scale_uv = regulator_get_voltage(reg->consumer);
if (scale_uv < 0)
return scale_uv;
*val = scale_uv / 1000;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
break;
}
return -EINVAL;
}
static int ad5449_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long info)
{
struct ad5449 *st = iio_priv(indio_dev);
int ret;
switch (info) {
case IIO_CHAN_INFO_RAW:
if (val < 0 || val >= (1 << chan->scan_type.realbits))
return -EINVAL;
ret = ad5449_write(indio_dev,
AD5449_CMD_LOAD_AND_UPDATE(chan->address),
val << chan->scan_type.shift);
if (ret == 0)
st->dac_cache[chan->address] = val;
break;
default:
ret = -EINVAL;
}
return ret;
}
static const char *ad5449_vref_name(struct ad5449 *st, int n)
{
if (st->chip_info->num_channels == 1)
return "VREF";
if (n == 0)
return "VREFA";
else
return "VREFB";
}
static int ad5449_spi_probe(struct spi_device *spi)
{
struct ad5449_platform_data *pdata = spi->dev.platform_data;
const struct spi_device_id *id = spi_get_device_id(spi);
struct iio_dev *indio_dev;
struct ad5449 *st;
unsigned int i;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->chip_info = &ad5449_chip_info[id->driver_data];
st->spi = spi;
for (i = 0; i < st->chip_info->num_channels; ++i)
st->vref_reg[i].supply = ad5449_vref_name(st, i);
ret = devm_regulator_bulk_get(&spi->dev, st->chip_info->num_channels,
st->vref_reg);
if (ret)
return ret;
ret = regulator_bulk_enable(st->chip_info->num_channels, st->vref_reg);
if (ret)
return ret;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = id->name;
indio_dev->info = &ad5449_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channels;
indio_dev->num_channels = st->chip_info->num_channels;
if (st->chip_info->has_ctrl) {
unsigned int ctrl = 0x00;
if (pdata) {
if (pdata->hardware_clear_to_midscale)
ctrl |= AD5449_CTRL_HCLR_TO_MIDSCALE;
ctrl |= pdata->sdo_mode << AD5449_CTRL_SDO_OFFSET;
st->has_sdo = pdata->sdo_mode != AD5449_SDO_DISABLED;
} else {
st->has_sdo = true;
}
ad5449_write(indio_dev, AD5449_CMD_CTRL, ctrl);
}
ret = iio_device_register(indio_dev);
if (ret)
goto error_disable_reg;
return 0;
error_disable_reg:
regulator_bulk_disable(st->chip_info->num_channels, st->vref_reg);
return ret;
}
static int ad5449_spi_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5449 *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_bulk_disable(st->chip_info->num_channels, st->vref_reg);
return 0;
}
