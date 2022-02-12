static int wm8804_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *regmap;
regmap = devm_regmap_init_i2c(i2c, &wm8804_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return wm8804_probe(&i2c->dev, regmap);
}
static int wm8804_i2c_remove(struct i2c_client *i2c)
{
wm8804_remove(&i2c->dev);
return 0;
}
