static int st_accel_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *ch, int *val,
int *val2, long mask)
{
int err;
struct st_sensor_data *adata = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
err = st_sensors_read_info_raw(indio_dev, ch, val);
if (err < 0)
goto read_error;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = adata->current_fullscale->gain;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
read_error:
return err;
}
static int st_accel_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
int err;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
err = st_sensors_set_fullscale_by_gain(indio_dev, val2);
break;
default:
return -EINVAL;
}
return err;
}
int st_accel_common_probe(struct iio_dev *indio_dev)
{
int err;
struct st_sensor_data *adata = iio_priv(indio_dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &accel_info;
err = st_sensors_check_device_support(indio_dev,
ARRAY_SIZE(st_accel_sensors), st_accel_sensors);
if (err < 0)
goto st_accel_common_probe_error;
adata->num_data_channels = ST_ACCEL_NUMBER_DATA_CHANNELS;
adata->multiread_bit = adata->sensor->multi_read_bit;
indio_dev->channels = adata->sensor->ch;
indio_dev->num_channels = ST_SENSORS_NUMBER_ALL_CHANNELS;
adata->current_fullscale = (struct st_sensor_fullscale_avl *)
&adata->sensor->fs.fs_avl[0];
adata->odr = adata->sensor->odr.odr_avl[0].hz;
err = st_sensors_init_sensor(indio_dev);
if (err < 0)
goto st_accel_common_probe_error;
if (adata->get_irq_data_ready(indio_dev) > 0) {
err = st_accel_allocate_ring(indio_dev);
if (err < 0)
goto st_accel_common_probe_error;
err = st_sensors_allocate_trigger(indio_dev,
ST_ACCEL_TRIGGER_OPS);
if (err < 0)
goto st_accel_probe_trigger_error;
}
err = iio_device_register(indio_dev);
if (err)
goto st_accel_device_register_error;
return err;
st_accel_device_register_error:
if (adata->get_irq_data_ready(indio_dev) > 0)
st_sensors_deallocate_trigger(indio_dev);
st_accel_probe_trigger_error:
if (adata->get_irq_data_ready(indio_dev) > 0)
st_accel_deallocate_ring(indio_dev);
st_accel_common_probe_error:
return err;
}
void st_accel_common_remove(struct iio_dev *indio_dev)
{
struct st_sensor_data *adata = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (adata->get_irq_data_ready(indio_dev) > 0) {
st_sensors_deallocate_trigger(indio_dev);
st_accel_deallocate_ring(indio_dev);
}
iio_device_free(indio_dev);
}
