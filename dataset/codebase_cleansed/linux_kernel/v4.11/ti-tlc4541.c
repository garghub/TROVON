static irqreturn_t tlc4541_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct tlc4541_state *st = iio_priv(indio_dev);
int ret;
ret = spi_sync(st->spi, &st->scan_single_msg);
if (ret < 0)
goto done;
iio_push_to_buffers_with_timestamp(indio_dev, st->rx_buf,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int tlc4541_get_range(struct tlc4541_state *st)
{
int vref;
vref = regulator_get_voltage(st->reg);
if (vref < 0)
return vref;
vref /= 1000;
return vref;
}
static int tlc4541_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret = 0;
struct tlc4541_state *st = iio_priv(indio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = spi_sync(st->spi, &st->scan_single_msg);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
*val = be16_to_cpu(st->rx_buf[0]);
*val = *val >> chan->scan_type.shift;
*val &= GENMASK(chan->scan_type.realbits - 1, 0);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = tlc4541_get_range(st);
if (ret < 0)
return ret;
*val = ret;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int tlc4541_probe(struct spi_device *spi)
{
struct tlc4541_state *st;
struct iio_dev *indio_dev;
const struct tlc4541_chip_info *info;
int ret;
int8_t device_init = 0;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
info = &tlc4541_chip_info[spi_get_device_id(spi)->driver_data];
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = info->channels;
indio_dev->num_channels = info->num_channels;
indio_dev->info = &tlc4541_info;
spi_write(spi, &device_init, 1);
st->scan_single_xfer[0].rx_buf = &st->rx_buf[0];
st->scan_single_xfer[0].len = 3;
st->scan_single_xfer[1].delay_usecs = 3;
st->scan_single_xfer[2].rx_buf = &st->rx_buf[0];
st->scan_single_xfer[2].len = 2;
spi_message_init_with_transfers(&st->scan_single_msg,
st->scan_single_xfer, 3);
st->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
ret = regulator_enable(st->reg);
if (ret)
return ret;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&tlc4541_trigger_handler, NULL);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_cleanup_buffer;
return 0;
error_cleanup_buffer:
iio_triggered_buffer_cleanup(indio_dev);
error_disable_reg:
regulator_disable(st->reg);
return ret;
}
static int tlc4541_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct tlc4541_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
regulator_disable(st->reg);
return 0;
}
