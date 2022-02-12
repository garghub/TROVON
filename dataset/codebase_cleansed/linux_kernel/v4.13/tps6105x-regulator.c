static int tps6105x_regulator_probe(struct platform_device *pdev)
{
struct tps6105x *tps6105x = dev_get_platdata(&pdev->dev);
struct tps6105x_platform_data *pdata = tps6105x->pdata;
struct regulator_config config = { };
int ret;
if (pdata->mode != TPS6105X_MODE_VOLTAGE) {
dev_info(&pdev->dev,
"chip not in voltage mode mode, exit probe\n");
return 0;
}
config.dev = &tps6105x->client->dev;
config.init_data = pdata->regulator_data;
config.driver_data = tps6105x;
config.regmap = tps6105x->regmap;
tps6105x->regulator = devm_regulator_register(&pdev->dev,
&tps6105x_regulator_desc,
&config);
if (IS_ERR(tps6105x->regulator)) {
ret = PTR_ERR(tps6105x->regulator);
dev_err(&tps6105x->client->dev,
"failed to register regulator\n");
return ret;
}
platform_set_drvdata(pdev, tps6105x);
return 0;
}
static __init int tps6105x_regulator_init(void)
{
return platform_driver_register(&tps6105x_regulator_driver);
}
static __exit void tps6105x_regulator_exit(void)
{
platform_driver_unregister(&tps6105x_regulator_driver);
}
