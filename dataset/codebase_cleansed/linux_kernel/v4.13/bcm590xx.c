static int bcm590xx_i2c_probe(struct i2c_client *i2c_pri,
const struct i2c_device_id *id)
{
struct bcm590xx *bcm590xx;
int ret;
bcm590xx = devm_kzalloc(&i2c_pri->dev, sizeof(*bcm590xx), GFP_KERNEL);
if (!bcm590xx)
return -ENOMEM;
i2c_set_clientdata(i2c_pri, bcm590xx);
bcm590xx->dev = &i2c_pri->dev;
bcm590xx->i2c_pri = i2c_pri;
bcm590xx->regmap_pri = devm_regmap_init_i2c(i2c_pri,
&bcm590xx_regmap_config_pri);
if (IS_ERR(bcm590xx->regmap_pri)) {
ret = PTR_ERR(bcm590xx->regmap_pri);
dev_err(&i2c_pri->dev, "primary regmap init failed: %d\n", ret);
return ret;
}
bcm590xx->i2c_sec = i2c_new_dummy(i2c_pri->adapter,
i2c_pri->addr | BIT(2));
if (!bcm590xx->i2c_sec) {
dev_err(&i2c_pri->dev, "failed to add secondary I2C device\n");
return -ENODEV;
}
i2c_set_clientdata(bcm590xx->i2c_sec, bcm590xx);
bcm590xx->regmap_sec = devm_regmap_init_i2c(bcm590xx->i2c_sec,
&bcm590xx_regmap_config_sec);
if (IS_ERR(bcm590xx->regmap_sec)) {
ret = PTR_ERR(bcm590xx->regmap_sec);
dev_err(&bcm590xx->i2c_sec->dev,
"secondary regmap init failed: %d\n", ret);
goto err;
}
ret = devm_mfd_add_devices(&i2c_pri->dev, -1, bcm590xx_devs,
ARRAY_SIZE(bcm590xx_devs), NULL, 0, NULL);
if (ret < 0) {
dev_err(&i2c_pri->dev, "failed to add sub-devices: %d\n", ret);
goto err;
}
return 0;
err:
i2c_unregister_device(bcm590xx->i2c_sec);
return ret;
}
