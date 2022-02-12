static int st_press_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *ch, int *val,
int *val2, long mask)
{
int err;
struct st_sensor_data *pdata = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
err = st_sensors_read_info_raw(indio_dev, ch, val);
if (err < 0)
goto read_error;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
switch (ch->type) {
case IIO_PRESSURE:
*val2 = pdata->current_fullscale->gain;
break;
case IIO_TEMP:
*val2 = pdata->current_fullscale->gain2;
break;
default:
err = -EINVAL;
goto read_error;
}
return IIO_VAL_INT_PLUS_NANO;
case IIO_CHAN_INFO_OFFSET:
switch (ch->type) {
case IIO_TEMP:
*val = 425;
*val2 = 10;
break;
default:
err = -EINVAL;
goto read_error;
}
return IIO_VAL_FRACTIONAL;
default:
return -EINVAL;
}
read_error:
return err;
}
int st_press_common_probe(struct iio_dev *indio_dev)
{
int err;
struct st_sensor_data *pdata = iio_priv(indio_dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &press_info;
err = st_sensors_check_device_support(indio_dev,
ARRAY_SIZE(st_press_sensors), st_press_sensors);
if (err < 0)
goto st_press_common_probe_error;
pdata->num_data_channels = ST_PRESS_NUMBER_DATA_CHANNELS;
pdata->multiread_bit = pdata->sensor->multi_read_bit;
indio_dev->channels = pdata->sensor->ch;
indio_dev->num_channels = ARRAY_SIZE(st_press_channels);
pdata->current_fullscale = (struct st_sensor_fullscale_avl *)
&pdata->sensor->fs.fs_avl[0];
pdata->odr = pdata->sensor->odr.odr_avl[0].hz;
err = st_sensors_init_sensor(indio_dev);
if (err < 0)
goto st_press_common_probe_error;
if (pdata->get_irq_data_ready(indio_dev) > 0) {
err = st_press_allocate_ring(indio_dev);
if (err < 0)
goto st_press_common_probe_error;
err = st_sensors_allocate_trigger(indio_dev,
ST_PRESS_TRIGGER_OPS);
if (err < 0)
goto st_press_probe_trigger_error;
}
err = iio_device_register(indio_dev);
if (err)
goto st_press_device_register_error;
return err;
st_press_device_register_error:
if (pdata->get_irq_data_ready(indio_dev) > 0)
st_sensors_deallocate_trigger(indio_dev);
st_press_probe_trigger_error:
if (pdata->get_irq_data_ready(indio_dev) > 0)
st_press_deallocate_ring(indio_dev);
st_press_common_probe_error:
return err;
}
void st_press_common_remove(struct iio_dev *indio_dev)
{
struct st_sensor_data *pdata = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (pdata->get_irq_data_ready(indio_dev) > 0) {
st_sensors_deallocate_trigger(indio_dev);
st_press_deallocate_ring(indio_dev);
}
iio_device_free(indio_dev);
}
