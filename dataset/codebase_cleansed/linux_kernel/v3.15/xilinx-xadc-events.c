static const struct iio_chan_spec *xadc_event_to_channel(
struct iio_dev *indio_dev, unsigned int event)
{
switch (event) {
case XADC_THRESHOLD_OT_MAX:
case XADC_THRESHOLD_TEMP_MAX:
return &indio_dev->channels[0];
case XADC_THRESHOLD_VCCINT_MAX:
case XADC_THRESHOLD_VCCAUX_MAX:
return &indio_dev->channels[event];
default:
return &indio_dev->channels[event-1];
}
}
static void xadc_handle_event(struct iio_dev *indio_dev, unsigned int event)
{
const struct iio_chan_spec *chan;
unsigned int offset;
if (event == 0)
return;
if (event < 4)
offset = event;
else
offset = event + 4;
chan = xadc_event_to_channel(indio_dev, event);
if (chan->type == IIO_TEMP) {
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(chan->type, chan->channel,
IIO_EV_TYPE_THRESH, IIO_EV_DIR_RISING),
iio_get_time_ns());
} else {
iio_push_event(indio_dev,
IIO_UNMOD_EVENT_CODE(chan->type, chan->channel,
IIO_EV_TYPE_THRESH, IIO_EV_DIR_EITHER),
iio_get_time_ns());
}
}
void xadc_handle_events(struct iio_dev *indio_dev, unsigned long events)
{
unsigned int i;
for_each_set_bit(i, &events, 8)
xadc_handle_event(indio_dev, i);
}
static unsigned xadc_get_threshold_offset(const struct iio_chan_spec *chan,
enum iio_event_direction dir)
{
unsigned int offset;
if (chan->type == IIO_TEMP) {
offset = XADC_THRESHOLD_OT_MAX;
} else {
if (chan->channel < 2)
offset = chan->channel + 1;
else
offset = chan->channel + 6;
}
if (dir == IIO_EV_DIR_FALLING)
offset += 4;
return offset;
}
static unsigned int xadc_get_alarm_mask(const struct iio_chan_spec *chan)
{
if (chan->type == IIO_TEMP) {
return XADC_ALARM_OT_MASK;
} else {
switch (chan->channel) {
case 0:
return XADC_ALARM_VCCINT_MASK;
case 1:
return XADC_ALARM_VCCAUX_MASK;
case 2:
return XADC_ALARM_VCCBRAM_MASK;
case 3:
return XADC_ALARM_VCCPINT_MASK;
case 4:
return XADC_ALARM_VCCPAUX_MASK;
case 5:
return XADC_ALARM_VCCODDR_MASK;
default:
return 0;
}
}
}
int xadc_read_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir)
{
struct xadc *xadc = iio_priv(indio_dev);
return (bool)(xadc->alarm_mask & xadc_get_alarm_mask(chan));
}
int xadc_write_event_config(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, int state)
{
unsigned int alarm = xadc_get_alarm_mask(chan);
struct xadc *xadc = iio_priv(indio_dev);
uint16_t cfg, old_cfg;
int ret;
mutex_lock(&xadc->mutex);
if (state)
xadc->alarm_mask |= alarm;
else
xadc->alarm_mask &= ~alarm;
xadc->ops->update_alarm(xadc, xadc->alarm_mask);
ret = _xadc_read_adc_reg(xadc, XADC_REG_CONF1, &cfg);
if (ret)
goto err_out;
old_cfg = cfg;
cfg |= XADC_CONF1_ALARM_MASK;
cfg &= ~((xadc->alarm_mask & 0xf0) << 4);
cfg &= ~((xadc->alarm_mask & 0x08) >> 3);
cfg &= ~((xadc->alarm_mask & 0x07) << 1);
if (old_cfg != cfg)
ret = _xadc_write_adc_reg(xadc, XADC_REG_CONF1, cfg);
err_out:
mutex_unlock(&xadc->mutex);
return ret;
}
int xadc_read_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info,
int *val, int *val2)
{
unsigned int offset = xadc_get_threshold_offset(chan, dir);
struct xadc *xadc = iio_priv(indio_dev);
switch (info) {
case IIO_EV_INFO_VALUE:
*val = xadc->threshold[offset];
break;
case IIO_EV_INFO_HYSTERESIS:
*val = xadc->temp_hysteresis;
break;
default:
return -EINVAL;
}
*val >>= XADC_THRESHOLD_VALUE_SHIFT;
return IIO_VAL_INT;
}
int xadc_write_event_value(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, enum iio_event_type type,
enum iio_event_direction dir, enum iio_event_info info,
int val, int val2)
{
unsigned int offset = xadc_get_threshold_offset(chan, dir);
struct xadc *xadc = iio_priv(indio_dev);
int ret = 0;
val <<= XADC_THRESHOLD_VALUE_SHIFT;
if (val < 0 || val > 0xffff)
return -EINVAL;
mutex_lock(&xadc->mutex);
switch (info) {
case IIO_EV_INFO_VALUE:
xadc->threshold[offset] = val;
break;
case IIO_EV_INFO_HYSTERESIS:
xadc->temp_hysteresis = val;
break;
default:
mutex_unlock(&xadc->mutex);
return -EINVAL;
}
if (chan->type == IIO_TEMP) {
val |= 0x3;
if (xadc->threshold[offset] < xadc->temp_hysteresis)
xadc->threshold[offset + 4] = 0;
else
xadc->threshold[offset + 4] = xadc->threshold[offset] -
xadc->temp_hysteresis;
ret = _xadc_write_adc_reg(xadc, XADC_REG_THRESHOLD(offset + 4),
xadc->threshold[offset + 4]);
if (ret)
goto out_unlock;
}
if (info == IIO_EV_INFO_VALUE)
ret = _xadc_write_adc_reg(xadc, XADC_REG_THRESHOLD(offset), val);
out_unlock:
mutex_unlock(&xadc->mutex);
return ret;
}
