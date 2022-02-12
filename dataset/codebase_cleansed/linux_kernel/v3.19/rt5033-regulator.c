static int rt5033_regulator_probe(struct platform_device *pdev)
{
struct rt5033_dev *rt5033 = dev_get_drvdata(pdev->dev.parent);
int ret, i;
struct regulator_config config = {};
config.dev = &pdev->dev;
config.driver_data = rt5033;
for (i = 0; i < ARRAY_SIZE(rt5033_supported_regulators); i++) {
struct regulator_dev *regulator;
config.regmap = rt5033->regmap;
regulator = devm_regulator_register(&pdev->dev,
&rt5033_supported_regulators[i], &config);
if (IS_ERR(regulator)) {
ret = PTR_ERR(regulator);
dev_err(&pdev->dev,
"Regulator init failed %d: with error: %d\n",
i, ret);
return ret;
}
}
return 0;
}
