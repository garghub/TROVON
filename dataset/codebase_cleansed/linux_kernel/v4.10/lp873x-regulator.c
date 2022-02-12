static int lp873x_buck_set_ramp_delay(struct regulator_dev *rdev,
int ramp_delay)
{
int id = rdev_get_id(rdev);
struct lp873x *lp873 = rdev_get_drvdata(rdev);
unsigned int reg;
int ret;
if (ramp_delay <= 470)
reg = 7;
else if (ramp_delay <= 940)
reg = 6;
else if (ramp_delay <= 1900)
reg = 5;
else if (ramp_delay <= 3800)
reg = 4;
else if (ramp_delay <= 7500)
reg = 3;
else if (ramp_delay <= 10000)
reg = 2;
else if (ramp_delay <= 15000)
reg = 1;
else
reg = 0;
ret = regmap_update_bits(lp873->regmap, regulators[id].ctrl2_reg,
LP873X_BUCK0_CTRL_2_BUCK0_SLEW_RATE,
reg << __ffs(LP873X_BUCK0_CTRL_2_BUCK0_SLEW_RATE));
if (ret) {
dev_err(lp873->dev, "SLEW RATE write failed: %d\n", ret);
return ret;
}
rdev->constraints->ramp_delay = lp873x_buck_ramp_delay[reg];
return 0;
}
static int lp873x_buck_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
int id = rdev_get_id(rdev);
struct lp873x *lp873 = rdev_get_drvdata(rdev);
int i;
for (i = ARRAY_SIZE(lp873x_buck_uA) - 1; i >= 0; i--) {
if (lp873x_buck_uA[i] >= min_uA &&
lp873x_buck_uA[i] <= max_uA)
return regmap_update_bits(lp873->regmap,
regulators[id].ctrl2_reg,
LP873X_BUCK0_CTRL_2_BUCK0_ILIM,
i << __ffs(LP873X_BUCK0_CTRL_2_BUCK0_ILIM));
}
return -EINVAL;
}
static int lp873x_buck_get_current_limit(struct regulator_dev *rdev)
{
int id = rdev_get_id(rdev);
struct lp873x *lp873 = rdev_get_drvdata(rdev);
int ret;
unsigned int val;
ret = regmap_read(lp873->regmap, regulators[id].ctrl2_reg, &val);
if (ret)
return ret;
val = (val & LP873X_BUCK0_CTRL_2_BUCK0_ILIM) >>
__ffs(LP873X_BUCK0_CTRL_2_BUCK0_ILIM);
return (val < ARRAY_SIZE(lp873x_buck_uA)) ?
lp873x_buck_uA[val] : -EINVAL;
}
static int lp873x_regulator_probe(struct platform_device *pdev)
{
struct lp873x *lp873 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
int i;
platform_set_drvdata(pdev, lp873);
config.dev = &pdev->dev;
config.dev->of_node = lp873->dev->of_node;
config.driver_data = lp873;
config.regmap = lp873->regmap;
for (i = 0; i < ARRAY_SIZE(regulators); i++) {
rdev = devm_regulator_register(&pdev->dev, &regulators[i].desc,
&config);
if (IS_ERR(rdev)) {
dev_err(lp873->dev, "failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
}
return 0;
}
