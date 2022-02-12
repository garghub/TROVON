void ACPI_INTERNAL_VAR_XFACE
acpi_error(const char *module_name, u32 line_number, const char *format, ...)
{
va_list arg_list;
ACPI_MSG_REDIRECT_BEGIN;
acpi_os_printf(ACPI_MSG_ERROR);
va_start(arg_list, format);
acpi_os_vprintf(format, arg_list);
ACPI_MSG_SUFFIX;
va_end(arg_list);
ACPI_MSG_REDIRECT_END;
}
void ACPI_INTERNAL_VAR_XFACE
acpi_exception(const char *module_name,
u32 line_number, acpi_status status, const char *format, ...)
{
va_list arg_list;
ACPI_MSG_REDIRECT_BEGIN;
acpi_os_printf(ACPI_MSG_EXCEPTION "%s, ",
acpi_format_exception(status));
va_start(arg_list, format);
acpi_os_vprintf(format, arg_list);
ACPI_MSG_SUFFIX;
va_end(arg_list);
ACPI_MSG_REDIRECT_END;
}
void ACPI_INTERNAL_VAR_XFACE
acpi_warning(const char *module_name, u32 line_number, const char *format, ...)
{
va_list arg_list;
ACPI_MSG_REDIRECT_BEGIN;
acpi_os_printf(ACPI_MSG_WARNING);
va_start(arg_list, format);
acpi_os_vprintf(format, arg_list);
ACPI_MSG_SUFFIX;
va_end(arg_list);
ACPI_MSG_REDIRECT_END;
}
void ACPI_INTERNAL_VAR_XFACE
acpi_info(const char *module_name, u32 line_number, const char *format, ...)
{
va_list arg_list;
ACPI_MSG_REDIRECT_BEGIN;
acpi_os_printf(ACPI_MSG_INFO);
va_start(arg_list, format);
acpi_os_vprintf(format, arg_list);
acpi_os_printf("\n");
va_end(arg_list);
ACPI_MSG_REDIRECT_END;
}
void ACPI_INTERNAL_VAR_XFACE
acpi_ut_predefined_warning(const char *module_name,
u32 line_number,
char *pathname,
u8 node_flags, const char *format, ...)
{
va_list arg_list;
if (node_flags & ANOBJ_EVALUATED) {
return;
}
acpi_os_printf(ACPI_MSG_WARNING "For %s: ", pathname);
va_start(arg_list, format);
acpi_os_vprintf(format, arg_list);
ACPI_MSG_SUFFIX;
va_end(arg_list);
}
void ACPI_INTERNAL_VAR_XFACE
acpi_ut_predefined_info(const char *module_name,
u32 line_number,
char *pathname, u8 node_flags, const char *format, ...)
{
va_list arg_list;
if (node_flags & ANOBJ_EVALUATED) {
return;
}
acpi_os_printf(ACPI_MSG_INFO "For %s: ", pathname);
va_start(arg_list, format);
acpi_os_vprintf(format, arg_list);
ACPI_MSG_SUFFIX;
va_end(arg_list);
}
void
acpi_ut_namespace_error(const char *module_name,
u32 line_number,
const char *internal_name, acpi_status lookup_status)
{
acpi_status status;
u32 bad_name;
char *name = NULL;
ACPI_MSG_REDIRECT_BEGIN;
acpi_os_printf(ACPI_MSG_ERROR);
if (lookup_status == AE_BAD_CHARACTER) {
ACPI_MOVE_32_TO_32(&bad_name,
ACPI_CAST_PTR(u32, internal_name));
acpi_os_printf("[0x%4.4X] (NON-ASCII)", bad_name);
} else {
status = acpi_ns_externalize_name(ACPI_UINT32_MAX,
internal_name, NULL, &name);
if (ACPI_SUCCESS(status)) {
acpi_os_printf("[%s]", name);
} else {
acpi_os_printf("[COULD NOT EXTERNALIZE NAME]");
}
if (name) {
ACPI_FREE(name);
}
}
acpi_os_printf(" Namespace lookup failure, %s",
acpi_format_exception(lookup_status));
ACPI_MSG_SUFFIX;
ACPI_MSG_REDIRECT_END;
}
void
acpi_ut_method_error(const char *module_name,
u32 line_number,
const char *message,
struct acpi_namespace_node *prefix_node,
const char *path, acpi_status method_status)
{
acpi_status status;
struct acpi_namespace_node *node = prefix_node;
ACPI_MSG_REDIRECT_BEGIN;
acpi_os_printf(ACPI_MSG_ERROR);
if (path) {
status =
acpi_ns_get_node(prefix_node, path, ACPI_NS_NO_UPSEARCH,
&node);
if (ACPI_FAILURE(status)) {
acpi_os_printf("[Could not get node by pathname]");
}
}
acpi_ns_print_node_pathname(node, message);
acpi_os_printf(", %s", acpi_format_exception(method_status));
ACPI_MSG_SUFFIX;
ACPI_MSG_REDIRECT_END;
}
