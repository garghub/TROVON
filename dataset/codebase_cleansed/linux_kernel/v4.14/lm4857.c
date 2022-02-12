static int lm4857_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *regmap;
regmap = devm_regmap_init_i2c(i2c, &lm4857_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return devm_snd_soc_register_component(&i2c->dev,
&lm4857_component_driver, NULL, 0);
}
