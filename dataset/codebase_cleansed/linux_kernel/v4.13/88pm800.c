static int pm800_get_current_limit(struct regulator_dev *rdev)
{
struct pm800_regulator_info *info = rdev_get_drvdata(rdev);
return info->max_ua;
}
static int pm800_regulator_probe(struct platform_device *pdev)
{
struct pm80x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm80x_platform_data *pdata = dev_get_platdata(pdev->dev.parent);
struct pm800_regulators *pm800_data;
struct regulator_config config = { };
struct regulator_init_data *init_data;
int i, ret;
if (pdata && pdata->num_regulators) {
unsigned int count = 0;
for (i = 0; i < ARRAY_SIZE(pdata->regulators); i++) {
if (pdata->regulators[i])
count++;
}
if (count != pdata->num_regulators)
return -EINVAL;
}
pm800_data = devm_kzalloc(&pdev->dev, sizeof(*pm800_data),
GFP_KERNEL);
if (!pm800_data)
return -ENOMEM;
pm800_data->map = chip->subchip->regmap_power;
pm800_data->chip = chip;
platform_set_drvdata(pdev, pm800_data);
config.dev = chip->dev;
config.regmap = pm800_data->map;
for (i = 0; i < PM800_ID_RG_MAX; i++) {
struct regulator_dev *regulator;
if (pdata && pdata->num_regulators) {
init_data = pdata->regulators[i];
if (!init_data)
continue;
config.init_data = init_data;
}
config.driver_data = &pm800_regulator_info[i];
regulator = devm_regulator_register(&pdev->dev,
&pm800_regulator_info[i].desc, &config);
if (IS_ERR(regulator)) {
ret = PTR_ERR(regulator);
dev_err(&pdev->dev, "Failed to register %s\n",
pm800_regulator_info[i].desc.name);
return ret;
}
}
return 0;
}
