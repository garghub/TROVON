acpi_status
acpi_ns_check_return_value(struct acpi_namespace_node *node,
struct acpi_evaluate_info *info,
u32 user_param_count,
acpi_status return_status,
union acpi_operand_object **return_object_ptr)
{
acpi_status status;
const union acpi_predefined_info *predefined;
predefined = info->predefined;
if (!predefined) {
return (AE_OK);
}
if ((return_status != AE_OK) && (return_status != AE_CTRL_RETURN_VALUE)) {
return (AE_OK);
}
if (acpi_gbl_disable_auto_repair ||
(!predefined->info.expected_btypes) ||
(predefined->info.expected_btypes == ACPI_RTYPE_ALL)) {
return (AE_OK);
}
status = acpi_ns_check_object_type(info, return_object_ptr,
predefined->info.expected_btypes,
ACPI_NOT_PACKAGE_ELEMENT);
if (ACPI_FAILURE(status)) {
goto exit;
}
if (!(*return_object_ptr)) {
goto exit;
}
if ((*return_object_ptr)->common.type == ACPI_TYPE_PACKAGE) {
info->parent_package = *return_object_ptr;
status = acpi_ns_check_package(info, return_object_ptr);
if (ACPI_FAILURE(status)) {
if ((status != AE_AML_OPERAND_TYPE) &&
(status != AE_AML_OPERAND_VALUE)) {
goto exit;
}
}
}
status = acpi_ns_complex_repairs(info, node, status, return_object_ptr);
exit:
if (ACPI_FAILURE(status) || (info->return_flags & ACPI_OBJECT_REPAIRED)) {
node->flags |= ANOBJ_EVALUATED;
}
return (status);
}
acpi_status
acpi_ns_check_object_type(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr,
u32 expected_btypes, u32 package_index)
{
union acpi_operand_object *return_object = *return_object_ptr;
acpi_status status = AE_OK;
char type_buffer[48];
if (return_object &&
ACPI_GET_DESCRIPTOR_TYPE(return_object) == ACPI_DESC_TYPE_NAMED) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"Invalid return type - Found a Namespace node [%4.4s] type %s",
return_object->node.name.ascii,
acpi_ut_get_type_name(return_object->node.
type)));
return (AE_AML_OPERAND_TYPE);
}
info->return_btype = acpi_ns_get_bitmapped_type(return_object);
if (info->return_btype == ACPI_RTYPE_ANY) {
goto type_error_exit;
}
if ((info->return_btype & expected_btypes) == ACPI_RTYPE_REFERENCE) {
status = acpi_ns_check_reference(info, return_object);
return (status);
}
status = acpi_ns_simple_repair(info, expected_btypes,
package_index, return_object_ptr);
if (ACPI_SUCCESS(status)) {
return (AE_OK);
}
type_error_exit:
acpi_ut_get_expected_return_types(type_buffer, expected_btypes);
if (!return_object) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"Expected return object of type %s",
type_buffer));
} else if (package_index == ACPI_NOT_PACKAGE_ELEMENT) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"Return type mismatch - found %s, expected %s",
acpi_ut_get_object_type_name
(return_object), type_buffer));
} else {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"Return Package type mismatch at index %u - "
"found %s, expected %s", package_index,
acpi_ut_get_object_type_name
(return_object), type_buffer));
}
return (AE_AML_OPERAND_TYPE);
}
static acpi_status
acpi_ns_check_reference(struct acpi_evaluate_info *info,
union acpi_operand_object *return_object)
{
if (return_object->reference.class == ACPI_REFCLASS_NAME) {
return (AE_OK);
}
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname, info->node_flags,
"Return type mismatch - unexpected reference object type [%s] %2.2X",
acpi_ut_get_reference_name(return_object),
return_object->reference.class));
return (AE_AML_OPERAND_TYPE);
}
static u32 acpi_ns_get_bitmapped_type(union acpi_operand_object *return_object)
{
u32 return_btype;
if (!return_object) {
return (ACPI_RTYPE_NONE);
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
return_btype = ACPI_RTYPE_ANY;
break;
}
return (return_btype);
}
