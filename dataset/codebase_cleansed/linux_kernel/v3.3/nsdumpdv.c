static acpi_status
acpi_ns_dump_one_device(acpi_handle obj_handle,
u32 level, void *context, void **return_value)
{
struct acpi_device_info *info;
acpi_status status;
u32 i;
ACPI_FUNCTION_NAME(ns_dump_one_device);
status =
acpi_ns_dump_one_object(obj_handle, level, context, return_value);
status = acpi_get_object_info(obj_handle, &info);
if (ACPI_SUCCESS(status)) {
for (i = 0; i < level; i++) {
ACPI_DEBUG_PRINT_RAW((ACPI_DB_TABLES, " "));
}
ACPI_DEBUG_PRINT_RAW((ACPI_DB_TABLES,
" HID: %s, ADR: %8.8X%8.8X, Status: %X\n",
info->hardware_id.string,
ACPI_FORMAT_UINT64(info->address),
info->current_status));
ACPI_FREE(info);
}
return (status);
}
void acpi_ns_dump_root_devices(void)
{
acpi_handle sys_bus_handle;
acpi_status status;
ACPI_FUNCTION_NAME(ns_dump_root_devices);
if (!(ACPI_LV_TABLES & acpi_dbg_level)) {
return;
}
status = acpi_get_handle(NULL, ACPI_NS_SYSTEM_BUS, &sys_bus_handle);
if (ACPI_FAILURE(status)) {
return;
}
ACPI_DEBUG_PRINT((ACPI_DB_TABLES,
"Display of all devices in the namespace:\n"));
status = acpi_ns_walk_namespace(ACPI_TYPE_DEVICE, sys_bus_handle,
ACPI_UINT32_MAX, ACPI_NS_WALK_NO_UNLOCK,
acpi_ns_dump_one_device, NULL, NULL,
NULL);
}
