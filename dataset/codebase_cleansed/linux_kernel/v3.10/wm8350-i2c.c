static int wm8350_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8350 *wm8350;
int ret = 0;
wm8350 = devm_kzalloc(&i2c->dev, sizeof(struct wm8350), GFP_KERNEL);
if (wm8350 == NULL)
return -ENOMEM;
wm8350->regmap = devm_regmap_init_i2c(i2c, &wm8350_regmap);
if (IS_ERR(wm8350->regmap)) {
ret = PTR_ERR(wm8350->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
i2c_set_clientdata(i2c, wm8350);
wm8350->dev = &i2c->dev;
return wm8350_device_init(wm8350, i2c->irq, i2c->dev.platform_data);
}
static int wm8350_i2c_remove(struct i2c_client *i2c)
{
struct wm8350 *wm8350 = i2c_get_clientdata(i2c);
wm8350_device_exit(wm8350);
return 0;
}
static int __init wm8350_i2c_init(void)
{
return i2c_add_driver(&wm8350_i2c_driver);
}
static void __exit wm8350_i2c_exit(void)
{
i2c_del_driver(&wm8350_i2c_driver);
}
