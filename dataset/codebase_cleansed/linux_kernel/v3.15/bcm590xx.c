static int bcm590xx_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct bcm590xx *bcm590xx;
int ret;
bcm590xx = devm_kzalloc(&i2c->dev, sizeof(*bcm590xx), GFP_KERNEL);
if (!bcm590xx)
return -ENOMEM;
i2c_set_clientdata(i2c, bcm590xx);
bcm590xx->dev = &i2c->dev;
bcm590xx->i2c_client = i2c;
bcm590xx->regmap = devm_regmap_init_i2c(i2c, &bcm590xx_regmap_config);
if (IS_ERR(bcm590xx->regmap)) {
ret = PTR_ERR(bcm590xx->regmap);
dev_err(&i2c->dev, "regmap initialization failed: %d\n", ret);
return ret;
}
ret = mfd_add_devices(&i2c->dev, -1, bcm590xx_devs,
ARRAY_SIZE(bcm590xx_devs), NULL, 0, NULL);
if (ret < 0)
dev_err(&i2c->dev, "failed to add sub-devices: %d\n", ret);
return ret;
}
