static int bmc150_magn_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
const char *name = NULL;
regmap = devm_regmap_init_i2c(client, &bmc150_magn_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Failed to initialize i2c regmap\n");
return PTR_ERR(regmap);
}
if (id)
name = id->name;
return bmc150_magn_probe(&client->dev, regmap, client->irq, name);
}
static int bmc150_magn_i2c_remove(struct i2c_client *client)
{
return bmc150_magn_remove(&client->dev);
}
