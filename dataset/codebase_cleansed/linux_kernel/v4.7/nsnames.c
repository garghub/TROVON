char *acpi_ns_get_external_pathname(struct acpi_namespace_node *node)
{
char *name_buffer;
ACPI_FUNCTION_TRACE_PTR(ns_get_external_pathname, node);
name_buffer = acpi_ns_get_normalized_pathname(node, FALSE);
return_PTR(name_buffer);
}
acpi_size acpi_ns_get_pathname_length(struct acpi_namespace_node *node)
{
acpi_size size;
ACPI_FUNCTION_ENTRY();
size = acpi_ns_build_normalized_path(node, NULL, 0, FALSE);
return (size);
}
acpi_status
acpi_ns_handle_to_pathname(acpi_handle target_handle,
struct acpi_buffer *buffer, u8 no_trailing)
{
acpi_status status;
struct acpi_namespace_node *node;
acpi_size required_size;
ACPI_FUNCTION_TRACE_PTR(ns_handle_to_pathname, target_handle);
node = acpi_ns_validate_handle(target_handle);
if (!node) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
required_size =
acpi_ns_build_normalized_path(node, NULL, 0, no_trailing);
if (!required_size) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_initialize_buffer(buffer, required_size);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
(void)acpi_ns_build_normalized_path(node, buffer->pointer,
required_size, no_trailing);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "%s [%X]\n",
(char *)buffer->pointer, (u32) required_size));
return_ACPI_STATUS(AE_OK);
}
u32
acpi_ns_build_normalized_path(struct acpi_namespace_node *node,
char *full_path, u32 path_size, u8 no_trailing)
{
u32 length = 0, i;
char name[ACPI_NAME_SIZE];
u8 do_no_trailing;
char c, *left, *right;
struct acpi_namespace_node *next_node;
ACPI_FUNCTION_TRACE_PTR(ns_build_normalized_path, node);
#define ACPI_PATH_PUT8(path, size, byte, length) \
do { \
if ((length) < (size)) \
{ \
(path)[(length)] = (byte); \
} \
(length)++; \
} while (0)
if (!full_path) {
path_size = 0;
}
if (!node) {
goto build_trailing_null;
}
next_node = node;
while (next_node && next_node != acpi_gbl_root_node) {
if (next_node != node) {
ACPI_PATH_PUT8(full_path, path_size,
AML_DUAL_NAME_PREFIX, length);
}
ACPI_MOVE_32_TO_32(name, &next_node->name);
do_no_trailing = no_trailing;
for (i = 0; i < 4; i++) {
c = name[4 - i - 1];
if (do_no_trailing && c != '_') {
do_no_trailing = FALSE;
}
if (!do_no_trailing) {
ACPI_PATH_PUT8(full_path, path_size, c, length);
}
}
next_node = next_node->parent;
}
ACPI_PATH_PUT8(full_path, path_size, AML_ROOT_PREFIX, length);
if (length <= path_size) {
left = full_path;
right = full_path + length - 1;
while (left < right) {
c = *left;
*left++ = *right;
*right-- = c;
}
}
build_trailing_null:
ACPI_PATH_PUT8(full_path, path_size, '\0', length);
#undef ACPI_PATH_PUT8
return_UINT32(length);
}
char *acpi_ns_get_normalized_pathname(struct acpi_namespace_node *node,
u8 no_trailing)
{
char *name_buffer;
acpi_size size;
ACPI_FUNCTION_TRACE_PTR(ns_get_normalized_pathname, node);
size = acpi_ns_build_normalized_path(node, NULL, 0, no_trailing);
if (!size) {
return_PTR(NULL);
}
name_buffer = ACPI_ALLOCATE_ZEROED(size);
if (!name_buffer) {
ACPI_ERROR((AE_INFO, "Could not allocate %u bytes", (u32)size));
return_PTR(NULL);
}
(void)acpi_ns_build_normalized_path(node, name_buffer, size,
no_trailing);
return_PTR(name_buffer);
}
