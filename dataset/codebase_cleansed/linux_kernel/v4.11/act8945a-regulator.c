static int act8945a_pmic_probe(struct platform_device *pdev)
{
struct regulator_config config = { };
const struct regulator_desc *regulators;
struct regulator_dev *rdev;
int i, num_regulators;
bool voltage_select;
voltage_select = of_property_read_bool(pdev->dev.parent->of_node,
"active-semi,vsel-high");
if (voltage_select) {
regulators = act8945a_alt_regulators;
num_regulators = ARRAY_SIZE(act8945a_alt_regulators);
} else {
regulators = act8945a_regulators;
num_regulators = ARRAY_SIZE(act8945a_regulators);
}
config.dev = &pdev->dev;
config.dev->of_node = pdev->dev.parent->of_node;
for (i = 0; i < num_regulators; i++) {
rdev = devm_regulator_register(&pdev->dev, &regulators[i], &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"failed to register %s regulator\n",
regulators[i].name);
return PTR_ERR(rdev);
}
}
return 0;
}
