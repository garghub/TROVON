static acpi_status
acpi_memory_get_resource(struct acpi_resource *resource, void *context)
{
struct acpi_memory_device *mem_device = context;
struct acpi_resource_address64 address64;
struct acpi_memory_info *info, *new;
acpi_status status;
status = acpi_resource_to_address64(resource, &address64);
if (ACPI_FAILURE(status) ||
(address64.resource_type != ACPI_MEMORY_RANGE))
return AE_OK;
list_for_each_entry(info, &mem_device->res_list, list) {
if ((info->caching == address64.info.mem.caching) &&
(info->write_protect == address64.info.mem.write_protect) &&
(info->start_addr + info->length == address64.minimum)) {
info->length += address64.address_length;
return AE_OK;
}
}
new = kzalloc(sizeof(struct acpi_memory_info), GFP_KERNEL);
if (!new)
return AE_ERROR;
INIT_LIST_HEAD(&new->list);
new->caching = address64.info.mem.caching;
new->write_protect = address64.info.mem.write_protect;
new->start_addr = address64.minimum;
new->length = address64.address_length;
list_add_tail(&new->list, &mem_device->res_list);
return AE_OK;
}
static void
acpi_memory_free_device_resources(struct acpi_memory_device *mem_device)
{
struct acpi_memory_info *info, *n;
list_for_each_entry_safe(info, n, &mem_device->res_list, list)
kfree(info);
INIT_LIST_HEAD(&mem_device->res_list);
}
static int
acpi_memory_get_device_resources(struct acpi_memory_device *mem_device)
{
acpi_status status;
if (!list_empty(&mem_device->res_list))
return 0;
status = acpi_walk_resources(mem_device->device->handle, METHOD_NAME__CRS,
acpi_memory_get_resource, mem_device);
if (ACPI_FAILURE(status)) {
acpi_memory_free_device_resources(mem_device);
return -EINVAL;
}
return 0;
}
static int
acpi_memory_get_device(acpi_handle handle,
struct acpi_memory_device **mem_device)
{
acpi_status status;
acpi_handle phandle;
struct acpi_device *device = NULL;
struct acpi_device *pdevice = NULL;
int result;
if (!acpi_bus_get_device(handle, &device) && device)
goto end;
status = acpi_get_parent(handle, &phandle);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Cannot find acpi parent"));
return -EINVAL;
}
result = acpi_bus_get_device(phandle, &pdevice);
if (result) {
acpi_handle_warn(phandle, "Cannot get acpi bus device\n");
return -EINVAL;
}
result = acpi_bus_add(&device, pdevice, handle, ACPI_BUS_TYPE_DEVICE);
if (result) {
acpi_handle_warn(handle, "Cannot add acpi bus\n");
return -EINVAL;
}
end:
*mem_device = acpi_driver_data(device);
if (!(*mem_device)) {
dev_err(&device->dev, "driver data not found\n");
return -ENODEV;
}
return 0;
}
static int acpi_memory_check_device(struct acpi_memory_device *mem_device)
{
unsigned long long current_status;
if (ACPI_FAILURE(acpi_evaluate_integer(mem_device->device->handle, "_STA",
NULL, &current_status)))
return -ENODEV;
if (!((current_status & ACPI_STA_DEVICE_PRESENT)
&& (current_status & ACPI_STA_DEVICE_ENABLED)
&& (current_status & ACPI_STA_DEVICE_FUNCTIONING)))
return -ENODEV;
return 0;
}
static int acpi_memory_enable_device(struct acpi_memory_device *mem_device)
{
int result, num_enabled = 0;
struct acpi_memory_info *info;
int node;
node = acpi_get_node(mem_device->device->handle);
list_for_each_entry(info, &mem_device->res_list, list) {
if (info->enabled) {
num_enabled++;
continue;
}
if (!info->length)
continue;
if (node < 0)
node = memory_add_physaddr_to_nid(info->start_addr);
result = add_memory(node, info->start_addr, info->length);
if (result && result != -EEXIST) {
info->failed = 1;
continue;
}
if (!result)
info->enabled = 1;
num_enabled++;
}
if (!num_enabled) {
dev_err(&mem_device->device->dev, "add_memory failed\n");
mem_device->state = MEMORY_INVALID_STATE;
return -EINVAL;
}
return 0;
}
static int acpi_memory_remove_memory(struct acpi_memory_device *mem_device)
{
int result = 0;
struct acpi_memory_info *info, *n;
list_for_each_entry_safe(info, n, &mem_device->res_list, list) {
if (info->failed)
continue;
if (!info->enabled)
return -EBUSY;
result = remove_memory(info->start_addr, info->length);
if (result)
return result;
list_del(&info->list);
kfree(info);
}
return result;
}
static void acpi_memory_device_notify(acpi_handle handle, u32 event, void *data)
{
struct acpi_memory_device *mem_device;
struct acpi_device *device;
struct acpi_eject_event *ej_event = NULL;
u32 ost_code = ACPI_OST_SC_NON_SPECIFIC_FAILURE;
switch (event) {
case ACPI_NOTIFY_BUS_CHECK:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"\nReceived BUS CHECK notification for device\n"));
case ACPI_NOTIFY_DEVICE_CHECK:
if (event == ACPI_NOTIFY_DEVICE_CHECK)
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"\nReceived DEVICE CHECK notification for device\n"));
if (acpi_memory_get_device(handle, &mem_device)) {
acpi_handle_err(handle, "Cannot find driver data\n");
break;
}
ost_code = ACPI_OST_SC_SUCCESS;
break;
case ACPI_NOTIFY_EJECT_REQUEST:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"\nReceived EJECT REQUEST notification for device\n"));
if (acpi_bus_get_device(handle, &device)) {
acpi_handle_err(handle, "Device doesn't exist\n");
break;
}
mem_device = acpi_driver_data(device);
if (!mem_device) {
acpi_handle_err(handle, "Driver Data is NULL\n");
break;
}
ej_event = kmalloc(sizeof(*ej_event), GFP_KERNEL);
if (!ej_event) {
pr_err(PREFIX "No memory, dropping EJECT\n");
break;
}
ej_event->handle = handle;
ej_event->event = ACPI_NOTIFY_EJECT_REQUEST;
acpi_os_hotplug_execute(acpi_bus_hot_remove_device,
(void *)ej_event);
return;
default:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Unsupported event [0x%x]\n", event));
return;
}
(void) acpi_evaluate_hotplug_ost(handle, event, ost_code, NULL);
return;
}
static void acpi_memory_device_free(struct acpi_memory_device *mem_device)
{
if (!mem_device)
return;
acpi_memory_free_device_resources(mem_device);
kfree(mem_device);
}
static int acpi_memory_device_add(struct acpi_device *device)
{
int result;
struct acpi_memory_device *mem_device = NULL;
if (!device)
return -EINVAL;
mem_device = kzalloc(sizeof(struct acpi_memory_device), GFP_KERNEL);
if (!mem_device)
return -ENOMEM;
INIT_LIST_HEAD(&mem_device->res_list);
mem_device->device = device;
sprintf(acpi_device_name(device), "%s", ACPI_MEMORY_DEVICE_NAME);
sprintf(acpi_device_class(device), "%s", ACPI_MEMORY_DEVICE_CLASS);
device->driver_data = mem_device;
result = acpi_memory_get_device_resources(mem_device);
if (result) {
kfree(mem_device);
return result;
}
mem_device->state = MEMORY_POWER_ON_STATE;
pr_debug("%s\n", acpi_device_name(device));
if (!acpi_memory_check_device(mem_device)) {
result = acpi_memory_enable_device(mem_device);
if (result) {
dev_err(&device->dev,
"Error in acpi_memory_enable_device\n");
acpi_memory_device_free(mem_device);
}
}
return result;
}
static int acpi_memory_device_remove(struct acpi_device *device, int type)
{
struct acpi_memory_device *mem_device = NULL;
int result;
if (!device || !acpi_driver_data(device))
return -EINVAL;
mem_device = acpi_driver_data(device);
result = acpi_memory_remove_memory(mem_device);
if (result)
return result;
acpi_memory_device_free(mem_device);
return 0;
}
static acpi_status is_memory_device(acpi_handle handle)
{
char *hardware_id;
acpi_status status;
struct acpi_device_info *info;
status = acpi_get_object_info(handle, &info);
if (ACPI_FAILURE(status))
return status;
if (!(info->valid & ACPI_VALID_HID)) {
kfree(info);
return AE_ERROR;
}
hardware_id = info->hardware_id.string;
if ((hardware_id == NULL) ||
(strcmp(hardware_id, ACPI_MEMORY_DEVICE_HID)))
status = AE_ERROR;
kfree(info);
return status;
}
static acpi_status
acpi_memory_register_notify_handler(acpi_handle handle,
u32 level, void *ctxt, void **retv)
{
acpi_status status;
status = is_memory_device(handle);
if (ACPI_FAILURE(status))
return AE_OK;
status = acpi_install_notify_handler(handle, ACPI_SYSTEM_NOTIFY,
acpi_memory_device_notify, NULL);
return AE_OK;
}
static acpi_status
acpi_memory_deregister_notify_handler(acpi_handle handle,
u32 level, void *ctxt, void **retv)
{
acpi_status status;
status = is_memory_device(handle);
if (ACPI_FAILURE(status))
return AE_OK;
status = acpi_remove_notify_handler(handle,
ACPI_SYSTEM_NOTIFY,
acpi_memory_device_notify);
return AE_OK;
}
static int __init acpi_memory_device_init(void)
{
int result;
acpi_status status;
result = acpi_bus_register_driver(&acpi_memory_device_driver);
if (result < 0)
return -ENODEV;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_memory_register_notify_handler, NULL,
NULL, NULL);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "walk_namespace failed"));
acpi_bus_unregister_driver(&acpi_memory_device_driver);
return -ENODEV;
}
return 0;
}
static void __exit acpi_memory_device_exit(void)
{
acpi_status status;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX,
acpi_memory_deregister_notify_handler, NULL,
NULL, NULL);
if (ACPI_FAILURE(status))
ACPI_EXCEPTION((AE_INFO, status, "walk_namespace failed"));
acpi_bus_unregister_driver(&acpi_memory_device_driver);
return;
}
