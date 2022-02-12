static int hmc5843_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return hmc5843_common_probe(&client->dev,
devm_regmap_init_i2c(client, &hmc5843_i2c_regmap_config),
id->driver_data);
}
static int hmc5843_i2c_remove(struct i2c_client *client)
{
return hmc5843_common_remove(&client->dev);
}
