static inline int convert_bin_to_uAh(
const struct ltc294x_info *info, int Q)
{
return ((Q * (info->Qlsb / 10))) / 100;
}
static inline int convert_uAh_to_bin(
const struct ltc294x_info *info, int uAh)
{
int Q;
Q = (uAh * 100) / (info->Qlsb/10);
return (Q < LTC294X_MAX_VALUE) ? Q : LTC294X_MAX_VALUE;
}
static int ltc294x_read_regs(struct i2c_client *client,
enum ltc294x_reg reg, u8 *buf, int num_regs)
{
int ret;
struct i2c_msg msgs[2] = { };
u8 reg_start = reg;
msgs[0].addr = client->addr;
msgs[0].len = 1;
msgs[0].buf = &reg_start;
msgs[1].addr = client->addr;
msgs[1].len = num_regs;
msgs[1].buf = buf;
msgs[1].flags = I2C_M_RD;
ret = i2c_transfer(client->adapter, &msgs[0], 2);
if (ret < 0) {
dev_err(&client->dev, "ltc2941 read_reg failed!\n");
return ret;
}
dev_dbg(&client->dev, "%s (%#x, %d) -> %#x\n",
__func__, reg, num_regs, *buf);
return 0;
}
static int ltc294x_write_regs(struct i2c_client *client,
enum ltc294x_reg reg, const u8 *buf, int num_regs)
{
int ret;
u8 reg_start = reg;
ret = i2c_smbus_write_i2c_block_data(client, reg_start, num_regs, buf);
if (ret < 0) {
dev_err(&client->dev, "ltc2941 write_reg failed!\n");
return ret;
}
dev_dbg(&client->dev, "%s (%#x, %d) -> %#x\n",
__func__, reg, num_regs, *buf);
return 0;
}
static int ltc294x_reset(const struct ltc294x_info *info, int prescaler_exp)
{
int ret;
u8 value;
u8 control;
ret = ltc294x_read_regs(info->client, LTC294X_REG_CONTROL, &value, 1);
if (ret < 0) {
dev_err(&info->client->dev,
"Could not read registers from device\n");
goto error_exit;
}
control = LTC294X_REG_CONTROL_PRESCALER_SET(prescaler_exp) |
LTC294X_REG_CONTROL_ALCC_CONFIG_DISABLED;
if (info->num_regs == LTC2943_NUM_REGS)
control |= LTC2943_REG_CONTROL_MODE_SCAN;
if (value != control) {
ret = ltc294x_write_regs(info->client,
LTC294X_REG_CONTROL, &control, 1);
if (ret < 0) {
dev_err(&info->client->dev,
"Could not write register\n");
goto error_exit;
}
}
return 0;
error_exit:
return ret;
}
static int ltc294x_read_charge_register(const struct ltc294x_info *info)
{
int ret;
u8 datar[2];
ret = ltc294x_read_regs(info->client,
LTC294X_REG_ACC_CHARGE_MSB, &datar[0], 2);
if (ret < 0)
return ret;
return (datar[0] << 8) + datar[1];
}
static int ltc294x_get_charge_now(const struct ltc294x_info *info, int *val)
{
int value = ltc294x_read_charge_register(info);
if (value < 0)
return value;
if (info->Qlsb < 0)
value -= 0xFFFF;
*val = convert_bin_to_uAh(info, value);
return 0;
}
static int ltc294x_set_charge_now(const struct ltc294x_info *info, int val)
{
int ret;
u8 dataw[2];
u8 ctrl_reg;
s32 value;
value = convert_uAh_to_bin(info, val);
if (info->Qlsb < 0)
value += 0xFFFF;
if ((value < 0) || (value > 0xFFFF))
return -EINVAL;
ret = ltc294x_read_regs(info->client,
LTC294X_REG_CONTROL, &ctrl_reg, 1);
if (ret < 0)
return ret;
ctrl_reg |= LTC294X_REG_CONTROL_SHUTDOWN_MASK;
ret = ltc294x_write_regs(info->client,
LTC294X_REG_CONTROL, &ctrl_reg, 1);
if (ret < 0)
return ret;
dataw[0] = I16_MSB(value);
dataw[1] = I16_LSB(value);
ret = ltc294x_write_regs(info->client,
LTC294X_REG_ACC_CHARGE_MSB, &dataw[0], 2);
if (ret < 0)
goto error_exit;
error_exit:
ctrl_reg &= ~LTC294X_REG_CONTROL_SHUTDOWN_MASK;
ret = ltc294x_write_regs(info->client,
LTC294X_REG_CONTROL, &ctrl_reg, 1);
return ret < 0 ? ret : 0;
}
static int ltc294x_get_charge_counter(
const struct ltc294x_info *info, int *val)
{
int value = ltc294x_read_charge_register(info);
if (value < 0)
return value;
value -= LTC294X_MID_SUPPLY;
*val = convert_bin_to_uAh(info, value);
return 0;
}
static int ltc294x_get_voltage(const struct ltc294x_info *info, int *val)
{
int ret;
u8 datar[2];
u32 value;
ret = ltc294x_read_regs(info->client,
LTC294X_REG_VOLTAGE_MSB, &datar[0], 2);
value = (datar[0] << 8) | datar[1];
*val = ((value * 23600) / 0xFFFF) * 1000;
return ret;
}
static int ltc294x_get_current(const struct ltc294x_info *info, int *val)
{
int ret;
u8 datar[2];
s32 value;
ret = ltc294x_read_regs(info->client,
LTC294X_REG_CURRENT_MSB, &datar[0], 2);
value = (datar[0] << 8) | datar[1];
value -= 0x7FFF;
*val = 1000 * ((60000 * value) / (info->r_sense * 0x7FFF));
return ret;
}
static int ltc294x_get_temperature(const struct ltc294x_info *info, int *val)
{
int ret;
u8 datar[2];
u32 value;
ret = ltc294x_read_regs(info->client,
LTC294X_REG_TEMPERATURE_MSB, &datar[0], 2);
value = (datar[0] << 8) | datar[1];
*val = (((51000 * value) / 0xFFFF) - 27215);
return ret;
}
static int ltc294x_get_property(struct power_supply *psy,
enum power_supply_property prop,
union power_supply_propval *val)
{
struct ltc294x_info *info = power_supply_get_drvdata(psy);
switch (prop) {
case POWER_SUPPLY_PROP_CHARGE_NOW:
return ltc294x_get_charge_now(info, &val->intval);
case POWER_SUPPLY_PROP_CHARGE_COUNTER:
return ltc294x_get_charge_counter(info, &val->intval);
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
return ltc294x_get_voltage(info, &val->intval);
case POWER_SUPPLY_PROP_CURRENT_NOW:
return ltc294x_get_current(info, &val->intval);
case POWER_SUPPLY_PROP_TEMP:
return ltc294x_get_temperature(info, &val->intval);
default:
return -EINVAL;
}
}
static int ltc294x_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct ltc294x_info *info = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_NOW:
return ltc294x_set_charge_now(info, val->intval);
default:
return -EPERM;
}
}
static int ltc294x_property_is_writeable(
struct power_supply *psy, enum power_supply_property psp)
{
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_NOW:
return 1;
default:
return 0;
}
}
static void ltc294x_update(struct ltc294x_info *info)
{
int charge = ltc294x_read_charge_register(info);
if (charge != info->charge) {
info->charge = charge;
power_supply_changed(info->supply);
}
}
static void ltc294x_work(struct work_struct *work)
{
struct ltc294x_info *info;
info = container_of(work, struct ltc294x_info, work.work);
ltc294x_update(info);
schedule_delayed_work(&info->work, LTC294X_WORK_DELAY * HZ);
}
static int ltc294x_i2c_remove(struct i2c_client *client)
{
struct ltc294x_info *info = i2c_get_clientdata(client);
cancel_delayed_work(&info->work);
power_supply_unregister(info->supply);
return 0;
}
static int ltc294x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct power_supply_config psy_cfg = {};
struct ltc294x_info *info;
int ret;
u32 prescaler_exp;
s32 r_sense;
struct device_node *np;
info = devm_kzalloc(&client->dev, sizeof(*info), GFP_KERNEL);
if (info == NULL)
return -ENOMEM;
i2c_set_clientdata(client, info);
np = of_node_get(client->dev.of_node);
info->num_regs = (unsigned long)of_device_get_match_data(&client->dev);
info->supply_desc.name = np->name;
ret = of_property_read_u32(np, "lltc,resistor-sense", &r_sense);
if (ret < 0) {
dev_err(&client->dev,
"Could not find lltc,resistor-sense in devicetree\n");
return ret;
}
info->r_sense = r_sense;
ret = of_property_read_u32(np, "lltc,prescaler-exponent",
&prescaler_exp);
if (ret < 0) {
dev_warn(&client->dev,
"lltc,prescaler-exponent not in devicetree\n");
prescaler_exp = LTC2941_MAX_PRESCALER_EXP;
}
if (info->num_regs == LTC2943_NUM_REGS) {
if (prescaler_exp > LTC2943_MAX_PRESCALER_EXP)
prescaler_exp = LTC2943_MAX_PRESCALER_EXP;
info->Qlsb = ((340 * 50000) / r_sense) /
(4096 / (1 << (2*prescaler_exp)));
} else {
if (prescaler_exp > LTC2941_MAX_PRESCALER_EXP)
prescaler_exp = LTC2941_MAX_PRESCALER_EXP;
info->Qlsb = ((85 * 50000) / r_sense) /
(128 / (1 << prescaler_exp));
}
info->client = client;
info->supply_desc.type = POWER_SUPPLY_TYPE_BATTERY;
info->supply_desc.properties = ltc294x_properties;
if (info->num_regs >= LTC294X_REG_TEMPERATURE_LSB)
info->supply_desc.num_properties =
ARRAY_SIZE(ltc294x_properties);
else if (info->num_regs >= LTC294X_REG_CURRENT_LSB)
info->supply_desc.num_properties =
ARRAY_SIZE(ltc294x_properties) - 1;
else if (info->num_regs >= LTC294X_REG_VOLTAGE_LSB)
info->supply_desc.num_properties =
ARRAY_SIZE(ltc294x_properties) - 2;
else
info->supply_desc.num_properties =
ARRAY_SIZE(ltc294x_properties) - 3;
info->supply_desc.get_property = ltc294x_get_property;
info->supply_desc.set_property = ltc294x_set_property;
info->supply_desc.property_is_writeable = ltc294x_property_is_writeable;
info->supply_desc.external_power_changed = NULL;
psy_cfg.drv_data = info;
INIT_DELAYED_WORK(&info->work, ltc294x_work);
ret = ltc294x_reset(info, prescaler_exp);
if (ret < 0) {
dev_err(&client->dev, "Communication with chip failed\n");
return ret;
}
info->supply = power_supply_register(&client->dev, &info->supply_desc,
&psy_cfg);
if (IS_ERR(info->supply)) {
dev_err(&client->dev, "failed to register ltc2941\n");
return PTR_ERR(info->supply);
} else {
schedule_delayed_work(&info->work, LTC294X_WORK_DELAY * HZ);
}
return 0;
}
static int ltc294x_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ltc294x_info *info = i2c_get_clientdata(client);
cancel_delayed_work(&info->work);
return 0;
}
static int ltc294x_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ltc294x_info *info = i2c_get_clientdata(client);
schedule_delayed_work(&info->work, LTC294X_WORK_DELAY * HZ);
return 0;
}
