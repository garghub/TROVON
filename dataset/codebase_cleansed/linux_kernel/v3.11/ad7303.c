static int ad7303_write(struct ad7303_state *st, unsigned int chan,
uint8_t val)
{
st->data = cpu_to_be16(AD7303_CMD_UPDATE_DAC |
(chan << AD7303_CFG_ADDR_OFFSET) |
st->config | val);
return spi_write(st->spi, &st->data, sizeof(st->data));
}
static ssize_t ad7303_read_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, char *buf)
{
struct ad7303_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n", (bool)(st->config &
AD7303_CFG_POWER_DOWN(chan->channel)));
}
static ssize_t ad7303_write_dac_powerdown(struct iio_dev *indio_dev,
uintptr_t private, const struct iio_chan_spec *chan, const char *buf,
size_t len)
{
struct ad7303_state *st = iio_priv(indio_dev);
bool pwr_down;
int ret;
ret = strtobool(buf, &pwr_down);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
if (pwr_down)
st->config |= AD7303_CFG_POWER_DOWN(chan->channel);
else
st->config &= ~AD7303_CFG_POWER_DOWN(chan->channel);
ad7303_write(st, chan->channel, st->dac_cache[chan->channel]);
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int ad7303_get_vref(struct ad7303_state *st,
struct iio_chan_spec const *chan)
{
int ret;
if (st->config & AD7303_CFG_EXTERNAL_VREF)
return regulator_get_voltage(st->vref_reg);
ret = regulator_get_voltage(st->vdd_reg);
if (ret < 0)
return ret;
return ret / 2;
}
static int ad7303_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long info)
{
struct ad7303_state *st = iio_priv(indio_dev);
int vref_uv;
switch (info) {
case IIO_CHAN_INFO_RAW:
*val = st->dac_cache[chan->channel];
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
vref_uv = ad7303_get_vref(st, chan);
if (vref_uv < 0)
return vref_uv;
*val = 2 * vref_uv / 1000;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
break;
}
return -EINVAL;
}
static int ad7303_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
struct ad7303_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val >= (1 << chan->scan_type.realbits) || val < 0)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
ret = ad7303_write(st, chan->address, val);
if (ret == 0)
st->dac_cache[chan->channel] = val;
mutex_unlock(&indio_dev->mlock);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int ad7303_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct iio_dev *indio_dev;
struct ad7303_state *st;
bool ext_ref;
int ret;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
st->vdd_reg = regulator_get(&spi->dev, "Vdd");
if (IS_ERR(st->vdd_reg)) {
ret = PTR_ERR(st->vdd_reg);
goto err_free;
}
ret = regulator_enable(st->vdd_reg);
if (ret)
goto err_put_vdd_reg;
if (spi->dev.of_node) {
ext_ref = of_property_read_bool(spi->dev.of_node,
"REF-supply");
} else {
struct ad7303_platform_data *pdata = spi->dev.platform_data;
if (pdata && pdata->use_external_ref)
ext_ref = true;
else
ext_ref = false;
}
if (ext_ref) {
st->vref_reg = regulator_get(&spi->dev, "REF");
if (IS_ERR(st->vref_reg)) {
ret = PTR_ERR(st->vref_reg);
goto err_disable_vdd_reg;
}
ret = regulator_enable(st->vref_reg);
if (ret)
goto err_put_vref_reg;
st->config |= AD7303_CFG_EXTERNAL_VREF;
}
indio_dev->dev.parent = &spi->dev;
indio_dev->name = id->name;
indio_dev->info = &ad7303_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ad7303_channels;
indio_dev->num_channels = ARRAY_SIZE(ad7303_channels);
ret = iio_device_register(indio_dev);
if (ret)
goto err_disable_vref_reg;
return 0;
err_disable_vref_reg:
if (st->vref_reg)
regulator_disable(st->vref_reg);
err_put_vref_reg:
if (st->vref_reg)
regulator_put(st->vref_reg);
err_disable_vdd_reg:
regulator_disable(st->vdd_reg);
err_put_vdd_reg:
regulator_put(st->vdd_reg);
err_free:
iio_device_free(indio_dev);
return ret;
}
static int ad7303_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7303_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (st->vref_reg) {
regulator_disable(st->vref_reg);
regulator_put(st->vref_reg);
}
regulator_disable(st->vdd_reg);
regulator_put(st->vdd_reg);
iio_device_free(indio_dev);
return 0;
}
