static int gpio_regulator_get_value(struct regulator_dev *dev)
{
struct gpio_regulator_data *data = rdev_get_drvdata(dev);
int ptr;
for (ptr = 0; ptr < data->nr_states; ptr++)
if (data->states[ptr].gpios == data->state)
return data->states[ptr].value;
return -EINVAL;
}
static int gpio_regulator_set_voltage(struct regulator_dev *dev,
int min_uV, int max_uV,
unsigned *selector)
{
struct gpio_regulator_data *data = rdev_get_drvdata(dev);
int ptr, target = 0, state, best_val = INT_MAX;
for (ptr = 0; ptr < data->nr_states; ptr++)
if (data->states[ptr].value < best_val &&
data->states[ptr].value >= min_uV &&
data->states[ptr].value <= max_uV) {
target = data->states[ptr].gpios;
best_val = data->states[ptr].value;
if (selector)
*selector = ptr;
}
if (best_val == INT_MAX)
return -EINVAL;
for (ptr = 0; ptr < data->nr_gpios; ptr++) {
state = (target & (1 << ptr)) >> ptr;
gpio_set_value(data->gpios[ptr].gpio, state);
}
data->state = target;
return 0;
}
static int gpio_regulator_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct gpio_regulator_data *data = rdev_get_drvdata(dev);
if (selector >= data->nr_states)
return -EINVAL;
return data->states[selector].value;
}
static int gpio_regulator_set_current_limit(struct regulator_dev *dev,
int min_uA, int max_uA)
{
struct gpio_regulator_data *data = rdev_get_drvdata(dev);
int ptr, target = 0, state, best_val = 0;
for (ptr = 0; ptr < data->nr_states; ptr++)
if (data->states[ptr].value > best_val &&
data->states[ptr].value >= min_uA &&
data->states[ptr].value <= max_uA) {
target = data->states[ptr].gpios;
best_val = data->states[ptr].value;
}
if (best_val == 0)
return -EINVAL;
for (ptr = 0; ptr < data->nr_gpios; ptr++) {
state = (target & (1 << ptr)) >> ptr;
gpio_set_value(data->gpios[ptr].gpio, state);
}
data->state = target;
return 0;
}
static int __devinit gpio_regulator_probe(struct platform_device *pdev)
{
struct gpio_regulator_config *config = pdev->dev.platform_data;
struct gpio_regulator_data *drvdata;
struct regulator_config cfg = { };
int ptr, ret, state;
drvdata = devm_kzalloc(&pdev->dev, sizeof(struct gpio_regulator_data),
GFP_KERNEL);
if (drvdata == NULL) {
dev_err(&pdev->dev, "Failed to allocate device data\n");
return -ENOMEM;
}
drvdata->desc.name = kstrdup(config->supply_name, GFP_KERNEL);
if (drvdata->desc.name == NULL) {
dev_err(&pdev->dev, "Failed to allocate supply name\n");
ret = -ENOMEM;
goto err;
}
drvdata->gpios = kmemdup(config->gpios,
config->nr_gpios * sizeof(struct gpio),
GFP_KERNEL);
if (drvdata->gpios == NULL) {
dev_err(&pdev->dev, "Failed to allocate gpio data\n");
ret = -ENOMEM;
goto err_name;
}
drvdata->states = kmemdup(config->states,
config->nr_states *
sizeof(struct gpio_regulator_state),
GFP_KERNEL);
if (drvdata->states == NULL) {
dev_err(&pdev->dev, "Failed to allocate state data\n");
ret = -ENOMEM;
goto err_memgpio;
}
drvdata->nr_states = config->nr_states;
drvdata->desc.owner = THIS_MODULE;
drvdata->desc.enable_time = config->startup_delay;
switch (config->type) {
case REGULATOR_VOLTAGE:
drvdata->desc.type = REGULATOR_VOLTAGE;
drvdata->desc.ops = &gpio_regulator_voltage_ops;
drvdata->desc.n_voltages = config->nr_states;
break;
case REGULATOR_CURRENT:
drvdata->desc.type = REGULATOR_CURRENT;
drvdata->desc.ops = &gpio_regulator_current_ops;
break;
default:
dev_err(&pdev->dev, "No regulator type set\n");
ret = -EINVAL;
goto err_memgpio;
break;
}
drvdata->nr_gpios = config->nr_gpios;
ret = gpio_request_array(drvdata->gpios, drvdata->nr_gpios);
if (ret) {
dev_err(&pdev->dev,
"Could not obtain regulator setting GPIOs: %d\n", ret);
goto err_memstate;
}
state = 0;
for (ptr = 0; ptr < drvdata->nr_gpios; ptr++) {
if (config->gpios[ptr].flags & GPIOF_OUT_INIT_HIGH)
state |= (1 << ptr);
}
drvdata->state = state;
cfg.dev = &pdev->dev;
cfg.init_data = config->init_data;
cfg.driver_data = drvdata;
if (config->enable_gpio >= 0)
cfg.ena_gpio = config->enable_gpio;
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
drvdata->dev = regulator_register(&drvdata->desc, &cfg);
if (IS_ERR(drvdata->dev)) {
ret = PTR_ERR(drvdata->dev);
dev_err(&pdev->dev, "Failed to register regulator: %d\n", ret);
goto err_stategpio;
}
platform_set_drvdata(pdev, drvdata);
return 0;
err_stategpio:
gpio_free_array(drvdata->gpios, drvdata->nr_gpios);
err_memstate:
kfree(drvdata->states);
err_memgpio:
kfree(drvdata->gpios);
err_name:
kfree(drvdata->desc.name);
err:
return ret;
}
static int __devexit gpio_regulator_remove(struct platform_device *pdev)
{
struct gpio_regulator_data *drvdata = platform_get_drvdata(pdev);
regulator_unregister(drvdata->dev);
gpio_free_array(drvdata->gpios, drvdata->nr_gpios);
kfree(drvdata->states);
kfree(drvdata->gpios);
kfree(drvdata->desc.name);
return 0;
}
static int __init gpio_regulator_init(void)
{
return platform_driver_register(&gpio_regulator_driver);
}
static void __exit gpio_regulator_exit(void)
{
platform_driver_unregister(&gpio_regulator_driver);
}
