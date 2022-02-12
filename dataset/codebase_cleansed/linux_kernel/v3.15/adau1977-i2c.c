static int adau1977_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap_config config;
config = adau1977_regmap_config;
config.val_bits = 8;
config.reg_bits = 8;
return adau1977_probe(&client->dev,
devm_regmap_init_i2c(client, &config),
id->driver_data, NULL);
}
static int adau1977_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
