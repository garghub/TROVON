static int arizona_micsupp_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector > ARIZONA_MICSUPP_MAX_SELECTOR)
return -EINVAL;
if (selector == ARIZONA_MICSUPP_MAX_SELECTOR)
return 3300000;
else
return (selector * 50000) + 1700000;
}
static int arizona_micsupp_map_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
unsigned int voltage;
int selector;
if (min_uV < 1700000)
min_uV = 1700000;
if (min_uV > 3200000)
selector = ARIZONA_MICSUPP_MAX_SELECTOR;
else
selector = DIV_ROUND_UP(min_uV - 1700000, 50000);
if (selector < 0)
return -EINVAL;
voltage = arizona_micsupp_list_voltage(rdev, selector);
if (voltage < min_uV || voltage > max_uV)
return -EINVAL;
return selector;
}
static int arizona_micsupp_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct regulator_config config = { };
struct arizona_micsupp *micsupp;
int ret;
micsupp = devm_kzalloc(&pdev->dev, sizeof(*micsupp), GFP_KERNEL);
if (micsupp == NULL) {
dev_err(&pdev->dev, "Unable to allocate private data\n");
return -ENOMEM;
}
micsupp->arizona = arizona;
micsupp->init_data = arizona_micsupp_default;
micsupp->init_data.consumer_supplies = &micsupp->supply;
micsupp->supply.supply = "MICVDD";
micsupp->supply.dev_name = dev_name(arizona->dev);
config.dev = arizona->dev;
config.driver_data = micsupp;
config.regmap = arizona->regmap;
if (arizona->pdata.micvdd)
config.init_data = arizona->pdata.micvdd;
else
config.init_data = &micsupp->init_data;
regmap_update_bits(arizona->regmap, ARIZONA_MIC_CHARGE_PUMP_1,
ARIZONA_CPMIC_BYPASS, 0);
micsupp->regulator = regulator_register(&arizona_micsupp, &config);
if (IS_ERR(micsupp->regulator)) {
ret = PTR_ERR(micsupp->regulator);
dev_err(arizona->dev, "Failed to register mic supply: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, micsupp);
return 0;
}
static int arizona_micsupp_remove(struct platform_device *pdev)
{
struct arizona_micsupp *micsupp = platform_get_drvdata(pdev);
regulator_unregister(micsupp->regulator);
return 0;
}
