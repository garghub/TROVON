static int ad7298_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *active_scan_mask)
{
struct ad7298_state *st = iio_priv(indio_dev);
int i, m;
unsigned short command;
int scan_count;
scan_count = bitmap_weight(active_scan_mask, indio_dev->masklength);
command = AD7298_WRITE | st->ext_ref;
for (i = 0, m = AD7298_CH(0); i < AD7298_MAX_CHAN; i++, m >>= 1)
if (test_bit(i, active_scan_mask))
command |= m;
st->tx_buf[0] = cpu_to_be16(command);
st->ring_xfer[0].tx_buf = &st->tx_buf[0];
st->ring_xfer[0].len = 2;
st->ring_xfer[0].cs_change = 1;
st->ring_xfer[1].tx_buf = &st->tx_buf[1];
st->ring_xfer[1].len = 2;
st->ring_xfer[1].cs_change = 1;
spi_message_init(&st->ring_msg);
spi_message_add_tail(&st->ring_xfer[0], &st->ring_msg);
spi_message_add_tail(&st->ring_xfer[1], &st->ring_msg);
for (i = 0; i < scan_count; i++) {
st->ring_xfer[i + 2].rx_buf = &st->rx_buf[i];
st->ring_xfer[i + 2].len = 2;
st->ring_xfer[i + 2].cs_change = 1;
spi_message_add_tail(&st->ring_xfer[i + 2], &st->ring_msg);
}
st->ring_xfer[i + 1].cs_change = 0;
return 0;
}
static irqreturn_t ad7298_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad7298_state *st = iio_priv(indio_dev);
int b_sent;
b_sent = spi_sync(st->spi, &st->ring_msg);
if (b_sent)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, st->rx_buf,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ad7298_scan_direct(struct ad7298_state *st, unsigned ch)
{
int ret;
st->tx_buf[0] = cpu_to_be16(AD7298_WRITE | st->ext_ref |
(AD7298_CH(0) >> ch));
ret = spi_sync(st->spi, &st->scan_single_msg);
if (ret)
return ret;
return be16_to_cpu(st->rx_buf[0]);
}
static int ad7298_scan_temp(struct ad7298_state *st, int *val)
{
int ret;
__be16 buf;
buf = cpu_to_be16(AD7298_WRITE | AD7298_TSENSE |
AD7298_TAVG | st->ext_ref);
ret = spi_write(st->spi, (u8 *)&buf, 2);
if (ret)
return ret;
buf = cpu_to_be16(0);
ret = spi_write(st->spi, (u8 *)&buf, 2);
if (ret)
return ret;
usleep_range(101, 1000);
ret = spi_read(st->spi, (u8 *)&buf, 2);
if (ret)
return ret;
*val = sign_extend32(be16_to_cpu(buf), 11);
return 0;
}
static int ad7298_get_ref_voltage(struct ad7298_state *st)
{
int vref;
if (st->ext_ref) {
vref = regulator_get_voltage(st->reg);
if (vref < 0)
return vref;
return vref / 1000;
} else {
return AD7298_INTREF_mV;
}
}
static int ad7298_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret;
struct ad7298_state *st = iio_priv(indio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (indio_dev->currentmode == INDIO_BUFFER_TRIGGERED) {
ret = -EBUSY;
} else {
if (chan->address == AD7298_CH_TEMP)
ret = ad7298_scan_temp(st, val);
else
ret = ad7298_scan_direct(st, chan->address);
}
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
if (chan->address != AD7298_CH_TEMP)
*val = ret & GENMASK(chan->scan_type.realbits - 1, 0);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_VOLTAGE:
*val = ad7298_get_ref_voltage(st);
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_TEMP:
*val = ad7298_get_ref_voltage(st);
*val2 = 10;
return IIO_VAL_FRACTIONAL;
default:
return -EINVAL;
}
case IIO_CHAN_INFO_OFFSET:
*val = 1093 - 2732500 / ad7298_get_ref_voltage(st);
return IIO_VAL_INT;
}
return -EINVAL;
}
static int ad7298_probe(struct spi_device *spi)
{
struct ad7298_platform_data *pdata = spi->dev.platform_data;
struct ad7298_state *st;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
if (pdata && pdata->ext_ref)
st->ext_ref = AD7298_EXTREF;
if (st->ext_ref) {
st->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
ret = regulator_enable(st->reg);
if (ret)
return ret;
}
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = ad7298_channels;
indio_dev->num_channels = ARRAY_SIZE(ad7298_channels);
indio_dev->info = &ad7298_info;
st->scan_single_xfer[0].tx_buf = &st->tx_buf[0];
st->scan_single_xfer[0].len = 2;
st->scan_single_xfer[0].cs_change = 1;
st->scan_single_xfer[1].tx_buf = &st->tx_buf[1];
st->scan_single_xfer[1].len = 2;
st->scan_single_xfer[1].cs_change = 1;
st->scan_single_xfer[2].rx_buf = &st->rx_buf[0];
st->scan_single_xfer[2].len = 2;
spi_message_init(&st->scan_single_msg);
spi_message_add_tail(&st->scan_single_xfer[0], &st->scan_single_msg);
spi_message_add_tail(&st->scan_single_xfer[1], &st->scan_single_msg);
spi_message_add_tail(&st->scan_single_xfer[2], &st->scan_single_msg);
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&ad7298_trigger_handler, NULL);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_ring;
return 0;
error_cleanup_ring:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
if (st->ext_ref)
regulator_disable(st->reg);
return ret;
}
static int ad7298_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7298_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (st->ext_ref)
regulator_disable(st->reg);
return 0;
}
