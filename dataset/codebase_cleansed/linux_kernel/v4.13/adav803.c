static int adav803_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return adav80x_bus_probe(&client->dev,
devm_regmap_init_i2c(client, &adav80x_regmap_config));
}
static int adav803_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
