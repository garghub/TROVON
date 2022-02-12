struct proc_dir_entry *acpi_lock_ac_dir(void)
{
mutex_lock(&cm_sbs_mutex);
if (!acpi_ac_dir)
acpi_ac_dir = proc_mkdir(ACPI_AC_CLASS, acpi_root_dir);
if (acpi_ac_dir) {
lock_ac_dir_cnt++;
} else {
printk(KERN_ERR PREFIX
"Cannot create %s\n", ACPI_AC_CLASS);
}
mutex_unlock(&cm_sbs_mutex);
return acpi_ac_dir;
}
void acpi_unlock_ac_dir(struct proc_dir_entry *acpi_ac_dir_param)
{
mutex_lock(&cm_sbs_mutex);
if (acpi_ac_dir_param)
lock_ac_dir_cnt--;
if (lock_ac_dir_cnt == 0 && acpi_ac_dir_param && acpi_ac_dir) {
remove_proc_entry(ACPI_AC_CLASS, acpi_root_dir);
acpi_ac_dir = NULL;
}
mutex_unlock(&cm_sbs_mutex);
}
struct proc_dir_entry *acpi_lock_battery_dir(void)
{
mutex_lock(&cm_sbs_mutex);
if (!acpi_battery_dir) {
acpi_battery_dir =
proc_mkdir(ACPI_BATTERY_CLASS, acpi_root_dir);
}
if (acpi_battery_dir) {
lock_battery_dir_cnt++;
} else {
printk(KERN_ERR PREFIX
"Cannot create %s\n", ACPI_BATTERY_CLASS);
}
mutex_unlock(&cm_sbs_mutex);
return acpi_battery_dir;
}
void acpi_unlock_battery_dir(struct proc_dir_entry *acpi_battery_dir_param)
{
mutex_lock(&cm_sbs_mutex);
if (acpi_battery_dir_param)
lock_battery_dir_cnt--;
if (lock_battery_dir_cnt == 0 && acpi_battery_dir_param
&& acpi_battery_dir) {
remove_proc_entry(ACPI_BATTERY_CLASS, acpi_root_dir);
acpi_battery_dir = NULL;
}
mutex_unlock(&cm_sbs_mutex);
return;
}
