static int mma7455_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regmap *regmap;
const char *name = NULL;
regmap = devm_regmap_init_i2c(i2c, &mma7455_core_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
if (id)
name = id->name;
return mma7455_core_probe(&i2c->dev, regmap, name);
}
static int mma7455_i2c_remove(struct i2c_client *i2c)
{
return mma7455_core_remove(&i2c->dev);
}
