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
iio_push_to_buffers(indio_dev, buf);
done:
gpio_set_value(st->pdata->gpio_convst, 0);
iio_trigger_notify_done(indio_dev->trig);
kfree(buf);
}
int ad7606_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
struct ad7606_state *st = iio_priv(indio_dev);
INIT_WORK(&st->poll_work, &ad7606_poll_bh_to_ring);
return iio_triggered_buffer_setup(indio_dev,
&ad7606_trigger_handler_th_bh, &ad7606_trigger_handler_th_bh,
NULL);
}
void ad7606_ring_cleanup(struct iio_dev *indio_dev)
{
iio_triggered_buffer_cleanup(indio_dev);
}
