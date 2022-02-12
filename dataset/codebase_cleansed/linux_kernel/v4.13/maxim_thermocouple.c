static int maxim_thermocouple_read(struct maxim_thermocouple_data *data,
struct iio_chan_spec const *chan, int *val)
{
unsigned int storage_bytes = data->chip->read_size;
unsigned int shift = chan->scan_type.shift + (chan->address * 8);
__be16 buf16;
__be32 buf32;
int ret;
switch (storage_bytes) {
case 2:
ret = spi_read(data->spi, (void *)&buf16, storage_bytes);
*val = be16_to_cpu(buf16);
break;
case 4:
ret = spi_read(data->spi, (void *)&buf32, storage_bytes);
*val = be32_to_cpu(buf32);
break;
default:
ret = -EINVAL;
}
if (ret)
return ret;
if (*val & data->chip->status_bit)
return -EINVAL;
*val = sign_extend32(*val >> shift, chan->scan_type.realbits - 1);
return 0;
}
static irqreturn_t maxim_thermocouple_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *indio_dev = pf->indio_dev;
struct maxim_thermocouple_data *data = iio_priv(indio_dev);
int ret;
ret = spi_read(data->spi, data->buffer, data->chip->read_size);
if (!ret) {
iio_push_to_buffers_with_timestamp(indio_dev, data->buffer,
iio_get_time_ns(indio_dev));
}
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int maxim_thermocouple_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct maxim_thermocouple_data *data = iio_priv(indio_dev);
int ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = maxim_thermocouple_read(data, chan, val);
iio_device_release_direct_mode(indio_dev);
if (!ret)
return IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
switch (chan->channel2) {
case IIO_MOD_TEMP_AMBIENT:
*val = 62;
*val2 = 500000;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
default:
*val = 250;
ret = IIO_VAL_INT;
};
break;
}
return ret;
}
static int maxim_thermocouple_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
struct iio_dev *indio_dev;
struct maxim_thermocouple_data *data;
const struct maxim_thermocouple_chip *chip =
&maxim_thermocouple_chips[id->driver_data];
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
indio_dev->info = &maxim_thermocouple_info;
indio_dev->name = MAXIM_THERMOCOUPLE_DRV_NAME;
indio_dev->channels = chip->channels;
indio_dev->available_scan_masks = chip->scan_masks;
indio_dev->num_channels = chip->num_channels;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->dev.parent = &spi->dev;
data = iio_priv(indio_dev);
data->spi = spi;
data->chip = chip;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
maxim_thermocouple_trigger_handler, NULL);
if (ret)
return ret;
ret = iio_device_register(indio_dev);
if (ret)
goto error_unreg_buffer;
return 0;
error_unreg_buffer:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int maxim_thermocouple_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return 0;
}
