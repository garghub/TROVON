static int adis16203_read_ring_data(struct iio_dev *indio_dev, u8 *rx)
{
struct spi_message msg;
struct adis16203_state *st = iio_priv(indio_dev);
struct spi_transfer xfers[ADIS16203_OUTPUTS + 1];
int ret;
int i;
mutex_lock(&st->buf_lock);
spi_message_init(&msg);
memset(xfers, 0, sizeof(xfers));
for (i = 0; i <= ADIS16203_OUTPUTS; i++) {
xfers[i].bits_per_word = 8;
xfers[i].cs_change = 1;
xfers[i].len = 2;
xfers[i].delay_usecs = 20;
xfers[i].tx_buf = st->tx + 2 * i;
if (i < 1)
st->tx[2 * i] = ADIS16203_READ_REG(ADIS16203_SUPPLY_OUT + 2 * i);
else
st->tx[2 * i] = ADIS16203_READ_REG(ADIS16203_SUPPLY_OUT + 2 * i + 6);
st->tx[2 * i + 1] = 0;
if (i >= 1)
xfers[i].rx_buf = rx + 2 * (i - 1);
spi_message_add_tail(&xfers[i], &msg);
}
ret = spi_sync(st->us, &msg);
if (ret)
dev_err(&st->us->dev, "problem when burst reading");
mutex_unlock(&st->buf_lock);
return ret;
}
static irqreturn_t adis16203_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct adis16203_state *st = iio_priv(indio_dev);
int i = 0;
s16 *data;
data = kmalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (data == NULL) {
dev_err(&st->us->dev, "memory alloc failed in ring bh");
goto done;
}
if (!bitmap_empty(indio_dev->active_scan_mask, indio_dev->masklength) &&
adis16203_read_ring_data(indio_dev, st->rx) >= 0)
for (; i < bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength); i++)
data[i] = be16_to_cpup((__be16 *)&(st->rx[i*2]));
if (indio_dev->scan_timestamp)
*((s64 *)(data + ((i + 3)/4)*4)) = pf->timestamp;
iio_push_to_buffer(indio_dev->buffer, (u8 *)data);
kfree(data);
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
void adis16203_unconfigure_ring(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_sw_rb_free(indio_dev->buffer);
}
int adis16203_configure_ring(struct iio_dev *indio_dev)
{
int ret = 0;
struct iio_buffer *ring;
ring = iio_sw_rb_allocate(indio_dev);
if (!ring) {
ret = -ENOMEM;
return ret;
}
indio_dev->buffer = ring;
ring->scan_timestamp = true;
indio_dev->setup_ops = &adis16203_ring_setup_ops;
indio_dev->pollfunc = iio_alloc_pollfunc(&iio_pollfunc_store_time,
&adis16203_trigger_handler,
IRQF_ONESHOT,
indio_dev,
"adis16203_consumer%d",
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_iio_sw_rb_free;
}
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
return 0;
error_iio_sw_rb_free:
iio_sw_rb_free(indio_dev->buffer);
return ret;
}
