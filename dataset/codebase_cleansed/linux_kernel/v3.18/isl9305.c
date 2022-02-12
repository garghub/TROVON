static int isl9305_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct regulator_config config = { };
struct isl9305_pdata *pdata = i2c->dev.platform_data;
struct regulator_dev *rdev;
struct regmap *regmap;
int i, ret;
regmap = devm_regmap_init_i2c(i2c, &isl9305_regmap);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(&i2c->dev, "Failed to create regmap: %d\n", ret);
return ret;
}
config.dev = &i2c->dev;
for (i = 0; i < ARRAY_SIZE(isl9305_regulators); i++) {
if (pdata)
config.init_data = pdata->init_data[i];
else
config.init_data = NULL;
rdev = devm_regulator_register(&i2c->dev,
&isl9305_regulators[i],
&config);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(&i2c->dev, "Failed to register %s: %d\n",
isl9305_regulators[i].name, ret);
return ret;
}
}
return 0;
}
