static int mt6380_regulator_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
int ret, val = 0;
struct mt6380_regulator_info *info = rdev_get_drvdata(rdev);
switch (mode) {
case REGULATOR_MODE_NORMAL:
val = MT6380_REGULATOR_MODE_AUTO;
break;
case REGULATOR_MODE_FAST:
val = MT6380_REGULATOR_MODE_FORCE_PWM;
break;
default:
return -EINVAL;
}
val <<= ffs(info->modeset_mask) - 1;
ret = regmap_update_bits(rdev->regmap, info->modeset_reg,
info->modeset_mask, val);
return ret;
}
static unsigned int mt6380_regulator_get_mode(struct regulator_dev *rdev)
{
unsigned int val;
unsigned int mode;
int ret;
struct mt6380_regulator_info *info = rdev_get_drvdata(rdev);
ret = regmap_read(rdev->regmap, info->modeset_reg, &val);
if (ret < 0)
return ret;
val &= info->modeset_mask;
val >>= ffs(info->modeset_mask) - 1;
switch (val) {
case MT6380_REGULATOR_MODE_AUTO:
mode = REGULATOR_MODE_NORMAL;
break;
case MT6380_REGULATOR_MODE_FORCE_PWM:
mode = REGULATOR_MODE_FAST;
break;
default:
return -EINVAL;
}
return mode;
}
static int mt6380_regulator_probe(struct platform_device *pdev)
{
struct regmap *regmap = dev_get_regmap(pdev->dev.parent, NULL);
struct regulator_config config = {};
struct regulator_dev *rdev;
int i;
for (i = 0; i < MT6380_MAX_REGULATOR; i++) {
config.dev = &pdev->dev;
config.driver_data = &mt6380_regulators[i];
config.regmap = regmap;
rdev = devm_regulator_register(&pdev->dev,
&mt6380_regulators[i].desc,
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register %s\n",
mt6380_regulators[i].desc.name);
return PTR_ERR(rdev);
}
}
return 0;
}
