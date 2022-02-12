static int is_device_present(acpi_handle handle)
{
acpi_handle temp;
acpi_status status;
unsigned long long sta;
status = acpi_get_handle(handle, "_STA", &temp);
if (ACPI_FAILURE(status))
return 1;
status = acpi_evaluate_integer(handle, "_STA", NULL, &sta);
if (ACPI_FAILURE(status))
return 0;
return ((sta & ACPI_STA_DEVICE_PRESENT) == ACPI_STA_DEVICE_PRESENT);
}
static bool is_container_device(const char *hid)
{
const struct acpi_device_id *container_id;
for (container_id = container_device_ids;
container_id->id[0]; container_id++) {
if (!strcmp((char *)container_id->id, hid))
return true;
}
return false;
}
static int acpi_container_add(struct acpi_device *device)
{
struct acpi_container *container;
container = kzalloc(sizeof(struct acpi_container), GFP_KERNEL);
if (!container)
return -ENOMEM;
container->handle = device->handle;
strcpy(acpi_device_name(device), ACPI_CONTAINER_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_CONTAINER_CLASS);
device->driver_data = container;
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Device <%s> bid <%s>\n",
acpi_device_name(device), acpi_device_bid(device)));
return 0;
}
static int acpi_container_remove(struct acpi_device *device, int type)
{
acpi_status status = AE_OK;
struct acpi_container *pc = NULL;
pc = acpi_driver_data(device);
kfree(pc);
return status;
}
static int container_device_add(struct acpi_device **device, acpi_handle handle)
{
acpi_handle phandle;
struct acpi_device *pdev;
int result;
if (acpi_get_parent(handle, &phandle)) {
return -ENODEV;
}
if (acpi_bus_get_device(phandle, &pdev)) {
return -ENODEV;
}
if (acpi_bus_add(device, pdev, handle, ACPI_BUS_TYPE_DEVICE)) {
return -ENODEV;
}
result = acpi_bus_start(*device);
return result;
}
static void container_notify_cb(acpi_handle handle, u32 type, void *context)
{
struct acpi_device *device = NULL;
int result;
int present;
acpi_status status;
u32 ost_code = ACPI_OST_SC_NON_SPECIFIC_FAILURE;
switch (type) {
case ACPI_NOTIFY_BUS_CHECK:
case ACPI_NOTIFY_DEVICE_CHECK:
pr_debug("Container driver received %s event\n",
(type == ACPI_NOTIFY_BUS_CHECK) ?
"ACPI_NOTIFY_BUS_CHECK" : "ACPI_NOTIFY_DEVICE_CHECK");
present = is_device_present(handle);
status = acpi_bus_get_device(handle, &device);
if (!present) {
if (ACPI_SUCCESS(status)) {
device->flags.eject_pending = 1;
kobject_uevent(&device->dev.kobj, KOBJ_OFFLINE);
return;
}
break;
}
if (!ACPI_FAILURE(status) || device)
break;
result = container_device_add(&device, handle);
if (result) {
acpi_handle_warn(handle, "Failed to add container\n");
break;
}
kobject_uevent(&device->dev.kobj, KOBJ_ONLINE);
ost_code = ACPI_OST_SC_SUCCESS;
break;
case ACPI_NOTIFY_EJECT_REQUEST:
if (!acpi_bus_get_device(handle, &device) && device) {
device->flags.eject_pending = 1;
kobject_uevent(&device->dev.kobj, KOBJ_OFFLINE);
return;
}
break;
default:
return;
}
(void) acpi_evaluate_hotplug_ost(handle, type, ost_code, NULL);
return;
}
static acpi_status
container_walk_namespace_cb(acpi_handle handle,
u32 lvl, void *context, void **rv)
{
char *hid = NULL;
struct acpi_device_info *info;
acpi_status status;
int *action = context;
status = acpi_get_object_info(handle, &info);
if (ACPI_FAILURE(status)) {
return AE_OK;
}
if (info->valid & ACPI_VALID_HID)
hid = info->hardware_id.string;
if (hid == NULL) {
goto end;
}
if (!is_container_device(hid))
goto end;
switch (*action) {
case INSTALL_NOTIFY_HANDLER:
acpi_install_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
container_notify_cb, NULL);
break;
case UNINSTALL_NOTIFY_HANDLER:
acpi_remove_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
container_notify_cb);
break;
default:
break;
}
end:
kfree(info);
return AE_OK;
}
static int __init acpi_container_init(void)
{
int result = 0;
int action = INSTALL_NOTIFY_HANDLER;
result = acpi_bus_register_driver(&acpi_container_driver);
if (result < 0) {
return (result);
}
acpi_walk_namespace(ACPI_TYPE_DEVICE,
ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
container_walk_namespace_cb, NULL, &action, NULL);
return (0);
}
static void __exit acpi_container_exit(void)
{
int action = UNINSTALL_NOTIFY_HANDLER;
acpi_walk_namespace(ACPI_TYPE_DEVICE,
ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
container_walk_namespace_cb, NULL, &action, NULL);
acpi_bus_unregister_driver(&acpi_container_driver);
return;
}
