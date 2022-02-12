static int st_press_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct iio_dev *indio_dev;
struct st_sensor_data *press_data;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*press_data));
if (!indio_dev)
return -ENOMEM;
press_data = iio_priv(indio_dev);
if (client->dev.of_node) {
st_sensors_of_name_probe(&client->dev, st_press_of_match,
client->name, sizeof(client->name));
} else if (ACPI_HANDLE(&client->dev)) {
ret = st_sensors_match_acpi_device(&client->dev);
if ((ret < 0) || (ret >= ST_PRESS_MAX))
return -ENODEV;
strncpy(client->name, st_press_id_table[ret].name,
sizeof(client->name));
client->name[sizeof(client->name) - 1] = '\0';
} else if (!id)
return -ENODEV;
st_sensors_i2c_configure(indio_dev, client, press_data);
ret = st_press_common_probe(indio_dev);
if (ret < 0)
return ret;
return 0;
}
static int st_press_i2c_remove(struct i2c_client *client)
{
st_press_common_remove(i2c_get_clientdata(client));
return 0;
}
