int iio_simple_dummy_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
return st->event_en;
}
int iio_simple_dummy_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
int state)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
switch (chan->type) {
case IIO_VOLTAGE:
switch (type) {
case IIO_EV_TYPE_THRESH:
if (dir == IIO_EV_DIR_RISING)
st->event_en = state;
else
return -EINVAL;
default:
return -EINVAL;
}
break;
case IIO_ACTIVITY:
switch (type) {
case IIO_EV_TYPE_THRESH:
st->event_en = state;
break;
default:
return -EINVAL;
}
case IIO_STEPS:
switch (type) {
case IIO_EV_TYPE_CHANGE:
st->event_en = state;
break;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
return 0;
}
int iio_simple_dummy_read_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int *val, int *val2)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
*val = st->event_val;
return IIO_VAL_INT;
}
int iio_simple_dummy_write_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum iio_event_type type,
enum iio_event_direction dir,
enum iio_event_info info,
int val, int val2)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
st->event_val = val;
return 0;
}
static irqreturn_t iio_simple_dummy_event_handler(int irq, void *private)
{
struct iio_dev *indio_dev = private;
struct iio_dummy_state *st = iio_priv(indio_dev);
dev_dbg(&indio_dev->dev, "id %x event %x\n",
st->regs->reg_id, st->regs->reg_data);
switch (st->regs->reg_data) {
case 0:
iio_push_event(indio_dev,
IIO_EVENT_CODE(IIO_VOLTAGE, 0, 0,
IIO_EV_DIR_RISING,
IIO_EV_TYPE_THRESH, 0, 0, 0),
iio_get_time_ns());
break;
case 1:
if (st->activity_running > st->event_val)
iio_push_event(indio_dev,
IIO_EVENT_CODE(IIO_ACTIVITY, 0,
IIO_MOD_RUNNING,
IIO_EV_DIR_RISING,
IIO_EV_TYPE_THRESH,
0, 0, 0),
iio_get_time_ns());
break;
case 2:
if (st->activity_walking < st->event_val)
iio_push_event(indio_dev,
IIO_EVENT_CODE(IIO_ACTIVITY, 0,
IIO_MOD_WALKING,
IIO_EV_DIR_FALLING,
IIO_EV_TYPE_THRESH,
0, 0, 0),
iio_get_time_ns());
break;
case 3:
iio_push_event(indio_dev,
IIO_EVENT_CODE(IIO_STEPS, 0, IIO_NO_MOD,
IIO_EV_DIR_NONE,
IIO_EV_TYPE_CHANGE, 0, 0, 0),
iio_get_time_ns());
break;
default:
break;
}
return IRQ_HANDLED;
}
int iio_simple_dummy_events_register(struct iio_dev *indio_dev)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
int ret;
st->event_irq = iio_dummy_evgen_get_irq();
if (st->event_irq < 0) {
ret = st->event_irq;
goto error_ret;
}
st->regs = iio_dummy_evgen_get_regs(st->event_irq);
ret = request_threaded_irq(st->event_irq,
NULL,
&iio_simple_dummy_event_handler,
IRQF_ONESHOT,
"iio_simple_event",
indio_dev);
if (ret < 0)
goto error_free_evgen;
return 0;
error_free_evgen:
iio_dummy_evgen_release_irq(st->event_irq);
error_ret:
return ret;
}
int iio_simple_dummy_events_unregister(struct iio_dev *indio_dev)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
free_irq(st->event_irq, indio_dev);
iio_dummy_evgen_release_irq(st->event_irq);
return 0;
}
