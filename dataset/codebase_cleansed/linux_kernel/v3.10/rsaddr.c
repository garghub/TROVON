u8
acpi_rs_get_address_common(struct acpi_resource *resource,
union aml_resource *aml)
{
ACPI_FUNCTION_ENTRY();
if ((aml->address.resource_type > 2)
&& (aml->address.resource_type < 0xC0)) {
return (FALSE);
}
(void)acpi_rs_convert_aml_to_resource(resource, aml,
acpi_rs_convert_general_flags);
if (resource->data.address.resource_type == ACPI_MEMORY_RANGE) {
(void)acpi_rs_convert_aml_to_resource(resource, aml,
acpi_rs_convert_mem_flags);
} else if (resource->data.address.resource_type == ACPI_IO_RANGE) {
(void)acpi_rs_convert_aml_to_resource(resource, aml,
acpi_rs_convert_io_flags);
} else {
resource->data.address.info.type_specific =
aml->address.specific_flags;
}
return (TRUE);
}
void
acpi_rs_set_address_common(union aml_resource *aml,
struct acpi_resource *resource)
{
ACPI_FUNCTION_ENTRY();
(void)acpi_rs_convert_resource_to_aml(resource, aml,
acpi_rs_convert_general_flags);
if (resource->data.address.resource_type == ACPI_MEMORY_RANGE) {
(void)acpi_rs_convert_resource_to_aml(resource, aml,
acpi_rs_convert_mem_flags);
} else if (resource->data.address.resource_type == ACPI_IO_RANGE) {
(void)acpi_rs_convert_resource_to_aml(resource, aml,
acpi_rs_convert_io_flags);
} else {
aml->address.specific_flags =
resource->data.address.info.type_specific;
}
}
