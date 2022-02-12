static int adis_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct adis *adis = trig->private_data;
return adis_enable_irq(adis, state);
}
int adis_probe_trigger(struct adis *adis, struct iio_dev *indio_dev)
{
int ret;
adis->trig = iio_trigger_alloc("%s-dev%d", indio_dev->name,
indio_dev->id);
if (adis->trig == NULL)
return -ENOMEM;
ret = request_irq(adis->spi->irq,
&iio_trigger_generic_data_rdy_poll,
IRQF_TRIGGER_RISING,
indio_dev->name,
adis->trig);
if (ret)
goto error_free_trig;
adis->trig->dev.parent = &adis->spi->dev;
adis->trig->ops = &adis_trigger_ops;
adis->trig->private_data = adis;
ret = iio_trigger_register(adis->trig);
indio_dev->trig = adis->trig;
if (ret)
goto error_free_irq;
return 0;
error_free_irq:
free_irq(adis->spi->irq, adis->trig);
error_free_trig:
iio_trigger_free(adis->trig);
return ret;
}
void adis_remove_trigger(struct adis *adis)
{
iio_trigger_unregister(adis->trig);
free_irq(adis->spi->irq, adis->trig);
iio_trigger_free(adis->trig);
}
