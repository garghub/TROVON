static int iio_dummy_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
int ret = -EINVAL;
mutex_lock(&st->lock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_VOLTAGE:
if (chan->output) {
*val = st->dac_val;
ret = IIO_VAL_INT;
} else if (chan->differential) {
if (chan->channel == 1)
*val = st->differential_adc_val[0];
else
*val = st->differential_adc_val[1];
ret = IIO_VAL_INT;
} else {
*val = st->single_ended_adc_val;
ret = IIO_VAL_INT;
}
break;
case IIO_ACCEL:
*val = st->accel_val;
ret = IIO_VAL_INT;
break;
default:
break;
}
break;
case IIO_CHAN_INFO_OFFSET:
*val = 7;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
switch (chan->differential) {
case 0:
*val = 0;
*val2 = 1333;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
case 1:
*val = 0;
*val2 = 1344;
ret = IIO_VAL_INT_PLUS_NANO;
}
break;
case IIO_CHAN_INFO_CALIBBIAS:
*val = st->accel_calibbias;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_CALIBSCALE:
*val = st->accel_calibscale->val;
*val2 = st->accel_calibscale->val2;
ret = IIO_VAL_INT_PLUS_MICRO;
break;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = 3;
*val2 = 33;
ret = IIO_VAL_INT_PLUS_NANO;
break;
default:
break;
}
mutex_unlock(&st->lock);
return ret;
}
static int iio_dummy_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
int i;
int ret = 0;
struct iio_dummy_state *st = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->output == 0)
return -EINVAL;
mutex_lock(&st->lock);
st->dac_val = val;
mutex_unlock(&st->lock);
return 0;
case IIO_CHAN_INFO_CALIBSCALE:
mutex_lock(&st->lock);
for (i = 0; i < ARRAY_SIZE(dummy_scales); i++)
if (val == dummy_scales[i].val &&
val2 == dummy_scales[i].val2)
break;
if (i == ARRAY_SIZE(dummy_scales))
ret = -EINVAL;
else
st->accel_calibscale = &dummy_scales[i];
mutex_unlock(&st->lock);
return ret;
case IIO_CHAN_INFO_CALIBBIAS:
mutex_lock(&st->lock);
st->accel_calibbias = val;
mutex_unlock(&st->lock);
return 0;
default:
return -EINVAL;
}
}
static int iio_dummy_init_device(struct iio_dev *indio_dev)
{
struct iio_dummy_state *st = iio_priv(indio_dev);
st->dac_val = 0;
st->single_ended_adc_val = 73;
st->differential_adc_val[0] = 33;
st->differential_adc_val[1] = -34;
st->accel_val = 34;
st->accel_calibbias = -7;
st->accel_calibscale = &dummy_scales[0];
return 0;
}
static int iio_dummy_probe(int index)
{
int ret;
struct iio_dev *indio_dev;
struct iio_dummy_state *st;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(indio_dev);
mutex_init(&st->lock);
iio_dummy_init_device(indio_dev);
iio_dummy_devs[index] = indio_dev;
indio_dev->name = iio_dummy_part_number;
indio_dev->channels = iio_dummy_channels;
indio_dev->num_channels = ARRAY_SIZE(iio_dummy_channels);
indio_dev->info = &iio_dummy_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_simple_dummy_events_register(indio_dev);
if (ret < 0)
goto error_free_device;
ret = iio_simple_dummy_configure_buffer(indio_dev,
iio_dummy_channels, 5);
if (ret < 0)
goto error_unregister_events;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto error_unconfigure_buffer;
return 0;
error_unconfigure_buffer:
iio_simple_dummy_unconfigure_buffer(indio_dev);
error_unregister_events:
iio_simple_dummy_events_unregister(indio_dev);
error_free_device:
iio_device_free(indio_dev);
error_ret:
return ret;
}
static int iio_dummy_remove(int index)
{
int ret;
struct iio_dev *indio_dev = iio_dummy_devs[index];
iio_device_unregister(indio_dev);
iio_simple_dummy_unconfigure_buffer(indio_dev);
ret = iio_simple_dummy_events_unregister(indio_dev);
if (ret)
goto error_ret;
iio_device_free(indio_dev);
error_ret:
return ret;
}
static __init int iio_dummy_init(void)
{
int i, ret;
if (instances > 10) {
instances = 1;
return -EINVAL;
}
iio_dummy_devs = kcalloc(instances, sizeof(*iio_dummy_devs),
GFP_KERNEL);
for (i = 0; i < instances; i++) {
ret = iio_dummy_probe(i);
if (ret < 0)
return ret;
}
return 0;
}
static __exit void iio_dummy_exit(void)
{
int i;
for (i = 0; i < instances; i++)
iio_dummy_remove(i);
kfree(iio_dummy_devs);
}
