static int cs42l51_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap_config config;
config = cs42l51_regmap;
config.val_bits = 8;
config.reg_bits = 8;
return cs42l51_probe(&i2c->dev, devm_regmap_init_i2c(i2c, &config));
}
static int cs42l51_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
