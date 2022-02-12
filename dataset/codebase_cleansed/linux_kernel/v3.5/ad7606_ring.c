static irqreturn_t ad7606_trigger_handler_th_bh(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct ad7606_state *st = iio_priv(pf->indio_dev);
gpio_set_value(st->pdata->gpio_convst, 1);
return IRQ_HANDLED;
}
static void ad7606_poll_bh_to_ring(struct work_struct *work_s)
{
struct ad7606_state *st = container_of(work_s, struct ad7606_state,
poll_work);
struct iio_dev *indio_dev = iio_priv_to_dev(st);
struct iio_buffer *ring = indio_dev->buffer;
s64 time_ns;
__u8 *buf;
int ret;
buf = kzalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (buf == NULL)
return;
if (gpio_is_valid(st->pdata->gpio_frstdata)) {
ret = st->bops->read_block(st->dev, 1, buf);
if (ret)
goto done;
if (!gpio_get_value(st->pdata->gpio_frstdata)) {
ad7606_reset(st);
goto done;
}
ret = st->bops->read_block(st->dev,
st->chip_info->num_channels - 1, buf + 2);
if (ret)
goto done;
} else {
ret = st->bops->read_block(st->dev,
st->chip_info->num_channels, buf);
if (ret)
goto done;
}
time_ns = iio_get_time_ns();
if (indio_dev->scan_timestamp)
*((s64 *)(buf + indio_dev->scan_bytes - sizeof(s64))) = time_ns;
ring->access->store_to(indio_dev->buffer, buf, time_ns);
done:
gpio_set_value(st->pdata->gpio_convst, 0);
iio_trigger_notify_done(indio_dev->trig);
kfree(buf);
}
int ad7606_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
struct ad7606_state *st = iio_priv(indio_dev);
int ret;
indio_dev->buffer = iio_kfifo_allocate(indio_dev);
if (!indio_dev->buffer) {
ret = -ENOMEM;
goto error_ret;
}
indio_dev->pollfunc = iio_alloc_pollfunc(&ad7606_trigger_handler_th_bh,
&ad7606_trigger_handler_th_bh,
0,
indio_dev,
"%s_consumer%d",
indio_dev->name,
indio_dev->id);
if (indio_dev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_deallocate_kfifo;
}
indio_dev->setup_ops = &ad7606_ring_setup_ops;
indio_dev->buffer->scan_timestamp = true;
INIT_WORK(&st->poll_work, &ad7606_poll_bh_to_ring);
indio_dev->modes |= INDIO_BUFFER_TRIGGERED;
return 0;
error_deallocate_kfifo:
iio_kfifo_free(indio_dev->buffer);
error_ret:
return ret;
}
void ad7606_ring_cleanup(struct iio_dev *indio_dev)
{
iio_dealloc_pollfunc(indio_dev->pollfunc);
iio_kfifo_free(indio_dev->buffer);
}
