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
return ERR_PTR(-ENOMEM);
config->init_data = of_get_regulator_init_data(dev, dev->of_node);
if (!config->init_data)
return ERR_PTR(-EINVAL);
init_data = config->init_data;
init_data->constraints.apply_uV = 0;
config->supply_name = init_data->constraints.name;
if (init_data->constraints.min_uV == init_data->constraints.max_uV) {
config->microvolts = init_data->constraints.min_uV;
} else {
dev_err(dev,
"Fixed regulator specified with variable voltages\n");
return ERR_PTR(-EINVAL);
}
if (init_data->constraints.boot_on)
config->enabled_at_boot = true;
config->gpio = of_get_named_gpio(np, "gpio", 0);
if ((config->gpio == -ENODEV) || (config->gpio == -EPROBE_DEFER))
return ERR_PTR(-EPROBE_DEFER);
delay = of_get_property(np, "startup-delay-us", NULL);
if (delay)
config->startup_delay = be32_to_cpu(*delay);
if (of_find_property(np, "enable-active-high", NULL))
config->enable_high = true;
if (of_find_property(np, "gpio-open-drain", NULL))
config->gpio_is_open_drain = true;
if (of_find_property(np, "vin-supply", NULL))
config->input_supply = "vin";
return config;
}
static int reg_fixed_voltage_probe(struct platform_device *pdev)
{
struct fixed_voltage_config *config;
struct fixed_voltage_data *drvdata;
struct regulator_config cfg = { };
int ret;
if (pdev->dev.of_node) {
config = of_get_fixed_voltage_config(&pdev->dev);
if (IS_ERR(config))
return PTR_ERR(config);
} else {
config = dev_get_platdata(&pdev->dev);
}
if (!config)
return -ENOMEM;
drvdata = devm_kzalloc(&pdev->dev, sizeof(struct fixed_voltage_data),
GFP_KERNEL);
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
drvdata->desc.enable_time = config->startup_delay;
if (config->input_supply) {
drvdata->desc.supply_name = kstrdup(config->input_supply,
GFP_KERNEL);
if (!drvdata->desc.supply_name) {
dev_err(&pdev->dev,
"Failed to allocate input supply\n");
ret = -ENOMEM;
goto err_name;
}
}
if (config->microvolts)
drvdata->desc.n_voltages = 1;
drvdata->desc.fixed_uV = config->microvolts;
if (config->gpio >= 0)
cfg.ena_gpio = config->gpio;
cfg.ena_gpio_invert = !config->enable_high;
if (config->enabled_at_boot) {
if (config->enable_high)
cfg.ena_gpio_flags |= GPIOF_OUT_INIT_HIGH;
else
cfg.ena_gpio_flags |= GPIOF_OUT_INIT_LOW;
} else {
if (config->enable_high)
cfg.ena_gpio_flags |= GPIOF_OUT_INIT_LOW;
else
cfg.ena_gpio_flags |= GPIOF_OUT_INIT_HIGH;
}
if (config->gpio_is_open_drain)
cfg.ena_gpio_flags |= GPIOF_OPEN_DRAIN;
cfg.dev = &pdev->dev;
cfg.init_data = config->init_data;
cfg.driver_data = drvdata;
cfg.of_node = pdev->dev.of_node;
drvdata->dev = regulator_register(&drvdata->desc, &cfg);
if (IS_ERR(drvdata->dev)) {
ret = PTR_ERR(drvdata->dev);
dev_err(&pdev->dev, "Failed to register regulator: %d\n", ret);
goto err_input;
}
platform_set_drvdata(pdev, drvdata);
dev_dbg(&pdev->dev, "%s supplying %duV\n", drvdata->desc.name,
drvdata->desc.fixed_uV);
return 0;
err_input:
kfree(drvdata->desc.supply_name);
err_name:
kfree(drvdata->desc.name);
err:
return ret;
}
static int reg_fixed_voltage_remove(struct platform_device *pdev)
{
struct fixed_voltage_data *drvdata = platform_get_drvdata(pdev);
regulator_unregister(drvdata->dev);
kfree(drvdata->desc.supply_name);
kfree(drvdata->desc.name);
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
