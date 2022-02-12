static int bd9571mwv_avs_get_moni_state(struct regulator_dev *rdev)
{
unsigned int val;
int ret;
ret = regmap_read(rdev->regmap, BD9571MWV_AVS_SET_MONI, &val);
if (ret != 0)
return ret;
return val & BD9571MWV_AVS_SET_MONI_MASK;
}
static int bd9571mwv_avs_set_voltage_sel_regmap(struct regulator_dev *rdev,
unsigned int sel)
{
int ret;
ret = bd9571mwv_avs_get_moni_state(rdev);
if (ret < 0)
return ret;
return regmap_write_bits(rdev->regmap, BD9571MWV_AVS_VD09_VID(ret),
rdev->desc->vsel_mask, sel);
}
static int bd9571mwv_avs_get_voltage_sel_regmap(struct regulator_dev *rdev)
{
unsigned int val;
int ret;
ret = bd9571mwv_avs_get_moni_state(rdev);
if (ret < 0)
return ret;
ret = regmap_read(rdev->regmap, BD9571MWV_AVS_VD09_VID(ret), &val);
if (ret != 0)
return ret;
val &= rdev->desc->vsel_mask;
val >>= ffs(rdev->desc->vsel_mask) - 1;
return val;
}
static int bd9571mwv_reg_set_voltage_sel_regmap(struct regulator_dev *rdev,
unsigned int sel)
{
return regmap_write_bits(rdev->regmap, BD9571MWV_DVFS_SETVID,
rdev->desc->vsel_mask, sel);
}
static int bd9571mwv_regulator_probe(struct platform_device *pdev)
{
struct bd9571mwv *bd = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct regulator_dev *rdev;
int i;
platform_set_drvdata(pdev, bd);
config.dev = &pdev->dev;
config.dev->of_node = bd->dev->of_node;
config.driver_data = bd;
config.regmap = bd->regmap;
for (i = 0; i < ARRAY_SIZE(regulators); i++) {
rdev = devm_regulator_register(&pdev->dev, &regulators[i],
&config);
if (IS_ERR(rdev)) {
dev_err(bd->dev, "failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
}
return 0;
}
