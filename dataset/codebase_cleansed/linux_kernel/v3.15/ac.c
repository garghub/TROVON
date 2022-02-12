static int acpi_ac_get_state(struct acpi_ac *ac)
{
acpi_status status = AE_OK;
if (!ac)
return -EINVAL;
status = acpi_evaluate_integer(ac->device->handle, "_PSR", NULL,
&ac->state);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Error reading AC Adapter state"));
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
if (ac_sleep_before_get_state_ms > 0)
msleep(ac_sleep_before_get_state_ms);
acpi_ac_get_state(ac);
acpi_bus_generate_netlink_event(device->pnp.device_class,
dev_name(&device->dev), event,
(u32) ac->state);
acpi_notifier_call_chain(device, event, (u32) ac->state);
kobject_uevent(&ac->charger.dev->kobj, KOBJ_CHANGE);
}
return;
}
static int acpi_ac_battery_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct acpi_ac *ac = container_of(nb, struct acpi_ac, battery_nb);
struct acpi_bus_event *event = (struct acpi_bus_event *)data;
if (strcmp(event->device_class, ACPI_BATTERY_CLASS) == 0 &&
event->type == ACPI_BATTERY_NOTIFY_STATUS)
acpi_ac_get_state(ac);
return NOTIFY_OK;
}
static int thinkpad_e530_quirk(const struct dmi_system_id *d)
{
ac_sleep_before_get_state_ms = 1000;
return 0;
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
ac->battery_nb.notifier_call = acpi_ac_battery_notify;
register_acpi_notifier(&ac->battery_nb);
end:
if (result)
kfree(ac);
dmi_check_system(ac_dmi_table);
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
unregister_acpi_notifier(&ac->battery_nb);
kfree(ac);
return 0;
}
static int __init acpi_ac_init(void)
{
int result;
if (acpi_disabled)
return -ENODEV;
result = acpi_bus_register_driver(&acpi_ac_driver);
if (result < 0)
return -ENODEV;
return 0;
}
static void __exit acpi_ac_exit(void)
{
acpi_bus_unregister_driver(&acpi_ac_driver);
}
