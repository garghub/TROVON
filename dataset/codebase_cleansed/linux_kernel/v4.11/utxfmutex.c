static acpi_status
acpi_ut_get_mutex_object(acpi_handle handle,
acpi_string pathname,
union acpi_operand_object **ret_obj)
{
struct acpi_namespace_node *mutex_node;
union acpi_operand_object *mutex_obj;
acpi_status status;
if (!ret_obj || (!handle && !pathname)) {
return (AE_BAD_PARAMETER);
}
mutex_node = handle;
if (pathname != NULL) {
status =
acpi_get_handle(handle, pathname,
ACPI_CAST_PTR(acpi_handle, &mutex_node));
if (ACPI_FAILURE(status)) {
return (status);
}
}
if (!mutex_node || (mutex_node->type != ACPI_TYPE_MUTEX)) {
return (AE_TYPE);
}
mutex_obj = acpi_ns_get_attached_object(mutex_node);
if (!mutex_obj) {
return (AE_NULL_OBJECT);
}
*ret_obj = mutex_obj;
return (AE_OK);
}
acpi_status
acpi_acquire_mutex(acpi_handle handle, acpi_string pathname, u16 timeout)
{
acpi_status status;
union acpi_operand_object *mutex_obj;
status = acpi_ut_get_mutex_object(handle, pathname, &mutex_obj);
if (ACPI_FAILURE(status)) {
return (status);
}
status = acpi_os_acquire_mutex(mutex_obj->mutex.os_mutex, timeout);
return (status);
}
acpi_status acpi_release_mutex(acpi_handle handle, acpi_string pathname)
{
acpi_status status;
union acpi_operand_object *mutex_obj;
status = acpi_ut_get_mutex_object(handle, pathname, &mutex_obj);
if (ACPI_FAILURE(status)) {
return (status);
}
acpi_os_release_mutex(mutex_obj->mutex.os_mutex);
return (AE_OK);
}
