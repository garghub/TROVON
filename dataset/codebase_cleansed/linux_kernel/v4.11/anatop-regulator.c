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
static int anatop_regmap_enable(struct regulator_dev *reg)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
int sel;
sel = anatop_reg->bypass ? LDO_FET_FULL_ON : anatop_reg->sel;
return regulator_set_voltage_sel_regmap(reg, sel);
}
static int anatop_regmap_disable(struct regulator_dev *reg)
{
return regulator_set_voltage_sel_regmap(reg, LDO_POWER_GATE);
}
static int anatop_regmap_is_enabled(struct regulator_dev *reg)
{
return regulator_get_voltage_sel_regmap(reg) != LDO_POWER_GATE;
}
static int anatop_regmap_core_set_voltage_sel(struct regulator_dev *reg,
unsigned selector)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
int ret;
if (anatop_reg->bypass || !anatop_regmap_is_enabled(reg)) {
anatop_reg->sel = selector;
return 0;
}
ret = regulator_set_voltage_sel_regmap(reg, selector);
if (!ret)
anatop_reg->sel = selector;
return ret;
}
static int anatop_regmap_core_get_voltage_sel(struct regulator_dev *reg)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
if (anatop_reg->bypass || !anatop_regmap_is_enabled(reg))
return anatop_reg->sel;
return regulator_get_voltage_sel_regmap(reg);
}
static int anatop_regmap_get_bypass(struct regulator_dev *reg, bool *enable)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
int sel;
sel = regulator_get_voltage_sel_regmap(reg);
if (sel == LDO_FET_FULL_ON)
WARN_ON(!anatop_reg->bypass);
else if (sel != LDO_POWER_GATE)
WARN_ON(anatop_reg->bypass);
*enable = anatop_reg->bypass;
return 0;
}
static int anatop_regmap_set_bypass(struct regulator_dev *reg, bool enable)
{
struct anatop_regulator *anatop_reg = rdev_get_drvdata(reg);
int sel;
if (enable == anatop_reg->bypass)
return 0;
sel = enable ? LDO_FET_FULL_ON : anatop_reg->sel;
anatop_reg->bypass = enable;
return regulator_set_voltage_sel_regmap(reg, sel);
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
u32 val;
sreg = devm_kzalloc(dev, sizeof(*sreg), GFP_KERNEL);
if (!sreg)
return -ENOMEM;
sreg->name = of_get_property(np, "regulator-name", NULL);
rdesc = &sreg->rdesc;
rdesc->name = sreg->name;
rdesc->type = REGULATOR_VOLTAGE;
rdesc->owner = THIS_MODULE;
initdata = of_get_regulator_init_data(dev, np, rdesc);
initdata->supply_regulator = "vin";
sreg->initdata = initdata;
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
return ret;
}
ret = of_property_read_u32(np, "anatop-vol-bit-width",
&sreg->vol_bit_width);
if (ret) {
dev_err(dev, "no anatop-vol-bit-width property set\n");
return ret;
}
ret = of_property_read_u32(np, "anatop-vol-bit-shift",
&sreg->vol_bit_shift);
if (ret) {
dev_err(dev, "no anatop-vol-bit-shift property set\n");
return ret;
}
ret = of_property_read_u32(np, "anatop-min-bit-val",
&sreg->min_bit_val);
if (ret) {
dev_err(dev, "no anatop-min-bit-val property set\n");
return ret;
}
ret = of_property_read_u32(np, "anatop-min-voltage",
&sreg->min_voltage);
if (ret) {
dev_err(dev, "no anatop-min-voltage property set\n");
return ret;
}
ret = of_property_read_u32(np, "anatop-max-voltage",
&sreg->max_voltage);
if (ret) {
dev_err(dev, "no anatop-max-voltage property set\n");
return ret;
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
rdesc->min_dropout_uV = 125000;
config.dev = &pdev->dev;
config.init_data = initdata;
config.driver_data = sreg;
config.of_node = pdev->dev.of_node;
config.regmap = sreg->anatop;
if (sreg->control_reg && sreg->delay_bit_width) {
rdesc->ops = &anatop_core_rops;
ret = regmap_read(config.regmap, rdesc->vsel_reg, &val);
if (ret) {
dev_err(dev, "failed to read initial state\n");
return ret;
}
sreg->sel = (val & rdesc->vsel_mask) >> sreg->vol_bit_shift;
if (sreg->sel == LDO_FET_FULL_ON) {
sreg->sel = 0;
sreg->bypass = true;
}
if (!sreg->sel && !strcmp(sreg->name, "vddpu"))
sreg->sel = 22;
if (!sreg->bypass && !sreg->sel) {
dev_err(&pdev->dev, "Failed to read a valid default voltage selector.\n");
return -EINVAL;
}
} else {
u32 enable_bit;
rdesc->ops = &anatop_rops;
if (!of_property_read_u32(np, "anatop-enable-bit",
&enable_bit)) {
anatop_rops.enable = regulator_enable_regmap;
anatop_rops.disable = regulator_disable_regmap;
anatop_rops.is_enabled = regulator_is_enabled_regmap;
rdesc->enable_reg = sreg->control_reg;
rdesc->enable_mask = BIT(enable_bit);
}
}
rdev = devm_regulator_register(dev, rdesc, &config);
if (IS_ERR(rdev)) {
dev_err(dev, "failed to register %s\n",
rdesc->name);
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
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
