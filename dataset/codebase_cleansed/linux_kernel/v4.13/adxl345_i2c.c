static int adxl345_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
regmap = devm_regmap_init_i2c(client, &adxl345_i2c_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Error initializing i2c regmap: %ld\n",
PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return adxl345_core_probe(&client->dev, regmap, id ? id->name : NULL);
}
static int adxl345_i2c_remove(struct i2c_client *client)
{
return adxl345_core_remove(&client->dev);
}
