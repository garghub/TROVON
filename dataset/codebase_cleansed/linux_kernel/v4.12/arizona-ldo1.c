static int arizona_ldo1_hc_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector >= rdev->desc->n_voltages)
return -EINVAL;
if (selector == rdev->desc->n_voltages - 1)
return 1800000;
else
return rdev->desc->min_uV + (rdev->desc->uV_step * selector);
}
static int arizona_ldo1_hc_map_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int sel;
sel = DIV_ROUND_UP(min_uV - rdev->desc->min_uV, rdev->desc->uV_step);
if (sel >= rdev->desc->n_voltages)
sel = rdev->desc->n_voltages - 1;
return sel;
}
static int arizona_ldo1_hc_set_voltage_sel(struct regulator_dev *rdev,
unsigned sel)
{
struct arizona_ldo1 *ldo = rdev_get_drvdata(rdev);
struct regmap *regmap = ldo->regmap;
unsigned int val;
int ret;
if (sel == rdev->desc->n_voltages - 1)
val = ARIZONA_LDO1_HI_PWR;
else
val = 0;
ret = regmap_update_bits(regmap, ARIZONA_LDO1_CONTROL_2,
ARIZONA_LDO1_HI_PWR, val);
if (ret != 0)
return ret;
if (val)
return 0;
val = sel << ARIZONA_LDO1_VSEL_SHIFT;
return regmap_update_bits(regmap, ARIZONA_LDO1_CONTROL_1,
ARIZONA_LDO1_VSEL_MASK, val);
}
static int arizona_ldo1_hc_get_voltage_sel(struct regulator_dev *rdev)
{
struct arizona_ldo1 *ldo = rdev_get_drvdata(rdev);
struct regmap *regmap = ldo->regmap;
unsigned int val;
int ret;
ret = regmap_read(regmap, ARIZONA_LDO1_CONTROL_2, &val);
if (ret != 0)
return ret;
if (val & ARIZONA_LDO1_HI_PWR)
return rdev->desc->n_voltages - 1;
ret = regmap_read(regmap, ARIZONA_LDO1_CONTROL_1, &val);
if (ret != 0)
return ret;
return (val & ARIZONA_LDO1_VSEL_MASK) >> ARIZONA_LDO1_VSEL_SHIFT;
}
static int arizona_ldo1_of_get_pdata(struct arizona_ldo1_pdata *pdata,
struct regulator_config *config,
const struct regulator_desc *desc,
bool *external_dcvdd)
{
struct arizona_ldo1 *ldo1 = config->driver_data;
struct device_node *np = config->dev->of_node;
struct device_node *init_node, *dcvdd_node;
struct regulator_init_data *init_data;
pdata->ldoena = of_get_named_gpio(np, "wlf,ldoena", 0);
if (pdata->ldoena < 0) {
dev_warn(config->dev,
"LDOENA GPIO property missing/malformed: %d\n",
pdata->ldoena);
pdata->ldoena = 0;
} else {
config->ena_gpio_initialized = true;
}
init_node = of_get_child_by_name(np, "ldo1");
dcvdd_node = of_parse_phandle(np, "DCVDD-supply", 0);
if (init_node) {
config->of_node = init_node;
init_data = of_get_regulator_init_data(config->dev, init_node,
desc);
if (init_data) {
init_data->consumer_supplies = &ldo1->supply;
init_data->num_consumer_supplies = 1;
if (dcvdd_node && dcvdd_node != init_node)
*external_dcvdd = true;
pdata->init_data = init_data;
}
} else if (dcvdd_node) {
*external_dcvdd = true;
}
of_node_put(dcvdd_node);
return 0;
}
static int arizona_ldo1_common_init(struct platform_device *pdev,
struct arizona_ldo1 *ldo1,
const struct regulator_desc *desc,
struct arizona_ldo1_pdata *pdata,
bool *external_dcvdd)
{
struct device *parent_dev = pdev->dev.parent;
struct regulator_config config = { };
int ret;
*external_dcvdd = false;
ldo1->supply.supply = "DCVDD";
ldo1->init_data.consumer_supplies = &ldo1->supply;
ldo1->supply.dev_name = dev_name(parent_dev);
config.dev = parent_dev;
config.driver_data = ldo1;
config.regmap = ldo1->regmap;
if (IS_ENABLED(CONFIG_OF)) {
if (!dev_get_platdata(parent_dev)) {
ret = arizona_ldo1_of_get_pdata(pdata,
&config, desc,
external_dcvdd);
if (ret < 0)
return ret;
}
}
config.ena_gpio = pdata->ldoena;
if (pdata->init_data)
config.init_data = pdata->init_data;
else
config.init_data = &ldo1->init_data;
if (config.init_data->num_consumer_supplies == 0)
*external_dcvdd = true;
ldo1->regulator = devm_regulator_register(&pdev->dev, desc, &config);
of_node_put(config.of_node);
if (IS_ERR(ldo1->regulator)) {
ret = PTR_ERR(ldo1->regulator);
dev_err(&pdev->dev, "Failed to register LDO1 supply: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, ldo1);
return 0;
}
static int arizona_ldo1_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct arizona_ldo1 *ldo1;
const struct regulator_desc *desc;
bool external_dcvdd;
int ret;
ldo1 = devm_kzalloc(&pdev->dev, sizeof(*ldo1), GFP_KERNEL);
if (!ldo1)
return -ENOMEM;
ldo1->regmap = arizona->regmap;
switch (arizona->type) {
case WM5102:
case WM8997:
case WM8998:
case WM1814:
desc = &arizona_ldo1_hc;
ldo1->init_data = arizona_ldo1_dvfs;
break;
case WM5110:
case WM8280:
desc = &arizona_ldo1;
ldo1->init_data = arizona_ldo1_wm5110;
break;
default:
desc = &arizona_ldo1;
ldo1->init_data = arizona_ldo1_default;
break;
}
ret = arizona_ldo1_common_init(pdev, ldo1, desc,
&arizona->pdata.ldo1,
&external_dcvdd);
if (ret == 0)
arizona->external_dcvdd = external_dcvdd;
return ret;
}
