static int add_dock_dependent_device(struct dock_station *ds,
struct acpi_device *adev)
{
struct dock_dependent_device *dd;
dd = kzalloc(sizeof(*dd), GFP_KERNEL);
if (!dd)
return -ENOMEM;
dd->adev = adev;
INIT_LIST_HEAD(&dd->list);
list_add_tail(&dd->list, &ds->dependent_devices);
return 0;
}
static void dock_hotplug_event(struct dock_dependent_device *dd, u32 event,
enum dock_callback_type cb_type)
{
struct acpi_device *adev = dd->adev;
acpi_lock_hp_context();
if (!adev->hp)
goto out;
if (cb_type == DOCK_CALL_FIXUP) {
void (*fixup)(struct acpi_device *);
fixup = adev->hp->fixup;
if (fixup) {
acpi_unlock_hp_context();
fixup(adev);
return;
}
} else if (cb_type == DOCK_CALL_UEVENT) {
void (*uevent)(struct acpi_device *, u32);
uevent = adev->hp->uevent;
if (uevent) {
acpi_unlock_hp_context();
uevent(adev, event);
return;
}
} else {
int (*notify)(struct acpi_device *, u32);
notify = adev->hp->notify;
if (notify) {
acpi_unlock_hp_context();
notify(adev, event);
return;
}
}
out:
acpi_unlock_hp_context();
}
static struct dock_station *find_dock_station(acpi_handle handle)
{
struct dock_station *ds;
list_for_each_entry(ds, &dock_stations, sibling)
if (ds->handle == handle)
return ds;
return NULL;
}
static struct dock_dependent_device *
find_dock_dependent_device(struct dock_station *ds, struct acpi_device *adev)
{
struct dock_dependent_device *dd;
list_for_each_entry(dd, &ds->dependent_devices, list)
if (adev == dd->adev)
return dd;
return NULL;
}
void register_dock_dependent_device(struct acpi_device *adev,
acpi_handle dshandle)
{
struct dock_station *ds = find_dock_station(dshandle);
if (ds && !find_dock_dependent_device(ds, adev))
add_dock_dependent_device(ds, adev);
}
int is_dock_device(struct acpi_device *adev)
{
struct dock_station *dock_station;
if (!dock_station_count)
return 0;
if (acpi_dock_match(adev->handle))
return 1;
list_for_each_entry(dock_station, &dock_stations, sibling)
if (find_dock_dependent_device(dock_station, adev))
return 1;
return 0;
}
static int dock_present(struct dock_station *ds)
{
unsigned long long sta;
acpi_status status;
if (ds) {
status = acpi_evaluate_integer(ds->handle, "_STA", NULL, &sta);
if (ACPI_SUCCESS(status) && sta)
return 1;
}
return 0;
}
static void hot_remove_dock_devices(struct dock_station *ds)
{
struct dock_dependent_device *dd;
list_for_each_entry_reverse(dd, &ds->dependent_devices, list)
dock_hotplug_event(dd, ACPI_NOTIFY_EJECT_REQUEST, false);
list_for_each_entry_reverse(dd, &ds->dependent_devices, list)
acpi_bus_trim(dd->adev);
}
static void hotplug_dock_devices(struct dock_station *ds, u32 event)
{
struct dock_dependent_device *dd;
list_for_each_entry(dd, &ds->dependent_devices, list)
dock_hotplug_event(dd, event, DOCK_CALL_FIXUP);
list_for_each_entry(dd, &ds->dependent_devices, list)
dock_hotplug_event(dd, event, DOCK_CALL_HANDLER);
list_for_each_entry(dd, &ds->dependent_devices, list) {
struct acpi_device *adev = dd->adev;
if (!acpi_device_enumerated(adev)) {
int ret = acpi_bus_scan(adev->handle);
if (ret)
dev_dbg(&adev->dev, "scan error %d\n", -ret);
}
}
}
static void dock_event(struct dock_station *ds, u32 event, int num)
{
struct device *dev = &ds->dock_device->dev;
char event_string[13];
char *envp[] = { event_string, NULL };
struct dock_dependent_device *dd;
if (num == UNDOCK_EVENT)
sprintf(event_string, "EVENT=undock");
else
sprintf(event_string, "EVENT=dock");
if (num == DOCK_EVENT)
kobject_uevent_env(&dev->kobj, KOBJ_CHANGE, envp);
list_for_each_entry(dd, &ds->dependent_devices, list)
dock_hotplug_event(dd, event, DOCK_CALL_UEVENT);
if (num != DOCK_EVENT)
kobject_uevent_env(&dev->kobj, KOBJ_CHANGE, envp);
}
static void handle_dock(struct dock_station *ds, int dock)
{
acpi_status status;
struct acpi_object_list arg_list;
union acpi_object arg;
unsigned long long value;
acpi_handle_info(ds->handle, "%s\n", dock ? "docking" : "undocking");
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = dock;
status = acpi_evaluate_integer(ds->handle, "_DCK", &arg_list, &value);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND)
acpi_handle_err(ds->handle, "Failed to execute _DCK (0x%x)\n",
status);
}
static inline void dock(struct dock_station *ds)
{
handle_dock(ds, 1);
}
static inline void undock(struct dock_station *ds)
{
handle_dock(ds, 0);
}
static inline void begin_dock(struct dock_station *ds)
{
ds->flags |= DOCK_DOCKING;
}
static inline void complete_dock(struct dock_station *ds)
{
ds->flags &= ~(DOCK_DOCKING);
ds->last_dock_time = jiffies;
}
static inline void begin_undock(struct dock_station *ds)
{
ds->flags |= DOCK_UNDOCKING;
}
static inline void complete_undock(struct dock_station *ds)
{
ds->flags &= ~(DOCK_UNDOCKING);
}
static int dock_in_progress(struct dock_station *ds)
{
if ((ds->flags & DOCK_DOCKING) ||
time_before(jiffies, (ds->last_dock_time + HZ)))
return 1;
return 0;
}
static int handle_eject_request(struct dock_station *ds, u32 event)
{
if (dock_in_progress(ds))
return -EBUSY;
dock_event(ds, event, UNDOCK_EVENT);
hot_remove_dock_devices(ds);
undock(ds);
acpi_evaluate_lck(ds->handle, 0);
acpi_evaluate_ej0(ds->handle);
if (dock_present(ds)) {
acpi_handle_err(ds->handle, "Unable to undock!\n");
return -EBUSY;
}
complete_undock(ds);
return 0;
}
int dock_notify(struct acpi_device *adev, u32 event)
{
acpi_handle handle = adev->handle;
struct dock_station *ds = find_dock_station(handle);
int surprise_removal = 0;
if (!ds)
return -ENODEV;
if ((ds->flags & DOCK_IS_DOCK) && event == ACPI_NOTIFY_DEVICE_CHECK)
event = ACPI_NOTIFY_EJECT_REQUEST;
switch (event) {
case ACPI_NOTIFY_BUS_CHECK:
case ACPI_NOTIFY_DEVICE_CHECK:
if (!dock_in_progress(ds) && !acpi_device_enumerated(adev)) {
begin_dock(ds);
dock(ds);
if (!dock_present(ds)) {
acpi_handle_err(handle, "Unable to dock!\n");
complete_dock(ds);
break;
}
hotplug_dock_devices(ds, event);
complete_dock(ds);
dock_event(ds, event, DOCK_EVENT);
acpi_evaluate_lck(ds->handle, 1);
acpi_update_all_gpes();
break;
}
if (dock_present(ds) || dock_in_progress(ds))
break;
surprise_removal = 1;
event = ACPI_NOTIFY_EJECT_REQUEST;
case ACPI_NOTIFY_EJECT_REQUEST:
begin_undock(ds);
if ((immediate_undock && !(ds->flags & DOCK_IS_ATA))
|| surprise_removal)
handle_eject_request(ds, event);
else
dock_event(ds, event, UNDOCK_EVENT);
break;
}
return 0;
}
static ssize_t show_docked(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dock_station *dock_station = dev->platform_data;
struct acpi_device *adev = NULL;
acpi_bus_get_device(dock_station->handle, &adev);
return snprintf(buf, PAGE_SIZE, "%u\n", acpi_device_enumerated(adev));
}
static ssize_t show_flags(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dock_station *dock_station = dev->platform_data;
return snprintf(buf, PAGE_SIZE, "%d\n", dock_station->flags);
}
static ssize_t write_undock(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int ret;
struct dock_station *dock_station = dev->platform_data;
if (!count)
return -EINVAL;
acpi_scan_lock_acquire();
begin_undock(dock_station);
ret = handle_eject_request(dock_station, ACPI_NOTIFY_EJECT_REQUEST);
acpi_scan_lock_release();
return ret ? ret: count;
}
static ssize_t show_dock_uid(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long long lbuf;
struct dock_station *dock_station = dev->platform_data;
acpi_status status = acpi_evaluate_integer(dock_station->handle,
"_UID", NULL, &lbuf);
if (ACPI_FAILURE(status))
return 0;
return snprintf(buf, PAGE_SIZE, "%llx\n", lbuf);
}
static ssize_t show_dock_type(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dock_station *dock_station = dev->platform_data;
char *type;
if (dock_station->flags & DOCK_IS_DOCK)
type = "dock_station";
else if (dock_station->flags & DOCK_IS_ATA)
type = "ata_bay";
else if (dock_station->flags & DOCK_IS_BAT)
type = "battery_bay";
else
type = "unknown";
return snprintf(buf, PAGE_SIZE, "%s\n", type);
}
void acpi_dock_add(struct acpi_device *adev)
{
struct dock_station *dock_station, ds = { NULL, };
struct platform_device_info pdevinfo;
acpi_handle handle = adev->handle;
struct platform_device *dd;
int ret;
memset(&pdevinfo, 0, sizeof(pdevinfo));
pdevinfo.name = "dock";
pdevinfo.id = dock_station_count;
pdevinfo.fwnode = acpi_fwnode_handle(adev);
pdevinfo.data = &ds;
pdevinfo.size_data = sizeof(ds);
dd = platform_device_register_full(&pdevinfo);
if (IS_ERR(dd))
return;
dock_station = dd->dev.platform_data;
dock_station->handle = handle;
dock_station->dock_device = dd;
dock_station->last_dock_time = jiffies - HZ;
INIT_LIST_HEAD(&dock_station->sibling);
INIT_LIST_HEAD(&dock_station->dependent_devices);
dev_set_uevent_suppress(&dd->dev, 0);
if (acpi_dock_match(handle))
dock_station->flags |= DOCK_IS_DOCK;
if (acpi_ata_match(handle))
dock_station->flags |= DOCK_IS_ATA;
if (acpi_device_is_battery(adev))
dock_station->flags |= DOCK_IS_BAT;
ret = sysfs_create_group(&dd->dev.kobj, &dock_attribute_group);
if (ret)
goto err_unregister;
ret = add_dock_dependent_device(dock_station, adev);
if (ret)
goto err_rmgroup;
dock_station_count++;
list_add(&dock_station->sibling, &dock_stations);
adev->flags.is_dock_station = true;
dev_info(&adev->dev, "ACPI dock station (docks/bays count: %d)\n",
dock_station_count);
return;
err_rmgroup:
sysfs_remove_group(&dd->dev.kobj, &dock_attribute_group);
err_unregister:
platform_device_unregister(dd);
acpi_handle_err(handle, "%s encountered error %d\n", __func__, ret);
}
