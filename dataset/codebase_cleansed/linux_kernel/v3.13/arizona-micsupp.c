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
static void arizona_micsupp_check_cp(struct work_struct *work)
{
struct arizona_micsupp *micsupp =
container_of(work, struct arizona_micsupp, check_cp_work);
struct snd_soc_dapm_context *dapm = micsupp->arizona->dapm;
struct arizona *arizona = micsupp->arizona;
struct regmap *regmap = arizona->regmap;
unsigned int reg;
int ret;
ret = regmap_read(regmap, ARIZONA_MIC_CHARGE_PUMP_1, &reg);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read CP state: %d\n", ret);
return;
}
if (dapm) {
if ((reg & (ARIZONA_CPMIC_ENA | ARIZONA_CPMIC_BYPASS)) ==
ARIZONA_CPMIC_ENA)
snd_soc_dapm_force_enable_pin(dapm, "MICSUPP");
else
snd_soc_dapm_disable_pin(dapm, "MICSUPP");
snd_soc_dapm_sync(dapm);
}
}
static int arizona_micsupp_enable(struct regulator_dev *rdev)
{
struct arizona_micsupp *micsupp = rdev_get_drvdata(rdev);
int ret;
ret = regulator_enable_regmap(rdev);
if (ret == 0)
schedule_work(&micsupp->check_cp_work);
return ret;
}
static int arizona_micsupp_disable(struct regulator_dev *rdev)
{
struct arizona_micsupp *micsupp = rdev_get_drvdata(rdev);
int ret;
ret = regulator_disable_regmap(rdev);
if (ret == 0)
schedule_work(&micsupp->check_cp_work);
return ret;
}
static int arizona_micsupp_set_bypass(struct regulator_dev *rdev, bool ena)
{
struct arizona_micsupp *micsupp = rdev_get_drvdata(rdev);
int ret;
ret = regulator_set_bypass_regmap(rdev, ena);
if (ret == 0)
schedule_work(&micsupp->check_cp_work);
return ret;
}
static int arizona_micsupp_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
const struct regulator_desc *desc;
struct regulator_config config = { };
struct arizona_micsupp *micsupp;
int ret;
micsupp = devm_kzalloc(&pdev->dev, sizeof(*micsupp), GFP_KERNEL);
if (micsupp == NULL) {
dev_err(&pdev->dev, "Unable to allocate private data\n");
return -ENOMEM;
}
micsupp->arizona = arizona;
INIT_WORK(&micsupp->check_cp_work, arizona_micsupp_check_cp);
switch (arizona->type) {
case WM5110:
desc = &arizona_micsupp_ext;
micsupp->init_data = arizona_micsupp_ext_default;
break;
default:
desc = &arizona_micsupp;
micsupp->init_data = arizona_micsupp_default;
break;
}
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
micsupp->regulator = devm_regulator_register(&pdev->dev,
desc,
&config);
if (IS_ERR(micsupp->regulator)) {
ret = PTR_ERR(micsupp->regulator);
dev_err(arizona->dev, "Failed to register mic supply: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, micsupp);
return 0;
}
