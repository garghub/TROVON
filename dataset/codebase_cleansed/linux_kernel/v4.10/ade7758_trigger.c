static irqreturn_t ade7758_data_rdy_trig_poll(int irq, void *private)
{
disable_irq_nosync(irq);
iio_trigger_poll(private);
return IRQ_HANDLED;
}
static int ade7758_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
dev_dbg(&indio_dev->dev, "%s (%d)\n", __func__, state);
return ade7758_set_irq(&indio_dev->dev, state);
}
static int ade7758_trig_try_reen(struct iio_trigger *trig)
{
struct iio_dev *indio_dev = iio_trigger_get_drvdata(trig);
struct ade7758_state *st = iio_priv(indio_dev);
enable_irq(st->us->irq);
return 0;
}
int ade7758_probe_trigger(struct iio_dev *indio_dev)
{
struct ade7758_state *st = iio_priv(indio_dev);
int ret;
st->trig = iio_trigger_alloc("%s-dev%d",
spi_get_device_id(st->us)->name,
indio_dev->id);
if (!st->trig) {
ret = -ENOMEM;
goto error_ret;
}
ret = request_irq(st->us->irq,
ade7758_data_rdy_trig_poll,
IRQF_TRIGGER_LOW,
spi_get_device_id(st->us)->name,
st->trig);
if (ret)
goto error_free_trig;
st->trig->dev.parent = &st->us->dev;
st->trig->ops = &ade7758_trigger_ops;
iio_trigger_set_drvdata(st->trig, indio_dev);
ret = iio_trigger_register(st->trig);
indio_dev->trig = iio_trigger_get(st->trig);
if (ret)
goto error_free_irq;
return 0;
error_free_irq:
free_irq(st->us->irq, st->trig);
error_free_trig:
iio_trigger_free(st->trig);
error_ret:
return ret;
}
void ade7758_remove_trigger(struct iio_dev *indio_dev)
{
struct ade7758_state *st = iio_priv(indio_dev);
iio_trigger_unregister(st->trig);
free_irq(st->us->irq, st->trig);
iio_trigger_free(st->trig);
}
