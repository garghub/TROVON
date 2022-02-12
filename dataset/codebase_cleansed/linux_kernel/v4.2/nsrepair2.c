acpi_status
acpi_ns_complex_repairs(struct acpi_evaluate_info *info,
struct acpi_namespace_node *node,
acpi_status validate_status,
union acpi_operand_object **return_object_ptr)
{
const struct acpi_repair_info *predefined;
acpi_status status;
predefined = acpi_ns_match_complex_repair(node);
if (!predefined) {
return (validate_status);
}
status = predefined->repair_function(info, return_object_ptr);
return (status);
}
static const struct acpi_repair_info *acpi_ns_match_complex_repair(struct
acpi_namespace_node
*node)
{
const struct acpi_repair_info *this_name;
this_name = acpi_ns_repairable_names;
while (this_name->repair_function) {
if (ACPI_COMPARE_NAME(node->name.ascii, this_name->name)) {
return (this_name);
}
this_name++;
}
return (NULL);
}
static acpi_status
acpi_ns_repair_ALR(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
acpi_status status;
status = acpi_ns_check_sorted_list(info, return_object, 0, 2, 1,
ACPI_SORT_ASCENDING,
"AmbientIlluminance");
return (status);
}
static acpi_status
acpi_ns_repair_FDE(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
union acpi_operand_object *buffer_object;
u8 *byte_buffer;
u32 *dword_buffer;
u32 i;
ACPI_FUNCTION_NAME(ns_repair_FDE);
switch (return_object->common.type) {
case ACPI_TYPE_BUFFER:
if (return_object->buffer.length >= ACPI_FDE_DWORD_BUFFER_SIZE) {
return (AE_OK);
}
if (return_object->buffer.length != ACPI_FDE_BYTE_BUFFER_SIZE) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"Incorrect return buffer length %u, expected %u",
return_object->buffer.length,
ACPI_FDE_DWORD_BUFFER_SIZE));
return (AE_AML_OPERAND_TYPE);
}
buffer_object =
acpi_ut_create_buffer_object(ACPI_FDE_DWORD_BUFFER_SIZE);
if (!buffer_object) {
return (AE_NO_MEMORY);
}
byte_buffer = return_object->buffer.pointer;
dword_buffer =
ACPI_CAST_PTR(u32, buffer_object->buffer.pointer);
for (i = 0; i < ACPI_FDE_FIELD_COUNT; i++) {
*dword_buffer = (u32) *byte_buffer;
dword_buffer++;
byte_buffer++;
}
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s Expanded Byte Buffer to expected DWord Buffer\n",
info->full_pathname));
break;
default:
return (AE_AML_OPERAND_TYPE);
}
acpi_ut_remove_reference(return_object);
*return_object_ptr = buffer_object;
info->return_flags |= ACPI_OBJECT_REPAIRED;
return (AE_OK);
}
static acpi_status
acpi_ns_repair_CID(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
acpi_status status;
union acpi_operand_object *return_object = *return_object_ptr;
union acpi_operand_object **element_ptr;
union acpi_operand_object *original_element;
u16 original_ref_count;
u32 i;
if (return_object->common.type == ACPI_TYPE_STRING) {
status = acpi_ns_repair_HID(info, return_object_ptr);
return (status);
}
if (return_object->common.type != ACPI_TYPE_PACKAGE) {
return (AE_OK);
}
element_ptr = return_object->package.elements;
for (i = 0; i < return_object->package.count; i++) {
original_element = *element_ptr;
original_ref_count = original_element->common.reference_count;
status = acpi_ns_repair_HID(info, element_ptr);
if (ACPI_FAILURE(status)) {
return (status);
}
if (original_element != *element_ptr) {
(*element_ptr)->common.reference_count =
original_ref_count;
acpi_ut_remove_reference(original_element);
}
element_ptr++;
}
return (AE_OK);
}
static acpi_status
acpi_ns_repair_CST(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
union acpi_operand_object **outer_elements;
u32 outer_element_count;
union acpi_operand_object *obj_desc;
acpi_status status;
u8 removing;
u32 i;
ACPI_FUNCTION_NAME(ns_repair_CST);
outer_element_count = return_object->package.count - 1;
i = 0;
while (i < outer_element_count) {
outer_elements = &return_object->package.elements[i + 1];
removing = FALSE;
if ((*outer_elements)->package.count == 0) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"SubPackage[%u] - removing entry due to zero count",
i));
removing = TRUE;
goto remove_element;
}
obj_desc = (*outer_elements)->package.elements[1];
if ((u32)obj_desc->integer.value == 0) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"SubPackage[%u] - removing entry due to invalid Type(0)",
i));
removing = TRUE;
}
remove_element:
if (removing) {
acpi_ns_remove_element(return_object, i + 1);
outer_element_count--;
} else {
i++;
}
}
obj_desc = return_object->package.elements[0];
obj_desc->integer.value = outer_element_count;
status = acpi_ns_check_sorted_list(info, return_object, 1, 4, 1,
ACPI_SORT_ASCENDING, "C-State Type");
if (ACPI_FAILURE(status)) {
return (status);
}
return (AE_OK);
}
static acpi_status
acpi_ns_repair_HID(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
union acpi_operand_object *new_string;
char *source;
char *dest;
ACPI_FUNCTION_NAME(ns_repair_HID);
if (return_object->common.type != ACPI_TYPE_STRING) {
return (AE_OK);
}
if (return_object->string.length == 0) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"Invalid zero-length _HID or _CID string"));
info->return_flags |= ACPI_OBJECT_REPAIRED;
return (AE_OK);
}
new_string = acpi_ut_create_string_object(return_object->string.length);
if (!new_string) {
return (AE_NO_MEMORY);
}
source = return_object->string.pointer;
if (*source == '*') {
source++;
new_string->string.length--;
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s: Removed invalid leading asterisk\n",
info->full_pathname));
}
for (dest = new_string->string.pointer; *source; dest++, source++) {
*dest = (char)toupper((int)*source);
}
acpi_ut_remove_reference(return_object);
*return_object_ptr = new_string;
return (AE_OK);
}
static acpi_status
acpi_ns_repair_PRT(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *package_object = *return_object_ptr;
union acpi_operand_object **top_object_list;
union acpi_operand_object **sub_object_list;
union acpi_operand_object *obj_desc;
union acpi_operand_object *sub_package;
u32 element_count;
u32 index;
top_object_list = package_object->package.elements;
element_count = package_object->package.count;
for (index = 0; index < element_count; index++, top_object_list++) {
sub_package = *top_object_list;
sub_object_list = sub_package->package.elements;
if (sub_package->package.count < 4) {
continue;
}
obj_desc = sub_object_list[3];
if (!obj_desc || (obj_desc->common.type != ACPI_TYPE_INTEGER)) {
sub_object_list[3] = sub_object_list[2];
sub_object_list[2] = obj_desc;
info->return_flags |= ACPI_OBJECT_REPAIRED;
ACPI_WARN_PREDEFINED((AE_INFO,
info->full_pathname,
info->node_flags,
"PRT[%X]: Fixed reversed SourceName and SourceIndex",
index));
}
}
return (AE_OK);
}
static acpi_status
acpi_ns_repair_PSS(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
union acpi_operand_object **outer_elements;
u32 outer_element_count;
union acpi_operand_object **elements;
union acpi_operand_object *obj_desc;
u32 previous_value;
acpi_status status;
u32 i;
status = acpi_ns_check_sorted_list(info, return_object, 0, 6, 0,
ACPI_SORT_DESCENDING,
"CpuFrequency");
if (ACPI_FAILURE(status)) {
return (status);
}
previous_value = ACPI_UINT32_MAX;
outer_elements = return_object->package.elements;
outer_element_count = return_object->package.count;
for (i = 0; i < outer_element_count; i++) {
elements = (*outer_elements)->package.elements;
obj_desc = elements[1];
if ((u32) obj_desc->integer.value > previous_value) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
info->node_flags,
"SubPackage[%u,%u] - suspicious power dissipation values",
i - 1, i));
}
previous_value = (u32) obj_desc->integer.value;
outer_elements++;
}
return (AE_OK);
}
static acpi_status
acpi_ns_repair_TSS(struct acpi_evaluate_info *info,
union acpi_operand_object **return_object_ptr)
{
union acpi_operand_object *return_object = *return_object_ptr;
acpi_status status;
struct acpi_namespace_node *node;
status = acpi_ns_get_node(info->node, "^_PSS",
ACPI_NS_NO_UPSEARCH, &node);
if (ACPI_SUCCESS(status)) {
return (AE_OK);
}
status = acpi_ns_check_sorted_list(info, return_object, 0, 5, 1,
ACPI_SORT_DESCENDING,
"PowerDissipation");
return (status);
}
static acpi_status
acpi_ns_check_sorted_list(struct acpi_evaluate_info *info,
union acpi_operand_object *return_object,
u32 start_index,
u32 expected_count,
u32 sort_index,
u8 sort_direction, char *sort_key_name)
{
u32 outer_element_count;
union acpi_operand_object **outer_elements;
union acpi_operand_object **elements;
union acpi_operand_object *obj_desc;
u32 i;
u32 previous_value;
ACPI_FUNCTION_NAME(ns_check_sorted_list);
if (return_object->common.type != ACPI_TYPE_PACKAGE) {
return (AE_AML_OPERAND_TYPE);
}
outer_element_count = return_object->package.count;
if (!outer_element_count || start_index >= outer_element_count) {
return (AE_AML_PACKAGE_LIMIT);
}
outer_elements = &return_object->package.elements[start_index];
outer_element_count -= start_index;
previous_value = 0;
if (sort_direction == ACPI_SORT_DESCENDING) {
previous_value = ACPI_UINT32_MAX;
}
for (i = 0; i < outer_element_count; i++) {
if ((*outer_elements)->common.type != ACPI_TYPE_PACKAGE) {
return (AE_AML_OPERAND_TYPE);
}
if ((*outer_elements)->package.count < expected_count) {
return (AE_AML_PACKAGE_LIMIT);
}
elements = (*outer_elements)->package.elements;
obj_desc = elements[sort_index];
if (obj_desc->common.type != ACPI_TYPE_INTEGER) {
return (AE_AML_OPERAND_TYPE);
}
if (((sort_direction == ACPI_SORT_ASCENDING) &&
(obj_desc->integer.value < previous_value)) ||
((sort_direction == ACPI_SORT_DESCENDING) &&
(obj_desc->integer.value > previous_value))) {
acpi_ns_sort_list(&return_object->package.
elements[start_index],
outer_element_count, sort_index,
sort_direction);
info->return_flags |= ACPI_OBJECT_REPAIRED;
ACPI_DEBUG_PRINT((ACPI_DB_REPAIR,
"%s: Repaired unsorted list - now sorted by %s\n",
info->full_pathname, sort_key_name));
return (AE_OK);
}
previous_value = (u32) obj_desc->integer.value;
outer_elements++;
}
return (AE_OK);
}
static void
acpi_ns_sort_list(union acpi_operand_object **elements,
u32 count, u32 index, u8 sort_direction)
{
union acpi_operand_object *obj_desc1;
union acpi_operand_object *obj_desc2;
union acpi_operand_object *temp_obj;
u32 i;
u32 j;
for (i = 1; i < count; i++) {
for (j = (count - 1); j >= i; j--) {
obj_desc1 = elements[j - 1]->package.elements[index];
obj_desc2 = elements[j]->package.elements[index];
if (((sort_direction == ACPI_SORT_ASCENDING) &&
(obj_desc1->integer.value >
obj_desc2->integer.value))
|| ((sort_direction == ACPI_SORT_DESCENDING)
&& (obj_desc1->integer.value <
obj_desc2->integer.value))) {
temp_obj = elements[j - 1];
elements[j - 1] = elements[j];
elements[j] = temp_obj;
}
}
}
}
static void
acpi_ns_remove_element(union acpi_operand_object *obj_desc, u32 index)
{
union acpi_operand_object **source;
union acpi_operand_object **dest;
u32 count;
u32 new_count;
u32 i;
ACPI_FUNCTION_NAME(ns_remove_element);
count = obj_desc->package.count;
new_count = count - 1;
source = obj_desc->package.elements;
dest = source;
for (i = 0; i < count; i++) {
if (i == index) {
acpi_ut_remove_reference(*source);
acpi_ut_remove_reference(*source);
} else {
*dest = *source;
dest++;
}
source++;
}
*dest = NULL;
obj_desc->package.count = new_count;
}
