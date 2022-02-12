static int max77802_get_opmode_shift(int id)
{
if (id == MAX77802_BUCK1 || (id >= MAX77802_BUCK5 &&
id <= MAX77802_BUCK10))
return 0;
if (id >= MAX77802_BUCK2 && id <= MAX77802_BUCK4)
return MAX77802_OPMODE_BUCK234_SHIFT;
if (id >= MAX77802_LDO1 && id <= MAX77802_LDO35)
return MAX77802_OPMODE_SHIFT_LDO;
return -EINVAL;
}
static int max77802_buck_set_suspend_disable(struct regulator_dev *rdev)
{
unsigned int val = MAX77802_OPMODE_STANDBY;
struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
int shift = max77802_get_opmode_shift(id);
max77802->opmode[id] = val;
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val << shift);
}
static int max77802_ldo_set_suspend_mode_logic1(struct regulator_dev *rdev,
unsigned int mode)
{
struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
unsigned int val;
int shift = max77802_get_opmode_shift(id);
switch (mode) {
case REGULATOR_MODE_IDLE:
val = MAX77802_OPMODE_LP;
break;
case REGULATOR_MODE_NORMAL:
val = MAX77802_OPMODE_NORMAL;
break;
case REGULATOR_MODE_STANDBY:
val = MAX77802_OPMODE_STANDBY;
break;
default:
dev_warn(&rdev->dev, "%s: regulator mode: 0x%x not supported\n",
rdev->desc->name, mode);
return -EINVAL;
}
max77802->opmode[id] = val;
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val << shift);
}
static int max77802_ldo_set_suspend_mode_logic2(struct regulator_dev *rdev,
unsigned int mode)
{
struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
unsigned int val;
int shift = max77802_get_opmode_shift(id);
switch (mode) {
case REGULATOR_MODE_IDLE:
val = MAX77802_OPMODE_LP;
break;
case REGULATOR_MODE_NORMAL:
val = MAX77802_OPMODE_NORMAL;
break;
default:
dev_warn(&rdev->dev, "%s: regulator mode: 0x%x not supported\n",
rdev->desc->name, mode);
return -EINVAL;
}
max77802->opmode[id] = val;
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val << shift);
}
static int max77802_enable(struct regulator_dev *rdev)
{
struct max77802_regulator_prv *max77802 = rdev_get_drvdata(rdev);
int id = rdev_get_id(rdev);
int shift = max77802_get_opmode_shift(id);
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask,
max77802->opmode[id] << shift);
}
static int max77802_find_ramp_value(struct regulator_dev *rdev,
const unsigned int limits[], int size,
unsigned int ramp_delay)
{
int i;
for (i = 0; i < size; i++) {
if (ramp_delay <= limits[i])
return i;
}
dev_warn(&rdev->dev, "%s: ramp_delay: %d not supported, setting 100000\n",
rdev->desc->name, ramp_delay);
return size - 1;
}
static int max77802_set_ramp_delay_2bit(struct regulator_dev *rdev,
int ramp_delay)
{
int id = rdev_get_id(rdev);
unsigned int ramp_value;
if (id > MAX77802_BUCK4) {
dev_warn(&rdev->dev,
"%s: regulator: ramp delay not supported\n",
rdev->desc->name);
return -EINVAL;
}
ramp_value = max77802_find_ramp_value(rdev, ramp_table_77802_2bit,
ARRAY_SIZE(ramp_table_77802_2bit), ramp_delay);
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
MAX77802_RAMP_RATE_MASK_2BIT,
ramp_value << MAX77802_RAMP_RATE_SHIFT_2BIT);
}
static int max77802_set_ramp_delay_4bit(struct regulator_dev *rdev,
int ramp_delay)
{
unsigned int ramp_value;
ramp_value = max77802_find_ramp_value(rdev, ramp_table_77802_4bit,
ARRAY_SIZE(ramp_table_77802_4bit), ramp_delay);
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
MAX77802_RAMP_RATE_MASK_4BIT,
ramp_value << MAX77802_RAMP_RATE_SHIFT_4BIT);
}
static int max77802_pmic_dt_parse_pdata(struct platform_device *pdev,
struct max77686_platform_data *pdata)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct device_node *pmic_np, *regulators_np;
struct max77686_regulator_data *rdata;
struct of_regulator_match rmatch = { };
unsigned int i;
pmic_np = iodev->dev->of_node;
regulators_np = of_get_child_by_name(pmic_np, "regulators");
if (!regulators_np) {
dev_err(&pdev->dev, "could not find regulators sub-node\n");
return -EINVAL;
}
pdata->num_regulators = ARRAY_SIZE(regulators);
rdata = devm_kzalloc(&pdev->dev, sizeof(*rdata) *
pdata->num_regulators, GFP_KERNEL);
if (!rdata) {
of_node_put(regulators_np);
return -ENOMEM;
}
for (i = 0; i < pdata->num_regulators; i++) {
rmatch.name = regulators[i].name;
rmatch.init_data = NULL;
rmatch.of_node = NULL;
if (of_regulator_match(&pdev->dev, regulators_np, &rmatch,
1) != 1) {
dev_warn(&pdev->dev, "No matching regulator for '%s'\n",
rmatch.name);
continue;
}
rdata[i].initdata = rmatch.init_data;
rdata[i].of_node = rmatch.of_node;
rdata[i].id = regulators[i].id;
}
pdata->regulators = rdata;
of_node_put(regulators_np);
return 0;
}
static int max77802_pmic_dt_parse_pdata(struct platform_device *pdev,
struct max77686_platform_data *pdata)
{
return 0;
}
static int max77802_pmic_probe(struct platform_device *pdev)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct max77686_platform_data *pdata = dev_get_platdata(iodev->dev);
struct max77802_regulator_prv *max77802;
int i, ret = 0, val;
struct regulator_config config = { };
if (!pdata) {
dev_err(&pdev->dev, "no platform data found for regulator\n");
return -ENODEV;
}
max77802 = devm_kzalloc(&pdev->dev,
sizeof(struct max77802_regulator_prv),
GFP_KERNEL);
if (!max77802)
return -ENOMEM;
if (iodev->dev->of_node) {
ret = max77802_pmic_dt_parse_pdata(pdev, pdata);
if (ret)
return ret;
}
config.dev = iodev->dev;
config.regmap = iodev->regmap;
config.driver_data = max77802;
platform_set_drvdata(pdev, max77802);
for (i = 0; i < MAX77802_REG_MAX; i++) {
struct regulator_dev *rdev;
int id = pdata->regulators[i].id;
int shift = max77802_get_opmode_shift(id);
config.init_data = pdata->regulators[i].initdata;
config.of_node = pdata->regulators[i].of_node;
ret = regmap_read(iodev->regmap, regulators[i].enable_reg, &val);
val = val >> shift & MAX77802_OPMODE_MASK;
if (val == MAX77802_OPMODE_OFF)
max77802->opmode[id] = MAX77802_OPMODE_NORMAL;
else
max77802->opmode[id] = val;
rdev = devm_regulator_register(&pdev->dev,
&regulators[i], &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev,
"regulator init failed for %d\n", i);
return PTR_ERR(rdev);
}
}
return 0;
}
