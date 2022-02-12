acpi_status
acpi_ns_simple_repair(struct acpi_evaluate_info *info,
u32 expected_btypes,
u32 package_index,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
union acpi_operand_object *new_object = NULL;
acpi_status status;
const struct acpi_simple_repair_info *predefined;
ACPI_FUNCTION_NAME(ns_simple_repair);
predefined = acpi_ns_match_simple_repair(info->node,
info->return_btype,
package_index);
if (predefined) {
if (!return_object) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
ACPI_WARN_ALWAYS,
"Missing expected return value"));
}
status =
predefined->object_converter(return_object, &new_object);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"During return object analysis"));
return (status);
}
if (new_object) {
goto object_repaired;
}
}
if (info->return_btype & expected_btypes) {
return (AE_OK);
}
if (!return_object) {
if (expected_btypes && (!(expected_btypes & ACPI_RTYPE_NONE))) {
if (package_index != ACPI_NOT_PACKAGE_ELEMENT) {
ACPI_WARN_PREDEFINED((AE_INFO,
info->full_pathname,
ACPI_WARN_ALWAYS,
"Found unexpected NULL package element"));
status =
acpi_ns_repair_null_element(info,
expected_btypes,
package_index,
return_object_ptr);
if (ACPI_SUCCESS(status)) {
return (AE_OK);
}
} else {
ACPI_WARN_PREDEFINED((AE_INFO,
info->full_pathname,
ACPI_WARN_ALWAYS,
"Missing expected return value"));
}
return (AE_AML_NO_RETURN_VALUE);
}
}
if (expected_btypes & ACPI_RTYPE_INTEGER) {
status = acpi_ns_convert_to_integer(return_object, &new_object);
if (ACPI_SUCCESS(status)) {
goto object_repaired;
}
}
if (expected_btypes & ACPI_RTYPE_STRING) {
status = acpi_ns_convert_to_string(return_object, &new_object);
if (ACPI_SUCCESS(status)) {
goto object_repaired;
}
}
if (expected_btypes & ACPI_RTYPE_BUFFER) {
status = acpi_ns_convert_to_buffer(return_object, &new_object);
if (ACPI_SUCCESS(status)) {
goto object_repaired;
}
}
if (expected_btypes & ACPI_RTYPE_PACKAGE) {
status =
acpi_ns_wrap_with_package(info, return_object, &new_object);
if (ACPI_SUCCESS(status)) {
*return_object_ptr = new_object;
info->return_flags |= ACPI_OBJECT_REPAIRED;
return (AE_OK);
}
}
return (AE_AML_OPERAND_TYPE);
object_repaired:
if (package_index != ACPI_NOT_PACKAGE_ELEMENT) {
if (!(info->return_flags & ACPI_OBJECT_WRAPPED)) {
new_object->common.reference_count =
return_object->common.reference_count;
if (return_object->common.reference_count > 1) {
return_object->common.reference_count--;
}
}
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s: Converted %s to expected %s at Package index %u\n",
info->full_pathname,
acpi_ut_get_object_type_name(return_object),
acpi_ut_get_object_type_name(new_object),
package_index));
} else {
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s: Converted %s to expected %s\n",
info->full_pathname,
acpi_ut_get_object_type_name(return_object),
acpi_ut_get_object_type_name(new_object)));
}
acpi_ut_remove_reference(return_object);
*return_object_ptr = new_object;
info->return_flags |= ACPI_OBJECT_REPAIRED;
return (AE_OK);
}
static const struct acpi_simple_repair_info *acpi_ns_match_simple_repair(struct
acpi_namespace_node
*node,
u32
return_btype,
u32
package_index)
{
const struct acpi_simple_repair_info *this_name;
this_name = acpi_object_repair_info;
while (this_name->object_converter) {
if (ACPI_COMPARE_NAME(node->name.ascii, this_name->name)) {
if ((return_btype & this_name->unexpected_btypes) &&
(package_index == this_name->package_index)) {
return (this_name);
}
return (NULL);
}
this_name++;
}
return (NULL);
}
acpi_status
acpi_ns_repair_null_element(struct acpi_evaluate_info * info,
u32 expected_btypes,
u32 package_index,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
union acpi_operand_object *new_object;
ACPI_FUNCTION_NAME(ns_repair_null_element);
if (return_object) {
return (AE_OK);
}
if (expected_btypes & ACPI_RTYPE_INTEGER) {
new_object = acpi_ut_create_integer_object((u64)0);
} else if (expected_btypes & ACPI_RTYPE_STRING) {
new_object = acpi_ut_create_string_object(0);
} else if (expected_btypes & ACPI_RTYPE_BUFFER) {
new_object = acpi_ut_create_buffer_object(0);
} else {
return (AE_AML_OPERAND_TYPE);
}
if (!new_object) {
return (AE_NO_MEMORY);
}
new_object->common.reference_count =
info->parent_package->common.reference_count;
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s: Converted NULL package element to expected %s at index %u\n",
info->full_pathname,
acpi_ut_get_object_type_name(new_object),
package_index));
*return_object_ptr = new_object;
info->return_flags |= ACPI_OBJECT_REPAIRED;
return (AE_OK);
}
void
acpi_ns_remove_null_elements(struct acpi_evaluate_info *info,
u8 package_type,
union acpi_operand_object *obj_desc)
{
union acpi_operand_object **source;
union acpi_operand_object **dest;
u32 count;
u32 new_count;
u32 i;
ACPI_FUNCTION_NAME(ns_remove_null_elements);
switch (package_type) {
case ACPI_PTYPE1_VAR:
case ACPI_PTYPE2:
case ACPI_PTYPE2_COUNT:
case ACPI_PTYPE2_PKG_COUNT:
case ACPI_PTYPE2_FIXED:
case ACPI_PTYPE2_MIN:
case ACPI_PTYPE2_REV_FIXED:
case ACPI_PTYPE2_FIX_VAR:
break;
default:
case ACPI_PTYPE2_VAR_VAR:
case ACPI_PTYPE1_FIXED:
case ACPI_PTYPE1_OPTION:
return;
}
count = obj_desc->package.count;
new_count = count;
source = obj_desc->package.elements;
dest = source;
for (i = 0; i < count; i++) {
if (!*source) {
new_count--;
} else {
*dest = *source;
dest++;
}
source++;
}
if (new_count < count) {
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s: Found and removed %u NULL elements\n",
info->full_pathname, (count - new_count)));
*dest = NULL;
obj_desc->package.count = new_count;
}
}
acpi_status
acpi_ns_wrap_with_package(struct acpi_evaluate_info *info,
union acpi_operand_object *original_object,
union acpi_operand_object **obj_desc_ptr)
{
union acpi_operand_object *pkg_obj_desc;
ACPI_FUNCTION_NAME(ns_wrap_with_package);
pkg_obj_desc = acpi_ut_create_package_object(1);
if (!pkg_obj_desc) {
return (AE_NO_MEMORY);
}
pkg_obj_desc->package.elements[0] = original_object;
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s: Wrapped %s with expected Package object\n",
info->full_pathname,
acpi_ut_get_object_type_name(original_object)));
*obj_desc_ptr = pkg_obj_desc;
info->return_flags |= ACPI_OBJECT_REPAIRED | ACPI_OBJECT_WRAPPED;
return (AE_OK);
}
