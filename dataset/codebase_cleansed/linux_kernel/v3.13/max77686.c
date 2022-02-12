static int max77686_buck_set_suspend_disable(struct regulator_dev *rdev)
{
unsigned int val;
struct max77686_data *max77686 = rdev_get_drvdata(rdev);
int ret, id = rdev_get_id(rdev);
if (id == MAX77686_BUCK1)
val = 0x1;
else
val = 0x1 << MAX77686_OPMODE_BUCK234_SHIFT;
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val);
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
val = 0x2 << MAX77686_OPMODE_SHIFT;
break;
case REGULATOR_MODE_NORMAL:
val = 0x3 << MAX77686_OPMODE_SHIFT;
break;
default:
pr_warn("%s: regulator_suspend_mode : 0x%x not supported\n",
rdev->desc->name, mode);
return -EINVAL;
}
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val);
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
val = 0x1 << MAX77686_OPMODE_SHIFT;
break;
case REGULATOR_MODE_IDLE:
val = 0x2 << MAX77686_OPMODE_SHIFT;
break;
case REGULATOR_MODE_NORMAL:
val = 0x3 << MAX77686_OPMODE_SHIFT;
break;
default:
pr_warn("%s: regulator_suspend_mode : 0x%x not supported\n",
rdev->desc->name, mode);
return -EINVAL;
}
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val);
if (ret)
return ret;
max77686->opmode[rdev_get_id(rdev)] = val;
return 0;
}
static int max77686_enable(struct regulator_dev *rdev)
{
struct max77686_data *max77686 = rdev_get_drvdata(rdev);
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask,
max77686->opmode[rdev_get_id(rdev)]);
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
static int max77686_pmic_dt_parse_pdata(struct platform_device *pdev,
struct max77686_platform_data *pdata)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct device_node *pmic_np, *regulators_np;
struct max77686_regulator_data *rdata;
struct of_regulator_match rmatch;
unsigned int i;
pmic_np = iodev->dev->of_node;
regulators_np = of_find_node_by_name(pmic_np, "voltage-regulators");
if (!regulators_np) {
dev_err(&pdev->dev, "could not find regulators sub-node\n");
return -EINVAL;
}
pdata->num_regulators = ARRAY_SIZE(regulators);
rdata = devm_kzalloc(&pdev->dev, sizeof(*rdata) *
pdata->num_regulators, GFP_KERNEL);
if (!rdata) {
dev_err(&pdev->dev,
"could not allocate memory for regulator data\n");
return -ENOMEM;
}
for (i = 0; i < pdata->num_regulators; i++) {
rmatch.name = regulators[i].name;
rmatch.init_data = NULL;
rmatch.of_node = NULL;
of_regulator_match(&pdev->dev, regulators_np, &rmatch, 1);
rdata[i].initdata = rmatch.init_data;
rdata[i].of_node = rmatch.of_node;
}
pdata->regulators = rdata;
return 0;
}
static int max77686_pmic_dt_parse_pdata(struct platform_device *pdev,
struct max77686_platform_data *pdata)
{
return 0;
}
static int max77686_pmic_probe(struct platform_device *pdev)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct max77686_platform_data *pdata = dev_get_platdata(iodev->dev);
struct max77686_data *max77686;
int i, ret = 0;
struct regulator_config config = { };
dev_dbg(&pdev->dev, "%s\n", __func__);
if (!pdata) {
dev_err(&pdev->dev, "no platform data found for regulator\n");
return -ENODEV;
}
if (iodev->dev->of_node) {
ret = max77686_pmic_dt_parse_pdata(pdev, pdata);
if (ret)
return ret;
}
if (pdata->num_regulators != MAX77686_REGULATORS) {
dev_err(&pdev->dev,
"Invalid initial data for regulator's initialiation\n");
return -EINVAL;
}
max77686 = devm_kzalloc(&pdev->dev, sizeof(struct max77686_data),
GFP_KERNEL);
if (!max77686)
return -ENOMEM;
config.dev = &pdev->dev;
config.regmap = iodev->regmap;
config.driver_data = max77686;
platform_set_drvdata(pdev, max77686);
for (i = 0; i < MAX77686_REGULATORS; i++) {
config.init_data = pdata->regulators[i].initdata;
config.of_node = pdata->regulators[i].of_node;
max77686->opmode[i] = regulators[i].enable_mask;
max77686->rdev[i] = devm_regulator_register(&pdev->dev,
&regulators[i], &config);
if (IS_ERR(max77686->rdev[i])) {
dev_err(&pdev->dev,
"regulator init failed for %d\n", i);
return PTR_ERR(max77686->rdev[i]);
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
