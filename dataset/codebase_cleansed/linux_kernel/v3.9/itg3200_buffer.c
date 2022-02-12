static int itg3200_read_all_channels(struct i2c_client *i2c, __be16 *buf)
{
u8 tx = 0x80 | ITG3200_REG_TEMP_OUT_H;
struct i2c_msg msg[2] = {
{
.addr = i2c->addr,
.flags = i2c->flags,
.len = 1,
.buf = &tx,
},
{
.addr = i2c->addr,
.flags = i2c->flags | I2C_M_RD,
.len = ITG3200_SCAN_ELEMENTS * sizeof(s16),
.buf = (char *)&buf,
},
};
return i2c_transfer(i2c->adapter, msg, 2);
}
static irqreturn_t itg3200_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct itg3200 *st = iio_priv(indio_dev);
__be16 buf[ITG3200_SCAN_ELEMENTS + sizeof(s64)/sizeof(u16)];
int ret = itg3200_read_all_channels(st->i2c, buf);
if (ret < 0)
goto error_ret;
if (indio_dev->scan_timestamp)
memcpy(buf + indio_dev->scan_bytes - sizeof(s64),
&pf->timestamp, sizeof(pf->timestamp));
iio_push_to_buffers(indio_dev, (u8 *)buf);
iio_trigger_notify_done(indio_dev->trig);
error_ret:
return IRQ_HANDLED;
}
int itg3200_buffer_configure(struct iio_dev *indio_dev)
{
return iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
itg3200_trigger_handler, NULL);
}
void itg3200_buffer_unconfigure(struct iio_dev *indio_dev)
{
iio_triggered_buffer_cleanup(indio_dev);
}
static int itg3200_data_rdy_trigger_set_state(struct iio_trigger *trig,
bool state)
{
struct iio_dev *indio_dev = trig->private_data;
int ret;
u8 msc;
ret = itg3200_read_reg_8(indio_dev, ITG3200_REG_IRQ_CONFIG, &msc);
if (ret)
goto error_ret;
if (state)
msc |= ITG3200_IRQ_DATA_RDY_ENABLE;
else
msc &= ~ITG3200_IRQ_DATA_RDY_ENABLE;
ret = itg3200_write_reg_8(indio_dev, ITG3200_REG_IRQ_CONFIG, msc);
if (ret)
goto error_ret;
error_ret:
return ret;
}
int itg3200_probe_trigger(struct iio_dev *indio_dev)
{
int ret;
struct itg3200 *st = iio_priv(indio_dev);
st->trig = iio_trigger_alloc("%s-dev%d", indio_dev->name,
indio_dev->id);
if (!st->trig)
return -ENOMEM;
ret = request_irq(st->i2c->irq,
&iio_trigger_generic_data_rdy_poll,
IRQF_TRIGGER_RISING,
"itg3200_data_rdy",
st->trig);
if (ret)
goto error_free_trig;
st->trig->dev.parent = &st->i2c->dev;
st->trig->ops = &itg3200_trigger_ops;
st->trig->private_data = indio_dev;
ret = iio_trigger_register(st->trig);
if (ret)
goto error_free_irq;
indio_dev->trig = st->trig;
return 0;
error_free_irq:
free_irq(st->i2c->irq, st->trig);
error_free_trig:
iio_trigger_free(st->trig);
return ret;
}
void itg3200_remove_trigger(struct iio_dev *indio_dev)
{
struct itg3200 *st = iio_priv(indio_dev);
iio_trigger_unregister(st->trig);
free_irq(st->i2c->irq, st->trig);
iio_trigger_free(st->trig);
}
