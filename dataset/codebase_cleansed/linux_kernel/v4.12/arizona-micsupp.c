static void arizona_micsupp_check_cp(struct work_struct *work)
{
struct arizona_micsupp *micsupp =
container_of(work, struct arizona_micsupp, check_cp_work);
struct snd_soc_dapm_context *dapm = *micsupp->dapm;
struct snd_soc_component *component;
unsigned int val;
int ret;
ret = regmap_read(micsupp->regmap, micsupp->enable_reg, &val);
if (ret != 0) {
dev_err(micsupp->dev,
"Failed to read CP state: %d\n", ret);
return;
}
if (dapm) {
component = snd_soc_dapm_to_component(dapm);
if ((val & (ARIZONA_CPMIC_ENA | ARIZONA_CPMIC_BYPASS)) ==
ARIZONA_CPMIC_ENA)
snd_soc_component_force_enable_pin(component,
"MICSUPP");
else
snd_soc_component_disable_pin(component, "MICSUPP");
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
static int arizona_micsupp_of_get_pdata(struct arizona_micsupp_pdata *pdata,
struct regulator_config *config,
const struct regulator_desc *desc)
{
struct arizona_micsupp *micsupp = config->driver_data;
struct device_node *np;
struct regulator_init_data *init_data;
np = of_get_child_by_name(config->dev->of_node, "micvdd");
if (np) {
config->of_node = np;
init_data = of_get_regulator_init_data(config->dev, np, desc);
if (init_data) {
init_data->consumer_supplies = &micsupp->supply;
init_data->num_consumer_supplies = 1;
pdata->init_data = init_data;
}
}
return 0;
}
static int arizona_micsupp_common_init(struct platform_device *pdev,
struct arizona_micsupp *micsupp,
const struct regulator_desc *desc,
struct arizona_micsupp_pdata *pdata)
{
struct regulator_config config = { };
int ret;
INIT_WORK(&micsupp->check_cp_work, arizona_micsupp_check_cp);
micsupp->init_data.consumer_supplies = &micsupp->supply;
micsupp->supply.supply = "MICVDD";
micsupp->supply.dev_name = dev_name(micsupp->dev);
micsupp->enable_reg = desc->enable_reg;
config.dev = micsupp->dev;
config.driver_data = micsupp;
config.regmap = micsupp->regmap;
if (IS_ENABLED(CONFIG_OF)) {
if (!dev_get_platdata(micsupp->dev)) {
ret = arizona_micsupp_of_get_pdata(pdata, &config,
desc);
if (ret < 0)
return ret;
}
}
if (pdata->init_data)
config.init_data = pdata->init_data;
else
config.init_data = &micsupp->init_data;
regmap_update_bits(micsupp->regmap, micsupp->enable_reg,
ARIZONA_CPMIC_BYPASS, 0);
micsupp->regulator = devm_regulator_register(&pdev->dev,
desc,
&config);
of_node_put(config.of_node);
if (IS_ERR(micsupp->regulator)) {
ret = PTR_ERR(micsupp->regulator);
dev_err(micsupp->dev, "Failed to register mic supply: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, micsupp);
return 0;
}
static int arizona_micsupp_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
const struct regulator_desc *desc;
struct arizona_micsupp *micsupp;
micsupp = devm_kzalloc(&pdev->dev, sizeof(*micsupp), GFP_KERNEL);
if (!micsupp)
return -ENOMEM;
micsupp->regmap = arizona->regmap;
micsupp->dapm = &arizona->dapm;
micsupp->dev = arizona->dev;
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
return arizona_micsupp_common_init(pdev, micsupp, desc,
&arizona->pdata.micvdd);
}
