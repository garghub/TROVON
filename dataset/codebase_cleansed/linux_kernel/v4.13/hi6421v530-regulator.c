static unsigned int hi6421v530_regulator_ldo_get_mode(
struct regulator_dev *rdev)
{
struct hi6421v530_regulator_info *info;
unsigned int reg_val;
info = rdev_get_drvdata(rdev);
regmap_read(rdev->regmap, rdev->desc->enable_reg, &reg_val);
if (reg_val & (info->mode_mask))
return REGULATOR_MODE_IDLE;
return REGULATOR_MODE_NORMAL;
}
static int hi6421v530_regulator_ldo_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct hi6421v530_regulator_info *info;
unsigned int new_mode;
info = rdev_get_drvdata(rdev);
switch (mode) {
case REGULATOR_MODE_NORMAL:
new_mode = 0;
break;
case REGULATOR_MODE_IDLE:
new_mode = info->mode_mask;
break;
default:
return -EINVAL;
}
regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
info->mode_mask, new_mode);
return 0;
}
static int hi6421v530_regulator_probe(struct platform_device *pdev)
{
struct hi6421_pmic *pmic;
struct regulator_dev *rdev;
struct regulator_config config = { };
unsigned int i;
pmic = dev_get_drvdata(pdev->dev.parent);
if (!pmic) {
dev_err(&pdev->dev, "no pmic in the regulator parent node\n");
return -ENODEV;
}
for (i = 0; i < ARRAY_SIZE(hi6421v530_regulator_info); i++) {
config.dev = pdev->dev.parent;
config.regmap = pmic->regmap;
config.driver_data = &hi6421v530_regulator_info[i];
rdev = devm_regulator_register(&pdev->dev,
&hi6421v530_regulator_info[i].rdesc,
&config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
hi6421v530_regulator_info[i].rdesc.name);
return PTR_ERR(rdev);
}
}
return 0;
}
