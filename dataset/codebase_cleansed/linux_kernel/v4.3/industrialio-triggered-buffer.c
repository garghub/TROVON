int iio_triggered_buffer_setup(struct iio_dev *indio_dev,
irqreturn_t (*h)(int irq, void *p),
irqreturn_t (*thread)(int irq, void *p),
const struct iio_buffer_setup_ops *setup_ops)
{
struct iio_buffer *buffer;
int ret;
buffer = iio_kfifo_allocate();
if (!buffer) {
ret = -ENOMEM;
goto error_ret;
}
iio_device_attach_buffer(indio_dev, buffer);
indio_dev->pollfunc = iio_alloc_pollfunc(h,
thread,
IRQF_ONESHOT,
indio_dev,
"%s_consumer%d",
indio_dev->name,
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_kfifo_free;
}
if (setup_ops)
indio_dev->setup_ops = setup_ops;
else
indio_dev->setup_ops = &iio_triggered_buffer_setup_ops;
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
return 0;
error_kfifo_free:
iio_kfifo_free(indio_dev->buffer);
error_ret:
return ret;
}
void iio_triggered_buffer_cleanup(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_kfifo_free(indio_dev->buffer);
}
