static int rn5t618_regulator_probe(struct platform_device *pdev)
{
struct rn5t618 *rn5t618 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
struct regulator_desc *regulators;
int i;
int num_regulators = 0;
switch (rn5t618->variant) {
case RN5T567:
regulators = rn5t567_regulators;
num_regulators = ARRAY_SIZE(rn5t567_regulators);
break;
case RN5T618:
regulators = rn5t618_regulators;
num_regulators = ARRAY_SIZE(rn5t618_regulators);
break;
case RC5T619:
regulators = rc5t619_regulators;
num_regulators = ARRAY_SIZE(rc5t619_regulators);
break;
default:
return -EINVAL;
}
config.dev = pdev->dev.parent;
config.regmap = rn5t618->regmap;
for (i = 0; i < num_regulators; i++) {
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
