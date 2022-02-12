static int as3935_read(struct as3935_state *st, unsigned int reg, int *val)
{
u8 cmd;
int ret;
cmd = (AS3935_READ_DATA | AS3935_ADDRESS(reg)) >> 8;
ret = spi_w8r8(st->spi, cmd);
if (ret < 0)
return ret;
*val = ret;
return 0;
}
static int as3935_write(struct as3935_state *st,
unsigned int reg,
unsigned int val)
{
u8 *buf = st->buf;
buf[0] = AS3935_ADDRESS(reg) >> 8;
buf[1] = val;
return spi_write(st->spi, buf, 2);
}
static ssize_t as3935_sensor_sensitivity_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct as3935_state *st = iio_priv(dev_to_iio_dev(dev));
int val, ret;
ret = as3935_read(st, AS3935_AFE_GAIN, &val);
if (ret)
return ret;
val = (val & AS3935_AFE_MASK) >> 1;
return sprintf(buf, "%d\n", val);
}
static ssize_t as3935_sensor_sensitivity_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct as3935_state *st = iio_priv(dev_to_iio_dev(dev));
unsigned long val;
int ret;
ret = kstrtoul((const char *) buf, 10, &val);
if (ret)
return -EINVAL;
if (val > AS3935_AFE_GAIN_MAX)
return -EINVAL;
as3935_write(st, AS3935_AFE_GAIN, val << 1);
return len;
}
static int as3935_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct as3935_state *st = iio_priv(indio_dev);
int ret;
switch (m) {
case IIO_CHAN_INFO_PROCESSED:
case IIO_CHAN_INFO_RAW:
*val2 = 0;
ret = as3935_read(st, AS3935_DATA, val);
if (ret)
return ret;
if (*val == AS3935_DATA_MASK)
return -EINVAL;
if (m == IIO_CHAN_INFO_RAW)
return IIO_VAL_INT;
if (m == IIO_CHAN_INFO_PROCESSED)
*val *= 1000;
break;
case IIO_CHAN_INFO_SCALE:
*val = 1000;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
}
static irqreturn_t as3935_trigger_handler(int irq, void *private)
{
struct iio_poll_func *pf = private;
struct iio_dev *indio_dev = pf->indio_dev;
struct as3935_state *st = iio_priv(indio_dev);
int val, ret;
ret = as3935_read(st, AS3935_DATA, &val);
if (ret)
goto err_read;
st->buffer[0] = val & AS3935_DATA_MASK;
iio_push_to_buffers_with_timestamp(indio_dev, &st->buffer,
iio_get_time_ns(indio_dev));
err_read:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static void as3935_event_work(struct work_struct *work)
{
struct as3935_state *st;
int val;
int ret;
st = container_of(work, struct as3935_state, work.work);
ret = as3935_read(st, AS3935_INT, &val);
if (ret) {
dev_warn(&st->spi->dev, "read error\n");
return;
}
val &= AS3935_INT_MASK;
switch (val) {
case AS3935_EVENT_INT:
iio_trigger_poll_chained(st->trig);
break;
case AS3935_NOISE_INT:
dev_warn(&st->spi->dev, "noise level is too high\n");
break;
}
}
static irqreturn_t as3935_interrupt_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct as3935_state *st = iio_priv(indio_dev);
schedule_delayed_work(&st->work, msecs_to_jiffies(3));
return IRQ_HANDLED;
}
static void calibrate_as3935(struct as3935_state *st)
{
as3935_write(st, AS3935_INT, BIT(5));
as3935_write(st, AS3935_CALIBRATE, 0x96);
as3935_write(st, AS3935_TUNE_CAP,
BIT(5) | (st->tune_cap / TUNE_CAP_DIV));
mdelay(2);
as3935_write(st, AS3935_TUNE_CAP, (st->tune_cap / TUNE_CAP_DIV));
}
static int as3935_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct as3935_state *st = iio_priv(indio_dev);
int val, ret;
mutex_lock(&st->lock);
ret = as3935_read(st, AS3935_AFE_GAIN, &val);
if (ret)
goto err_suspend;
val |= AS3935_AFE_PWR_BIT;
ret = as3935_write(st, AS3935_AFE_GAIN, val);
err_suspend:
mutex_unlock(&st->lock);
return ret;
}
static int as3935_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct as3935_state *st = iio_priv(indio_dev);
int val, ret;
mutex_lock(&st->lock);
ret = as3935_read(st, AS3935_AFE_GAIN, &val);
if (ret)
goto err_resume;
val &= ~AS3935_AFE_PWR_BIT;
ret = as3935_write(st, AS3935_AFE_GAIN, val);
calibrate_as3935(st);
err_resume:
mutex_unlock(&st->lock);
return ret;
}
static int as3935_probe(struct spi_device *spi)
{
struct iio_dev *indio_dev;
struct iio_trigger *trig;
struct as3935_state *st;
struct device_node *np = spi->dev.of_node;
int ret;
if (!spi->irq) {
dev_err(&spi->dev, "unable to get event interrupt\n");
return -EINVAL;
}
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
st = iio_priv(indio_dev);
st->spi = spi;
spi_set_drvdata(spi, indio_dev);
mutex_init(&st->lock);
INIT_DELAYED_WORK(&st->work, as3935_event_work);
ret = of_property_read_u32(np,
"ams,tuning-capacitor-pf", &st->tune_cap);
if (ret) {
st->tune_cap = 0;
dev_warn(&spi->dev,
"no tuning-capacitor-pf set, defaulting to %d",
st->tune_cap);
}
if (st->tune_cap > MAX_PF_CAP) {
dev_err(&spi->dev,
"wrong tuning-capacitor-pf setting of %d\n",
st->tune_cap);
return -EINVAL;
}
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->channels = as3935_channels;
indio_dev->num_channels = ARRAY_SIZE(as3935_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &as3935_info;
trig = devm_iio_trigger_alloc(&spi->dev, "%s-dev%d",
indio_dev->name, indio_dev->id);
if (!trig)
return -ENOMEM;
st->trig = trig;
trig->dev.parent = indio_dev->dev.parent;
iio_trigger_set_drvdata(trig, indio_dev);
trig->ops = &iio_interrupt_trigger_ops;
ret = iio_trigger_register(trig);
if (ret) {
dev_err(&spi->dev, "failed to register trigger\n");
return ret;
}
ret = iio_triggered_buffer_setup(indio_dev, iio_pollfunc_store_time,
&as3935_trigger_handler, NULL);
if (ret) {
dev_err(&spi->dev, "cannot setup iio trigger\n");
goto unregister_trigger;
}
calibrate_as3935(st);
ret = devm_request_irq(&spi->dev, spi->irq,
&as3935_interrupt_handler,
IRQF_TRIGGER_RISING,
dev_name(&spi->dev),
indio_dev);
if (ret) {
dev_err(&spi->dev, "unable to request irq\n");
goto unregister_buffer;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&spi->dev, "unable to register device\n");
goto unregister_buffer;
}
return 0;
unregister_buffer:
iio_triggered_buffer_cleanup(indio_dev);
unregister_trigger:
iio_trigger_unregister(st->trig);
return ret;
}
static int as3935_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct as3935_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
iio_trigger_unregister(st->trig);
return 0;
}
