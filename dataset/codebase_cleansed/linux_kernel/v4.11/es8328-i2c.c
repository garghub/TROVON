static int es8328_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
return es8328_probe(&i2c->dev,
devm_regmap_init_i2c(i2c, &es8328_regmap_config));
}
static int es8328_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
