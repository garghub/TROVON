static int __devinit da9055_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da9055 *da9055;
int ret;
da9055 = devm_kzalloc(&i2c->dev, sizeof(struct da9055), GFP_KERNEL);
if (!da9055)
return -ENOMEM;
da9055->regmap = devm_regmap_init_i2c(i2c, &da9055_regmap_config);
if (IS_ERR(da9055->regmap)) {
ret = PTR_ERR(da9055->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
da9055->dev = &i2c->dev;
da9055->chip_irq = i2c->irq;
i2c_set_clientdata(i2c, da9055);
return da9055_device_init(da9055);
}
static int __devexit da9055_i2c_remove(struct i2c_client *i2c)
{
struct da9055 *da9055 = i2c_get_clientdata(i2c);
da9055_device_exit(da9055);
return 0;
}
static int __init da9055_i2c_init(void)
{
int ret;
ret = i2c_add_driver(&da9055_i2c_driver);
if (ret != 0) {
pr_err("DA9055 I2C registration failed %d\n", ret);
return ret;
}
return 0;
}
static void __exit da9055_i2c_exit(void)
{
i2c_del_driver(&da9055_i2c_driver);
}
