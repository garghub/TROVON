static int ad5764_write(struct iio_dev *indio_dev, unsigned int reg,
unsigned int val)
{
struct ad5764_state *st = iio_priv(indio_dev);
int ret;
mutex_lock(&indio_dev->mlock);
st->data[0].d32 = cpu_to_be32((reg << 16) | val);
ret = spi_write(st->spi, &st->data[0].d8[1], 3);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5764_read(struct iio_dev *indio_dev, unsigned int reg,
unsigned int *val)
{
struct ad5764_state *st = iio_priv(indio_dev);
struct spi_message m;
int ret;
struct spi_transfer t[] = {
{
.tx_buf = &st->data[0].d8[1],
.len = 3,
.cs_change = 1,
}, {
.rx_buf = &st->data[1].d8[1],
.len = 3,
},
};
spi_message_init(&m);
spi_message_add_tail(&t[0], &m);
spi_message_add_tail(&t[1], &m);
mutex_lock(&indio_dev->mlock);
st->data[0].d32 = cpu_to_be32((1 << 23) | (reg << 16));
ret = spi_sync(st->spi, &m);
if (ret >= 0)
*val = be32_to_cpu(st->data[1].d32) & 0xffff;
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5764_chan_info_to_reg(struct iio_chan_spec const *chan, long info)
{
switch (info) {
case 0:
return AD5764_REG_DATA(chan->address);
case IIO_CHAN_INFO_CALIBBIAS:
return AD5764_REG_OFFSET(chan->address);
case IIO_CHAN_INFO_CALIBSCALE:
return AD5764_REG_FINE_GAIN(chan->address);
default:
break;
}
return 0;
}
static int ad5764_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long info)
{
const int max_val = (1 << chan->scan_type.realbits);
unsigned int reg;
switch (info) {
case 0:
if (val >= max_val || val < 0)
return -EINVAL;
val <<= chan->scan_type.shift;
break;
case IIO_CHAN_INFO_CALIBBIAS:
if (val >= 128 || val < -128)
return -EINVAL;
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (val >= 32 || val < -32)
return -EINVAL;
break;
default:
return -EINVAL;
}
reg = ad5764_chan_info_to_reg(chan, info);
return ad5764_write(indio_dev, reg, (u16)val);
}
static int ad5764_get_channel_vref(struct ad5764_state *st,
unsigned int channel)
{
if (st->chip_info->int_vref)
return st->chip_info->int_vref;
else
return regulator_get_voltage(st->vref_reg[channel / 2].consumer);
}
static int ad5764_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
struct ad5764_state *st = iio_priv(indio_dev);
unsigned long scale_uv;
unsigned int reg;
int vref;
int ret;
switch (info) {
case 0:
reg = AD5764_REG_DATA(chan->address);
ret = ad5764_read(indio_dev, reg, val);
if (ret < 0)
return ret;
*val >>= chan->scan_type.shift;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBBIAS:
reg = AD5764_REG_OFFSET(chan->address);
ret = ad5764_read(indio_dev, reg, val);
if (ret < 0)
return ret;
*val = sign_extend32(*val, 7);
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBSCALE:
reg = AD5764_REG_FINE_GAIN(chan->address);
ret = ad5764_read(indio_dev, reg, val);
if (ret < 0)
return ret;
*val = sign_extend32(*val, 5);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
vref = ad5764_get_channel_vref(st, chan->channel);
if (vref < 0)
return vref;
scale_uv = (vref * 4 * 100) >> chan->scan_type.realbits;
*val = scale_uv / 100000;
*val2 = (scale_uv % 100000) * 10;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_OFFSET:
*val = -(1 << chan->scan_type.realbits) / 2;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int __devinit ad5764_probe(struct spi_device *spi)
{
enum ad5764_type type = spi_get_device_id(spi)->driver_data;
struct iio_dev *indio_dev;
struct ad5764_state *st;
int ret;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
dev_err(&spi->dev, "Failed to allocate iio device\n");
return -ENOMEM;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
st->chip_info = &ad5764_chip_infos[type];
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad5764_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->num_channels = AD5764_NUM_CHANNELS;
indio_dev->channels = st->chip_info->channels;
if (st->chip_info->int_vref == 0) {
st->vref_reg[0].supply = "vrefAB";
st->vref_reg[1].supply = "vrefCD";
ret = regulator_bulk_get(&st->spi->dev,
ARRAY_SIZE(st->vref_reg), st->vref_reg);
if (ret) {
dev_err(&spi->dev, "Failed to request vref regulators: %d\n",
ret);
goto error_free;
}
ret = regulator_bulk_enable(ARRAY_SIZE(st->vref_reg),
st->vref_reg);
if (ret) {
dev_err(&spi->dev, "Failed to enable vref regulators: %d\n",
ret);
goto error_free_reg;
}
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&spi->dev, "Failed to register iio device: %d\n", ret);
goto error_disable_reg;
}
return 0;
error_disable_reg:
if (st->chip_info->int_vref == 0)
regulator_bulk_disable(ARRAY_SIZE(st->vref_reg), st->vref_reg);
error_free_reg:
if (st->chip_info->int_vref == 0)
regulator_bulk_free(ARRAY_SIZE(st->vref_reg), st->vref_reg);
error_free:
iio_free_device(indio_dev);
return ret;
}
static int __devexit ad5764_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad5764_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (st->chip_info->int_vref == 0) {
regulator_bulk_disable(ARRAY_SIZE(st->vref_reg), st->vref_reg);
regulator_bulk_free(ARRAY_SIZE(st->vref_reg), st->vref_reg);
}
iio_free_device(indio_dev);
return 0;
}
static int __init ad5764_spi_init(void)
{
return spi_register_driver(&ad5764_driver);
}
static void __exit ad5764_spi_exit(void)
{
spi_unregister_driver(&ad5764_driver);
}
