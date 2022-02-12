int max1363_single_channel_from_ring(const long *mask, struct max1363_state *st)
{
struct iio_buffer *ring = iio_priv_to_dev(st)->buffer;
int count = 0, ret, index;
u8 *ring_data;
index = find_first_bit(mask, MAX1363_MAX_CHANNELS);
if (!(test_bit(index, st->current_mode->modemask))) {
ret = -EBUSY;
goto error_ret;
}
ring_data = kmalloc(ring->access->get_bytes_per_datum(ring),
GFP_KERNEL);
if (ring_data == NULL) {
ret = -ENOMEM;
goto error_ret;
}
ret = ring->access->read_last(ring, ring_data);
if (ret)
goto error_free_ring_data;
count = bitmap_weight(mask, index - 1);
if (st->chip_info->bits != 8)
ret = ((int)(ring_data[count*2 + 0] & 0x0F) << 8)
+ (int)(ring_data[count*2 + 1]);
else
ret = ring_data[count];
error_free_ring_data:
kfree(ring_data);
error_ret:
return ret;
}
static int max1363_ring_preenable(struct iio_dev *indio_dev)
{
struct max1363_state *st = iio_priv(indio_dev);
struct iio_buffer *ring = indio_dev->buffer;
size_t d_size = 0;
unsigned long numvals;
st->current_mode = max1363_match_mode(ring->scan_mask,
st->chip_info);
if (!st->current_mode)
return -EINVAL;
max1363_set_scan_mode(st);
numvals = bitmap_weight(st->current_mode->modemask,
indio_dev->masklength);
if (ring->access->set_bytes_per_datum) {
if (ring->scan_timestamp)
d_size += sizeof(s64);
if (st->chip_info->bits != 8)
d_size += numvals*2;
else
d_size += numvals;
if (ring->scan_timestamp && (d_size % 8))
d_size += 8 - (d_size % 8);
ring->access->set_bytes_per_datum(ring, d_size);
}
return 0;
}
static irqreturn_t max1363_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct max1363_state *st = iio_priv(indio_dev);
s64 time_ns;
__u8 *rxbuf;
int b_sent;
size_t d_size;
unsigned long numvals = bitmap_weight(st->current_mode->modemask,
MAX1363_MAX_CHANNELS);
if (st->chip_info->bits != 8)
d_size = numvals*2 + sizeof(s64);
else
d_size = numvals + sizeof(s64);
if (d_size % sizeof(s64))
d_size += sizeof(s64) - (d_size % sizeof(s64));
if (numvals == 0)
return IRQ_HANDLED;
rxbuf = kmalloc(d_size, GFP_KERNEL);
if (rxbuf == NULL)
return -ENOMEM;
if (st->chip_info->bits != 8)
b_sent = i2c_master_recv(st->client, rxbuf, numvals*2);
else
b_sent = i2c_master_recv(st->client, rxbuf, numvals);
if (b_sent < 0)
goto done;
time_ns = iio_get_time_ns();
memcpy(rxbuf + d_size - sizeof(s64), &time_ns, sizeof(time_ns));
indio_dev->buffer->access->store_to(indio_dev->buffer, rxbuf, time_ns);
done:
iio_trigger_notify_done(indio_dev->trig);
kfree(rxbuf);
return IRQ_HANDLED;
}
int max1363_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
struct max1363_state *st = iio_priv(indio_dev);
int ret = 0;
indio_dev->buffer = iio_sw_rb_allocate(indio_dev);
if (!indio_dev->buffer) {
ret = -ENOMEM;
goto error_ret;
}
indio_dev->pollfunc = iio_alloc_pollfunc(NULL,
&max1363_trigger_handler,
IRQF_ONESHOT,
indio_dev,
"%s_consumer%d",
st->client->name,
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_deallocate_sw_rb;
}
indio_dev->buffer->access = &ring_sw_access_funcs;
indio_dev->buffer->setup_ops = &max1363_ring_setup_ops;
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
return 0;
error_deallocate_sw_rb:
iio_sw_rb_free(indio_dev->buffer);
error_ret:
return ret;
}
void max1363_ring_cleanup(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_sw_rb_free(indio_dev->buffer);
}
