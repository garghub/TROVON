static bool is_batt_present(struct charger_manager *cm)
{
union power_supply_propval val;
bool present = false;
int i, ret;
switch (cm->desc->battery_present) {
case CM_BATTERY_PRESENT:
present = true;
break;
case CM_NO_BATTERY:
break;
case CM_FUEL_GAUGE:
ret = cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_PRESENT, &val);
if (ret == 0 && val.intval)
present = true;
break;
case CM_CHARGER_STAT:
for (i = 0; cm->charger_stat[i]; i++) {
ret = cm->charger_stat[i]->get_property(
cm->charger_stat[i],
POWER_SUPPLY_PROP_PRESENT, &val);
if (ret == 0 && val.intval) {
present = true;
break;
}
}
break;
}
return present;
}
static bool is_ext_pwr_online(struct charger_manager *cm)
{
union power_supply_propval val;
bool online = false;
int i, ret;
for (i = 0; cm->charger_stat[i]; i++) {
ret = cm->charger_stat[i]->get_property(
cm->charger_stat[i],
POWER_SUPPLY_PROP_ONLINE, &val);
if (ret == 0 && val.intval) {
online = true;
break;
}
}
return online;
}
static int get_batt_uV(struct charger_manager *cm, int *uV)
{
union power_supply_propval val;
int ret;
if (!cm->fuel_gauge)
return -ENODEV;
ret = cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_VOLTAGE_NOW, &val);
if (ret)
return ret;
*uV = val.intval;
return 0;
}
static bool is_charging(struct charger_manager *cm)
{
int i, ret;
bool charging = false;
union power_supply_propval val;
if (!is_batt_present(cm))
return false;
for (i = 0; cm->charger_stat[i]; i++) {
if (cm->emergency_stop)
continue;
if (!cm->charger_enabled)
continue;
ret = cm->charger_stat[i]->get_property(
cm->charger_stat[i],
POWER_SUPPLY_PROP_ONLINE, &val);
if (ret) {
dev_warn(cm->dev, "Cannot read ONLINE value from %s.\n",
cm->desc->psy_charger_stat[i]);
continue;
}
if (val.intval == 0)
continue;
ret = cm->charger_stat[i]->get_property(
cm->charger_stat[i],
POWER_SUPPLY_PROP_STATUS, &val);
if (ret) {
dev_warn(cm->dev, "Cannot read STATUS value from %s.\n",
cm->desc->psy_charger_stat[i]);
continue;
}
if (val.intval == POWER_SUPPLY_STATUS_FULL ||
val.intval == POWER_SUPPLY_STATUS_DISCHARGING ||
val.intval == POWER_SUPPLY_STATUS_NOT_CHARGING)
continue;
charging = true;
break;
}
return charging;
}
static bool is_full_charged(struct charger_manager *cm)
{
struct charger_desc *desc = cm->desc;
union power_supply_propval val;
int ret = 0;
int uV;
if (!is_batt_present(cm))
return false;
if (cm->fuel_gauge && desc->fullbatt_full_capacity > 0) {
val.intval = 0;
ret = cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_CHARGE_FULL, &val);
if (!ret && val.intval > desc->fullbatt_full_capacity)
return true;
}
if (desc->fullbatt_uV > 0) {
ret = get_batt_uV(cm, &uV);
if (!ret && uV >= desc->fullbatt_uV)
return true;
}
if (cm->fuel_gauge && desc->fullbatt_soc > 0) {
val.intval = 0;
ret = cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_CAPACITY, &val);
if (!ret && val.intval >= desc->fullbatt_soc)
return true;
}
return false;
}
static bool is_polling_required(struct charger_manager *cm)
{
switch (cm->desc->polling_mode) {
case CM_POLL_DISABLE:
return false;
case CM_POLL_ALWAYS:
return true;
case CM_POLL_EXTERNAL_POWER_ONLY:
return is_ext_pwr_online(cm);
case CM_POLL_CHARGING_ONLY:
return is_charging(cm);
default:
dev_warn(cm->dev, "Incorrect polling_mode (%d)\n",
cm->desc->polling_mode);
}
return false;
}
static int try_charger_enable(struct charger_manager *cm, bool enable)
{
int err = 0, i;
struct charger_desc *desc = cm->desc;
if (enable == cm->charger_enabled)
return 0;
if (enable) {
if (cm->emergency_stop)
return -EAGAIN;
cm->charging_start_time = ktime_to_ms(ktime_get());
cm->charging_end_time = 0;
for (i = 0 ; i < desc->num_charger_regulators ; i++) {
if (desc->charger_regulators[i].externally_control)
continue;
err = regulator_enable(desc->charger_regulators[i].consumer);
if (err < 0) {
dev_warn(cm->dev,
"Cannot enable %s regulator\n",
desc->charger_regulators[i].regulator_name);
}
}
} else {
cm->charging_start_time = 0;
cm->charging_end_time = ktime_to_ms(ktime_get());
for (i = 0 ; i < desc->num_charger_regulators ; i++) {
if (desc->charger_regulators[i].externally_control)
continue;
err = regulator_disable(desc->charger_regulators[i].consumer);
if (err < 0) {
dev_warn(cm->dev,
"Cannot disable %s regulator\n",
desc->charger_regulators[i].regulator_name);
}
}
for (i = 0; i < desc->num_charger_regulators; i++) {
if (regulator_is_enabled(
desc->charger_regulators[i].consumer)) {
regulator_force_disable(
desc->charger_regulators[i].consumer);
dev_warn(cm->dev,
"Disable regulator(%s) forcibly.\n",
desc->charger_regulators[i].regulator_name);
}
}
}
if (!err)
cm->charger_enabled = enable;
return err;
}
static int try_charger_restart(struct charger_manager *cm)
{
int err;
if (cm->emergency_stop)
return -EAGAIN;
err = try_charger_enable(cm, false);
if (err)
return err;
return try_charger_enable(cm, true);
}
static void uevent_notify(struct charger_manager *cm, const char *event)
{
static char env_str[UEVENT_BUF_SIZE + 1] = "";
static char env_str_save[UEVENT_BUF_SIZE + 1] = "";
if (cm_suspended) {
if (env_str_save[0] == 0) {
if (!strncmp(env_str, event, UEVENT_BUF_SIZE))
return;
strncpy(env_str_save, event, UEVENT_BUF_SIZE);
return;
}
if (!strncmp(env_str_save, event, UEVENT_BUF_SIZE))
return;
strncpy(env_str_save, event, UEVENT_BUF_SIZE);
return;
}
if (event == NULL) {
if (!env_str_save[0])
return;
strncpy(env_str, env_str_save, UEVENT_BUF_SIZE);
kobject_uevent(&cm->dev->kobj, KOBJ_CHANGE);
env_str_save[0] = 0;
return;
}
if (!strncmp(env_str, event, UEVENT_BUF_SIZE))
return;
strncpy(env_str, event, UEVENT_BUF_SIZE);
kobject_uevent(&cm->dev->kobj, KOBJ_CHANGE);
dev_info(cm->dev, event);
}
static void fullbatt_vchk(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct charger_manager *cm = container_of(dwork,
struct charger_manager, fullbatt_vchk_work);
struct charger_desc *desc = cm->desc;
int batt_uV, err, diff;
cm->fullbatt_vchk_jiffies_at = 0;
if (!desc->fullbatt_vchkdrop_uV || !desc->fullbatt_vchkdrop_ms)
return;
err = get_batt_uV(cm, &batt_uV);
if (err) {
dev_err(cm->dev, "%s: get_batt_uV error(%d).\n", __func__, err);
return;
}
diff = desc->fullbatt_uV - batt_uV;
if (diff < 0)
return;
dev_info(cm->dev, "VBATT dropped %duV after full-batt.\n", diff);
if (diff > desc->fullbatt_vchkdrop_uV) {
try_charger_restart(cm);
uevent_notify(cm, "Recharging");
}
}
static int check_charging_duration(struct charger_manager *cm)
{
struct charger_desc *desc = cm->desc;
u64 curr = ktime_to_ms(ktime_get());
u64 duration;
int ret = false;
if (!desc->charging_max_duration_ms &&
!desc->discharging_max_duration_ms)
return ret;
if (cm->charger_enabled) {
duration = curr - cm->charging_start_time;
if (duration > desc->charging_max_duration_ms) {
dev_info(cm->dev, "Charging duration exceed %lldms",
desc->charging_max_duration_ms);
uevent_notify(cm, "Discharging");
try_charger_enable(cm, false);
ret = true;
}
} else if (is_ext_pwr_online(cm) && !cm->charger_enabled) {
duration = curr - cm->charging_end_time;
if (duration > desc->charging_max_duration_ms &&
is_ext_pwr_online(cm)) {
dev_info(cm->dev, "DisCharging duration exceed %lldms",
desc->discharging_max_duration_ms);
uevent_notify(cm, "Recharing");
try_charger_enable(cm, true);
ret = true;
}
}
return ret;
}
static bool _cm_monitor(struct charger_manager *cm)
{
struct charger_desc *desc = cm->desc;
int temp = desc->temperature_out_of_range(&cm->last_temp_mC);
dev_dbg(cm->dev, "monitoring (%2.2d.%3.3dC)\n",
cm->last_temp_mC / 1000, cm->last_temp_mC % 1000);
if (temp && cm->emergency_stop)
return false;
if (temp) {
cm->emergency_stop = temp;
if (!try_charger_enable(cm, false)) {
if (temp > 0)
uevent_notify(cm, "OVERHEAT");
else
uevent_notify(cm, "COLD");
}
} else if (!cm->emergency_stop && check_charging_duration(cm)) {
dev_dbg(cm->dev,
"Charging/Discharging duration is out of range");
} else if (!cm->emergency_stop && is_ext_pwr_online(cm) &&
!cm->charger_enabled) {
fullbatt_vchk(&cm->fullbatt_vchk_work.work);
} else if (!cm->emergency_stop && is_full_charged(cm) &&
cm->charger_enabled) {
dev_info(cm->dev, "EVENT_HANDLE: Battery Fully Charged.\n");
uevent_notify(cm, default_event_names[CM_EVENT_BATT_FULL]);
try_charger_enable(cm, false);
fullbatt_vchk(&cm->fullbatt_vchk_work.work);
} else {
cm->emergency_stop = 0;
if (is_ext_pwr_online(cm)) {
if (!try_charger_enable(cm, true))
uevent_notify(cm, "CHARGING");
}
}
return true;
}
static bool cm_monitor(void)
{
bool stop = false;
struct charger_manager *cm;
mutex_lock(&cm_list_mtx);
list_for_each_entry(cm, &cm_list, entry) {
if (_cm_monitor(cm))
stop = true;
}
mutex_unlock(&cm_list_mtx);
return stop;
}
static void _setup_polling(struct work_struct *work)
{
unsigned long min = ULONG_MAX;
struct charger_manager *cm;
bool keep_polling = false;
unsigned long _next_polling;
mutex_lock(&cm_list_mtx);
list_for_each_entry(cm, &cm_list, entry) {
if (is_polling_required(cm) && cm->desc->polling_interval_ms) {
keep_polling = true;
if (min > cm->desc->polling_interval_ms)
min = cm->desc->polling_interval_ms;
}
}
polling_jiffy = msecs_to_jiffies(min);
if (polling_jiffy <= CM_JIFFIES_SMALL)
polling_jiffy = CM_JIFFIES_SMALL + 1;
if (!keep_polling)
polling_jiffy = ULONG_MAX;
if (polling_jiffy == ULONG_MAX)
goto out;
WARN(cm_wq == NULL, "charger-manager: workqueue not initialized"
". try it later. %s\n", __func__);
_next_polling = jiffies + polling_jiffy;
if (!delayed_work_pending(&cm_monitor_work) ||
(delayed_work_pending(&cm_monitor_work) &&
time_after(next_polling, _next_polling))) {
next_polling = jiffies + polling_jiffy;
mod_delayed_work(cm_wq, &cm_monitor_work, polling_jiffy);
}
out:
mutex_unlock(&cm_list_mtx);
}
static void cm_monitor_poller(struct work_struct *work)
{
cm_monitor();
schedule_work(&setup_polling);
}
static void fullbatt_handler(struct charger_manager *cm)
{
struct charger_desc *desc = cm->desc;
if (!desc->fullbatt_vchkdrop_uV || !desc->fullbatt_vchkdrop_ms)
goto out;
if (cm_suspended)
device_set_wakeup_capable(cm->dev, true);
mod_delayed_work(cm_wq, &cm->fullbatt_vchk_work,
msecs_to_jiffies(desc->fullbatt_vchkdrop_ms));
cm->fullbatt_vchk_jiffies_at = jiffies + msecs_to_jiffies(
desc->fullbatt_vchkdrop_ms);
if (cm->fullbatt_vchk_jiffies_at == 0)
cm->fullbatt_vchk_jiffies_at = 1;
out:
dev_info(cm->dev, "EVENT_HANDLE: Battery Fully Charged.\n");
uevent_notify(cm, default_event_names[CM_EVENT_BATT_FULL]);
}
static void battout_handler(struct charger_manager *cm)
{
if (cm_suspended)
device_set_wakeup_capable(cm->dev, true);
if (!is_batt_present(cm)) {
dev_emerg(cm->dev, "Battery Pulled Out!\n");
uevent_notify(cm, default_event_names[CM_EVENT_BATT_OUT]);
} else {
uevent_notify(cm, "Battery Reinserted?");
}
}
static void misc_event_handler(struct charger_manager *cm,
enum cm_event_types type)
{
if (cm_suspended)
device_set_wakeup_capable(cm->dev, true);
if (!delayed_work_pending(&cm_monitor_work) &&
is_polling_required(cm) && cm->desc->polling_interval_ms)
schedule_work(&setup_polling);
uevent_notify(cm, default_event_names[type]);
}
static int charger_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct charger_manager *cm = container_of(psy,
struct charger_manager, charger_psy);
struct charger_desc *desc = cm->desc;
int ret = 0;
int uV;
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (is_charging(cm))
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else if (is_ext_pwr_online(cm))
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
case POWER_SUPPLY_PROP_HEALTH:
if (cm->emergency_stop > 0)
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
else if (cm->emergency_stop < 0)
val->intval = POWER_SUPPLY_HEALTH_COLD;
else
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
case POWER_SUPPLY_PROP_PRESENT:
if (is_batt_present(cm))
val->intval = 1;
else
val->intval = 0;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = get_batt_uV(cm, &val->intval);
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_CURRENT_NOW, val);
break;
case POWER_SUPPLY_PROP_TEMP:
if (cm->last_temp_mC == INT_MIN)
desc->temperature_out_of_range(&cm->last_temp_mC);
val->intval = cm->last_temp_mC / 100;
if (!desc->measure_battery_temp)
ret = -ENODEV;
break;
case POWER_SUPPLY_PROP_TEMP_AMBIENT:
if (cm->last_temp_mC == INT_MIN)
desc->temperature_out_of_range(&cm->last_temp_mC);
val->intval = cm->last_temp_mC / 100;
if (desc->measure_battery_temp)
ret = -ENODEV;
break;
case POWER_SUPPLY_PROP_CAPACITY:
if (!cm->fuel_gauge) {
ret = -ENODEV;
break;
}
if (!is_batt_present(cm)) {
val->intval = 100;
break;
}
ret = cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_CAPACITY, val);
if (ret)
break;
if (val->intval > 100) {
val->intval = 100;
break;
}
if (val->intval < 0)
val->intval = 0;
if (is_charging(cm))
break;
ret = get_batt_uV(cm, &uV);
if (ret) {
ret = 0;
break;
}
if (desc->fullbatt_uV > 0 && uV >= desc->fullbatt_uV &&
!is_charging(cm)) {
val->intval = 100;
break;
}
break;
case POWER_SUPPLY_PROP_ONLINE:
if (is_ext_pwr_online(cm))
val->intval = 1;
else
val->intval = 0;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL:
if (is_full_charged(cm))
val->intval = 1;
else
val->intval = 0;
ret = 0;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
if (is_charging(cm)) {
ret = cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_CHARGE_NOW,
val);
if (ret) {
val->intval = 1;
ret = 0;
} else {
val->intval = (val->intval > 0) ?
val->intval : 1;
}
} else {
val->intval = 0;
}
break;
default:
return -EINVAL;
}
return ret;
}
static bool cm_setup_timer(void)
{
struct charger_manager *cm;
unsigned int wakeup_ms = UINT_MAX;
bool ret = false;
mutex_lock(&cm_list_mtx);
list_for_each_entry(cm, &cm_list, entry) {
unsigned int fbchk_ms = 0;
if (cm->fullbatt_vchk_jiffies_at) {
fbchk_ms = jiffies_to_msecs(cm->fullbatt_vchk_jiffies_at
- jiffies);
if (time_is_before_eq_jiffies(
cm->fullbatt_vchk_jiffies_at) ||
msecs_to_jiffies(fbchk_ms) < CM_JIFFIES_SMALL) {
fullbatt_vchk(&cm->fullbatt_vchk_work.work);
fbchk_ms = 0;
}
}
CM_MIN_VALID(wakeup_ms, fbchk_ms);
if (!is_polling_required(cm) && !cm->emergency_stop)
continue;
if (cm->desc->polling_interval_ms == 0)
continue;
CM_MIN_VALID(wakeup_ms, cm->desc->polling_interval_ms);
}
mutex_unlock(&cm_list_mtx);
if (wakeup_ms < UINT_MAX && wakeup_ms > 0) {
pr_info("Charger Manager wakeup timer: %u ms.\n", wakeup_ms);
if (rtc_dev) {
struct rtc_wkalrm tmp;
unsigned long time, now;
unsigned long add = DIV_ROUND_UP(wakeup_ms, 1000);
tmp.enabled = 1;
rtc_read_time(rtc_dev, &tmp.time);
rtc_tm_to_time(&tmp.time, &now);
if (add < CM_RTC_SMALL)
add = CM_RTC_SMALL;
time = now + add;
ret = true;
if (rtc_wkalarm_save.enabled &&
rtc_wkalarm_save_time &&
rtc_wkalarm_save_time < time) {
if (rtc_wkalarm_save_time < now + CM_RTC_SMALL)
time = now + CM_RTC_SMALL;
else
time = rtc_wkalarm_save_time;
ret = false;
}
pr_info("Waking up after %lu secs.\n",
time - now);
rtc_time_to_tm(time, &tmp.time);
rtc_set_alarm(rtc_dev, &tmp);
cm_suspend_duration_ms += wakeup_ms;
return ret;
}
}
if (rtc_dev)
rtc_set_alarm(rtc_dev, &rtc_wkalarm_save);
return false;
}
static void _cm_fbchk_in_suspend(struct charger_manager *cm)
{
unsigned long jiffy_now = jiffies;
if (!cm->fullbatt_vchk_jiffies_at)
return;
if (g_desc && g_desc->assume_timer_stops_in_suspend)
jiffy_now += msecs_to_jiffies(cm_suspend_duration_ms);
jiffy_now += CM_JIFFIES_SMALL;
if (time_after_eq(jiffy_now, cm->fullbatt_vchk_jiffies_at))
fullbatt_vchk(&cm->fullbatt_vchk_work.work);
}
bool cm_suspend_again(void)
{
struct charger_manager *cm;
bool ret = false;
if (!g_desc || !g_desc->rtc_only_wakeup || !g_desc->rtc_only_wakeup() ||
!cm_rtc_set)
return false;
if (cm_monitor())
goto out;
ret = true;
mutex_lock(&cm_list_mtx);
list_for_each_entry(cm, &cm_list, entry) {
_cm_fbchk_in_suspend(cm);
if (cm->status_save_ext_pwr_inserted != is_ext_pwr_online(cm) ||
cm->status_save_batt != is_batt_present(cm)) {
ret = false;
break;
}
}
mutex_unlock(&cm_list_mtx);
cm_rtc_set = cm_setup_timer();
out:
if (rtc_wkalarm_save.enabled) {
unsigned long now;
struct rtc_time tmp;
rtc_read_time(rtc_dev, &tmp);
rtc_tm_to_time(&tmp, &now);
if (rtc_wkalarm_save_time &&
now + CM_RTC_SMALL >= rtc_wkalarm_save_time)
return false;
}
return ret;
}
int setup_charger_manager(struct charger_global_desc *gd)
{
if (!gd)
return -EINVAL;
if (rtc_dev)
rtc_class_close(rtc_dev);
rtc_dev = NULL;
g_desc = NULL;
if (!gd->rtc_only_wakeup) {
pr_err("The callback rtc_only_wakeup is not given.\n");
return -EINVAL;
}
if (gd->rtc_name) {
rtc_dev = rtc_class_open(gd->rtc_name);
if (IS_ERR_OR_NULL(rtc_dev)) {
rtc_dev = NULL;
}
} else {
pr_warn("No wakeup timer is given for charger manager."
"In-suspend monitoring won't work.\n");
}
g_desc = gd;
return 0;
}
static void charger_extcon_work(struct work_struct *work)
{
struct charger_cable *cable =
container_of(work, struct charger_cable, wq);
int ret;
if (cable->attached && cable->min_uA != 0 && cable->max_uA != 0) {
ret = regulator_set_current_limit(cable->charger->consumer,
cable->min_uA, cable->max_uA);
if (ret < 0) {
pr_err("Cannot set current limit of %s (%s)\n",
cable->charger->regulator_name, cable->name);
return;
}
pr_info("Set current limit of %s : %duA ~ %duA\n",
cable->charger->regulator_name,
cable->min_uA, cable->max_uA);
}
try_charger_enable(cable->cm, cable->attached);
}
static int charger_extcon_notifier(struct notifier_block *self,
unsigned long event, void *ptr)
{
struct charger_cable *cable =
container_of(self, struct charger_cable, nb);
cable->attached = event;
if (cable->attached && is_polling_required(cable->cm)) {
if (work_pending(&setup_polling))
cancel_work_sync(&setup_polling);
schedule_work(&setup_polling);
}
schedule_work(&cable->wq);
return NOTIFY_DONE;
}
static int charger_extcon_init(struct charger_manager *cm,
struct charger_cable *cable)
{
int ret = 0;
INIT_WORK(&cable->wq, charger_extcon_work);
cable->nb.notifier_call = charger_extcon_notifier;
ret = extcon_register_interest(&cable->extcon_dev,
cable->extcon_name, cable->name, &cable->nb);
if (ret < 0) {
pr_info("Cannot register extcon_dev for %s(cable: %s).\n",
cable->extcon_name,
cable->name);
ret = -EINVAL;
}
return ret;
}
static ssize_t charger_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct charger_regulator *charger
= container_of(attr, struct charger_regulator, attr_name);
return sprintf(buf, "%s\n", charger->regulator_name);
}
static ssize_t charger_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct charger_regulator *charger
= container_of(attr, struct charger_regulator, attr_state);
int state = 0;
if (!charger->externally_control)
state = regulator_is_enabled(charger->consumer);
return sprintf(buf, "%s\n", state ? "enabled" : "disabled");
}
static ssize_t charger_externally_control_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct charger_regulator *charger = container_of(attr,
struct charger_regulator, attr_externally_control);
return sprintf(buf, "%d\n", charger->externally_control);
}
static ssize_t charger_externally_control_store(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct charger_regulator *charger
= container_of(attr, struct charger_regulator,
attr_externally_control);
struct charger_manager *cm = charger->cm;
struct charger_desc *desc = cm->desc;
int i;
int ret;
int externally_control;
int chargers_externally_control = 1;
ret = sscanf(buf, "%d", &externally_control);
if (ret == 0) {
ret = -EINVAL;
return ret;
}
if (!externally_control) {
charger->externally_control = 0;
return count;
}
for (i = 0; i < desc->num_charger_regulators; i++) {
if (&desc->charger_regulators[i] != charger &&
!desc->charger_regulators[i].externally_control) {
chargers_externally_control = 0;
break;
}
}
if (!chargers_externally_control) {
if (cm->charger_enabled) {
try_charger_enable(charger->cm, false);
charger->externally_control = externally_control;
try_charger_enable(charger->cm, true);
} else {
charger->externally_control = externally_control;
}
} else {
dev_warn(cm->dev,
"'%s' regulator should be controlled "
"in charger-manager because charger-manager "
"must need at least one charger for charging\n",
charger->regulator_name);
}
return count;
}
static int charger_manager_probe(struct platform_device *pdev)
{
struct charger_desc *desc = dev_get_platdata(&pdev->dev);
struct charger_manager *cm;
int ret = 0, i = 0;
int j = 0;
int chargers_externally_control = 1;
union power_supply_propval val;
if (g_desc && !rtc_dev && g_desc->rtc_name) {
rtc_dev = rtc_class_open(g_desc->rtc_name);
if (IS_ERR_OR_NULL(rtc_dev)) {
rtc_dev = NULL;
dev_err(&pdev->dev, "Cannot get RTC %s.\n",
g_desc->rtc_name);
ret = -ENODEV;
goto err_alloc;
}
}
if (!desc) {
dev_err(&pdev->dev, "No platform data (desc) found.\n");
ret = -ENODEV;
goto err_alloc;
}
cm = kzalloc(sizeof(struct charger_manager), GFP_KERNEL);
if (!cm) {
dev_err(&pdev->dev, "Cannot allocate memory.\n");
ret = -ENOMEM;
goto err_alloc;
}
cm->dev = &pdev->dev;
cm->desc = kzalloc(sizeof(struct charger_desc), GFP_KERNEL);
if (!cm->desc) {
dev_err(&pdev->dev, "Cannot allocate memory.\n");
ret = -ENOMEM;
goto err_alloc_desc;
}
memcpy(cm->desc, desc, sizeof(struct charger_desc));
cm->last_temp_mC = INT_MIN;
if (desc->fullbatt_uV == 0) {
dev_info(&pdev->dev, "Ignoring full-battery voltage threshold"
" as it is not supplied.");
}
if (!desc->fullbatt_vchkdrop_ms || !desc->fullbatt_vchkdrop_uV) {
dev_info(&pdev->dev, "Disabling full-battery voltage drop "
"checking mechanism as it is not supplied.");
desc->fullbatt_vchkdrop_ms = 0;
desc->fullbatt_vchkdrop_uV = 0;
}
if (desc->fullbatt_soc == 0) {
dev_info(&pdev->dev, "Ignoring full-battery soc(state of"
" charge) threshold as it is not"
" supplied.");
}
if (desc->fullbatt_full_capacity == 0) {
dev_info(&pdev->dev, "Ignoring full-battery full capacity"
" threshold as it is not supplied.");
}
if (!desc->charger_regulators || desc->num_charger_regulators < 1) {
ret = -EINVAL;
dev_err(&pdev->dev, "charger_regulators undefined.\n");
goto err_no_charger;
}
if (!desc->psy_charger_stat || !desc->psy_charger_stat[0]) {
dev_err(&pdev->dev, "No power supply defined.\n");
ret = -EINVAL;
goto err_no_charger_stat;
}
while (desc->psy_charger_stat[i])
i++;
cm->charger_stat = kzalloc(sizeof(struct power_supply *) * (i + 1),
GFP_KERNEL);
if (!cm->charger_stat) {
ret = -ENOMEM;
goto err_no_charger_stat;
}
for (i = 0; desc->psy_charger_stat[i]; i++) {
cm->charger_stat[i] = power_supply_get_by_name(
desc->psy_charger_stat[i]);
if (!cm->charger_stat[i]) {
dev_err(&pdev->dev, "Cannot find power supply "
"\"%s\"\n",
desc->psy_charger_stat[i]);
ret = -ENODEV;
goto err_chg_stat;
}
}
cm->fuel_gauge = power_supply_get_by_name(desc->psy_fuel_gauge);
if (!cm->fuel_gauge) {
dev_err(&pdev->dev, "Cannot find power supply \"%s\"\n",
desc->psy_fuel_gauge);
ret = -ENODEV;
goto err_chg_stat;
}
if (desc->polling_interval_ms == 0 ||
msecs_to_jiffies(desc->polling_interval_ms) <= CM_JIFFIES_SMALL) {
dev_err(&pdev->dev, "polling_interval_ms is too small\n");
ret = -EINVAL;
goto err_chg_stat;
}
if (!desc->temperature_out_of_range) {
dev_err(&pdev->dev, "there is no temperature_out_of_range\n");
ret = -EINVAL;
goto err_chg_stat;
}
if (!desc->charging_max_duration_ms ||
!desc->discharging_max_duration_ms) {
dev_info(&pdev->dev, "Cannot limit charging duration "
"checking mechanism to prevent overcharge/overheat "
"and control discharging duration");
desc->charging_max_duration_ms = 0;
desc->discharging_max_duration_ms = 0;
}
platform_set_drvdata(pdev, cm);
memcpy(&cm->charger_psy, &psy_default, sizeof(psy_default));
if (!desc->psy_name) {
strncpy(cm->psy_name_buf, psy_default.name, PSY_NAME_MAX);
} else {
strncpy(cm->psy_name_buf, desc->psy_name, PSY_NAME_MAX);
}
cm->charger_psy.name = cm->psy_name_buf;
cm->charger_psy.properties = kzalloc(sizeof(enum power_supply_property)
* (ARRAY_SIZE(default_charger_props) +
NUM_CHARGER_PSY_OPTIONAL),
GFP_KERNEL);
if (!cm->charger_psy.properties) {
dev_err(&pdev->dev, "Cannot allocate for psy properties.\n");
ret = -ENOMEM;
goto err_chg_stat;
}
memcpy(cm->charger_psy.properties, default_charger_props,
sizeof(enum power_supply_property) *
ARRAY_SIZE(default_charger_props));
cm->charger_psy.num_properties = psy_default.num_properties;
if (!cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_CHARGE_NOW, &val)) {
cm->charger_psy.properties[cm->charger_psy.num_properties] =
POWER_SUPPLY_PROP_CHARGE_NOW;
cm->charger_psy.num_properties++;
}
if (!cm->fuel_gauge->get_property(cm->fuel_gauge,
POWER_SUPPLY_PROP_CURRENT_NOW,
&val)) {
cm->charger_psy.properties[cm->charger_psy.num_properties] =
POWER_SUPPLY_PROP_CURRENT_NOW;
cm->charger_psy.num_properties++;
}
if (desc->measure_battery_temp) {
cm->charger_psy.properties[cm->charger_psy.num_properties] =
POWER_SUPPLY_PROP_TEMP;
cm->charger_psy.num_properties++;
} else {
cm->charger_psy.properties[cm->charger_psy.num_properties] =
POWER_SUPPLY_PROP_TEMP_AMBIENT;
cm->charger_psy.num_properties++;
}
INIT_DELAYED_WORK(&cm->fullbatt_vchk_work, fullbatt_vchk);
ret = power_supply_register(NULL, &cm->charger_psy);
if (ret) {
dev_err(&pdev->dev, "Cannot register charger-manager with"
" name \"%s\".\n", cm->charger_psy.name);
goto err_register;
}
for (i = 0 ; i < desc->num_charger_regulators ; i++) {
struct charger_regulator *charger
= &desc->charger_regulators[i];
char buf[11];
char *str;
charger->consumer = regulator_get(&pdev->dev,
charger->regulator_name);
if (charger->consumer == NULL) {
dev_err(&pdev->dev, "Cannot find charger(%s)n",
charger->regulator_name);
ret = -EINVAL;
goto err_chg_get;
}
charger->cm = cm;
for (j = 0 ; j < charger->num_cables ; j++) {
struct charger_cable *cable = &charger->cables[j];
ret = charger_extcon_init(cm, cable);
if (ret < 0) {
dev_err(&pdev->dev, "Cannot find charger(%s)n",
charger->regulator_name);
goto err_extcon;
}
cable->charger = charger;
cable->cm = cm;
}
snprintf(buf, 10, "charger.%d", i);
str = kzalloc(sizeof(char) * (strlen(buf) + 1), GFP_KERNEL);
if (!str) {
for (i--; i >= 0; i--) {
charger = &desc->charger_regulators[i];
kfree(charger->attr_g.name);
}
ret = -ENOMEM;
goto err_extcon;
}
strcpy(str, buf);
charger->attrs[0] = &charger->attr_name.attr;
charger->attrs[1] = &charger->attr_state.attr;
charger->attrs[2] = &charger->attr_externally_control.attr;
charger->attrs[3] = NULL;
charger->attr_g.name = str;
charger->attr_g.attrs = charger->attrs;
sysfs_attr_init(&charger->attr_name.attr);
charger->attr_name.attr.name = "name";
charger->attr_name.attr.mode = 0444;
charger->attr_name.show = charger_name_show;
sysfs_attr_init(&charger->attr_state.attr);
charger->attr_state.attr.name = "state";
charger->attr_state.attr.mode = 0444;
charger->attr_state.show = charger_state_show;
sysfs_attr_init(&charger->attr_externally_control.attr);
charger->attr_externally_control.attr.name
= "externally_control";
charger->attr_externally_control.attr.mode = 0644;
charger->attr_externally_control.show
= charger_externally_control_show;
charger->attr_externally_control.store
= charger_externally_control_store;
if (!desc->charger_regulators[i].externally_control ||
!chargers_externally_control) {
chargers_externally_control = 0;
}
dev_info(&pdev->dev, "'%s' regulator's externally_control"
"is %d\n", charger->regulator_name,
charger->externally_control);
ret = sysfs_create_group(&cm->charger_psy.dev->kobj,
&charger->attr_g);
if (ret < 0) {
dev_info(&pdev->dev, "Cannot create sysfs entry"
"of %s regulator\n",
charger->regulator_name);
}
}
if (chargers_externally_control) {
dev_err(&pdev->dev, "Cannot register regulator because "
"charger-manager must need at least "
"one charger for charging battery\n");
ret = -EINVAL;
goto err_chg_enable;
}
ret = try_charger_enable(cm, true);
if (ret) {
dev_err(&pdev->dev, "Cannot enable charger regulators\n");
goto err_chg_enable;
}
mutex_lock(&cm_list_mtx);
list_add(&cm->entry, &cm_list);
mutex_unlock(&cm_list_mtx);
device_init_wakeup(&pdev->dev, true);
device_set_wakeup_capable(&pdev->dev, false);
schedule_work(&setup_polling);
return 0;
err_chg_enable:
for (i = 0; i < desc->num_charger_regulators; i++) {
struct charger_regulator *charger;
charger = &desc->charger_regulators[i];
sysfs_remove_group(&cm->charger_psy.dev->kobj,
&charger->attr_g);
kfree(charger->attr_g.name);
}
err_extcon:
for (i = 0 ; i < desc->num_charger_regulators ; i++) {
struct charger_regulator *charger
= &desc->charger_regulators[i];
for (j = 0 ; j < charger->num_cables ; j++) {
struct charger_cable *cable = &charger->cables[j];
extcon_unregister_interest(&cable->extcon_dev);
}
}
err_chg_get:
for (i = 0 ; i < desc->num_charger_regulators ; i++)
regulator_put(desc->charger_regulators[i].consumer);
power_supply_unregister(&cm->charger_psy);
err_register:
kfree(cm->charger_psy.properties);
err_chg_stat:
kfree(cm->charger_stat);
err_no_charger_stat:
err_no_charger:
kfree(cm->desc);
err_alloc_desc:
kfree(cm);
err_alloc:
return ret;
}
static int charger_manager_remove(struct platform_device *pdev)
{
struct charger_manager *cm = platform_get_drvdata(pdev);
struct charger_desc *desc = cm->desc;
int i = 0;
int j = 0;
mutex_lock(&cm_list_mtx);
list_del(&cm->entry);
mutex_unlock(&cm_list_mtx);
if (work_pending(&setup_polling))
cancel_work_sync(&setup_polling);
if (delayed_work_pending(&cm_monitor_work))
cancel_delayed_work_sync(&cm_monitor_work);
for (i = 0 ; i < desc->num_charger_regulators ; i++) {
struct charger_regulator *charger
= &desc->charger_regulators[i];
for (j = 0 ; j < charger->num_cables ; j++) {
struct charger_cable *cable = &charger->cables[j];
extcon_unregister_interest(&cable->extcon_dev);
}
}
for (i = 0 ; i < desc->num_charger_regulators ; i++)
regulator_put(desc->charger_regulators[i].consumer);
power_supply_unregister(&cm->charger_psy);
try_charger_enable(cm, false);
kfree(cm->charger_psy.properties);
kfree(cm->charger_stat);
kfree(cm->desc);
kfree(cm);
return 0;
}
static int cm_suspend_noirq(struct device *dev)
{
int ret = 0;
if (device_may_wakeup(dev)) {
device_set_wakeup_capable(dev, false);
ret = -EAGAIN;
}
return ret;
}
static int cm_suspend_prepare(struct device *dev)
{
struct charger_manager *cm = dev_get_drvdata(dev);
if (!cm_suspended) {
if (rtc_dev) {
struct rtc_time tmp;
unsigned long now;
rtc_read_alarm(rtc_dev, &rtc_wkalarm_save);
rtc_read_time(rtc_dev, &tmp);
if (rtc_wkalarm_save.enabled) {
rtc_tm_to_time(&rtc_wkalarm_save.time,
&rtc_wkalarm_save_time);
rtc_tm_to_time(&tmp, &now);
if (now > rtc_wkalarm_save_time)
rtc_wkalarm_save_time = 0;
} else {
rtc_wkalarm_save_time = 0;
}
}
cm_suspended = true;
}
if (delayed_work_pending(&cm->fullbatt_vchk_work))
cancel_delayed_work(&cm->fullbatt_vchk_work);
cm->status_save_ext_pwr_inserted = is_ext_pwr_online(cm);
cm->status_save_batt = is_batt_present(cm);
if (!cm_rtc_set) {
cm_suspend_duration_ms = 0;
cm_rtc_set = cm_setup_timer();
}
return 0;
}
static void cm_suspend_complete(struct device *dev)
{
struct charger_manager *cm = dev_get_drvdata(dev);
if (cm_suspended) {
if (rtc_dev) {
struct rtc_wkalrm tmp;
rtc_read_alarm(rtc_dev, &tmp);
rtc_wkalarm_save.pending = tmp.pending;
rtc_set_alarm(rtc_dev, &rtc_wkalarm_save);
}
cm_suspended = false;
cm_rtc_set = false;
}
if (cm->fullbatt_vchk_jiffies_at) {
unsigned long delay = 0;
unsigned long now = jiffies + CM_JIFFIES_SMALL;
if (time_after_eq(now, cm->fullbatt_vchk_jiffies_at)) {
delay = (unsigned long)((long)now
- (long)(cm->fullbatt_vchk_jiffies_at));
delay = jiffies_to_msecs(delay);
} else {
delay = 0;
}
if (g_desc && g_desc->assume_timer_stops_in_suspend) {
if (delay > cm_suspend_duration_ms)
delay -= cm_suspend_duration_ms;
else
delay = 0;
}
queue_delayed_work(cm_wq, &cm->fullbatt_vchk_work,
msecs_to_jiffies(delay));
}
device_set_wakeup_capable(cm->dev, false);
uevent_notify(cm, NULL);
}
static int __init charger_manager_init(void)
{
cm_wq = create_freezable_workqueue("charger_manager");
INIT_DELAYED_WORK(&cm_monitor_work, cm_monitor_poller);
return platform_driver_register(&charger_manager_driver);
}
static void __exit charger_manager_cleanup(void)
{
destroy_workqueue(cm_wq);
cm_wq = NULL;
platform_driver_unregister(&charger_manager_driver);
}
static bool find_power_supply(struct charger_manager *cm,
struct power_supply *psy)
{
int i;
bool found = false;
for (i = 0; cm->charger_stat[i]; i++) {
if (psy == cm->charger_stat[i]) {
found = true;
break;
}
}
return found;
}
void cm_notify_event(struct power_supply *psy, enum cm_event_types type,
char *msg)
{
struct charger_manager *cm;
bool found_power_supply = false;
if (psy == NULL)
return;
mutex_lock(&cm_list_mtx);
list_for_each_entry(cm, &cm_list, entry) {
found_power_supply = find_power_supply(cm, psy);
if (found_power_supply)
break;
}
mutex_unlock(&cm_list_mtx);
if (!found_power_supply)
return;
switch (type) {
case CM_EVENT_BATT_FULL:
fullbatt_handler(cm);
break;
case CM_EVENT_BATT_OUT:
battout_handler(cm);
break;
case CM_EVENT_BATT_IN:
case CM_EVENT_EXT_PWR_IN_OUT ... CM_EVENT_CHG_START_STOP:
misc_event_handler(cm, type);
break;
case CM_EVENT_UNKNOWN:
case CM_EVENT_OTHERS:
uevent_notify(cm, msg ? msg : default_event_names[type]);
break;
default:
dev_err(cm->dev, "%s type not specified.\n", __func__);
break;
}
}
