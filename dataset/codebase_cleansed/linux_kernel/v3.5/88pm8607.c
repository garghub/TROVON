static int pm8607_list_voltage(struct regulator_dev *rdev, unsigned index)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
int ret = -EINVAL;
if (info->vol_table && (index < rdev->desc->n_voltages)) {
ret = info->vol_table[index];
if (info->slope_double)
ret <<= 1;
}
return ret;
}
static int pm8607_set_voltage_sel(struct regulator_dev *rdev, unsigned selector)
{
struct pm8607_regulator_info *info = rdev_get_drvdata(rdev);
uint8_t val;
int ret;
val = (uint8_t)(selector << (ffs(rdev->desc->vsel_mask) - 1));
ret = pm860x_set_bits(info->i2c, rdev->desc->vsel_reg,
rdev->desc->vsel_mask, val);
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
static int __devinit pm8607_regulator_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm8607_regulator_info *info = NULL;
struct regulator_init_data *pdata = pdev->dev.platform_data;
struct regulator_config config = { };
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
config.dev = &pdev->dev;
config.init_data = pdata;
config.driver_data = info;
if (chip->id == CHIP_PM8607)
config.regmap = chip->regmap;
else
config.regmap = chip->regmap_companion;
info->regulator = regulator_register(&info->desc, &config);
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
