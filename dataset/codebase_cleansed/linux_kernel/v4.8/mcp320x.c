static int mcp320x_channel_to_tx_data(int device_index,
const unsigned int channel, bool differential)
{
int start_bit = 1;
switch (device_index) {
case mcp3001:
case mcp3201:
case mcp3301:
return 0;
case mcp3002:
case mcp3202:
return ((start_bit << 4) | (!differential << 3) |
(channel << 2));
case mcp3004:
case mcp3204:
case mcp3008:
case mcp3208:
return ((start_bit << 6) | (!differential << 5) |
(channel << 2));
default:
return -EINVAL;
}
}
static int mcp320x_adc_conversion(struct mcp320x *adc, u8 channel,
bool differential, int device_index)
{
int ret;
adc->rx_buf[0] = 0;
adc->rx_buf[1] = 0;
adc->tx_buf = mcp320x_channel_to_tx_data(device_index,
channel, differential);
if (device_index != mcp3001 && device_index != mcp3201 && device_index != mcp3301) {
ret = spi_sync(adc->spi, &adc->msg);
if (ret < 0)
return ret;
} else {
ret = spi_read(adc->spi, &adc->rx_buf, sizeof(adc->rx_buf));
if (ret < 0)
return ret;
}
switch (device_index) {
case mcp3001:
return (adc->rx_buf[0] << 5 | adc->rx_buf[1] >> 3);
case mcp3002:
case mcp3004:
case mcp3008:
return (adc->rx_buf[0] << 2 | adc->rx_buf[1] >> 6);
case mcp3201:
return (adc->rx_buf[0] << 7 | adc->rx_buf[1] >> 1);
case mcp3202:
case mcp3204:
case mcp3208:
return (adc->rx_buf[0] << 4 | adc->rx_buf[1] >> 4);
case mcp3301:
return sign_extend32((adc->rx_buf[0] & 0x1f) << 8 | adc->rx_buf[1], 12);
default:
return -EINVAL;
}
}
static int mcp320x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
struct mcp320x *adc = iio_priv(indio_dev);
int ret = -EINVAL;
int device_index = 0;
mutex_lock(&adc->lock);
device_index = spi_get_device_id(adc->spi)->driver_data;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = mcp320x_adc_conversion(adc, channel->address,
channel->differential, device_index);
if (ret < 0)
goto out;
*val = ret;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(adc->reg);
if (ret < 0)
goto out;
*val = ret / 1000;
*val2 = adc->chip_info->resolution;
ret = IIO_VAL_FRACTIONAL_LOG2;
break;
}
out:
mutex_unlock(&adc->lock);
return ret;
}
static int mcp320x_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct mcp320x *adc;
const struct mcp320x_chip_info *chip_info;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &mcp320x_info;
chip_info = &mcp320x_chip_infos[spi_get_device_id(spi)->driver_data];
indio_dev->channels = chip_info->channels;
indio_dev->num_channels = chip_info->num_channels;
adc->chip_info = chip_info;
adc->transfer[0].tx_buf = &adc->tx_buf;
adc->transfer[0].len = sizeof(adc->tx_buf);
adc->transfer[1].rx_buf = adc->rx_buf;
adc->transfer[1].len = sizeof(adc->rx_buf);
spi_message_init_with_transfers(&adc->msg, adc->transfer,
ARRAY_SIZE(adc->transfer));
adc->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(adc->reg))
return PTR_ERR(adc->reg);
ret = regulator_enable(adc->reg);
if (ret < 0)
return ret;
mutex_init(&adc->lock);
ret = iio_device_register(indio_dev);
if (ret < 0)
goto reg_disable;
return 0;
reg_disable:
regulator_disable(adc->reg);
return ret;
}
static int mcp320x_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct mcp320x *adc = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(adc->reg);
return 0;
}
