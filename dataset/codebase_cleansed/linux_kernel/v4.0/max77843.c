static int max77843_reg_is_enabled(struct regulator_dev *rdev)
{
struct regmap *regmap = rdev->regmap;
int ret;
unsigned int reg;
ret = regmap_read(regmap, rdev->desc->enable_reg, &reg);
if (ret) {
dev_err(&rdev->dev, "Fialed to read charger register\n");
return ret;
}
return (reg & rdev->desc->enable_mask) == rdev->desc->enable_mask;
}
static int max77843_reg_get_current_limit(struct regulator_dev *rdev)
{
struct regmap *regmap = rdev->regmap;
unsigned int chg_min_uA = rdev->constraints->min_uA;
unsigned int chg_max_uA = rdev->constraints->max_uA;
unsigned int val;
int ret;
unsigned int reg, sel;
ret = regmap_read(regmap, MAX77843_CHG_REG_CHG_CNFG_02, &reg);
if (ret) {
dev_err(&rdev->dev, "Failed to read charger register\n");
return ret;
}
sel = reg & MAX77843_CHG_FAST_CHG_CURRENT_MASK;
if (sel < 0x03)
sel = 0;
else
sel -= 2;
val = chg_min_uA + MAX77843_CHG_FAST_CHG_CURRENT_STEP * sel;
if (val > chg_max_uA)
return -EINVAL;
return val;
}
static int max77843_reg_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
struct regmap *regmap = rdev->regmap;
unsigned int chg_min_uA = rdev->constraints->min_uA;
int sel = 0;
while (chg_min_uA + MAX77843_CHG_FAST_CHG_CURRENT_STEP * sel < min_uA)
sel++;
if (chg_min_uA + MAX77843_CHG_FAST_CHG_CURRENT_STEP * sel > max_uA)
return -EINVAL;
sel += 2;
return regmap_write(regmap, MAX77843_CHG_REG_CHG_CNFG_02, sel);
}
static struct regmap *max77843_get_regmap(struct max77843 *max77843, int reg_id)
{
switch (reg_id) {
case MAX77843_SAFEOUT1:
case MAX77843_SAFEOUT2:
return max77843->regmap;
case MAX77843_CHARGER:
return max77843->regmap_chg;
default:
return max77843->regmap;
}
}
static int max77843_regulator_probe(struct platform_device *pdev)
{
struct max77843 *max77843 = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = {};
int i;
config.dev = max77843->dev;
config.driver_data = max77843;
for (i = 0; i < ARRAY_SIZE(max77843_supported_regulators); i++) {
struct regulator_dev *regulator;
config.regmap = max77843_get_regmap(max77843,
max77843_supported_regulators[i].id);
regulator = devm_regulator_register(&pdev->dev,
&max77843_supported_regulators[i], &config);
if (IS_ERR(regulator)) {
dev_err(&pdev->dev,
"Failed to regiser regulator-%d\n", i);
return PTR_ERR(regulator);
}
}
return 0;
}
static int __init max77843_regulator_init(void)
{
return platform_driver_register(&max77843_regulator_driver);
}
static void __exit max77843_regulator_exit(void)
{
platform_driver_unregister(&max77843_regulator_driver);
}
