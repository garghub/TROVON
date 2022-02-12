static int ti_ads7950_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *active_scan_mask)
{
struct ti_ads7950_state *st = iio_priv(indio_dev);
int i, cmd, len;
len = 0;
for_each_set_bit(i, active_scan_mask, indio_dev->num_channels) {
cmd = TI_ADS7950_CR_WRITE | TI_ADS7950_CR_CHAN(i) | st->settings;
st->tx_buf[len++] = cpu_to_be16(cmd);
}
len += 2;
for (i = 0; i < len; i++) {
if ((i + 2) < len)
st->ring_xfer[i].tx_buf = &st->tx_buf[i];
if (i >= 2)
st->ring_xfer[i].rx_buf = &st->rx_buf[i - 2];
st->ring_xfer[i].len = 2;
st->ring_xfer[i].cs_change = 1;
}
st->ring_xfer[len - 1].cs_change = 0;
spi_message_init_with_transfers(&st->ring_msg, st->ring_xfer, len);
return 0;
}
static irqreturn_t ti_ads7950_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ti_ads7950_state *st = iio_priv(indio_dev);
int ret;
ret = spi_sync(st->spi, &st->ring_msg);
if (ret < 0)
goto out;
iio_push_to_buffers_with_timestamp(indio_dev, st->rx_buf,
iio_get_time_ns(indio_dev));
out:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ti_ads7950_scan_direct(struct ti_ads7950_state *st, unsigned int ch)
{
int ret, cmd;
cmd = TI_ADS7950_CR_WRITE | TI_ADS7950_CR_CHAN(ch) | st->settings;
st->tx_buf[0] = cpu_to_be16(cmd);
ret = spi_sync(st->spi, &st->scan_single_msg);
if (ret)
return ret;
return be16_to_cpu(st->rx_buf[0]);
}
static int ti_ads7950_get_range(struct ti_ads7950_state *st)
{
int vref;
if (st->vref_mv) {
vref = st->vref_mv;
} else {
vref = regulator_get_voltage(st->reg);
if (vref < 0)
return vref;
vref /= 1000;
}
if (st->settings & TI_ADS7950_CR_RANGE_5V)
vref *= 2;
return vref;
}
static int ti_ads7950_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long m)
{
struct ti_ads7950_state *st = iio_priv(indio_dev);
int ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret < 0)
return ret;
ret = ti_ads7950_scan_direct(st, chan->address);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
if (chan->address != TI_ADS7950_EXTRACT(ret, 12, 4))
return -EIO;
*val = TI_ADS7950_EXTRACT(ret, chan->scan_type.shift,
chan->scan_type.realbits);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = ti_ads7950_get_range(st);
if (ret < 0)
return ret;
*val = ret;
*val2 = (1 << chan->scan_type.realbits) - 1;
return IIO_VAL_FRACTIONAL;
}
return -EINVAL;
}
static int ti_ads7950_probe(struct spi_device *spi)
{
struct ti_ads7950_state *st;
struct iio_dev *indio_dev;
const struct ti_ads7950_chip_info *info;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
st->settings = TI_ADS7950_CR_MANUAL | TI_ADS7950_CR_RANGE_5V;
info = &ti_ads7950_chip_info[spi_get_device_id(spi)->driver_data];
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = info->channels;
indio_dev->num_channels = info->num_channels;
indio_dev->info = &ti_ads7950_info;
st->scan_single_xfer[0].tx_buf = &st->tx_buf[0];
st->scan_single_xfer[0].len = 2;
st->scan_single_xfer[0].cs_change = 1;
st->scan_single_xfer[1].tx_buf = &st->tx_buf[0];
st->scan_single_xfer[1].len = 2;
st->scan_single_xfer[1].cs_change = 1;
st->scan_single_xfer[2].rx_buf = &st->rx_buf[0];
st->scan_single_xfer[2].len = 2;
spi_message_init_with_transfers(&st->scan_single_msg,
st->scan_single_xfer, 3);
if (ACPI_COMPANION(&spi->dev))
st->vref_mv = TI_ADS7950_VA_MV_ACPI_DEFAULT;
st->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(st->reg)) {
dev_err(&spi->dev, "Failed get get regulator \"vref\"\n");
return PTR_ERR(st->reg);
}
ret = regulator_enable(st->reg);
if (ret) {
dev_err(&spi->dev, "Failed to enable regulator \"vref\"\n");
return ret;
}
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&ti_ads7950_trigger_handler, NULL);
if (ret) {
dev_err(&spi->dev, "Failed to setup triggered buffer\n");
goto error_disable_reg;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&spi->dev, "Failed to register iio device\n");
goto error_cleanup_ring;
}
return 0;
error_cleanup_ring:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
regulator_disable(st->reg);
return ret;
}
static int ti_ads7950_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ti_ads7950_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
regulator_disable(st->reg);
return 0;
}
