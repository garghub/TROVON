acpi_status
acpi_evaluate_object_typed(acpi_handle handle,
acpi_string pathname,
struct acpi_object_list *external_params,
struct acpi_buffer *return_buffer,
acpi_object_type return_type)
{
acpi_status status;
u8 free_buffer_on_error = FALSE;
ACPI_FUNCTION_TRACE(acpi_evaluate_object_typed);
if (!return_buffer) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (return_buffer->length == ACPI_ALLOCATE_BUFFER) {
free_buffer_on_error = TRUE;
}
status = acpi_evaluate_object(handle, pathname,
external_params, return_buffer);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (return_type == ACPI_TYPE_ANY) {
return_ACPI_STATUS(AE_OK);
}
if (return_buffer->length == 0) {
ACPI_ERROR((AE_INFO, "No return value"));
return_ACPI_STATUS(AE_NULL_OBJECT);
}
if (((union acpi_object *)return_buffer->pointer)->type == return_type) {
return_ACPI_STATUS(AE_OK);
}
ACPI_ERROR((AE_INFO,
"Incorrect return type [%s] requested [%s]",
acpi_ut_get_type_name(((union acpi_object *)return_buffer->
pointer)->type),
acpi_ut_get_type_name(return_type)));
if (free_buffer_on_error) {
acpi_os_free(return_buffer->pointer);
return_buffer->pointer = NULL;
}
return_buffer->length = 0;
return_ACPI_STATUS(AE_TYPE);
}
acpi_status
acpi_evaluate_object(acpi_handle handle,
acpi_string pathname,
struct acpi_object_list *external_params,
struct acpi_buffer *return_buffer)
{
acpi_status status;
struct acpi_evaluate_info *info;
acpi_size buffer_space_needed;
u32 i;
ACPI_FUNCTION_TRACE(acpi_evaluate_object);
info = ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_evaluate_info));
if (!info) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
info->prefix_node = acpi_ns_validate_handle(handle);
if (!info->prefix_node) {
status = AE_BAD_PARAMETER;
goto cleanup;
}
if ((pathname) && (ACPI_IS_ROOT_PREFIX(pathname[0]))) {
info->prefix_node = NULL;
} else if (!handle) {
if (!pathname) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Both Handle and Pathname are NULL"));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Null Handle with relative pathname [%s]",
pathname));
}
status = AE_BAD_PARAMETER;
goto cleanup;
}
info->relative_pathname = pathname;
if (external_params && external_params->count) {
info->param_count = (u16)external_params->count;
if (info->param_count > ACPI_METHOD_NUM_ARGS) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Excess arguments (%u) - using only %u",
info->param_count,
ACPI_METHOD_NUM_ARGS));
info->param_count = ACPI_METHOD_NUM_ARGS;
}
info->parameters = ACPI_ALLOCATE_ZEROED(((acpi_size) info->
param_count +
1) * sizeof(void *));
if (!info->parameters) {
status = AE_NO_MEMORY;
goto cleanup;
}
for (i = 0; i < info->param_count; i++) {
status =
acpi_ut_copy_eobject_to_iobject(&external_params->
pointer[i],
&info->
parameters[i]);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
}
info->parameters[info->param_count] = NULL;
}
#if 0
switch (acpi_ns_get_type(info->node)) {
case ACPI_TYPE_METHOD:
if (info->obj_desc->method.param_count > info->param_count) {
ACPI_ERROR((AE_INFO,
"Insufficient arguments (%u) - %u are required",
info->param_count,
info->obj_desc->method.param_count));
status = AE_MISSING_ARGUMENTS;
goto cleanup;
}
else if (info->obj_desc->method.param_count < info->param_count) {
ACPI_WARNING((AE_INFO,
"Excess arguments (%u) - only %u are required",
info->param_count,
info->obj_desc->method.param_count));
info->param_count = info->obj_desc->method.param_count;
}
if (info->param_count) {
info->parameters = ACPI_ALLOCATE_ZEROED(((acpi_size)
info->
param_count +
1) *
sizeof(void *));
if (!info->parameters) {
status = AE_NO_MEMORY;
goto cleanup;
}
for (i = 0; i < info->param_count; i++) {
status =
acpi_ut_copy_eobject_to_iobject
(&external_params->pointer[i],
&info->parameters[i]);
if (ACPI_FAILURE(status)) {
goto cleanup;
}
}
info->parameters[info->param_count] = NULL;
}
break;
default:
if (info->param_count) {
ACPI_WARNING((AE_INFO,
"%u arguments were passed to a non-method ACPI object",
info->param_count));
}
break;
}
#endif
status = acpi_ns_evaluate(info);
if (return_buffer) {
if (!info->return_object) {
return_buffer->length = 0;
} else {
if (ACPI_GET_DESCRIPTOR_TYPE(info->return_object) ==
ACPI_DESC_TYPE_NAMED) {
status = AE_TYPE;
info->return_object = NULL;
return_buffer->length = 0;
}
if (ACPI_SUCCESS(status)) {
acpi_ns_resolve_references(info);
status =
acpi_ut_get_object_size(info->return_object,
&buffer_space_needed);
if (ACPI_SUCCESS(status)) {
status =
acpi_ut_initialize_buffer
(return_buffer,
buffer_space_needed);
if (ACPI_FAILURE(status)) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Needed buffer size %X, %s\n",
(u32)
buffer_space_needed,
acpi_format_exception
(status)));
} else {
status =
acpi_ut_copy_iobject_to_eobject
(info->return_object,
return_buffer);
}
}
}
}
}
if (info->return_object) {
acpi_ex_enter_interpreter();
acpi_ut_remove_reference(info->return_object);
acpi_ex_exit_interpreter();
}
cleanup:
if (info->parameters) {
acpi_ut_delete_internal_object_list(info->parameters);
}
ACPI_FREE(info);
return_ACPI_STATUS(status);
}
static void acpi_ns_resolve_references(struct acpi_evaluate_info *info)
{
union acpi_operand_object *obj_desc = NULL;
struct acpi_namespace_node *node;
if ((info->return_object)->common.type != ACPI_TYPE_LOCAL_REFERENCE) {
return;
}
switch (info->return_object->reference.class) {
case ACPI_REFCLASS_INDEX:
obj_desc = *(info->return_object->reference.where);
break;
case ACPI_REFCLASS_REFOF:
node = info->return_object->reference.object;
if (node) {
obj_desc = node->object;
}
break;
default:
return;
}
if (obj_desc) {
acpi_ut_add_reference(obj_desc);
acpi_ut_remove_reference(info->return_object);
info->return_object = obj_desc;
}
return;
}
acpi_status
acpi_walk_namespace(acpi_object_type type,
acpi_handle start_object,
u32 max_depth,
acpi_walk_callback descending_callback,
acpi_walk_callback ascending_callback,
void *context, void **return_value)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_walk_namespace);
if ((type > ACPI_TYPE_LOCAL_MAX) ||
(!max_depth) || (!descending_callback && !ascending_callback)) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_read_lock(&acpi_gbl_namespace_rw_lock);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
goto unlock_and_exit;
}
if (!acpi_ns_validate_handle(start_object)) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit2;
}
status = acpi_ns_walk_namespace(type, start_object, max_depth,
ACPI_NS_WALK_UNLOCK,
descending_callback, ascending_callback,
context, return_value);
unlock_and_exit2:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
unlock_and_exit:
(void)acpi_ut_release_read_lock(&acpi_gbl_namespace_rw_lock);
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ns_get_device_callback(acpi_handle obj_handle,
u32 nesting_level,
void *context, void **return_value)
{
struct acpi_get_devices_info *info = context;
acpi_status status;
struct acpi_namespace_node *node;
u32 flags;
struct acpi_pnp_device_id *hid;
struct acpi_pnp_device_id_list *cid;
u32 i;
u8 found;
int no_match;
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
node = acpi_ns_validate_handle(obj_handle);
status = acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
if (!node) {
return (AE_BAD_PARAMETER);
}
if (info->hid != NULL) {
status = acpi_ut_execute_HID(node, &hid);
if (status == AE_NOT_FOUND) {
return (AE_OK);
} else if (ACPI_FAILURE(status)) {
return (AE_CTRL_DEPTH);
}
no_match = strcmp(hid->string, info->hid);
ACPI_FREE(hid);
if (no_match) {
status = acpi_ut_execute_CID(node, &cid);
if (status == AE_NOT_FOUND) {
return (AE_OK);
} else if (ACPI_FAILURE(status)) {
return (AE_CTRL_DEPTH);
}
found = FALSE;
for (i = 0; i < cid->count; i++) {
if (strcmp(cid->ids[i].string, info->hid) == 0) {
found = TRUE;
break;
}
}
ACPI_FREE(cid);
if (!found) {
return (AE_OK);
}
}
}
status = acpi_ut_execute_STA(node, &flags);
if (ACPI_FAILURE(status)) {
return (AE_CTRL_DEPTH);
}
if (!(flags & ACPI_STA_DEVICE_PRESENT) &&
!(flags & ACPI_STA_DEVICE_FUNCTIONING)) {
return (AE_CTRL_DEPTH);
}
status = info->user_function(obj_handle, nesting_level, info->context,
return_value);
return (status);
}
acpi_status
acpi_get_devices(const char *HID,
acpi_walk_callback user_function,
void *context, void **return_value)
{
acpi_status status;
struct acpi_get_devices_info info;
ACPI_FUNCTION_TRACE(acpi_get_devices);
if (!user_function) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
info.hid = HID;
info.context = context;
info.user_function = user_function;
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_ns_walk_namespace(ACPI_TYPE_DEVICE, ACPI_ROOT_OBJECT,
ACPI_UINT32_MAX, ACPI_NS_WALK_UNLOCK,
acpi_ns_get_device_callback, NULL,
&info, return_value);
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return_ACPI_STATUS(status);
}
acpi_status
acpi_attach_data(acpi_handle obj_handle,
acpi_object_handler handler, void *data)
{
struct acpi_namespace_node *node;
acpi_status status;
if (!obj_handle || !handler || !data) {
return (AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
node = acpi_ns_validate_handle(obj_handle);
if (!node) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
status = acpi_ns_attach_data(node, handler, data);
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
acpi_status
acpi_detach_data(acpi_handle obj_handle, acpi_object_handler handler)
{
struct acpi_namespace_node *node;
acpi_status status;
if (!obj_handle || !handler) {
return (AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
node = acpi_ns_validate_handle(obj_handle);
if (!node) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
status = acpi_ns_detach_data(node, handler);
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
acpi_status
acpi_get_data_full(acpi_handle obj_handle, acpi_object_handler handler,
void **data, void (*callback)(void *))
{
struct acpi_namespace_node *node;
acpi_status status;
if (!obj_handle || !handler || !data) {
return (AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
node = acpi_ns_validate_handle(obj_handle);
if (!node) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
status = acpi_ns_get_attached_data(node, handler, data);
if (ACPI_SUCCESS(status) && callback) {
callback(*data);
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
acpi_status
acpi_get_data(acpi_handle obj_handle, acpi_object_handler handler, void **data)
{
return acpi_get_data_full(obj_handle, handler, data, NULL);
}
