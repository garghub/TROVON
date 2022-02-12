static int axp20x_set_dcdc_freq(struct platform_device *pdev, u32 dcdcfreq)
{
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
if (dcdcfreq < 750) {
dcdcfreq = 750;
dev_warn(&pdev->dev, "DCDC frequency too low. Set to 750kHz\n");
}
if (dcdcfreq > 1875) {
dcdcfreq = 1875;
dev_warn(&pdev->dev, "DCDC frequency too high. Set to 1875kHz\n");
}
dcdcfreq = (dcdcfreq - 750) / 75;
return regmap_update_bits(axp20x->regmap, AXP20X_DCDC_FREQ,
AXP20X_FREQ_DCDC_MASK, dcdcfreq);
}
static int axp20x_regulator_parse_dt(struct platform_device *pdev)
{
struct device_node *np, *regulators;
int ret;
u32 dcdcfreq;
np = of_node_get(pdev->dev.parent->of_node);
if (!np)
return 0;
regulators = of_get_child_by_name(np, "regulators");
if (!regulators) {
dev_warn(&pdev->dev, "regulators node not found\n");
} else {
ret = of_regulator_match(&pdev->dev, regulators, axp20x_matches,
ARRAY_SIZE(axp20x_matches));
if (ret < 0) {
dev_err(&pdev->dev, "Error parsing regulator init data: %d\n", ret);
return ret;
}
dcdcfreq = 1500;
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
unsigned int mask = AXP20X_WORKMODE_DCDC2_MASK;
if ((id != AXP20X_DCDC2) && (id != AXP20X_DCDC3))
return -EINVAL;
if (id == AXP20X_DCDC3)
mask = AXP20X_WORKMODE_DCDC3_MASK;
workmode <<= ffs(mask) - 1;
return regmap_update_bits(rdev->regmap, AXP20X_DCDC_MODE, mask, workmode);
}
static int axp20x_regulator_probe(struct platform_device *pdev)
{
struct regulator_dev *rdev;
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_init_data *init_data;
int ret, i;
u32 workmode;
ret = axp20x_regulator_parse_dt(pdev);
if (ret)
return ret;
for (i = 0; i < AXP20X_REG_ID_MAX; i++) {
init_data = axp20x_matches[i].init_data;
config.dev = &pdev->dev;
config.init_data = init_data;
config.regmap = axp20x->regmap;
config.of_node = axp20x_matches[i].of_node;
rdev = devm_regulator_register(&pdev->dev, &axp20x_regulators[i],
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "Failed to register %s\n",
axp20x_regulators[i].name);
return PTR_ERR(rdev);
}
ret = of_property_read_u32(axp20x_matches[i].of_node, "x-powers,dcdc-workmode",
&workmode);
if (!ret) {
if (axp20x_set_dcdc_workmode(rdev, i, workmode))
dev_err(&pdev->dev, "Failed to set workmode on %s\n",
axp20x_regulators[i].name);
}
}
return 0;
}
