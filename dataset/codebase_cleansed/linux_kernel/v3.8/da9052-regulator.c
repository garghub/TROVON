static int verify_range(struct da9052_regulator_info *info,
int min_uV, int max_uV)
{
if (min_uV > info->max_uV || max_uV < info->min_uV)
return -EINVAL;
return 0;
}
static int da9052_dcdc_get_current_limit(struct regulator_dev *rdev)
{
struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
int offset = rdev_get_id(rdev);
int ret, row = 2;
ret = da9052_reg_read(regulator->da9052, DA9052_BUCKA_REG + offset/2);
if (ret < 0)
return ret;
if (offset % 2 == 0)
ret = (ret & DA9052_BUCK_ILIM_MASK_EVEN) >> 2;
else
ret = (ret & DA9052_BUCK_ILIM_MASK_ODD) >> 6;
if (regulator->da9052->chip_id == DA9052)
row = 0;
else if (offset == 0)
row = 1;
return da9052_current_limits[row][ret];
}
static int da9052_dcdc_set_current_limit(struct regulator_dev *rdev, int min_uA,
int max_uA)
{
struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
int offset = rdev_get_id(rdev);
int reg_val = 0;
int i, row = 2;
if (regulator->da9052->chip_id == DA9052)
row = 0;
else if (offset == 0)
row = 1;
for (i = DA9052_CURRENT_RANGE - 1; i >= 0; i--) {
if ((min_uA <= da9052_current_limits[row][i]) &&
(da9052_current_limits[row][i] <= max_uA)) {
reg_val = i;
break;
}
}
if (i < 0)
return -EINVAL;
if (offset % 2 == 0)
return da9052_reg_update(regulator->da9052,
DA9052_BUCKA_REG + offset/2,
DA9052_BUCK_ILIM_MASK_EVEN,
reg_val << 2);
else
return da9052_reg_update(regulator->da9052,
DA9052_BUCKA_REG + offset/2,
DA9052_BUCK_ILIM_MASK_ODD,
reg_val << 6);
}
static int da9052_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
struct da9052_regulator_info *info = regulator->info;
int id = rdev_get_id(rdev);
int volt_uV;
if ((id == DA9052_ID_BUCK4) && (regulator->da9052->chip_id == DA9052)
&& (selector >= DA9052_BUCK_PERI_REG_MAP_UPTO_3uV)) {
volt_uV = ((DA9052_BUCK_PERI_REG_MAP_UPTO_3uV * info->step_uV)
+ info->min_uV);
volt_uV += (selector - DA9052_BUCK_PERI_REG_MAP_UPTO_3uV)
* (DA9052_BUCK_PERI_3uV_STEP);
} else {
volt_uV = (selector * info->step_uV) + info->min_uV;
}
if (volt_uV > info->max_uV)
return -EINVAL;
return volt_uV;
}
static int da9052_map_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
struct da9052_regulator_info *info = regulator->info;
int id = rdev_get_id(rdev);
int ret, sel;
ret = verify_range(info, min_uV, max_uV);
if (ret < 0)
return ret;
if (min_uV < info->min_uV)
min_uV = info->min_uV;
if ((id == DA9052_ID_BUCK4) && (regulator->da9052->chip_id == DA9052)
&& (min_uV >= DA9052_CONST_3uV)) {
sel = DA9052_BUCK_PERI_REG_MAP_UPTO_3uV +
DIV_ROUND_UP(min_uV - DA9052_CONST_3uV,
DA9052_BUCK_PERI_3uV_STEP);
} else {
sel = DIV_ROUND_UP(min_uV - info->min_uV, info->step_uV);
}
ret = da9052_list_voltage(rdev, sel);
if (ret < 0)
return ret;
return sel;
}
static int da9052_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned int selector)
{
struct da9052_regulator *regulator = rdev_get_drvdata(rdev);
struct da9052_regulator_info *info = regulator->info;
int id = rdev_get_id(rdev);
int ret;
ret = da9052_reg_update(regulator->da9052, rdev->desc->vsel_reg,
rdev->desc->vsel_mask, selector);
if (ret < 0)
return ret;
switch (id) {
case DA9052_ID_BUCK1:
case DA9052_ID_BUCK2:
case DA9052_ID_BUCK3:
case DA9052_ID_LDO2:
case DA9052_ID_LDO3:
ret = da9052_reg_update(regulator->da9052, DA9052_SUPPLY_REG,
info->activate_bit, info->activate_bit);
break;
}
return ret;
}
static inline struct da9052_regulator_info *find_regulator_info(u8 chip_id,
int id)
{
struct da9052_regulator_info *info;
int i;
switch (chip_id) {
case DA9052:
for (i = 0; i < ARRAY_SIZE(da9052_regulator_info); i++) {
info = &da9052_regulator_info[i];
if (info->reg_desc.id == id)
return info;
}
break;
case DA9053_AA:
case DA9053_BA:
case DA9053_BB:
for (i = 0; i < ARRAY_SIZE(da9053_regulator_info); i++) {
info = &da9053_regulator_info[i];
if (info->reg_desc.id == id)
return info;
}
break;
}
return NULL;
}
static int da9052_regulator_probe(struct platform_device *pdev)
{
struct regulator_config config = { };
struct da9052_regulator *regulator;
struct da9052 *da9052;
struct da9052_pdata *pdata;
regulator = devm_kzalloc(&pdev->dev, sizeof(struct da9052_regulator),
GFP_KERNEL);
if (!regulator)
return -ENOMEM;
da9052 = dev_get_drvdata(pdev->dev.parent);
pdata = da9052->dev->platform_data;
regulator->da9052 = da9052;
regulator->info = find_regulator_info(regulator->da9052->chip_id,
pdev->id);
if (regulator->info == NULL) {
dev_err(&pdev->dev, "invalid regulator ID specified\n");
return -EINVAL;
}
config.dev = &pdev->dev;
config.driver_data = regulator;
config.regmap = da9052->regmap;
if (pdata && pdata->regulators) {
config.init_data = pdata->regulators[pdev->id];
} else {
#ifdef CONFIG_OF
struct device_node *nproot = da9052->dev->of_node;
struct device_node *np;
if (!nproot)
return -ENODEV;
nproot = of_find_node_by_name(nproot, "regulators");
if (!nproot)
return -ENODEV;
for_each_child_of_node(nproot, np) {
if (!of_node_cmp(np->name,
regulator->info->reg_desc.name)) {
config.init_data = of_get_regulator_init_data(
&pdev->dev, np);
config.of_node = np;
break;
}
}
#endif
}
regulator->rdev = regulator_register(&regulator->info->reg_desc,
&config);
if (IS_ERR(regulator->rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
regulator->info->reg_desc.name);
return PTR_ERR(regulator->rdev);
}
platform_set_drvdata(pdev, regulator);
return 0;
}
static int da9052_regulator_remove(struct platform_device *pdev)
{
struct da9052_regulator *regulator = platform_get_drvdata(pdev);
regulator_unregister(regulator->rdev);
return 0;
}
static int __init da9052_regulator_init(void)
{
return platform_driver_register(&da9052_regulator_driver);
}
static void __exit da9052_regulator_exit(void)
{
platform_driver_unregister(&da9052_regulator_driver);
}
