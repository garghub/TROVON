static int st_magn_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *ch, int *val,
int *val2, long mask)
{
int err;
struct st_sensor_data *mdata = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
err = st_sensors_read_info_raw(indio_dev, ch, val);
if (err < 0)
goto read_error;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
if ((ch->scan_index == ST_SENSORS_SCAN_Z) &&
(mdata->current_fullscale->gain2 != 0))
*val2 = mdata->current_fullscale->gain2;
else
*val2 = mdata->current_fullscale->gain;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = mdata->odr;
return IIO_VAL_INT;
default:
return -EINVAL;
}
read_error:
return err;
}
static int st_magn_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2, long mask)
{
int err;
switch (mask) {
case IIO_CHAN_INFO_SCALE:
err = st_sensors_set_fullscale_by_gain(indio_dev, val2);
break;
case IIO_CHAN_INFO_SAMP_FREQ:
if (val2)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
err = st_sensors_set_odr(indio_dev, val);
mutex_unlock(&indio_dev->mlock);
return err;
default:
err = -EINVAL;
}
return err;
}
int st_magn_common_probe(struct iio_dev *indio_dev)
{
struct st_sensor_data *mdata = iio_priv(indio_dev);
int irq = mdata->get_irq_data_ready(indio_dev);
int err;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &magn_info;
mutex_init(&mdata->tb.buf_lock);
st_sensors_power_enable(indio_dev);
err = st_sensors_check_device_support(indio_dev,
ARRAY_SIZE(st_magn_sensors_settings),
st_magn_sensors_settings);
if (err < 0)
return err;
mdata->num_data_channels = ST_MAGN_NUMBER_DATA_CHANNELS;
mdata->multiread_bit = mdata->sensor_settings->multi_read_bit;
indio_dev->channels = mdata->sensor_settings->ch;
indio_dev->num_channels = ST_SENSORS_NUMBER_ALL_CHANNELS;
mdata->current_fullscale = (struct st_sensor_fullscale_avl *)
&mdata->sensor_settings->fs.fs_avl[0];
mdata->odr = mdata->sensor_settings->odr.odr_avl[0].hz;
err = st_sensors_init_sensor(indio_dev, NULL);
if (err < 0)
return err;
err = st_magn_allocate_ring(indio_dev);
if (err < 0)
return err;
if (irq > 0) {
err = st_sensors_allocate_trigger(indio_dev,
ST_MAGN_TRIGGER_OPS);
if (err < 0)
goto st_magn_probe_trigger_error;
}
err = iio_device_register(indio_dev);
if (err)
goto st_magn_device_register_error;
dev_info(&indio_dev->dev, "registered magnetometer %s\n",
indio_dev->name);
return 0;
st_magn_device_register_error:
if (irq > 0)
st_sensors_deallocate_trigger(indio_dev);
st_magn_probe_trigger_error:
st_magn_deallocate_ring(indio_dev);
return err;
}
void st_magn_common_remove(struct iio_dev *indio_dev)
{
struct st_sensor_data *mdata = iio_priv(indio_dev);
st_sensors_power_disable(indio_dev);
iio_device_unregister(indio_dev);
if (mdata->get_irq_data_ready(indio_dev) > 0)
st_sensors_deallocate_trigger(indio_dev);
st_magn_deallocate_ring(indio_dev);
}
