static int tps65217_pmic_enable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
return tps65217_set_bits(tps, TPS65217_REG_ENABLE,
dev->desc->enable_mask, dev->desc->enable_mask,
TPS65217_PROTECT_L1);
}
static int tps65217_pmic_disable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
return tps65217_clear_bits(tps, TPS65217_REG_ENABLE,
dev->desc->enable_mask, TPS65217_PROTECT_L1);
}
static int tps65217_pmic_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
int ret;
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
ret = tps65217_set_bits(tps, dev->desc->vsel_reg, dev->desc->vsel_mask,
selector, TPS65217_PROTECT_L2);
switch (rid) {
case TPS65217_DCDC_1 ... TPS65217_DCDC_3:
ret = tps65217_set_bits(tps, TPS65217_REG_DEFSLEW,
TPS65217_DEFSLEW_GO, TPS65217_DEFSLEW_GO,
TPS65217_PROTECT_L2);
break;
}
return ret;
}
static int tps65217_pmic_set_suspend_enable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
return tps65217_clear_bits(tps, dev->desc->bypass_reg,
dev->desc->bypass_mask,
TPS65217_PROTECT_L1);
}
static int tps65217_pmic_set_suspend_disable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
if (!tps->strobes[rid])
return -EINVAL;
return tps65217_set_bits(tps, dev->desc->bypass_reg,
dev->desc->bypass_mask,
tps->strobes[rid], TPS65217_PROTECT_L1);
}
static int tps65217_regulator_probe(struct platform_device *pdev)
{
struct tps65217 *tps = dev_get_drvdata(pdev->dev.parent);
struct tps65217_board *pdata = dev_get_platdata(tps->dev);
struct regulator_dev *rdev;
struct regulator_config config = { };
int i, ret;
unsigned int val;
if (tps65217_chip_id(tps) != TPS65217) {
dev_err(&pdev->dev, "Invalid tps chip version\n");
return -ENODEV;
}
tps->strobes = devm_kzalloc(&pdev->dev, sizeof(u8) *
TPS65217_NUM_REGULATOR, GFP_KERNEL);
platform_set_drvdata(pdev, tps);
for (i = 0; i < TPS65217_NUM_REGULATOR; i++) {
config.dev = tps->dev;
if (pdata)
config.init_data = pdata->tps65217_init_data[i];
config.driver_data = tps;
config.regmap = tps->regmap;
rdev = devm_regulator_register(&pdev->dev, &regulators[i],
&config);
if (IS_ERR(rdev)) {
dev_err(tps->dev, "failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
ret = tps65217_reg_read(tps, regulators[i].bypass_reg, &val);
tps->strobes[i] = val & regulators[i].bypass_mask;
}
return 0;
}
static int __init tps65217_regulator_init(void)
{
return platform_driver_register(&tps65217_regulator_driver);
}
static void __exit tps65217_regulator_exit(void)
{
platform_driver_unregister(&tps65217_regulator_driver);
}
