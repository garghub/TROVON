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
gpio_set_value_cansleep(data->gpios[ptr].gpio, state);
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
gpio_set_value_cansleep(data->gpios[ptr].gpio, state);
}
data->state = target;
return 0;
}
struct gpio_regulator_config *
of_get_gpio_regulator_config(struct device *dev, struct device_node *np)
{
struct gpio_regulator_config *config;
struct property *prop;
const char *regtype;
int proplen, gpio, i;
config = devm_kzalloc(dev,
sizeof(struct gpio_regulator_config),
GFP_KERNEL);
if (!config)
return ERR_PTR(-ENOMEM);
config->init_data = of_get_regulator_init_data(dev, np);
if (!config->init_data)
return ERR_PTR(-EINVAL);
config->supply_name = config->init_data->constraints.name;
if (of_property_read_bool(np, "enable-active-high"))
config->enable_high = true;
if (of_property_read_bool(np, "enable-at-boot"))
config->enabled_at_boot = true;
of_property_read_u32(np, "startup-delay-us", &config->startup_delay);
config->enable_gpio = of_get_named_gpio(np, "enable-gpio", 0);
for (i = 0; ; i++)
if (of_get_named_gpio(np, "gpios", i) < 0)
break;
config->nr_gpios = i;
config->gpios = devm_kzalloc(dev,
sizeof(struct gpio) * config->nr_gpios,
GFP_KERNEL);
if (!config->gpios)
return ERR_PTR(-ENOMEM);
for (i = 0; i < config->nr_gpios; i++) {
gpio = of_get_named_gpio(np, "gpios", i);
if (gpio < 0)
break;
config->gpios[i].gpio = gpio;
}
prop = of_find_property(np, "states", NULL);
if (!prop) {
dev_err(dev, "No 'states' property found\n");
return ERR_PTR(-EINVAL);
}
proplen = prop->length / sizeof(int);
config->states = devm_kzalloc(dev,
sizeof(struct gpio_regulator_state)
* (proplen / 2),
GFP_KERNEL);
if (!config->states)
return ERR_PTR(-ENOMEM);
for (i = 0; i < proplen / 2; i++) {
config->states[i].value =
be32_to_cpup((int *)prop->value + (i * 2));
config->states[i].gpios =
be32_to_cpup((int *)prop->value + (i * 2 + 1));
}
config->nr_states = i;
of_property_read_string(np, "regulator-type", &regtype);
if (!strncmp("voltage", regtype, 7))
config->type = REGULATOR_VOLTAGE;
else if (!strncmp("current", regtype, 7))
config->type = REGULATOR_CURRENT;
return config;
}
static int gpio_regulator_probe(struct platform_device *pdev)
{
struct gpio_regulator_config *config = pdev->dev.platform_data;
struct device_node *np = pdev->dev.of_node;
struct gpio_regulator_data *drvdata;
struct regulator_config cfg = { };
int ptr, ret, state;
if (np) {
config = of_get_gpio_regulator_config(&pdev->dev, np);
if (IS_ERR(config))
return PTR_ERR(config);
}
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
cfg.of_node = np;
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
static int gpio_regulator_remove(struct platform_device *pdev)
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
