acpi_status
acpi_get_handle(acpi_handle parent,
acpi_string pathname, acpi_handle * ret_handle)
{
acpi_status status;
struct acpi_namespace_node *node = NULL;
struct acpi_namespace_node *prefix_node = NULL;
ACPI_FUNCTION_ENTRY();
if (!ret_handle || !pathname) {
return (AE_BAD_PARAMETER);
}
if (parent) {
prefix_node = acpi_ns_validate_handle(parent);
if (!prefix_node) {
return (AE_BAD_PARAMETER);
}
}
if (ACPI_IS_ROOT_PREFIX(pathname[0])) {
if (!strcmp(pathname, ACPI_NS_ROOT_PATH)) {
*ret_handle =
ACPI_CAST_PTR(acpi_handle, acpi_gbl_root_node);
return (AE_OK);
}
} else if (!prefix_node) {
return (AE_BAD_PARAMETER);
}
status =
acpi_ns_get_node(prefix_node, pathname, ACPI_NS_NO_UPSEARCH, &node);
if (ACPI_SUCCESS(status)) {
*ret_handle = ACPI_CAST_PTR(acpi_handle, node);
}
return (status);
}
acpi_status
acpi_get_name(acpi_handle handle, u32 name_type, struct acpi_buffer * buffer)
{
acpi_status status;
struct acpi_namespace_node *node;
char *node_name;
if (name_type > ACPI_NAME_TYPE_MAX) {
return (AE_BAD_PARAMETER);
}
status = acpi_ut_validate_buffer(buffer);
if (ACPI_FAILURE(status)) {
return (status);
}
if (name_type == ACPI_FULL_PATHNAME) {
status = acpi_ns_handle_to_pathname(handle, buffer);
return (status);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
node = acpi_ns_validate_handle(handle);
if (!node) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
status = acpi_ut_initialize_buffer(buffer, ACPI_PATH_SEGMENT_LENGTH);
if (ACPI_FAILURE(status)) {
goto unlock_and_exit;
}
node_name = acpi_ut_get_node_name(node);
ACPI_MOVE_NAME(buffer->pointer, node_name);
((char *)buffer->pointer)[ACPI_NAME_SIZE] = 0;
status = AE_OK;
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
static char *acpi_ns_copy_device_id(struct acpi_pnp_device_id *dest,
struct acpi_pnp_device_id *source,
char *string_area)
{
dest->string = string_area;
dest->length = source->length;
memcpy(string_area, source->string, source->length);
return (string_area + source->length);
}
acpi_status
acpi_get_object_info(acpi_handle handle,
struct acpi_device_info **return_buffer)
{
struct acpi_namespace_node *node;
struct acpi_device_info *info;
struct acpi_pnp_device_id_list *cid_list = NULL;
struct acpi_pnp_device_id *hid = NULL;
struct acpi_pnp_device_id *uid = NULL;
struct acpi_pnp_device_id *sub = NULL;
struct acpi_pnp_device_id *cls = NULL;
char *next_id_string;
acpi_object_type type;
acpi_name name;
u8 param_count = 0;
u16 valid = 0;
u32 info_size;
u32 i;
acpi_status status;
if (!handle || !return_buffer) {
return (AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
node = acpi_ns_validate_handle(handle);
if (!node) {
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (AE_BAD_PARAMETER);
}
info_size = sizeof(struct acpi_device_info);
type = node->type;
name = node->name.integer;
if (node->type == ACPI_TYPE_METHOD) {
param_count = node->object->method.param_count;
}
status = acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
if ((type == ACPI_TYPE_DEVICE) || (type == ACPI_TYPE_PROCESSOR)) {
status = acpi_ut_execute_HID(node, &hid);
if (ACPI_SUCCESS(status)) {
info_size += hid->length;
valid |= ACPI_VALID_HID;
}
status = acpi_ut_execute_UID(node, &uid);
if (ACPI_SUCCESS(status)) {
info_size += uid->length;
valid |= ACPI_VALID_UID;
}
status = acpi_ut_execute_SUB(node, &sub);
if (ACPI_SUCCESS(status)) {
info_size += sub->length;
valid |= ACPI_VALID_SUB;
}
status = acpi_ut_execute_CID(node, &cid_list);
if (ACPI_SUCCESS(status)) {
info_size +=
(cid_list->list_size -
sizeof(struct acpi_pnp_device_id_list));
valid |= ACPI_VALID_CID;
}
status = acpi_ut_execute_CLS(node, &cls);
if (ACPI_SUCCESS(status)) {
info_size += cls->length;
valid |= ACPI_VALID_CLS;
}
}
info = ACPI_ALLOCATE_ZEROED(info_size);
if (!info) {
status = AE_NO_MEMORY;
goto cleanup;
}
if ((type == ACPI_TYPE_DEVICE) || (type == ACPI_TYPE_PROCESSOR)) {
status = acpi_ut_execute_STA(node, &info->current_status);
if (ACPI_SUCCESS(status)) {
valid |= ACPI_VALID_STA;
}
status = acpi_ut_evaluate_numeric_object(METHOD_NAME__ADR, node,
&info->address);
if (ACPI_SUCCESS(status)) {
valid |= ACPI_VALID_ADR;
}
status = acpi_ut_execute_power_methods(node,
acpi_gbl_lowest_dstate_names,
ACPI_NUM_sx_w_METHODS,
info->lowest_dstates);
if (ACPI_SUCCESS(status)) {
valid |= ACPI_VALID_SXWS;
}
status = acpi_ut_execute_power_methods(node,
acpi_gbl_highest_dstate_names,
ACPI_NUM_sx_d_METHODS,
info->highest_dstates);
if (ACPI_SUCCESS(status)) {
valid |= ACPI_VALID_SXDS;
}
}
next_id_string = ACPI_CAST_PTR(char, info->compatible_id_list.ids);
if (cid_list) {
next_id_string +=
((acpi_size) cid_list->count *
sizeof(struct acpi_pnp_device_id));
}
if (hid) {
next_id_string = acpi_ns_copy_device_id(&info->hardware_id,
hid, next_id_string);
if (acpi_ut_is_pci_root_bridge(hid->string)) {
info->flags |= ACPI_PCI_ROOT_BRIDGE;
}
}
if (uid) {
next_id_string = acpi_ns_copy_device_id(&info->unique_id,
uid, next_id_string);
}
if (sub) {
next_id_string = acpi_ns_copy_device_id(&info->subsystem_id,
sub, next_id_string);
}
if (cid_list) {
info->compatible_id_list.count = cid_list->count;
info->compatible_id_list.list_size = cid_list->list_size;
for (i = 0; i < cid_list->count; i++) {
next_id_string =
acpi_ns_copy_device_id(&info->compatible_id_list.
ids[i], &cid_list->ids[i],
next_id_string);
if (acpi_ut_is_pci_root_bridge(cid_list->ids[i].string)) {
info->flags |= ACPI_PCI_ROOT_BRIDGE;
}
}
}
if (cls) {
next_id_string = acpi_ns_copy_device_id(&info->class_code,
cls, next_id_string);
}
info->info_size = info_size;
info->type = type;
info->name = name;
info->param_count = param_count;
info->valid = valid;
*return_buffer = info;
status = AE_OK;
cleanup:
if (hid) {
ACPI_FREE(hid);
}
if (uid) {
ACPI_FREE(uid);
}
if (sub) {
ACPI_FREE(sub);
}
if (cid_list) {
ACPI_FREE(cid_list);
}
if (cls) {
ACPI_FREE(cls);
}
return (status);
}
acpi_status acpi_install_method(u8 *buffer)
{
struct acpi_table_header *table =
ACPI_CAST_PTR(struct acpi_table_header, buffer);
u8 *aml_buffer;
u8 *aml_start;
char *path;
struct acpi_namespace_node *node;
union acpi_operand_object *method_obj;
struct acpi_parse_state parser_state;
u32 aml_length;
u16 opcode;
u8 method_flags;
acpi_status status;
if (!buffer) {
return (AE_BAD_PARAMETER);
}
if (!ACPI_COMPARE_NAME(table->signature, ACPI_SIG_DSDT) &&
!ACPI_COMPARE_NAME(table->signature, ACPI_SIG_SSDT)) {
return (AE_BAD_HEADER);
}
parser_state.aml = buffer + sizeof(struct acpi_table_header);
opcode = acpi_ps_peek_opcode(&parser_state);
if (opcode != AML_METHOD_OP) {
return (AE_BAD_PARAMETER);
}
parser_state.aml += acpi_ps_get_opcode_size(opcode);
parser_state.pkg_end = acpi_ps_get_next_package_end(&parser_state);
path = acpi_ps_get_next_namestring(&parser_state);
method_flags = *parser_state.aml++;
aml_start = parser_state.aml;
aml_length = ACPI_PTR_DIFF(parser_state.pkg_end, aml_start);
aml_buffer = ACPI_ALLOCATE(aml_length);
if (!aml_buffer) {
return (AE_NO_MEMORY);
}
method_obj = acpi_ut_create_internal_object(ACPI_TYPE_METHOD);
if (!method_obj) {
ACPI_FREE(aml_buffer);
return (AE_NO_MEMORY);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
status =
acpi_ns_lookup(NULL, path, ACPI_TYPE_METHOD, ACPI_IMODE_LOAD_PASS1,
ACPI_NS_DONT_OPEN_SCOPE | ACPI_NS_ERROR_IF_FOUND,
NULL, &node);
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
if (status != AE_ALREADY_EXISTS) {
goto error_exit;
}
if (node->type != ACPI_TYPE_METHOD) {
status = AE_TYPE;
goto error_exit;
}
}
memcpy(aml_buffer, aml_start, aml_length);
method_obj->method.aml_start = aml_buffer;
method_obj->method.aml_length = aml_length;
method_obj->method.param_count = (u8)
(method_flags & AML_METHOD_ARG_COUNT);
if (method_flags & AML_METHOD_SERIALIZED) {
method_obj->method.info_flags = ACPI_METHOD_SERIALIZED;
method_obj->method.sync_level = (u8)
((method_flags & AML_METHOD_SYNC_LEVEL) >> 4);
}
status = acpi_ns_attach_object(node, method_obj, ACPI_TYPE_METHOD);
node->flags |= ANOBJ_ALLOCATED_BUFFER;
acpi_ut_remove_reference(method_obj);
return (status);
error_exit:
ACPI_FREE(aml_buffer);
ACPI_FREE(method_obj);
return (status);
}
