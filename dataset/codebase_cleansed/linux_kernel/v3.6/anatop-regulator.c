static int anatop_set_voltage_sel(struct regulator_dev *reg, unsigned selector)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
u32 val, mask;
if (!anatop_reg->control_reg)
return -ENOTSUPP;
val = anatop_reg->min_bit_val + selector;
dev_dbg(&reg->dev, "%s: calculated val %d\n", __func__, val);
mask = ((1 << anatop_reg->vol_bit_width) - 1) <<
anatop_reg->vol_bit_shift;
val <<= anatop_reg->vol_bit_shift;
anatop_write_reg(anatop_reg->mfd, anatop_reg->control_reg, val, mask);
return 0;
}
static int anatop_get_voltage_sel(struct regulator_dev *reg)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
u32 val, mask;
if (!anatop_reg->control_reg)
return -ENOTSUPP;
val = anatop_read_reg(anatop_reg->mfd, anatop_reg->control_reg);
mask = ((1 << anatop_reg->vol_bit_width) - 1) <<
anatop_reg->vol_bit_shift;
val = (val & mask) >> anatop_reg->vol_bit_shift;
return val - anatop_reg->min_bit_val;
}
static int __devinit anatop_regulator_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct regulator_desc *rdesc;
struct regulator_dev *rdev;
struct anatop_regulator *sreg;
struct regulator_init_data *initdata;
struct anatop *anatopmfd = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
int ret = 0;
initdata = of_get_regulator_init_data(dev, np);
sreg = devm_kzalloc(dev, sizeof(*sreg), GFP_KERNEL);
if (!sreg)
return -ENOMEM;
sreg->initdata = initdata;
sreg->name = kstrdup(of_get_property(np, "regulator-name", NULL),
GFP_KERNEL);
rdesc = &sreg->rdesc;
memset(rdesc, 0, sizeof(*rdesc));
rdesc->name = sreg->name;
rdesc->ops = &anatop_rops;
rdesc->type = REGULATOR_VOLTAGE;
rdesc->owner = THIS_MODULE;
sreg->mfd = anatopmfd;
ret = of_property_read_u32(np, "anatop-reg-offset",
&sreg->control_reg);
if (ret) {
dev_err(dev, "no anatop-reg-offset property set\n");
goto anatop_probe_end;
}
ret = of_property_read_u32(np, "anatop-vol-bit-width",
&sreg->vol_bit_width);
if (ret) {
dev_err(dev, "no anatop-vol-bit-width property set\n");
goto anatop_probe_end;
}
ret = of_property_read_u32(np, "anatop-vol-bit-shift",
&sreg->vol_bit_shift);
if (ret) {
dev_err(dev, "no anatop-vol-bit-shift property set\n");
goto anatop_probe_end;
}
ret = of_property_read_u32(np, "anatop-min-bit-val",
&sreg->min_bit_val);
if (ret) {
dev_err(dev, "no anatop-min-bit-val property set\n");
goto anatop_probe_end;
}
ret = of_property_read_u32(np, "anatop-min-voltage",
&sreg->min_voltage);
if (ret) {
dev_err(dev, "no anatop-min-voltage property set\n");
goto anatop_probe_end;
}
ret = of_property_read_u32(np, "anatop-max-voltage",
&sreg->max_voltage);
if (ret) {
dev_err(dev, "no anatop-max-voltage property set\n");
goto anatop_probe_end;
}
rdesc->n_voltages = (sreg->max_voltage - sreg->min_voltage)
/ 25000 + 1;
rdesc->min_uV = sreg->min_voltage;
rdesc->uV_step = 25000;
config.dev = &pdev->dev;
config.init_data = initdata;
config.driver_data = sreg;
config.of_node = pdev->dev.of_node;
rdev = regulator_register(rdesc, &config);
if (IS_ERR(rdev)) {
dev_err(dev, "failed to register %s\n",
rdesc->name);
ret = PTR_ERR(rdev);
goto anatop_probe_end;
}
platform_set_drvdata(pdev, rdev);
anatop_probe_end:
if (ret)
kfree(sreg->name);
return ret;
}
static int __devexit anatop_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
struct anatop_regulator *sreg = rdev_get_drvdata(rdev);
const char *name = sreg->name;
regulator_unregister(rdev);
kfree(name);
return 0;
}
static int __init anatop_regulator_init(void)
{
return platform_driver_register(&anatop_regulator_driver);
}
static void __exit anatop_regulator_exit(void)
{
platform_driver_unregister(&anatop_regulator_driver);
}
