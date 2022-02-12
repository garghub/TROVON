static int hi655x_is_enabled(struct regulator_dev *rdev)
{
unsigned int value = 0;
struct hi655x_regulator *regulator = rdev_get_drvdata(rdev);
regmap_read(rdev->regmap, regulator->status_reg, &value);
return (value & BIT(regulator->ctrl_mask));
}
static int hi655x_disable(struct regulator_dev *rdev)
{
int ret = 0;
struct hi655x_regulator *regulator = rdev_get_drvdata(rdev);
ret = regmap_write(rdev->regmap, regulator->disable_reg,
BIT(regulator->ctrl_mask));
return ret;
}
static int hi655x_regulator_probe(struct platform_device *pdev)
{
unsigned int i;
struct hi655x_regulator *regulator;
struct hi655x_pmic *pmic;
struct regulator_config config = { };
struct regulator_dev *rdev;
pmic = dev_get_drvdata(pdev->dev.parent);
if (!pmic) {
dev_err(&pdev->dev, "no pmic in the regulator parent node\n");
return -ENODEV;
}
regulator = devm_kzalloc(&pdev->dev, sizeof(*regulator), GFP_KERNEL);
if (!regulator)
return -ENOMEM;
platform_set_drvdata(pdev, regulator);
config.dev = pdev->dev.parent;
config.regmap = pmic->regmap;
config.driver_data = regulator;
for (i = 0; i < ARRAY_SIZE(regulators); i++) {
rdev = devm_regulator_register(&pdev->dev,
&regulators[i].rdesc,
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
regulator->rdesc.name);
return PTR_ERR(rdev);
}
}
return 0;
}
