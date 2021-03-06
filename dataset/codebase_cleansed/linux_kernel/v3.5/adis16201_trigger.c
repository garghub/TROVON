static int adis16201_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = trig->private_data;
dev_dbg(&indio_dev->dev, "%s (%d)\n", __func__, state);
return adis16201_set_irq(indio_dev, state);
}
int adis16201_probe_trigger(struct iio_dev *indio_dev)
{
int ret;
struct adis16201_state *st = iio_priv(indio_dev);
st->trig = iio_trigger_alloc("adis16201-dev%d", indio_dev->id);
if (st->trig == NULL) {
ret = -ENOMEM;
goto error_ret;
}
ret = request_irq(st->us->irq,
&iio_trigger_generic_data_rdy_poll,
IRQF_TRIGGER_RISING,
"adis16201",
st->trig);
if (ret)
goto error_free_trig;
st->trig->dev.parent = &st->us->dev;
st->trig->ops = &adis16201_trigger_ops;
st->trig->private_data = indio_dev;
ret = iio_trigger_register(st->trig);
indio_dev->trig = st->trig;
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
void adis16201_remove_trigger(struct iio_dev *indio_dev)
{
struct adis16201_state *state = iio_priv(indio_dev);
iio_trigger_unregister(state->trig);
free_irq(state->us->irq, state->trig);
iio_trigger_free(state->trig);
}
