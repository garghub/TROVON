static int bq2415x_i2c_read(struct bq2415x_device *bq, u8 reg)
{
struct i2c_client *client = to_i2c_client(bq->dev);
struct i2c_msg msg[2];
u8 val;
int ret;
if (!client->adapter)
return -ENODEV;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].buf = &reg;
msg[0].len = sizeof(reg);
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = &val;
msg[1].len = sizeof(val);
mutex_lock(&bq2415x_i2c_mutex);
ret = i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg));
mutex_unlock(&bq2415x_i2c_mutex);
if (ret < 0)
return ret;
return val;
}
static int bq2415x_i2c_read_mask(struct bq2415x_device *bq, u8 reg,
u8 mask, u8 shift)
{
int ret;
if (shift > 8)
return -EINVAL;
ret = bq2415x_i2c_read(bq, reg);
if (ret < 0)
return ret;
return (ret & mask) >> shift;
}
static int bq2415x_i2c_read_bit(struct bq2415x_device *bq, u8 reg, u8 bit)
{
if (bit > 8)
return -EINVAL;
return bq2415x_i2c_read_mask(bq, reg, BIT(bit), bit);
}
static int bq2415x_i2c_write(struct bq2415x_device *bq, u8 reg, u8 val)
{
struct i2c_client *client = to_i2c_client(bq->dev);
struct i2c_msg msg[1];
u8 data[2];
int ret;
data[0] = reg;
data[1] = val;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].buf = data;
msg[0].len = ARRAY_SIZE(data);
mutex_lock(&bq2415x_i2c_mutex);
ret = i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg));
mutex_unlock(&bq2415x_i2c_mutex);
if (ret < 0)
return ret;
else if (ret != 1)
return -EIO;
return 0;
}
static int bq2415x_i2c_write_mask(struct bq2415x_device *bq, u8 reg, u8 val,
u8 mask, u8 shift)
{
int ret;
if (shift > 8)
return -EINVAL;
ret = bq2415x_i2c_read(bq, reg);
if (ret < 0)
return ret;
ret &= ~mask;
ret |= val << shift;
return bq2415x_i2c_write(bq, reg, ret);
}
static int bq2415x_i2c_write_bit(struct bq2415x_device *bq, u8 reg,
bool val, u8 bit)
{
if (bit > 8)
return -EINVAL;
return bq2415x_i2c_write_mask(bq, reg, val, BIT(bit), bit);
}
static int bq2415x_exec_command(struct bq2415x_device *bq,
enum bq2415x_command command)
{
int ret;
switch (command) {
case BQ2415X_TIMER_RESET:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_STATUS,
1, BQ2415X_BIT_TMR_RST);
case BQ2415X_OTG_STATUS:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_STATUS,
BQ2415X_BIT_OTG);
case BQ2415X_STAT_PIN_STATUS:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_STATUS,
BQ2415X_BIT_EN_STAT);
case BQ2415X_STAT_PIN_ENABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_STATUS, 1,
BQ2415X_BIT_EN_STAT);
case BQ2415X_STAT_PIN_DISABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_STATUS, 0,
BQ2415X_BIT_EN_STAT);
case BQ2415X_CHARGE_STATUS:
return bq2415x_i2c_read_mask(bq, BQ2415X_REG_STATUS,
BQ2415X_MASK_STAT, BQ2415X_SHIFT_STAT);
case BQ2415X_BOOST_STATUS:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_STATUS,
BQ2415X_BIT_BOOST);
case BQ2415X_FAULT_STATUS:
return bq2415x_i2c_read_mask(bq, BQ2415X_REG_STATUS,
BQ2415X_MASK_FAULT, BQ2415X_SHIFT_FAULT);
case BQ2415X_CHARGE_TERMINATION_STATUS:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_CONTROL,
BQ2415X_BIT_TE);
case BQ2415X_CHARGE_TERMINATION_ENABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
1, BQ2415X_BIT_TE);
case BQ2415X_CHARGE_TERMINATION_DISABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
0, BQ2415X_BIT_TE);
case BQ2415X_CHARGER_STATUS:
ret = bq2415x_i2c_read_bit(bq, BQ2415X_REG_CONTROL,
BQ2415X_BIT_CE);
if (ret < 0)
return ret;
else
return ret > 0 ? 0 : 1;
case BQ2415X_CHARGER_ENABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
0, BQ2415X_BIT_CE);
case BQ2415X_CHARGER_DISABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
1, BQ2415X_BIT_CE);
case BQ2415X_HIGH_IMPEDANCE_STATUS:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_CONTROL,
BQ2415X_BIT_HZ_MODE);
case BQ2415X_HIGH_IMPEDANCE_ENABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
1, BQ2415X_BIT_HZ_MODE);
case BQ2415X_HIGH_IMPEDANCE_DISABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
0, BQ2415X_BIT_HZ_MODE);
case BQ2415X_BOOST_MODE_STATUS:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_CONTROL,
BQ2415X_BIT_OPA_MODE);
case BQ2415X_BOOST_MODE_ENABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
1, BQ2415X_BIT_OPA_MODE);
case BQ2415X_BOOST_MODE_DISABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_CONTROL,
0, BQ2415X_BIT_OPA_MODE);
case BQ2415X_OTG_LEVEL:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_VOLTAGE,
BQ2415X_BIT_OTG_PL);
case BQ2415X_OTG_ACTIVATE_HIGH:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_VOLTAGE,
1, BQ2415X_BIT_OTG_PL);
case BQ2415X_OTG_ACTIVATE_LOW:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_VOLTAGE,
0, BQ2415X_BIT_OTG_PL);
case BQ2415X_OTG_PIN_STATUS:
return bq2415x_i2c_read_bit(bq, BQ2415X_REG_VOLTAGE,
BQ2415X_BIT_OTG_EN);
case BQ2415X_OTG_PIN_ENABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_VOLTAGE,
1, BQ2415X_BIT_OTG_EN);
case BQ2415X_OTG_PIN_DISABLE:
return bq2415x_i2c_write_bit(bq, BQ2415X_REG_VOLTAGE,
0, BQ2415X_BIT_OTG_EN);
case BQ2415X_VENDER_CODE:
return bq2415x_i2c_read_mask(bq, BQ2415X_REG_VENDER,
BQ2415X_MASK_VENDER, BQ2415X_SHIFT_VENDER);
case BQ2415X_PART_NUMBER:
return bq2415x_i2c_read_mask(bq, BQ2415X_REG_VENDER,
BQ2415X_MASK_PN, BQ2415X_SHIFT_PN);
case BQ2415X_REVISION:
return bq2415x_i2c_read_mask(bq, BQ2415X_REG_VENDER,
BQ2415X_MASK_REVISION, BQ2415X_SHIFT_REVISION);
}
return -EINVAL;
}
static enum bq2415x_chip bq2415x_detect_chip(struct bq2415x_device *bq)
{
struct i2c_client *client = to_i2c_client(bq->dev);
int ret = bq2415x_exec_command(bq, BQ2415X_PART_NUMBER);
if (ret < 0)
return ret;
switch (client->addr) {
case 0x6b:
switch (ret) {
case 0:
if (bq->chip == BQ24151A)
return bq->chip;
else
return BQ24151;
case 1:
if (bq->chip == BQ24150A ||
bq->chip == BQ24152 ||
bq->chip == BQ24155)
return bq->chip;
else
return BQ24150;
case 2:
if (bq->chip == BQ24153A)
return bq->chip;
else
return BQ24153;
default:
return BQUNKNOWN;
}
break;
case 0x6a:
switch (ret) {
case 0:
if (bq->chip == BQ24156A)
return bq->chip;
else
return BQ24156;
case 2:
return BQ24158;
default:
return BQUNKNOWN;
}
break;
}
return BQUNKNOWN;
}
static int bq2415x_detect_revision(struct bq2415x_device *bq)
{
int ret = bq2415x_exec_command(bq, BQ2415X_REVISION);
int chip = bq2415x_detect_chip(bq);
if (ret < 0 || chip < 0)
return -1;
switch (chip) {
case BQ24150:
case BQ24150A:
case BQ24151:
case BQ24151A:
case BQ24152:
if (ret >= 0 && ret <= 3)
return ret;
else
return -1;
case BQ24153:
case BQ24153A:
case BQ24156:
case BQ24156A:
case BQ24158:
if (ret == 3)
return 0;
else if (ret == 1)
return 1;
else
return -1;
case BQ24155:
if (ret == 3)
return 3;
else
return -1;
case BQUNKNOWN:
return -1;
}
return -1;
}
static int bq2415x_get_vender_code(struct bq2415x_device *bq)
{
int ret;
ret = bq2415x_exec_command(bq, BQ2415X_VENDER_CODE);
if (ret < 0)
return 0;
return (ret & 0x1) +
((ret >> 1) & 0x1) * 10 +
((ret >> 2) & 0x1) * 100;
}
static void bq2415x_reset_chip(struct bq2415x_device *bq)
{
bq2415x_i2c_write(bq, BQ2415X_REG_CURRENT, BQ2415X_RESET_CURRENT);
bq2415x_i2c_write(bq, BQ2415X_REG_VOLTAGE, BQ2415X_RESET_VOLTAGE);
bq2415x_i2c_write(bq, BQ2415X_REG_CONTROL, BQ2415X_RESET_CONTROL);
bq2415x_i2c_write(bq, BQ2415X_REG_STATUS, BQ2415X_RESET_STATUS);
bq->timer_error = NULL;
}
static int bq2415x_set_current_limit(struct bq2415x_device *bq, int mA)
{
int val;
if (mA <= 100)
val = 0;
else if (mA <= 500)
val = 1;
else if (mA <= 800)
val = 2;
else
val = 3;
return bq2415x_i2c_write_mask(bq, BQ2415X_REG_CONTROL, val,
BQ2415X_MASK_LIMIT, BQ2415X_SHIFT_LIMIT);
}
static int bq2415x_get_current_limit(struct bq2415x_device *bq)
{
int ret;
ret = bq2415x_i2c_read_mask(bq, BQ2415X_REG_CONTROL,
BQ2415X_MASK_LIMIT, BQ2415X_SHIFT_LIMIT);
if (ret < 0)
return ret;
else if (ret == 0)
return 100;
else if (ret == 1)
return 500;
else if (ret == 2)
return 800;
else if (ret == 3)
return 1800;
return -EINVAL;
}
static int bq2415x_set_weak_battery_voltage(struct bq2415x_device *bq, int mV)
{
int val;
if (mV <= 3400 + 50)
val = 0;
else if (mV <= 3500 + 50)
val = 1;
else if (mV <= 3600 + 50)
val = 2;
else
val = 3;
return bq2415x_i2c_write_mask(bq, BQ2415X_REG_CONTROL, val,
BQ2415X_MASK_VLOWV, BQ2415X_SHIFT_VLOWV);
}
static int bq2415x_get_weak_battery_voltage(struct bq2415x_device *bq)
{
int ret;
ret = bq2415x_i2c_read_mask(bq, BQ2415X_REG_CONTROL,
BQ2415X_MASK_VLOWV, BQ2415X_SHIFT_VLOWV);
if (ret < 0)
return ret;
return 100 * (34 + ret);
}
static int bq2415x_set_battery_regulation_voltage(struct bq2415x_device *bq,
int mV)
{
int val = (mV/10 - 350) / 2;
if (val < 0)
val = 0;
else if (val > 94)
return -EINVAL;
return bq2415x_i2c_write_mask(bq, BQ2415X_REG_VOLTAGE, val,
BQ2415X_MASK_VO, BQ2415X_SHIFT_VO);
}
static int bq2415x_get_battery_regulation_voltage(struct bq2415x_device *bq)
{
int ret = bq2415x_i2c_read_mask(bq, BQ2415X_REG_VOLTAGE,
BQ2415X_MASK_VO, BQ2415X_SHIFT_VO);
if (ret < 0)
return ret;
return 10 * (350 + 2*ret);
}
static int bq2415x_set_charge_current(struct bq2415x_device *bq, int mA)
{
int val;
if (bq->init_data.resistor_sense <= 0)
return -ENOSYS;
val = (mA * bq->init_data.resistor_sense - 37400) / 6800;
if (val < 0)
val = 0;
else if (val > 7)
val = 7;
return bq2415x_i2c_write_mask(bq, BQ2415X_REG_CURRENT, val,
BQ2415X_MASK_VI_CHRG | BQ2415X_MASK_RESET,
BQ2415X_SHIFT_VI_CHRG);
}
static int bq2415x_get_charge_current(struct bq2415x_device *bq)
{
int ret;
if (bq->init_data.resistor_sense <= 0)
return -ENOSYS;
ret = bq2415x_i2c_read_mask(bq, BQ2415X_REG_CURRENT,
BQ2415X_MASK_VI_CHRG, BQ2415X_SHIFT_VI_CHRG);
if (ret < 0)
return ret;
return (37400 + 6800*ret) / bq->init_data.resistor_sense;
}
static int bq2415x_set_termination_current(struct bq2415x_device *bq, int mA)
{
int val;
if (bq->init_data.resistor_sense <= 0)
return -ENOSYS;
val = (mA * bq->init_data.resistor_sense - 3400) / 3400;
if (val < 0)
val = 0;
else if (val > 7)
val = 7;
return bq2415x_i2c_write_mask(bq, BQ2415X_REG_CURRENT, val,
BQ2415X_MASK_VI_TERM | BQ2415X_MASK_RESET,
BQ2415X_SHIFT_VI_TERM);
}
static int bq2415x_get_termination_current(struct bq2415x_device *bq)
{
int ret;
if (bq->init_data.resistor_sense <= 0)
return -ENOSYS;
ret = bq2415x_i2c_read_mask(bq, BQ2415X_REG_CURRENT,
BQ2415X_MASK_VI_TERM, BQ2415X_SHIFT_VI_TERM);
if (ret < 0)
return ret;
return (3400 + 3400*ret) / bq->init_data.resistor_sense;
}
static int bq2415x_set_defaults(struct bq2415x_device *bq)
{
bq2415x_exec_command(bq, BQ2415X_BOOST_MODE_DISABLE);
bq2415x_exec_command(bq, BQ2415X_CHARGER_DISABLE);
bq2415x_exec_command(bq, BQ2415X_CHARGE_TERMINATION_DISABLE);
bq2415x_set_default_value(bq, current_limit);
bq2415x_set_default_value(bq, weak_battery_voltage);
bq2415x_set_default_value(bq, battery_regulation_voltage);
if (bq->init_data.resistor_sense > 0) {
bq2415x_set_default_value(bq, charge_current);
bq2415x_set_default_value(bq, termination_current);
bq2415x_exec_command(bq, BQ2415X_CHARGE_TERMINATION_ENABLE);
}
bq2415x_exec_command(bq, BQ2415X_CHARGER_ENABLE);
return 0;
}
static int bq2415x_set_mode(struct bq2415x_device *bq, enum bq2415x_mode mode)
{
int ret = 0;
int charger = 0;
int boost = 0;
if (mode == BQ2415X_MODE_BOOST)
boost = 1;
else if (mode != BQ2415X_MODE_OFF)
charger = 1;
if (!charger)
ret = bq2415x_exec_command(bq, BQ2415X_CHARGER_DISABLE);
if (!boost)
ret = bq2415x_exec_command(bq, BQ2415X_BOOST_MODE_DISABLE);
if (ret < 0)
return ret;
switch (mode) {
case BQ2415X_MODE_OFF:
dev_dbg(bq->dev, "changing mode to: Offline\n");
ret = bq2415x_set_current_limit(bq, 100);
break;
case BQ2415X_MODE_NONE:
dev_dbg(bq->dev, "changing mode to: N/A\n");
ret = bq2415x_set_current_limit(bq, 100);
break;
case BQ2415X_MODE_HOST_CHARGER:
dev_dbg(bq->dev, "changing mode to: Host/HUB charger\n");
ret = bq2415x_set_current_limit(bq, 500);
break;
case BQ2415X_MODE_DEDICATED_CHARGER:
dev_dbg(bq->dev, "changing mode to: Dedicated charger\n");
ret = bq2415x_set_current_limit(bq, 1800);
break;
case BQ2415X_MODE_BOOST:
dev_dbg(bq->dev, "changing mode to: Boost\n");
ret = bq2415x_set_current_limit(bq, 100);
break;
}
if (ret < 0)
return ret;
if (charger)
ret = bq2415x_exec_command(bq, BQ2415X_CHARGER_ENABLE);
else if (boost)
ret = bq2415x_exec_command(bq, BQ2415X_BOOST_MODE_ENABLE);
if (ret < 0)
return ret;
bq2415x_set_default_value(bq, weak_battery_voltage);
bq2415x_set_default_value(bq, battery_regulation_voltage);
bq->mode = mode;
sysfs_notify(&bq->charger.dev->kobj, NULL, "mode");
return 0;
}
static void bq2415x_hook_function(enum bq2415x_mode mode, void *data)
{
struct bq2415x_device *bq = data;
if (!bq)
return;
dev_dbg(bq->dev, "hook function was called\n");
bq->reported_mode = mode;
if (bq->automode < 1)
return;
sysfs_notify(&bq->charger.dev->kobj, NULL, "reported_mode");
bq2415x_set_mode(bq, bq->reported_mode);
}
static void bq2415x_set_autotimer(struct bq2415x_device *bq, int state)
{
mutex_lock(&bq2415x_timer_mutex);
if (bq->autotimer == state) {
mutex_unlock(&bq2415x_timer_mutex);
return;
}
bq->autotimer = state;
if (state) {
schedule_delayed_work(&bq->work, BQ2415X_TIMER_TIMEOUT * HZ);
bq2415x_exec_command(bq, BQ2415X_TIMER_RESET);
bq->timer_error = NULL;
} else {
cancel_delayed_work_sync(&bq->work);
}
mutex_unlock(&bq2415x_timer_mutex);
}
static void bq2415x_timer_error(struct bq2415x_device *bq, const char *msg)
{
bq->timer_error = msg;
sysfs_notify(&bq->charger.dev->kobj, NULL, "timer");
dev_err(bq->dev, "%s\n", msg);
if (bq->automode > 0)
bq->automode = 0;
bq2415x_set_mode(bq, BQ2415X_MODE_OFF);
bq2415x_set_autotimer(bq, 0);
}
static void bq2415x_timer_work(struct work_struct *work)
{
struct bq2415x_device *bq = container_of(work, struct bq2415x_device,
work.work);
int ret;
int error;
int boost;
if (!bq->autotimer)
return;
ret = bq2415x_exec_command(bq, BQ2415X_TIMER_RESET);
if (ret < 0) {
bq2415x_timer_error(bq, "Resetting timer failed");
return;
}
boost = bq2415x_exec_command(bq, BQ2415X_BOOST_MODE_STATUS);
if (boost < 0) {
bq2415x_timer_error(bq, "Unknown error");
return;
}
error = bq2415x_exec_command(bq, BQ2415X_FAULT_STATUS);
if (error < 0) {
bq2415x_timer_error(bq, "Unknown error");
return;
}
if (boost) {
switch (error) {
case 0:
break;
case 6:
dev_err(bq->dev, "Timer expired\n");
break;
case 3:
dev_err(bq->dev, "Battery voltage to low\n");
break;
case 1:
bq2415x_timer_error(bq,
"Overvoltage protection (chip fried)");
return;
case 2:
bq2415x_timer_error(bq, "Overload");
return;
case 4:
bq2415x_timer_error(bq,
"Battery overvoltage protection");
return;
case 5:
bq2415x_timer_error(bq,
"Thermal shutdown (too hot)");
return;
case 7:
bq2415x_timer_error(bq, "Unknown error");
return;
}
} else {
switch (error) {
case 0:
break;
case 2:
dev_err(bq->dev, "Sleep mode\n");
break;
case 3:
dev_err(bq->dev, "Poor input source\n");
break;
case 6:
dev_err(bq->dev, "Timer expired\n");
break;
case 7:
dev_err(bq->dev, "No battery\n");
break;
case 1:
bq2415x_timer_error(bq,
"Overvoltage protection (chip fried)");
return;
case 4:
bq2415x_timer_error(bq,
"Battery overvoltage protection");
return;
case 5:
bq2415x_timer_error(bq,
"Thermal shutdown (too hot)");
return;
}
}
schedule_delayed_work(&bq->work, BQ2415X_TIMER_TIMEOUT * HZ);
}
static int bq2415x_power_supply_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
int ret;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = bq2415x_exec_command(bq, BQ2415X_CHARGE_STATUS);
if (ret < 0)
return ret;
else if (ret == 0)
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (ret == 1)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (ret == 2)
val->intval = POWER_SUPPLY_STATUS_FULL;
else
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = bq->model;
break;
default:
return -EINVAL;
}
return 0;
}
static int bq2415x_power_supply_init(struct bq2415x_device *bq)
{
int ret;
int chip;
char revstr[8];
bq->charger.name = bq->name;
bq->charger.type = POWER_SUPPLY_TYPE_USB;
bq->charger.properties = bq2415x_power_supply_props;
bq->charger.num_properties = ARRAY_SIZE(bq2415x_power_supply_props);
bq->charger.get_property = bq2415x_power_supply_get_property;
ret = bq2415x_detect_chip(bq);
if (ret < 0)
chip = BQUNKNOWN;
else
chip = ret;
ret = bq2415x_detect_revision(bq);
if (ret < 0)
strcpy(revstr, "unknown");
else
sprintf(revstr, "1.%d", ret);
bq->model = kasprintf(GFP_KERNEL,
"chip %s, revision %s, vender code %.3d",
bq2415x_chip_name[chip], revstr,
bq2415x_get_vender_code(bq));
if (!bq->model) {
dev_err(bq->dev, "failed to allocate model name\n");
return -ENOMEM;
}
ret = power_supply_register(bq->dev, &bq->charger);
if (ret) {
kfree(bq->model);
return ret;
}
return 0;
}
static void bq2415x_power_supply_exit(struct bq2415x_device *bq)
{
bq->autotimer = 0;
if (bq->automode > 0)
bq->automode = 0;
cancel_delayed_work_sync(&bq->work);
power_supply_unregister(&bq->charger);
kfree(bq->model);
}
static ssize_t bq2415x_sysfs_show_status(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
enum bq2415x_command command;
int ret;
if (strcmp(attr->attr.name, "otg_status") == 0)
command = BQ2415X_OTG_STATUS;
else if (strcmp(attr->attr.name, "charge_status") == 0)
command = BQ2415X_CHARGE_STATUS;
else if (strcmp(attr->attr.name, "boost_status") == 0)
command = BQ2415X_BOOST_STATUS;
else if (strcmp(attr->attr.name, "fault_status") == 0)
command = BQ2415X_FAULT_STATUS;
else
return -EINVAL;
ret = bq2415x_exec_command(bq, command);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ret);
}
static ssize_t bq2415x_sysfs_set_timer(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
int ret = 0;
if (strncmp(buf, "auto", 4) == 0)
bq2415x_set_autotimer(bq, 1);
else if (strncmp(buf, "off", 3) == 0)
bq2415x_set_autotimer(bq, 0);
else
ret = bq2415x_exec_command(bq, BQ2415X_TIMER_RESET);
if (ret < 0)
return ret;
return count;
}
static ssize_t bq2415x_sysfs_show_timer(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
if (bq->timer_error)
return sprintf(buf, "%s\n", bq->timer_error);
if (bq->autotimer)
return sprintf(buf, "auto\n");
return sprintf(buf, "off\n");
}
static ssize_t bq2415x_sysfs_set_mode(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
enum bq2415x_mode mode;
int ret = 0;
if (strncmp(buf, "auto", 4) == 0) {
if (bq->automode < 0)
return -ENOSYS;
bq->automode = 1;
mode = bq->reported_mode;
} else if (strncmp(buf, "off", 3) == 0) {
if (bq->automode > 0)
bq->automode = 0;
mode = BQ2415X_MODE_OFF;
} else if (strncmp(buf, "none", 4) == 0) {
if (bq->automode > 0)
bq->automode = 0;
mode = BQ2415X_MODE_NONE;
} else if (strncmp(buf, "host", 4) == 0) {
if (bq->automode > 0)
bq->automode = 0;
mode = BQ2415X_MODE_HOST_CHARGER;
} else if (strncmp(buf, "dedicated", 9) == 0) {
if (bq->automode > 0)
bq->automode = 0;
mode = BQ2415X_MODE_DEDICATED_CHARGER;
} else if (strncmp(buf, "boost", 5) == 0) {
if (bq->automode > 0)
bq->automode = 0;
mode = BQ2415X_MODE_BOOST;
} else if (strncmp(buf, "reset", 5) == 0) {
bq2415x_reset_chip(bq);
bq2415x_set_defaults(bq);
if (bq->automode <= 0)
return count;
bq->automode = 1;
mode = bq->reported_mode;
} else {
return -EINVAL;
}
ret = bq2415x_set_mode(bq, mode);
if (ret < 0)
return ret;
return count;
}
static ssize_t bq2415x_sysfs_show_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
ssize_t ret = 0;
if (bq->automode > 0)
ret += sprintf(buf+ret, "auto (");
switch (bq->mode) {
case BQ2415X_MODE_OFF:
ret += sprintf(buf+ret, "off");
break;
case BQ2415X_MODE_NONE:
ret += sprintf(buf+ret, "none");
break;
case BQ2415X_MODE_HOST_CHARGER:
ret += sprintf(buf+ret, "host");
break;
case BQ2415X_MODE_DEDICATED_CHARGER:
ret += sprintf(buf+ret, "dedicated");
break;
case BQ2415X_MODE_BOOST:
ret += sprintf(buf+ret, "boost");
break;
}
if (bq->automode > 0)
ret += sprintf(buf+ret, ")");
ret += sprintf(buf+ret, "\n");
return ret;
}
static ssize_t bq2415x_sysfs_show_reported_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
if (bq->automode < 0)
return -EINVAL;
switch (bq->reported_mode) {
case BQ2415X_MODE_OFF:
return sprintf(buf, "off\n");
case BQ2415X_MODE_NONE:
return sprintf(buf, "none\n");
case BQ2415X_MODE_HOST_CHARGER:
return sprintf(buf, "host\n");
case BQ2415X_MODE_DEDICATED_CHARGER:
return sprintf(buf, "dedicated\n");
case BQ2415X_MODE_BOOST:
return sprintf(buf, "boost\n");
}
return -EINVAL;
}
static ssize_t bq2415x_sysfs_set_registers(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
ssize_t ret = 0;
unsigned int reg;
unsigned int val;
if (sscanf(buf, "%x %x", &reg, &val) != 2)
return -EINVAL;
if (reg > 4 || val > 255)
return -EINVAL;
ret = bq2415x_i2c_write(bq, reg, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t bq2415x_sysfs_print_reg(struct bq2415x_device *bq,
u8 reg,
char *buf)
{
int ret = bq2415x_i2c_read(bq, reg);
if (ret < 0)
return sprintf(buf, "%#.2x=error %d\n", reg, ret);
return sprintf(buf, "%#.2x=%#.2x\n", reg, ret);
}
static ssize_t bq2415x_sysfs_show_registers(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
ssize_t ret = 0;
ret += bq2415x_sysfs_print_reg(bq, BQ2415X_REG_STATUS, buf+ret);
ret += bq2415x_sysfs_print_reg(bq, BQ2415X_REG_CONTROL, buf+ret);
ret += bq2415x_sysfs_print_reg(bq, BQ2415X_REG_VOLTAGE, buf+ret);
ret += bq2415x_sysfs_print_reg(bq, BQ2415X_REG_VENDER, buf+ret);
ret += bq2415x_sysfs_print_reg(bq, BQ2415X_REG_CURRENT, buf+ret);
return ret;
}
static ssize_t bq2415x_sysfs_set_limit(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
long val;
int ret;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
if (strcmp(attr->attr.name, "current_limit") == 0)
ret = bq2415x_set_current_limit(bq, val);
else if (strcmp(attr->attr.name, "weak_battery_voltage") == 0)
ret = bq2415x_set_weak_battery_voltage(bq, val);
else if (strcmp(attr->attr.name, "battery_regulation_voltage") == 0)
ret = bq2415x_set_battery_regulation_voltage(bq, val);
else if (strcmp(attr->attr.name, "charge_current") == 0)
ret = bq2415x_set_charge_current(bq, val);
else if (strcmp(attr->attr.name, "termination_current") == 0)
ret = bq2415x_set_termination_current(bq, val);
else
return -EINVAL;
if (ret < 0)
return ret;
return count;
}
static ssize_t bq2415x_sysfs_show_limit(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
int ret;
if (strcmp(attr->attr.name, "current_limit") == 0)
ret = bq2415x_get_current_limit(bq);
else if (strcmp(attr->attr.name, "weak_battery_voltage") == 0)
ret = bq2415x_get_weak_battery_voltage(bq);
else if (strcmp(attr->attr.name, "battery_regulation_voltage") == 0)
ret = bq2415x_get_battery_regulation_voltage(bq);
else if (strcmp(attr->attr.name, "charge_current") == 0)
ret = bq2415x_get_charge_current(bq);
else if (strcmp(attr->attr.name, "termination_current") == 0)
ret = bq2415x_get_termination_current(bq);
else
return -EINVAL;
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ret);
}
static ssize_t bq2415x_sysfs_set_enable(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
enum bq2415x_command command;
long val;
int ret;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
if (strcmp(attr->attr.name, "charge_termination_enable") == 0)
command = val ? BQ2415X_CHARGE_TERMINATION_ENABLE :
BQ2415X_CHARGE_TERMINATION_DISABLE;
else if (strcmp(attr->attr.name, "high_impedance_enable") == 0)
command = val ? BQ2415X_HIGH_IMPEDANCE_ENABLE :
BQ2415X_HIGH_IMPEDANCE_DISABLE;
else if (strcmp(attr->attr.name, "otg_pin_enable") == 0)
command = val ? BQ2415X_OTG_PIN_ENABLE :
BQ2415X_OTG_PIN_DISABLE;
else if (strcmp(attr->attr.name, "stat_pin_enable") == 0)
command = val ? BQ2415X_STAT_PIN_ENABLE :
BQ2415X_STAT_PIN_DISABLE;
else
return -EINVAL;
ret = bq2415x_exec_command(bq, command);
if (ret < 0)
return ret;
return count;
}
static ssize_t bq2415x_sysfs_show_enable(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq2415x_device *bq = container_of(psy, struct bq2415x_device,
charger);
enum bq2415x_command command;
int ret;
if (strcmp(attr->attr.name, "charge_termination_enable") == 0)
command = BQ2415X_CHARGE_TERMINATION_STATUS;
else if (strcmp(attr->attr.name, "high_impedance_enable") == 0)
command = BQ2415X_HIGH_IMPEDANCE_STATUS;
else if (strcmp(attr->attr.name, "otg_pin_enable") == 0)
command = BQ2415X_OTG_PIN_STATUS;
else if (strcmp(attr->attr.name, "stat_pin_enable") == 0)
command = BQ2415X_STAT_PIN_STATUS;
else
return -EINVAL;
ret = bq2415x_exec_command(bq, command);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", ret);
}
static int bq2415x_sysfs_init(struct bq2415x_device *bq)
{
return sysfs_create_group(&bq->charger.dev->kobj,
&bq2415x_sysfs_attr_group);
}
static void bq2415x_sysfs_exit(struct bq2415x_device *bq)
{
sysfs_remove_group(&bq->charger.dev->kobj, &bq2415x_sysfs_attr_group);
}
static int bq2415x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
int num;
char *name;
struct bq2415x_device *bq;
if (!client->dev.platform_data) {
dev_err(&client->dev, "platform data not set\n");
return -ENODEV;
}
mutex_lock(&bq2415x_id_mutex);
num = idr_alloc(&bq2415x_id, client, 0, 0, GFP_KERNEL);
mutex_unlock(&bq2415x_id_mutex);
if (num < 0)
return num;
name = kasprintf(GFP_KERNEL, "%s-%d", id->name, num);
if (!name) {
dev_err(&client->dev, "failed to allocate device name\n");
ret = -ENOMEM;
goto error_1;
}
bq = devm_kzalloc(&client->dev, sizeof(*bq), GFP_KERNEL);
if (!bq) {
dev_err(&client->dev, "failed to allocate device data\n");
ret = -ENOMEM;
goto error_2;
}
i2c_set_clientdata(client, bq);
bq->id = num;
bq->dev = &client->dev;
bq->chip = id->driver_data;
bq->name = name;
bq->mode = BQ2415X_MODE_OFF;
bq->reported_mode = BQ2415X_MODE_OFF;
bq->autotimer = 0;
bq->automode = 0;
memcpy(&bq->init_data, client->dev.platform_data,
sizeof(bq->init_data));
bq2415x_reset_chip(bq);
ret = bq2415x_power_supply_init(bq);
if (ret) {
dev_err(bq->dev, "failed to register power supply: %d\n", ret);
goto error_2;
}
ret = bq2415x_sysfs_init(bq);
if (ret) {
dev_err(bq->dev, "failed to create sysfs entries: %d\n", ret);
goto error_3;
}
ret = bq2415x_set_defaults(bq);
if (ret) {
dev_err(bq->dev, "failed to set default values: %d\n", ret);
goto error_4;
}
if (bq->init_data.set_mode_hook) {
if (bq->init_data.set_mode_hook(
bq2415x_hook_function, bq)) {
bq->automode = 1;
bq2415x_set_mode(bq, bq->reported_mode);
dev_info(bq->dev, "automode enabled\n");
} else {
bq->automode = -1;
dev_info(bq->dev, "automode failed\n");
}
} else {
bq->automode = -1;
dev_info(bq->dev, "automode not supported\n");
}
INIT_DELAYED_WORK(&bq->work, bq2415x_timer_work);
bq2415x_set_autotimer(bq, 1);
dev_info(bq->dev, "driver registered\n");
return 0;
error_4:
bq2415x_sysfs_exit(bq);
error_3:
bq2415x_power_supply_exit(bq);
error_2:
kfree(name);
error_1:
mutex_lock(&bq2415x_id_mutex);
idr_remove(&bq2415x_id, num);
mutex_unlock(&bq2415x_id_mutex);
return ret;
}
static int bq2415x_remove(struct i2c_client *client)
{
struct bq2415x_device *bq = i2c_get_clientdata(client);
if (bq->init_data.set_mode_hook)
bq->init_data.set_mode_hook(NULL, NULL);
bq2415x_sysfs_exit(bq);
bq2415x_power_supply_exit(bq);
bq2415x_reset_chip(bq);
mutex_lock(&bq2415x_id_mutex);
idr_remove(&bq2415x_id, bq->id);
mutex_unlock(&bq2415x_id_mutex);
dev_info(bq->dev, "driver unregistered\n");
kfree(bq->name);
return 0;
}
