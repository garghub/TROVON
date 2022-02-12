static int max1118_read(struct spi_device *spi, int channel)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct max1118 *adc = iio_priv(indio_dev);
struct spi_transfer xfers[] = {
{
.len = 0,
.delay_usecs = 1,
.cs_change = 1,
},
{
.len = 0,
.delay_usecs = 8,
},
{
.rx_buf = &adc->data,
.len = 1,
},
};
int ret;
if (channel == 0)
ret = spi_sync_transfer(spi, xfers + 1, 2);
else
ret = spi_sync_transfer(spi, xfers, 3);
if (ret)
return ret;
return adc->data;
}
static int max1118_get_vref_mV(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct max1118 *adc = iio_priv(indio_dev);
const struct spi_device_id *id = spi_get_device_id(spi);
int vref_uV;
switch (id->driver_data) {
case max1117:
return 2048;
case max1119:
return 4096;
case max1118:
vref_uV = regulator_get_voltage(adc->reg);
if (vref_uV < 0)
return vref_uV;
return vref_uV / 1000;
}
return -ENODEV;
}
static int max1118_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct max1118 *adc = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&adc->lock);
*val = max1118_read(adc->spi, chan->channel);
mutex_unlock(&adc->lock);
if (*val < 0)
return *val;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = max1118_get_vref_mV(adc->spi);
if (*val < 0)
return *val;
*val2 = 8;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static irqreturn_t max1118_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct max1118 *adc = iio_priv(indio_dev);
u8 data[16] = { };
int scan_index;
int i = 0;
mutex_lock(&adc->lock);
for_each_set_bit(scan_index, indio_dev->active_scan_mask,
indio_dev->masklength) {
const struct iio_chan_spec *scan_chan =
&indio_dev->channels[scan_index];
int ret = max1118_read(adc->spi, scan_chan->channel);
if (ret < 0) {
dev_warn(&adc->spi->dev,
"failed to get conversion data\n");
goto out;
}
data[i] = ret;
i++;
}
iio_push_to_buffers_with_timestamp(indio_dev, data,
iio_get_time_ns(indio_dev));
out:
mutex_unlock(&adc->lock);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int max1118_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct max1118 *adc;
const struct spi_device_id *id = spi_get_device_id(spi);
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->spi = spi;
mutex_init(&adc->lock);
if (id->driver_data == max1118) {
adc->reg = devm_regulator_get(&spi->dev, "vref");
if (IS_ERR(adc->reg)) {
dev_err(&spi->dev, "failed to get vref regulator\n");
return PTR_ERR(adc->reg);
}
ret = regulator_enable(adc->reg);
if (ret)
return ret;
}
spi_set_drvdata(spi, indio_dev);
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &max1118_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = max1118_channels;
indio_dev->num_channels = ARRAY_SIZE(max1118_channels);
max1118_read(spi, 0);
ret = iio_triggered_buffer_setup(indio_dev, NULL,
max1118_trigger_handler, NULL);
if (ret)
goto err_reg_disable;
ret = iio_device_register(indio_dev);
if (ret)
goto err_buffer_cleanup;
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_reg_disable:
if (id->driver_data == max1118)
regulator_disable(adc->reg);
return ret;
}
static int max1118_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct max1118 *adc = iio_priv(indio_dev);
const struct spi_device_id *id = spi_get_device_id(spi);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (id->driver_data == max1118)
return regulator_disable(adc->reg);
return 0;
}
