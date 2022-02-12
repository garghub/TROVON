static int max11100_read_single(struct iio_dev *indio_dev, int *val)
{
int ret;
struct max11100_state *state = iio_priv(indio_dev);
ret = spi_read(state->spi, state->buffer, sizeof(state->buffer));
if (ret) {
dev_err(&indio_dev->dev, "SPI transfer failed\n");
return ret;
}
if (state->buffer[0]) {
dev_err(&indio_dev->dev, "Invalid value: buffer[0] != 0\n");
return -EINVAL;
}
*val = (state->buffer[1] << 8) | state->buffer[2];
return 0;
}
static int max11100_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long info)
{
int ret, vref_uv;
struct max11100_state *state = iio_priv(indio_dev);
switch (info) {
case IIO_CHAN_INFO_RAW:
ret = max11100_read_single(indio_dev, val);
if (ret)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
vref_uv = regulator_get_voltage(state->vref_reg);
if (vref_uv < 0)
return -EINVAL;
*val = vref_uv / 1000;
*val2 = MAX11100_LSB_DIV;
return IIO_VAL_FRACTIONAL;
}
return -EINVAL;
}
static int max11100_probe(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev;
struct max11100_state *state;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*state));
if (!indio_dev)
return -ENOMEM;
spi_set_drvdata(spi, indio_dev);
state = iio_priv(indio_dev);
state->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->name = "max11100";
indio_dev->info = &max11100_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = max11100_channels;
indio_dev->num_channels = ARRAY_SIZE(max11100_channels);
state->vref_reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(state->vref_reg))
return PTR_ERR(state->vref_reg);
ret = regulator_enable(state->vref_reg);
if (ret)
return ret;
ret = iio_device_register(indio_dev);
if (ret)
goto disable_regulator;
return 0;
disable_regulator:
regulator_disable(state->vref_reg);
return ret;
}
static int max11100_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct max11100_state *state = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(state->vref_reg);
return 0;
}
