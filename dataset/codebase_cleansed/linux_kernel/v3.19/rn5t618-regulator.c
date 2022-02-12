static int rn5t618_regulator_probe(struct platform_device *pdev)
{
struct rn5t618 *rn5t618 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
int i;
for (i = 0; i < RN5T618_REG_NUM; i++) {
config.dev = pdev->dev.parent;
config.regmap = rn5t618->regmap;
rdev = devm_regulator_register(&pdev->dev,
&rn5t618_regulators[i],
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register %s regulator\n",
rn5t618_regulators[i].name);
return PTR_ERR(rdev);
}
}
return 0;
}
