int iio_triggered_event_setup(struct iio_dev *indio_dev,
irqreturn_t (*h)(int irq, void *p),
irqreturn_t (*thread)(int irq, void *p))
{
indio_dev->pollfunc_event = iio_alloc_pollfunc(h,
thread,
IRQF_ONESHOT,
indio_dev,
"%s_consumer%d",
indio_dev->name,
indio_dev->id);
if (indio_dev->pollfunc_event == NULL)
return -ENOMEM;
indio_dev->modes |= INDIO_EVENT_TRIGGERED;
return 0;
}
void iio_triggered_event_cleanup(struct iio_dev *indio_dev)
{
indio_dev->modes &= ~INDIO_EVENT_TRIGGERED;
iio_dealloc_pollfunc(indio_dev->pollfunc_event);
}
