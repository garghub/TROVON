static int st_gyro_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *ch, int *val,
int *val2, long mask)
{
int err;
struct st_sensor_data *gdata = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
err = st_sensors_read_info_raw(indio_dev, ch, val);
if (err < 0)
goto read_error;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = gdata->current_fullscale->gain;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
read_error:
return err;
}
static int st_gyro_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
int err;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
err = st_sensors_set_fullscale_by_gain(indio_dev, val2);
break;
default:
err = -EINVAL;
}
return err;
}
int st_gyro_common_probe(struct iio_dev *indio_dev)
{
int err;
struct st_sensor_data *gdata = iio_priv(indio_dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &gyro_info;
err = st_sensors_check_device_support(indio_dev,
ARRAY_SIZE(st_gyro_sensors), st_gyro_sensors);
if (err < 0)
goto st_gyro_common_probe_error;
gdata->num_data_channels = ST_GYRO_NUMBER_DATA_CHANNELS;
gdata->multiread_bit = gdata->sensor->multi_read_bit;
indio_dev->channels = gdata->sensor->ch;
indio_dev->num_channels = ST_SENSORS_NUMBER_ALL_CHANNELS;
gdata->current_fullscale = (struct st_sensor_fullscale_avl *)
&gdata->sensor->fs.fs_avl[0];
gdata->odr = gdata->sensor->odr.odr_avl[0].hz;
err = st_sensors_init_sensor(indio_dev);
if (err < 0)
goto st_gyro_common_probe_error;
if (gdata->get_irq_data_ready(indio_dev) > 0) {
err = st_gyro_allocate_ring(indio_dev);
if (err < 0)
goto st_gyro_common_probe_error;
err = st_sensors_allocate_trigger(indio_dev,
ST_GYRO_TRIGGER_OPS);
if (err < 0)
goto st_gyro_probe_trigger_error;
}
err = iio_device_register(indio_dev);
if (err)
goto st_gyro_device_register_error;
return err;
st_gyro_device_register_error:
if (gdata->get_irq_data_ready(indio_dev) > 0)
st_sensors_deallocate_trigger(indio_dev);
st_gyro_probe_trigger_error:
if (gdata->get_irq_data_ready(indio_dev) > 0)
st_gyro_deallocate_ring(indio_dev);
st_gyro_common_probe_error:
return err;
}
void st_gyro_common_remove(struct iio_dev *indio_dev)
{
struct st_sensor_data *gdata = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (gdata->get_irq_data_ready(indio_dev) > 0) {
st_sensors_deallocate_trigger(indio_dev);
st_gyro_deallocate_ring(indio_dev);
}
iio_device_free(indio_dev);
}
