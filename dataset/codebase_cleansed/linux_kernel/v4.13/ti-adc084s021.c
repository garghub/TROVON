static int adc084s021_adc_conversion(struct adc084s021 *adc, void *data)
{
int n_words = (adc->spi_trans.len >> 1) - 1;
int ret, i = 0;
u16 *p = data;
ret = spi_sync(adc->spi, &adc->message);
if (ret < 0)
return ret;
for (; i < n_words; i++)
*(p + i) = adc->rx_buf[i + 1];
return ret;
}
static int adc084s021_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long mask)
{
struct adc084s021 *adc = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret < 0)
return ret;
ret = regulator_enable(adc->reg);
if (ret) {
iio_device_release_direct_mode(indio_dev);
return ret;
}
adc->tx_buf[0] = channel->channel << 3;
ret = adc084s021_adc_conversion(adc, val);
iio_device_release_direct_mode(indio_dev);
regulator_disable(adc->reg);
if (ret < 0)
return ret;
*val = be16_to_cpu(*val);
*val = (*val >> channel->scan_type.shift) & 0xff;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = regulator_enable(adc->reg);
if (ret)
return ret;
ret = regulator_get_voltage(adc->reg);
regulator_disable(adc->reg);
if (ret < 0)
return ret;
*val = ret / 1000;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static irqreturn_t adc084s021_buffer_trigger_handler(int irq, void *pollfunc)
{
struct iio_poll_func *pf = pollfunc;
struct iio_dev *indio_dev = pf->indio_dev;
struct adc084s021 *adc = iio_priv(indio_dev);
__be16 data[8] = {0};
mutex_lock(&adc->lock);
if (adc084s021_adc_conversion(adc, &data) < 0)
dev_err(&adc->spi->dev, "Failed to read data\n");
iio_push_to_buffers_with_timestamp(indio_dev, data,
iio_get_time_ns(indio_dev));
mutex_unlock(&adc->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int adc084s021_buffer_preenable(struct iio_dev *indio_dev)
{
struct adc084s021 *adc = iio_priv(indio_dev);
int scan_index;
int i = 0;
for_each_set_bit(scan_index, indio_dev->active_scan_mask,
indio_dev->masklength) {
const struct iio_chan_spec *channel =
&indio_dev->channels[scan_index];
adc->tx_buf[i++] = channel->channel << 3;
}
adc->spi_trans.len = 2 + (i * sizeof(__be16));
return regulator_enable(adc->reg);
}
static int adc084s021_buffer_postdisable(struct iio_dev *indio_dev)
{
struct adc084s021 *adc = iio_priv(indio_dev);
adc->spi_trans.len = 4;
return regulator_disable(adc->reg);
}
static int adc084s021_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct adc084s021 *adc;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adc));
if (!indio_dev) {
dev_err(&spi->dev, "Failed to allocate IIO device\n");
return -ENOMEM;
}
adc = iio_priv(indio_dev);
adc->spi = spi;
spi_set_drvdata(spi, indio_dev);
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &adc084s021_info;
indio_dev->channels = adc084s021_channels;
indio_dev->num_channels = ARRAY_SIZE(adc084s021_channels);
adc->spi_trans.tx_buf = adc->tx_buf;
adc->spi_trans.rx_buf = adc->rx_buf;
adc->spi_trans.len = 4;
spi_message_init_with_transfers(&adc->message, &adc->spi_trans, 1);
adc->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(adc->reg))
return PTR_ERR(adc->reg);
mutex_init(&adc->lock);
ret = devm_iio_triggered_buffer_setup(&spi->dev, indio_dev, NULL,
adc084s021_buffer_trigger_handler,
&adc084s021_buffer_setup_ops);
if (ret) {
dev_err(&spi->dev, "Failed to setup triggered buffer\n");
return ret;
}
return devm_iio_device_register(&spi->dev, indio_dev);
}
