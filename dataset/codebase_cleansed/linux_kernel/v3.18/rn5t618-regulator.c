static int rn5t618_regulator_parse_dt(struct platform_device *pdev)
{
struct device_node *np, *regulators;
int ret;
np = of_node_get(pdev->dev.parent->of_node);
if (!np)
return 0;
regulators = of_get_child_by_name(np, "regulators");
if (!regulators) {
dev_err(&pdev->dev, "regulators node not found\n");
return -EINVAL;
}
ret = of_regulator_match(&pdev->dev, regulators, rn5t618_matches,
ARRAY_SIZE(rn5t618_matches));
of_node_put(regulators);
if (ret < 0) {
dev_err(&pdev->dev, "error parsing regulator init data: %d\n",
ret);
}
return 0;
}
static int rn5t618_regulator_probe(struct platform_device *pdev)
{
struct rn5t618 *rn5t618 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
int ret, i;
ret = rn5t618_regulator_parse_dt(pdev);
if (ret)
return ret;
for (i = 0; i < RN5T618_REG_NUM; i++) {
config.dev = &pdev->dev;
config.init_data = rn5t618_matches[i].init_data;
config.of_node = rn5t618_matches[i].of_node;
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
