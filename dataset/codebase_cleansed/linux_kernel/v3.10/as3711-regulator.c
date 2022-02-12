static int as3711_list_voltage_sd(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector >= rdev->desc->n_voltages)
return -EINVAL;
if (!selector)
return 0;
if (selector < 0x41)
return 600000 + selector * 12500;
if (selector < 0x71)
return 1400000 + (selector - 0x40) * 25000;
return 2600000 + (selector - 0x70) * 50000;
}
static int as3711_list_voltage_aldo(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector >= rdev->desc->n_voltages)
return -EINVAL;
if (selector < 0x10)
return 1200000 + selector * 50000;
return 1800000 + (selector - 0x10) * 100000;
}
static int as3711_list_voltage_dldo(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector >= rdev->desc->n_voltages ||
(selector > 0x10 && selector < 0x20))
return -EINVAL;
if (selector < 0x11)
return 900000 + selector * 50000;
return 1750000 + (selector - 0x20) * 50000;
}
static int as3711_bound_check(struct regulator_dev *rdev,
int *min_uV, int *max_uV)
{
struct as3711_regulator *reg = rdev_get_drvdata(rdev);
struct as3711_regulator_info *info = reg->reg_info;
dev_dbg(&rdev->dev, "%s(), %d, %d, %d\n", __func__,
*min_uV, rdev->desc->min_uV, info->max_uV);
if (*max_uV < *min_uV ||
*min_uV > info->max_uV || rdev->desc->min_uV > *max_uV)
return -EINVAL;
if (rdev->desc->n_voltages == 1)
return 0;
if (*max_uV > info->max_uV)
*max_uV = info->max_uV;
if (*min_uV < rdev->desc->min_uV)
*min_uV = rdev->desc->min_uV;
return *min_uV;
}
static int as3711_sel_check(int min, int max, int bottom, int step)
{
int sel, voltage;
sel = DIV_ROUND_UP(min - bottom, step);
voltage = sel * step + bottom;
pr_debug("%s(): select %d..%d in %d+N*%d: %d\n", __func__,
min, max, bottom, step, sel);
if (voltage > max)
return -EINVAL;
return sel;
}
static int as3711_map_voltage_sd(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int ret;
ret = as3711_bound_check(rdev, &min_uV, &max_uV);
if (ret <= 0)
return ret;
if (min_uV <= 1400000)
return as3711_sel_check(min_uV, max_uV, 600000, 12500);
if (min_uV <= 2600000)
return as3711_sel_check(min_uV, max_uV, 1400000, 25000) + 0x40;
return as3711_sel_check(min_uV, max_uV, 2600000, 50000) + 0x70;
}
static int as3711_set_mode_sd(struct regulator_dev *rdev, unsigned int mode)
{
unsigned int fast_bit = rdev->desc->enable_mask,
low_noise_bit = fast_bit << 4;
u8 val;
switch (mode) {
case REGULATOR_MODE_FAST:
val = fast_bit | low_noise_bit;
break;
case REGULATOR_MODE_NORMAL:
val = low_noise_bit;
break;
case REGULATOR_MODE_IDLE:
val = 0;
break;
default:
return -EINVAL;
}
return regmap_update_bits(rdev->regmap, AS3711_SD_CONTROL_1,
low_noise_bit | fast_bit, val);
}
static unsigned int as3711_get_mode_sd(struct regulator_dev *rdev)
{
unsigned int fast_bit = rdev->desc->enable_mask,
low_noise_bit = fast_bit << 4, mask = fast_bit | low_noise_bit;
unsigned int val;
int ret = regmap_read(rdev->regmap, AS3711_SD_CONTROL_1, &val);
if (ret < 0)
return ret;
if ((val & mask) == mask)
return REGULATOR_MODE_FAST;
if ((val & mask) == low_noise_bit)
return REGULATOR_MODE_NORMAL;
if (!(val & mask))
return REGULATOR_MODE_IDLE;
return -EINVAL;
}
static int as3711_map_voltage_aldo(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int ret;
ret = as3711_bound_check(rdev, &min_uV, &max_uV);
if (ret <= 0)
return ret;
if (min_uV <= 1800000)
return as3711_sel_check(min_uV, max_uV, 1200000, 50000);
return as3711_sel_check(min_uV, max_uV, 1800000, 100000) + 0x10;
}
static int as3711_map_voltage_dldo(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int ret;
ret = as3711_bound_check(rdev, &min_uV, &max_uV);
if (ret <= 0)
return ret;
if (min_uV <= 1700000)
return as3711_sel_check(min_uV, max_uV, 900000, 50000);
return as3711_sel_check(min_uV, max_uV, 1750000, 50000) + 0x20;
}
static int as3711_regulator_parse_dt(struct device *dev,
struct device_node **of_node, const int count)
{
struct as3711_regulator_pdata *pdata = dev_get_platdata(dev);
struct device_node *regulators =
of_find_node_by_name(dev->parent->of_node, "regulators");
struct of_regulator_match *match;
int ret, i;
if (!regulators) {
dev_err(dev, "regulator node not found\n");
return -ENODEV;
}
ret = of_regulator_match(dev->parent, regulators,
as3711_regulator_matches, count);
of_node_put(regulators);
if (ret < 0) {
dev_err(dev, "Error parsing regulator init data: %d\n", ret);
return ret;
}
for (i = 0, match = as3711_regulator_matches; i < count; i++, match++)
if (match->of_node) {
pdata->init_data[i] = match->init_data;
of_node[i] = match->of_node;
}
return 0;
}
static int as3711_regulator_probe(struct platform_device *pdev)
{
struct as3711_regulator_pdata *pdata = dev_get_platdata(&pdev->dev);
struct as3711 *as3711 = dev_get_drvdata(pdev->dev.parent);
struct regulator_init_data *reg_data;
struct regulator_config config = {.dev = &pdev->dev,};
struct as3711_regulator *reg = NULL;
struct as3711_regulator *regs;
struct device_node *of_node[AS3711_REGULATOR_NUM] = {};
struct regulator_dev *rdev;
struct as3711_regulator_info *ri;
int ret;
int id;
if (!pdata) {
dev_err(&pdev->dev, "No platform data...\n");
return -ENODEV;
}
if (pdev->dev.parent->of_node) {
ret = as3711_regulator_parse_dt(&pdev->dev, of_node, AS3711_REGULATOR_NUM);
if (ret < 0) {
dev_err(&pdev->dev, "DT parsing failed: %d\n", ret);
return ret;
}
}
regs = devm_kzalloc(&pdev->dev, AS3711_REGULATOR_NUM *
sizeof(struct as3711_regulator), GFP_KERNEL);
if (!regs) {
dev_err(&pdev->dev, "Memory allocation failed exiting..\n");
return -ENOMEM;
}
for (id = 0, ri = as3711_reg_info; id < AS3711_REGULATOR_NUM; ++id, ri++) {
reg_data = pdata->init_data[id];
if (!reg_data)
continue;
reg = &regs[id];
reg->reg_info = ri;
config.init_data = reg_data;
config.driver_data = reg;
config.regmap = as3711->regmap;
config.of_node = of_node[id];
rdev = regulator_register(&ri->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "Failed to register regulator %s\n",
ri->desc.name);
ret = PTR_ERR(rdev);
goto eregreg;
}
reg->rdev = rdev;
}
platform_set_drvdata(pdev, regs);
return 0;
eregreg:
while (--id >= 0)
regulator_unregister(regs[id].rdev);
return ret;
}
static int as3711_regulator_remove(struct platform_device *pdev)
{
struct as3711_regulator *regs = platform_get_drvdata(pdev);
int id;
for (id = 0; id < AS3711_REGULATOR_NUM; ++id)
regulator_unregister(regs[id].rdev);
return 0;
}
static int __init as3711_regulator_init(void)
{
return platform_driver_register(&as3711_regulator_driver);
}
static void __exit as3711_regulator_exit(void)
{
platform_driver_unregister(&as3711_regulator_driver);
}
