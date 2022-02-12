acpi_status acpi_get_type(acpi_handle handle, acpi_object_type *ret_type)
{
struct acpi_namespace_node *node;
acpi_status status;
if (!ret_type) {
return (AE_BAD_PARAMETER);
}
if (handle == ACPI_ROOT_OBJECT) {
*ret_type = ACPI_TYPE_ANY;
return (AE_OK);
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
*ret_type = node->type;
status = acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
acpi_status acpi_get_parent(acpi_handle handle, acpi_handle *ret_handle)
{
struct acpi_namespace_node *node;
struct acpi_namespace_node *parent_node;
acpi_status status;
if (!ret_handle) {
return (AE_BAD_PARAMETER);
}
if (handle == ACPI_ROOT_OBJECT) {
return (AE_NULL_ENTRY);
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
parent_node = node->parent;
*ret_handle = ACPI_CAST_PTR(acpi_handle, parent_node);
if (!parent_node) {
status = AE_NULL_ENTRY;
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
acpi_status
acpi_get_next_object(acpi_object_type type,
acpi_handle parent,
acpi_handle child, acpi_handle *ret_handle)
{
acpi_status status;
struct acpi_namespace_node *node;
struct acpi_namespace_node *parent_node = NULL;
struct acpi_namespace_node *child_node = NULL;
if (type > ACPI_TYPE_EXTERNAL_MAX) {
return (AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_NAMESPACE);
if (ACPI_FAILURE(status)) {
return (status);
}
if (!child) {
parent_node = acpi_ns_validate_handle(parent);
if (!parent_node) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
} else {
child_node = acpi_ns_validate_handle(child);
if (!child_node) {
status = AE_BAD_PARAMETER;
goto unlock_and_exit;
}
}
node = acpi_ns_get_next_node_typed(type, parent_node, child_node);
if (!node) {
status = AE_NOT_FOUND;
goto unlock_and_exit;
}
if (ret_handle) {
*ret_handle = ACPI_CAST_PTR(acpi_handle, node);
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_NAMESPACE);
return (status);
}
