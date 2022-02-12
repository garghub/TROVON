static int tps51632_dcdc_set_ramp_delay(struct regulator_dev *rdev,
int ramp_delay)
{
struct tps51632_chip *tps = rdev_get_drvdata(rdev);
int bit = ramp_delay/6000;
int ret;
if (bit)
bit--;
ret = regmap_write(tps->regmap, TPS51632_SLEW_REGS, BIT(bit));
if (ret < 0)
dev_err(tps->dev, "SLEW reg write failed, err %d\n", ret);
return ret;
}
static int tps51632_init_dcdc(struct tps51632_chip *tps,
struct tps51632_regulator_platform_data *pdata)
{
int ret;
uint8_t control = 0;
int vsel;
if (!pdata->enable_pwm_dvfs)
goto skip_pwm_config;
control |= TPS51632_DVFS_PWMEN;
vsel = TPS51632_VOLT_VSEL(pdata->base_voltage_uV);
ret = regmap_write(tps->regmap, TPS51632_VOLTAGE_BASE_REG, vsel);
if (ret < 0) {
dev_err(tps->dev, "BASE reg write failed, err %d\n", ret);
return ret;
}
if (pdata->dvfs_step_20mV)
control |= TPS51632_DVFS_STEP_20;
if (pdata->max_voltage_uV) {
unsigned int vmax;
ret = regmap_read(tps->regmap, TPS51632_VMAX_REG, &vmax);
if (ret < 0) {
dev_err(tps->dev, "VMAX read failed, err %d\n", ret);
return ret;
}
if (!(vmax & TPS51632_VMAX_LOCK)) {
vsel = TPS51632_VOLT_VSEL(pdata->max_voltage_uV);
ret = regmap_write(tps->regmap, TPS51632_VMAX_REG,
vsel);
if (ret < 0) {
dev_err(tps->dev,
"VMAX write failed, err %d\n", ret);
return ret;
}
}
}
skip_pwm_config:
ret = regmap_write(tps->regmap, TPS51632_DVFS_CONTROL_REG, control);
if (ret < 0)
dev_err(tps->dev, "DVFS reg write failed, err %d\n", ret);
return ret;
}
static bool is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS51632_OFFSET_REG:
case TPS51632_FAULT_REG:
case TPS51632_IMON_REG:
return true;
default:
return false;
}
}
static bool is_read_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0x08 ... 0x0F:
return false;
default:
return true;
}
}
static bool is_write_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS51632_VOLTAGE_SELECT_REG:
case TPS51632_VOLTAGE_BASE_REG:
case TPS51632_VMAX_REG:
case TPS51632_DVFS_CONTROL_REG:
case TPS51632_POWER_STATE_REG:
case TPS51632_SLEW_REGS:
return true;
default:
return false;
}
}
static struct tps51632_regulator_platform_data *
of_get_tps51632_platform_data(struct device *dev)
{
struct tps51632_regulator_platform_data *pdata;
struct device_node *np = dev->of_node;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(dev, "Memory alloc failed for platform data\n");
return NULL;
}
pdata->reg_init_data = of_get_regulator_init_data(dev, dev->of_node);
if (!pdata->reg_init_data) {
dev_err(dev, "Not able to get OF regulator init data\n");
return NULL;
}
pdata->enable_pwm_dvfs =
of_property_read_bool(np, "ti,enable-pwm-dvfs");
pdata->dvfs_step_20mV = of_property_read_bool(np, "ti,dvfs-step-20mV");
pdata->base_voltage_uV = pdata->reg_init_data->constraints.min_uV ? :
TPS51632_MIN_VOLATGE;
pdata->max_voltage_uV = pdata->reg_init_data->constraints.max_uV ? :
TPS51632_MAX_VOLATGE;
return pdata;
}
static struct tps51632_regulator_platform_data *
of_get_tps51632_platform_data(struct device *dev)
{
return NULL;
}
static int tps51632_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tps51632_regulator_platform_data *pdata;
struct regulator_dev *rdev;
struct tps51632_chip *tps;
int ret;
struct regulator_config config = { };
if (client->dev.of_node) {
const struct of_device_id *match;
match = of_match_device(of_match_ptr(tps51632_of_match),
&client->dev);
if (!match) {
dev_err(&client->dev, "Error: No device match found\n");
return -ENODEV;
}
}
pdata = client->dev.platform_data;
if (!pdata && client->dev.of_node)
pdata = of_get_tps51632_platform_data(&client->dev);
if (!pdata) {
dev_err(&client->dev, "No Platform data\n");
return -EINVAL;
}
if (pdata->enable_pwm_dvfs) {
if ((pdata->base_voltage_uV < TPS51632_MIN_VOLATGE) ||
(pdata->base_voltage_uV > TPS51632_MAX_VOLATGE)) {
dev_err(&client->dev, "Invalid base_voltage_uV setting\n");
return -EINVAL;
}
if ((pdata->max_voltage_uV) &&
((pdata->max_voltage_uV < TPS51632_MIN_VOLATGE) ||
(pdata->max_voltage_uV > TPS51632_MAX_VOLATGE))) {
dev_err(&client->dev, "Invalid max_voltage_uV setting\n");
return -EINVAL;
}
}
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps) {
dev_err(&client->dev, "Memory allocation failed\n");
return -ENOMEM;
}
tps->dev = &client->dev;
tps->desc.name = id->name;
tps->desc.id = 0;
tps->desc.ramp_delay = TPS51632_DEFAULT_RAMP_DELAY;
tps->desc.min_uV = TPS51632_MIN_VOLATGE;
tps->desc.uV_step = TPS51632_VOLATGE_STEP_10mV;
tps->desc.linear_min_sel = TPS51632_MIN_VSEL;
tps->desc.n_voltages = TPS51632_MAX_VSEL + 1;
tps->desc.ops = &tps51632_dcdc_ops;
tps->desc.type = REGULATOR_VOLTAGE;
tps->desc.owner = THIS_MODULE;
if (pdata->enable_pwm_dvfs)
tps->desc.vsel_reg = TPS51632_VOLTAGE_BASE_REG;
else
tps->desc.vsel_reg = TPS51632_VOLTAGE_SELECT_REG;
tps->desc.vsel_mask = TPS51632_VOUT_MASK;
tps->regmap = devm_regmap_init_i2c(client, &tps51632_regmap_config);
if (IS_ERR(tps->regmap)) {
ret = PTR_ERR(tps->regmap);
dev_err(&client->dev, "regmap init failed, err %d\n", ret);
return ret;
}
i2c_set_clientdata(client, tps);
ret = tps51632_init_dcdc(tps, pdata);
if (ret < 0) {
dev_err(tps->dev, "Init failed, err = %d\n", ret);
return ret;
}
config.dev = &client->dev;
config.init_data = pdata->reg_init_data;
config.driver_data = tps;
config.regmap = tps->regmap;
config.of_node = client->dev.of_node;
rdev = regulator_register(&tps->desc, &config);
if (IS_ERR(rdev)) {
dev_err(tps->dev, "regulator register failed\n");
return PTR_ERR(rdev);
}
tps->rdev = rdev;
return 0;
}
static int tps51632_remove(struct i2c_client *client)
{
struct tps51632_chip *tps = i2c_get_clientdata(client);
regulator_unregister(tps->rdev);
return 0;
}
static int __init tps51632_init(void)
{
return i2c_add_driver(&tps51632_i2c_driver);
}
static void __exit tps51632_cleanup(void)
{
i2c_del_driver(&tps51632_i2c_driver);
}
