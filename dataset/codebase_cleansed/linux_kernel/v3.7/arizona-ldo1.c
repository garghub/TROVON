static __devinit int arizona_ldo1_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct arizona_ldo1 *ldo1;
int ret;
ldo1 = devm_kzalloc(&pdev->dev, sizeof(*ldo1), GFP_KERNEL);
if (ldo1 == NULL) {
dev_err(&pdev->dev, "Unable to allocate private data\n");
return -ENOMEM;
}
ldo1->arizona = arizona;
ldo1->init_data = arizona_ldo1_default;
ldo1->init_data.consumer_supplies = &ldo1->supply;
ldo1->supply.supply = "DCVDD";
ldo1->supply.dev_name = dev_name(arizona->dev);
config.dev = arizona->dev;
config.driver_data = ldo1;
config.regmap = arizona->regmap;
config.ena_gpio = arizona->pdata.ldoena;
if (arizona->pdata.ldo1)
config.init_data = arizona->pdata.ldo1;
else
config.init_data = &ldo1->init_data;
ldo1->regulator = regulator_register(&arizona_ldo1, &config);
if (IS_ERR(ldo1->regulator)) {
ret = PTR_ERR(ldo1->regulator);
dev_err(arizona->dev, "Failed to register LDO1 supply: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, ldo1);
return 0;
}
static __devexit int arizona_ldo1_remove(struct platform_device *pdev)
{
struct arizona_ldo1 *ldo1 = platform_get_drvdata(pdev);
regulator_unregister(ldo1->regulator);
return 0;
}
