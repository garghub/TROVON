static ssize_t ads8688_show_scales(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ads8688_state *st = iio_priv(dev_to_iio_dev(dev));
return sprintf(buf, "0.%09u 0.%09u 0.%09u\n",
ads8688_range_def[0].scale * st->vref_mv,
ads8688_range_def[1].scale * st->vref_mv,
ads8688_range_def[2].scale * st->vref_mv);
}
static ssize_t ads8688_show_offsets(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d %d\n", ads8688_range_def[0].offset,
ads8688_range_def[3].offset);
}
static int ads8688_prog_write(struct iio_dev *indio_dev, unsigned int addr,
unsigned int val)
{
struct ads8688_state *st = iio_priv(indio_dev);
u32 tmp;
tmp = ADS8688_PROG_REG(addr) | ADS8688_PROG_WR_BIT | val;
tmp <<= ADS8688_PROG_DONT_CARE_BITS;
st->data[0].d32 = cpu_to_be32(tmp);
return spi_write(st->spi, &st->data[0].d8[1], 3);
}
static int ads8688_reset(struct iio_dev *indio_dev)
{
struct ads8688_state *st = iio_priv(indio_dev);
u32 tmp;
tmp = ADS8688_CMD_REG(ADS8688_CMD_REG_RST);
tmp <<= ADS8688_CMD_DONT_CARE_BITS;
st->data[0].d32 = cpu_to_be32(tmp);
return spi_write(st->spi, &st->data[0].d8[0], 4);
}
static int ads8688_read(struct iio_dev *indio_dev, unsigned int chan)
{
struct ads8688_state *st = iio_priv(indio_dev);
int ret;
u32 tmp;
struct spi_transfer t[] = {
{
.tx_buf = &st->data[0].d8[0],
.len = 4,
.cs_change = 1,
}, {
.tx_buf = &st->data[1].d8[0],
.rx_buf = &st->data[1].d8[0],
.len = 4,
},
};
tmp = ADS8688_CMD_REG(ADS8688_CMD_REG_MAN_CH(chan));
tmp <<= ADS8688_CMD_DONT_CARE_BITS;
st->data[0].d32 = cpu_to_be32(tmp);
tmp = ADS8688_CMD_REG(ADS8688_CMD_REG_NOOP);
tmp <<= ADS8688_CMD_DONT_CARE_BITS;
st->data[1].d32 = cpu_to_be32(tmp);
ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
if (ret < 0)
return ret;
return be32_to_cpu(st->data[1].d32) & 0xffff;
}
static int ads8688_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long m)
{
int ret, offset;
unsigned long scale_mv;
struct ads8688_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = ads8688_read(indio_dev, chan->channel);
mutex_unlock(&st->lock);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
scale_mv = st->vref_mv;
scale_mv *= ads8688_range_def[st->range[chan->channel]].scale;
*val = 0;
*val2 = scale_mv;
mutex_unlock(&st->lock);
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_OFFSET:
offset = ads8688_range_def[st->range[chan->channel]].offset;
*val = offset;
mutex_unlock(&st->lock);
return IIO_VAL_INT;
}
mutex_unlock(&st->lock);
return -EINVAL;
}
static int ads8688_write_reg_range(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
enum ads8688_range range)
{
unsigned int tmp;
int ret;
tmp = ADS8688_PROG_REG_RANGE_CH(chan->channel);
ret = ads8688_prog_write(indio_dev, tmp, range);
return ret;
}
static int ads8688_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct ads8688_state *st = iio_priv(indio_dev);
unsigned int scale = 0;
int ret = -EINVAL, i, offset = 0;
mutex_lock(&st->lock);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
offset = ads8688_range_def[st->range[chan->channel]].offset;
if (offset == 0 && val2 == ads8688_range_def[0].scale * st->vref_mv) {
mutex_unlock(&st->lock);
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(ads8688_range_def); i++)
if (val2 == ads8688_range_def[i].scale * st->vref_mv &&
offset == ads8688_range_def[i].offset) {
ret = ads8688_write_reg_range(indio_dev, chan,
ads8688_range_def[i].reg);
break;
}
break;
case IIO_CHAN_INFO_OFFSET:
if (!(ads8688_range_def[0].offset == val ||
ads8688_range_def[3].offset == val)) {
mutex_unlock(&st->lock);
return -EINVAL;
}
if (val == 0 &&
st->range[chan->channel] == ADS8688_PLUSMINUS25VREF) {
mutex_unlock(&st->lock);
return -EINVAL;
}
scale = ads8688_range_def[st->range[chan->channel]].scale;
for (i = 0; i < ARRAY_SIZE(ads8688_range_def); i++)
if (val == ads8688_range_def[i].offset &&
scale == ads8688_range_def[i].scale) {
ret = ads8688_write_reg_range(indio_dev, chan,
ads8688_range_def[i].reg);
break;
}
break;
}
if (!ret)
st->range[chan->channel] = ads8688_range_def[i].range;
mutex_unlock(&st->lock);
return ret;
}
static int ads8688_write_raw_get_fmt(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
long mask)
{
switch (mask) {
case IIO_CHAN_INFO_SCALE:
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_OFFSET:
return IIO_VAL_INT;
}
return -EINVAL;
}
static int ads8688_probe(struct spi_device *spi)
{
struct ads8688_state *st;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = devm_regulator_get_optional(&spi->dev, "vref");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
return ret;
ret = regulator_get_voltage(st->reg);
if (ret < 0)
goto error_out;
st->vref_mv = ret / 1000;
} else {
st->vref_mv = ADS8688_VREF_MV;
}
st->chip_info = &ads8688_chip_info_tbl[spi_get_device_id(spi)->driver_data];
spi->mode = SPI_MODE_1;
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channels;
indio_dev->num_channels = st->chip_info->num_channels;
indio_dev->info = &ads8688_info;
ads8688_reset(indio_dev);
mutex_init(&st->lock);
ret = iio_device_register(indio_dev);
if (ret)
goto error_out;
return 0;
error_out:
if (!IS_ERR_OR_NULL(st->reg))
regulator_disable(st->reg);
return ret;
}
static int ads8688_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ads8688_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR_OR_NULL(st->reg))
regulator_disable(st->reg);
return 0;
}
