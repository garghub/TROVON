static int arizona_ldo1_hc_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector >= rdev->desc->n_voltages)
return -EINVAL;
if (selector == rdev->desc->n_voltages - 1)
return 1800000;
else
return rdev->desc->min_uV + (rdev->desc->uV_step * selector);
}
static int arizona_ldo1_hc_map_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int sel;
sel = DIV_ROUND_UP(min_uV - rdev->desc->min_uV, rdev->desc->uV_step);
if (sel >= rdev->desc->n_voltages)
sel = rdev->desc->n_voltages - 1;
return sel;
}
static int arizona_ldo1_hc_set_voltage_sel(struct regulator_dev *rdev,
unsigned sel)
{
struct arizona_ldo1 *ldo = rdev_get_drvdata(rdev);
struct regmap *regmap = ldo->arizona->regmap;
unsigned int val;
int ret;
if (sel == rdev->desc->n_voltages - 1)
val = ARIZONA_LDO1_HI_PWR;
else
val = 0;
ret = regmap_update_bits(regmap, ARIZONA_LDO1_CONTROL_2,
ARIZONA_LDO1_HI_PWR, val);
if (ret != 0)
return ret;
ret = regmap_update_bits(regmap, ARIZONA_DYNAMIC_FREQUENCY_SCALING_1,
ARIZONA_SUBSYS_MAX_FREQ, val);
if (ret != 0)
return ret;
if (val)
return 0;
val = sel << ARIZONA_LDO1_VSEL_SHIFT;
return regmap_update_bits(regmap, ARIZONA_LDO1_CONTROL_1,
ARIZONA_LDO1_VSEL_MASK, val);
}
static int arizona_ldo1_hc_get_voltage_sel(struct regulator_dev *rdev)
{
struct arizona_ldo1 *ldo = rdev_get_drvdata(rdev);
struct regmap *regmap = ldo->arizona->regmap;
unsigned int val;
int ret;
ret = regmap_read(regmap, ARIZONA_LDO1_CONTROL_2, &val);
if (ret != 0)
return ret;
if (val & ARIZONA_LDO1_HI_PWR)
return rdev->desc->n_voltages - 1;
ret = regmap_read(regmap, ARIZONA_LDO1_CONTROL_1, &val);
if (ret != 0)
return ret;
return (val & ARIZONA_LDO1_VSEL_MASK) >> ARIZONA_LDO1_VSEL_SHIFT;
}
static int arizona_ldo1_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
const struct regulator_desc *desc;
struct regulator_config config = { };
struct arizona_ldo1 *ldo1;
int ret;
ldo1 = devm_kzalloc(&pdev->dev, sizeof(*ldo1), GFP_KERNEL);
if (!ldo1)
return -ENOMEM;
ldo1->arizona = arizona;
switch (arizona->type) {
case WM5102:
case WM8997:
desc = &arizona_ldo1_hc;
ldo1->init_data = arizona_ldo1_dvfs;
break;
default:
desc = &arizona_ldo1;
ldo1->init_data = arizona_ldo1_default;
break;
}
ldo1->init_data.consumer_supplies = &ldo1->supply;
ldo1->supply.supply = "DCVDD";
ldo1->supply.dev_name = dev_name(arizona->dev);
config.dev = arizona->dev;
config.driver_data = ldo1;
config.regmap = arizona->regmap;
config.ena_gpio = arizona->pdata.ldoena;
if (arizona->pdata.ldo1)
config.init_data = arizona->pdata.ldo1;
else
config.init_data = &ldo1->init_data;
ldo1->regulator = devm_regulator_register(&pdev->dev, desc, &config);
if (IS_ERR(ldo1->regulator)) {
ret = PTR_ERR(ldo1->regulator);
dev_err(arizona->dev, "Failed to register LDO1 supply: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, ldo1);
return 0;
}
