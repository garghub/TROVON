static int pwm_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(rdev);
return drvdata->state;
}
static int pwm_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(rdev);
struct pwm_args pargs;
int dutycycle;
int ret;
pwm_get_args(drvdata->pwm, &pargs);
dutycycle = (pargs.period *
drvdata->duty_cycle_table[selector].dutycycle) / 100;
ret = pwm_config(drvdata->pwm, dutycycle, pargs.period);
if (ret) {
dev_err(&rdev->dev, "Failed to configure PWM: %d\n", ret);
return ret;
}
drvdata->state = selector;
return 0;
}
static int pwm_regulator_list_voltage(struct regulator_dev *rdev,
unsigned selector)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(rdev);
if (selector >= rdev->desc->n_voltages)
return -EINVAL;
return drvdata->duty_cycle_table[selector].uV;
}
static int pwm_regulator_enable(struct regulator_dev *dev)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
return pwm_enable(drvdata->pwm);
}
static int pwm_regulator_disable(struct regulator_dev *dev)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
pwm_disable(drvdata->pwm);
return 0;
}
static int pwm_regulator_is_enabled(struct regulator_dev *dev)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(dev);
return pwm_is_enabled(drvdata->pwm);
}
static int pwm_regulator_get_voltage(struct regulator_dev *rdev)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(rdev);
return drvdata->volt_uV;
}
static int pwm_regulator_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV,
unsigned *selector)
{
struct pwm_regulator_data *drvdata = rdev_get_drvdata(rdev);
unsigned int ramp_delay = rdev->constraints->ramp_delay;
struct pwm_args pargs;
unsigned int req_diff = min_uV - rdev->constraints->min_uV;
unsigned int diff;
unsigned int duty_pulse;
u64 req_period;
u32 rem;
int ret;
pwm_get_args(drvdata->pwm, &pargs);
diff = rdev->constraints->max_uV - rdev->constraints->min_uV;
req_period = req_diff * pargs.period;
div_u64_rem(req_period, diff, &rem);
if (!rem) {
do_div(req_period, diff);
duty_pulse = (unsigned int)req_period;
} else {
duty_pulse = (pargs.period / 100) * ((req_diff * 100) / diff);
}
ret = pwm_config(drvdata->pwm, duty_pulse, pargs.period);
if (ret) {
dev_err(&rdev->dev, "Failed to configure PWM: %d\n", ret);
return ret;
}
ret = pwm_enable(drvdata->pwm);
if (ret) {
dev_err(&rdev->dev, "Failed to enable PWM: %d\n", ret);
return ret;
}
drvdata->volt_uV = min_uV;
usleep_range(ramp_delay, ramp_delay + 1000);
return 0;
}
static int pwm_regulator_init_table(struct platform_device *pdev,
struct pwm_regulator_data *drvdata)
{
struct device_node *np = pdev->dev.of_node;
struct pwm_voltages *duty_cycle_table;
unsigned int length = 0;
int ret;
of_find_property(np, "voltage-table", &length);
if ((length < sizeof(*duty_cycle_table)) ||
(length % sizeof(*duty_cycle_table))) {
dev_err(&pdev->dev, "voltage-table length(%d) is invalid\n",
length);
return -EINVAL;
}
duty_cycle_table = devm_kzalloc(&pdev->dev, length, GFP_KERNEL);
if (!duty_cycle_table)
return -ENOMEM;
ret = of_property_read_u32_array(np, "voltage-table",
(u32 *)duty_cycle_table,
length / sizeof(u32));
if (ret) {
dev_err(&pdev->dev, "Failed to read voltage-table: %d\n", ret);
return ret;
}
drvdata->duty_cycle_table = duty_cycle_table;
memcpy(&drvdata->ops, &pwm_regulator_voltage_table_ops,
sizeof(drvdata->ops));
drvdata->desc.ops = &drvdata->ops;
drvdata->desc.n_voltages = length / sizeof(*duty_cycle_table);
return 0;
}
static int pwm_regulator_init_continuous(struct platform_device *pdev,
struct pwm_regulator_data *drvdata)
{
memcpy(&drvdata->ops, &pwm_regulator_voltage_continuous_ops,
sizeof(drvdata->ops));
drvdata->desc.ops = &drvdata->ops;
drvdata->desc.continuous_voltage_range = true;
return 0;
}
static int pwm_regulator_probe(struct platform_device *pdev)
{
const struct regulator_init_data *init_data;
struct pwm_regulator_data *drvdata;
struct regulator_dev *regulator;
struct regulator_config config = { };
struct device_node *np = pdev->dev.of_node;
int ret;
if (!np) {
dev_err(&pdev->dev, "Device Tree node missing\n");
return -EINVAL;
}
drvdata = devm_kzalloc(&pdev->dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
memcpy(&drvdata->desc, &pwm_regulator_desc, sizeof(drvdata->desc));
if (of_find_property(np, "voltage-table", NULL))
ret = pwm_regulator_init_table(pdev, drvdata);
else
ret = pwm_regulator_init_continuous(pdev, drvdata);
if (ret)
return ret;
init_data = of_get_regulator_init_data(&pdev->dev, np,
&drvdata->desc);
if (!init_data)
return -ENOMEM;
config.of_node = np;
config.dev = &pdev->dev;
config.driver_data = drvdata;
config.init_data = init_data;
drvdata->pwm = devm_pwm_get(&pdev->dev, NULL);
if (IS_ERR(drvdata->pwm)) {
ret = PTR_ERR(drvdata->pwm);
dev_err(&pdev->dev, "Failed to get PWM: %d\n", ret);
return ret;
}
pwm_apply_args(drvdata->pwm);
regulator = devm_regulator_register(&pdev->dev,
&drvdata->desc, &config);
if (IS_ERR(regulator)) {
ret = PTR_ERR(regulator);
dev_err(&pdev->dev, "Failed to register regulator %s: %d\n",
drvdata->desc.name, ret);
return ret;
}
return 0;
}
