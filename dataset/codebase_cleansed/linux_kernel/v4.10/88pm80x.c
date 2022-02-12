int pm80x_init(struct i2c_client *client)
{
struct pm80x_chip *chip;
struct regmap *map;
unsigned int val;
int i, ret = 0;
chip =
devm_kzalloc(&client->dev, sizeof(struct pm80x_chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
map = devm_regmap_init_i2c(client, &pm80x_regmap_config);
if (IS_ERR(map)) {
ret = PTR_ERR(map);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
chip->client = client;
chip->regmap = map;
chip->irq = client->irq;
chip->dev = &client->dev;
dev_set_drvdata(chip->dev, chip);
i2c_set_clientdata(chip->client, chip);
ret = regmap_read(chip->regmap, PM80X_CHIP_ID, &val);
if (ret < 0) {
dev_err(chip->dev, "Failed to read CHIP ID: %d\n", ret);
return ret;
}
for (i = 0; i < ARRAY_SIZE(chip_mapping); i++) {
if (chip_mapping[i].id == PM80X_CHIP_ID_NUM(val)) {
chip->type = chip_mapping[i].type;
break;
}
}
if (i == ARRAY_SIZE(chip_mapping)) {
dev_err(chip->dev,
"Failed to detect Marvell 88PM800:ChipID[0x%x]\n", val);
return -EINVAL;
}
device_init_wakeup(&client->dev, 1);
if (!g_pm80x_chip)
g_pm80x_chip = chip;
else {
chip->companion = g_pm80x_chip->client;
g_pm80x_chip->companion = chip->client;
}
return 0;
}
int pm80x_deinit(void)
{
if (g_pm80x_chip->companion)
g_pm80x_chip->companion = NULL;
else
g_pm80x_chip = NULL;
return 0;
}
static int pm80x_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct pm80x_chip *chip = i2c_get_clientdata(client);
if (chip && chip->wu_flag)
if (device_may_wakeup(chip->dev))
enable_irq_wake(chip->irq);
return 0;
}
static int pm80x_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct pm80x_chip *chip = i2c_get_clientdata(client);
if (chip && chip->wu_flag)
if (device_may_wakeup(chip->dev))
disable_irq_wake(chip->irq);
return 0;
}
