static int cs4271_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap_config config;
config = cs4271_regmap_config;
config.reg_bits = 8;
config.val_bits = 8;
return cs4271_probe(&client->dev,
devm_regmap_init_i2c(client, &config));
}
static int cs4271_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
