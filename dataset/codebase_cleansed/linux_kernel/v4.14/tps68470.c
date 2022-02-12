static int tps68470_chip_init(struct device *dev, struct regmap *regmap)
{
unsigned int version;
int ret;
ret = regmap_write(regmap, TPS68470_REG_RESET, TPS68470_REG_RESET_MASK);
if (ret)
return ret;
ret = regmap_read(regmap, TPS68470_REG_REVID, &version);
if (ret) {
dev_err(dev, "Failed to read revision register: %d\n", ret);
return ret;
}
dev_info(dev, "TPS68470 REVID: 0x%x\n", version);
return 0;
}
static int tps68470_probe(struct i2c_client *client)
{
struct device *dev = &client->dev;
struct regmap *regmap;
int ret;
regmap = devm_regmap_init_i2c(client, &tps68470_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "devm_regmap_init_i2c Error %ld\n",
PTR_ERR(regmap));
return PTR_ERR(regmap);
}
i2c_set_clientdata(client, regmap);
ret = tps68470_chip_init(dev, regmap);
if (ret < 0) {
dev_err(dev, "TPS68470 Init Error %d\n", ret);
return ret;
}
ret = devm_mfd_add_devices(dev, PLATFORM_DEVID_NONE, tps68470s,
ARRAY_SIZE(tps68470s), NULL, 0, NULL);
if (ret < 0) {
dev_err(dev, "devm_mfd_add_devices failed: %d\n", ret);
return ret;
}
return 0;
}
