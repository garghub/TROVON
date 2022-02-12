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
static void devm_iio_triggered_buffer_clean(struct device *dev, void *res)
{
iio_triggered_buffer_cleanup(*(struct iio_dev **)res);
}
int devm_iio_triggered_buffer_setup(struct device *dev,
struct iio_dev *indio_dev,
irqreturn_t (*h)(int irq, void *p),
irqreturn_t (*thread)(int irq, void *p),
const struct iio_buffer_setup_ops *ops)
{
struct iio_dev **ptr;
int ret;
ptr = devres_alloc(devm_iio_triggered_buffer_clean, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return -ENOMEM;
*ptr = indio_dev;
ret = iio_triggered_buffer_setup(indio_dev, h, thread, ops);
if (!ret)
devres_add(dev, ptr);
else
devres_free(ptr);
return ret;
}
void devm_iio_triggered_buffer_cleanup(struct device *dev,
struct iio_dev *indio_dev)
{
int rc;
rc = devres_release(dev, devm_iio_triggered_buffer_clean,
devm_iio_device_match, indio_dev);
WARN_ON(rc);
}
