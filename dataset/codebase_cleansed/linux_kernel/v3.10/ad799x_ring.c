static irqreturn_t ad799x_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad799x_state *st = iio_priv(indio_dev);
s64 time_ns;
int b_sent;
u8 cmd;
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
cmd, st->transfer_size, st->rx_buf);
if (b_sent < 0)
goto out;
time_ns = iio_get_time_ns();
if (indio_dev->scan_timestamp)
memcpy(st->rx_buf + indio_dev->scan_bytes - sizeof(s64),
&time_ns, sizeof(time_ns));
iio_push_to_buffers(indio_dev, st->rx_buf);
out:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
int ad799x_register_ring_funcs_and_init(struct iio_dev *indio_dev)
{
return iio_triggered_buffer_setup(indio_dev, NULL,
&ad799x_trigger_handler, NULL);
}
void ad799x_ring_cleanup(struct iio_dev *indio_dev)
{
iio_triggered_buffer_cleanup(indio_dev);
}
