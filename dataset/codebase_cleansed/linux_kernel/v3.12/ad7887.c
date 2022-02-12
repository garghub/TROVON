static int ad7887_ring_preenable(struct iio_dev *indio_dev)
{
struct ad7887_state *st = iio_priv(indio_dev);
int ret;
ret = iio_sw_buffer_preenable(indio_dev);
if (ret < 0)
return ret;
switch (*indio_dev->active_scan_mask) {
case (1 << 0):
st->ring_msg = &st->msg[AD7887_CH0];
break;
case (1 << 1):
st->ring_msg = &st->msg[AD7887_CH1];
spi_sync(st->spi, st->ring_msg);
break;
case ((1 << 1) | (1 << 0)):
st->ring_msg = &st->msg[AD7887_CH0_CH1];
break;
}
return 0;
}
static int ad7887_ring_postdisable(struct iio_dev *indio_dev)
{
struct ad7887_state *st = iio_priv(indio_dev);
return spi_sync(st->spi, &st->msg[AD7887_CH0]);
}
static irqreturn_t ad7887_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad7887_state *st = iio_priv(indio_dev);
s64 time_ns;
int b_sent;
b_sent = spi_sync(st->spi, st->ring_msg);
if (b_sent)
goto done;
time_ns = iio_get_time_ns();
if (indio_dev->scan_timestamp)
memcpy(st->data + indio_dev->scan_bytes - sizeof(s64),
&time_ns, sizeof(time_ns));
iio_push_to_buffers(indio_dev, st->data);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int ad7887_scan_direct(struct ad7887_state *st, unsigned ch)
{
int ret = spi_sync(st->spi, &st->msg[ch]);
if (ret)
return ret;
return (st->data[(ch * 2)] << 8) | st->data[(ch * 2) + 1];
}
static int ad7887_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret;
struct ad7887_state *st = iio_priv(indio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else
ret = ad7887_scan_direct(st, chan->address);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
*val = ret >> chan->scan_type.shift;
*val &= RES_MASK(chan->scan_type.realbits);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (st->reg) {
*val = regulator_get_voltage(st->reg);
if (*val < 0)
return *val;
*val /= 1000;
} else {
*val = st->chip_info->int_vref_mv;
}
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int ad7887_probe(struct spi_device *spi)
{
struct ad7887_platform_data *pdata = spi->dev.platform_data;
struct ad7887_state *st;
struct iio_dev *indio_dev;
uint8_t mode;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
if (!pdata || !pdata->use_onchip_ref) {
st->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
ret = regulator_enable(st->reg);
if (ret)
return ret;
}
st->chip_info =
&ad7887_chip_info_tbl[spi_get_device_id(spi)->driver_data];
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad7887_info;
indio_dev->modes = INDIO_DIRECT_MODE;
mode = AD7887_PM_MODE4;
if (!pdata || !pdata->use_onchip_ref)
mode |= AD7887_REF_DIS;
if (pdata && pdata->en_dual)
mode |= AD7887_DUAL;
st->tx_cmd_buf[0] = AD7887_CH_AIN0 | mode;
st->xfer[0].rx_buf = &st->data[0];
st->xfer[0].tx_buf = &st->tx_cmd_buf[0];
st->xfer[0].len = 2;
spi_message_init(&st->msg[AD7887_CH0]);
spi_message_add_tail(&st->xfer[0], &st->msg[AD7887_CH0]);
if (pdata && pdata->en_dual) {
st->tx_cmd_buf[2] = AD7887_CH_AIN1 | mode;
st->xfer[1].rx_buf = &st->data[0];
st->xfer[1].tx_buf = &st->tx_cmd_buf[2];
st->xfer[1].len = 2;
st->xfer[2].rx_buf = &st->data[2];
st->xfer[2].tx_buf = &st->tx_cmd_buf[0];
st->xfer[2].len = 2;
spi_message_init(&st->msg[AD7887_CH0_CH1]);
spi_message_add_tail(&st->xfer[1], &st->msg[AD7887_CH0_CH1]);
spi_message_add_tail(&st->xfer[2], &st->msg[AD7887_CH0_CH1]);
st->xfer[3].rx_buf = &st->data[2];
st->xfer[3].tx_buf = &st->tx_cmd_buf[2];
st->xfer[3].len = 2;
spi_message_init(&st->msg[AD7887_CH1]);
spi_message_add_tail(&st->xfer[3], &st->msg[AD7887_CH1]);
indio_dev->channels = st->chip_info->channel;
indio_dev->num_channels = 3;
} else {
indio_dev->channels = &st->chip_info->channel[1];
indio_dev->num_channels = 2;
}
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
&ad7887_trigger_handler, &ad7887_ring_setup_ops);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unregister_ring;
return 0;
error_unregister_ring:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
if (st->reg)
regulator_disable(st->reg);
return ret;
}
static int ad7887_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7887_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (st->reg)
regulator_disable(st->reg);
return 0;
}
