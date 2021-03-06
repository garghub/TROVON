static int max77693_get_charger_state(struct regmap *regmap)
{
int state;
unsigned int data;
if (regmap_read(regmap, MAX77693_CHG_REG_CHG_DETAILS_01, &data) < 0)
return POWER_SUPPLY_STATUS_UNKNOWN;
data &= CHG_DETAILS_01_CHG_MASK;
data >>= CHG_DETAILS_01_CHG_SHIFT;
switch (data) {
case MAX77693_CHARGING_PREQUALIFICATION:
case MAX77693_CHARGING_FAST_CONST_CURRENT:
case MAX77693_CHARGING_FAST_CONST_VOLTAGE:
case MAX77693_CHARGING_TOP_OFF:
case MAX77693_CHARGING_HIGH_TEMP:
state = POWER_SUPPLY_STATUS_CHARGING;
break;
case MAX77693_CHARGING_DONE:
state = POWER_SUPPLY_STATUS_FULL;
break;
case MAX77693_CHARGING_TIMER_EXPIRED:
case MAX77693_CHARGING_THERMISTOR_SUSPEND:
state = POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
case MAX77693_CHARGING_OFF:
case MAX77693_CHARGING_OVER_TEMP:
case MAX77693_CHARGING_WATCHDOG_EXPIRED:
state = POWER_SUPPLY_STATUS_DISCHARGING;
break;
case MAX77693_CHARGING_RESERVED:
default:
state = POWER_SUPPLY_STATUS_UNKNOWN;
}
return state;
}
static int max77693_get_charge_type(struct regmap *regmap)
{
int state;
unsigned int data;
if (regmap_read(regmap, MAX77693_CHG_REG_CHG_DETAILS_01, &data) < 0)
return POWER_SUPPLY_CHARGE_TYPE_UNKNOWN;
data &= CHG_DETAILS_01_CHG_MASK;
data >>= CHG_DETAILS_01_CHG_SHIFT;
switch (data) {
case MAX77693_CHARGING_PREQUALIFICATION:
case MAX77693_CHARGING_TOP_OFF:
state = POWER_SUPPLY_CHARGE_TYPE_TRICKLE;
break;
case MAX77693_CHARGING_FAST_CONST_CURRENT:
case MAX77693_CHARGING_FAST_CONST_VOLTAGE:
case MAX77693_CHARGING_HIGH_TEMP:
state = POWER_SUPPLY_CHARGE_TYPE_FAST;
break;
case MAX77693_CHARGING_DONE:
case MAX77693_CHARGING_TIMER_EXPIRED:
case MAX77693_CHARGING_THERMISTOR_SUSPEND:
case MAX77693_CHARGING_OFF:
case MAX77693_CHARGING_OVER_TEMP:
case MAX77693_CHARGING_WATCHDOG_EXPIRED:
state = POWER_SUPPLY_CHARGE_TYPE_NONE;
break;
case MAX77693_CHARGING_RESERVED:
default:
state = POWER_SUPPLY_CHARGE_TYPE_UNKNOWN;
}
return state;
}
static int max77693_get_battery_health(struct regmap *regmap)
{
int state;
unsigned int data;
if (regmap_read(regmap, MAX77693_CHG_REG_CHG_DETAILS_01, &data) < 0)
return POWER_SUPPLY_HEALTH_UNKNOWN;
data &= CHG_DETAILS_01_BAT_MASK;
data >>= CHG_DETAILS_01_BAT_SHIFT;
switch (data) {
case MAX77693_BATTERY_NOBAT:
state = POWER_SUPPLY_HEALTH_DEAD;
break;
case MAX77693_BATTERY_PREQUALIFICATION:
case MAX77693_BATTERY_GOOD:
case MAX77693_BATTERY_LOWVOLTAGE:
state = POWER_SUPPLY_HEALTH_GOOD;
break;
case MAX77693_BATTERY_TIMER_EXPIRED:
state = POWER_SUPPLY_HEALTH_SAFETY_TIMER_EXPIRE;
break;
case MAX77693_BATTERY_OVERVOLTAGE:
state = POWER_SUPPLY_HEALTH_OVERVOLTAGE;
break;
case MAX77693_BATTERY_OVERCURRENT:
state = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
case MAX77693_BATTERY_RESERVED:
default:
state = POWER_SUPPLY_HEALTH_UNKNOWN;
break;
}
return state;
}
static int max77693_get_present(struct regmap *regmap)
{
unsigned int data;
regmap_read(regmap, MAX77693_CHG_REG_CHG_INT_OK, &data);
if (data & CHG_INT_OK_DETBAT_MASK)
return 0;
return 1;
}
static int max77693_get_online(struct regmap *regmap)
{
unsigned int data;
regmap_read(regmap, MAX77693_CHG_REG_CHG_INT_OK, &data);
if (data & CHG_INT_OK_CHGIN_MASK)
return 1;
return 0;
}
static int max77693_charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct max77693_charger *chg = container_of(psy,
struct max77693_charger,
charger);
struct regmap *regmap = chg->max77693->regmap;
int ret = 0;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
val->intval = max77693_get_charger_state(regmap);
break;
case POWER_SUPPLY_PROP_CHARGE_TYPE:
val->intval = max77693_get_charge_type(regmap);
break;
case POWER_SUPPLY_PROP_HEALTH:
val->intval = max77693_get_battery_health(regmap);
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = max77693_get_present(regmap);
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = max77693_get_online(regmap);
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = max77693_charger_model;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = max77693_charger_manufacturer;
break;
default:
return -EINVAL;
}
return ret;
}
static ssize_t device_attr_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count,
int (*fn)(struct max77693_charger *, unsigned long))
{
struct max77693_charger *chg = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
ret = fn(chg, val);
if (ret)
return ret;
return count;
}
static ssize_t fast_charge_timer_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct max77693_charger *chg = dev_get_drvdata(dev);
unsigned int data, val;
int ret;
ret = regmap_read(chg->max77693->regmap, MAX77693_CHG_REG_CHG_CNFG_01,
&data);
if (ret < 0)
return ret;
data &= CHG_CNFG_01_FCHGTIME_MASK;
data >>= CHG_CNFG_01_FCHGTIME_SHIFT;
switch (data) {
case 0x1 ... 0x7:
val = 4 + (data - 1) * 2;
break;
case 0x0:
default:
val = 0;
break;
}
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static int max77693_set_fast_charge_timer(struct max77693_charger *chg,
unsigned long hours)
{
unsigned int data;
switch (hours) {
case 4 ... 16:
data = (hours - 4) / 2 + 1;
break;
case 0:
data = 0;
break;
default:
return -EINVAL;
}
data <<= CHG_CNFG_01_FCHGTIME_SHIFT;
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_01,
CHG_CNFG_01_FCHGTIME_MASK, data);
}
static ssize_t fast_charge_timer_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return device_attr_store(dev, attr, buf, count,
max77693_set_fast_charge_timer);
}
static ssize_t top_off_threshold_current_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct max77693_charger *chg = dev_get_drvdata(dev);
unsigned int data, val;
int ret;
ret = regmap_read(chg->max77693->regmap, MAX77693_CHG_REG_CHG_CNFG_03,
&data);
if (ret < 0)
return ret;
data &= CHG_CNFG_03_TOITH_MASK;
data >>= CHG_CNFG_03_TOITH_SHIFT;
if (data <= 0x04)
val = 100000 + data * 25000;
else
val = data * 50000;
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static int max77693_set_top_off_threshold_current(struct max77693_charger *chg,
unsigned long uamp)
{
unsigned int data;
if (uamp < 100000 || uamp > 350000)
return -EINVAL;
if (uamp <= 200000)
data = (uamp - 100000) / 25000;
else
data = uamp / 50000;
data <<= CHG_CNFG_03_TOITH_SHIFT;
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_03,
CHG_CNFG_03_TOITH_MASK, data);
}
static ssize_t top_off_threshold_current_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return device_attr_store(dev, attr, buf, count,
max77693_set_top_off_threshold_current);
}
static ssize_t top_off_timer_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct max77693_charger *chg = dev_get_drvdata(dev);
unsigned int data, val;
int ret;
ret = regmap_read(chg->max77693->regmap, MAX77693_CHG_REG_CHG_CNFG_03,
&data);
if (ret < 0)
return ret;
data &= CHG_CNFG_03_TOTIME_MASK;
data >>= CHG_CNFG_03_TOTIME_SHIFT;
val = data * 10;
return scnprintf(buf, PAGE_SIZE, "%u\n", val);
}
static int max77693_set_top_off_timer(struct max77693_charger *chg,
unsigned long minutes)
{
unsigned int data;
if (minutes > 70)
return -EINVAL;
data = minutes / 10;
data <<= CHG_CNFG_03_TOTIME_SHIFT;
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_03,
CHG_CNFG_03_TOTIME_MASK, data);
}
static ssize_t top_off_timer_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
return device_attr_store(dev, attr, buf, count,
max77693_set_top_off_timer);
}
static int max77693_set_constant_volt(struct max77693_charger *chg,
unsigned int uvolt)
{
unsigned int data;
if (uvolt >= 3650000 && uvolt < 4340000)
data = (uvolt - 3650000) / 25000;
else if (uvolt >= 4340000 && uvolt < 4350000)
data = 0x1c;
else if (uvolt >= 4350000 && uvolt <= 4400000)
data = 0x1d + (uvolt - 4350000) / 25000;
else {
dev_err(chg->dev, "Wrong value for charging constant voltage\n");
return -EINVAL;
}
data <<= CHG_CNFG_04_CHGCVPRM_SHIFT;
dev_dbg(chg->dev, "Charging constant voltage: %u (0x%x)\n", uvolt,
data);
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_04,
CHG_CNFG_04_CHGCVPRM_MASK, data);
}
static int max77693_set_min_system_volt(struct max77693_charger *chg,
unsigned int uvolt)
{
unsigned int data;
if (uvolt < 3000000 || uvolt > 3700000) {
dev_err(chg->dev, "Wrong value for minimum system regulation voltage\n");
return -EINVAL;
}
data = (uvolt - 3000000) / 100000;
data <<= CHG_CNFG_04_MINVSYS_SHIFT;
dev_dbg(chg->dev, "Minimum system regulation voltage: %u (0x%x)\n",
uvolt, data);
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_04,
CHG_CNFG_04_MINVSYS_MASK, data);
}
static int max77693_set_thermal_regulation_temp(struct max77693_charger *chg,
unsigned int cels)
{
unsigned int data;
switch (cels) {
case 70:
case 85:
case 100:
case 115:
data = (cels - 70) / 15;
break;
default:
dev_err(chg->dev, "Wrong value for thermal regulation loop temperature\n");
return -EINVAL;
}
data <<= CHG_CNFG_07_REGTEMP_SHIFT;
dev_dbg(chg->dev, "Thermal regulation loop temperature: %u (0x%x)\n",
cels, data);
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_07,
CHG_CNFG_07_REGTEMP_MASK, data);
}
static int max77693_set_batttery_overcurrent(struct max77693_charger *chg,
unsigned int uamp)
{
unsigned int data;
if (uamp && (uamp < 2000000 || uamp > 3500000)) {
dev_err(chg->dev, "Wrong value for battery overcurrent\n");
return -EINVAL;
}
if (uamp)
data = ((uamp - 2000000) / 250000) + 1;
else
data = 0;
data <<= CHG_CNFG_12_B2SOVRC_SHIFT;
dev_dbg(chg->dev, "Battery overcurrent: %u (0x%x)\n", uamp, data);
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_12,
CHG_CNFG_12_B2SOVRC_MASK, data);
}
static int max77693_set_charge_input_threshold_volt(struct max77693_charger *chg,
unsigned int uvolt)
{
unsigned int data;
switch (uvolt) {
case 4300000:
data = 0x0;
break;
case 4700000:
case 4800000:
case 4900000:
data = (uvolt - 4700000) / 100000;
default:
dev_err(chg->dev, "Wrong value for charge input voltage regulation threshold\n");
return -EINVAL;
}
data <<= CHG_CNFG_12_VCHGINREG_SHIFT;
dev_dbg(chg->dev, "Charge input voltage regulation threshold: %u (0x%x)\n",
uvolt, data);
return regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_12,
CHG_CNFG_12_VCHGINREG_MASK, data);
}
static int max77693_reg_init(struct max77693_charger *chg)
{
int ret;
unsigned int data;
data = (0x3 << CHG_CNFG_06_CHGPROT_SHIFT);
ret = regmap_update_bits(chg->max77693->regmap,
MAX77693_CHG_REG_CHG_CNFG_06,
CHG_CNFG_06_CHGPROT_MASK, data);
if (ret) {
dev_err(chg->dev, "Error unlocking registers: %d\n", ret);
return ret;
}
ret = max77693_set_fast_charge_timer(chg, DEFAULT_FAST_CHARGE_TIMER);
if (ret)
return ret;
ret = max77693_set_top_off_threshold_current(chg,
DEFAULT_TOP_OFF_THRESHOLD_CURRENT);
if (ret)
return ret;
ret = max77693_set_top_off_timer(chg, DEFAULT_TOP_OFF_TIMER);
if (ret)
return ret;
ret = max77693_set_constant_volt(chg, chg->constant_volt);
if (ret)
return ret;
ret = max77693_set_min_system_volt(chg, chg->min_system_volt);
if (ret)
return ret;
ret = max77693_set_thermal_regulation_temp(chg,
chg->thermal_regulation_temp);
if (ret)
return ret;
ret = max77693_set_batttery_overcurrent(chg, chg->batttery_overcurrent);
if (ret)
return ret;
return max77693_set_charge_input_threshold_volt(chg,
chg->charge_input_threshold_volt);
}
static int max77693_dt_init(struct device *dev, struct max77693_charger *chg)
{
struct device_node *np = dev->of_node;
if (!np) {
dev_err(dev, "no charger OF node\n");
return -EINVAL;
}
if (of_property_read_u32(np, "maxim,constant-microvolt",
&chg->constant_volt))
chg->constant_volt = DEFAULT_CONSTANT_VOLT;
if (of_property_read_u32(np, "maxim,min-system-microvolt",
&chg->min_system_volt))
chg->min_system_volt = DEFAULT_MIN_SYSTEM_VOLT;
if (of_property_read_u32(np, "maxim,thermal-regulation-celsius",
&chg->thermal_regulation_temp))
chg->thermal_regulation_temp = DEFAULT_THERMAL_REGULATION_TEMP;
if (of_property_read_u32(np, "maxim,battery-overcurrent-microamp",
&chg->batttery_overcurrent))
chg->batttery_overcurrent = DEFAULT_BATTERY_OVERCURRENT;
if (of_property_read_u32(np, "maxim,charge-input-threshold-microvolt",
&chg->charge_input_threshold_volt))
chg->charge_input_threshold_volt =
DEFAULT_CHARGER_INPUT_THRESHOLD_VOLT;
return 0;
}
static int max77693_dt_init(struct device *dev, struct max77693_charger *chg)
{
return 0;
}
static int max77693_charger_probe(struct platform_device *pdev)
{
struct max77693_charger *chg;
struct max77693_dev *max77693 = dev_get_drvdata(pdev->dev.parent);
int ret;
chg = devm_kzalloc(&pdev->dev, sizeof(*chg), GFP_KERNEL);
if (!chg)
return -ENOMEM;
platform_set_drvdata(pdev, chg);
chg->dev = &pdev->dev;
chg->max77693 = max77693;
ret = max77693_dt_init(&pdev->dev, chg);
if (ret)
return ret;
ret = max77693_reg_init(chg);
if (ret)
return ret;
chg->charger.name = max77693_charger_name;
chg->charger.type = POWER_SUPPLY_TYPE_BATTERY;
chg->charger.properties = max77693_charger_props;
chg->charger.num_properties = ARRAY_SIZE(max77693_charger_props);
chg->charger.get_property = max77693_charger_get_property;
ret = device_create_file(&pdev->dev, &dev_attr_fast_charge_timer);
if (ret) {
dev_err(&pdev->dev, "failed: create fast charge timer sysfs entry\n");
goto err;
}
ret = device_create_file(&pdev->dev,
&dev_attr_top_off_threshold_current);
if (ret) {
dev_err(&pdev->dev, "failed: create top off current sysfs entry\n");
goto err;
}
ret = device_create_file(&pdev->dev, &dev_attr_top_off_timer);
if (ret) {
dev_err(&pdev->dev, "failed: create top off timer sysfs entry\n");
goto err;
}
ret = power_supply_register(&pdev->dev, &chg->charger);
if (ret) {
dev_err(&pdev->dev, "failed: power supply register\n");
goto err;
}
return 0;
err:
device_remove_file(&pdev->dev, &dev_attr_top_off_timer);
device_remove_file(&pdev->dev, &dev_attr_top_off_threshold_current);
device_remove_file(&pdev->dev, &dev_attr_fast_charge_timer);
return ret;
}
static int max77693_charger_remove(struct platform_device *pdev)
{
struct max77693_charger *chg = platform_get_drvdata(pdev);
device_remove_file(&pdev->dev, &dev_attr_top_off_timer);
device_remove_file(&pdev->dev, &dev_attr_top_off_threshold_current);
device_remove_file(&pdev->dev, &dev_attr_fast_charge_timer);
power_supply_unregister(&chg->charger);
return 0;
}
