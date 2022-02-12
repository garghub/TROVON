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
static int pm8607_regulator_dt_init(struct platform_device *pdev,
struct pm8607_regulator_info *info,
struct regulator_config *config)
{
struct device_node *nproot, *np;
nproot = of_node_get(pdev->dev.parent->of_node);
if (!nproot)
return -ENODEV;
nproot = of_find_node_by_name(nproot, "regulators");
if (!nproot) {
dev_err(&pdev->dev, "failed to find regulators node\n");
return -ENODEV;
}
for_each_child_of_node(nproot, np) {
if (!of_node_cmp(np->name, info->desc.name)) {
config->init_data =
of_get_regulator_init_data(&pdev->dev, np);
config->of_node = np;
break;
}
}
of_node_put(nproot);
return 0;
}
static int pm8607_regulator_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm8607_regulator_info *info = NULL;
struct regulator_init_data *pdata = dev_get_platdata(&pdev->dev);
struct regulator_config config = { };
struct resource *res;
int i;
res = platform_get_resource(pdev, IORESOURCE_REG, 0);
if (res) {
for (i = 0; i < ARRAY_SIZE(pm8607_regulator_info); i++) {
info = &pm8607_regulator_info[i];
if (info->desc.vsel_reg == res->start)
break;
}
if (i == ARRAY_SIZE(pm8607_regulator_info)) {
dev_err(&pdev->dev, "Failed to find regulator %llu\n",
(unsigned long long)res->start);
return -EINVAL;
}
} else {
info = &pm8606_regulator_info[0];
i = -1;
}
info->i2c = (chip->id == CHIP_PM8607) ? chip->client : chip->companion;
info->i2c_8606 = (chip->id == CHIP_PM8607) ? chip->companion :
chip->client;
info->chip = chip;
if ((i == PM8607_ID_BUCK3) && info->chip->buck3_double)
info->slope_double = 1;
config.dev = &pdev->dev;
config.driver_data = info;
if (pm8607_regulator_dt_init(pdev, info, &config))
if (pdata)
config.init_data = pdata;
if (chip->id == CHIP_PM8607)
config.regmap = chip->regmap;
else
config.regmap = chip->regmap_companion;
info->regulator = devm_regulator_register(&pdev->dev, &info->desc,
&config);
if (IS_ERR(info->regulator)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
info->desc.name);
return PTR_ERR(info->regulator);
}
platform_set_drvdata(pdev, info);
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
