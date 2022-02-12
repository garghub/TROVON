static int hi6421_regulator_enable(struct regulator_dev *rdev)
{
struct hi6421_regulator_pdata *pdata;
pdata = dev_get_drvdata(rdev->dev.parent);
mutex_lock(&pdata->lock);
regulator_enable_regmap(rdev);
mutex_unlock(&pdata->lock);
return 0;
}
static unsigned int hi6421_regulator_ldo_get_mode(struct regulator_dev *rdev)
{
struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
u32 reg_val;
regmap_read(rdev->regmap, rdev->desc->enable_reg, &reg_val);
if (reg_val & info->mode_mask)
return REGULATOR_MODE_IDLE;
return REGULATOR_MODE_NORMAL;
}
static unsigned int hi6421_regulator_buck_get_mode(struct regulator_dev *rdev)
{
struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
u32 reg_val;
regmap_read(rdev->regmap, rdev->desc->enable_reg, &reg_val);
if (reg_val & info->mode_mask)
return REGULATOR_MODE_STANDBY;
return REGULATOR_MODE_NORMAL;
}
static int hi6421_regulator_ldo_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
u32 new_mode;
switch (mode) {
case REGULATOR_MODE_NORMAL:
new_mode = 0;
break;
case REGULATOR_MODE_IDLE:
new_mode = info->mode_mask;
break;
default:
return -EINVAL;
}
regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
info->mode_mask, new_mode);
return 0;
}
static int hi6421_regulator_buck_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
u32 new_mode;
switch (mode) {
case REGULATOR_MODE_NORMAL:
new_mode = 0;
break;
case REGULATOR_MODE_STANDBY:
new_mode = info->mode_mask;
break;
default:
return -EINVAL;
}
regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
info->mode_mask, new_mode);
return 0;
}
unsigned int hi6421_regulator_ldo_get_optimum_mode(struct regulator_dev *rdev,
int input_uV, int output_uV, int load_uA)
{
struct hi6421_regulator_info *info = rdev_get_drvdata(rdev);
if (load_uA > info->eco_microamp)
return REGULATOR_MODE_NORMAL;
return REGULATOR_MODE_IDLE;
}
static int hi6421_regulator_register(struct platform_device *pdev,
struct regmap *rmap,
struct regulator_init_data *init_data,
int id, struct device_node *np)
{
struct hi6421_regulator_info *info = NULL;
struct regulator_config config = { };
struct regulator_dev *rdev;
info = &hi6421_regulator_info[id];
config.dev = &pdev->dev;
config.init_data = init_data;
config.driver_data = info;
config.regmap = rmap;
config.of_node = np;
rdev = devm_regulator_register(&pdev->dev, &info->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
info->desc.name);
return PTR_ERR(rdev);
}
return 0;
}
static int hi6421_regulator_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np;
struct hi6421_pmic *pmic;
struct hi6421_regulator_pdata *pdata;
int i, ret = 0;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
mutex_init(&pdata->lock);
platform_set_drvdata(pdev, pdata);
np = of_get_child_by_name(dev->parent->of_node, "regulators");
if (!np)
return -ENODEV;
ret = of_regulator_match(dev, np,
hi6421_regulator_match,
ARRAY_SIZE(hi6421_regulator_match));
of_node_put(np);
if (ret < 0) {
dev_err(dev, "Error parsing regulator init data: %d\n", ret);
return ret;
}
pmic = dev_get_drvdata(dev->parent);
for (i = 0; i < ARRAY_SIZE(hi6421_regulator_info); i++) {
ret = hi6421_regulator_register(pdev, pmic->regmap,
hi6421_regulator_match[i].init_data, i,
hi6421_regulator_match[i].of_node);
if (ret)
return ret;
}
return 0;
}
