static int pwm_regulator_get_voltage_sel(struct regulator_dev *dev)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
return drvdata->state;
}
static int pwm_regulator_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
unsigned int pwm_reg_period;
int dutycycle;
int ret;
pwm_reg_period = pwm_get_period(drvdata->pwm);
dutycycle = (pwm_reg_period *
drvdata->duty_cycle_table[selector].dutycycle) / 100;
ret = pwm_config(drvdata->pwm, dutycycle, pwm_reg_period);
if (ret) {
dev_err(&dev->dev, "Failed to configure PWM\n");
return ret;
}
drvdata->state = selector;
if (!drvdata->enabled) {
ret = pwm_enable(drvdata->pwm);
if (ret) {
dev_err(&dev->dev, "Failed to enable PWM\n");
return ret;
}
drvdata->enabled = true;
}
return 0;
}
static int pwm_regulator_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
if (selector >= drvdata->desc.n_voltages)
return -EINVAL;
return drvdata->duty_cycle_table[selector].uV;
}
static int pwm_regulator_probe(struct platform_device *pdev)
{
struct pwm_regulator_data *drvdata;
struct property *prop;
struct regulator_dev *regulator;
struct regulator_config config = { };
struct device_node *np = pdev->dev.of_node;
int length, ret;
if (!np) {
dev_err(&pdev->dev, "Device Tree node missing\n");
return -EINVAL;
}
drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
memcpy(&drvdata->desc, &pwm_regulator_desc, sizeof(pwm_regulator_desc));
prop = of_find_property(np, "voltage-table", &length);
if (!prop) {
dev_err(&pdev->dev, "No voltage-table\n");
return -EINVAL;
}
if ((length < sizeof(*drvdata->duty_cycle_table)) ||
(length % sizeof(*drvdata->duty_cycle_table))) {
dev_err(&pdev->dev, "voltage-table length(%d) is invalid\n",
length);
return -EINVAL;
}
drvdata->desc.n_voltages = length / sizeof(*drvdata->duty_cycle_table);
drvdata->duty_cycle_table = devm_kzalloc(&pdev->dev,
length, GFP_KERNEL);
if (!drvdata->duty_cycle_table)
return -ENOMEM;
ret = of_property_read_u32_array(np, "voltage-table",
(u32 *)drvdata->duty_cycle_table,
length / sizeof(u32));
if (ret < 0) {
dev_err(&pdev->dev, "read voltage-table failed\n");
return ret;
}
config.init_data = of_get_regulator_init_data(&pdev->dev, np,
&drvdata->desc);
if (!config.init_data)
return -ENOMEM;
config.of_node = np;
config.dev = &pdev->dev;
config.driver_data = drvdata;
drvdata->pwm = devm_pwm_get(&pdev->dev, NULL);
if (IS_ERR(drvdata->pwm)) {
dev_err(&pdev->dev, "Failed to get PWM\n");
return PTR_ERR(drvdata->pwm);
}
regulator = devm_regulator_register(&pdev->dev,
&drvdata->desc, &config);
if (IS_ERR(regulator)) {
dev_err(&pdev->dev, "Failed to register regulator %s\n",
drvdata->desc.name);
return PTR_ERR(regulator);
}
return 0;
}
