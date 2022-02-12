static int ssm2602_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return ssm2602_probe(&client->dev, id->driver_data,
devm_regmap_init_i2c(client, &ssm2602_regmap_config));
}
static int ssm2602_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
