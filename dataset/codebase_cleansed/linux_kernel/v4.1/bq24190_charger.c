static u8 bq24190_find_idx(const int tbl[], int tbl_size, int v)
{
int i;
for (i = 1; i < tbl_size; i++)
if (v < tbl[i])
break;
return i - 1;
}
static int bq24190_read(struct bq24190_dev_info *bdi, u8 reg, u8 *data)
{
int ret;
ret = i2c_smbus_read_byte_data(bdi->client, reg);
if (ret < 0)
return ret;
*data = ret;
return 0;
}
static int bq24190_write(struct bq24190_dev_info *bdi, u8 reg, u8 data)
{
return i2c_smbus_write_byte_data(bdi->client, reg, data);
}
static int bq24190_read_mask(struct bq24190_dev_info *bdi, u8 reg,
u8 mask, u8 shift, u8 *data)
{
u8 v;
int ret;
ret = bq24190_read(bdi, reg, &v);
if (ret < 0)
return ret;
v &= mask;
v >>= shift;
*data = v;
return 0;
}
static int bq24190_write_mask(struct bq24190_dev_info *bdi, u8 reg,
u8 mask, u8 shift, u8 data)
{
u8 v;
int ret;
ret = bq24190_read(bdi, reg, &v);
if (ret < 0)
return ret;
v &= ~mask;
v |= ((data << shift) & mask);
return bq24190_write(bdi, reg, v);
}
static int bq24190_get_field_val(struct bq24190_dev_info *bdi,
u8 reg, u8 mask, u8 shift,
const int tbl[], int tbl_size,
int *val)
{
u8 v;
int ret;
ret = bq24190_read_mask(bdi, reg, mask, shift, &v);
if (ret < 0)
return ret;
v = (v >= tbl_size) ? (tbl_size - 1) : v;
*val = tbl[v];
return 0;
}
static int bq24190_set_field_val(struct bq24190_dev_info *bdi,
u8 reg, u8 mask, u8 shift,
const int tbl[], int tbl_size,
int val)
{
u8 idx;
idx = bq24190_find_idx(tbl, tbl_size, val);
return bq24190_write_mask(bdi, reg, mask, shift, idx);
}
static void bq24190_sysfs_init_attrs(void)
{
int i, limit = ARRAY_SIZE(bq24190_sysfs_field_tbl);
for (i = 0; i < limit; i++)
bq24190_sysfs_attrs[i] = &bq24190_sysfs_field_tbl[i].attr.attr;
bq24190_sysfs_attrs[limit] = NULL;
}
static struct bq24190_sysfs_field_info *bq24190_sysfs_field_lookup(
const char *name)
{
int i, limit = ARRAY_SIZE(bq24190_sysfs_field_tbl);
for (i = 0; i < limit; i++)
if (!strcmp(name, bq24190_sysfs_field_tbl[i].attr.attr.name))
break;
if (i >= limit)
return NULL;
return &bq24190_sysfs_field_tbl[i];
}
static ssize_t bq24190_sysfs_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq24190_dev_info *bdi = power_supply_get_drvdata(psy);
struct bq24190_sysfs_field_info *info;
int ret;
u8 v;
info = bq24190_sysfs_field_lookup(attr->attr.name);
if (!info)
return -EINVAL;
ret = bq24190_read_mask(bdi, info->reg, info->mask, info->shift, &v);
if (ret)
return ret;
return scnprintf(buf, PAGE_SIZE, "%hhx\n", v);
}
static ssize_t bq24190_sysfs_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct power_supply *psy = dev_get_drvdata(dev);
struct bq24190_dev_info *bdi = power_supply_get_drvdata(psy);
struct bq24190_sysfs_field_info *info;
int ret;
u8 v;
info = bq24190_sysfs_field_lookup(attr->attr.name);
if (!info)
return -EINVAL;
ret = kstrtou8(buf, 0, &v);
if (ret < 0)
return ret;
ret = bq24190_write_mask(bdi, info->reg, info->mask, info->shift, v);
if (ret)
return ret;
return count;
}
static int bq24190_sysfs_create_group(struct bq24190_dev_info *bdi)
{
bq24190_sysfs_init_attrs();
return sysfs_create_group(&bdi->charger->dev.kobj,
&bq24190_sysfs_attr_group);
}
static void bq24190_sysfs_remove_group(struct bq24190_dev_info *bdi)
{
sysfs_remove_group(&bdi->charger->dev.kobj, &bq24190_sysfs_attr_group);
}
static int bq24190_sysfs_create_group(struct bq24190_dev_info *bdi)
{
return 0;
}
static inline void bq24190_sysfs_remove_group(struct bq24190_dev_info *bdi) {}
static int bq24190_set_mode_host(struct bq24190_dev_info *bdi)
{
int ret;
u8 v;
ret = bq24190_read(bdi, BQ24190_REG_CTTC, &v);
if (ret < 0)
return ret;
bdi->watchdog = ((v & BQ24190_REG_CTTC_WATCHDOG_MASK) >>
BQ24190_REG_CTTC_WATCHDOG_SHIFT);
v &= ~BQ24190_REG_CTTC_WATCHDOG_MASK;
return bq24190_write(bdi, BQ24190_REG_CTTC, v);
}
static int bq24190_register_reset(struct bq24190_dev_info *bdi)
{
int ret, limit = 100;
u8 v;
ret = bq24190_write_mask(bdi, BQ24190_REG_POC,
BQ24190_REG_POC_RESET_MASK,
BQ24190_REG_POC_RESET_SHIFT,
0x1);
if (ret < 0)
return ret;
do {
ret = bq24190_read_mask(bdi, BQ24190_REG_POC,
BQ24190_REG_POC_RESET_MASK,
BQ24190_REG_POC_RESET_SHIFT,
&v);
if (ret < 0)
return ret;
if (!v)
break;
udelay(10);
} while (--limit);
if (!limit)
return -EIO;
return 0;
}
static int bq24190_charger_get_charge_type(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
u8 v;
int type, ret;
ret = bq24190_read_mask(bdi, BQ24190_REG_POC,
BQ24190_REG_POC_CHG_CONFIG_MASK,
BQ24190_REG_POC_CHG_CONFIG_SHIFT,
&v);
if (ret < 0)
return ret;
if (!v) {
type = POWER_SUPPLY_CHARGE_TYPE_NONE;
} else {
ret = bq24190_read_mask(bdi, BQ24190_REG_CCC,
BQ24190_REG_CCC_FORCE_20PCT_MASK,
BQ24190_REG_CCC_FORCE_20PCT_SHIFT,
&v);
if (ret < 0)
return ret;
type = (v) ? POWER_SUPPLY_CHARGE_TYPE_TRICKLE :
POWER_SUPPLY_CHARGE_TYPE_FAST;
}
val->intval = type;
return 0;
}
static int bq24190_charger_set_charge_type(struct bq24190_dev_info *bdi,
const union power_supply_propval *val)
{
u8 chg_config, force_20pct, en_term;
int ret;
switch (val->intval) {
case POWER_SUPPLY_CHARGE_TYPE_NONE:
chg_config = 0x0;
break;
case POWER_SUPPLY_CHARGE_TYPE_TRICKLE:
chg_config = 0x1;
force_20pct = 0x1;
en_term = 0x0;
break;
case POWER_SUPPLY_CHARGE_TYPE_FAST:
chg_config = 0x1;
force_20pct = 0x0;
en_term = 0x1;
break;
default:
return -EINVAL;
}
if (chg_config) {
ret = bq24190_write_mask(bdi, BQ24190_REG_CCC,
BQ24190_REG_CCC_FORCE_20PCT_MASK,
BQ24190_REG_CCC_FORCE_20PCT_SHIFT,
force_20pct);
if (ret < 0)
return ret;
ret = bq24190_write_mask(bdi, BQ24190_REG_CTTC,
BQ24190_REG_CTTC_EN_TERM_MASK,
BQ24190_REG_CTTC_EN_TERM_SHIFT,
en_term);
if (ret < 0)
return ret;
}
return bq24190_write_mask(bdi, BQ24190_REG_POC,
BQ24190_REG_POC_CHG_CONFIG_MASK,
BQ24190_REG_POC_CHG_CONFIG_SHIFT, chg_config);
}
static int bq24190_charger_get_health(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
u8 v;
int health, ret;
mutex_lock(&bdi->f_reg_lock);
if (bdi->charger_health_valid) {
v = bdi->f_reg;
bdi->charger_health_valid = false;
mutex_unlock(&bdi->f_reg_lock);
} else {
mutex_unlock(&bdi->f_reg_lock);
ret = bq24190_read(bdi, BQ24190_REG_F, &v);
if (ret < 0)
return ret;
}
if (v & BQ24190_REG_F_BOOST_FAULT_MASK) {
health = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
} else {
v &= BQ24190_REG_F_CHRG_FAULT_MASK;
v >>= BQ24190_REG_F_CHRG_FAULT_SHIFT;
switch (v) {
case 0x0:
health = POWER_SUPPLY_HEALTH_GOOD;
break;
case 0x1:
health = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
case 0x2:
health = POWER_SUPPLY_HEALTH_OVERHEAT;
break;
case 0x3:
health = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
break;
default:
health = POWER_SUPPLY_HEALTH_UNKNOWN;
}
}
val->intval = health;
return 0;
}
static int bq24190_charger_get_online(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
u8 v;
int ret;
ret = bq24190_read_mask(bdi, BQ24190_REG_SS,
BQ24190_REG_SS_PG_STAT_MASK,
BQ24190_REG_SS_PG_STAT_SHIFT, &v);
if (ret < 0)
return ret;
val->intval = v;
return 0;
}
static int bq24190_charger_get_current(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
u8 v;
int curr, ret;
ret = bq24190_get_field_val(bdi, BQ24190_REG_CCC,
BQ24190_REG_CCC_ICHG_MASK, BQ24190_REG_CCC_ICHG_SHIFT,
bq24190_ccc_ichg_values,
ARRAY_SIZE(bq24190_ccc_ichg_values), &curr);
if (ret < 0)
return ret;
ret = bq24190_read_mask(bdi, BQ24190_REG_CCC,
BQ24190_REG_CCC_FORCE_20PCT_MASK,
BQ24190_REG_CCC_FORCE_20PCT_SHIFT, &v);
if (ret < 0)
return ret;
if (v)
curr /= 5;
val->intval = curr;
return 0;
}
static int bq24190_charger_get_current_max(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
int idx = ARRAY_SIZE(bq24190_ccc_ichg_values) - 1;
val->intval = bq24190_ccc_ichg_values[idx];
return 0;
}
static int bq24190_charger_set_current(struct bq24190_dev_info *bdi,
const union power_supply_propval *val)
{
u8 v;
int ret, curr = val->intval;
ret = bq24190_read_mask(bdi, BQ24190_REG_CCC,
BQ24190_REG_CCC_FORCE_20PCT_MASK,
BQ24190_REG_CCC_FORCE_20PCT_SHIFT, &v);
if (ret < 0)
return ret;
if (v)
curr *= 5;
return bq24190_set_field_val(bdi, BQ24190_REG_CCC,
BQ24190_REG_CCC_ICHG_MASK, BQ24190_REG_CCC_ICHG_SHIFT,
bq24190_ccc_ichg_values,
ARRAY_SIZE(bq24190_ccc_ichg_values), curr);
}
static int bq24190_charger_get_voltage(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
int voltage, ret;
ret = bq24190_get_field_val(bdi, BQ24190_REG_CVC,
BQ24190_REG_CVC_VREG_MASK, BQ24190_REG_CVC_VREG_SHIFT,
bq24190_cvc_vreg_values,
ARRAY_SIZE(bq24190_cvc_vreg_values), &voltage);
if (ret < 0)
return ret;
val->intval = voltage;
return 0;
}
static int bq24190_charger_get_voltage_max(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
int idx = ARRAY_SIZE(bq24190_cvc_vreg_values) - 1;
val->intval = bq24190_cvc_vreg_values[idx];
return 0;
}
static int bq24190_charger_set_voltage(struct bq24190_dev_info *bdi,
const union power_supply_propval *val)
{
return bq24190_set_field_val(bdi, BQ24190_REG_CVC,
BQ24190_REG_CVC_VREG_MASK, BQ24190_REG_CVC_VREG_SHIFT,
bq24190_cvc_vreg_values,
ARRAY_SIZE(bq24190_cvc_vreg_values), val->intval);
}
static int bq24190_charger_get_property(struct power_supply *psy,
enum power_supply_property psp, union power_supply_propval *val)
{
struct bq24190_dev_info *bdi = power_supply_get_drvdata(psy);
int ret;
dev_dbg(bdi->dev, "prop: %d\n", psp);
pm_runtime_get_sync(bdi->dev);
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_TYPE:
ret = bq24190_charger_get_charge_type(bdi, val);
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = bq24190_charger_get_health(bdi, val);
break;
case POWER_SUPPLY_PROP_ONLINE:
ret = bq24190_charger_get_online(bdi, val);
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
ret = bq24190_charger_get_current(bdi, val);
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT_MAX:
ret = bq24190_charger_get_current_max(bdi, val);
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE:
ret = bq24190_charger_get_voltage(bdi, val);
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE_MAX:
ret = bq24190_charger_get_voltage_max(bdi, val);
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_SYSTEM;
ret = 0;
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = bdi->model_name;
ret = 0;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = BQ24190_MANUFACTURER;
ret = 0;
break;
default:
ret = -ENODATA;
}
pm_runtime_put_sync(bdi->dev);
return ret;
}
static int bq24190_charger_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct bq24190_dev_info *bdi = power_supply_get_drvdata(psy);
int ret;
dev_dbg(bdi->dev, "prop: %d\n", psp);
pm_runtime_get_sync(bdi->dev);
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_TYPE:
ret = bq24190_charger_set_charge_type(bdi, val);
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
ret = bq24190_charger_set_current(bdi, val);
break;
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE:
ret = bq24190_charger_set_voltage(bdi, val);
break;
default:
ret = -EINVAL;
}
pm_runtime_put_sync(bdi->dev);
return ret;
}
static int bq24190_charger_property_is_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
int ret;
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_TYPE:
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_CURRENT:
case POWER_SUPPLY_PROP_CONSTANT_CHARGE_VOLTAGE:
ret = 1;
break;
default:
ret = 0;
}
return ret;
}
static int bq24190_battery_get_status(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
u8 ss_reg, chrg_fault;
int status, ret;
mutex_lock(&bdi->f_reg_lock);
if (bdi->battery_status_valid) {
chrg_fault = bdi->f_reg;
bdi->battery_status_valid = false;
mutex_unlock(&bdi->f_reg_lock);
} else {
mutex_unlock(&bdi->f_reg_lock);
ret = bq24190_read(bdi, BQ24190_REG_F, &chrg_fault);
if (ret < 0)
return ret;
}
chrg_fault &= BQ24190_REG_F_CHRG_FAULT_MASK;
chrg_fault >>= BQ24190_REG_F_CHRG_FAULT_SHIFT;
ret = bq24190_read(bdi, BQ24190_REG_SS, &ss_reg);
if (ret < 0)
return ret;
if (!(ss_reg & BQ24190_REG_SS_PG_STAT_MASK) || chrg_fault) {
status = POWER_SUPPLY_STATUS_DISCHARGING;
} else {
ss_reg &= BQ24190_REG_SS_CHRG_STAT_MASK;
ss_reg >>= BQ24190_REG_SS_CHRG_STAT_SHIFT;
switch (ss_reg) {
case 0x0:
status = POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
case 0x1:
case 0x2:
status = POWER_SUPPLY_STATUS_CHARGING;
break;
case 0x3:
status = POWER_SUPPLY_STATUS_FULL;
break;
default:
ret = -EIO;
}
}
if (!ret)
val->intval = status;
return ret;
}
static int bq24190_battery_get_health(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
u8 v;
int health, ret;
mutex_lock(&bdi->f_reg_lock);
if (bdi->battery_health_valid) {
v = bdi->f_reg;
bdi->battery_health_valid = false;
mutex_unlock(&bdi->f_reg_lock);
} else {
mutex_unlock(&bdi->f_reg_lock);
ret = bq24190_read(bdi, BQ24190_REG_F, &v);
if (ret < 0)
return ret;
}
if (v & BQ24190_REG_F_BAT_FAULT_MASK) {
health = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
} else {
v &= BQ24190_REG_F_NTC_FAULT_MASK;
v >>= BQ24190_REG_F_NTC_FAULT_SHIFT;
switch (v) {
case 0x0:
health = POWER_SUPPLY_HEALTH_GOOD;
break;
case 0x1:
case 0x3:
case 0x5:
health = POWER_SUPPLY_HEALTH_COLD;
break;
case 0x2:
case 0x4:
case 0x6:
health = POWER_SUPPLY_HEALTH_OVERHEAT;
break;
default:
health = POWER_SUPPLY_HEALTH_UNKNOWN;
}
}
val->intval = health;
return 0;
}
static int bq24190_battery_get_online(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
u8 batfet_disable;
int ret;
ret = bq24190_read_mask(bdi, BQ24190_REG_MOC,
BQ24190_REG_MOC_BATFET_DISABLE_MASK,
BQ24190_REG_MOC_BATFET_DISABLE_SHIFT, &batfet_disable);
if (ret < 0)
return ret;
val->intval = !batfet_disable;
return 0;
}
static int bq24190_battery_set_online(struct bq24190_dev_info *bdi,
const union power_supply_propval *val)
{
return bq24190_write_mask(bdi, BQ24190_REG_MOC,
BQ24190_REG_MOC_BATFET_DISABLE_MASK,
BQ24190_REG_MOC_BATFET_DISABLE_SHIFT, !val->intval);
}
static int bq24190_battery_get_temp_alert_max(struct bq24190_dev_info *bdi,
union power_supply_propval *val)
{
int temp, ret;
ret = bq24190_get_field_val(bdi, BQ24190_REG_ICTRC,
BQ24190_REG_ICTRC_TREG_MASK,
BQ24190_REG_ICTRC_TREG_SHIFT,
bq24190_ictrc_treg_values,
ARRAY_SIZE(bq24190_ictrc_treg_values), &temp);
if (ret < 0)
return ret;
val->intval = temp;
return 0;
}
static int bq24190_battery_set_temp_alert_max(struct bq24190_dev_info *bdi,
const union power_supply_propval *val)
{
return bq24190_set_field_val(bdi, BQ24190_REG_ICTRC,
BQ24190_REG_ICTRC_TREG_MASK,
BQ24190_REG_ICTRC_TREG_SHIFT,
bq24190_ictrc_treg_values,
ARRAY_SIZE(bq24190_ictrc_treg_values), val->intval);
}
static int bq24190_battery_get_property(struct power_supply *psy,
enum power_supply_property psp, union power_supply_propval *val)
{
struct bq24190_dev_info *bdi = power_supply_get_drvdata(psy);
int ret;
dev_dbg(bdi->dev, "prop: %d\n", psp);
pm_runtime_get_sync(bdi->dev);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
ret = bq24190_battery_get_status(bdi, val);
break;
case POWER_SUPPLY_PROP_HEALTH:
ret = bq24190_battery_get_health(bdi, val);
break;
case POWER_SUPPLY_PROP_ONLINE:
ret = bq24190_battery_get_online(bdi, val);
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
ret = 0;
break;
case POWER_SUPPLY_PROP_TEMP_ALERT_MAX:
ret = bq24190_battery_get_temp_alert_max(bdi, val);
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_SYSTEM;
ret = 0;
break;
default:
ret = -ENODATA;
}
pm_runtime_put_sync(bdi->dev);
return ret;
}
static int bq24190_battery_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct bq24190_dev_info *bdi = power_supply_get_drvdata(psy);
int ret;
dev_dbg(bdi->dev, "prop: %d\n", psp);
pm_runtime_put_sync(bdi->dev);
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
ret = bq24190_battery_set_online(bdi, val);
break;
case POWER_SUPPLY_PROP_TEMP_ALERT_MAX:
ret = bq24190_battery_set_temp_alert_max(bdi, val);
break;
default:
ret = -EINVAL;
}
pm_runtime_put_sync(bdi->dev);
return ret;
}
static int bq24190_battery_property_is_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
int ret;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
case POWER_SUPPLY_PROP_TEMP_ALERT_MAX:
ret = 1;
break;
default:
ret = 0;
}
return ret;
}
static irqreturn_t bq24190_irq_handler_thread(int irq, void *data)
{
struct bq24190_dev_info *bdi = data;
bool alert_userspace = false;
u8 ss_reg = 0, f_reg = 0;
int ret;
pm_runtime_get_sync(bdi->dev);
ret = bq24190_read(bdi, BQ24190_REG_SS, &ss_reg);
if (ret < 0) {
dev_err(bdi->dev, "Can't read SS reg: %d\n", ret);
goto out;
}
if (ss_reg != bdi->ss_reg) {
if ((bdi->ss_reg & BQ24190_REG_SS_PG_STAT_MASK) &&
!(ss_reg & BQ24190_REG_SS_PG_STAT_MASK)) {
ret = bq24190_write_mask(bdi, BQ24190_REG_ISC,
BQ24190_REG_ISC_EN_HIZ_MASK,
BQ24190_REG_ISC_EN_HIZ_SHIFT,
0);
if (ret < 0)
dev_err(bdi->dev, "Can't access ISC reg: %d\n",
ret);
}
bdi->ss_reg = ss_reg;
alert_userspace = true;
}
mutex_lock(&bdi->f_reg_lock);
ret = bq24190_read(bdi, BQ24190_REG_F, &f_reg);
if (ret < 0) {
mutex_unlock(&bdi->f_reg_lock);
dev_err(bdi->dev, "Can't read F reg: %d\n", ret);
goto out;
}
if (f_reg != bdi->f_reg) {
bdi->f_reg = f_reg;
bdi->charger_health_valid = true;
bdi->battery_health_valid = true;
bdi->battery_status_valid = true;
alert_userspace = true;
}
mutex_unlock(&bdi->f_reg_lock);
if (alert_userspace && !bdi->first_time) {
power_supply_changed(bdi->charger);
power_supply_changed(bdi->battery);
bdi->first_time = false;
}
out:
pm_runtime_put_sync(bdi->dev);
dev_dbg(bdi->dev, "ss_reg: 0x%02x, f_reg: 0x%02x\n", ss_reg, f_reg);
return IRQ_HANDLED;
}
static int bq24190_hw_init(struct bq24190_dev_info *bdi)
{
u8 v;
int ret;
pm_runtime_get_sync(bdi->dev);
ret = bq24190_read_mask(bdi, BQ24190_REG_VPRS,
BQ24190_REG_VPRS_PN_MASK,
BQ24190_REG_VPRS_PN_SHIFT,
&v);
if (ret < 0)
goto out;
if (v != bdi->model) {
ret = -ENODEV;
goto out;
}
ret = bq24190_register_reset(bdi);
if (ret < 0)
goto out;
ret = bq24190_set_mode_host(bdi);
out:
pm_runtime_put_sync(bdi->dev);
return ret;
}
static int bq24190_setup_dt(struct bq24190_dev_info *bdi)
{
bdi->irq = irq_of_parse_and_map(bdi->dev->of_node, 0);
if (bdi->irq <= 0)
return -1;
return 0;
}
static int bq24190_setup_dt(struct bq24190_dev_info *bdi)
{
return -1;
}
static int bq24190_setup_pdata(struct bq24190_dev_info *bdi,
struct bq24190_platform_data *pdata)
{
int ret;
if (!gpio_is_valid(pdata->gpio_int))
return -1;
ret = gpio_request(pdata->gpio_int, dev_name(bdi->dev));
if (ret < 0)
return -1;
ret = gpio_direction_input(pdata->gpio_int);
if (ret < 0)
goto out;
bdi->irq = gpio_to_irq(pdata->gpio_int);
if (!bdi->irq)
goto out;
bdi->gpio_int = pdata->gpio_int;
return 0;
out:
gpio_free(pdata->gpio_int);
return -1;
}
static int bq24190_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct device *dev = &client->dev;
struct bq24190_platform_data *pdata = client->dev.platform_data;
struct power_supply_config charger_cfg = {}, battery_cfg = {};
struct bq24190_dev_info *bdi;
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(dev, "No support for SMBUS_BYTE_DATA\n");
return -ENODEV;
}
bdi = devm_kzalloc(dev, sizeof(*bdi), GFP_KERNEL);
if (!bdi) {
dev_err(dev, "Can't alloc bdi struct\n");
return -ENOMEM;
}
bdi->client = client;
bdi->dev = dev;
bdi->model = id->driver_data;
strncpy(bdi->model_name, id->name, I2C_NAME_SIZE);
mutex_init(&bdi->f_reg_lock);
bdi->first_time = true;
bdi->charger_health_valid = false;
bdi->battery_health_valid = false;
bdi->battery_status_valid = false;
i2c_set_clientdata(client, bdi);
if (dev->of_node)
ret = bq24190_setup_dt(bdi);
else
ret = bq24190_setup_pdata(bdi, pdata);
if (ret) {
dev_err(dev, "Can't get irq info\n");
return -EINVAL;
}
ret = devm_request_threaded_irq(dev, bdi->irq, NULL,
bq24190_irq_handler_thread,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"bq24190-charger", bdi);
if (ret < 0) {
dev_err(dev, "Can't set up irq handler\n");
goto out1;
}
pm_runtime_enable(dev);
pm_runtime_resume(dev);
ret = bq24190_hw_init(bdi);
if (ret < 0) {
dev_err(dev, "Hardware init failed\n");
goto out2;
}
charger_cfg.drv_data = bdi;
charger_cfg.supplied_to = bq24190_charger_supplied_to;
charger_cfg.num_supplicants = ARRAY_SIZE(bq24190_charger_supplied_to),
bdi->charger = power_supply_register(dev, &bq24190_charger_desc,
&charger_cfg);
if (IS_ERR(bdi->charger)) {
dev_err(dev, "Can't register charger\n");
ret = PTR_ERR(bdi->charger);
goto out2;
}
battery_cfg.drv_data = bdi;
bdi->battery = power_supply_register(dev, &bq24190_battery_desc,
&battery_cfg);
if (IS_ERR(bdi->battery)) {
dev_err(dev, "Can't register battery\n");
ret = PTR_ERR(bdi->battery);
goto out3;
}
ret = bq24190_sysfs_create_group(bdi);
if (ret) {
dev_err(dev, "Can't create sysfs entries\n");
goto out4;
}
return 0;
out4:
power_supply_unregister(bdi->battery);
out3:
power_supply_unregister(bdi->charger);
out2:
pm_runtime_disable(dev);
out1:
if (bdi->gpio_int)
gpio_free(bdi->gpio_int);
return ret;
}
static int bq24190_remove(struct i2c_client *client)
{
struct bq24190_dev_info *bdi = i2c_get_clientdata(client);
pm_runtime_get_sync(bdi->dev);
bq24190_register_reset(bdi);
pm_runtime_put_sync(bdi->dev);
bq24190_sysfs_remove_group(bdi);
power_supply_unregister(bdi->battery);
power_supply_unregister(bdi->charger);
pm_runtime_disable(bdi->dev);
if (bdi->gpio_int)
gpio_free(bdi->gpio_int);
return 0;
}
static int bq24190_pm_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct bq24190_dev_info *bdi = i2c_get_clientdata(client);
pm_runtime_get_sync(bdi->dev);
bq24190_register_reset(bdi);
pm_runtime_put_sync(bdi->dev);
return 0;
}
static int bq24190_pm_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct bq24190_dev_info *bdi = i2c_get_clientdata(client);
bdi->charger_health_valid = false;
bdi->battery_health_valid = false;
bdi->battery_status_valid = false;
pm_runtime_get_sync(bdi->dev);
bq24190_register_reset(bdi);
pm_runtime_put_sync(bdi->dev);
power_supply_changed(bdi->charger);
power_supply_changed(bdi->battery);
return 0;
}
