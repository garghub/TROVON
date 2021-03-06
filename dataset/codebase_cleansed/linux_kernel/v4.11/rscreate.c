acpi_status
acpi_buffer_to_resource(u8 *aml_buffer,
u16 aml_buffer_length,
struct acpi_resource **resource_ptr)
{
acpi_status status;
acpi_size list_size_needed;
void *resource;
void *current_resource_ptr;
ACPI_FUNCTION_TRACE(acpi_buffer_to_resource);
status =
acpi_rs_get_list_length(aml_buffer, aml_buffer_length,
&list_size_needed);
if (status == AE_AML_NO_RESOURCE_END_TAG) {
status = AE_OK;
}
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
resource = ACPI_ALLOCATE_ZEROED(list_size_needed);
current_resource_ptr = resource;
if (!resource) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
status = acpi_ut_walk_aml_resources(NULL, aml_buffer, aml_buffer_length,
acpi_rs_convert_aml_to_resources,
&current_resource_ptr);
if (status == AE_AML_NO_RESOURCE_END_TAG) {
status = AE_OK;
}
if (ACPI_FAILURE(status)) {
ACPI_FREE(resource);
} else {
*resource_ptr = resource;
}
return_ACPI_STATUS(status);
}
acpi_status
acpi_rs_create_resource_list(union acpi_operand_object *aml_buffer,
struct acpi_buffer *output_buffer)
{
acpi_status status;
u8 *aml_start;
acpi_size list_size_needed = 0;
u32 aml_buffer_length;
void *resource;
ACPI_FUNCTION_TRACE(rs_create_resource_list);
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "AmlBuffer = %p\n", aml_buffer));
aml_buffer_length = aml_buffer->buffer.length;
aml_start = aml_buffer->buffer.pointer;
status = acpi_rs_get_list_length(aml_start, aml_buffer_length,
&list_size_needed);
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "Status=%X ListSizeNeeded=%X\n",
status, (u32) list_size_needed));
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_ut_initialize_buffer(output_buffer, list_size_needed);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
resource = output_buffer->pointer;
status = acpi_ut_walk_aml_resources(NULL, aml_start, aml_buffer_length,
acpi_rs_convert_aml_to_resources,
&resource);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "OutputBuffer %p Length %X\n",
output_buffer->pointer, (u32) output_buffer->length));
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_rs_create_pci_routing_table(union acpi_operand_object *package_object,
struct acpi_buffer *output_buffer)
{
u8 *buffer;
union acpi_operand_object **top_object_list;
union acpi_operand_object **sub_object_list;
union acpi_operand_object *obj_desc;
acpi_size buffer_size_needed = 0;
u32 number_of_elements;
u32 index;
struct acpi_pci_routing_table *user_prt;
struct acpi_namespace_node *node;
acpi_status status;
struct acpi_buffer path_buffer;
ACPI_FUNCTION_TRACE(rs_create_pci_routing_table);
status =
acpi_rs_get_pci_routing_table_length(package_object,
&buffer_size_needed);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "BufferSizeNeeded = %X\n",
(u32) buffer_size_needed));
status = acpi_ut_initialize_buffer(output_buffer, buffer_size_needed);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
top_object_list = package_object->package.elements;
number_of_elements = package_object->package.count;
buffer = output_buffer->pointer;
user_prt = ACPI_CAST_PTR(struct acpi_pci_routing_table, buffer);
for (index = 0; index < number_of_elements; index++) {
buffer += user_prt->length;
user_prt = ACPI_CAST_PTR(struct acpi_pci_routing_table, buffer);
user_prt->length = (sizeof(struct acpi_pci_routing_table) - 4);
if ((*top_object_list)->package.count != 4) {
ACPI_ERROR((AE_INFO,
"(PRT[%u]) Need package of length 4, found length %u",
index, (*top_object_list)->package.count));
return_ACPI_STATUS(AE_AML_PACKAGE_LIMIT);
}
sub_object_list = (*top_object_list)->package.elements;
obj_desc = sub_object_list[0];
if (!obj_desc || obj_desc->common.type != ACPI_TYPE_INTEGER) {
ACPI_ERROR((AE_INFO,
"(PRT[%u].Address) Need Integer, found %s",
index,
acpi_ut_get_object_type_name(obj_desc)));
return_ACPI_STATUS(AE_BAD_DATA);
}
user_prt->address = obj_desc->integer.value;
obj_desc = sub_object_list[1];
if (!obj_desc || obj_desc->common.type != ACPI_TYPE_INTEGER) {
ACPI_ERROR((AE_INFO,
"(PRT[%u].Pin) Need Integer, found %s",
index,
acpi_ut_get_object_type_name(obj_desc)));
return_ACPI_STATUS(AE_BAD_DATA);
}
user_prt->pin = (u32) obj_desc->integer.value;
obj_desc = sub_object_list[2];
if (obj_desc) {
switch (obj_desc->common.type) {
case ACPI_TYPE_LOCAL_REFERENCE:
if (obj_desc->reference.class !=
ACPI_REFCLASS_NAME) {
ACPI_ERROR((AE_INFO,
"(PRT[%u].Source) Need name, found Reference Class 0x%X",
index,
obj_desc->reference.class));
return_ACPI_STATUS(AE_BAD_DATA);
}
node = obj_desc->reference.node;
path_buffer.length = output_buffer->length -
(u32) ((u8 *) user_prt->source -
(u8 *) output_buffer->pointer);
path_buffer.pointer = user_prt->source;
status = acpi_ns_handle_to_pathname((acpi_handle)node, &path_buffer, FALSE);
user_prt->length +=
(u32)strlen(user_prt->source) + 1;
break;
case ACPI_TYPE_STRING:
strcpy(user_prt->source,
obj_desc->string.pointer);
user_prt->length += obj_desc->string.length + 1;
break;
case ACPI_TYPE_INTEGER:
user_prt->length += sizeof(u32);
break;
default:
ACPI_ERROR((AE_INFO,
"(PRT[%u].Source) Need Ref/String/Integer, found %s",
index,
acpi_ut_get_object_type_name
(obj_desc)));
return_ACPI_STATUS(AE_BAD_DATA);
}
}
user_prt->length =
(u32) ACPI_ROUND_UP_TO_64BIT(user_prt->length);
obj_desc = sub_object_list[3];
if (!obj_desc || obj_desc->common.type != ACPI_TYPE_INTEGER) {
ACPI_ERROR((AE_INFO,
"(PRT[%u].SourceIndex) Need Integer, found %s",
index,
acpi_ut_get_object_type_name(obj_desc)));
return_ACPI_STATUS(AE_BAD_DATA);
}
user_prt->source_index = (u32) obj_desc->integer.value;
top_object_list++;
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "OutputBuffer %p Length %X\n",
output_buffer->pointer, (u32) output_buffer->length));
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_rs_create_aml_resources(struct acpi_buffer *resource_list,
struct acpi_buffer *output_buffer)
{
acpi_status status;
acpi_size aml_size_needed = 0;
ACPI_FUNCTION_TRACE(rs_create_aml_resources);
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "ResourceList Buffer = %p\n",
resource_list->pointer));
status =
acpi_rs_get_aml_length(resource_list->pointer,
resource_list->length, &aml_size_needed);
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "AmlSizeNeeded=%X, %s\n",
(u32)aml_size_needed, acpi_format_exception(status)));
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_ut_initialize_buffer(output_buffer, aml_size_needed);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_rs_convert_resources_to_aml(resource_list->pointer,
aml_size_needed,
output_buffer->pointer);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO, "OutputBuffer %p Length %X\n",
output_buffer->pointer, (u32) output_buffer->length));
return_ACPI_STATUS(AE_OK);
}
