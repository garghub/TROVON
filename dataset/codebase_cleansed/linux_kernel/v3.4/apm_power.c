static int __find_main_battery(struct device *dev, void *data)
{
struct find_bat_param *bp = (struct find_bat_param *)data;
bp->bat = dev_get_drvdata(dev);
if (bp->bat->use_for_apm) {
bp->main = bp->bat;
return 1;
}
if (!PSY_PROP(bp->bat, CHARGE_FULL_DESIGN, &bp->full) ||
!PSY_PROP(bp->bat, CHARGE_FULL, &bp->full)) {
if (bp->full.intval > bp->max_charge) {
bp->max_charge_bat = bp->bat;
bp->max_charge = bp->full.intval;
}
} else if (!PSY_PROP(bp->bat, ENERGY_FULL_DESIGN, &bp->full) ||
!PSY_PROP(bp->bat, ENERGY_FULL, &bp->full)) {
if (bp->full.intval > bp->max_energy) {
bp->max_energy_bat = bp->bat;
bp->max_energy = bp->full.intval;
}
}
return 0;
}
static void find_main_battery(void)
{
struct find_bat_param bp;
int error;
memset(&bp, 0, sizeof(struct find_bat_param));
main_battery = NULL;
bp.main = main_battery;
error = class_for_each_device(power_supply_class, NULL, &bp,
__find_main_battery);
if (error) {
main_battery = bp.main;
return;
}
if ((bp.max_energy_bat && bp.max_charge_bat) &&
(bp.max_energy_bat != bp.max_charge_bat)) {
if (!PSY_PROP(bp.max_charge_bat, VOLTAGE_MAX_DESIGN,
&bp.full)) {
if (bp.max_energy > bp.max_charge * bp.full.intval)
main_battery = bp.max_energy_bat;
else
main_battery = bp.max_charge_bat;
} else if (!PSY_PROP(bp.max_energy_bat, VOLTAGE_MAX_DESIGN,
&bp.full)) {
if (bp.max_charge > bp.max_energy / bp.full.intval)
main_battery = bp.max_charge_bat;
else
main_battery = bp.max_energy_bat;
} else {
main_battery = bp.max_energy_bat;
}
} else if (bp.max_charge_bat) {
main_battery = bp.max_charge_bat;
} else if (bp.max_energy_bat) {
main_battery = bp.max_energy_bat;
} else {
main_battery = bp.bat;
}
}
static int do_calculate_time(int status, enum apm_source source)
{
union power_supply_propval full;
union power_supply_propval empty;
union power_supply_propval cur;
union power_supply_propval I;
enum power_supply_property full_prop;
enum power_supply_property full_design_prop;
enum power_supply_property empty_prop;
enum power_supply_property empty_design_prop;
enum power_supply_property cur_avg_prop;
enum power_supply_property cur_now_prop;
if (MPSY_PROP(CURRENT_AVG, &I)) {
if (MPSY_PROP(CURRENT_NOW, &I))
return -1;
}
if (!I.intval)
return 0;
switch (source) {
case SOURCE_CHARGE:
full_prop = POWER_SUPPLY_PROP_CHARGE_FULL;
full_design_prop = POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN;
empty_prop = POWER_SUPPLY_PROP_CHARGE_EMPTY;
empty_design_prop = POWER_SUPPLY_PROP_CHARGE_EMPTY;
cur_avg_prop = POWER_SUPPLY_PROP_CHARGE_AVG;
cur_now_prop = POWER_SUPPLY_PROP_CHARGE_NOW;
break;
case SOURCE_ENERGY:
full_prop = POWER_SUPPLY_PROP_ENERGY_FULL;
full_design_prop = POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN;
empty_prop = POWER_SUPPLY_PROP_ENERGY_EMPTY;
empty_design_prop = POWER_SUPPLY_PROP_CHARGE_EMPTY;
cur_avg_prop = POWER_SUPPLY_PROP_ENERGY_AVG;
cur_now_prop = POWER_SUPPLY_PROP_ENERGY_NOW;
break;
case SOURCE_VOLTAGE:
full_prop = POWER_SUPPLY_PROP_VOLTAGE_MAX;
full_design_prop = POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN;
empty_prop = POWER_SUPPLY_PROP_VOLTAGE_MIN;
empty_design_prop = POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN;
cur_avg_prop = POWER_SUPPLY_PROP_VOLTAGE_AVG;
cur_now_prop = POWER_SUPPLY_PROP_VOLTAGE_NOW;
break;
default:
printk(KERN_ERR "Unsupported source: %d\n", source);
return -1;
}
if (_MPSY_PROP(full_prop, &full)) {
if (_MPSY_PROP(full_design_prop, &full))
return -1;
}
if (_MPSY_PROP(empty_prop, &empty)) {
if (_MPSY_PROP(empty_design_prop, &empty))
empty.intval = 0;
}
if (_MPSY_PROP(cur_avg_prop, &cur)) {
if (_MPSY_PROP(cur_now_prop, &cur))
return -1;
}
if (status == POWER_SUPPLY_STATUS_CHARGING)
return ((cur.intval - full.intval) * 60L) / I.intval;
else
return -((cur.intval - empty.intval) * 60L) / I.intval;
}
static int calculate_time(int status)
{
int time;
time = do_calculate_time(status, SOURCE_ENERGY);
if (time != -1)
return time;
time = do_calculate_time(status, SOURCE_CHARGE);
if (time != -1)
return time;
time = do_calculate_time(status, SOURCE_VOLTAGE);
if (time != -1)
return time;
return -1;
}
static int calculate_capacity(enum apm_source source)
{
enum power_supply_property full_prop, empty_prop;
enum power_supply_property full_design_prop, empty_design_prop;
enum power_supply_property now_prop, avg_prop;
union power_supply_propval empty, full, cur;
int ret;
switch (source) {
case SOURCE_CHARGE:
full_prop = POWER_SUPPLY_PROP_CHARGE_FULL;
empty_prop = POWER_SUPPLY_PROP_CHARGE_EMPTY;
full_design_prop = POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN;
empty_design_prop = POWER_SUPPLY_PROP_CHARGE_EMPTY_DESIGN;
now_prop = POWER_SUPPLY_PROP_CHARGE_NOW;
avg_prop = POWER_SUPPLY_PROP_CHARGE_AVG;
break;
case SOURCE_ENERGY:
full_prop = POWER_SUPPLY_PROP_ENERGY_FULL;
empty_prop = POWER_SUPPLY_PROP_ENERGY_EMPTY;
full_design_prop = POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN;
empty_design_prop = POWER_SUPPLY_PROP_ENERGY_EMPTY_DESIGN;
now_prop = POWER_SUPPLY_PROP_ENERGY_NOW;
avg_prop = POWER_SUPPLY_PROP_ENERGY_AVG;
break;
case SOURCE_VOLTAGE:
full_prop = POWER_SUPPLY_PROP_VOLTAGE_MAX;
empty_prop = POWER_SUPPLY_PROP_VOLTAGE_MIN;
full_design_prop = POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN;
empty_design_prop = POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN;
now_prop = POWER_SUPPLY_PROP_VOLTAGE_NOW;
avg_prop = POWER_SUPPLY_PROP_VOLTAGE_AVG;
break;
default:
printk(KERN_ERR "Unsupported source: %d\n", source);
return -1;
}
if (_MPSY_PROP(full_prop, &full)) {
if (_MPSY_PROP(full_design_prop, &full))
return -1;
}
if (_MPSY_PROP(avg_prop, &cur)) {
if (_MPSY_PROP(now_prop, &cur))
return -1;
}
if (_MPSY_PROP(empty_prop, &empty)) {
if (_MPSY_PROP(empty_design_prop, &empty))
empty.intval = 0;
}
if (full.intval - empty.intval)
ret = ((cur.intval - empty.intval) * 100L) /
(full.intval - empty.intval);
else
return -1;
if (ret > 100)
return 100;
else if (ret < 0)
return 0;
return ret;
}
static void apm_battery_apm_get_power_status(struct apm_power_info *info)
{
union power_supply_propval status;
union power_supply_propval capacity, time_to_full, time_to_empty;
mutex_lock(&apm_mutex);
find_main_battery();
if (!main_battery) {
mutex_unlock(&apm_mutex);
return;
}
if (MPSY_PROP(STATUS, &status))
status.intval = POWER_SUPPLY_STATUS_UNKNOWN;
if ((status.intval == POWER_SUPPLY_STATUS_CHARGING) ||
(status.intval == POWER_SUPPLY_STATUS_NOT_CHARGING) ||
(status.intval == POWER_SUPPLY_STATUS_FULL))
info->ac_line_status = APM_AC_ONLINE;
else
info->ac_line_status = APM_AC_OFFLINE;
if (MPSY_PROP(CAPACITY, &capacity) == 0) {
info->battery_life = capacity.intval;
} else {
info->battery_life = calculate_capacity(SOURCE_ENERGY);
if (info->battery_life == -1)
info->battery_life = calculate_capacity(SOURCE_CHARGE);
if (info->battery_life == -1)
info->battery_life = calculate_capacity(SOURCE_VOLTAGE);
}
if (status.intval == POWER_SUPPLY_STATUS_CHARGING) {
info->battery_status = APM_BATTERY_STATUS_CHARGING;
} else {
if (info->battery_life > 50)
info->battery_status = APM_BATTERY_STATUS_HIGH;
else if (info->battery_life > 5)
info->battery_status = APM_BATTERY_STATUS_LOW;
else
info->battery_status = APM_BATTERY_STATUS_CRITICAL;
}
info->battery_flag = info->battery_status;
info->units = APM_UNITS_MINS;
if (status.intval == POWER_SUPPLY_STATUS_CHARGING) {
if (!MPSY_PROP(TIME_TO_FULL_AVG, &time_to_full) ||
!MPSY_PROP(TIME_TO_FULL_NOW, &time_to_full))
info->time = time_to_full.intval / 60;
else
info->time = calculate_time(status.intval);
} else {
if (!MPSY_PROP(TIME_TO_EMPTY_AVG, &time_to_empty) ||
!MPSY_PROP(TIME_TO_EMPTY_NOW, &time_to_empty))
info->time = time_to_empty.intval / 60;
else
info->time = calculate_time(status.intval);
}
mutex_unlock(&apm_mutex);
}
static int __init apm_battery_init(void)
{
printk(KERN_INFO "APM Battery Driver\n");
apm_get_power_status = apm_battery_apm_get_power_status;
return 0;
}
static void __exit apm_battery_exit(void)
{
apm_get_power_status = NULL;
}
