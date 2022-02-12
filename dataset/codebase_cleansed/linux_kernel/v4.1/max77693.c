static int max77693_chg_is_enabled(struct regulator_dev *rdev)
{
int ret;
unsigned int val;
ret = regmap_read(rdev->regmap, rdev->desc->enable_reg, &val);
if (ret)
return ret;
return (val & rdev->desc->enable_mask) == rdev->desc->enable_mask;
}
static int max77693_chg_get_current_limit(struct regulator_dev *rdev)
{
unsigned int chg_min_uA = rdev->constraints->min_uA;
unsigned int chg_max_uA = rdev->constraints->max_uA;
unsigned int reg, sel;
unsigned int val;
int ret;
ret = regmap_read(rdev->regmap, MAX77693_CHG_REG_CHG_CNFG_09, &reg);
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
return regmap_write(rdev->regmap,
MAX77693_CHG_REG_CHG_CNFG_09, sel);
}
static int max77693_pmic_probe(struct platform_device *pdev)
{
struct max77693_dev *iodev = dev_get_drvdata(pdev->dev.parent);
int i;
struct regulator_config config = { };
config.dev = iodev->dev;
config.regmap = iodev->regmap;
for (i = 0; i < ARRAY_SIZE(regulators); i++) {
struct regulator_dev *rdev;
rdev = devm_regulator_register(&pdev->dev,
&regulators[i], &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"Failed to initialize regulator-%d\n", i);
return PTR_ERR(rdev);
}
}
return 0;
}
