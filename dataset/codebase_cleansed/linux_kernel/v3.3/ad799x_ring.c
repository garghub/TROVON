static int ad799x_ring_preenable(struct iio_dev *indio_dev)
{
struct iio_buffer *ring = indio_dev->buffer;
struct ad799x_state *st = iio_priv(indio_dev);
if (st->id == ad7997 || st->id == ad7998)
ad7997_8_set_scan_mode(st, *indio_dev->active_scan_mask);
st->d_size = bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength) * 2;
if (ring->scan_timestamp) {
st->d_size += sizeof(s64);
if (st->d_size % sizeof(s64))
st->d_size += sizeof(s64) - (st->d_size % sizeof(s64));
}
if (indio_dev->buffer->access->set_bytes_per_datum)
indio_dev->buffer->access->
set_bytes_per_datum(indio_dev->buffer, st->d_size);
return 0;
}
static irqreturn_t ad799x_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad799x_state *st = iio_priv(indio_dev);
struct iio_buffer *ring = indio_dev->buffer;
s64 time_ns;
__u8 *rxbuf;
int b_sent;
u8 cmd;
rxbuf = kmalloc(st->d_size, GFP_KERNEL);
if (rxbuf == NULL)
goto out;
switch (st->id) {
case ad7991:
case ad7995:
case ad7999:
cmd = st->config |
(*indio_dev->active_scan_mask << AD799X_CHANNEL_SHIFT);
break;
case ad7992:
case ad7993:
case ad7994:
cmd = (*indio_dev->active_scan_mask << AD799X_CHANNEL_SHIFT) |
AD7998_CONV_RES_REG;
break;
case ad7997:
case ad7998:
cmd = AD7997_8_READ_SEQUENCE | AD7998_CONV_RES_REG;
break;
default:
cmd = 0;
}
b_sent = i2c_smbus_read_i2c_block_data(st->client,
cmd, bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength) * 2, rxbuf);
if (b_sent < 0)
goto done;
time_ns = iio_get_time_ns();
if (ring->scan_timestamp)
memcpy(rxbuf + st->d_size - sizeof(s64),
&time_ns, sizeof(time_ns));
ring->access->store_to(indio_dev->buffer, rxbuf, time_ns);
done:
kfree(rxbuf);
if (b_sent < 0)
return b_sent;
out:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
int ad799x_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
int ret = 0;
indio_dev->buffer = iio_sw_rb_allocate(indio_dev);
if (!indio_dev->buffer) {
ret = -ENOMEM;
goto error_ret;
}
indio_dev->buffer->access = &ring_sw_access_funcs;
indio_dev->pollfunc = iio_alloc_pollfunc(NULL,
&ad799x_trigger_handler,
IRQF_ONESHOT,
indio_dev,
"%s_consumer%d",
indio_dev->name,
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_deallocate_sw_rb;
}
indio_dev->setup_ops = &ad799x_buf_setup_ops;
indio_dev->buffer->scan_timestamp = true;
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
return 0;
error_deallocate_sw_rb:
iio_sw_rb_free(indio_dev->buffer);
error_ret:
return ret;
}
void ad799x_ring_cleanup(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_sw_rb_free(indio_dev->buffer);
}
