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
int rid = rdev_get_id(dev);
if (rid < TPS65218_DCDC_1 || rid > TPS65218_LDO_1)
return -EINVAL;
return tps65218_set_bits(tps, dev->desc->enable_reg,
dev->desc->enable_mask, dev->desc->enable_mask,
TPS65218_PROTECT_L1);
}
static int tps65218_pmic_disable(struct regulator_dev *dev)
{
struct tps65218 *tps = rdev_get_drvdata(dev);
int rid = rdev_get_id(dev);
if (rid < TPS65218_DCDC_1 || rid > TPS65218_LDO_1)
return -EINVAL;
return tps65218_clear_bits(tps, dev->desc->enable_reg,
dev->desc->enable_mask, TPS65218_PROTECT_L1);
}
static int tps65218_pmic_set_suspend_enable(struct regulator_dev *dev)
{
struct tps65218 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65218_DCDC_1 || rid > TPS65218_LDO_1)
return -EINVAL;
return tps65218_clear_bits(tps, dev->desc->bypass_reg,
dev->desc->bypass_mask,
TPS65218_PROTECT_L1);
}
static int tps65218_pmic_set_suspend_disable(struct regulator_dev *dev)
{
struct tps65218 *tps = rdev_get_drvdata(dev);
unsigned int rid = rdev_get_id(dev);
if (rid < TPS65218_DCDC_1 || rid > TPS65218_LDO_1)
return -EINVAL;
if (!tps->info[rid]->strobe) {
if (rid == TPS65218_DCDC_3)
tps->info[rid]->strobe = 3;
else
return -EINVAL;
}
return tps65218_set_bits(tps, dev->desc->bypass_reg,
dev->desc->bypass_mask,
tps->info[rid]->strobe,
TPS65218_PROTECT_L1);
}
static int tps65218_pmic_set_input_current_lim(struct regulator_dev *dev,
int lim_uA)
{
unsigned int index = 0;
unsigned int num_currents = ARRAY_SIZE(ls3_currents);
struct tps65218 *tps = rdev_get_drvdata(dev);
while (index < num_currents && ls3_currents[index] != lim_uA)
index++;
if (index == num_currents)
return -EINVAL;
return tps65218_set_bits(tps, dev->desc->csel_reg, dev->desc->csel_mask,
index << 2, TPS65218_PROTECT_L1);
}
static int tps65218_pmic_set_current_limit(struct regulator_dev *dev,
int min_uA, int max_uA)
{
int index = 0;
unsigned int num_currents = ARRAY_SIZE(ls3_currents);
struct tps65218 *tps = rdev_get_drvdata(dev);
while (index < num_currents && ls3_currents[index] < max_uA)
index++;
index--;
if (index < 0 || ls3_currents[index] < min_uA)
return -EINVAL;
return tps65218_set_bits(tps, dev->desc->csel_reg, dev->desc->csel_mask,
index << 2, TPS65218_PROTECT_L1);
}
static int tps65218_pmic_get_current_limit(struct regulator_dev *dev)
{
int retval;
unsigned int index;
struct tps65218 *tps = rdev_get_drvdata(dev);
retval = tps65218_reg_read(tps, dev->desc->csel_reg, &index);
if (retval < 0)
return retval;
index = (index & dev->desc->csel_mask) >> 2;
return ls3_currents[index];
}
static int tps65218_regulator_probe(struct platform_device *pdev)
{
struct tps65218 *tps = dev_get_drvdata(pdev->dev.parent);
struct regulator_init_data *init_data;
const struct tps_info *template;
struct regulator_dev *rdev;
const struct of_device_id *match;
struct regulator_config config = { };
int id, ret;
unsigned int val;
match = of_match_device(tps65218_of_match, &pdev->dev);
if (!match)
return -ENODEV;
template = match->data;
id = template->id;
init_data = of_get_regulator_init_data(&pdev->dev, pdev->dev.of_node,
&regulators[id]);
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
ret = tps65218_reg_read(tps, regulators[id].bypass_reg, &val);
if (ret)
return ret;
tps->info[id]->strobe = val & regulators[id].bypass_mask;
return 0;
}
