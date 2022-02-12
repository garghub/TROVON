static int tps65218_pmic_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
int ret;
struct tps65218 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
ret = tps65218_set_bits(tps, dev->desc->vsel_reg, dev->desc->vsel_mask,
selector, TPS65218_PROTECT_L1);
switch (rid) {
case TPS65218_DCDC_1:
case TPS65218_DCDC_2:
ret = tps65218_set_bits(tps, TPS65218_REG_CONTRL_SLEW_RATE,
TPS65218_SLEW_RATE_GO,
TPS65218_SLEW_RATE_GO,
TPS65218_PROTECT_L1);
break;
}
return ret;
}
static int tps65218_pmic_enable(struct regulator_dev *dev)
{
struct tps65218 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65218_DCDC_1 || rid > TPS65218_LDO_1)
return -EINVAL;
return tps65218_set_bits(tps, dev->desc->enable_reg,
dev->desc->enable_mask, dev->desc->enable_mask,
TPS65218_PROTECT_L1);
}
static int tps65218_pmic_disable(struct regulator_dev *dev)
{
struct tps65218 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65218_DCDC_1 || rid > TPS65218_LDO_1)
return -EINVAL;
return tps65218_clear_bits(tps, dev->desc->enable_reg,
dev->desc->enable_mask, TPS65218_PROTECT_L1);
}
static int tps65218_regulator_probe(struct platform_device *pdev)
{
struct tps65218 *tps = dev_get_drvdata(pdev->dev.parent);
struct regulator_init_data *init_data;
const struct tps_info *template;
struct regulator_dev *rdev;
const struct of_device_id *match;
struct regulator_config config = { };
int id;
match = of_match_device(tps65218_of_match, &pdev->dev);
if (!match)
return -ENODEV;
template = match->data;
id = template->id;
init_data = of_get_regulator_init_data(&pdev->dev, pdev->dev.of_node);
platform_set_drvdata(pdev, tps);
tps->info[id] = &tps65218_pmic_regs[id];
config.dev = &pdev->dev;
config.init_data = init_data;
config.driver_data = tps;
config.regmap = tps->regmap;
config.of_node = pdev->dev.of_node;
rdev = devm_regulator_register(&pdev->dev, &regulators[id], &config);
if (IS_ERR(rdev)) {
dev_err(tps->dev, "failed to register %s regulator\n",
pdev->name);
return PTR_ERR(rdev);
}
return 0;
}
