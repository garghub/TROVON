static acpi_status
acpi_ds_init_one_object(acpi_handle obj_handle,
u32 level, void *context, void **return_value)
{
struct acpi_init_walk_info *info =
(struct acpi_init_walk_info *)context;
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
acpi_object_type type;
acpi_status status;
ACPI_FUNCTION_ENTRY();
if (node->owner_id != info->owner_id) {
return (AE_OK);
}
info->object_count++;
type = acpi_ns_get_type(obj_handle);
switch (type) {
case ACPI_TYPE_REGION:
status = acpi_ds_initialize_region(obj_handle);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During Region initialization %p [%4.4s]",
obj_handle,
acpi_ut_get_node_name(obj_handle)));
}
info->op_region_count++;
break;
case ACPI_TYPE_METHOD:
info->method_count++;
break;
case ACPI_TYPE_DEVICE:
info->device_count++;
break;
default:
break;
}
return (AE_OK);
}
acpi_status
acpi_ds_initialize_objects(u32 table_index,
struct acpi_namespace_node * start_node)
{
acpi_status status;
struct acpi_init_walk_info info;
struct acpi_table_header *table;
acpi_owner_id owner_id;
ACPI_FUNCTION_TRACE(ds_initialize_objects);
status = acpi_tb_get_owner_id(table_index, &owner_id);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"**** Starting initialization of namespace objects ****\n"));
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT, "Parsing all Control Methods:"));
ACPI_MEMSET(&info, 0, sizeof(struct acpi_init_walk_info));
info.owner_id = owner_id;
info.table_index = table_index;
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status =
acpi_ns_walk_namespace(ACPI_TYPE_ANY, start_node, ACPI_UINT32_MAX,
ACPI_NS_WALK_UNLOCK, acpi_ds_init_one_object,
NULL, &info, NULL);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "During WalkNamespace"));
}
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
status = acpi_get_table_by_index(table_index, &table);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
"\nTable [%4.4s](id %4.4X) - %u Objects with %u Devices %u Methods %u Regions\n",
table->signature, owner_id, info.object_count,
info.device_count, info.method_count,
info.op_region_count));
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"%u Methods, %u Regions\n", info.method_count,
info.op_region_count));
return_ACPI_STATUS(AE_OK);
}
