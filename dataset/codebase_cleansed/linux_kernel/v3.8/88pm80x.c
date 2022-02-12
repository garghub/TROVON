int pm80x_init(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pm80x_chip *chip;
struct regmap *map;
int ret = 0;
chip =
devm_kzalloc(&client->dev, sizeof(struct pm80x_chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
map = devm_regmap_init_i2c(client, &pm80x_regmap_config);
if (IS_ERR(map)) {
ret = PTR_ERR(map);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
goto err_regmap_init;
}
chip->id = id->driver_data;
if (chip->id < CHIP_PM800 || chip->id > CHIP_PM805) {
ret = -EINVAL;
goto err_chip_id;
}
chip->client = client;
chip->regmap = map;
chip->irq = client->irq;
chip->dev = &client->dev;
dev_set_drvdata(chip->dev, chip);
i2c_set_clientdata(chip->client, chip);
device_init_wakeup(&client->dev, 1);
if (!g_pm80x_chip)
g_pm80x_chip = chip;
else {
chip->companion = g_pm80x_chip->client;
g_pm80x_chip->companion = chip->client;
}
return 0;
err_chip_id:
regmap_exit(map);
err_regmap_init:
devm_kfree(&client->dev, chip);
return ret;
}
int pm80x_deinit(struct i2c_client *client)
{
struct pm80x_chip *chip = i2c_get_clientdata(client);
if (g_pm80x_chip->companion)
g_pm80x_chip->companion = NULL;
else
g_pm80x_chip = NULL;
regmap_exit(chip->regmap);
devm_kfree(&client->dev, chip);
return 0;
}
static int pm80x_suspend(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct pm80x_chip *chip = i2c_get_clientdata(client);
if (chip && chip->wu_flag)
if (device_may_wakeup(chip->dev))
enable_irq_wake(chip->irq);
return 0;
}
static int pm80x_resume(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct pm80x_chip *chip = i2c_get_clientdata(client);
if (chip && chip->wu_flag)
if (device_may_wakeup(chip->dev))
disable_irq_wake(chip->irq);
return 0;
}
