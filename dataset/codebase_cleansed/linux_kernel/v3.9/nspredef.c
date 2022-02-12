acpi_status
acpi_ns_check_predefined_names(struct acpi_namespace_node *node,
u32 user_param_count,
acpi_status return_status,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
acpi_status status = AE_OK;
const union acpi_predefined_info *predefined;
char *pathname;
struct acpi_predefined_data *data;
predefined = acpi_ns_check_for_predefined_name(node);
pathname = acpi_ns_get_external_pathname(node);
if (!pathname) {
return (AE_OK);
}
acpi_ns_check_parameter_count(pathname, node, user_param_count,
predefined);
if (!predefined) {
goto cleanup;
}
if ((return_status != AE_OK) && (return_status != AE_CTRL_RETURN_VALUE)) {
goto cleanup;
}
if (!return_object) {
if ((predefined->info.expected_btypes) &&
(!(predefined->info.expected_btypes & ACPI_RTYPE_NONE))) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Missing expected return value"));
status = AE_AML_NO_RETURN_VALUE;
}
goto cleanup;
}
if (acpi_gbl_disable_auto_repair ||
(!predefined->info.expected_btypes) ||
(predefined->info.expected_btypes == ACPI_RTYPE_ALL)) {
goto cleanup;
}
data = ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_predefined_data));
if (!data) {
goto cleanup;
}
data->predefined = predefined;
data->node = node;
data->node_flags = node->flags;
data->pathname = pathname;
status = acpi_ns_check_object_type(data, return_object_ptr,
predefined->info.expected_btypes,
ACPI_NOT_PACKAGE_ELEMENT);
if (ACPI_FAILURE(status)) {
goto exit;
}
if ((*return_object_ptr)->common.type == ACPI_TYPE_PACKAGE) {
data->parent_package = *return_object_ptr;
status = acpi_ns_check_package(data, return_object_ptr);
if (ACPI_FAILURE(status)) {
goto exit;
}
}
status = acpi_ns_complex_repairs(data, node, status, return_object_ptr);
exit:
if (ACPI_FAILURE(status) || (data->flags & ACPI_OBJECT_REPAIRED)) {
node->flags |= ANOBJ_EVALUATED;
}
ACPI_FREE(data);
cleanup:
ACPI_FREE(pathname);
return (status);
}
void
acpi_ns_check_parameter_count(char *pathname,
struct acpi_namespace_node *node,
u32 user_param_count,
const union acpi_predefined_info *predefined)
{
u32 param_count;
u32 required_params_current;
u32 required_params_old;
param_count = 0;
if (node->type == ACPI_TYPE_METHOD) {
param_count = node->object->method.param_count;
}
if (!predefined) {
if (user_param_count < param_count) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Insufficient arguments - needs %u, found %u",
param_count, user_param_count));
} else if (user_param_count > param_count) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Excess arguments - needs %u, found %u",
param_count, user_param_count));
}
return;
}
required_params_current = predefined->info.param_count & 0x0F;
required_params_old = predefined->info.param_count >> 4;
if (user_param_count != ACPI_UINT32_MAX) {
if ((user_param_count != required_params_current) &&
(user_param_count != required_params_old)) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname,
ACPI_WARN_ALWAYS,
"Parameter count mismatch - "
"caller passed %u, ACPI requires %u",
user_param_count,
required_params_current));
}
}
if ((param_count != required_params_current) &&
(param_count != required_params_old)) {
ACPI_WARN_PREDEFINED((AE_INFO, pathname, node->flags,
"Parameter count mismatch - ASL declared %u, ACPI requires %u",
param_count, required_params_current));
}
}
const union acpi_predefined_info *acpi_ns_check_for_predefined_name(struct
acpi_namespace_node
*node)
{
const union acpi_predefined_info *this_name;
if (node->name.ascii[0] != '_') {
return (NULL);
}
this_name = predefined_names;
while (this_name->info.name[0]) {
if (ACPI_COMPARE_NAME(node->name.ascii, this_name->info.name)) {
return (this_name);
}
if (this_name->info.expected_btypes & ACPI_RTYPE_PACKAGE) {
this_name++;
}
this_name++;
}
return (NULL);
}
acpi_status
acpi_ns_check_object_type(struct acpi_predefined_data *data,
union acpi_operand_object **return_object_ptr,
u32 expected_btypes, u32 package_index)
{
union acpi_operand_object *return_object = *return_object_ptr;
acpi_status status = AE_OK;
u32 return_btype;
char type_buffer[48];
if (!return_object) {
status = acpi_ns_repair_null_element(data, expected_btypes,
package_index,
return_object_ptr);
if (ACPI_SUCCESS(status)) {
return (AE_OK);
}
goto type_error_exit;
}
if (ACPI_GET_DESCRIPTOR_TYPE(return_object) == ACPI_DESC_TYPE_NAMED) {
ACPI_WARN_PREDEFINED((AE_INFO, data->pathname, data->node_flags,
"Invalid return type - Found a Namespace node [%4.4s] type %s",
return_object->node.name.ascii,
acpi_ut_get_type_name(return_object->node.
type)));
return (AE_AML_OPERAND_TYPE);
}
switch (return_object->common.type) {
case ACPI_TYPE_INTEGER:
return_btype = ACPI_RTYPE_INTEGER;
break;
case ACPI_TYPE_BUFFER:
return_btype = ACPI_RTYPE_BUFFER;
break;
case ACPI_TYPE_STRING:
return_btype = ACPI_RTYPE_STRING;
break;
case ACPI_TYPE_PACKAGE:
return_btype = ACPI_RTYPE_PACKAGE;
break;
case ACPI_TYPE_LOCAL_REFERENCE:
return_btype = ACPI_RTYPE_REFERENCE;
break;
default:
goto type_error_exit;
}
if (return_btype & expected_btypes) {
if (return_object->common.type == ACPI_TYPE_LOCAL_REFERENCE) {
status = acpi_ns_check_reference(data, return_object);
}
return (status);
}
status = acpi_ns_repair_object(data, expected_btypes,
package_index, return_object_ptr);
if (ACPI_SUCCESS(status)) {
return (AE_OK);
}
type_error_exit:
acpi_ns_get_expected_types(type_buffer, expected_btypes);
if (package_index == ACPI_NOT_PACKAGE_ELEMENT) {
ACPI_WARN_PREDEFINED((AE_INFO, data->pathname, data->node_flags,
"Return type mismatch - found %s, expected %s",
acpi_ut_get_object_type_name
(return_object), type_buffer));
} else {
ACPI_WARN_PREDEFINED((AE_INFO, data->pathname, data->node_flags,
"Return Package type mismatch at index %u - "
"found %s, expected %s", package_index,
acpi_ut_get_object_type_name
(return_object), type_buffer));
}
return (AE_AML_OPERAND_TYPE);
}
static acpi_status
acpi_ns_check_reference(struct acpi_predefined_data *data,
union acpi_operand_object *return_object)
{
if (return_object->reference.class == ACPI_REFCLASS_NAME) {
return (AE_OK);
}
ACPI_WARN_PREDEFINED((AE_INFO, data->pathname, data->node_flags,
"Return type mismatch - unexpected reference object type [%s] %2.2X",
acpi_ut_get_reference_name(return_object),
return_object->reference.class));
return (AE_AML_OPERAND_TYPE);
}
static void acpi_ns_get_expected_types(char *buffer, u32 expected_btypes)
{
u32 this_rtype;
u32 i;
u32 j;
j = 1;
buffer[0] = 0;
this_rtype = ACPI_RTYPE_INTEGER;
for (i = 0; i < ACPI_NUM_RTYPES; i++) {
if (expected_btypes & this_rtype) {
ACPI_STRCAT(buffer, &acpi_rtype_names[i][j]);
j = 0;
}
this_rtype <<= 1;
}
}
