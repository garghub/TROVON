static irqreturn_t adis16240_data_rdy_trig_poll(int irq, void *trig)
{
iio_trigger_poll(trig, iio_get_time_ns());
return IRQ_HANDLED;
}
static int adis16240_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = trig->private_data;
dev_dbg(&indio_dev->dev, "%s (%d)\n", __func__, state);
return adis16240_set_irq(indio_dev, state);
}
int adis16240_probe_trigger(struct iio_dev *indio_dev)
{
int ret;
struct adis16240_state *st = iio_priv(indio_dev);
st->trig = iio_allocate_trigger("adis16240-dev%d", indio_dev->id);
if (st->trig == NULL) {
ret = -ENOMEM;
goto error_ret;
}
ret = request_irq(st->us->irq,
adis16240_data_rdy_trig_poll,
IRQF_TRIGGER_RISING,
"adis16240",
st->trig);
if (ret)
goto error_free_trig;
st->trig->dev.parent = &st->us->dev;
st->trig->owner = THIS_MODULE;
st->trig->private_data = indio_dev;
st->trig->set_trigger_state = &adis16240_data_rdy_trigger_set_state;
ret = iio_trigger_register(st->trig);
indio_dev->trig = st->trig;
if (ret)
goto error_free_irq;
return 0;
error_free_irq:
free_irq(st->us->irq, st->trig);
error_free_trig:
iio_free_trigger(st->trig);
error_ret:
return ret;
}
void adis16240_remove_trigger(struct iio_dev *indio_dev)
{
struct adis16240_state *st = iio_priv(indio_dev);
iio_trigger_unregister(st->trig);
free_irq(st->us->irq, st->trig);
iio_free_trigger(st->trig);
}
