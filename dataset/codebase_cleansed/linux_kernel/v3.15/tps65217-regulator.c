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
static struct tps65217_board *tps65217_parse_dt(struct platform_device *pdev)
{
struct tps65217 *tps = dev_get_drvdata(pdev->dev.parent);
struct device_node *node = tps->dev->of_node;
struct tps65217_board *pdata;
struct device_node *regs;
int i, count;
regs = of_get_child_by_name(node, "regulators");
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
if (!reg_matches[i].of_node)
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
struct regulator_dev *rdev;
struct regulator_config config = { };
int i;
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
config.dev = tps->dev;
config.init_data = pdata->tps65217_init_data[i];
config.driver_data = tps;
config.regmap = tps->regmap;
if (tps->dev->of_node)
config.of_node = pdata->of_node[i];
rdev = devm_regulator_register(&pdev->dev, &regulators[i],
&config);
if (IS_ERR(rdev)) {
dev_err(tps->dev, "failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
tps->rdev[i] = rdev;
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
