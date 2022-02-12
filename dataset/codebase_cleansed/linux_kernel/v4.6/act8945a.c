static int act8945a_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
int ret;
struct regmap *regmap;
regmap = devm_regmap_init_i2c(i2c, &act8945a_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(&i2c->dev, "regmap init failed: %d\n", ret);
return ret;
}
i2c_set_clientdata(i2c, regmap);
ret = mfd_add_devices(&i2c->dev, PLATFORM_DEVID_NONE, act8945a_devs,
ARRAY_SIZE(act8945a_devs), NULL, 0, NULL);
if (ret) {
dev_err(&i2c->dev, "Failed to add sub devices\n");
return ret;
}
return 0;
}
static int act8945a_i2c_remove(struct i2c_client *i2c)
{
mfd_remove_devices(&i2c->dev);
return 0;
}
static int __init act8945a_i2c_init(void)
{
return i2c_add_driver(&act8945a_i2c_driver);
}
static void __exit act8945a_i2c_exit(void)
{
i2c_del_driver(&act8945a_i2c_driver);
}
