static int st_magn_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct st_sensor_data *mdata;
int err;
indio_dev = iio_device_alloc(sizeof(*mdata));
if (indio_dev == NULL) {
err = -ENOMEM;
goto iio_device_alloc_error;
}
mdata = iio_priv(indio_dev);
mdata->dev = &client->dev;
st_sensors_i2c_configure(indio_dev, client, mdata);
err = st_magn_common_probe(indio_dev);
if (err < 0)
goto st_magn_common_probe_error;
return 0;
st_magn_common_probe_error:
iio_device_free(indio_dev);
iio_device_alloc_error:
return err;
}
static int st_magn_i2c_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
st_magn_common_remove(indio_dev);
return 0;
}
