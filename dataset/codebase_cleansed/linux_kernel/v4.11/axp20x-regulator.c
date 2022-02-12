static int axp20x_set_dcdc_freq(struct platform_device *pdev, u32 dcdcfreq)
{
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
unsigned int reg = AXP20X_DCDC_FREQ;
u32 min, max, def, step;
switch (axp20x->variant) {
case AXP202_ID:
case AXP209_ID:
min = 750;
max = 1875;
def = 1500;
step = 75;
break;
case AXP806_ID:
reg = AXP806_DCDC_FREQ_CTRL;
case AXP221_ID:
case AXP223_ID:
case AXP809_ID:
min = 1800;
max = 4050;
def = 3000;
step = 150;
break;
default:
dev_err(&pdev->dev,
"Setting DCDC frequency for unsupported AXP variant\n");
return -EINVAL;
}
if (dcdcfreq == 0)
dcdcfreq = def;
if (dcdcfreq < min) {
dcdcfreq = min;
dev_warn(&pdev->dev, "DCDC frequency too low. Set to %ukHz\n",
min);
}
if (dcdcfreq > max) {
dcdcfreq = max;
dev_warn(&pdev->dev, "DCDC frequency too high. Set to %ukHz\n",
max);
}
dcdcfreq = (dcdcfreq - min) / step;
return regmap_update_bits(axp20x->regmap, reg,
AXP20X_FREQ_DCDC_MASK, dcdcfreq);
}
static int axp20x_regulator_parse_dt(struct platform_device *pdev)
{
struct device_node *np, *regulators;
int ret;
u32 dcdcfreq = 0;
np = of_node_get(pdev->dev.parent->of_node);
if (!np)
return 0;
regulators = of_get_child_by_name(np, "regulators");
if (!regulators) {
dev_warn(&pdev->dev, "regulators node not found\n");
} else {
of_property_read_u32(regulators, "x-powers,dcdc-freq", &dcdcfreq);
ret = axp20x_set_dcdc_freq(pdev, dcdcfreq);
if (ret < 0) {
dev_err(&pdev->dev, "Error setting dcdc frequency: %d\n", ret);
return ret;
}
of_node_put(regulators);
}
return 0;
}
static int axp20x_set_dcdc_workmode(struct regulator_dev *rdev, int id, u32 workmode)
{
struct axp20x_dev *axp20x = rdev_get_drvdata(rdev);
unsigned int reg = AXP20X_DCDC_MODE;
unsigned int mask;
switch (axp20x->variant) {
case AXP202_ID:
case AXP209_ID:
if ((id != AXP20X_DCDC2) && (id != AXP20X_DCDC3))
return -EINVAL;
mask = AXP20X_WORKMODE_DCDC2_MASK;
if (id == AXP20X_DCDC3)
mask = AXP20X_WORKMODE_DCDC3_MASK;
workmode <<= ffs(mask) - 1;
break;
case AXP806_ID:
reg = AXP806_DCDC_MODE_CTRL2;
case AXP221_ID:
case AXP223_ID:
case AXP809_ID:
if (id < AXP22X_DCDC1 || id > AXP22X_DCDC5)
return -EINVAL;
mask = AXP22X_WORKMODE_DCDCX_MASK(id - AXP22X_DCDC1);
workmode <<= id - AXP22X_DCDC1;
break;
default:
WARN_ON(1);
return -EINVAL;
}
return regmap_update_bits(rdev->regmap, reg, mask, workmode);
}
static bool axp20x_is_polyphase_slave(struct axp20x_dev *axp20x, int id)
{
u32 reg = 0;
if (axp20x->variant != AXP806_ID)
return false;
regmap_read(axp20x->regmap, AXP806_DCDC_MODE_CTRL2, &reg);
switch (id) {
case AXP806_DCDCB:
return (((reg & GENMASK(7, 6)) == BIT(6)) ||
((reg & GENMASK(7, 6)) == BIT(7)));
case AXP806_DCDCC:
return ((reg & GENMASK(7, 6)) == BIT(7));
case AXP806_DCDCE:
return !!(reg & BIT(5));
}
return false;
}
static int axp20x_regulator_probe(struct platform_device *pdev)
{
struct regulator_dev *rdev;
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
const struct regulator_desc *regulators;
struct regulator_config config = {
.dev = pdev->dev.parent,
.regmap = axp20x->regmap,
.driver_data = axp20x,
};
int ret, i, nregulators;
u32 workmode;
const char *dcdc1_name = axp22x_regulators[AXP22X_DCDC1].name;
const char *dcdc5_name = axp22x_regulators[AXP22X_DCDC5].name;
bool drivevbus = false;
switch (axp20x->variant) {
case AXP202_ID:
case AXP209_ID:
regulators = axp20x_regulators;
nregulators = AXP20X_REG_ID_MAX;
break;
case AXP221_ID:
case AXP223_ID:
regulators = axp22x_regulators;
nregulators = AXP22X_REG_ID_MAX;
drivevbus = of_property_read_bool(pdev->dev.parent->of_node,
"x-powers,drive-vbus-en");
break;
case AXP806_ID:
regulators = axp806_regulators;
nregulators = AXP806_REG_ID_MAX;
break;
case AXP809_ID:
regulators = axp809_regulators;
nregulators = AXP809_REG_ID_MAX;
break;
default:
dev_err(&pdev->dev, "Unsupported AXP variant: %ld\n",
axp20x->variant);
return -EINVAL;
}
axp20x_regulator_parse_dt(pdev);
for (i = 0; i < nregulators; i++) {
const struct regulator_desc *desc = &regulators[i];
struct regulator_desc *new_desc;
if (axp20x_is_polyphase_slave(axp20x, i))
continue;
if ((regulators == axp22x_regulators && i == AXP22X_DC1SW) ||
(regulators == axp809_regulators && i == AXP809_DC1SW)) {
new_desc = devm_kzalloc(&pdev->dev, sizeof(*desc),
GFP_KERNEL);
*new_desc = regulators[i];
new_desc->supply_name = dcdc1_name;
desc = new_desc;
}
if ((regulators == axp22x_regulators && i == AXP22X_DC5LDO) ||
(regulators == axp809_regulators && i == AXP809_DC5LDO)) {
new_desc = devm_kzalloc(&pdev->dev, sizeof(*desc),
GFP_KERNEL);
*new_desc = regulators[i];
new_desc->supply_name = dcdc5_name;
desc = new_desc;
}
rdev = devm_regulator_register(&pdev->dev, desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "Failed to register %s\n",
regulators[i].name);
return PTR_ERR(rdev);
}
ret = of_property_read_u32(rdev->dev.of_node,
"x-powers,dcdc-workmode",
&workmode);
if (!ret) {
if (axp20x_set_dcdc_workmode(rdev, i, workmode))
dev_err(&pdev->dev, "Failed to set workmode on %s\n",
rdev->desc->name);
}
if ((regulators == axp22x_regulators && i == AXP22X_DCDC1) ||
(regulators == axp809_regulators && i == AXP809_DCDC1))
of_property_read_string(rdev->dev.of_node,
"regulator-name",
&dcdc1_name);
if ((regulators == axp22x_regulators && i == AXP22X_DCDC5) ||
(regulators == axp809_regulators && i == AXP809_DCDC5))
of_property_read_string(rdev->dev.of_node,
"regulator-name",
&dcdc5_name);
}
if (drivevbus) {
regmap_update_bits(axp20x->regmap, AXP20X_OVER_TMP,
AXP22X_MISC_N_VBUSEN_FUNC, 0);
rdev = devm_regulator_register(&pdev->dev,
&axp22x_drivevbus_regulator,
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "Failed to register drivevbus\n");
return PTR_ERR(rdev);
}
}
return 0;
}
