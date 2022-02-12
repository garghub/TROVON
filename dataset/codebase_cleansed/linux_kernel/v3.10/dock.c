static int
add_dock_dependent_device(struct dock_station *ds, acpi_handle handle)
{
struct dock_dependent_device *dd;
dd = kzalloc(sizeof(*dd), GFP_KERNEL);
if (!dd)
return -ENOMEM;
dd->handle = handle;
INIT_LIST_HEAD(&dd->list);
spin_lock(&ds->dd_lock);
list_add_tail(&dd->list, &ds->dependent_devices);
spin_unlock(&ds->dd_lock);
return 0;
}
static int dock_init_hotplug(struct dock_dependent_device *dd,
const struct acpi_dock_ops *ops, void *context,
void (*init)(void *), void (*release)(void *))
{
int ret = 0;
mutex_lock(&hotplug_lock);
if (dd->hp_context) {
ret = -EEXIST;
} else {
dd->hp_refcount = 1;
dd->hp_ops = ops;
dd->hp_context = context;
dd->hp_release = release;
}
if (!WARN_ON(ret) && init)
init(context);
mutex_unlock(&hotplug_lock);
return ret;
}
static void dock_release_hotplug(struct dock_dependent_device *dd)
{
void (*release)(void *) = NULL;
void *context = NULL;
mutex_lock(&hotplug_lock);
if (dd->hp_context && !--dd->hp_refcount) {
dd->hp_ops = NULL;
context = dd->hp_context;
dd->hp_context = NULL;
release = dd->hp_release;
dd->hp_release = NULL;
}
if (release && context)
release(context);
mutex_unlock(&hotplug_lock);
}
static void dock_hotplug_event(struct dock_dependent_device *dd, u32 event,
bool uevent)
{
acpi_notify_handler cb = NULL;
bool run = false;
mutex_lock(&hotplug_lock);
if (dd->hp_context) {
run = true;
dd->hp_refcount++;
if (dd->hp_ops)
cb = uevent ? dd->hp_ops->uevent : dd->hp_ops->handler;
}
mutex_unlock(&hotplug_lock);
if (!run)
return;
if (cb)
cb(dd->handle, event, dd->hp_context);
dock_release_hotplug(dd);
}
static struct dock_dependent_device *
find_dock_dependent_device(struct dock_station *ds, acpi_handle handle)
{
struct dock_dependent_device *dd;
spin_lock(&ds->dd_lock);
list_for_each_entry(dd, &ds->dependent_devices, list) {
if (handle == dd->handle) {
spin_unlock(&ds->dd_lock);
return dd;
}
}
spin_unlock(&ds->dd_lock);
return NULL;
}
static int is_dock(acpi_handle handle)
{
acpi_status status;
acpi_handle tmp;
status = acpi_get_handle(handle, "_DCK", &tmp);
if (ACPI_FAILURE(status))
return 0;
return 1;
}
static int is_ejectable(acpi_handle handle)
{
acpi_status status;
acpi_handle tmp;
status = acpi_get_handle(handle, "_EJ0", &tmp);
if (ACPI_FAILURE(status))
return 0;
return 1;
}
static int is_ata(acpi_handle handle)
{
acpi_handle tmp;
if ((ACPI_SUCCESS(acpi_get_handle(handle, "_GTF", &tmp))) ||
(ACPI_SUCCESS(acpi_get_handle(handle, "_GTM", &tmp))) ||
(ACPI_SUCCESS(acpi_get_handle(handle, "_STM", &tmp))) ||
(ACPI_SUCCESS(acpi_get_handle(handle, "_SDD", &tmp))))
return 1;
return 0;
}
static int is_battery(acpi_handle handle)
{
struct acpi_device_info *info;
int ret = 1;
if (!ACPI_SUCCESS(acpi_get_object_info(handle, &info)))
return 0;
if (!(info->valid & ACPI_VALID_HID))
ret = 0;
else
ret = !strcmp("PNP0C0A", info->hardware_id.string);
kfree(info);
return ret;
}
static int is_ejectable_bay(acpi_handle handle)
{
acpi_handle phandle;
if (!is_ejectable(handle))
return 0;
if (is_battery(handle) || is_ata(handle))
return 1;
if (!acpi_get_parent(handle, &phandle) && is_ata(phandle))
return 1;
return 0;
}
int is_dock_device(acpi_handle handle)
{
struct dock_station *dock_station;
if (!dock_station_count)
return 0;
if (is_dock(handle))
return 1;
list_for_each_entry(dock_station, &dock_stations, sibling)
if (find_dock_dependent_device(dock_station, handle))
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
static struct acpi_device * dock_create_acpi_device(acpi_handle handle)
{
struct acpi_device *device;
int ret;
if (acpi_bus_get_device(handle, &device)) {
ret = acpi_bus_scan(handle);
if (ret)
pr_debug("error adding bus, %x\n", -ret);
acpi_bus_get_device(handle, &device);
}
return device;
}
static void dock_remove_acpi_device(acpi_handle handle)
{
struct acpi_device *device;
if (!acpi_bus_get_device(handle, &device))
acpi_bus_trim(device);
}
static void hotplug_dock_devices(struct dock_station *ds, u32 event)
{
struct dock_dependent_device *dd;
mutex_lock(&ds->hp_lock);
list_for_each_entry(dd, &ds->dependent_devices, list)
dock_hotplug_event(dd, event, false);
list_for_each_entry(dd, &ds->dependent_devices, list) {
if (event == ACPI_NOTIFY_EJECT_REQUEST)
dock_remove_acpi_device(dd->handle);
else
dock_create_acpi_device(dd->handle);
}
mutex_unlock(&ds->hp_lock);
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
dock_hotplug_event(dd, event, true);
if (num != DOCK_EVENT)
kobject_uevent_env(&dev->kobj, KOBJ_CHANGE, envp);
}
static void eject_dock(struct dock_station *ds)
{
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status;
acpi_handle tmp;
status = acpi_get_handle(ds->handle, "_EJ0", &tmp);
if (ACPI_FAILURE(status)) {
pr_debug("No _EJ0 support for dock device\n");
return;
}
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = 1;
status = acpi_evaluate_object(ds->handle, "_EJ0", &arg_list, NULL);
if (ACPI_FAILURE(status))
pr_debug("Failed to evaluate _EJ0!\n");
}
static void handle_dock(struct dock_station *ds, int dock)
{
acpi_status status;
struct acpi_object_list arg_list;
union acpi_object arg;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_handle_info(ds->handle, "%s\n", dock ? "docking" : "undocking");
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = dock;
status = acpi_evaluate_object(ds->handle, "_DCK", &arg_list, &buffer);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND)
acpi_handle_err(ds->handle, "Failed to execute _DCK (0x%x)\n",
status);
kfree(buffer.pointer);
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
static void dock_lock(struct dock_station *ds, int lock)
{
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status;
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = !!lock;
status = acpi_evaluate_object(ds->handle, "_LCK", &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
if (lock)
acpi_handle_warn(ds->handle,
"Locking device failed (0x%x)\n", status);
else
acpi_handle_warn(ds->handle,
"Unlocking device failed (0x%x)\n", status);
}
}
static int dock_in_progress(struct dock_station *ds)
{
if ((ds->flags & DOCK_DOCKING) ||
time_before(jiffies, (ds->last_dock_time + HZ)))
return 1;
return 0;
}
int register_dock_notifier(struct notifier_block *nb)
{
if (!dock_station_count)
return -ENODEV;
return atomic_notifier_chain_register(&dock_notifier_list, nb);
}
void unregister_dock_notifier(struct notifier_block *nb)
{
if (!dock_station_count)
return;
atomic_notifier_chain_unregister(&dock_notifier_list, nb);
}
int register_hotplug_dock_device(acpi_handle handle,
const struct acpi_dock_ops *ops, void *context,
void (*init)(void *), void (*release)(void *))
{
struct dock_dependent_device *dd;
struct dock_station *dock_station;
int ret = -EINVAL;
if (WARN_ON(!context))
return -EINVAL;
if (!dock_station_count)
return -ENODEV;
list_for_each_entry(dock_station, &dock_stations, sibling) {
dd = find_dock_dependent_device(dock_station, handle);
if (dd && !dock_init_hotplug(dd, ops, context, init, release))
ret = 0;
}
return ret;
}
void unregister_hotplug_dock_device(acpi_handle handle)
{
struct dock_dependent_device *dd;
struct dock_station *dock_station;
if (!dock_station_count)
return;
list_for_each_entry(dock_station, &dock_stations, sibling) {
dd = find_dock_dependent_device(dock_station, handle);
if (dd)
dock_release_hotplug(dd);
}
}
static int handle_eject_request(struct dock_station *ds, u32 event)
{
if (dock_in_progress(ds))
return -EBUSY;
dock_event(ds, event, UNDOCK_EVENT);
hotplug_dock_devices(ds, ACPI_NOTIFY_EJECT_REQUEST);
undock(ds);
dock_lock(ds, 0);
eject_dock(ds);
if (dock_present(ds)) {
acpi_handle_err(ds->handle, "Unable to undock!\n");
return -EBUSY;
}
complete_undock(ds);
return 0;
}
static void dock_notify(acpi_handle handle, u32 event, void *data)
{
struct dock_station *ds = data;
struct acpi_device *tmp;
int surprise_removal = 0;
if ((ds->flags & DOCK_IS_DOCK) && event == ACPI_NOTIFY_DEVICE_CHECK)
event = ACPI_NOTIFY_EJECT_REQUEST;
switch (event) {
case ACPI_NOTIFY_BUS_CHECK:
case ACPI_NOTIFY_DEVICE_CHECK:
if (!dock_in_progress(ds) && acpi_bus_get_device(ds->handle,
&tmp)) {
begin_dock(ds);
dock(ds);
if (!dock_present(ds)) {
acpi_handle_err(handle, "Unable to dock!\n");
complete_dock(ds);
break;
}
atomic_notifier_call_chain(&dock_notifier_list,
event, NULL);
hotplug_dock_devices(ds, event);
complete_dock(ds);
dock_event(ds, event, DOCK_EVENT);
dock_lock(ds, 1);
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
default:
acpi_handle_err(handle, "Unknown dock event %d\n", event);
}
}
static void acpi_dock_deferred_cb(void *context)
{
struct dock_data *data = context;
acpi_scan_lock_acquire();
dock_notify(data->handle, data->event, data->ds);
acpi_scan_lock_release();
kfree(data);
}
static int acpi_dock_notifier_call(struct notifier_block *this,
unsigned long event, void *data)
{
struct dock_station *dock_station;
acpi_handle handle = data;
if (event != ACPI_NOTIFY_BUS_CHECK && event != ACPI_NOTIFY_DEVICE_CHECK
&& event != ACPI_NOTIFY_EJECT_REQUEST)
return 0;
acpi_scan_lock_acquire();
list_for_each_entry(dock_station, &dock_stations, sibling) {
if (dock_station->handle == handle) {
struct dock_data *dd;
acpi_status status;
dd = kmalloc(sizeof(*dd), GFP_KERNEL);
if (!dd)
break;
dd->handle = handle;
dd->event = event;
dd->ds = dock_station;
status = acpi_os_hotplug_execute(acpi_dock_deferred_cb,
dd);
if (ACPI_FAILURE(status))
kfree(dd);
break;
}
}
acpi_scan_lock_release();
return 0;
}
static acpi_status
find_dock_devices(acpi_handle handle, u32 lvl, void *context, void **rv)
{
acpi_status status;
acpi_handle tmp, parent;
struct dock_station *ds = context;
status = acpi_bus_get_ejd(handle, &tmp);
if (ACPI_FAILURE(status)) {
status = acpi_get_parent(handle, &parent);
if (ACPI_FAILURE(status))
goto fdd_out;
status = acpi_bus_get_ejd(parent, &tmp);
if (ACPI_FAILURE(status))
goto fdd_out;
}
if (tmp == ds->handle)
add_dock_dependent_device(ds, handle);
fdd_out:
return AE_OK;
}
static ssize_t show_docked(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct acpi_device *tmp;
struct dock_station *dock_station = dev->platform_data;
if (!acpi_bus_get_device(dock_station->handle, &tmp))
return snprintf(buf, PAGE_SIZE, "1\n");
return snprintf(buf, PAGE_SIZE, "0\n");
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
static int __init dock_add(acpi_handle handle)
{
int ret, id;
struct dock_station ds, *dock_station;
struct platform_device *dd;
id = dock_station_count;
memset(&ds, 0, sizeof(ds));
dd = platform_device_register_data(NULL, "dock", id, &ds, sizeof(ds));
if (IS_ERR(dd))
return PTR_ERR(dd);
dock_station = dd->dev.platform_data;
dock_station->handle = handle;
dock_station->dock_device = dd;
dock_station->last_dock_time = jiffies - HZ;
mutex_init(&dock_station->hp_lock);
spin_lock_init(&dock_station->dd_lock);
INIT_LIST_HEAD(&dock_station->sibling);
ATOMIC_INIT_NOTIFIER_HEAD(&dock_notifier_list);
INIT_LIST_HEAD(&dock_station->dependent_devices);
dev_set_uevent_suppress(&dd->dev, 0);
if (is_dock(handle))
dock_station->flags |= DOCK_IS_DOCK;
if (is_ata(handle))
dock_station->flags |= DOCK_IS_ATA;
if (is_battery(handle))
dock_station->flags |= DOCK_IS_BAT;
ret = sysfs_create_group(&dd->dev.kobj, &dock_attribute_group);
if (ret)
goto err_unregister;
acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, find_dock_devices, NULL,
dock_station, NULL);
ret = add_dock_dependent_device(dock_station, handle);
if (ret)
goto err_rmgroup;
dock_station_count++;
list_add(&dock_station->sibling, &dock_stations);
return 0;
err_rmgroup:
sysfs_remove_group(&dd->dev.kobj, &dock_attribute_group);
err_unregister:
platform_device_unregister(dd);
acpi_handle_err(handle, "%s encountered error %d\n", __func__, ret);
return ret;
}
static __init acpi_status
find_dock_and_bay(acpi_handle handle, u32 lvl, void *context, void **rv)
{
if (is_dock(handle) || is_ejectable_bay(handle))
dock_add(handle);
return AE_OK;
}
int __init acpi_dock_init(void)
{
if (acpi_disabled)
return 0;
acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, find_dock_and_bay, NULL, NULL, NULL);
if (!dock_station_count) {
pr_info(PREFIX "No dock devices found.\n");
return 0;
}
register_acpi_bus_notifier(&dock_acpi_notifier);
pr_info(PREFIX "%s: %d docks/bays found\n",
ACPI_DOCK_DRIVER_DESCRIPTION, dock_station_count);
return 0;
}
