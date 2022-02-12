static int st_magn_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct st_sensor_data *mdata;
int err;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*mdata));
if (!indio_dev)
return -ENOMEM;
mdata = iio_priv(indio_dev);
mdata->dev = &client->dev;
st_sensors_of_i2c_probe(client, st_magn_of_match);
st_sensors_i2c_configure(indio_dev, client, mdata);
err = st_magn_common_probe(indio_dev, NULL);
if (err < 0)
return err;
return 0;
}
static int st_magn_i2c_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
st_magn_common_remove(indio_dev);
return 0;
}
