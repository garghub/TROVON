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
u8 end_tag[2] = { 0x79, 0x00 };
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
return_ACPI_STATUS(status);
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
if (user_function) {
(void)acpi_ut_validate_resource(end_tag, &resource_index);
status =
user_function(end_tag, 2, offset, resource_index, context);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
return_ACPI_STATUS(AE_AML_NO_RESOURCE_END_TAG);
}
acpi_status acpi_ut_validate_resource(void *aml, u8 * return_index)
{
union aml_resource *aml_resource;
u8 resource_type;
u8 resource_index;
acpi_rs_length resource_length;
acpi_rs_length minimum_resource_length;
ACPI_FUNCTION_ENTRY();
resource_type = ACPI_GET8(aml);
if (resource_type & ACPI_RESOURCE_NAME_LARGE) {
if (resource_type > ACPI_RESOURCE_NAME_LARGE_MAX) {
goto invalid_resource;
}
resource_index = (u8) (resource_type - 0x70);
} else {
resource_index = (u8)
((resource_type & ACPI_RESOURCE_NAME_SMALL_MASK) >> 3);
}
if (!acpi_gbl_resource_types[resource_index]) {
goto invalid_resource;
}
resource_length = acpi_ut_get_resource_length(aml);
minimum_resource_length = acpi_gbl_resource_aml_sizes[resource_index];
switch (acpi_gbl_resource_types[resource_index]) {
case ACPI_FIXED_LENGTH:
if (resource_length != minimum_resource_length) {
goto bad_resource_length;
}
break;
case ACPI_VARIABLE_LENGTH:
if (resource_length < minimum_resource_length) {
goto bad_resource_length;
}
break;
case ACPI_SMALL_VARIABLE_LENGTH:
if ((resource_length > minimum_resource_length) ||
(resource_length < (minimum_resource_length - 1))) {
goto bad_resource_length;
}
break;
default:
goto invalid_resource;
}
aml_resource = ACPI_CAST_PTR(union aml_resource, aml);
if (resource_type == ACPI_RESOURCE_NAME_SERIAL_BUS) {
if ((aml_resource->common_serial_bus.type == 0) ||
(aml_resource->common_serial_bus.type >
AML_RESOURCE_MAX_SERIALBUSTYPE)) {
ACPI_RESOURCE_ERROR((AE_INFO,
"Invalid/unsupported SerialBus resource descriptor: BusType 0x%2.2X",
aml_resource->common_serial_bus.
type));
return (AE_AML_INVALID_RESOURCE_TYPE);
}
}
if (return_index) {
*return_index = resource_index;
}
return (AE_OK);
invalid_resource:
ACPI_RESOURCE_ERROR((AE_INFO,
"Invalid/unsupported resource descriptor: Type 0x%2.2X",
resource_type));
return (AE_AML_INVALID_RESOURCE_TYPE);
bad_resource_length:
ACPI_RESOURCE_ERROR((AE_INFO,
"Invalid resource descriptor length: Type "
"0x%2.2X, Length 0x%4.4X, MinLength 0x%4.4X",
resource_type, resource_length,
minimum_resource_length));
return (AE_AML_BAD_RESOURCE_LENGTH);
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
