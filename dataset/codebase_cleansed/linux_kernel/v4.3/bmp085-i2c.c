static int bmp085_i2c_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
if (client->addr != BMP085_I2C_ADDRESS)
return -ENODEV;
return bmp085_detect(&client->dev);
}
static int bmp085_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int err;
struct regmap *regmap = devm_regmap_init_i2c(client,
&bmp085_regmap_config);
if (IS_ERR(regmap)) {
err = PTR_ERR(regmap);
dev_err(&client->dev, "Failed to init regmap: %d\n", err);
return err;
}
return bmp085_probe(&client->dev, regmap, client->irq);
}
static int bmp085_i2c_remove(struct i2c_client *client)
{
return bmp085_remove(&client->dev);
}
