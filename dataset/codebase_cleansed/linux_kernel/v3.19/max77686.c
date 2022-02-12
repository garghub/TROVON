static unsigned int max77686_get_opmode_shift(int id)
{
switch (id) {
case MAX77686_BUCK1:
case MAX77686_BUCK5 ... MAX77686_BUCK9:
return 0;
case MAX77686_BUCK2 ... MAX77686_BUCK4:
return MAX77686_OPMODE_BUCK234_SHIFT;
default:
return MAX77686_OPMODE_SHIFT;
}
}
static int max77686_set_suspend_disable(struct regulator_dev *rdev)
{
unsigned int val, shift;
struct max77686_data *max77686 = rdev_get_drvdata(rdev);
int ret, id = rdev_get_id(rdev);
shift = max77686_get_opmode_shift(id);
val = MAX77686_OFF_PWRREQ;
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val << shift);
if (ret)
return ret;
max77686->opmode[id] = val;
return 0;
}
static int max77686_set_suspend_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct max77686_data *max77686 = rdev_get_drvdata(rdev);
unsigned int val;
int ret, id = rdev_get_id(rdev);
if (id >= MAX77686_BUCK5)
return 0;
switch (mode) {
case REGULATOR_MODE_IDLE:
val = MAX77686_LDO_LOWPOWER_PWRREQ;
break;
case REGULATOR_MODE_NORMAL:
val = MAX77686_NORMAL;
break;
default:
pr_warn("%s: regulator_suspend_mode : 0x%x not supported\n",
rdev->desc->name, mode);
return -EINVAL;
}
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask,
val << MAX77686_OPMODE_SHIFT);
if (ret)
return ret;
max77686->opmode[id] = val;
return 0;
}
static int max77686_ldo_set_suspend_mode(struct regulator_dev *rdev,
unsigned int mode)
{
unsigned int val;
struct max77686_data *max77686 = rdev_get_drvdata(rdev);
int ret;
switch (mode) {
case REGULATOR_MODE_STANDBY:
val = MAX77686_OFF_PWRREQ;
break;
case REGULATOR_MODE_IDLE:
val = MAX77686_LDO_LOWPOWER_PWRREQ;
break;
case REGULATOR_MODE_NORMAL:
val = MAX77686_NORMAL;
break;
default:
pr_warn("%s: regulator_suspend_mode : 0x%x not supported\n",
rdev->desc->name, mode);
return -EINVAL;
}
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask,
val << MAX77686_OPMODE_SHIFT);
if (ret)
return ret;
max77686->opmode[rdev_get_id(rdev)] = val;
return 0;
}
static int max77686_enable(struct regulator_dev *rdev)
{
struct max77686_data *max77686 = rdev_get_drvdata(rdev);
unsigned int shift;
int id = rdev_get_id(rdev);
shift = max77686_get_opmode_shift(id);
if (max77686->opmode[id] == MAX77686_OFF_PWRREQ)
max77686->opmode[id] = MAX77686_NORMAL;
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask,
max77686->opmode[id] << shift);
}
static int max77686_set_ramp_delay(struct regulator_dev *rdev, int ramp_delay)
{
unsigned int ramp_value = RAMP_RATE_NO_CTRL;
switch (ramp_delay) {
case 1 ... 13750:
ramp_value = RAMP_RATE_13P75MV;
break;
case 13751 ... 27500:
ramp_value = RAMP_RATE_27P5MV;
break;
case 27501 ... 55000:
ramp_value = RAMP_RATE_55MV;
break;
case 55001 ... 100000:
break;
default:
pr_warn("%s: ramp_delay: %d not supported, setting 100000\n",
rdev->desc->name, ramp_delay);
}
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
MAX77686_RAMP_RATE_MASK, ramp_value << 6);
}
static int max77686_pmic_probe(struct platform_device *pdev)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct max77686_data *max77686;
int i;
struct regulator_config config = { };
dev_dbg(&pdev->dev, "%s\n", __func__);
max77686 = devm_kzalloc(&pdev->dev, sizeof(struct max77686_data),
GFP_KERNEL);
if (!max77686)
return -ENOMEM;
config.dev = iodev->dev;
config.regmap = iodev->regmap;
config.driver_data = max77686;
platform_set_drvdata(pdev, max77686);
for (i = 0; i < MAX77686_REGULATORS; i++) {
struct regulator_dev *rdev;
int id = regulators[i].id;
max77686->opmode[id] = MAX77686_NORMAL;
rdev = devm_regulator_register(&pdev->dev,
&regulators[i], &config);
if (IS_ERR(rdev)) {
int ret = PTR_ERR(rdev);
dev_err(&pdev->dev,
"regulator init failed for %d: %d\n", i, ret);
return ret;
}
}
return 0;
}
static int __init max77686_pmic_init(void)
{
return platform_driver_register(&max77686_pmic_driver);
}
static void __exit max77686_pmic_cleanup(void)
{
platform_driver_unregister(&max77686_pmic_driver);
}
