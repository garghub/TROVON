static int acpi_ac_get_state(struct acpi_ac *ac)
{
acpi_status status = AE_OK;
if (!ac)
return -EINVAL;
status = acpi_evaluate_integer(ac->device->handle, "_PSR", NULL, &ac->state);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Error reading AC Adapter state"));
ac->state = ACPI_AC_STATUS_UNKNOWN;
return -ENODEV;
}
return 0;
}
static int get_ac_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct acpi_ac *ac = to_acpi_ac(psy);
if (!ac)
return -ENODEV;
if (acpi_ac_get_state(ac))
return -ENODEV;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = ac->state;
break;
default:
return -EINVAL;
}
return 0;
}
static int acpi_ac_seq_show(struct seq_file *seq, void *offset)
{
struct acpi_ac *ac = seq->private;
if (!ac)
return 0;
if (acpi_ac_get_state(ac)) {
seq_puts(seq, "ERROR: Unable to read AC Adapter state\n");
return 0;
}
seq_puts(seq, "state: ");
switch (ac->state) {
case ACPI_AC_STATUS_OFFLINE:
seq_puts(seq, "off-line\n");
break;
case ACPI_AC_STATUS_ONLINE:
seq_puts(seq, "on-line\n");
break;
default:
seq_puts(seq, "unknown\n");
break;
}
return 0;
}
static int acpi_ac_open_fs(struct inode *inode, struct file *file)
{
return single_open(file, acpi_ac_seq_show, PDE(inode)->data);
}
static int acpi_ac_add_fs(struct acpi_device *device)
{
struct proc_dir_entry *entry = NULL;
printk(KERN_WARNING PREFIX "Deprecated procfs I/F for AC is loaded,"
" please retry with CONFIG_ACPI_PROCFS_POWER cleared\n");
if (!acpi_device_dir(device)) {
acpi_device_dir(device) = proc_mkdir(acpi_device_bid(device),
acpi_ac_dir);
if (!acpi_device_dir(device))
return -ENODEV;
}
entry = proc_create_data(ACPI_AC_FILE_STATE,
S_IRUGO, acpi_device_dir(device),
&acpi_ac_fops, acpi_driver_data(device));
if (!entry)
return -ENODEV;
return 0;
}
static int acpi_ac_remove_fs(struct acpi_device *device)
{
if (acpi_device_dir(device)) {
remove_proc_entry(ACPI_AC_FILE_STATE, acpi_device_dir(device));
remove_proc_entry(acpi_device_bid(device), acpi_ac_dir);
acpi_device_dir(device) = NULL;
}
return 0;
}
static void acpi_ac_notify(struct acpi_device *device, u32 event)
{
struct acpi_ac *ac = acpi_driver_data(device);
if (!ac)
return;
switch (event) {
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Unsupported event [0x%x]\n", event));
case ACPI_AC_NOTIFY_STATUS:
case ACPI_NOTIFY_BUS_CHECK:
case ACPI_NOTIFY_DEVICE_CHECK:
acpi_ac_get_state(ac);
acpi_bus_generate_proc_event(device, event, (u32) ac->state);
acpi_bus_generate_netlink_event(device->pnp.device_class,
dev_name(&device->dev), event,
(u32) ac->state);
acpi_notifier_call_chain(device, event, (u32) ac->state);
kobject_uevent(&ac->charger.dev->kobj, KOBJ_CHANGE);
}
return;
}
static int acpi_ac_add(struct acpi_device *device)
{
int result = 0;
struct acpi_ac *ac = NULL;
if (!device)
return -EINVAL;
ac = kzalloc(sizeof(struct acpi_ac), GFP_KERNEL);
if (!ac)
return -ENOMEM;
ac->device = device;
strcpy(acpi_device_name(device), ACPI_AC_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_AC_CLASS);
device->driver_data = ac;
result = acpi_ac_get_state(ac);
if (result)
goto end;
#ifdef CONFIG_ACPI_PROCFS_POWER
result = acpi_ac_add_fs(device);
#endif
if (result)
goto end;
ac->charger.name = acpi_device_bid(device);
ac->charger.type = POWER_SUPPLY_TYPE_MAINS;
ac->charger.properties = ac_props;
ac->charger.num_properties = ARRAY_SIZE(ac_props);
ac->charger.get_property = get_ac_property;
result = power_supply_register(&ac->device->dev, &ac->charger);
if (result)
goto end;
printk(KERN_INFO PREFIX "%s [%s] (%s)\n",
acpi_device_name(device), acpi_device_bid(device),
ac->state ? "on-line" : "off-line");
end:
if (result) {
#ifdef CONFIG_ACPI_PROCFS_POWER
acpi_ac_remove_fs(device);
#endif
kfree(ac);
}
return result;
}
static int acpi_ac_resume(struct device *dev)
{
struct acpi_ac *ac;
unsigned old_state;
if (!dev)
return -EINVAL;
ac = acpi_driver_data(to_acpi_device(dev));
if (!ac)
return -EINVAL;
old_state = ac->state;
if (acpi_ac_get_state(ac))
return 0;
if (old_state != ac->state)
kobject_uevent(&ac->charger.dev->kobj, KOBJ_CHANGE);
return 0;
}
static int acpi_ac_remove(struct acpi_device *device)
{
struct acpi_ac *ac = NULL;
if (!device || !acpi_driver_data(device))
return -EINVAL;
ac = acpi_driver_data(device);
if (ac->charger.dev)
power_supply_unregister(&ac->charger);
#ifdef CONFIG_ACPI_PROCFS_POWER
acpi_ac_remove_fs(device);
#endif
kfree(ac);
return 0;
}
static int __init acpi_ac_init(void)
{
int result;
if (acpi_disabled)
return -ENODEV;
#ifdef CONFIG_ACPI_PROCFS_POWER
acpi_ac_dir = acpi_lock_ac_dir();
if (!acpi_ac_dir)
return -ENODEV;
#endif
result = acpi_bus_register_driver(&acpi_ac_driver);
if (result < 0) {
#ifdef CONFIG_ACPI_PROCFS_POWER
acpi_unlock_ac_dir(acpi_ac_dir);
#endif
return -ENODEV;
}
return 0;
}
static void __exit acpi_ac_exit(void)
{
acpi_bus_unregister_driver(&acpi_ac_driver);
#ifdef CONFIG_ACPI_PROCFS_POWER
acpi_unlock_ac_dir(acpi_ac_dir);
#endif
return;
}
