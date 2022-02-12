static int st_gyro_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct st_sensor_data *gdata;
int err;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*gdata));
if (!indio_dev)
return -ENOMEM;
gdata = iio_priv(indio_dev);
st_sensors_of_name_probe(&client->dev, st_gyro_of_match,
client->name, sizeof(client->name));
st_sensors_i2c_configure(indio_dev, client, gdata);
err = st_gyro_common_probe(indio_dev);
if (err < 0)
return err;
return 0;
}
static int st_gyro_i2c_remove(struct i2c_client *client)
{
st_gyro_common_remove(i2c_get_clientdata(client));
return 0;
}
