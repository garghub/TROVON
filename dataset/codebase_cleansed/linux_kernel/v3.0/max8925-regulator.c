static inline int check_range(struct max8925_regulator_info *info,
int min_uV, int max_uV)
{
if (min_uV < info->min_uV || min_uV > info->max_uV)
return -EINVAL;
return 0;
}
static int max8925_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return info->min_uV + index * info->step_uV;
}
static int max8925_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned int *selector)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
unsigned char data, mask;
if (check_range(info, min_uV, max_uV)) {
dev_err(info->chip->dev, "invalid voltage range (%d, %d) uV\n",
min_uV, max_uV);
return -EINVAL;
}
data = (min_uV - info->min_uV + info->step_uV - 1) / info->step_uV;
*selector = data;
data <<= info->vol_shift;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
return max8925_set_bits(info->i2c, info->vol_reg, mask, data);
}
static int max8925_get_voltage(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
unsigned char data, mask;
int ret;
ret = max8925_reg_read(info->i2c, info->vol_reg);
if (ret < 0)
return ret;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
data = (ret & mask) >> info->vol_shift;
return max8925_list_voltage(rdev, data);
}
static int max8925_enable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->enable_reg,
OUT_ENABLE << info->enable_bit,
OUT_ENABLE << info->enable_bit);
}
static int max8925_disable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->enable_reg,
OUT_ENABLE << info->enable_bit,
OUT_DISABLE << info->enable_bit);
}
static int max8925_is_enabled(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
int ret;
ret = max8925_reg_read(info->i2c, info->enable_reg);
if (ret < 0)
return ret;
return ret & (1 << info->enable_bit);
}
static int max8925_set_dvm_voltage(struct regulator_dev *rdev, int uV)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
unsigned char data, mask;
if (uV < SD1_DVM_VMIN || uV > SD1_DVM_VMAX)
return -EINVAL;
data = (uV - SD1_DVM_VMIN + SD1_DVM_STEP - 1) / SD1_DVM_STEP;
data <<= SD1_DVM_SHIFT;
mask = 3 << SD1_DVM_SHIFT;
return max8925_set_bits(info->i2c, info->enable_reg, mask, data);
}
static int max8925_set_dvm_enable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->vol_reg, 1 << SD1_DVM_EN,
1 << SD1_DVM_EN);
}
static int max8925_set_dvm_disable(struct regulator_dev *rdev)
{
struct max8925_regulator_info *info = rdev_get_drvdata(rdev);
return max8925_set_bits(info->i2c, info->vol_reg, 1 << SD1_DVM_EN, 0);
}
static struct max8925_regulator_info * __devinit find_regulator_info(int id)
{
struct max8925_regulator_info *ri;
int i;
for (i = 0; i < ARRAY_SIZE(max8925_regulator_info); i++) {
ri = &max8925_regulator_info[i];
if (ri->desc.id == id)
return ri;
}
return NULL;
}
static int __devinit max8925_regulator_probe(struct platform_device *pdev)
{
struct max8925_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct max8925_platform_data *pdata = chip->dev->platform_data;
struct max8925_regulator_info *ri;
struct regulator_dev *rdev;
ri = find_regulator_info(pdev->id);
if (ri == NULL) {
dev_err(&pdev->dev, "invalid regulator ID specified\n");
return -EINVAL;
}
ri->i2c = chip->i2c;
ri->chip = chip;
rdev = regulator_register(&ri->desc, &pdev->dev,
pdata->regulator[pdev->id], ri);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
ri->desc.name);
return PTR_ERR(rdev);
}
platform_set_drvdata(pdev, rdev);
return 0;
}
static int __devexit max8925_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(rdev);
return 0;
}
static int __init max8925_regulator_init(void)
{
return platform_driver_register(&max8925_regulator_driver);
}
static void __exit max8925_regulator_exit(void)
{
platform_driver_unregister(&max8925_regulator_driver);
}
