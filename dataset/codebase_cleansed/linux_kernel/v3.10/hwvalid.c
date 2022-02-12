static acpi_status
acpi_hw_validate_io_request(acpi_io_address address, u32 bit_width)
{
u32 i;
u32 byte_width;
acpi_io_address last_address;
const struct acpi_port_info *port_info;
ACPI_FUNCTION_TRACE(hw_validate_io_request);
if ((bit_width != 8) && (bit_width != 16) && (bit_width != 32)) {
ACPI_ERROR((AE_INFO,
"Bad BitWidth parameter: %8.8X", bit_width));
return (AE_BAD_PARAMETER);
}
port_info = acpi_protected_ports;
byte_width = ACPI_DIV_8(bit_width);
last_address = address + byte_width - 1;
ACPI_DEBUG_PRINT((ACPI_DB_IO, "Address %p LastAddress %p Length %X",
ACPI_CAST_PTR(void, address), ACPI_CAST_PTR(void,
last_address),
byte_width));
if (last_address > ACPI_UINT16_MAX) {
ACPI_ERROR((AE_INFO,
"Illegal I/O port address/length above 64K: %p/0x%X",
ACPI_CAST_PTR(void, address), byte_width));
return_ACPI_STATUS(AE_LIMIT);
}
if (address > acpi_protected_ports[ACPI_PORT_INFO_ENTRIES - 1].end) {
return_ACPI_STATUS(AE_OK);
}
for (i = 0; i < ACPI_PORT_INFO_ENTRIES; i++, port_info++) {
if ((address <= port_info->end)
&& (last_address >= port_info->start)) {
if (acpi_gbl_osi_data >= port_info->osi_dependency) {
ACPI_DEBUG_PRINT((ACPI_DB_IO,
"Denied AML access to port 0x%p/%X (%s 0x%.4X-0x%.4X)",
ACPI_CAST_PTR(void, address),
byte_width, port_info->name,
port_info->start,
port_info->end));
return_ACPI_STATUS(AE_AML_ILLEGAL_ADDRESS);
}
}
if (last_address <= port_info->end) {
break;
}
}
return_ACPI_STATUS(AE_OK);
}
acpi_status acpi_hw_read_port(acpi_io_address address, u32 *value, u32 width)
{
acpi_status status;
u32 one_byte;
u32 i;
if (acpi_gbl_truncate_io_addresses) {
address &= ACPI_UINT16_MAX;
}
status = acpi_hw_validate_io_request(address, width);
if (ACPI_SUCCESS(status)) {
status = acpi_os_read_port(address, value, width);
return (status);
}
if (status != AE_AML_ILLEGAL_ADDRESS) {
return (status);
}
for (i = 0, *value = 0; i < width; i += 8) {
if (acpi_hw_validate_io_request(address, 8) == AE_OK) {
status = acpi_os_read_port(address, &one_byte, 8);
if (ACPI_FAILURE(status)) {
return (status);
}
*value |= (one_byte << i);
}
address++;
}
return (AE_OK);
}
acpi_status acpi_hw_write_port(acpi_io_address address, u32 value, u32 width)
{
acpi_status status;
u32 i;
if (acpi_gbl_truncate_io_addresses) {
address &= ACPI_UINT16_MAX;
}
status = acpi_hw_validate_io_request(address, width);
if (ACPI_SUCCESS(status)) {
status = acpi_os_write_port(address, value, width);
return (status);
}
if (status != AE_AML_ILLEGAL_ADDRESS) {
return (status);
}
for (i = 0; i < width; i += 8) {
if (acpi_hw_validate_io_request(address, 8) == AE_OK) {
status =
acpi_os_write_port(address, (value >> i) & 0xFF, 8);
if (ACPI_FAILURE(status)) {
return (status);
}
}
address++;
}
return (AE_OK);
}
