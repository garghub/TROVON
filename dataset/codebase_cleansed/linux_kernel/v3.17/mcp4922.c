static int mcp4922_spi_write(struct mcp4922_state *state, u8 addr, u32 val)
{
state->mosi[1] = val & 0xff;
state->mosi[0] = (addr == 0) ? 0x00 : 0x80;
state->mosi[0] |= 0x30 | ((val >> 8) & 0x0f);
return spi_write(state->spi, state->mosi, 2);
}
static int mcp4922_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct mcp4922_state *state = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
*val = state->value[chan->channel];
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = state->vref_mv;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static int mcp4922_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct mcp4922_state *state = iio_priv(indio_dev);
if (val2 != 0)
return -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val > GENMASK(chan->scan_type.realbits-1, 0))
return -EINVAL;
val <<= chan->scan_type.shift;
state->value[chan->channel] = val;
return mcp4922_spi_write(state, chan->channel, val);
default:
return -EINVAL;
}
}
static int mcp4922_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct mcp4922_state *state;
const struct spi_device_id *id;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*state));
if (indio_dev == NULL)
return -ENOMEM;
state = iio_priv(indio_dev);
state->spi = spi;
state->vref_reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(state->vref_reg)) {
dev_err(&spi->dev, "Vref regulator not specified\n");
return PTR_ERR(state->vref_reg);
}
ret = regulator_enable(state->vref_reg);
if (ret) {
dev_err(&spi->dev, "Failed to enable vref regulator: %d\n",
ret);
return ret;
}
ret = regulator_get_voltage(state->vref_reg);
if (ret < 0) {
dev_err(&spi->dev, "Failed to read vref regulator: %d\n",
ret);
goto error_disable_reg;
}
state->vref_mv = ret / 1000;
spi_set_drvdata(spi, indio_dev);
id = spi_get_device_id(spi);
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &mcp4922_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = mcp4922_channels[id->driver_data];
indio_dev->num_channels = MCP4922_NUM_CHANNELS;
indio_dev->name = id->name;
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&spi->dev, "Failed to register iio device: %d\n",
ret);
goto error_disable_reg;
}
return 0;
error_disable_reg:
regulator_disable(state->vref_reg);
return ret;
}
static int mcp4922_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct mcp4922_state *state;
iio_device_unregister(indio_dev);
state = iio_priv(indio_dev);
regulator_disable(state->vref_reg);
return 0;
}
