static int bmi160_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
const char *name = NULL;
regmap = devm_regmap_init_i2c(client, &bmi160_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Failed to register i2c regmap %d\n",
(int)PTR_ERR(regmap));
return PTR_ERR(regmap);
}
if (id)
name = id->name;
return bmi160_core_probe(&client->dev, regmap, name, false);
}
static int bmi160_i2c_remove(struct i2c_client *client)
{
bmi160_core_remove(&client->dev);
return 0;
}
