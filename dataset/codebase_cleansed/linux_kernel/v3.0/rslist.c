acpi_status
acpi_rs_convert_aml_to_resources(u8 * aml,
u32 length,
u32 offset, u8 resource_index, void **context)
{
struct acpi_resource **resource_ptr =
ACPI_CAST_INDIRECT_PTR(struct acpi_resource, context);
struct acpi_resource *resource;
acpi_status status;
ACPI_FUNCTION_TRACE(rs_convert_aml_to_resources);
resource = *resource_ptr;
if (ACPI_IS_MISALIGNED(resource)) {
ACPI_WARNING((AE_INFO,
"Misaligned resource pointer %p", resource));
}
status =
acpi_rs_convert_aml_to_resource(resource,
ACPI_CAST_PTR(union aml_resource,
aml),
acpi_gbl_get_resource_dispatch
[resource_index]);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Could not convert AML resource (Type 0x%X)",
*aml));
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_RESOURCES,
"Type %.2X, AmlLength %.2X InternalLength %.2X\n",
acpi_ut_get_resource_type(aml), length,
resource->length));
*resource_ptr = ACPI_ADD_PTR(void, resource, resource->length);
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_rs_convert_resources_to_aml(struct acpi_resource *resource,
acpi_size aml_size_needed, u8 * output_buffer)
{
u8 *aml = output_buffer;
u8 *end_aml = output_buffer + aml_size_needed;
acpi_status status;
ACPI_FUNCTION_TRACE(rs_convert_resources_to_aml);
while (aml < end_aml) {
if (resource->type > ACPI_RESOURCE_TYPE_MAX) {
ACPI_ERROR((AE_INFO,
"Invalid descriptor type (0x%X) in resource list",
resource->type));
return_ACPI_STATUS(AE_BAD_DATA);
}
status = acpi_rs_convert_resource_to_aml(resource, ACPI_CAST_PTR(union
aml_resource,
aml),
acpi_gbl_set_resource_dispatch
[resource->type]);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"Could not convert resource (type 0x%X) to AML",
resource->type));
return_ACPI_STATUS(status);
}
status =
acpi_ut_validate_resource(ACPI_CAST_PTR
(union aml_resource, aml), NULL);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (resource->type == ACPI_RESOURCE_TYPE_END_TAG) {
return_ACPI_STATUS(AE_OK);
}
aml += acpi_ut_get_descriptor_length(aml);
resource =
ACPI_ADD_PTR(struct acpi_resource, resource,
resource->length);
}
return_ACPI_STATUS(AE_AML_NO_RESOURCE_END_TAG);
}
