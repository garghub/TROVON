static int ad7879_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(&client->dev, "SMBUS Word Data not Supported\n");
return -EIO;
}
regmap = devm_regmap_init_i2c(client, &ad7879_i2c_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return ad7879_probe(&client->dev, regmap, client->irq,
BUS_I2C, AD7879_DEVID);
}
