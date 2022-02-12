static int ad7887_ring_preenable(struct iio_dev *indio_dev)
{
struct ad7887_state *st = iio_priv(indio_dev);
int ret;
ret = iio_sw_buffer_preenable(indio_dev);
if (ret < 0)
return ret;
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
s64 time_ns;
__u8 *buf;
int b_sent;
unsigned int bytes = bitmap_weight(indio_dev->active_scan_mask,
indio_dev->masklength) *
st->chip_info->channel[0].scan_type.storagebits / 8;
buf = kzalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (buf == NULL)
goto done;
b_sent = spi_sync(st->spi, st->ring_msg);
if (b_sent)
goto done;
time_ns = iio_get_time_ns();
memcpy(buf, st->data, bytes);
if (indio_dev->scan_timestamp)
memcpy(buf + indio_dev->scan_bytes - sizeof(s64),
&time_ns, sizeof(time_ns));
iio_push_to_buffer(indio_dev->buffer, buf);
done:
kfree(buf);
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
int ad7887_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
return iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
&ad7887_trigger_handler, &ad7887_ring_setup_ops);
}
void ad7887_ring_cleanup(struct iio_dev *indio_dev)
{
iio_triggered_buffer_cleanup(indio_dev);
}
