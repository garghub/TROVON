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
if (result && result != -EEXIST)
continue;
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
int result = 0, nid;
struct acpi_memory_info *info, *n;
nid = acpi_get_node(mem_device->device->handle);
list_for_each_entry_safe(info, n, &mem_device->res_list, list) {
if (!info->enabled)
continue;
if (nid < 0)
nid = memory_add_physaddr_to_nid(info->start_addr);
result = remove_memory(nid, info->start_addr, info->length);
if (result)
return result;
list_del(&info->list);
kfree(info);
}
return result;
}
static void acpi_memory_device_free(struct acpi_memory_device *mem_device)
{
if (!mem_device)
return;
acpi_memory_free_device_resources(mem_device);
mem_device->device->driver_data = NULL;
kfree(mem_device);
}
static int acpi_memory_device_add(struct acpi_device *device,
const struct acpi_device_id *not_used)
{
struct acpi_memory_device *mem_device;
int result;
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
result = acpi_memory_check_device(mem_device);
if (result) {
acpi_memory_device_free(mem_device);
return 0;
}
result = acpi_memory_enable_device(mem_device);
if (result) {
dev_err(&device->dev, "acpi_memory_enable_device() error\n");
acpi_memory_device_free(mem_device);
return -ENODEV;
}
dev_dbg(&device->dev, "Memory device configured by ACPI\n");
return 1;
}
static void acpi_memory_device_remove(struct acpi_device *device)
{
struct acpi_memory_device *mem_device;
if (!device || !acpi_driver_data(device))
return;
mem_device = acpi_driver_data(device);
acpi_memory_remove_memory(mem_device);
acpi_memory_device_free(mem_device);
}
void __init acpi_memory_hotplug_init(void)
{
acpi_scan_add_handler_with_hotplug(&memory_device_handler, "memory");
}
