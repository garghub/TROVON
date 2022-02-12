int lp8788_read_byte(struct lp8788 *lp, u8 reg, u8 *data)
{
int ret;
unsigned int val;
ret = regmap_read(lp->regmap, reg, &val);
if (ret < 0) {
dev_err(lp->dev, "failed to read 0x%.2x\n", reg);
return ret;
}
*data = (u8)val;
return 0;
}
int lp8788_read_multi_bytes(struct lp8788 *lp, u8 reg, u8 *data, size_t count)
{
return regmap_bulk_read(lp->regmap, reg, data, count);
}
int lp8788_write_byte(struct lp8788 *lp, u8 reg, u8 data)
{
return regmap_write(lp->regmap, reg, data);
}
int lp8788_update_bits(struct lp8788 *lp, u8 reg, u8 mask, u8 data)
{
return regmap_update_bits(lp->regmap, reg, mask, data);
}
static int lp8788_platform_init(struct lp8788 *lp)
{
struct lp8788_platform_data *pdata = lp->pdata;
return (pdata && pdata->init_func) ? pdata->init_func(lp) : 0;
}
static int lp8788_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct lp8788 *lp;
struct lp8788_platform_data *pdata = cl->dev.platform_data;
int ret;
lp = devm_kzalloc(&cl->dev, sizeof(struct lp8788), GFP_KERNEL);
if (!lp)
return -ENOMEM;
lp->regmap = devm_regmap_init_i2c(cl, &lp8788_regmap_config);
if (IS_ERR(lp->regmap)) {
ret = PTR_ERR(lp->regmap);
dev_err(&cl->dev, "regmap init i2c err: %d\n", ret);
return ret;
}
lp->pdata = pdata;
lp->dev = &cl->dev;
i2c_set_clientdata(cl, lp);
ret = lp8788_platform_init(lp);
if (ret)
return ret;
ret = lp8788_irq_init(lp, cl->irq);
if (ret)
return ret;
return mfd_add_devices(lp->dev, -1, lp8788_devs,
ARRAY_SIZE(lp8788_devs), NULL, 0, NULL);
}
static int __devexit lp8788_remove(struct i2c_client *cl)
{
struct lp8788 *lp = i2c_get_clientdata(cl);
mfd_remove_devices(lp->dev);
lp8788_irq_exit(lp);
return 0;
}
static int __init lp8788_init(void)
{
return i2c_add_driver(&lp8788_driver);
}
static void __exit lp8788_exit(void)
{
i2c_del_driver(&lp8788_driver);
}
