static int mt6323_get_status(struct regulator_dev *rdev)
{
int ret;
u32 regval;
struct mt6323_regulator_info *info = rdev_get_drvdata(rdev);
ret = regmap_read(rdev->regmap, info->desc.enable_reg, &regval);
if (ret != 0) {
dev_err(&rdev->dev, "Failed to get enable reg: %d\n", ret);
return ret;
}
return (regval & info->qi) ? REGULATOR_STATUS_ON : REGULATOR_STATUS_OFF;
}
static int mt6323_ldo_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
int ret, val = 0;
struct mt6323_regulator_info *info = rdev_get_drvdata(rdev);
if (!info->modeset_mask) {
dev_err(&rdev->dev, "regulator %s doesn't support set_mode\n",
info->desc.name);
return -EINVAL;
}
switch (mode) {
case REGULATOR_MODE_STANDBY:
val = MT6323_LDO_MODE_LP;
break;
case REGULATOR_MODE_NORMAL:
val = MT6323_LDO_MODE_NORMAL;
break;
default:
return -EINVAL;
}
val <<= ffs(info->modeset_mask) - 1;
ret = regmap_update_bits(rdev->regmap, info->modeset_reg,
info->modeset_mask, val);
return ret;
}
static unsigned int mt6323_ldo_get_mode(struct regulator_dev *rdev)
{
unsigned int val;
unsigned int mode;
int ret;
struct mt6323_regulator_info *info = rdev_get_drvdata(rdev);
if (!info->modeset_mask) {
dev_err(&rdev->dev, "regulator %s doesn't support get_mode\n",
info->desc.name);
return -EINVAL;
}
ret = regmap_read(rdev->regmap, info->modeset_reg, &val);
if (ret < 0)
return ret;
val &= info->modeset_mask;
val >>= ffs(info->modeset_mask) - 1;
if (val & 0x1)
mode = REGULATOR_MODE_STANDBY;
else
mode = REGULATOR_MODE_NORMAL;
return mode;
}
static int mt6323_set_buck_vosel_reg(struct platform_device *pdev)
{
struct mt6397_chip *mt6323 = dev_get_drvdata(pdev->dev.parent);
int i;
u32 regval;
for (i = 0; i < MT6323_MAX_REGULATOR; i++) {
if (mt6323_regulators[i].vselctrl_reg) {
if (regmap_read(mt6323->regmap,
mt6323_regulators[i].vselctrl_reg,
&regval) < 0) {
dev_err(&pdev->dev,
"Failed to read buck ctrl\n");
return -EIO;
}
if (regval & mt6323_regulators[i].vselctrl_mask) {
mt6323_regulators[i].desc.vsel_reg =
mt6323_regulators[i].vselon_reg;
}
}
}
return 0;
}
static int mt6323_regulator_probe(struct platform_device *pdev)
{
struct mt6397_chip *mt6323 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = {};
struct regulator_dev *rdev;
int i;
u32 reg_value;
if (mt6323_set_buck_vosel_reg(pdev))
return -EIO;
if (regmap_read(mt6323->regmap, MT6323_CID, &reg_value) < 0) {
dev_err(&pdev->dev, "Failed to read Chip ID\n");
return -EIO;
}
dev_info(&pdev->dev, "Chip ID = 0x%x\n", reg_value);
for (i = 0; i < MT6323_MAX_REGULATOR; i++) {
config.dev = &pdev->dev;
config.driver_data = &mt6323_regulators[i];
config.regmap = mt6323->regmap;
rdev = devm_regulator_register(&pdev->dev,
&mt6323_regulators[i].desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register %s\n",
mt6323_regulators[i].desc.name);
return PTR_ERR(rdev);
}
}
return 0;
}
