static int ad7476_scan_direct(struct ad7476_state *st)
{
int ret;
ret = spi_sync(st->spi, &st->msg);
if (ret)
return ret;
return (st->data[0] << 8) | st->data[1];
}
static int ad7476_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
int ret;
struct ad7476_state *st = iio_priv(indio_dev);
unsigned int scale_uv;
switch (m) {
case 0:
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
scale_uv = (st->int_vref_mv * 1000)
>> st->chip_info->channel[0].scan_type.realbits;
*val = scale_uv/1000;
*val2 = (scale_uv%1000)*1000;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
}
static int __devinit ad7476_probe(struct spi_device *spi)
{
struct ad7476_platform_data *pdata = spi->dev.platform_data;
struct ad7476_state *st;
struct iio_dev *indio_dev;
int ret, voltage_uv = 0;
indio_dev = iio_allocate_device(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
st->chip_info =
&ad7476_chip_info_tbl[spi_get_device_id(spi)->driver_data];
if (st->chip_info->int_vref_mv)
st->int_vref_mv = st->chip_info->int_vref_mv;
else if (pdata && pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (voltage_uv)
st->int_vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
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
ret = ad7476_register_ring_funcs_and_init(indio_dev);
if (ret)
goto error_disable_reg;
ret = iio_buffer_register(indio_dev,
st->chip_info->channel,
ARRAY_SIZE(st->chip_info->channel));
if (ret)
goto error_cleanup_ring;
ret = iio_device_register(indio_dev);
if (ret)
goto error_ring_unregister;
return 0;
error_ring_unregister:
iio_buffer_unregister(indio_dev);
error_cleanup_ring:
ad7476_ring_cleanup(indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
iio_free_device(indio_dev);
error_ret:
return ret;
}
static int ad7476_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7476_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_buffer_unregister(indio_dev);
ad7476_ring_cleanup(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_free_device(indio_dev);
return 0;
}
