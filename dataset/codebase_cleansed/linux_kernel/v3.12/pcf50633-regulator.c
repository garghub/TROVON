static int pcf50633_regulator_probe(struct platform_device *pdev)
{
struct regulator_dev *rdev;
struct pcf50633 *pcf;
struct regulator_config config = { };
pcf = dev_to_pcf50633(pdev->dev.parent);
config.dev = &pdev->dev;
config.init_data = dev_get_platdata(&pdev->dev);
config.driver_data = pcf;
config.regmap = pcf->regmap;
rdev = regulator_register(&regulators[pdev->id], &config);
if (IS_ERR(rdev))
return PTR_ERR(rdev);
platform_set_drvdata(pdev, rdev);
if (pcf->pdata->regulator_registered)
pcf->pdata->regulator_registered(pcf, pdev->id);
return 0;
}
static int pcf50633_regulator_remove(struct platform_device *pdev)
{
struct regulator_dev *rdev = platform_get_drvdata(pdev);
regulator_unregister(rdev);
return 0;
}
static int __init pcf50633_regulator_init(void)
{
return platform_driver_register(&pcf50633_regulator_driver);
}
static void __exit pcf50633_regulator_exit(void)
{
platform_driver_unregister(&pcf50633_regulator_driver);
}
