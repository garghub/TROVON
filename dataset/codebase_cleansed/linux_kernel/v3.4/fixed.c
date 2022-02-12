static struct fixed_voltage_config *
of_get_fixed_voltage_config(struct device *dev)
{
struct fixed_voltage_config *config;
struct device_node *np = dev->of_node;
const __be32 *delay;
struct regulator_init_data *init_data;
config = devm_kzalloc(dev, sizeof(struct fixed_voltage_config),
GFP_KERNEL);
if (!config)
return NULL;
config->init_data = of_get_regulator_init_data(dev, dev->of_node);
if (!config->init_data)
return NULL;
init_data = config->init_data;
init_data->constraints.apply_uV = 0;
config->supply_name = init_data->constraints.name;
if (init_data->constraints.min_uV == init_data->constraints.max_uV) {
config->microvolts = init_data->constraints.min_uV;
} else {
dev_err(dev,
"Fixed regulator specified with variable voltages\n");
return NULL;
}
if (init_data->constraints.boot_on)
config->enabled_at_boot = true;
config->gpio = of_get_named_gpio(np, "gpio", 0);
delay = of_get_property(np, "startup-delay-us", NULL);
if (delay)
config->startup_delay = be32_to_cpu(*delay);
if (of_find_property(np, "enable-active-high", NULL))
config->enable_high = true;
return config;
}
static int fixed_voltage_is_enabled(struct regulator_dev *dev)
{
struct fixed_voltage_data *data = rdev_get_drvdata(dev);
return data->is_enabled;
}
static int fixed_voltage_enable(struct regulator_dev *dev)
{
struct fixed_voltage_data *data = rdev_get_drvdata(dev);
if (gpio_is_valid(data->gpio)) {
gpio_set_value_cansleep(data->gpio, data->enable_high);
data->is_enabled = true;
}
return 0;
}
static int fixed_voltage_disable(struct regulator_dev *dev)
{
struct fixed_voltage_data *data = rdev_get_drvdata(dev);
if (gpio_is_valid(data->gpio)) {
gpio_set_value_cansleep(data->gpio, !data->enable_high);
data->is_enabled = false;
}
return 0;
}
static int fixed_voltage_enable_time(struct regulator_dev *dev)
{
struct fixed_voltage_data *data = rdev_get_drvdata(dev);
return data->startup_delay;
}
static int fixed_voltage_get_voltage(struct regulator_dev *dev)
{
struct fixed_voltage_data *data = rdev_get_drvdata(dev);
if (data->microvolts)
return data->microvolts;
else
return -EINVAL;
}
static int fixed_voltage_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct fixed_voltage_data *data = rdev_get_drvdata(dev);
if (selector != 0)
return -EINVAL;
return data->microvolts;
}
static int __devinit reg_fixed_voltage_probe(struct platform_device *pdev)
{
struct fixed_voltage_config *config;
struct fixed_voltage_data *drvdata;
int ret;
if (pdev->dev.of_node)
config = of_get_fixed_voltage_config(&pdev->dev);
else
config = pdev->dev.platform_data;
if (!config)
return -ENOMEM;
drvdata = kzalloc(sizeof(struct fixed_voltage_data), GFP_KERNEL);
if (drvdata == NULL) {
dev_err(&pdev->dev, "Failed to allocate device data\n");
ret = -ENOMEM;
goto err;
}
drvdata->desc.name = kstrdup(config->supply_name, GFP_KERNEL);
if (drvdata->desc.name == NULL) {
dev_err(&pdev->dev, "Failed to allocate supply name\n");
ret = -ENOMEM;
goto err;
}
drvdata->desc.type = REGULATOR_VOLTAGE;
drvdata->desc.owner = THIS_MODULE;
drvdata->desc.ops = &fixed_voltage_ops;
if (config->microvolts)
drvdata->desc.n_voltages = 1;
drvdata->microvolts = config->microvolts;
drvdata->gpio = config->gpio;
drvdata->startup_delay = config->startup_delay;
if (gpio_is_valid(config->gpio)) {
drvdata->enable_high = config->enable_high;
if (!config->gpio)
dev_warn(&pdev->dev,
"using GPIO 0 for regulator enable control\n");
ret = gpio_request(config->gpio, config->supply_name);
if (ret) {
dev_err(&pdev->dev,
"Could not obtain regulator enable GPIO %d: %d\n",
config->gpio, ret);
goto err_name;
}
drvdata->is_enabled = config->enabled_at_boot;
ret = drvdata->is_enabled ?
config->enable_high : !config->enable_high;
ret = gpio_direction_output(config->gpio, ret);
if (ret) {
dev_err(&pdev->dev,
"Could not configure regulator enable GPIO %d direction: %d\n",
config->gpio, ret);
goto err_gpio;
}
} else {
drvdata->is_enabled = true;
}
drvdata->dev = regulator_register(&drvdata->desc, &pdev->dev,
config->init_data, drvdata,
pdev->dev.of_node);
if (IS_ERR(drvdata->dev)) {
ret = PTR_ERR(drvdata->dev);
dev_err(&pdev->dev, "Failed to register regulator: %d\n", ret);
goto err_gpio;
}
platform_set_drvdata(pdev, drvdata);
dev_dbg(&pdev->dev, "%s supplying %duV\n", drvdata->desc.name,
drvdata->microvolts);
return 0;
err_gpio:
if (gpio_is_valid(config->gpio))
gpio_free(config->gpio);
err_name:
kfree(drvdata->desc.name);
err:
kfree(drvdata);
return ret;
}
static int __devexit reg_fixed_voltage_remove(struct platform_device *pdev)
{
struct fixed_voltage_data *drvdata = platform_get_drvdata(pdev);
regulator_unregister(drvdata->dev);
if (gpio_is_valid(drvdata->gpio))
gpio_free(drvdata->gpio);
kfree(drvdata->desc.name);
kfree(drvdata);
return 0;
}
static int __init regulator_fixed_voltage_init(void)
{
return platform_driver_register(&regulator_fixed_voltage_driver);
}
static void __exit regulator_fixed_voltage_exit(void)
{
platform_driver_unregister(&regulator_fixed_voltage_driver);
}
