static int ad7887_ring_preenable(struct iio_dev *indio_dev)
{
struct ad7887_state *st = iio_priv(indio_dev);
struct iio_buffer *ring = indio_dev->buffer;
st->d_size = bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength) *
st->chip_info->channel[0].scan_type.storagebits / 8;
if (ring->scan_timestamp) {
st->d_size += sizeof(s64);
if (st->d_size % sizeof(s64))
st->d_size += sizeof(s64) - (st->d_size % sizeof(s64));
}
if (indio_dev->buffer->access->set_bytes_per_datum)
indio_dev->buffer->access->
set_bytes_per_datum(indio_dev->buffer, st->d_size);
switch (*indio_dev->active_scan_mask) {
case (1 << 0):
st->ring_msg = &st->msg[AD7887_CH0];
break;
case (1 << 1):
st->ring_msg = &st->msg[AD7887_CH1];
spi_sync(st->spi, st->ring_msg);
break;
case ((1 << 1) | (1 << 0)):
st->ring_msg = &st->msg[AD7887_CH0_CH1];
break;
}
return 0;
}
static int ad7887_ring_postdisable(struct iio_dev *indio_dev)
{
struct ad7887_state *st = iio_priv(indio_dev);
return spi_sync(st->spi, &st->msg[AD7887_CH0]);
}
static irqreturn_t ad7887_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad7887_state *st = iio_priv(indio_dev);
struct iio_buffer *ring = indio_dev->buffer;
s64 time_ns;
__u8 *buf;
int b_sent;
unsigned int bytes = bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength) *
st->chip_info->channel[0].scan_type.storagebits / 8;
buf = kzalloc(st->d_size, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
b_sent = spi_sync(st->spi, st->ring_msg);
if (b_sent)
goto done;
time_ns = iio_get_time_ns();
memcpy(buf, st->data, bytes);
if (ring->scan_timestamp)
memcpy(buf + st->d_size - sizeof(s64),
&time_ns, sizeof(time_ns));
indio_dev->buffer->access->store_to(indio_dev->buffer, buf, time_ns);
done:
kfree(buf);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
int ad7887_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
int ret;
indio_dev->buffer = iio_sw_rb_allocate(indio_dev);
if (!indio_dev->buffer) {
ret = -ENOMEM;
goto error_ret;
}
indio_dev->buffer->access = &ring_sw_access_funcs;
indio_dev->pollfunc = iio_alloc_pollfunc(&iio_pollfunc_store_time,
&ad7887_trigger_handler,
IRQF_ONESHOT,
indio_dev,
"ad7887_consumer%d",
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_deallocate_sw_rb;
}
indio_dev->setup_ops = &ad7887_ring_setup_ops;
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
return 0;
error_deallocate_sw_rb:
iio_sw_rb_free(indio_dev->buffer);
error_ret:
return ret;
}
void ad7887_ring_cleanup(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_sw_rb_free(indio_dev->buffer);
}
