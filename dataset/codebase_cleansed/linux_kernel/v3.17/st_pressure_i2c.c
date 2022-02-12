static int st_press_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct st_sensor_data *pdata;
int err;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*pdata));
if (!indio_dev)
return -ENOMEM;
pdata = iio_priv(indio_dev);
pdata->dev = &client->dev;
st_sensors_of_i2c_probe(client, st_press_of_match);
st_sensors_i2c_configure(indio_dev, client, pdata);
err = st_press_common_probe(indio_dev, client->dev.platform_data);
if (err < 0)
return err;
return 0;
}
static int st_press_i2c_remove(struct i2c_client *client)
{
st_press_common_remove(i2c_get_clientdata(client));
return 0;
}
