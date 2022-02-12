acpi_status
acpi_ut_walk_aml_resources(u8 * aml,
acpi_size aml_length,
acpi_walk_aml_callback user_function, void **context)
{
acpi_status status;
u8 *end_aml;
u8 resource_index;
u32 length;
u32 offset = 0;
ACPI_FUNCTION_TRACE(ut_walk_aml_resources);
if (aml_length < sizeof(struct aml_resource_end_tag)) {
return_ACPI_STATUS(AE_AML_NO_RESOURCE_END_TAG);
}
end_aml = aml + aml_length;
while (aml < end_aml) {
status = acpi_ut_validate_resource(aml, &resource_index);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
length = acpi_ut_get_descriptor_length(aml);
if (user_function) {
status =
user_function(aml, length, offset, resource_index,
context);
if (ACPI_FAILURE(status)) {
return (status);
}
}
if (acpi_ut_get_resource_type(aml) ==
ACPI_RESOURCE_NAME_END_TAG) {
if ((aml + 1) >= end_aml) {
return_ACPI_STATUS(AE_AML_NO_RESOURCE_END_TAG);
}
if (!user_function) {
*context = aml;
}
return_ACPI_STATUS(AE_OK);
}
aml += length;
offset += length;
}
return (AE_AML_NO_RESOURCE_END_TAG);
}
acpi_status acpi_ut_validate_resource(void *aml, u8 * return_index)
{
u8 resource_type;
u8 resource_index;
acpi_rs_length resource_length;
acpi_rs_length minimum_resource_length;
ACPI_FUNCTION_ENTRY();
resource_type = ACPI_GET8(aml);
if (resource_type & ACPI_RESOURCE_NAME_LARGE) {
if (resource_type > ACPI_RESOURCE_NAME_LARGE_MAX) {
return (AE_AML_INVALID_RESOURCE_TYPE);
}
resource_index = (u8) (resource_type - 0x70);
} else {
resource_index = (u8)
((resource_type & ACPI_RESOURCE_NAME_SMALL_MASK) >> 3);
}
if (!acpi_gbl_resource_types[resource_index]) {
return (AE_AML_INVALID_RESOURCE_TYPE);
}
resource_length = acpi_ut_get_resource_length(aml);
minimum_resource_length = acpi_gbl_resource_aml_sizes[resource_index];
switch (acpi_gbl_resource_types[resource_index]) {
case ACPI_FIXED_LENGTH:
if (resource_length != minimum_resource_length) {
return (AE_AML_BAD_RESOURCE_LENGTH);
}
break;
case ACPI_VARIABLE_LENGTH:
if (resource_length < minimum_resource_length) {
return (AE_AML_BAD_RESOURCE_LENGTH);
}
break;
case ACPI_SMALL_VARIABLE_LENGTH:
if ((resource_length > minimum_resource_length) ||
(resource_length < (minimum_resource_length - 1))) {
return (AE_AML_BAD_RESOURCE_LENGTH);
}
break;
default:
return (AE_AML_INVALID_RESOURCE_TYPE);
}
if (return_index) {
*return_index = resource_index;
}
return (AE_OK);
}
u8 acpi_ut_get_resource_type(void *aml)
{
ACPI_FUNCTION_ENTRY();
if (ACPI_GET8(aml) & ACPI_RESOURCE_NAME_LARGE) {
return (ACPI_GET8(aml));
} else {
return ((u8) (ACPI_GET8(aml) & ACPI_RESOURCE_NAME_SMALL_MASK));
}
}
u16 acpi_ut_get_resource_length(void *aml)
{
acpi_rs_length resource_length;
ACPI_FUNCTION_ENTRY();
if (ACPI_GET8(aml) & ACPI_RESOURCE_NAME_LARGE) {
ACPI_MOVE_16_TO_16(&resource_length, ACPI_ADD_PTR(u8, aml, 1));
} else {
resource_length = (u16) (ACPI_GET8(aml) &
ACPI_RESOURCE_NAME_SMALL_LENGTH_MASK);
}
return (resource_length);
}
u8 acpi_ut_get_resource_header_length(void *aml)
{
ACPI_FUNCTION_ENTRY();
if (ACPI_GET8(aml) & ACPI_RESOURCE_NAME_LARGE) {
return (sizeof(struct aml_resource_large_header));
} else {
return (sizeof(struct aml_resource_small_header));
}
}
u32 acpi_ut_get_descriptor_length(void *aml)
{
ACPI_FUNCTION_ENTRY();
return (acpi_ut_get_resource_length(aml) +
acpi_ut_get_resource_header_length(aml));
}
acpi_status
acpi_ut_get_resource_end_tag(union acpi_operand_object * obj_desc,
u8 ** end_tag)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ut_get_resource_end_tag);
if (!obj_desc->buffer.length) {
*end_tag = obj_desc->buffer.pointer;
return_ACPI_STATUS(AE_OK);
}
status = acpi_ut_walk_aml_resources(obj_desc->buffer.pointer,
obj_desc->buffer.length, NULL,
(void **)end_tag);
return_ACPI_STATUS(status);
}
