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
unsigned int scale_uv;
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
static int __devinit ad7887_probe(struct spi_device *spi)
{
struct ad7887_platform_data *pdata = spi->dev.platform_data;
struct ad7887_state *st;
int ret, voltage_uv = 0;
struct iio_dev *indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
voltage_uv = regulator_get_voltage(st->reg);
}
st->chip_info =
&ad7887_chip_info_tbl[spi_get_device_id(spi)->driver_data];
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad7887_info;
indio_dev->modes = INDIO_DIRECT_MODE;
st->tx_cmd_buf[0] = AD7887_CH_AIN0 | AD7887_PM_MODE4 |
((pdata && pdata->use_onchip_ref) ?
0 : AD7887_REF_DIS);
st->xfer[0].rx_buf = &st->data[0];
st->xfer[0].tx_buf = &st->tx_cmd_buf[0];
st->xfer[0].len = 2;
spi_message_init(&st->msg[AD7887_CH0]);
spi_message_add_tail(&st->xfer[0], &st->msg[AD7887_CH0]);
if (pdata && pdata->en_dual) {
st->tx_cmd_buf[0] |= AD7887_DUAL | AD7887_REF_DIS;
st->tx_cmd_buf[2] = AD7887_CH_AIN1 | AD7887_DUAL |
AD7887_REF_DIS | AD7887_PM_MODE4;
st->tx_cmd_buf[4] = AD7887_CH_AIN0 | AD7887_DUAL |
AD7887_REF_DIS | AD7887_PM_MODE4;
st->tx_cmd_buf[6] = AD7887_CH_AIN1 | AD7887_DUAL |
AD7887_REF_DIS | AD7887_PM_MODE4;
st->xfer[1].rx_buf = &st->data[0];
st->xfer[1].tx_buf = &st->tx_cmd_buf[2];
st->xfer[1].len = 2;
st->xfer[2].rx_buf = &st->data[2];
st->xfer[2].tx_buf = &st->tx_cmd_buf[4];
st->xfer[2].len = 2;
spi_message_init(&st->msg[AD7887_CH0_CH1]);
spi_message_add_tail(&st->xfer[1], &st->msg[AD7887_CH0_CH1]);
spi_message_add_tail(&st->xfer[2], &st->msg[AD7887_CH0_CH1]);
st->xfer[3].rx_buf = &st->data[0];
st->xfer[3].tx_buf = &st->tx_cmd_buf[6];
st->xfer[3].len = 2;
spi_message_init(&st->msg[AD7887_CH1]);
spi_message_add_tail(&st->xfer[3], &st->msg[AD7887_CH1]);
if (pdata && pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (voltage_uv)
st->int_vref_mv = voltage_uv / 1000;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
indio_dev->channels = st->chip_info->channel;
indio_dev->num_channels = 3;
} else {
if (pdata && pdata->vref_mv)
st->int_vref_mv = pdata->vref_mv;
else if (pdata && pdata->use_onchip_ref)
st->int_vref_mv = st->chip_info->int_vref_mv;
else
dev_warn(&spi->dev, "reference voltage unspecified\n");
indio_dev->channels = &st->chip_info->channel[1];
indio_dev->num_channels = 2;
}
ret = ad7887_register_ring_funcs_and_init(indio_dev);
if (ret)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unregister_ring;
return 0;
error_unregister_ring:
ad7887_ring_cleanup(indio_dev);
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
iio_device_free(indio_dev);
return ret;
}
static int ad7887_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7887_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
ad7887_ring_cleanup(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_free(indio_dev);
return 0;
}
