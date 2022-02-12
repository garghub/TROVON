static bool find_voltage_set_register(struct max8973_chip *tps,
int req_vsel, int *vout_reg, int *gpio_val)
{
int i;
bool found = false;
int new_vout_reg = tps->lru_index[MAX8973_MAX_VOUT_REG - 1];
int found_index = MAX8973_MAX_VOUT_REG - 1;
for (i = 0; i < MAX8973_MAX_VOUT_REG; ++i) {
if (tps->curr_vout_val[tps->lru_index[i]] == req_vsel) {
new_vout_reg = tps->lru_index[i];
found_index = i;
found = true;
goto update_lru_index;
}
}
update_lru_index:
for (i = found_index; i > 0; i--)
tps->lru_index[i] = tps->lru_index[i - 1];
tps->lru_index[0] = new_vout_reg;
*gpio_val = new_vout_reg;
*vout_reg = MAX8973_VOUT + new_vout_reg;
return found;
}
static int max8973_dcdc_get_voltage_sel(struct regulator_dev *rdev)
{
struct max8973_chip *max = rdev_get_drvdata(rdev);
unsigned int data;
int ret;
ret = regmap_read(max->regmap, max->curr_vout_reg, &data);
if (ret < 0) {
dev_err(max->dev, "register %d read failed, err = %d\n",
max->curr_vout_reg, ret);
return ret;
}
return data & MAX8973_VOUT_MASK;
}
static int max8973_dcdc_set_voltage_sel(struct regulator_dev *rdev,
unsigned vsel)
{
struct max8973_chip *max = rdev_get_drvdata(rdev);
int ret;
bool found = false;
int vout_reg = max->curr_vout_reg;
int gpio_val = max->curr_gpio_val;
if (max->valid_dvs_gpio)
found = find_voltage_set_register(max, vsel,
&vout_reg, &gpio_val);
if (!found) {
ret = regmap_update_bits(max->regmap, vout_reg,
MAX8973_VOUT_MASK, vsel);
if (ret < 0) {
dev_err(max->dev, "register %d update failed, err %d\n",
vout_reg, ret);
return ret;
}
max->curr_vout_reg = vout_reg;
max->curr_vout_val[gpio_val] = vsel;
}
if (max->valid_dvs_gpio) {
gpio_set_value_cansleep(max->dvs_gpio, gpio_val & 0x1);
max->curr_gpio_val = gpio_val;
}
return 0;
}
static int max8973_dcdc_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct max8973_chip *max = rdev_get_drvdata(rdev);
int ret;
int pwm;
switch (mode) {
case REGULATOR_MODE_FAST:
pwm = MAX8973_FPWM_EN_M;
break;
case REGULATOR_MODE_NORMAL:
pwm = 0;
break;
default:
return -EINVAL;
}
ret = regmap_update_bits(max->regmap, MAX8973_CONTROL1,
MAX8973_FPWM_EN_M, pwm);
if (ret < 0)
dev_err(max->dev, "register %d update failed, err %d\n",
MAX8973_CONTROL1, ret);
return ret;
}
static unsigned int max8973_dcdc_get_mode(struct regulator_dev *rdev)
{
struct max8973_chip *max = rdev_get_drvdata(rdev);
unsigned int data;
int ret;
ret = regmap_read(max->regmap, MAX8973_CONTROL1, &data);
if (ret < 0) {
dev_err(max->dev, "register %d read failed, err %d\n",
MAX8973_CONTROL1, ret);
return ret;
}
return (data & MAX8973_FPWM_EN_M) ?
REGULATOR_MODE_FAST : REGULATOR_MODE_NORMAL;
}
static int max8973_init_dcdc(struct max8973_chip *max,
struct max8973_regulator_platform_data *pdata)
{
int ret;
uint8_t control1 = 0;
uint8_t control2 = 0;
if (pdata->control_flags & MAX8973_CONTROL_REMOTE_SENSE_ENABLE)
control1 |= MAX8973_SNS_ENABLE;
if (!(pdata->control_flags & MAX8973_CONTROL_FALLING_SLEW_RATE_ENABLE))
control1 |= MAX8973_NFSR_ENABLE;
if (pdata->control_flags & MAX8973_CONTROL_OUTPUT_ACTIVE_DISCH_ENABLE)
control1 |= MAX8973_AD_ENABLE;
if (pdata->control_flags & MAX8973_CONTROL_BIAS_ENABLE)
control1 |= MAX8973_BIAS_ENABLE;
if (pdata->control_flags & MAX8973_CONTROL_FREQ_SHIFT_9PER_ENABLE)
control1 |= MAX8973_FREQSHIFT_9PER;
if (pdata->reg_init_data &&
pdata->reg_init_data->constraints.ramp_delay) {
if (pdata->reg_init_data->constraints.ramp_delay < 25000)
control1 |= MAX8973_RAMP_12mV_PER_US;
else if (pdata->reg_init_data->constraints.ramp_delay < 50000)
control1 |= MAX8973_RAMP_25mV_PER_US;
else if (pdata->reg_init_data->constraints.ramp_delay < 200000)
control1 |= MAX8973_RAMP_50mV_PER_US;
else
control1 |= MAX8973_RAMP_200mV_PER_US;
} else {
control1 |= MAX8973_RAMP_12mV_PER_US;
max->desc.ramp_delay = 12500;
}
if (!(pdata->control_flags & MAX8973_CONTROL_PULL_DOWN_ENABLE))
control2 |= MAX8973_DISCH_ENBABLE;
switch (pdata->control_flags & MAX8973_CONTROL_CLKADV_TRIP_MASK) {
case MAX8973_CONTROL_CLKADV_TRIP_DISABLED:
control2 |= MAX8973_CKKADV_TRIP_DISABLE;
break;
case MAX8973_CONTROL_CLKADV_TRIP_75mV_PER_US:
control2 |= MAX8973_CKKADV_TRIP_75mV_PER_US;
break;
case MAX8973_CONTROL_CLKADV_TRIP_150mV_PER_US:
control2 |= MAX8973_CKKADV_TRIP_150mV_PER_US;
break;
case MAX8973_CONTROL_CLKADV_TRIP_75mV_PER_US_HIST_DIS:
control2 |= MAX8973_CKKADV_TRIP_75mV_PER_US_HIST_DIS;
break;
}
switch (pdata->control_flags & MAX8973_CONTROL_INDUCTOR_VALUE_MASK) {
case MAX8973_CONTROL_INDUCTOR_VALUE_NOMINAL:
control2 |= MAX8973_INDUCTOR_NOMINAL;
break;
case MAX8973_CONTROL_INDUCTOR_VALUE_MINUS_30_PER:
control2 |= MAX8973_INDUCTOR_MIN_30_PER;
break;
case MAX8973_CONTROL_INDUCTOR_VALUE_PLUS_30_PER:
control2 |= MAX8973_INDUCTOR_PLUS_30_PER;
break;
case MAX8973_CONTROL_INDUCTOR_VALUE_PLUS_60_PER:
control2 |= MAX8973_INDUCTOR_PLUS_60_PER;
break;
}
ret = regmap_write(max->regmap, MAX8973_CONTROL1, control1);
if (ret < 0) {
dev_err(max->dev, "register %d write failed, err = %d",
MAX8973_CONTROL1, ret);
return ret;
}
ret = regmap_write(max->regmap, MAX8973_CONTROL2, control2);
if (ret < 0) {
dev_err(max->dev, "register %d write failed, err = %d",
MAX8973_CONTROL2, ret);
return ret;
}
if (max->enable_external_control) {
ret = regmap_update_bits(max->regmap, MAX8973_VOUT,
MAX8973_VOUT_ENABLE, 0);
if (ret < 0)
dev_err(max->dev, "register %d update failed, err = %d",
MAX8973_VOUT, ret);
}
return ret;
}
static int max8973_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max8973_regulator_platform_data *pdata;
struct regulator_config config = { };
struct regulator_dev *rdev;
struct max8973_chip *max;
int ret;
pdata = client->dev.platform_data;
if (!pdata) {
dev_err(&client->dev, "No Platform data");
return -EIO;
}
max = devm_kzalloc(&client->dev, sizeof(*max), GFP_KERNEL);
if (!max) {
dev_err(&client->dev, "Memory allocation for max failed\n");
return -ENOMEM;
}
max->regmap = devm_regmap_init_i2c(client, &max8973_regmap_config);
if (IS_ERR(max->regmap)) {
ret = PTR_ERR(max->regmap);
dev_err(&client->dev, "regmap init failed, err %d\n", ret);
return ret;
}
i2c_set_clientdata(client, max);
max->dev = &client->dev;
max->desc.name = id->name;
max->desc.id = 0;
max->desc.ops = &max8973_dcdc_ops;
max->desc.type = REGULATOR_VOLTAGE;
max->desc.owner = THIS_MODULE;
max->desc.min_uV = MAX8973_MIN_VOLATGE;
max->desc.uV_step = MAX8973_VOLATGE_STEP;
max->desc.n_voltages = MAX8973_BUCK_N_VOLTAGE;
if (!pdata->enable_ext_control) {
max->desc.enable_reg = MAX8973_VOUT;
max->desc.enable_mask = MAX8973_VOUT_ENABLE;
max8973_dcdc_ops.enable = regulator_enable_regmap;
max8973_dcdc_ops.disable = regulator_disable_regmap;
max8973_dcdc_ops.is_enabled = regulator_is_enabled_regmap;
}
max->enable_external_control = pdata->enable_ext_control;
max->dvs_gpio = pdata->dvs_gpio;
max->curr_gpio_val = pdata->dvs_def_state;
max->curr_vout_reg = MAX8973_VOUT + pdata->dvs_def_state;
max->lru_index[0] = max->curr_vout_reg;
max->valid_dvs_gpio = false;
if (gpio_is_valid(max->dvs_gpio)) {
int gpio_flags;
int i;
gpio_flags = (pdata->dvs_def_state) ?
GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
ret = devm_gpio_request_one(&client->dev, max->dvs_gpio,
gpio_flags, "max8973-dvs");
if (ret) {
dev_err(&client->dev,
"gpio_request for gpio %d failed, err = %d\n",
max->dvs_gpio, ret);
return ret;
}
max->valid_dvs_gpio = true;
for (i = 0; i < MAX8973_MAX_VOUT_REG; ++i)
max->lru_index[i] = i;
max->lru_index[0] = max->curr_vout_reg;
max->lru_index[max->curr_vout_reg] = 0;
}
ret = max8973_init_dcdc(max, pdata);
if (ret < 0) {
dev_err(max->dev, "Max8973 Init failed, err = %d\n", ret);
return ret;
}
config.dev = &client->dev;
config.init_data = pdata->reg_init_data;
config.driver_data = max;
config.of_node = client->dev.of_node;
config.regmap = max->regmap;
rdev = regulator_register(&max->desc, &config);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(max->dev, "regulator register failed, err %d\n", ret);
return ret;
}
max->rdev = rdev;
return 0;
}
static int max8973_remove(struct i2c_client *client)
{
struct max8973_chip *max = i2c_get_clientdata(client);
regulator_unregister(max->rdev);
return 0;
}
static int __init max8973_init(void)
{
return i2c_add_driver(&max8973_i2c_driver);
}
static void __exit max8973_cleanup(void)
{
i2c_del_driver(&max8973_i2c_driver);
}
