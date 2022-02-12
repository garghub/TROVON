static int smsc_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct smsc *smsc;
int devid, rev, venid_l, venid_h;
int ret;
smsc = devm_kzalloc(&i2c->dev, sizeof(struct smsc),
GFP_KERNEL);
if (!smsc) {
dev_err(&i2c->dev, "smsc mfd driver memory allocation failed\n");
return -ENOMEM;
}
smsc->regmap = devm_regmap_init_i2c(i2c, &smsc_regmap_config);
if (IS_ERR(smsc->regmap))
return PTR_ERR(smsc->regmap);
i2c_set_clientdata(i2c, smsc);
smsc->dev = &i2c->dev;
#ifdef CONFIG_OF
of_property_read_u32(i2c->dev.of_node, "clock", &smsc->clk);
#endif
regmap_read(smsc->regmap, SMSC_DEV_ID, &devid);
regmap_read(smsc->regmap, SMSC_DEV_REV, &rev);
regmap_read(smsc->regmap, SMSC_VEN_ID_L, &venid_l);
regmap_read(smsc->regmap, SMSC_VEN_ID_H, &venid_h);
dev_info(&i2c->dev, "SMSCxxx devid: %02x rev: %02x venid: %02x\n",
devid, rev, (venid_h << 8) | venid_l);
ret = regmap_write(smsc->regmap, SMSC_CLK_CTRL, smsc->clk);
if (ret)
return ret;
#ifdef CONFIG_OF
if (i2c->dev.of_node)
ret = devm_of_platform_populate(&i2c->dev);
#endif
return ret;
}
