int lp3943_read_byte(struct lp3943 *lp3943, u8 reg, u8 *read)
{
int ret;
unsigned int val;
ret = regmap_read(lp3943->regmap, reg, &val);
if (ret < 0)
return ret;
*read = (u8)val;
return 0;
}
int lp3943_write_byte(struct lp3943 *lp3943, u8 reg, u8 data)
{
return regmap_write(lp3943->regmap, reg, data);
}
int lp3943_update_bits(struct lp3943 *lp3943, u8 reg, u8 mask, u8 data)
{
return regmap_update_bits(lp3943->regmap, reg, mask, data);
}
static int lp3943_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct lp3943 *lp3943;
struct device *dev = &cl->dev;
lp3943 = devm_kzalloc(dev, sizeof(*lp3943), GFP_KERNEL);
if (!lp3943)
return -ENOMEM;
lp3943->regmap = devm_regmap_init_i2c(cl, &lp3943_regmap_config);
if (IS_ERR(lp3943->regmap))
return PTR_ERR(lp3943->regmap);
lp3943->pdata = dev_get_platdata(dev);
lp3943->dev = dev;
lp3943->mux_cfg = lp3943_mux_cfg;
i2c_set_clientdata(cl, lp3943);
return mfd_add_devices(dev, -1, lp3943_devs, ARRAY_SIZE(lp3943_devs),
NULL, 0, NULL);
}
static int lp3943_remove(struct i2c_client *cl)
{
struct lp3943 *lp3943 = i2c_get_clientdata(cl);
mfd_remove_devices(lp3943->dev);
return 0;
}
