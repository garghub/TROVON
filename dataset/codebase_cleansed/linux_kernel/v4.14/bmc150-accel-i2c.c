static int bmc150_accel_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
const char *name = NULL;
bool block_supported =
i2c_check_functionality(client->adapter, I2C_FUNC_I2C) ||
i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_I2C_BLOCK);
regmap = devm_regmap_init_i2c(client, &bmc150_regmap_conf);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "Failed to initialize i2c regmap\n");
return PTR_ERR(regmap);
}
if (id)
name = id->name;
return bmc150_accel_core_probe(&client->dev, regmap, client->irq, name,
block_supported);
}
static int bmc150_accel_remove(struct i2c_client *client)
{
return bmc150_accel_core_remove(&client->dev);
}
