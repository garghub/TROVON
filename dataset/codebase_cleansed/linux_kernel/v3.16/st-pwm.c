static int st_pwm_regulator_get_voltage_sel(struct regulator_dev *dev)
{
struct st_pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
return drvdata->state;
}
static int st_pwm_regulator_set_voltage_sel(struct regulator_dev *dev,
unsigned selector)
{
struct st_pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
int dutycycle;
int ret;
dutycycle = (ST_PWM_REG_PERIOD / 100) *
drvdata->pdata->duty_cycle_table[selector].dutycycle;
ret = pwm_config(drvdata->pwm, dutycycle, ST_PWM_REG_PERIOD);
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
static int st_pwm_regulator_list_voltage(struct regulator_dev *dev,
unsigned selector)
{
struct st_pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
if (selector >= dev->desc->n_voltages)
return -EINVAL;
return drvdata->pdata->duty_cycle_table[selector].uV;
}
static int st_pwm_regulator_probe(struct platform_device *pdev)
{
struct st_pwm_regulator_data *drvdata;
struct regulator_dev *regulator;
struct regulator_config config = { };
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_match;
if (!np) {
dev_err(&pdev->dev, "Device Tree node missing\n");
return -EINVAL;
}
drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
of_match = of_match_device(st_pwm_of_match, &pdev->dev);
if (!of_match) {
dev_err(&pdev->dev, "failed to match of device\n");
return -ENODEV;
}
drvdata->pdata = of_match->data;
config.init_data = of_get_regulator_init_data(&pdev->dev, np);
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
drvdata->pdata->desc, &config);
if (IS_ERR(regulator)) {
dev_err(&pdev->dev, "Failed to register regulator %s\n",
drvdata->pdata->desc->name);
return PTR_ERR(regulator);
}
return 0;
}
