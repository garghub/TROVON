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
static int acpi_container_add(struct acpi_device *device)
{
struct acpi_container *container;
if (!device) {
printk(KERN_ERR PREFIX "device is NULL\n");
return -EINVAL;
}
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
present = is_device_present(handle);
switch (type) {
case ACPI_NOTIFY_BUS_CHECK:
case ACPI_NOTIFY_DEVICE_CHECK:
printk(KERN_WARNING "Container driver received %s event\n",
(type == ACPI_NOTIFY_BUS_CHECK) ?
"ACPI_NOTIFY_BUS_CHECK" : "ACPI_NOTIFY_DEVICE_CHECK");
status = acpi_bus_get_device(handle, &device);
if (present) {
if (ACPI_FAILURE(status) || !device) {
result = container_device_add(&device, handle);
if (!result)
kobject_uevent(&device->dev.kobj,
KOBJ_ONLINE);
else
printk(KERN_WARNING
"Failed to add container\n");
}
} else {
if (ACPI_SUCCESS(status)) {
kobject_uevent(&device->dev.kobj, KOBJ_OFFLINE);
}
}
break;
case ACPI_NOTIFY_EJECT_REQUEST:
if (!acpi_bus_get_device(handle, &device) && device) {
kobject_uevent(&device->dev.kobj, KOBJ_OFFLINE);
}
break;
default:
break;
}
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
if (strcmp(hid, "ACPI0004") && strcmp(hid, "PNP0A05") &&
strcmp(hid, "PNP0A06")) {
goto end;
}
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
