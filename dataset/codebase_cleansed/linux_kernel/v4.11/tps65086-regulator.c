static int tps65086_of_parse_cb(struct device_node *node,
const struct regulator_desc *desc,
struct regulator_config *config)
{
int ret;
if (of_property_read_bool(node, "ti,regulator-step-size-25mv")) {
switch (desc->id) {
case BUCK1:
case BUCK2:
case BUCK6:
regulators[desc->id].desc.linear_ranges =
tps65086_buck126_25mv_ranges;
regulators[desc->id].desc.n_linear_ranges =
ARRAY_SIZE(tps65086_buck126_25mv_ranges);
break;
case BUCK3:
case BUCK4:
case BUCK5:
regulators[desc->id].desc.linear_ranges =
tps65086_buck345_25mv_ranges;
regulators[desc->id].desc.n_linear_ranges =
ARRAY_SIZE(tps65086_buck345_25mv_ranges);
break;
default:
dev_warn(config->dev, "25mV step mode only valid for BUCK regulators\n");
}
}
if (desc->id <= BUCK6 && of_property_read_bool(node, "ti,regulator-decay")) {
ret = regmap_write_bits(config->regmap,
regulators[desc->id].decay_reg,
regulators[desc->id].decay_mask,
regulators[desc->id].decay_mask);
if (ret) {
dev_err(config->dev, "Error setting decay\n");
return ret;
}
}
return 0;
}
static int tps65086_regulator_probe(struct platform_device *pdev)
{
struct tps65086 *tps = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
int i;
platform_set_drvdata(pdev, tps);
config.dev = &pdev->dev;
config.dev->of_node = tps->dev->of_node;
config.driver_data = tps;
config.regmap = tps->regmap;
for (i = 0; i < ARRAY_SIZE(regulators); i++) {
rdev = devm_regulator_register(&pdev->dev, &regulators[i].desc,
&config);
if (IS_ERR(rdev)) {
dev_err(tps->dev, "failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
}
return 0;
}
