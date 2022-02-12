static irqreturn_t ad7476_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad7476_state *st = iio_priv(indio_dev);
s64 time_ns;
int b_sent;
b_sent = spi_sync(st->spi, &st->msg);
if (b_sent < 0)
goto done;
time_ns = iio_get_time_ns();
if (indio_dev->scan_timestamp)
((s64 *)st->data)[1] = time_ns;
iio_push_to_buffer(indio_dev->buffer, st->data);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static void ad7091_reset(struct ad7476_state *st)
{
spi_read(st->spi, st->data, 1);
}
static int ad7476_scan_direct(struct ad7476_state *st)
{
int ret;
ret = spi_sync(st->spi, &st->msg);
if (ret)
return ret;
return be16_to_cpup((__be16 *)st->data);
}
static int ad7476_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret;
struct ad7476_state *st = iio_priv(indio_dev);
int scale_uv;
switch (m) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
if (iio_buffer_enabled(indio_dev))
ret = -EBUSY;
else
ret = ad7476_scan_direct(st);
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
*val = (ret >> st->chip_info->channel[0].scan_type.shift) &
RES_MASK(st->chip_info->channel[0].scan_type.realbits);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (!st->chip_info->int_vref_uv) {
scale_uv = regulator_get_voltage(st->reg);
if (scale_uv < 0)
return scale_uv;
} else {
scale_uv = st->chip_info->int_vref_uv;
}
scale_uv >>= chan->scan_type.realbits;
*val = scale_uv / 1000;
*val2 = (scale_uv % 1000) * 1000;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int __devinit ad7476_probe(struct spi_device *spi)
{
struct ad7476_state *st;
struct iio_dev *indio_dev;
int ret;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
st->chip_info =
&ad7476_chip_info_tbl[spi_get_device_id(spi)->driver_data];
st->reg = regulator_get(&spi->dev, "vcc");
if (IS_ERR(st->reg)) {
ret = PTR_ERR(st->reg);
goto error_free_dev;
}
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->chip_info->channel;
indio_dev->num_channels = 2;
indio_dev->info = &ad7476_info;
st->xfer.rx_buf = &st->data;
st->xfer.len = st->chip_info->channel[0].scan_type.storagebits / 8;
spi_message_init(&st->msg);
spi_message_add_tail(&st->xfer, &st->msg);
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&ad7476_trigger_handler, NULL);
if (ret)
goto error_disable_reg;
if (st->chip_info->reset)
st->chip_info->reset(st);
ret = iio_device_register(indio_dev);
if (ret)
goto error_ring_unregister;
return 0;
error_ring_unregister:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
regulator_disable(st->reg);
error_put_reg:
regulator_put(st->reg);
error_free_dev:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int __devexit ad7476_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7476_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
regulator_disable(st->reg);
regulator_put(st->reg);
iio_device_free(indio_dev);
return 0;
}
