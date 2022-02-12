static int max77693_chg_get_current_limit(struct regulator_dev *rdev)
{
const struct chg_reg_data *reg_data = rdev_get_drvdata(rdev);
unsigned int chg_min_uA = rdev->constraints->min_uA;
unsigned int chg_max_uA = rdev->constraints->max_uA;
unsigned int reg, sel;
unsigned int val;
int ret;
ret = regmap_read(rdev->regmap, reg_data->linear_reg, &reg);
if (ret < 0)
return ret;
sel = reg & reg_data->linear_mask;
if (sel <= reg_data->min_sel)
sel = 0;
else
sel -= reg_data->min_sel;
val = chg_min_uA + reg_data->uA_step * sel;
if (val > chg_max_uA)
return -EINVAL;
return val;
}
static int max77693_chg_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
const struct chg_reg_data *reg_data = rdev_get_drvdata(rdev);
unsigned int chg_min_uA = rdev->constraints->min_uA;
int sel = 0;
while (chg_min_uA + reg_data->uA_step * sel < min_uA)
sel++;
if (chg_min_uA + reg_data->uA_step * sel > max_uA)
return -EINVAL;
sel += reg_data->min_sel;
return regmap_write(rdev->regmap, reg_data->linear_reg, sel);
}
static struct regmap *max77693_get_regmap(enum max77693_types type,
struct max77693_dev *max77693,
int reg_id)
{
if (type == TYPE_MAX77693)
return max77693->regmap;
switch (reg_id) {
case MAX77843_SAFEOUT1:
case MAX77843_SAFEOUT2:
return max77693->regmap;
case MAX77843_CHARGER:
return max77693->regmap_chg;
default:
return max77693->regmap;
}
}
static int max77693_pmic_probe(struct platform_device *pdev)
{
enum max77693_types type = platform_get_device_id(pdev)->driver_data;
struct max77693_dev *iodev = dev_get_drvdata(pdev->dev.parent);
const struct regulator_desc *regulators;
unsigned int regulators_size;
int i;
struct regulator_config config = { };
config.dev = iodev->dev;
switch (type) {
case TYPE_MAX77693:
regulators = max77693_supported_regulators;
regulators_size = ARRAY_SIZE(max77693_supported_regulators);
config.driver_data = (void *)&max77693_chg_reg_data;
break;
case TYPE_MAX77843:
regulators = max77843_supported_regulators;
regulators_size = ARRAY_SIZE(max77843_supported_regulators);
config.driver_data = (void *)&max77843_chg_reg_data;
break;
default:
dev_err(&pdev->dev, "Unsupported device type: %u\n", type);
return -ENODEV;
}
for (i = 0; i < regulators_size; i++) {
struct regulator_dev *rdev;
config.regmap = max77693_get_regmap(type, iodev,
regulators[i].id);
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
static int __init max77693_pmic_init(void)
{
return platform_driver_register(&max77693_pmic_driver);
}
static void __exit max77693_pmic_cleanup(void)
{
platform_driver_unregister(&max77693_pmic_driver);
}
