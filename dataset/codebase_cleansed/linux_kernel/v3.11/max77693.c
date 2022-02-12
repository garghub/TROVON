static int max77693_chg_is_enabled(struct regulator_dev *rdev)
{
int ret;
u8 val;
ret = max77693_read_reg(rdev->regmap, rdev->desc->enable_reg, &val);
if (ret)
return ret;
return (val & rdev->desc->enable_mask) == rdev->desc->enable_mask;
}
static int max77693_chg_get_current_limit(struct regulator_dev *rdev)
{
unsigned int chg_min_uA = rdev->constraints->min_uA;
unsigned int chg_max_uA = rdev->constraints->max_uA;
u8 reg, sel;
unsigned int val;
int ret;
ret = max77693_read_reg(rdev->regmap,
MAX77693_CHG_REG_CHG_CNFG_09, &reg);
if (ret < 0)
return ret;
sel = reg & CHG_CNFG_09_CHGIN_ILIM_MASK;
if (sel <= 3)
sel = 0;
else
sel -= 3;
val = chg_min_uA + CHGIN_ILIM_STEP_20mA * sel;
if (val > chg_max_uA)
return -EINVAL;
return val;
}
static int max77693_chg_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
unsigned int chg_min_uA = rdev->constraints->min_uA;
int sel = 0;
while (chg_min_uA + CHGIN_ILIM_STEP_20mA * sel < min_uA)
sel++;
if (chg_min_uA + CHGIN_ILIM_STEP_20mA * sel > max_uA)
return -EINVAL;
sel += 3;
return max77693_write_reg(rdev->regmap,
MAX77693_CHG_REG_CHG_CNFG_09, sel);
}
static int max77693_pmic_dt_parse_rdata(struct device *dev,
struct max77693_regulator_data **rdata)
{
struct device_node *np;
struct of_regulator_match *rmatch;
struct max77693_regulator_data *tmp;
int i, matched = 0;
np = of_find_node_by_name(dev->parent->of_node, "regulators");
if (!np)
return -EINVAL;
rmatch = devm_kzalloc(dev,
sizeof(*rmatch) * ARRAY_SIZE(regulators), GFP_KERNEL);
if (!rmatch)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(regulators); i++)
rmatch[i].name = regulators[i].name;
matched = of_regulator_match(dev, np, rmatch, ARRAY_SIZE(regulators));
if (matched <= 0)
return matched;
*rdata = devm_kzalloc(dev, sizeof(**rdata) * matched, GFP_KERNEL);
if (!(*rdata))
return -ENOMEM;
tmp = *rdata;
for (i = 0; i < matched; i++) {
tmp->initdata = rmatch[i].init_data;
tmp->of_node = rmatch[i].of_node;
tmp->id = regulators[i].id;
tmp++;
}
return matched;
}
static int max77693_pmic_dt_parse_rdata(struct device *dev,
struct max77693_regulator_data **rdata)
{
return 0;
}
static int max77693_pmic_init_rdata(struct device *dev,
struct max77693_regulator_data **rdata)
{
struct max77693_platform_data *pdata;
int num_regulators = 0;
pdata = dev_get_platdata(dev->parent);
if (pdata) {
*rdata = pdata->regulators;
num_regulators = pdata->num_regulators;
}
if (!(*rdata) && dev->parent->of_node)
num_regulators = max77693_pmic_dt_parse_rdata(dev, rdata);
return num_regulators;
}
static int max77693_pmic_probe(struct platform_device *pdev)
{
struct max77693_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct max77693_pmic_dev *max77693_pmic;
struct max77693_regulator_data *rdata = NULL;
int num_rdata, i, ret;
struct regulator_config config;
num_rdata = max77693_pmic_init_rdata(&pdev->dev, &rdata);
if (!rdata || num_rdata <= 0) {
dev_err(&pdev->dev, "No init data supplied.\n");
return -ENODEV;
}
max77693_pmic = devm_kzalloc(&pdev->dev,
sizeof(struct max77693_pmic_dev),
GFP_KERNEL);
if (!max77693_pmic)
return -ENOMEM;
max77693_pmic->rdev = devm_kzalloc(&pdev->dev,
sizeof(struct regulator_dev *) * num_rdata,
GFP_KERNEL);
if (!max77693_pmic->rdev)
return -ENOMEM;
max77693_pmic->dev = &pdev->dev;
max77693_pmic->iodev = iodev;
max77693_pmic->num_regulators = num_rdata;
config.dev = &pdev->dev;
config.regmap = iodev->regmap;
config.driver_data = max77693_pmic;
platform_set_drvdata(pdev, max77693_pmic);
for (i = 0; i < max77693_pmic->num_regulators; i++) {
int id = rdata[i].id;
config.init_data = rdata[i].initdata;
config.of_node = rdata[i].of_node;
max77693_pmic->rdev[i] = regulator_register(&regulators[id],
&config);
if (IS_ERR(max77693_pmic->rdev[i])) {
ret = PTR_ERR(max77693_pmic->rdev[i]);
dev_err(max77693_pmic->dev,
"Failed to initialize regulator-%d\n", id);
max77693_pmic->rdev[i] = NULL;
goto err;
}
}
return 0;
err:
while (--i >= 0)
regulator_unregister(max77693_pmic->rdev[i]);
return ret;
}
static int max77693_pmic_remove(struct platform_device *pdev)
{
struct max77693_pmic_dev *max77693_pmic = platform_get_drvdata(pdev);
struct regulator_dev **rdev = max77693_pmic->rdev;
int i;
for (i = 0; i < max77693_pmic->num_regulators; i++)
if (rdev[i])
regulator_unregister(rdev[i]);
return 0;
}
