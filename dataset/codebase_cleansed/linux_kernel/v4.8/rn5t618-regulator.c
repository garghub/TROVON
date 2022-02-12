static int rn5t618_regulator_probe(struct platform_device *pdev)
{
struct rn5t618 *rn5t618 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
struct regulator_desc *regulators;
int i;
switch (rn5t618->variant) {
case RN5T567:
regulators = rn5t567_regulators;
break;
case RN5T618:
regulators = rn5t618_regulators;
break;
default:
return -EINVAL;
}
config.dev = pdev->dev.parent;
config.regmap = rn5t618->regmap;
for (i = 0; i < RN5T618_REG_NUM; i++) {
if (!regulators[i].name)
continue;
rdev = devm_regulator_register(&pdev->dev,
&regulators[i],
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register %s regulator\n",
regulators[i].name);
return PTR_ERR(rdev);
}
}
return 0;
}
