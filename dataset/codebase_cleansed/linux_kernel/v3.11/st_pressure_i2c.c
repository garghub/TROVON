static int st_press_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct st_sensor_data *pdata;
int err;
indio_dev = iio_device_alloc(sizeof(*pdata));
if (indio_dev == NULL) {
err = -ENOMEM;
goto iio_device_alloc_error;
}
pdata = iio_priv(indio_dev);
pdata->dev = &client->dev;
st_sensors_i2c_configure(indio_dev, client, pdata);
err = st_press_common_probe(indio_dev);
if (err < 0)
goto st_press_common_probe_error;
return 0;
st_press_common_probe_error:
iio_device_free(indio_dev);
iio_device_alloc_error:
return err;
}
static int st_press_i2c_remove(struct i2c_client *client)
{
st_press_common_remove(i2c_get_clientdata(client));
return 0;
}
