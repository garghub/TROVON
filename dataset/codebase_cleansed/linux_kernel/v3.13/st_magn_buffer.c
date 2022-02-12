static int st_magn_buffer_preenable(struct iio_dev *indio_dev)
{
return st_sensors_set_enable(indio_dev, true);
}
static int st_magn_buffer_postenable(struct iio_dev *indio_dev)
{
int err;
struct st_sensor_data *mdata = iio_priv(indio_dev);
mdata->buffer_data = kmalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (mdata->buffer_data == NULL) {
err = -ENOMEM;
goto allocate_memory_error;
}
err = iio_triggered_buffer_postenable(indio_dev);
if (err < 0)
goto st_magn_buffer_postenable_error;
return err;
st_magn_buffer_postenable_error:
kfree(mdata->buffer_data);
allocate_memory_error:
return err;
}
static int st_magn_buffer_predisable(struct iio_dev *indio_dev)
{
int err;
struct st_sensor_data *mdata = iio_priv(indio_dev);
err = iio_triggered_buffer_predisable(indio_dev);
if (err < 0)
goto st_magn_buffer_predisable_error;
err = st_sensors_set_enable(indio_dev, false);
st_magn_buffer_predisable_error:
kfree(mdata->buffer_data);
return err;
}
int st_magn_allocate_ring(struct iio_dev *indio_dev)
{
return iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
&st_sensors_trigger_handler, &st_magn_buffer_setup_ops);
}
void st_magn_deallocate_ring(struct iio_dev *indio_dev)
{
iio_triggered_buffer_cleanup(indio_dev);
}
