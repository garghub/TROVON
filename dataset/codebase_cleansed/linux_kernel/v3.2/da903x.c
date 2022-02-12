static inline struct device *to_da903x_dev(struct regulator_dev *rdev)
{
return rdev_get_dev(rdev)->parent->parent;
}
static inline int check_range(struct da903x_regulator_info *info,
int min_uV, int max_uV)
{
if (min_uV < info->min_uV || min_uV > info->max_uV)
return -EINVAL;
return 0;
}
static int da903x_set_ldo_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
uint8_t val, mask;
if (check_range(info, min_uV, max_uV)) {
pr_err("invalid voltage range (%d, %d) uV\n", min_uV, max_uV);
return -EINVAL;
}
val = (min_uV - info->min_uV + info->step_uV - 1) / info->step_uV;
*selector = val;
val <<= info->vol_shift;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
return da903x_update(da9034_dev, info->vol_reg, val, mask);
}
static int da903x_get_voltage(struct regulator_dev *rdev)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
uint8_t val, mask;
int ret;
ret = da903x_read(da9034_dev, info->vol_reg, &val);
if (ret)
return ret;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
val = (val & mask) >> info->vol_shift;
return info->min_uV + info->step_uV * val;
}
static int da903x_enable(struct regulator_dev *rdev)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
return da903x_set_bits(da9034_dev, info->enable_reg,
1 << info->enable_bit);
}
static int da903x_disable(struct regulator_dev *rdev)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
return da903x_clr_bits(da9034_dev, info->enable_reg,
1 << info->enable_bit);
}
static int da903x_is_enabled(struct regulator_dev *rdev)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
uint8_t reg_val;
int ret;
ret = da903x_read(da9034_dev, info->enable_reg, &reg_val);
if (ret)
return ret;
return !!(reg_val & (1 << info->enable_bit));
}
static int da903x_list_voltage(struct regulator_dev *rdev, unsigned selector)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
int ret;
ret = info->min_uV + info->step_uV * selector;
if (ret > info->max_uV)
return -EINVAL;
return ret;
}
static int da9030_set_ldo1_15_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV,
unsigned *selector)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da903x_dev = to_da903x_dev(rdev);
uint8_t val, mask;
int ret;
if (check_range(info, min_uV, max_uV)) {
pr_err("invalid voltage range (%d, %d) uV\n", min_uV, max_uV);
return -EINVAL;
}
val = (min_uV - info->min_uV + info->step_uV - 1) / info->step_uV;
*selector = val;
val <<= info->vol_shift;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
val |= DA9030_LDO_UNLOCK;
mask |= DA9030_LDO_UNLOCK_MASK;
ret = da903x_update(da903x_dev, info->vol_reg, val, mask);
if (ret)
return ret;
return da903x_update(da903x_dev, info->vol_reg, val, mask);
}
static int da9030_set_ldo14_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV,
unsigned *selector)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da903x_dev = to_da903x_dev(rdev);
uint8_t val, mask;
int thresh;
if (check_range(info, min_uV, max_uV)) {
pr_err("invalid voltage range (%d, %d) uV\n", min_uV, max_uV);
return -EINVAL;
}
thresh = (info->max_uV + info->min_uV) / 2;
if (min_uV < thresh) {
val = (thresh - min_uV + info->step_uV - 1) / info->step_uV;
val |= 0x4;
} else {
val = (min_uV - thresh + info->step_uV - 1) / info->step_uV;
}
*selector = val;
val <<= info->vol_shift;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
return da903x_update(da903x_dev, info->vol_reg, val, mask);
}
static int da9030_get_ldo14_voltage(struct regulator_dev *rdev)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da903x_dev = to_da903x_dev(rdev);
uint8_t val, mask;
int ret;
ret = da903x_read(da903x_dev, info->vol_reg, &val);
if (ret)
return ret;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
val = (val & mask) >> info->vol_shift;
if (val & 0x4)
return info->min_uV + info->step_uV * (3 - (val & ~0x4));
else
return (info->max_uV + info->min_uV) / 2 +
info->step_uV * (val & ~0x4);
}
static int da9034_set_dvc_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
uint8_t val, mask;
int ret;
if (check_range(info, min_uV, max_uV)) {
pr_err("invalid voltage range (%d, %d) uV\n", min_uV, max_uV);
return -EINVAL;
}
val = (min_uV - info->min_uV + info->step_uV - 1) / info->step_uV;
*selector = val;
val <<= info->vol_shift;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
ret = da903x_update(da9034_dev, info->vol_reg, val, mask);
if (ret)
return ret;
ret = da903x_set_bits(da9034_dev, info->update_reg,
1 << info->update_bit);
return ret;
}
static int da9034_set_ldo12_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
uint8_t val, mask;
if (check_range(info, min_uV, max_uV)) {
pr_err("invalid voltage range (%d, %d) uV\n", min_uV, max_uV);
return -EINVAL;
}
val = (min_uV - info->min_uV + info->step_uV - 1) / info->step_uV;
val = (val >= 20) ? val - 12 : ((val > 7) ? 8 : val);
*selector = val;
val <<= info->vol_shift;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
return da903x_update(da9034_dev, info->vol_reg, val, mask);
}
static int da9034_get_ldo12_voltage(struct regulator_dev *rdev)
{
struct da903x_regulator_info *info = rdev_get_drvdata(rdev);
struct device *da9034_dev = to_da903x_dev(rdev);
uint8_t val, mask;
int ret;
ret = da903x_read(da9034_dev, info->vol_reg, &val);
if (ret)
return ret;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
val = (val & mask) >> info->vol_shift;
if (val >= 8)
return 2700000 + info->step_uV * (val - 8);
return info->min_uV + info->step_uV * val;
}
static int da9034_list_ldo12_voltage(struct regulator_dev *rdev,
unsigned selector)
{
if (selector >= ARRAY_SIZE(da9034_ldo12_data))
return -EINVAL;
return da9034_ldo12_data[selector] * 1000;
}
static inline struct da903x_regulator_info *find_regulator_info(int id)
{
struct da903x_regulator_info *ri;
int i;
for (i = 0; i < ARRAY_SIZE(da903x_regulator_info); i++) {
ri = &da903x_regulator_info[i];
if (ri->desc.id == id)
return ri;
}
return NULL;
}
static int __devinit da903x_regulator_probe(struct platform_device *pdev)
{
struct da903x_regulator_info *ri = NULL;
struct regulator_dev *rdev;
ri = find_regulator_info(pdev->id);
if (ri == NULL) {
dev_err(&pdev->dev, "invalid regulator ID specified\n");
return -EINVAL;
}
if (ri->desc.id == DA9034_ID_LDO12) {
ri->desc.ops = &da9034_regulator_ldo12_ops;
ri->desc.n_voltages = ARRAY_SIZE(da9034_ldo12_data);
}
if (ri->desc.id == DA9030_ID_LDO14)
ri->desc.ops = &da9030_regulator_ldo14_ops;
if (ri->desc.id == DA9030_ID_LDO1 || ri->desc.id == DA9030_ID_LDO15)
ri->desc.ops = &da9030_regulator_ldo1_15_ops;
rdev = regulator_register(&ri->desc, &pdev->dev,
pdev->dev.platform_data, ri);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
ri->desc.name);
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
return 0;
}
static int __devexit da903x_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
return 0;
}
static int __init da903x_regulator_init(void)
{
return platform_driver_register(&da903x_regulator_driver);
}
static void __exit da903x_regulator_exit(void)
{
platform_driver_unregister(&da903x_regulator_driver);
}
