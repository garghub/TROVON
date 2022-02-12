static irqreturn_t iio_simple_dummy_trigger_h(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct iio_buffer *buffer = indio_dev->buffer;
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
j = find_next_bit(buffer->scan_mask,
indio_dev->masklength, j);
data[i] = fakedata[j];
len += 2;
}
}
if (indio_dev->scan_timestamp)
*(s64 *)((u8 *)data + ALIGN(len, sizeof(s64)))
= iio_get_time_ns();
buffer->access->store_to(buffer, (u8 *)data, pf->timestamp);
kfree(data);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
int iio_simple_dummy_configure_buffer(struct iio_dev *indio_dev)
{
int ret;
struct iio_buffer *buffer;
buffer = iio_kfifo_allocate(indio_dev);
if (buffer == NULL) {
ret = -ENOMEM;
goto error_ret;
}
indio_dev->buffer = buffer;
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
return 0;
error_free_buffer:
iio_kfifo_free(indio_dev->buffer);
error_ret:
return ret;
}
void iio_simple_dummy_unconfigure_buffer(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_kfifo_free(indio_dev->buffer);
}
