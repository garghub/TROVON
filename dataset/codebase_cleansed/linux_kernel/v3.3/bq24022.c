static int bq24022_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
struct bq24022_mach_info *pdata = rdev_get_drvdata(rdev);
dev_dbg(rdev_get_dev(rdev), "setting current limit to %s mA\n",
max_uA >= 500000 ? "500" : "100");
gpio_set_value(pdata->gpio_iset2, max_uA >= 500000);
return 0;
}
static int bq24022_get_current_limit(struct regulator_dev *rdev)
{
struct bq24022_mach_info *pdata = rdev_get_drvdata(rdev);
return gpio_get_value(pdata->gpio_iset2) ? 500000 : 100000;
}
static int bq24022_enable(struct regulator_dev *rdev)
{
struct bq24022_mach_info *pdata = rdev_get_drvdata(rdev);
dev_dbg(rdev_get_dev(rdev), "enabling charger\n");
gpio_set_value(pdata->gpio_nce, 0);
return 0;
}
static int bq24022_disable(struct regulator_dev *rdev)
{
struct bq24022_mach_info *pdata = rdev_get_drvdata(rdev);
dev_dbg(rdev_get_dev(rdev), "disabling charger\n");
gpio_set_value(pdata->gpio_nce, 1);
return 0;
}
static int bq24022_is_enabled(struct regulator_dev *rdev)
{
struct bq24022_mach_info *pdata = rdev_get_drvdata(rdev);
return !gpio_get_value(pdata->gpio_nce);
}
static int __init bq24022_probe(struct platform_device *pdev)
{
struct bq24022_mach_info *pdata = pdev->dev.platform_data;
struct regulator_dev *bq24022;
int ret;
if (!pdata || !pdata->gpio_nce || !pdata->gpio_iset2)
return -EINVAL;
ret = gpio_request(pdata->gpio_nce, "ncharge_en");
if (ret) {
dev_dbg(&pdev->dev, "couldn't request nCE GPIO: %d\n",
pdata->gpio_nce);
goto err_ce;
}
ret = gpio_request(pdata->gpio_iset2, "charge_mode");
if (ret) {
dev_dbg(&pdev->dev, "couldn't request ISET2 GPIO: %d\n",
pdata->gpio_iset2);
goto err_iset2;
}
ret = gpio_direction_output(pdata->gpio_iset2, 0);
ret = gpio_direction_output(pdata->gpio_nce, 1);
bq24022 = regulator_register(&bq24022_desc, &pdev->dev,
pdata->init_data, pdata, NULL);
if (IS_ERR(bq24022)) {
dev_dbg(&pdev->dev, "couldn't register regulator\n");
ret = PTR_ERR(bq24022);
goto err_reg;
}
platform_set_drvdata(pdev, bq24022);
dev_dbg(&pdev->dev, "registered regulator\n");
return 0;
err_reg:
gpio_free(pdata->gpio_iset2);
err_iset2:
gpio_free(pdata->gpio_nce);
err_ce:
return ret;
}
static int __devexit bq24022_remove(struct platform_device *pdev)
{
struct bq24022_mach_info *pdata = pdev->dev.platform_data;
struct regulator_dev *bq24022 = platform_get_drvdata(pdev);
regulator_unregister(bq24022);
gpio_free(pdata->gpio_iset2);
gpio_free(pdata->gpio_nce);
return 0;
}
static int __init bq24022_init(void)
{
return platform_driver_probe(&bq24022_driver, bq24022_probe);
}
static void __exit bq24022_exit(void)
{
platform_driver_unregister(&bq24022_driver);
}
