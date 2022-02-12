static inline int battery_scale(int log)
{
int scale = 1;
while (log--)
scale *= 10;
return scale;
}
static inline int acpi_battery_vscale(struct acpi_battery *battery)
{
return battery_scale((battery->spec & 0x0f00) >> 8);
}
static inline int acpi_battery_ipscale(struct acpi_battery *battery)
{
return battery_scale((battery->spec & 0xf000) >> 12);
}
static inline int acpi_battery_mode(struct acpi_battery *battery)
{
return (battery->mode & 0x8000);
}
static inline int acpi_battery_scale(struct acpi_battery *battery)
{
return (acpi_battery_mode(battery) ? 10 : 1) *
acpi_battery_ipscale(battery);
}
static int sbs_get_ac_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct acpi_sbs *sbs = to_acpi_sbs(psy);
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = sbs->charger_present;
break;
default:
return -EINVAL;
}
return 0;
}
static int acpi_battery_technology(struct acpi_battery *battery)
{
if (!strcasecmp("NiCd", battery->device_chemistry))
return POWER_SUPPLY_TECHNOLOGY_NiCd;
if (!strcasecmp("NiMH", battery->device_chemistry))
return POWER_SUPPLY_TECHNOLOGY_NiMH;
if (!strcasecmp("LION", battery->device_chemistry))
return POWER_SUPPLY_TECHNOLOGY_LION;
if (!strcasecmp("LiP", battery->device_chemistry))
return POWER_SUPPLY_TECHNOLOGY_LIPO;
return POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
}
static int acpi_sbs_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct acpi_battery *battery = to_acpi_battery(psy);
if ((!battery->present) && psp != POWER_SUPPLY_PROP_PRESENT)
return -ENODEV;
acpi_battery_get_state(battery);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (battery->rate_now < 0)
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else if (battery->rate_now > 0)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_FULL;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = battery->present;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = acpi_battery_technology(battery);
break;
case POWER_SUPPLY_PROP_CYCLE_COUNT:
val->intval = battery->cycle_count;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = battery->design_voltage *
acpi_battery_vscale(battery) * 1000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = battery->voltage_now *
acpi_battery_vscale(battery) * 1000;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
case POWER_SUPPLY_PROP_POWER_NOW:
val->intval = abs(battery->rate_now) *
acpi_battery_ipscale(battery) * 1000;
val->intval *= (acpi_battery_mode(battery)) ?
(battery->voltage_now *
acpi_battery_vscale(battery) / 1000) : 1;
break;
case POWER_SUPPLY_PROP_CURRENT_AVG:
case POWER_SUPPLY_PROP_POWER_AVG:
val->intval = abs(battery->rate_avg) *
acpi_battery_ipscale(battery) * 1000;
val->intval *= (acpi_battery_mode(battery)) ?
(battery->voltage_now *
acpi_battery_vscale(battery) / 1000) : 1;
break;
case POWER_SUPPLY_PROP_CAPACITY:
val->intval = battery->state_of_charge;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
case POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN:
val->intval = battery->design_capacity *
acpi_battery_scale(battery) * 1000;
break;
case POWER_SUPPLY_PROP_CHARGE_FULL:
case POWER_SUPPLY_PROP_ENERGY_FULL:
val->intval = battery->full_charge_capacity *
acpi_battery_scale(battery) * 1000;
break;
case POWER_SUPPLY_PROP_CHARGE_NOW:
case POWER_SUPPLY_PROP_ENERGY_NOW:
val->intval = battery->capacity_now *
acpi_battery_scale(battery) * 1000;
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval = battery->temp_now - 2730;
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
val->strval = battery->device_name;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
val->strval = battery->manufacturer_name;
break;
default:
return -EINVAL;
}
return 0;
}
static int acpi_manager_get_info(struct acpi_sbs *sbs)
{
int result = 0;
u16 battery_system_info;
result = acpi_smbus_read(sbs->hc, SMBUS_READ_WORD, ACPI_SBS_MANAGER,
0x04, (u8 *)&battery_system_info);
if (!result)
sbs->batteries_supported = battery_system_info & 0x000f;
return result;
}
static int acpi_battery_get_info(struct acpi_battery *battery)
{
int i, result = 0;
for (i = 0; i < ARRAY_SIZE(info_readers); ++i) {
result = acpi_smbus_read(battery->sbs->hc,
info_readers[i].mode,
ACPI_SBS_BATTERY,
info_readers[i].command,
(u8 *) battery +
info_readers[i].offset);
if (result)
break;
}
return result;
}
static int acpi_battery_get_state(struct acpi_battery *battery)
{
int i, result = 0;
if (battery->update_time &&
time_before(jiffies, battery->update_time +
msecs_to_jiffies(cache_time)))
return 0;
for (i = 0; i < ARRAY_SIZE(state_readers); ++i) {
result = acpi_smbus_read(battery->sbs->hc,
state_readers[i].mode,
ACPI_SBS_BATTERY,
state_readers[i].command,
(u8 *)battery +
state_readers[i].offset);
if (result)
goto end;
}
end:
battery->update_time = jiffies;
return result;
}
static int acpi_battery_get_alarm(struct acpi_battery *battery)
{
return acpi_smbus_read(battery->sbs->hc, SMBUS_READ_WORD,
ACPI_SBS_BATTERY, 0x01,
(u8 *)&battery->alarm_capacity);
}
static int acpi_battery_set_alarm(struct acpi_battery *battery)
{
struct acpi_sbs *sbs = battery->sbs;
u16 value, sel = 1 << (battery->id + 12);
int ret;
if (sbs->manager_present) {
ret = acpi_smbus_read(sbs->hc, SMBUS_READ_WORD, ACPI_SBS_MANAGER,
0x01, (u8 *)&value);
if (ret)
goto end;
if ((value & 0xf000) != sel) {
value &= 0x0fff;
value |= sel;
ret = acpi_smbus_write(sbs->hc, SMBUS_WRITE_WORD,
ACPI_SBS_MANAGER,
0x01, (u8 *)&value, 2);
if (ret)
goto end;
}
}
ret = acpi_smbus_write(sbs->hc, SMBUS_WRITE_WORD, ACPI_SBS_BATTERY,
0x01, (u8 *)&battery->alarm_capacity, 2);
end:
return ret;
}
static int acpi_ac_get_present(struct acpi_sbs *sbs)
{
int result;
u16 status;
result = acpi_smbus_read(sbs->hc, SMBUS_READ_WORD, ACPI_SBS_CHARGER,
0x13, (u8 *) & status);
if (!result)
sbs->charger_present = (status >> 15) & 0x1;
return result;
}
static ssize_t acpi_battery_alarm_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct acpi_battery *battery = to_acpi_battery(dev_get_drvdata(dev));
acpi_battery_get_alarm(battery);
return sprintf(buf, "%d\n", battery->alarm_capacity *
acpi_battery_scale(battery) * 1000);
}
static ssize_t acpi_battery_alarm_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long x;
struct acpi_battery *battery = to_acpi_battery(dev_get_drvdata(dev));
if (sscanf(buf, "%ld\n", &x) == 1)
battery->alarm_capacity = x /
(1000 * acpi_battery_scale(battery));
if (battery->present)
acpi_battery_set_alarm(battery);
return count;
}
static int
acpi_sbs_add_fs(struct proc_dir_entry **dir,
struct proc_dir_entry *parent_dir,
char *dir_name,
const struct file_operations *info_fops,
const struct file_operations *state_fops,
const struct file_operations *alarm_fops, void *data)
{
printk(KERN_WARNING PREFIX "Deprecated procfs I/F for SBS is loaded,"
" please retry with CONFIG_ACPI_PROCFS_POWER cleared\n");
if (!*dir) {
*dir = proc_mkdir(dir_name, parent_dir);
if (!*dir) {
return -ENODEV;
}
}
if (info_fops)
proc_create_data(ACPI_SBS_FILE_INFO, S_IRUGO, *dir,
info_fops, data);
if (state_fops)
proc_create_data(ACPI_SBS_FILE_STATE, S_IRUGO, *dir,
state_fops, data);
if (alarm_fops)
proc_create_data(ACPI_SBS_FILE_ALARM, S_IRUGO, *dir,
alarm_fops, data);
return 0;
}
static inline char *acpi_battery_units(struct acpi_battery *battery)
{
return acpi_battery_mode(battery) ? " mW" : " mA";
}
static int acpi_battery_read_info(struct seq_file *seq, void *offset)
{
struct acpi_battery *battery = seq->private;
struct acpi_sbs *sbs = battery->sbs;
int result = 0;
mutex_lock(&sbs->lock);
seq_printf(seq, "present: %s\n",
(battery->present) ? "yes" : "no");
if (!battery->present)
goto end;
seq_printf(seq, "design capacity: %i%sh\n",
battery->design_capacity * acpi_battery_scale(battery),
acpi_battery_units(battery));
seq_printf(seq, "last full capacity: %i%sh\n",
battery->full_charge_capacity * acpi_battery_scale(battery),
acpi_battery_units(battery));
seq_printf(seq, "battery technology: rechargeable\n");
seq_printf(seq, "design voltage: %i mV\n",
battery->design_voltage * acpi_battery_vscale(battery));
seq_printf(seq, "design capacity warning: unknown\n");
seq_printf(seq, "design capacity low: unknown\n");
seq_printf(seq, "cycle count: %i\n", battery->cycle_count);
seq_printf(seq, "capacity granularity 1: unknown\n");
seq_printf(seq, "capacity granularity 2: unknown\n");
seq_printf(seq, "model number: %s\n", battery->device_name);
seq_printf(seq, "serial number: %i\n",
battery->serial_number);
seq_printf(seq, "battery type: %s\n",
battery->device_chemistry);
seq_printf(seq, "OEM info: %s\n",
battery->manufacturer_name);
end:
mutex_unlock(&sbs->lock);
return result;
}
static int acpi_battery_info_open_fs(struct inode *inode, struct file *file)
{
return single_open(file, acpi_battery_read_info, PDE_DATA(inode));
}
static int acpi_battery_read_state(struct seq_file *seq, void *offset)
{
struct acpi_battery *battery = seq->private;
struct acpi_sbs *sbs = battery->sbs;
int rate;
mutex_lock(&sbs->lock);
seq_printf(seq, "present: %s\n",
(battery->present) ? "yes" : "no");
if (!battery->present)
goto end;
acpi_battery_get_state(battery);
seq_printf(seq, "capacity state: %s\n",
(battery->state & 0x0010) ? "critical" : "ok");
seq_printf(seq, "charging state: %s\n",
(battery->rate_now < 0) ? "discharging" :
((battery->rate_now > 0) ? "charging" : "charged"));
rate = abs(battery->rate_now) * acpi_battery_ipscale(battery);
rate *= (acpi_battery_mode(battery))?(battery->voltage_now *
acpi_battery_vscale(battery)/1000):1;
seq_printf(seq, "present rate: %d%s\n", rate,
acpi_battery_units(battery));
seq_printf(seq, "remaining capacity: %i%sh\n",
battery->capacity_now * acpi_battery_scale(battery),
acpi_battery_units(battery));
seq_printf(seq, "present voltage: %i mV\n",
battery->voltage_now * acpi_battery_vscale(battery));
end:
mutex_unlock(&sbs->lock);
return 0;
}
static int acpi_battery_state_open_fs(struct inode *inode, struct file *file)
{
return single_open(file, acpi_battery_read_state, PDE_DATA(inode));
}
static int acpi_battery_read_alarm(struct seq_file *seq, void *offset)
{
struct acpi_battery *battery = seq->private;
struct acpi_sbs *sbs = battery->sbs;
int result = 0;
mutex_lock(&sbs->lock);
if (!battery->present) {
seq_printf(seq, "present: no\n");
goto end;
}
acpi_battery_get_alarm(battery);
seq_printf(seq, "alarm: ");
if (battery->alarm_capacity)
seq_printf(seq, "%i%sh\n",
battery->alarm_capacity *
acpi_battery_scale(battery),
acpi_battery_units(battery));
else
seq_printf(seq, "disabled\n");
end:
mutex_unlock(&sbs->lock);
return result;
}
static ssize_t
acpi_battery_write_alarm(struct file *file, const char __user * buffer,
size_t count, loff_t * ppos)
{
struct seq_file *seq = file->private_data;
struct acpi_battery *battery = seq->private;
struct acpi_sbs *sbs = battery->sbs;
char alarm_string[12] = { '\0' };
int result = 0;
mutex_lock(&sbs->lock);
if (!battery->present) {
result = -ENODEV;
goto end;
}
if (count > sizeof(alarm_string) - 1) {
result = -EINVAL;
goto end;
}
if (copy_from_user(alarm_string, buffer, count)) {
result = -EFAULT;
goto end;
}
alarm_string[count] = 0;
battery->alarm_capacity = simple_strtoul(alarm_string, NULL, 0) /
acpi_battery_scale(battery);
acpi_battery_set_alarm(battery);
end:
mutex_unlock(&sbs->lock);
if (result)
return result;
return count;
}
static int acpi_battery_alarm_open_fs(struct inode *inode, struct file *file)
{
return single_open(file, acpi_battery_read_alarm, PDE_DATA(inode));
}
static int acpi_ac_read_state(struct seq_file *seq, void *offset)
{
struct acpi_sbs *sbs = seq->private;
mutex_lock(&sbs->lock);
seq_printf(seq, "state: %s\n",
sbs->charger_present ? "on-line" : "off-line");
mutex_unlock(&sbs->lock);
return 0;
}
static int acpi_ac_state_open_fs(struct inode *inode, struct file *file)
{
return single_open(file, acpi_ac_read_state, PDE_DATA(inode));
}
static int acpi_battery_read(struct acpi_battery *battery)
{
int result = 0, saved_present = battery->present;
u16 state;
if (battery->sbs->manager_present) {
result = acpi_smbus_read(battery->sbs->hc, SMBUS_READ_WORD,
ACPI_SBS_MANAGER, 0x01, (u8 *)&state);
if (!result)
battery->present = state & (1 << battery->id);
state &= 0x0fff;
state |= 1 << (battery->id + 12);
acpi_smbus_write(battery->sbs->hc, SMBUS_WRITE_WORD,
ACPI_SBS_MANAGER, 0x01, (u8 *)&state, 2);
} else if (battery->id == 0)
battery->present = 1;
if (result || !battery->present)
return result;
if (saved_present != battery->present) {
battery->update_time = 0;
result = acpi_battery_get_info(battery);
if (result)
return result;
}
result = acpi_battery_get_state(battery);
return result;
}
static int acpi_battery_add(struct acpi_sbs *sbs, int id)
{
struct acpi_battery *battery = &sbs->battery[id];
int result;
battery->id = id;
battery->sbs = sbs;
result = acpi_battery_read(battery);
if (result)
return result;
sprintf(battery->name, ACPI_BATTERY_DIR_NAME, id);
#ifdef CONFIG_ACPI_PROCFS_POWER
acpi_sbs_add_fs(&battery->proc_entry, acpi_battery_dir,
battery->name, &acpi_battery_info_fops,
&acpi_battery_state_fops, &acpi_battery_alarm_fops,
battery);
#endif
battery->bat.name = battery->name;
battery->bat.type = POWER_SUPPLY_TYPE_BATTERY;
if (!acpi_battery_mode(battery)) {
battery->bat.properties = sbs_charge_battery_props;
battery->bat.num_properties =
ARRAY_SIZE(sbs_charge_battery_props);
} else {
battery->bat.properties = sbs_energy_battery_props;
battery->bat.num_properties =
ARRAY_SIZE(sbs_energy_battery_props);
}
battery->bat.get_property = acpi_sbs_battery_get_property;
result = power_supply_register(&sbs->device->dev, &battery->bat);
if (result)
goto end;
result = device_create_file(battery->bat.dev, &alarm_attr);
if (result)
goto end;
battery->have_sysfs_alarm = 1;
end:
printk(KERN_INFO PREFIX "%s [%s]: Battery Slot [%s] (battery %s)\n",
ACPI_SBS_DEVICE_NAME, acpi_device_bid(sbs->device),
battery->name, battery->present ? "present" : "absent");
return result;
}
static void acpi_battery_remove(struct acpi_sbs *sbs, int id)
{
struct acpi_battery *battery = &sbs->battery[id];
if (battery->bat.dev) {
if (battery->have_sysfs_alarm)
device_remove_file(battery->bat.dev, &alarm_attr);
power_supply_unregister(&battery->bat);
}
#ifdef CONFIG_ACPI_PROCFS_POWER
proc_remove(battery->proc_entry);
battery->proc_entry = NULL;
#endif
}
static int acpi_charger_add(struct acpi_sbs *sbs)
{
int result;
result = acpi_ac_get_present(sbs);
if (result)
goto end;
#ifdef CONFIG_ACPI_PROCFS_POWER
result = acpi_sbs_add_fs(&sbs->charger_entry, acpi_ac_dir,
ACPI_AC_DIR_NAME, NULL,
&acpi_ac_state_fops, NULL, sbs);
if (result)
goto end;
#endif
sbs->charger.name = "sbs-charger";
sbs->charger.type = POWER_SUPPLY_TYPE_MAINS;
sbs->charger.properties = sbs_ac_props;
sbs->charger.num_properties = ARRAY_SIZE(sbs_ac_props);
sbs->charger.get_property = sbs_get_ac_property;
power_supply_register(&sbs->device->dev, &sbs->charger);
printk(KERN_INFO PREFIX "%s [%s]: AC Adapter [%s] (%s)\n",
ACPI_SBS_DEVICE_NAME, acpi_device_bid(sbs->device),
ACPI_AC_DIR_NAME, sbs->charger_present ? "on-line" : "off-line");
end:
return result;
}
static void acpi_charger_remove(struct acpi_sbs *sbs)
{
if (sbs->charger.dev)
power_supply_unregister(&sbs->charger);
#ifdef CONFIG_ACPI_PROCFS_POWER
proc_remove(sbs->charger_entry);
sbs->charger_entry = NULL;
#endif
}
static void acpi_sbs_callback(void *context)
{
int id;
struct acpi_sbs *sbs = context;
struct acpi_battery *bat;
u8 saved_charger_state = sbs->charger_present;
u8 saved_battery_state;
acpi_ac_get_present(sbs);
if (sbs->charger_present != saved_charger_state) {
#ifdef CONFIG_ACPI_PROC_EVENT
acpi_bus_generate_proc_event4(ACPI_AC_CLASS, ACPI_AC_DIR_NAME,
ACPI_SBS_NOTIFY_STATUS,
sbs->charger_present);
#endif
kobject_uevent(&sbs->charger.dev->kobj, KOBJ_CHANGE);
}
if (sbs->manager_present) {
for (id = 0; id < MAX_SBS_BAT; ++id) {
if (!(sbs->batteries_supported & (1 << id)))
continue;
bat = &sbs->battery[id];
saved_battery_state = bat->present;
acpi_battery_read(bat);
if (saved_battery_state == bat->present)
continue;
#ifdef CONFIG_ACPI_PROC_EVENT
acpi_bus_generate_proc_event4(ACPI_BATTERY_CLASS,
bat->name,
ACPI_SBS_NOTIFY_STATUS,
bat->present);
#endif
kobject_uevent(&bat->bat.dev->kobj, KOBJ_CHANGE);
}
}
}
static int acpi_sbs_add(struct acpi_device *device)
{
struct acpi_sbs *sbs;
int result = 0;
int id;
sbs = kzalloc(sizeof(struct acpi_sbs), GFP_KERNEL);
if (!sbs) {
result = -ENOMEM;
goto end;
}
mutex_init(&sbs->lock);
sbs->hc = acpi_driver_data(device->parent);
sbs->device = device;
strcpy(acpi_device_name(device), ACPI_SBS_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_SBS_CLASS);
device->driver_data = sbs;
result = acpi_charger_add(sbs);
if (result)
goto end;
result = acpi_manager_get_info(sbs);
if (!result) {
sbs->manager_present = 1;
for (id = 0; id < MAX_SBS_BAT; ++id)
if ((sbs->batteries_supported & (1 << id)))
acpi_battery_add(sbs, id);
} else
acpi_battery_add(sbs, 0);
acpi_smbus_register_callback(sbs->hc, acpi_sbs_callback, sbs);
end:
if (result)
acpi_sbs_remove(device);
return result;
}
static int acpi_sbs_remove(struct acpi_device *device)
{
struct acpi_sbs *sbs;
int id;
if (!device)
return -EINVAL;
sbs = acpi_driver_data(device);
if (!sbs)
return -EINVAL;
mutex_lock(&sbs->lock);
acpi_smbus_unregister_callback(sbs->hc);
for (id = 0; id < MAX_SBS_BAT; ++id)
acpi_battery_remove(sbs, id);
acpi_charger_remove(sbs);
mutex_unlock(&sbs->lock);
mutex_destroy(&sbs->lock);
kfree(sbs);
return 0;
}
static void acpi_sbs_rmdirs(void)
{
#ifdef CONFIG_ACPI_PROCFS_POWER
if (acpi_ac_dir) {
acpi_unlock_ac_dir(acpi_ac_dir);
acpi_ac_dir = NULL;
}
if (acpi_battery_dir) {
acpi_unlock_battery_dir(acpi_battery_dir);
acpi_battery_dir = NULL;
}
#endif
}
static int acpi_sbs_resume(struct device *dev)
{
struct acpi_sbs *sbs;
if (!dev)
return -EINVAL;
sbs = to_acpi_device(dev)->driver_data;
acpi_sbs_callback(sbs);
return 0;
}
static int __init acpi_sbs_init(void)
{
int result = 0;
if (acpi_disabled)
return -ENODEV;
#ifdef CONFIG_ACPI_PROCFS_POWER
acpi_ac_dir = acpi_lock_ac_dir();
if (!acpi_ac_dir)
return -ENODEV;
acpi_battery_dir = acpi_lock_battery_dir();
if (!acpi_battery_dir) {
acpi_sbs_rmdirs();
return -ENODEV;
}
#endif
result = acpi_bus_register_driver(&acpi_sbs_driver);
if (result < 0) {
acpi_sbs_rmdirs();
return -ENODEV;
}
return 0;
}
static void __exit acpi_sbs_exit(void)
{
acpi_bus_unregister_driver(&acpi_sbs_driver);
acpi_sbs_rmdirs();
return;
}
