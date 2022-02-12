static int st_press_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *ch,
int val,
int val2,
long mask)
{
int err;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
if (val2)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
err = st_sensors_set_odr(indio_dev, val);
mutex_unlock(&indio_dev->mlock);
return err;
default:
return -EINVAL;
}
}
static int st_press_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *ch, int *val,
int *val2, long mask)
{
int err;
struct st_sensor_data *press_data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
err = st_sensors_read_info_raw(indio_dev, ch, val);
if (err < 0)
goto read_error;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (ch->type) {
case IIO_PRESSURE:
*val = 0;
*val2 = press_data->current_fullscale->gain;
return IIO_VAL_INT_PLUS_NANO;
case IIO_TEMP:
*val = MCELSIUS_PER_CELSIUS;
*val2 = press_data->current_fullscale->gain2;
return IIO_VAL_FRACTIONAL;
default:
err = -EINVAL;
goto read_error;
}
case IIO_CHAN_INFO_OFFSET:
switch (ch->type) {
case IIO_TEMP:
*val = ST_PRESS_MILLI_CELSIUS_OFFSET *
press_data->current_fullscale->gain2;
*val2 = MCELSIUS_PER_CELSIUS;
break;
default:
err = -EINVAL;
goto read_error;
}
return IIO_VAL_FRACTIONAL;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = press_data->odr;
return IIO_VAL_INT;
default:
return -EINVAL;
}
read_error:
return err;
}
int st_press_common_probe(struct iio_dev *indio_dev)
{
struct st_sensor_data *press_data = iio_priv(indio_dev);
struct st_sensors_platform_data *pdata =
(struct st_sensors_platform_data *)press_data->dev->platform_data;
int irq = press_data->get_irq_data_ready(indio_dev);
int err;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &press_info;
mutex_init(&press_data->tb.buf_lock);
err = st_sensors_power_enable(indio_dev);
if (err)
return err;
err = st_sensors_check_device_support(indio_dev,
ARRAY_SIZE(st_press_sensors_settings),
st_press_sensors_settings);
if (err < 0)
goto st_press_power_off;
press_data->num_data_channels = press_data->sensor_settings->num_ch - 1;
press_data->multiread_bit = press_data->sensor_settings->multi_read_bit;
indio_dev->channels = press_data->sensor_settings->ch;
indio_dev->num_channels = press_data->sensor_settings->num_ch;
press_data->current_fullscale =
(struct st_sensor_fullscale_avl *)
&press_data->sensor_settings->fs.fs_avl[0];
press_data->odr = press_data->sensor_settings->odr.odr_avl[0].hz;
if (!pdata && press_data->sensor_settings->drdy_irq.addr)
pdata = (struct st_sensors_platform_data *)&default_press_pdata;
err = st_sensors_init_sensor(indio_dev, press_data->dev->platform_data);
if (err < 0)
goto st_press_power_off;
err = st_press_allocate_ring(indio_dev);
if (err < 0)
goto st_press_power_off;
if (irq > 0) {
err = st_sensors_allocate_trigger(indio_dev,
ST_PRESS_TRIGGER_OPS);
if (err < 0)
goto st_press_probe_trigger_error;
}
err = iio_device_register(indio_dev);
if (err)
goto st_press_device_register_error;
dev_info(&indio_dev->dev, "registered pressure sensor %s\n",
indio_dev->name);
return err;
st_press_device_register_error:
if (irq > 0)
st_sensors_deallocate_trigger(indio_dev);
st_press_probe_trigger_error:
st_press_deallocate_ring(indio_dev);
st_press_power_off:
st_sensors_power_disable(indio_dev);
return err;
}
void st_press_common_remove(struct iio_dev *indio_dev)
{
struct st_sensor_data *press_data = iio_priv(indio_dev);
st_sensors_power_disable(indio_dev);
iio_device_unregister(indio_dev);
if (press_data->get_irq_data_ready(indio_dev) > 0)
st_sensors_deallocate_trigger(indio_dev);
st_press_deallocate_ring(indio_dev);
}
