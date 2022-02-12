static int aic32x4_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *regmap;
struct regmap_config config;
config = aic32x4_regmap_config;
config.reg_bits = 8;
config.val_bits = 8;
regmap = devm_regmap_init_i2c(i2c, &config);
return aic32x4_probe(&i2c->dev, regmap);
}
static int aic32x4_i2c_remove(struct i2c_client *i2c)
{
return aic32x4_remove(&i2c->dev);
}
