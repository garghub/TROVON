static int adc108s102_update_scan_mode(struct iio_dev *indio_dev,
unsigned long const *active_scan_mask)
{
struct adc108s102_state *st = iio_priv(indio_dev);
unsigned int bit, cmds;
cmds = 0;
for_each_set_bit(bit, active_scan_mask, ADC108S102_MAX_CHANNELS)
st->tx_buf[cmds++] = cpu_to_be16(ADC108S102_CMD(bit));
st->tx_buf[cmds++] = 0x00;
st->ring_xfer.tx_buf = &st->tx_buf[0];
st->ring_xfer.rx_buf = &st->rx_buf[0];
st->ring_xfer.len = cmds * sizeof(st->tx_buf[0]);
spi_message_init_with_transfers(&st->ring_msg, &st->ring_xfer, 1);
return 0;
}
static irqreturn_t adc108s102_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct adc108s102_state *st = iio_priv(indio_dev);
int ret;
ret = spi_sync(st->spi, &st->ring_msg);
if (ret < 0)
goto out_notify;
iio_push_to_buffers_with_timestamp(indio_dev,
(u8 *)&st->rx_buf[1],
iio_get_time_ns(indio_dev));
out_notify:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int adc108s102_scan_direct(struct adc108s102_state *st, unsigned int ch)
{
int ret;
st->tx_buf[0] = cpu_to_be16(ADC108S102_CMD(ch));
ret = spi_sync(st->spi, &st->scan_single_msg);
if (ret)
return ret;
return be16_to_cpu(st->rx_buf[1]);
}
static int adc108s102_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long m)
{
struct adc108s102_state *st = iio_priv(indio_dev);
int ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = adc108s102_scan_direct(st, chan->address);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
*val = ADC108S102_RES_DATA(ret);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (chan->type != IIO_VOLTAGE)
break;
*val = st->va_millivolt;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
break;
}
return -EINVAL;
}
static int adc108s102_probe(struct spi_device *spi)
{
struct adc108s102_state *st;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
if (ACPI_COMPANION(&spi->dev)) {
st->va_millivolt = ADC108S102_VA_MV_ACPI_DEFAULT;
} else {
st->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
ret = regulator_enable(st->reg);
if (ret < 0) {
dev_err(&spi->dev, "Cannot enable vref regulator\n");
return ret;
}
ret = regulator_get_voltage(st->reg);
if (ret < 0) {
dev_err(&spi->dev, "vref get voltage failed\n");
return ret;
}
st->va_millivolt = ret / 1000;
}
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->name = spi->modalias;
indio_dev->dev.parent = &spi->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = adc108s102_channels;
indio_dev->num_channels = ARRAY_SIZE(adc108s102_channels);
indio_dev->info = &adc108s102_info;
st->scan_single_xfer.tx_buf = st->tx_buf;
st->scan_single_xfer.rx_buf = st->rx_buf;
st->scan_single_xfer.len = 2 * sizeof(st->tx_buf[0]);
spi_message_init_with_transfers(&st->scan_single_msg,
&st->scan_single_xfer, 1);
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&adc108s102_trigger_handler, NULL);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&spi->dev, "Failed to register IIO device\n");
goto error_cleanup_triggered_buffer;
}
return 0;
error_cleanup_triggered_buffer:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
regulator_disable(st->reg);
return ret;
}
static int adc108s102_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct adc108s102_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
regulator_disable(st->reg);
return 0;
}
