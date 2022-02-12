static int anatop_regmap_set_voltage_sel(struct regulator_dev *reg,
unsigned selector)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
if (!anatop_reg->control_reg)
return -ENOTSUPP;
return regulator_set_voltage_sel_regmap(reg, selector);
}
static int anatop_regmap_set_voltage_time_sel(struct regulator_dev *reg,
unsigned int old_sel,
unsigned int new_sel)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
u32 val;
int ret = 0;
if (anatop_reg->delay_bit_width && new_sel > old_sel) {
regmap_read(anatop_reg->anatop, anatop_reg->delay_reg, &val);
val = (val >> anatop_reg->delay_bit_shift) &
((1 << anatop_reg->delay_bit_width) - 1);
ret = (new_sel - old_sel) * (LDO_RAMP_UP_UNIT_IN_CYCLES <<
val) / LDO_RAMP_UP_FREQ_IN_MHZ + 1;
}
return ret;
}
static int anatop_regmap_get_voltage_sel(struct regulator_dev *reg)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
if (!anatop_reg->control_reg)
return -ENOTSUPP;
return regulator_get_voltage_sel_regmap(reg);
}
static int anatop_regulator_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *anatop_np;
struct regulator_desc *rdesc;
struct regulator_dev *rdev;
struct anatop_regulator *sreg;
struct regulator_init_data *initdata;
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
anatop_np = of_get_parent(np);
if (!anatop_np)
return -ENODEV;
sreg->anatop = syscon_node_to_regmap(anatop_np);
of_node_put(anatop_np);
if (IS_ERR(sreg->anatop))
return PTR_ERR(sreg->anatop);
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
of_property_read_u32(np, "anatop-delay-reg-offset",
&sreg->delay_reg);
of_property_read_u32(np, "anatop-delay-bit-width",
&sreg->delay_bit_width);
of_property_read_u32(np, "anatop-delay-bit-shift",
&sreg->delay_bit_shift);
rdesc->n_voltages = (sreg->max_voltage - sreg->min_voltage) / 25000 + 1
+ sreg->min_bit_val;
rdesc->min_uV = sreg->min_voltage;
rdesc->uV_step = 25000;
rdesc->linear_min_sel = sreg->min_bit_val;
rdesc->vsel_reg = sreg->control_reg;
rdesc->vsel_mask = ((1 << sreg->vol_bit_width) - 1) <<
sreg->vol_bit_shift;
config.dev = &pdev->dev;
config.init_data = initdata;
config.driver_data = sreg;
config.of_node = pdev->dev.of_node;
config.regmap = sreg->anatop;
rdev = devm_regulator_register(dev, rdesc, &config);
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
static int anatop_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
struct anatop_regulator *sreg = rdev_get_drvdata(rdev);
const char *name = sreg->name;
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
