static int tps65912_regulator_probe(struct platform_device *pdev)
{
struct tps65912 *tps = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
int i;
platform_set_drvdata(pdev, tps);
config.dev = &pdev->dev;
config.driver_data = tps;
config.dev->of_node = tps->dev->of_node;
config.regmap = tps->regmap;
for (i = 0; i < ARRAY_SIZE(regulators); i++) {
rdev = devm_regulator_register(&pdev->dev, &regulators[i],
&config);
if (IS_ERR(rdev)) {
dev_err(tps->dev, "failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
}
return 0;
}
