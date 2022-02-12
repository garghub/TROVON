static int max5481_write_cmd(struct max5481_data *data, u8 cmd, u16 val)
{
struct spi_device *spi = data->spi;
data->msg[0] = cmd;
switch (cmd) {
case MAX5481_WRITE_WIPER:
data->msg[1] = val >> 2;
data->msg[2] = (val & 0x3) << 6;
return spi_write(spi, data->msg, 3);
case MAX5481_COPY_AB_TO_NV:
case MAX5481_COPY_NV_TO_AB:
return spi_write(spi, data->msg, 1);
default:
return -EIO;
}
}
static int max5481_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct max5481_data *data = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_SCALE)
return -EINVAL;
*val = 1000 * data->cfg->kohms;
*val2 = MAX5481_MAX_POS;
return IIO_VAL_FRACTIONAL;
}
static int max5481_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct max5481_data *data = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
if (val < 0 || val > MAX5481_MAX_POS)
return -EINVAL;
return max5481_write_cmd(data, MAX5481_WRITE_WIPER, val);
}
static int max5481_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct max5481_data *data;
const struct spi_device_id *id = spi_get_device_id(spi);
const struct of_device_id *match;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
dev_set_drvdata(&spi->dev, indio_dev);
data = iio_priv(indio_dev);
data->spi = spi;
match = of_match_device(of_match_ptr(max5481_match), &spi->dev);
if (match)
data->cfg = of_device_get_match_data(&spi->dev);
else
data->cfg = &max5481_cfg[id->driver_data];
indio_dev->name = id->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &max5481_info;
indio_dev->channels = max5481_channels;
indio_dev->num_channels = ARRAY_SIZE(max5481_channels);
ret = max5481_write_cmd(data, MAX5481_COPY_NV_TO_AB, 0);
if (ret < 0)
return ret;
return iio_device_register(indio_dev);
}
static int max5481_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = dev_get_drvdata(&spi->dev);
struct max5481_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
return max5481_write_cmd(data, MAX5481_COPY_AB_TO_NV, 0);
}
