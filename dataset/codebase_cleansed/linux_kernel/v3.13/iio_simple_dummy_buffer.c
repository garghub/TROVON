static irqreturn_t iio_simple_dummy_trigger_h(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
int len = 0;
u16 *data;
data = kmalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (data == NULL)
goto done;
if (!bitmap_empty(indio_dev->active_scan_mask, indio_dev->masklength)) {
int i, j;
for (i = 0, j = 0;
i < bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength);
i++, j++) {
j = find_next_bit(indio_dev->active_scan_mask,
indio_dev->masklength, j);
data[i] = fakedata[j];
len += 2;
}
}
iio_push_to_buffers_with_timestamp(indio_dev, data, iio_get_time_ns());
kfree(data);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
int iio_simple_dummy_configure_buffer(struct iio_dev *indio_dev,
const struct iio_chan_spec *channels, unsigned int num_channels)
{
int ret;
struct iio_buffer *buffer;
buffer = iio_kfifo_allocate(indio_dev);
if (buffer == NULL) {
ret = -ENOMEM;
goto error_ret;
}
iio_device_attach_buffer(indio_dev, buffer);
buffer->scan_timestamp = true;
indio_dev->setup_ops = &iio_simple_dummy_buffer_setup_ops;
indio_dev->pollfunc = iio_alloc_pollfunc(NULL,
&iio_simple_dummy_trigger_h,
IRQF_ONESHOT,
indio_dev,
"iio_simple_dummy_consumer%d",
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_free_buffer;
}
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
ret = iio_buffer_register(indio_dev, channels, num_channels);
if (ret)
goto error_dealloc_pollfunc;
return 0;
error_dealloc_pollfunc:
iio_dealloc_pollfunc(indio_dev->pollfunc);
error_free_buffer:
iio_kfifo_free(indio_dev->buffer);
error_ret:
return ret;
}
void iio_simple_dummy_unconfigure_buffer(struct iio_dev *indio_dev)
{
iio_buffer_unregister(indio_dev);
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_kfifo_free(indio_dev->buffer);
}
