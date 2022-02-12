static int ad7923_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *active_scan_mask)
{
struct ad7923_state *st = iio_priv(indio_dev);
int i, cmd, len;
len = 0;
for_each_set_bit(i, active_scan_mask, AD7923_MAX_CHAN) {
cmd = AD7923_WRITE_CR | AD7923_CHANNEL_WRITE(i) |
AD7923_SEQUENCE_WRITE(AD7923_SEQUENCE_OFF) |
st->settings;
cmd <<= AD7923_SHIFT_REGISTER;
st->tx_buf[len++] = cpu_to_be16(cmd);
}
st->ring_xfer[0].tx_buf = &st->tx_buf[0];
st->ring_xfer[0].len = len;
st->ring_xfer[0].cs_change = 1;
spi_message_init(&st->ring_msg);
spi_message_add_tail(&st->ring_xfer[0], &st->ring_msg);
for (i = 0; i < len; i++) {
st->ring_xfer[i + 1].rx_buf = &st->rx_buf[i];
st->ring_xfer[i + 1].len = 2;
st->ring_xfer[i + 1].cs_change = 1;
spi_message_add_tail(&st->ring_xfer[i + 1], &st->ring_msg);
}
st->ring_xfer[i + 1].cs_change = 0;
return 0;
}
static irqreturn_t ad7923_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad7923_state *st = iio_priv(indio_dev);
int b_sent;
b_sent = spi_sync(st->spi, &st->ring_msg);
if (b_sent)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, st->rx_buf,
iio_get_time_ns());
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ad7923_scan_direct(struct ad7923_state *st, unsigned ch)
{
int ret, cmd;
cmd = AD7923_WRITE_CR | AD7923_CHANNEL_WRITE(ch) |
AD7923_SEQUENCE_WRITE(AD7923_SEQUENCE_OFF) |
st->settings;
cmd <<= AD7923_SHIFT_REGISTER;
st->tx_buf[0] = cpu_to_be16(cmd);
ret = spi_sync(st->spi, &st->scan_single_msg);
if (ret)
return ret;
return be16_to_cpu(st->rx_buf[0]);
}
static int ad7923_get_range(struct ad7923_state *st)
{
int vref;
vref = regulator_get_voltage(st->reg);
if (vref < 0)
return vref;
vref /= 1000;
if (!(st->settings & AD7923_RANGE))
vref *= 2;
return vref;
}
static int ad7923_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret;
struct ad7923_state *st = iio_priv(indio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else
ret = ad7923_scan_direct(st, chan->address);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
if (chan->address == EXTRACT(ret, 12, 4))
*val = EXTRACT(ret, 0, 12);
else
return -EIO;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = ad7923_get_range(st);
if (ret < 0)
return ret;
*val = ret;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int ad7923_probe(struct spi_device *spi)
{
struct ad7923_state *st;
struct iio_dev *indio_dev;
const struct ad7923_chip_info *info;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
st->settings = AD7923_CODING | AD7923_RANGE |
AD7923_PM_MODE_WRITE(AD7923_PM_MODE_OPS);
info = &ad7923_chip_info[spi_get_device_id(spi)->driver_data];
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = info->channels;
indio_dev->num_channels = info->num_channels;
indio_dev->info = &ad7923_info;
st->scan_single_xfer[0].tx_buf = &st->tx_buf[0];
st->scan_single_xfer[0].len = 2;
st->scan_single_xfer[0].cs_change = 1;
st->scan_single_xfer[1].rx_buf = &st->rx_buf[0];
st->scan_single_xfer[1].len = 2;
spi_message_init(&st->scan_single_msg);
spi_message_add_tail(&st->scan_single_xfer[0], &st->scan_single_msg);
spi_message_add_tail(&st->scan_single_xfer[1], &st->scan_single_msg);
st->reg = devm_regulator_get(&spi->dev, "refin");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
ret = regulator_enable(st->reg);
if (ret)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&ad7923_trigger_handler, NULL);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_ring;
return 0;
error_cleanup_ring:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
regulator_disable(st->reg);
return ret;
}
static int ad7923_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7923_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
regulator_disable(st->reg);
return 0;
}
