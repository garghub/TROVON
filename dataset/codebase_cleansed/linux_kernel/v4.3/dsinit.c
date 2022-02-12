static acpi_status
acpi_ds_init_one_object(acpi_handle obj_handle,
u32 level, void *context, void **return_value)
{
struct acpi_init_walk_info *info =
(struct acpi_init_walk_info *)context;
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
acpi_status status;
union acpi_operand_object *obj_desc;
ACPI_FUNCTION_ENTRY();
if (node->owner_id != info->owner_id) {
return (AE_OK);
}
info->object_count++;
switch (acpi_ns_get_type(obj_handle)) {
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
obj_desc = acpi_ns_get_attached_object(node);
if (!obj_desc) {
break;
}
if (obj_desc->method.info_flags & ACPI_METHOD_SERIALIZED) {
info->serial_method_count++;
break;
}
if (acpi_gbl_auto_serialize_methods) {
acpi_ds_auto_serialize_method(node, obj_desc);
if (obj_desc->method.
info_flags & ACPI_METHOD_SERIALIZED) {
info->serial_method_count++;
info->serialized_method_count++;
break;
}
}
info->non_serial_method_count++;
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
memset(&info, 0, sizeof(struct acpi_init_walk_info));
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
if (ACPI_COMPARE_NAME(table->signature, ACPI_SIG_DSDT)) {
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
"\nInitializing Namespace objects:\n"));
}
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
"Table [%4.4s:%8.8s] (id %.2X) - %4u Objects with %3u Devices, "
"%3u Regions, %4u Methods (%u/%u/%u Serial/Non/Cvt)\n",
table->signature, table->oem_table_id, owner_id,
info.object_count, info.device_count,
info.op_region_count, info.method_count,
info.serial_method_count,
info.non_serial_method_count,
info.serialized_method_count));
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH, "%u Methods, %u Regions\n",
info.method_count, info.op_region_count));
return_ACPI_STATUS(AE_OK);
}
