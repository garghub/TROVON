static int mcp4131_read(struct spi_device *spi, void *buf, size_t len)
{
struct spi_transfer t = {
.tx_buf = buf,
.rx_buf = buf,
.len = len,
};
struct spi_message m;
spi_message_init(&m);
spi_message_add_tail(&t, &m);
return spi_sync(spi, &m);
}
static int mcp4131_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int err;
struct mcp4131_data *data = iio_priv(indio_dev);
int address = chan->channel;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&data->lock);
data->buf[0] = (address << MCP4131_WIPER_SHIFT) | MCP4131_READ;
data->buf[1] = 0;
err = mcp4131_read(data->spi, data->buf, 2);
if (err) {
mutex_unlock(&data->lock);
return err;
}
if (!MCP4131_CMDERR(data->buf)) {
mutex_unlock(&data->lock);
return -EIO;
}
*val = MCP4131_RAW(data->buf);
mutex_unlock(&data->lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 1000 * data->cfg->kohms;
*val2 = data->cfg->max_pos;
return IIO_VAL_FRACTIONAL;
}
return -EINVAL;
}
static int mcp4131_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
int err;
struct mcp4131_data *data = iio_priv(indio_dev);
int address = chan->channel << MCP4131_WIPER_SHIFT;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val > data->cfg->max_pos || val < 0)
return -EINVAL;
break;
default:
return -EINVAL;
}
mutex_lock(&data->lock);
data->buf[0] = address << MCP4131_WIPER_SHIFT;
data->buf[0] |= MCP4131_WRITE | (val >> 8);
data->buf[1] = val & 0xFF;
err = spi_write(data->spi, data->buf, 2);
mutex_unlock(&data->lock);
return err;
}
static int mcp4131_probe(struct spi_device *spi)
{
int err;
struct device *dev = &spi->dev;
unsigned long devid = spi_get_device_id(spi)->driver_data;
struct mcp4131_data *data;
struct iio_dev *indio_dev;
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
data->spi = spi;
data->cfg = &mcp4131_cfg[devid];
mutex_init(&data->lock);
indio_dev->dev.parent = dev;
indio_dev->info = &mcp4131_info;
indio_dev->channels = mcp4131_channels;
indio_dev->num_channels = data->cfg->wipers;
indio_dev->name = spi_get_device_id(spi)->name;
err = devm_iio_device_register(dev, indio_dev);
if (err) {
dev_info(&spi->dev, "Unable to register %s\n", indio_dev->name);
return err;
}
return 0;
}
