static int max14577_reg_is_enabled(struct regulator_dev *rdev)
{
int rid = rdev_get_id(rdev);
struct regmap *rmap = rdev->regmap;
u8 reg_data;
switch (rid) {
case MAX14577_CHARGER:
max14577_read_reg(rmap, MAX14577_CHG_REG_CHG_CTRL2, &reg_data);
if ((reg_data & CHGCTRL2_MBCHOSTEN_MASK) == 0)
return 0;
max14577_read_reg(rmap, MAX14577_CHG_REG_STATUS3, &reg_data);
if ((reg_data & STATUS3_CGMBC_MASK) == 0)
return 0;
return 1;
default:
return -EINVAL;
}
}
static int max14577_reg_get_current_limit(struct regulator_dev *rdev)
{
u8 reg_data;
struct regmap *rmap = rdev->regmap;
struct max14577 *max14577 = rdev_get_drvdata(rdev);
const struct maxim_charger_current *limits =
&maxim_charger_currents[max14577->dev_type];
if (rdev_get_id(rdev) != MAX14577_CHARGER)
return -EINVAL;
max14577_read_reg(rmap, MAX14577_CHG_REG_CHG_CTRL4, &reg_data);
if ((reg_data & CHGCTRL4_MBCICHWRCL_MASK) == 0)
return limits->min;
reg_data = ((reg_data & CHGCTRL4_MBCICHWRCH_MASK) >>
CHGCTRL4_MBCICHWRCH_SHIFT);
return limits->high_start + reg_data * limits->high_step;
}
static int max14577_reg_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
u8 reg_data;
int ret;
struct max14577 *max14577 = rdev_get_drvdata(rdev);
const struct maxim_charger_current *limits =
&maxim_charger_currents[max14577->dev_type];
if (rdev_get_id(rdev) != MAX14577_CHARGER)
return -EINVAL;
ret = maxim_charger_calc_reg_current(limits, min_uA, max_uA, &reg_data);
if (ret)
return ret;
return max14577_update_reg(rdev->regmap, MAX14577_CHG_REG_CHG_CTRL4,
CHGCTRL4_MBCICHWRCL_MASK | CHGCTRL4_MBCICHWRCH_MASK,
reg_data);
}
static inline struct regulator_init_data *match_init_data(int index,
enum maxim_device_type dev_type)
{
switch (dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
return max77836_regulator_matches[index].init_data;
case MAXIM_DEVICE_TYPE_MAX14577:
default:
return max14577_regulator_matches[index].init_data;
}
}
static inline struct device_node *match_of_node(int index,
enum maxim_device_type dev_type)
{
switch (dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
return max77836_regulator_matches[index].of_node;
case MAXIM_DEVICE_TYPE_MAX14577:
default:
return max14577_regulator_matches[index].of_node;
}
}
static inline struct regulator_init_data *match_init_data(int index,
enum maxim_device_type dev_type)
{
return NULL;
}
static inline struct device_node *match_of_node(int index,
enum maxim_device_type dev_type)
{
return NULL;
}
static struct regmap *max14577_get_regmap(struct max14577 *max14577,
int reg_id)
{
switch (max14577->dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
switch (reg_id) {
case MAX77836_SAFEOUT ... MAX77836_CHARGER:
return max14577->regmap;
default:
return max14577->regmap_pmic;
}
case MAXIM_DEVICE_TYPE_MAX14577:
default:
return max14577->regmap;
}
}
static int max14577_regulator_probe(struct platform_device *pdev)
{
struct max14577 *max14577 = dev_get_drvdata(pdev->dev.parent);
struct max14577_platform_data *pdata = dev_get_platdata(max14577->dev);
int i, ret = 0;
struct regulator_config config = {};
const struct regulator_desc *supported_regulators;
unsigned int supported_regulators_size;
enum maxim_device_type dev_type = max14577->dev_type;
switch (dev_type) {
case MAXIM_DEVICE_TYPE_MAX77836:
supported_regulators = max77836_supported_regulators;
supported_regulators_size = ARRAY_SIZE(max77836_supported_regulators);
break;
case MAXIM_DEVICE_TYPE_MAX14577:
default:
supported_regulators = max14577_supported_regulators;
supported_regulators_size = ARRAY_SIZE(max14577_supported_regulators);
}
config.dev = max14577->dev;
config.driver_data = max14577;
for (i = 0; i < supported_regulators_size; i++) {
struct regulator_dev *regulator;
if (pdata && pdata->regulators) {
config.init_data = pdata->regulators[i].initdata;
config.of_node = pdata->regulators[i].of_node;
} else {
config.init_data = match_init_data(i, dev_type);
config.of_node = match_of_node(i, dev_type);
}
config.regmap = max14577_get_regmap(max14577,
supported_regulators[i].id);
regulator = devm_regulator_register(&pdev->dev,
&supported_regulators[i], &config);
if (IS_ERR(regulator)) {
ret = PTR_ERR(regulator);
dev_err(&pdev->dev,
"Regulator init failed for %d/%s with error: %d\n",
i, supported_regulators[i].name, ret);
return ret;
}
}
return ret;
}
static int __init max14577_regulator_init(void)
{
BUILD_BUG_ON(ARRAY_SIZE(max14577_supported_regulators) != MAX14577_REGULATOR_NUM);
BUILD_BUG_ON(ARRAY_SIZE(max77836_supported_regulators) != MAX77836_REGULATOR_NUM);
BUILD_BUG_ON(MAX77836_REGULATOR_LDO_VOLTAGE_MIN +
(MAX77836_REGULATOR_LDO_VOLTAGE_STEP *
(MAX77836_REGULATOR_LDO_VOLTAGE_STEPS_NUM - 1)) !=
MAX77836_REGULATOR_LDO_VOLTAGE_MAX);
return platform_driver_register(&max14577_regulator_driver);
}
static void __exit max14577_regulator_exit(void)
{
platform_driver_unregister(&max14577_regulator_driver);
}
