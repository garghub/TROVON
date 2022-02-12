static int wm831x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm831x *wm831x;
int ret;
wm831x = devm_kzalloc(&i2c->dev, sizeof(struct wm831x), GFP_KERNEL);
if (wm831x == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm831x);
wm831x->dev = &i2c->dev;
wm831x->regmap = devm_regmap_init_i2c(i2c, &wm831x_regmap_config);
if (IS_ERR(wm831x->regmap)) {
ret = PTR_ERR(wm831x->regmap);
dev_err(wm831x->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
return wm831x_device_init(wm831x, id->driver_data, i2c->irq);
}
static int wm831x_i2c_remove(struct i2c_client *i2c)
{
struct wm831x *wm831x = i2c_get_clientdata(i2c);
wm831x_device_exit(wm831x);
return 0;
}
static int wm831x_i2c_suspend(struct device *dev)
{
struct wm831x *wm831x = dev_get_drvdata(dev);
return wm831x_device_suspend(wm831x);
}
static void wm831x_i2c_shutdown(struct i2c_client *i2c)
{
struct wm831x *wm831x = i2c_get_clientdata(i2c);
wm831x_device_shutdown(wm831x);
}
static int __init wm831x_i2c_init(void)
{
int ret;
ret = i2c_add_driver(&wm831x_i2c_driver);
if (ret != 0)
pr_err("Failed to register wm831x I2C driver: %d\n", ret);
return ret;
}
static void __exit wm831x_i2c_exit(void)
{
i2c_del_driver(&wm831x_i2c_driver);
}
