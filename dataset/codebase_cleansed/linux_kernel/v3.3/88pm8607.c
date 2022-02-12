static int pm8607_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
int ret = -EINVAL;
if (info->vol_table && (index < (1 << info->vol_nbits))) {
ret = info->vol_table[index];
if (info->slope_double)
ret <<= 1;
}
return ret;
}
static int choose_voltage(struct regulator_dev *rdev, int min_uV, int max_uV)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
int i, ret = -ENOENT;
if (info->slope_double) {
min_uV = min_uV >> 1;
max_uV = max_uV >> 1;
}
if (info->vol_table) {
for (i = 0; i < (1 << info->vol_nbits); i++) {
if (!info->vol_table[i])
break;
if ((min_uV <= info->vol_table[i])
&& (max_uV >= info->vol_table[i])) {
ret = i;
break;
}
}
}
if (ret < 0)
pr_err("invalid voltage range (%d %d) uV\n", min_uV, max_uV);
return ret;
}
static int pm8607_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
uint8_t val, mask;
int ret;
if (min_uV > max_uV) {
pr_err("invalid voltage range (%d, %d) uV\n", min_uV, max_uV);
return -EINVAL;
}
ret = choose_voltage(rdev, min_uV, max_uV);
if (ret < 0)
return -EINVAL;
*selector = ret;
val = (uint8_t)(ret << info->vol_shift);
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
ret = pm860x_set_bits(info->i2c, info->vol_reg, mask, val);
if (ret)
return ret;
switch (info->desc.id) {
case PM8607_ID_BUCK1:
case PM8607_ID_BUCK3:
ret = pm860x_set_bits(info->i2c, info->update_reg,
1 << info->update_bit,
1 << info->update_bit);
break;
}
return ret;
}
static int pm8607_get_voltage(struct regulator_dev *rdev)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
uint8_t val, mask;
int ret;
ret = pm860x_reg_read(info->i2c, info->vol_reg);
if (ret < 0)
return ret;
mask = ((1 << info->vol_nbits) - 1) << info->vol_shift;
val = ((unsigned char)ret & mask) >> info->vol_shift;
return pm8607_list_voltage(rdev, val);
}
static int pm8607_enable(struct regulator_dev *rdev)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
return pm860x_set_bits(info->i2c, info->enable_reg,
1 << info->enable_bit,
1 << info->enable_bit);
}
static int pm8607_disable(struct regulator_dev *rdev)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
return pm860x_set_bits(info->i2c, info->enable_reg,
1 << info->enable_bit, 0);
}
static int pm8607_is_enabled(struct regulator_dev *rdev)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
int ret;
ret = pm860x_reg_read(info->i2c, info->enable_reg);
if (ret < 0)
return ret;
return !!((unsigned char)ret & (1 << info->enable_bit));
}
static int __devinit pm8607_regulator_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm8607_regulator_info *info = NULL;
struct regulator_init_data *pdata = pdev->dev.platform_data;
struct resource *res;
int i;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (res == NULL) {
dev_err(&pdev->dev, "No I/O resource!\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(pm8607_regulator_info); i++) {
info = &pm8607_regulator_info[i];
if (info->desc.id == res->start)
break;
}
if (i == ARRAY_SIZE(pm8607_regulator_info)) {
dev_err(&pdev->dev, "Failed to find regulator %llu\n",
(unsigned long long)res->start);
return -EINVAL;
}
info->i2c = (chip->id == CHIP_PM8607) ? chip->client : chip->companion;
info->chip = chip;
if ((i == PM8607_ID_BUCK3) && info->chip->buck3_double)
info->slope_double = 1;
info->regulator = regulator_register(&info->desc, &pdev->dev,
pdata, info, NULL);
if (IS_ERR(info->regulator)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
info->desc.name);
return PTR_ERR(info->regulator);
}
platform_set_drvdata(pdev, info);
return 0;
}
static int __devexit pm8607_regulator_remove(struct platform_device *pdev)
{
struct pm8607_regulator_info *info = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
regulator_unregister(info->regulator);
return 0;
}
static int __init pm8607_regulator_init(void)
{
return platform_driver_register(&pm8607_regulator_driver);
}
static void __exit pm8607_regulator_exit(void)
{
platform_driver_unregister(&pm8607_regulator_driver);
}
