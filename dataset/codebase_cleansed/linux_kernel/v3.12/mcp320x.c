static int mcp320x_adc_conversion(struct mcp320x *adc, u8 msg)
{
int ret;
adc->tx_buf = msg;
ret = spi_sync(adc->spi, &adc->msg);
if (ret < 0)
return ret;
return ((adc->rx_buf[0] & 0x3f) << 6) |
(adc->rx_buf[1] >> 2);
}
static int mcp320x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
struct mcp320x *adc = iio_priv(indio_dev);
int ret = -EINVAL;
mutex_lock(&adc->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (channel->differential)
ret = mcp320x_adc_conversion(adc,
MCP_START_BIT | channel->address);
else
ret = mcp320x_adc_conversion(adc,
MCP_START_BIT | MCP_SINGLE_ENDED |
channel->address);
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
*val2 = 12;
ret = IIO_VAL_FRACTIONAL_LOG2;
break;
default:
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
const struct mcp3208_chip_info *chip_info;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &mcp320x_info;
chip_info = &mcp3208_chip_infos[spi_get_device_id(spi)->driver_data];
indio_dev->channels = chip_info->channels;
indio_dev->num_channels = chip_info->num_channels;
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
