acpi_status acpi_ns_initialize_objects(void)
{
acpi_status status;
struct acpi_init_walk_info info;
ACPI_FUNCTION_TRACE(ns_initialize_objects);
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Completing Initialization of ACPI Objects\n"));
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"**** Starting initialization of namespace objects ****\n"));
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
"Completing Region/Field/Buffer/Package initialization:\n"));
memset(&info, 0, sizeof(struct acpi_init_walk_info));
status = acpi_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, acpi_ns_init_one_object,
NULL, &info, NULL);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "During WalkNamespace"));
}
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
" Initialized %u/%u Regions %u/%u Fields %u/%u "
"Buffers %u/%u Packages (%u nodes)\n",
info.op_region_init, info.op_region_count,
info.field_init, info.field_count,
info.buffer_init, info.buffer_count,
info.package_init, info.package_count,
info.object_count));
ACPI_DEBUG_PRINT((ACPI_DB_DISPATCH,
"%u Control Methods found\n%u Op Regions found\n",
info.method_count, info.op_region_count));
return_ACPI_STATUS(AE_OK);
}
acpi_status acpi_ns_initialize_devices(u32 flags)
{
acpi_status status = AE_OK;
struct acpi_device_walk_info info;
acpi_handle handle;
ACPI_FUNCTION_TRACE(ns_initialize_devices);
if (!(flags & ACPI_NO_DEVICE_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Initializing ACPI Devices\n"));
info.device_count = 0;
info.num_STA = 0;
info.num_INI = 0;
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
"Initializing Device/Processor/Thermal objects "
"and executing _INI/_STA methods:\n"));
status = acpi_ns_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, FALSE,
acpi_ns_find_ini_methods, NULL,
&info, NULL);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
info.evaluate_info =
ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_evaluate_info));
if (!info.evaluate_info) {
status = AE_NO_MEMORY;
goto error_exit;
}
info.evaluate_info->prefix_node = acpi_gbl_root_node;
info.evaluate_info->relative_pathname = METHOD_NAME__INI;
info.evaluate_info->parameters = NULL;
info.evaluate_info->flags = ACPI_IGNORE_RETURN_VALUE;
status = acpi_ns_evaluate(info.evaluate_info);
if (ACPI_SUCCESS(status)) {
info.num_INI++;
}
status = acpi_get_handle(NULL, "\\_SB", &handle);
if (ACPI_SUCCESS(status)) {
memset(info.evaluate_info, 0,
sizeof(struct acpi_evaluate_info));
info.evaluate_info->prefix_node = handle;
info.evaluate_info->relative_pathname =
METHOD_NAME__INI;
info.evaluate_info->parameters = NULL;
info.evaluate_info->flags = ACPI_IGNORE_RETURN_VALUE;
status = acpi_ns_evaluate(info.evaluate_info);
if (ACPI_SUCCESS(status)) {
info.num_INI++;
}
}
}
if (!(flags & ACPI_NO_ADDRESS_SPACE_INIT)) {
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"[Init] Executing _REG OpRegion methods\n"));
status = acpi_ev_initialize_op_regions();
if (ACPI_FAILURE(status)) {
goto error_exit;
}
}
if (!(flags & ACPI_NO_DEVICE_INIT)) {
status = acpi_ns_walk_namespace(ACPI_TYPE_ANY, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, FALSE,
acpi_ns_init_one_device, NULL,
&info, NULL);
if (acpi_gbl_osi_data >= ACPI_OSI_WIN_2000) {
acpi_gbl_truncate_io_addresses = TRUE;
}
ACPI_FREE(info.evaluate_info);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
" Executed %u _INI methods requiring %u _STA executions "
"(examined %u objects)\n",
info.num_INI, info.num_STA,
info.device_count));
}
return_ACPI_STATUS(status);
error_exit:
ACPI_EXCEPTION((AE_INFO, status, "During device initialization"));
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ns_init_one_object(acpi_handle obj_handle,
u32 level, void *context, void **return_value)
{
acpi_object_type type;
acpi_status status = AE_OK;
struct acpi_init_walk_info *info =
(struct acpi_init_walk_info *)context;
struct acpi_namespace_node *node =
(struct acpi_namespace_node *)obj_handle;
union acpi_operand_object *obj_desc;
ACPI_FUNCTION_NAME(ns_init_one_object);
info->object_count++;
type = acpi_ns_get_type(obj_handle);
obj_desc = acpi_ns_get_attached_object(node);
if (!obj_desc) {
return (AE_OK);
}
switch (type) {
case ACPI_TYPE_REGION:
info->op_region_count++;
break;
case ACPI_TYPE_BUFFER_FIELD:
info->field_count++;
break;
case ACPI_TYPE_LOCAL_BANK_FIELD:
info->field_count++;
break;
case ACPI_TYPE_BUFFER:
info->buffer_count++;
break;
case ACPI_TYPE_PACKAGE:
info->package_count++;
break;
default:
return (AE_OK);
}
if (obj_desc->common.flags & AOPOBJ_DATA_VALID) {
return (AE_OK);
}
acpi_ex_enter_interpreter();
switch (type) {
case ACPI_TYPE_REGION:
info->op_region_init++;
status = acpi_ds_get_region_arguments(obj_desc);
break;
case ACPI_TYPE_BUFFER_FIELD:
info->field_init++;
status = acpi_ds_get_buffer_field_arguments(obj_desc);
break;
case ACPI_TYPE_LOCAL_BANK_FIELD:
info->field_init++;
status = acpi_ds_get_bank_field_arguments(obj_desc);
break;
case ACPI_TYPE_BUFFER:
info->buffer_init++;
status = acpi_ds_get_buffer_arguments(obj_desc);
break;
case ACPI_TYPE_PACKAGE:
info->package_init++;
status = acpi_ds_get_package_arguments(obj_desc);
break;
default:
break;
}
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Could not execute arguments for [%4.4s] (%s)",
acpi_ut_get_node_name(node),
acpi_ut_get_type_name(type)));
}
acpi_ex_exit_interpreter();
return (AE_OK);
}
static acpi_status
acpi_ns_find_ini_methods(acpi_handle obj_handle,
u32 nesting_level, void *context, void **return_value)
{
struct acpi_device_walk_info *info =
ACPI_CAST_PTR(struct acpi_device_walk_info, context);
struct acpi_namespace_node *node;
struct acpi_namespace_node *parent_node;
node = ACPI_CAST_PTR(struct acpi_namespace_node, obj_handle);
if ((node->type == ACPI_TYPE_DEVICE) ||
(node->type == ACPI_TYPE_PROCESSOR) ||
(node->type == ACPI_TYPE_THERMAL)) {
info->device_count++;
return (AE_OK);
}
if (!ACPI_COMPARE_NAME(node->name.ascii, METHOD_NAME__INI)) {
return (AE_OK);
}
parent_node = node->parent;
switch (parent_node->type) {
case ACPI_TYPE_DEVICE:
case ACPI_TYPE_PROCESSOR:
case ACPI_TYPE_THERMAL:
while (parent_node) {
parent_node->flags |= ANOBJ_SUBTREE_HAS_INI;
parent_node = parent_node->parent;
}
break;
default:
break;
}
return (AE_OK);
}
static acpi_status
acpi_ns_init_one_device(acpi_handle obj_handle,
u32 nesting_level, void *context, void **return_value)
{
struct acpi_device_walk_info *walk_info =
ACPI_CAST_PTR(struct acpi_device_walk_info, context);
struct acpi_evaluate_info *info = walk_info->evaluate_info;
u32 flags;
acpi_status status;
struct acpi_namespace_node *device_node;
ACPI_FUNCTION_TRACE(ns_init_one_device);
device_node = ACPI_CAST_PTR(struct acpi_namespace_node, obj_handle);
if ((device_node->type != ACPI_TYPE_DEVICE) &&
(device_node->type != ACPI_TYPE_PROCESSOR) &&
(device_node->type != ACPI_TYPE_THERMAL)) {
return_ACPI_STATUS(AE_OK);
}
if (!(device_node->flags & ANOBJ_SUBTREE_HAS_INI)) {
return_ACPI_STATUS(AE_CTRL_DEPTH);
}
ACPI_DEBUG_EXEC(acpi_ut_display_init_pathname
(ACPI_TYPE_METHOD, device_node, METHOD_NAME__STA));
status = acpi_ut_execute_STA(device_node, &flags);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(AE_OK);
}
if (flags != ACPI_UINT32_MAX) {
walk_info->num_STA++;
}
if (!(flags & ACPI_STA_DEVICE_PRESENT)) {
if (flags & ACPI_STA_DEVICE_FUNCTIONING) {
return_ACPI_STATUS(AE_OK);
} else {
return_ACPI_STATUS(AE_CTRL_DEPTH);
}
}
if (!ACPI_COMPARE_NAME(device_node->name.ascii, "_SB_") ||
device_node->parent != acpi_gbl_root_node) {
ACPI_DEBUG_EXEC(acpi_ut_display_init_pathname
(ACPI_TYPE_METHOD, device_node,
METHOD_NAME__INI));
memset(info, 0, sizeof(struct acpi_evaluate_info));
info->prefix_node = device_node;
info->relative_pathname = METHOD_NAME__INI;
info->parameters = NULL;
info->flags = ACPI_IGNORE_RETURN_VALUE;
status = acpi_ns_evaluate(info);
if (ACPI_SUCCESS(status)) {
walk_info->num_INI++;
}
#ifdef ACPI_DEBUG_OUTPUT
else if (status != AE_NOT_FOUND) {
char *scope_name =
acpi_ns_get_normalized_pathname(device_node, TRUE);
ACPI_EXCEPTION((AE_INFO, status,
"during %s._INI execution",
scope_name));
ACPI_FREE(scope_name);
}
#endif
}
status = AE_OK;
if (acpi_gbl_init_handler) {
status =
acpi_gbl_init_handler(device_node, ACPI_INIT_DEVICE_INI);
}
return_ACPI_STATUS(status);
}
