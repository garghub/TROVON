static int bmp280_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct regmap *regmap;
const struct regmap_config *regmap_config;
switch (id->driver_data) {
case BMP180_CHIP_ID:
regmap_config = &bmp180_regmap_config;
break;
case BMP280_CHIP_ID:
case BME280_CHIP_ID:
regmap_config = &bmp280_regmap_config;
break;
default:
return -EINVAL;
}
regmap = devm_regmap_init_i2c(client, regmap_config);
if (IS_ERR(regmap)) {
dev_err(&client->dev, "failed to allocate register map\n");
return PTR_ERR(regmap);
}
return bmp280_common_probe(&client->dev,
regmap,
id->driver_data,
id->name,
client->irq);
}
static int bmp280_i2c_remove(struct i2c_client *client)
{
return bmp280_common_remove(&client->dev);
}
