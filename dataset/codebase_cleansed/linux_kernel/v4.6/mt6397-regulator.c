static int mt6397_get_status(struct regulator_dev *rdev)
{
int ret;
u32 regval;
struct mt6397_regulator_info *info = rdev_get_drvdata(rdev);
ret = regmap_read(rdev->regmap, info->desc.enable_reg, &regval);
if (ret != 0) {
dev_err(&rdev->dev, "Failed to get enable reg: %d\n", ret);
return ret;
}
return (regval & info->qi) ? REGULATOR_STATUS_ON : REGULATOR_STATUS_OFF;
}
static int mt6397_set_buck_vosel_reg(struct platform_device *pdev)
{
struct mt6397_chip *mt6397 = dev_get_drvdata(pdev->dev.parent);
int i;
u32 regval;
for (i = 0; i < MT6397_MAX_REGULATOR; i++) {
if (mt6397_regulators[i].vselctrl_reg) {
if (regmap_read(mt6397->regmap,
mt6397_regulators[i].vselctrl_reg,
&regval) < 0) {
dev_err(&pdev->dev,
"Failed to read buck ctrl\n");
return -EIO;
}
if (regval & mt6397_regulators[i].vselctrl_mask) {
mt6397_regulators[i].desc.vsel_reg =
mt6397_regulators[i].vselon_reg;
}
}
}
return 0;
}
static int mt6397_regulator_probe(struct platform_device *pdev)
{
struct mt6397_chip *mt6397 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = {};
struct regulator_dev *rdev;
int i;
u32 reg_value, version;
if (mt6397_set_buck_vosel_reg(pdev))
return -EIO;
if (regmap_read(mt6397->regmap, MT6397_CID, &reg_value) < 0) {
dev_err(&pdev->dev, "Failed to read Chip ID\n");
return -EIO;
}
dev_info(&pdev->dev, "Chip ID = 0x%x\n", reg_value);
version = (reg_value & 0xFF);
switch (version) {
case MT6397_REGULATOR_ID91:
mt6397_regulators[MT6397_ID_VGP2].desc.volt_table =
ldo_volt_table5_v2;
break;
default:
break;
}
for (i = 0; i < MT6397_MAX_REGULATOR; i++) {
config.dev = &pdev->dev;
config.driver_data = &mt6397_regulators[i];
config.regmap = mt6397->regmap;
rdev = devm_regulator_register(&pdev->dev,
&mt6397_regulators[i].desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register %s\n",
mt6397_regulators[i].desc.name);
return PTR_ERR(rdev);
}
}
return 0;
}
