static int da9063_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct da9063 *da9063;
int ret;
da9063 = devm_kzalloc(&i2c->dev, sizeof(struct da9063), GFP_KERNEL);
if (da9063 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, da9063);
da9063->dev = &i2c->dev;
da9063->chip_irq = i2c->irq;
da9063->regmap = devm_regmap_init_i2c(i2c, &da9063_regmap_config);
if (IS_ERR(da9063->regmap)) {
ret = PTR_ERR(da9063->regmap);
dev_err(da9063->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
return da9063_device_init(da9063, i2c->irq);
}
static int da9063_i2c_remove(struct i2c_client *i2c)
{
struct da9063 *da9063 = i2c_get_clientdata(i2c);
da9063_device_exit(da9063);
return 0;
}
