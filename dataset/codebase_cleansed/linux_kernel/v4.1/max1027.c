static int max1027_read_single_value(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val)
{
int ret;
struct max1027_state *st = iio_priv(indio_dev);
if (iio_buffer_enabled(indio_dev)) {
dev_warn(&indio_dev->dev, "trigger mode already enabled");
return -EBUSY;
}
st->reg = MAX1027_SETUP_REG | MAX1027_REF_MODE2 | MAX1027_CKS_MODE2;
ret = spi_write(st->spi, &st->reg, 1);
if (ret < 0) {
dev_err(&indio_dev->dev,
"Failed to configure setup register\n");
return ret;
}
st->reg = MAX1027_CONV_REG | MAX1027_CHAN(chan->channel) |
MAX1027_NOSCAN | !!(chan->type == IIO_TEMP);
ret = spi_write(st->spi, &st->reg, 1);
if (ret < 0) {
dev_err(&indio_dev->dev,
"Failed to configure conversion register\n");
return ret;
}
mdelay(1);
ret = spi_read(st->spi, st->buffer, (chan->type == IIO_TEMP) ? 4 : 2);
if (ret < 0)
return ret;
*val = be16_to_cpu(st->buffer[0]);
return IIO_VAL_INT;
}
static int max1027_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret = 0;
struct max1027_state *st = iio_priv(indio_dev);
mutex_lock(&st->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = max1027_read_single_value(indio_dev, chan, val);
break;
case IIO_CHAN_INFO_SCALE:
switch (chan->type) {
case IIO_TEMP:
*val = 1;
*val2 = 8;
ret = IIO_VAL_FRACTIONAL;
break;
case IIO_VOLTAGE:
*val = 2500;
*val2 = 10;
ret = IIO_VAL_FRACTIONAL_LOG2;
break;
default:
ret = -EINVAL;
break;
}
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&st->lock);
return ret;
}
static int max1027_debugfs_reg_access(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
struct max1027_state *st = iio_priv(indio_dev);
u8 *val = (u8 *)st->buffer;
if (readval != NULL)
return -EINVAL;
*val = (u8)writeval;
return spi_write(st->spi, val, 1);
}
static int max1027_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
struct max1027_state *st = iio_priv(indio_dev);
if (st->trig != trig)
return -EINVAL;
return 0;
}
static int max1027_set_trigger_state(struct iio_trigger *trig, bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct max1027_state *st = iio_priv(indio_dev);
int ret;
if (state) {
st->reg = MAX1027_SETUP_REG | MAX1027_CKS_MODE0 |
MAX1027_REF_MODE2;
ret = spi_write(st->spi, &st->reg, 1);
if (ret < 0)
return ret;
st->reg = MAX1027_CONV_REG | MAX1027_CHAN(0) |
MAX1027_SCAN_N_M | MAX1027_TEMP;
ret = spi_write(st->spi, &st->reg, 1);
if (ret < 0)
return ret;
} else {
st->reg = MAX1027_SETUP_REG | MAX1027_CKS_MODE2 |
MAX1027_REF_MODE2;
ret = spi_write(st->spi, &st->reg, 1);
if (ret < 0)
return ret;
}
return 0;
}
static int max1027_validate_device(struct iio_trigger *trig,
struct iio_dev *indio_dev)
{
struct iio_dev *indio = iio_trigger_get_drvdata(trig);
if (indio != indio_dev)
return -EINVAL;
return 0;
}
static irqreturn_t max1027_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = (struct iio_poll_func *)private;
struct iio_dev *indio_dev = pf->indio_dev;
struct max1027_state *st = iio_priv(indio_dev);
pr_debug("%s(irq=%d, private=0x%p)\n", __func__, irq, private);
spi_read(st->spi, st->buffer, indio_dev->masklength * 2);
iio_push_to_buffers(indio_dev, st->buffer);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int max1027_probe(struct spi_device *spi)
{
int ret;
struct iio_dev *indio_dev;
struct max1027_state *st;
pr_debug("%s: probe(spi = 0x%p)\n", __func__, spi);
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL) {
pr_err("Can't allocate iio device\n");
return -ENOMEM;
}
spi_set_drvdata(spi, indio_dev);
st = iio_priv(indio_dev);
st->spi = spi;
st->info = &max1027_chip_info_tbl[spi_get_device_id(spi)->driver_data];
mutex_init(&st->lock);
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->dev.parent = &spi->dev;
indio_dev->info = &max1027_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->info->channels;
indio_dev->num_channels = st->info->num_channels;
indio_dev->available_scan_masks = st->info->available_scan_masks;
st->buffer = devm_kmalloc(&indio_dev->dev,
indio_dev->num_channels * 2,
GFP_KERNEL);
if (st->buffer == NULL) {
dev_err(&indio_dev->dev, "Can't allocate buffer\n");
return -ENOMEM;
}
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
&max1027_trigger_handler, NULL);
if (ret < 0) {
dev_err(&indio_dev->dev, "Failed to setup buffer\n");
return ret;
}
st->trig = devm_iio_trigger_alloc(&spi->dev, "%s-trigger",
indio_dev->name);
if (st->trig == NULL) {
ret = -ENOMEM;
dev_err(&indio_dev->dev, "Failed to allocate iio trigger\n");
goto fail_trigger_alloc;
}
st->trig->ops = &max1027_trigger_ops;
st->trig->dev.parent = &spi->dev;
iio_trigger_set_drvdata(st->trig, indio_dev);
iio_trigger_register(st->trig);
ret = devm_request_threaded_irq(&spi->dev, spi->irq,
iio_trigger_generic_data_rdy_poll,
NULL,
IRQF_TRIGGER_FALLING,
spi->dev.driver->name, st->trig);
if (ret < 0) {
dev_err(&indio_dev->dev, "Failed to allocate IRQ.\n");
goto fail_dev_register;
}
st->reg = MAX1027_AVG_REG;
ret = spi_write(st->spi, &st->reg, 1);
if (ret < 0) {
dev_err(&indio_dev->dev, "Failed to configure averaging register\n");
goto fail_dev_register;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&indio_dev->dev, "Failed to register iio device\n");
goto fail_dev_register;
}
return 0;
fail_dev_register:
fail_trigger_alloc:
iio_triggered_buffer_cleanup(indio_dev);
return ret;
}
static int max1027_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
pr_debug("%s: remove(spi = 0x%p)\n", __func__, spi);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
return 0;
}
