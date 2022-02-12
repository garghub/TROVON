static acpi_status hp_ccsr_locate(acpi_handle obj, u64 *base, u64 *length)
{
acpi_status status;
struct acpi_buffer buffer = { ACPI_ALLOCATE_BUFFER, NULL };
struct acpi_resource *resource;
struct acpi_resource_vendor_typed *vendor;
status = acpi_get_vendor_resource(obj, METHOD_NAME__CRS, &hp_ccsr_uuid,
&buffer);
resource = buffer.pointer;
vendor = &resource->data.vendor_typed;
if (ACPI_FAILURE(status) || vendor->byte_length < 16) {
status = AE_NOT_FOUND;
goto exit;
}
memcpy(base, vendor->byte_data, sizeof(*base));
memcpy(length, vendor->byte_data + 8, sizeof(*length));
exit:
kfree(buffer.pointer);
return status;
}
static acpi_status find_csr_space(struct acpi_resource *resource, void *data)
{
struct csr_space *space = data;
struct acpi_resource_address64 addr;
acpi_status status;
status = acpi_resource_to_address64(resource, &addr);
if (ACPI_SUCCESS(status) &&
addr.resource_type == ACPI_MEMORY_RANGE &&
addr.address.address_length &&
addr.producer_consumer == ACPI_CONSUMER) {
space->base = addr.address.minimum;
space->length = addr.address.address_length;
return AE_CTRL_TERMINATE;
}
return AE_OK;
}
static acpi_status hp_crs_locate(acpi_handle obj, u64 *base, u64 *length)
{
struct csr_space space = { 0, 0 };
acpi_walk_resources(obj, METHOD_NAME__CRS, find_csr_space, &space);
if (!space.length)
return AE_NOT_FOUND;
*base = space.base;
*length = space.length;
return AE_OK;
}
acpi_status hp_acpi_csr_space(acpi_handle obj, u64 *csr_base, u64 *csr_length)
{
acpi_status status;
status = hp_ccsr_locate(obj, csr_base, csr_length);
if (ACPI_SUCCESS(status))
return status;
return hp_crs_locate(obj, csr_base, csr_length);
}
