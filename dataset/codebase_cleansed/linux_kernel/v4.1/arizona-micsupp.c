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
static int arizona_micsupp_of_get_pdata(struct arizona *arizona,
struct regulator_config *config,
const struct regulator_desc *desc)
{
struct arizona_pdata *pdata = &arizona->pdata;
struct arizona_micsupp *micsupp = config->driver_data;
struct device_node *np;
struct regulator_init_data *init_data;
np = of_get_child_by_name(arizona->dev->of_node, "micvdd");
if (np) {
config->of_node = np;
init_data = of_get_regulator_init_data(arizona->dev, np, desc);
if (init_data) {
init_data->consumer_supplies = &micsupp->supply;
init_data->num_consumer_supplies = 1;
pdata->micvdd = init_data;
}
}
return 0;
}
static int arizona_micsupp_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
const struct regulator_desc *desc;
struct regulator_config config = { };
struct arizona_micsupp *micsupp;
int ret;
micsupp = devm_kzalloc(&pdev->dev, sizeof(*micsupp), GFP_KERNEL);
if (!micsupp)
return -ENOMEM;
micsupp->arizona = arizona;
INIT_WORK(&micsupp->check_cp_work, arizona_micsupp_check_cp);
switch (arizona->type) {
case WM5110:
case WM8280:
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
if (IS_ENABLED(CONFIG_OF)) {
if (!dev_get_platdata(arizona->dev)) {
ret = arizona_micsupp_of_get_pdata(arizona, &config,
desc);
if (ret < 0)
return ret;
}
}
if (arizona->pdata.micvdd)
config.init_data = arizona->pdata.micvdd;
else
config.init_data = &micsupp->init_data;
regmap_update_bits(arizona->regmap, ARIZONA_MIC_CHARGE_PUMP_1,
ARIZONA_CPMIC_BYPASS, 0);
micsupp->regulator = devm_regulator_register(&pdev->dev,
desc,
&config);
of_node_put(config.of_node);
if (IS_ERR(micsupp->regulator)) {
ret = PTR_ERR(micsupp->regulator);
dev_err(arizona->dev, "Failed to register mic supply: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, micsupp);
return 0;
}
