void acpi_ns_check_argument_types(struct acpi_evaluate_info *info)
{
u16 arg_type_list;
u8 arg_count;
u8 arg_type;
u8 user_arg_type;
u32 i;
if (!info->predefined) {
return;
}
arg_type_list = info->predefined->info.argument_list;
arg_count = METHOD_GET_ARG_COUNT(arg_type_list);
for (i = 0; ((i < arg_count) && (i < info->param_count)); i++) {
arg_type = METHOD_GET_NEXT_TYPE(arg_type_list);
user_arg_type = info->parameters[i]->common.type;
if (user_arg_type != arg_type) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
ACPI_WARN_ALWAYS,
"Argument #%u type mismatch - "
"Found [%s], ACPI requires [%s]",
(i + 1),
acpi_ut_get_type_name
(user_arg_type),
acpi_ut_get_type_name(arg_type)));
}
}
}
void
acpi_ns_check_acpi_compliance(char *pathname,
struct acpi_namespace_node *node,
const union acpi_predefined_info *predefined)
{
u32 aml_param_count;
u32 required_param_count;
if (!predefined) {
return;
}
required_param_count =
METHOD_GET_ARG_COUNT(predefined->info.argument_list);
if (node->type != ACPI_TYPE_METHOD) {
if (required_param_count > 0) {
ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Object (%s) must be a control method with %u arguments",
acpi_ut_get_type_name(node->
type),
required_param_count));
} else if (!required_param_count
&& !predefined->info.expected_btypes) {
ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Object (%s) must be a control method "
"with no arguments and no return value",
acpi_ut_get_type_name(node->
type)));
}
return;
}
aml_param_count = node->object->method.param_count;
if (aml_param_count < required_param_count) {
ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
"Insufficient arguments - "
"ASL declared %u, ACPI requires %u",
aml_param_count,
required_param_count));
} else if ((aml_param_count > required_param_count)
&& !(predefined->info.
argument_list & ARG_COUNT_IS_MINIMUM)) {
ACPI_BIOS_ERROR_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
"Excess arguments - "
"ASL declared %u, ACPI requires %u",
aml_param_count,
required_param_count));
}
}
void
acpi_ns_check_argument_count(char *pathname,
struct acpi_namespace_node *node,
u32 user_param_count,
const union acpi_predefined_info *predefined)
{
u32 aml_param_count;
u32 required_param_count;
if (!predefined) {
if (node->type != ACPI_TYPE_METHOD) {
if (user_param_count) {
ACPI_INFO_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"%u arguments were passed to a non-method ACPI object (%s)",
user_param_count,
acpi_ut_get_type_name
(node->type)));
}
return;
}
aml_param_count = node->object->method.param_count;
if (user_param_count < aml_param_count) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Insufficient arguments - "
"Caller passed %u, method requires %u",
user_param_count,
aml_param_count));
} else if (user_param_count > aml_param_count) {
ACPI_INFO_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Excess arguments - "
"Caller passed %u, method requires %u",
user_param_count,
aml_param_count));
}
return;
}
required_param_count =
METHOD_GET_ARG_COUNT(predefined->info.argument_list);
if (user_param_count < required_param_count) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
"Insufficient arguments - "
"Caller passed %u, ACPI requires %u",
user_param_count, required_param_count));
} else if ((user_param_count > required_param_count) &&
!(predefined->info.argument_list & ARG_COUNT_IS_MINIMUM)) {
ACPI_INFO_PREDEFINED((AE_INFO, pathname, ACPI_WARN_ALWAYS,
"Excess arguments - "
"Caller passed %u, ACPI requires %u",
user_param_count, required_param_count));
}
}
