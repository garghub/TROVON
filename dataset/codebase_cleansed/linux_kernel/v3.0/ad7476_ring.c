int ad7476_scan_from_ring(struct ad7476_state *st)
{
struct iio_ring_buffer *ring = st->indio_dev->ring;
int ret;
u8 *ring_data;
ring_data = kmalloc(ring->access->get_bytes_per_datum(ring),
GFP_KERNEL);
if (ring_data == NULL) {
ret = -ENOMEM;
goto error_ret;
}
ret = ring->access->read_last(ring, ring_data);
if (ret)
goto error_free_ring_data;
ret = (ring_data[0] << 8) | ring_data[1];
error_free_ring_data:
kfree(ring_data);
error_ret:
return ret;
}
static int ad7476_ring_preenable(struct iio_dev *indio_dev)
{
struct ad7476_state *st = indio_dev->dev_data;
struct iio_ring_buffer *ring = indio_dev->ring;
st->d_size = ring->scan_count *
st->chip_info->channel[0].scan_type.storagebits / 8;
if (ring->scan_timestamp) {
st->d_size += sizeof(s64);
if (st->d_size % sizeof(s64))
st->d_size += sizeof(s64) - (st->d_size % sizeof(s64));
}
if (indio_dev->ring->access->set_bytes_per_datum)
indio_dev->ring->access->set_bytes_per_datum(indio_dev->ring,
st->d_size);
return 0;
}
static irqreturn_t ad7476_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->private_data;
struct ad7476_state *st = iio_dev_get_devdata(indio_dev);
s64 time_ns;
__u8 *rxbuf;
int b_sent;
rxbuf = kzalloc(st->d_size, GFP_KERNEL);
if (rxbuf == NULL)
return -ENOMEM;
b_sent = spi_read(st->spi, rxbuf,
st->chip_info->channel[0].scan_type.storagebits / 8);
if (b_sent < 0)
goto done;
time_ns = iio_get_time_ns();
if (indio_dev->ring->scan_timestamp)
memcpy(rxbuf + st->d_size - sizeof(s64),
&time_ns, sizeof(time_ns));
indio_dev->ring->access->store_to(indio_dev->ring, rxbuf, time_ns);
done:
iio_trigger_notify_done(indio_dev->trig);
kfree(rxbuf);
return IRQ_HANDLED;
}
int ad7476_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
struct ad7476_state *st = indio_dev->dev_data;
int ret = 0;
indio_dev->ring = iio_sw_rb_allocate(indio_dev);
if (!indio_dev->ring) {
ret = -ENOMEM;
goto error_ret;
}
indio_dev->ring->access = &ring_sw_access_funcs;
indio_dev->pollfunc
= iio_alloc_pollfunc(NULL,
&ad7476_trigger_handler,
IRQF_ONESHOT,
indio_dev,
"%s_consumer%d",
spi_get_device_id(st->spi)->name,
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_deallocate_sw_rb;
}
indio_dev->ring->setup_ops = &ad7476_ring_setup_ops;
indio_dev->ring->scan_timestamp = true;
indio_dev->modes |= INDIO_RING_TRIGGERED;
return 0;
error_deallocate_sw_rb:
iio_sw_rb_free(indio_dev->ring);
error_ret:
return ret;
}
void ad7476_ring_cleanup(struct iio_dev *indio_dev)
{
if (indio_dev->trig) {
iio_put_trigger(indio_dev->trig);
iio_trigger_dettach_poll_func(indio_dev->trig,
indio_dev->pollfunc);
}
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_sw_rb_free(indio_dev->ring);
}
