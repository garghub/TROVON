static int tps65217_vsel_to_uv1(unsigned int vsel)
{
int uV = 0;
if (vsel > 63)
return -EINVAL;
if (vsel <= 24)
uV = vsel * 25000 + 900000;
else if (vsel <= 52)
uV = (vsel - 24) * 50000 + 1500000;
else if (vsel < 56)
uV = (vsel - 52) * 100000 + 2900000;
else
uV = 3300000;
return uV;
}
static int tps65217_uv_to_vsel1(int uV, unsigned int *vsel)
{
if ((uV < 0) && (uV > 3300000))
return -EINVAL;
if (uV <= 1500000)
*vsel = DIV_ROUND_UP(uV - 900000, 25000);
else if (uV <= 2900000)
*vsel = 24 + DIV_ROUND_UP(uV - 1500000, 50000);
else if (uV < 3300000)
*vsel = 52 + DIV_ROUND_UP(uV - 2900000, 100000);
else
*vsel = 56;
return 0;
}
static int tps65217_vsel_to_uv2(unsigned int vsel)
{
int uV = 0;
if (vsel > 31)
return -EINVAL;
if (vsel <= 8)
uV = vsel * 50000 + 1500000;
else if (vsel <= 13)
uV = (vsel - 8) * 100000 + 1900000;
else
uV = (vsel - 13) * 50000 + 2400000;
return uV;
}
static int tps65217_uv_to_vsel2(int uV, unsigned int *vsel)
{
if ((uV < 0) && (uV > 3300000))
return -EINVAL;
if (uV <= 1900000)
*vsel = DIV_ROUND_UP(uV - 1500000, 50000);
else if (uV <= 2400000)
*vsel = 8 + DIV_ROUND_UP(uV - 1900000, 100000);
else
*vsel = 13 + DIV_ROUND_UP(uV - 2400000, 50000);
return 0;
}
static int tps65217_pmic_is_enabled(struct regulator_dev *dev)
{
int ret;
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int data, rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
ret = tps65217_reg_read(tps, TPS65217_REG_ENABLE, &data);
if (ret)
return ret;
return (data & tps->info[rid]->enable_mask) ? 1 : 0;
}
static int tps65217_pmic_enable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
return tps65217_set_bits(tps, TPS65217_REG_ENABLE,
tps->info[rid]->enable_mask,
tps->info[rid]->enable_mask,
TPS65217_PROTECT_L1);
}
static int tps65217_pmic_disable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
return tps65217_clear_bits(tps, TPS65217_REG_ENABLE,
tps->info[rid]->enable_mask, TPS65217_PROTECT_L1);
}
static int tps65217_pmic_get_voltage_sel(struct regulator_dev *dev)
{
int ret;
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int selector, rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
ret = tps65217_reg_read(tps, tps->info[rid]->set_vout_reg, &selector);
if (ret)
return ret;
selector &= tps->info[rid]->set_vout_mask;
return selector;
}
static int tps65217_pmic_ldo1_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
int ldo = rdev_get_id(dev);
if (ldo != TPS65217_LDO_1)
return -EINVAL;
if (selector >= tps->info[ldo]->table_len)
return -EINVAL;
return tps65217_set_bits(tps, tps->info[ldo]->set_vout_reg,
tps->info[ldo]->set_vout_mask,
selector, TPS65217_PROTECT_L2);
}
static int tps65217_pmic_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV, unsigned *selector)
{
int ret;
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid == TPS65217_LDO_1)
return -EINVAL;
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
if (min_uV < tps->info[rid]->min_uV
|| min_uV > tps->info[rid]->max_uV)
return -EINVAL;
if (max_uV < tps->info[rid]->min_uV
|| max_uV > tps->info[rid]->max_uV)
return -EINVAL;
ret = tps->info[rid]->uv_to_vsel(min_uV, selector);
if (ret)
return ret;
ret = tps65217_set_bits(tps, tps->info[rid]->set_vout_reg,
tps->info[rid]->set_vout_mask,
*selector, TPS65217_PROTECT_L2);
switch (rid) {
case TPS65217_DCDC_1 ... TPS65217_DCDC_3:
ret = tps65217_set_bits(tps, TPS65217_REG_DEFSLEW,
TPS65217_DEFSLEW_GO, TPS65217_DEFSLEW_GO,
TPS65217_PROTECT_L2);
break;
}
return ret;
}
static int tps65217_pmic_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
if (selector >= tps->info[rid]->table_len)
return -EINVAL;
if (tps->info[rid]->table)
return tps->info[rid]->table[selector];
return tps->info[rid]->vsel_to_uv(selector);
}
static int __devinit tps65217_regulator_probe(struct platform_device *pdev)
{
struct regulator_dev *rdev;
struct tps65217 *tps;
struct tps_info *info = &tps65217_pmic_regs[pdev->id];
tps = dev_to_tps65217(pdev->dev.parent);
tps->info[pdev->id] = info;
rdev = regulator_register(&regulators[pdev->id], &pdev->dev,
pdev->dev.platform_data, tps, NULL);
if (IS_ERR(rdev))
return PTR_ERR(rdev);
platform_set_drvdata(pdev, rdev);
return 0;
}
static int __devexit tps65217_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(rdev);
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
