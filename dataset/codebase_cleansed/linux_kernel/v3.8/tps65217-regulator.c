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
if (uV < 0 || uV > 3300000)
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
if (uV < 0 || uV > 3300000)
return -EINVAL;
if (uV <= 1900000)
*vsel = DIV_ROUND_UP(uV - 1500000, 50000);
else if (uV <= 2400000)
*vsel = 8 + DIV_ROUND_UP(uV - 1900000, 100000);
else
*vsel = 13 + DIV_ROUND_UP(uV - 2400000, 50000);
return 0;
}
static int tps65217_pmic_enable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
return tps65217_set_bits(tps, TPS65217_REG_ENABLE,
dev->desc->enable_mask, dev->desc->enable_mask,
TPS65217_PROTECT_L1);
}
static int tps65217_pmic_disable(struct regulator_dev *dev)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
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
static int tps65217_pmic_map_voltage(struct regulator_dev *dev,
int min_uV, int max_uV)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int sel, rid = rdev_get_id(dev);
int ret;
if (rid == TPS65217_LDO_1)
return -EINVAL;
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
if (min_uV < tps->info[rid]->min_uV)
min_uV = tps->info[rid]->min_uV;
if (max_uV < tps->info[rid]->min_uV || min_uV > tps->info[rid]->max_uV)
return -EINVAL;
ret = tps->info[rid]->uv_to_vsel(min_uV, &sel);
if (ret)
return ret;
return sel;
}
static int tps65217_pmic_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct tps65217 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65217_DCDC_1 || rid > TPS65217_LDO_4)
return -EINVAL;
if (selector >= dev->desc->n_voltages)
return -EINVAL;
return tps->info[rid]->vsel_to_uv(selector);
}
static struct tps65217_board *tps65217_parse_dt(struct platform_device *pdev)
{
struct tps65217 *tps = dev_get_drvdata(pdev->dev.parent);
struct device_node *node = tps->dev->of_node;
struct tps65217_board *pdata;
struct device_node *regs;
int i, count;
regs = of_find_node_by_name(node, "regulators");
if (!regs)
return NULL;
count = of_regulator_match(&pdev->dev, regs, reg_matches,
TPS65217_NUM_REGULATOR);
of_node_put(regs);
if ((count < 0) || (count > TPS65217_NUM_REGULATOR))
return NULL;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
for (i = 0; i < count; i++) {
if (!reg_matches[i].init_data || !reg_matches[i].of_node)
continue;
pdata->tps65217_init_data[i] = reg_matches[i].init_data;
pdata->of_node[i] = reg_matches[i].of_node;
}
return pdata;
}
static struct tps65217_board *tps65217_parse_dt(struct platform_device *pdev)
{
return NULL;
}
static int tps65217_regulator_probe(struct platform_device *pdev)
{
struct tps65217 *tps = dev_get_drvdata(pdev->dev.parent);
struct tps65217_board *pdata = dev_get_platdata(tps->dev);
struct regulator_init_data *reg_data;
struct regulator_dev *rdev;
struct regulator_config config = { };
int i, ret;
if (tps->dev->of_node)
pdata = tps65217_parse_dt(pdev);
if (!pdata) {
dev_err(&pdev->dev, "Platform data not found\n");
return -EINVAL;
}
if (tps65217_chip_id(tps) != TPS65217) {
dev_err(&pdev->dev, "Invalid tps chip version\n");
return -ENODEV;
}
platform_set_drvdata(pdev, tps);
for (i = 0; i < TPS65217_NUM_REGULATOR; i++) {
reg_data = pdata->tps65217_init_data[i];
if (!reg_data)
continue;
tps->info[i] = &tps65217_pmic_regs[i];
config.dev = tps->dev;
config.init_data = reg_data;
config.driver_data = tps;
config.regmap = tps->regmap;
if (tps->dev->of_node)
config.of_node = pdata->of_node[i];
rdev = regulator_register(&regulators[i], &config);
if (IS_ERR(rdev)) {
dev_err(tps->dev, "failed to register %s regulator\n",
pdev->name);
ret = PTR_ERR(rdev);
goto err_unregister_regulator;
}
tps->rdev[i] = rdev;
}
return 0;
err_unregister_regulator:
while (--i >= 0)
regulator_unregister(tps->rdev[i]);
return ret;
}
static int tps65217_regulator_remove(struct platform_device *pdev)
{
struct tps65217 *tps = platform_get_drvdata(pdev);
unsigned int i;
for (i = 0; i < TPS65217_NUM_REGULATOR; i++)
regulator_unregister(tps->rdev[i]);
platform_set_drvdata(pdev, NULL);
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
