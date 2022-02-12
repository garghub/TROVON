u32 acpi_tb_get_rsdp_length(struct acpi_table_rsdp *rsdp)
{
if (!ACPI_VALIDATE_RSDP_SIG(rsdp->signature)) {
return (0);
}
if (rsdp->revision >= 2) {
return (rsdp->length);
} else {
return (ACPI_RSDP_CHECKSUM_LENGTH);
}
}
acpi_status acpi_tb_validate_rsdp(struct acpi_table_rsdp * rsdp)
{
if (!ACPI_VALIDATE_RSDP_SIG(rsdp->signature)) {
return (AE_BAD_SIGNATURE);
}
if (acpi_tb_checksum((u8 *) rsdp, ACPI_RSDP_CHECKSUM_LENGTH) != 0) {
return (AE_BAD_CHECKSUM);
}
if ((rsdp->revision >= 2) &&
(acpi_tb_checksum((u8 *) rsdp, ACPI_RSDP_XCHECKSUM_LENGTH) != 0)) {
return (AE_BAD_CHECKSUM);
}
return (AE_OK);
}
acpi_status __init acpi_find_root_pointer(acpi_physical_address * table_address)
{
u8 *table_ptr;
u8 *mem_rover;
u32 physical_address;
ACPI_FUNCTION_TRACE(acpi_find_root_pointer);
table_ptr = acpi_os_map_memory((acpi_physical_address)
ACPI_EBDA_PTR_LOCATION,
ACPI_EBDA_PTR_LENGTH);
if (!table_ptr) {
ACPI_ERROR((AE_INFO,
"Could not map memory at 0x%8.8X for length %u",
ACPI_EBDA_PTR_LOCATION, ACPI_EBDA_PTR_LENGTH));
return_ACPI_STATUS(AE_NO_MEMORY);
}
ACPI_MOVE_16_TO_32(&physical_address, table_ptr);
physical_address <<= 4;
acpi_os_unmap_memory(table_ptr, ACPI_EBDA_PTR_LENGTH);
if (physical_address > 0x400) {
table_ptr = acpi_os_map_memory((acpi_physical_address)
physical_address,
ACPI_EBDA_WINDOW_SIZE);
if (!table_ptr) {
ACPI_ERROR((AE_INFO,
"Could not map memory at 0x%8.8X for length %u",
physical_address, ACPI_EBDA_WINDOW_SIZE));
return_ACPI_STATUS(AE_NO_MEMORY);
}
mem_rover =
acpi_tb_scan_memory_for_rsdp(table_ptr,
ACPI_EBDA_WINDOW_SIZE);
acpi_os_unmap_memory(table_ptr, ACPI_EBDA_WINDOW_SIZE);
if (mem_rover) {
physical_address +=
(u32) ACPI_PTR_DIFF(mem_rover, table_ptr);
*table_address =
(acpi_physical_address) physical_address;
return_ACPI_STATUS(AE_OK);
}
}
table_ptr = acpi_os_map_memory((acpi_physical_address)
ACPI_HI_RSDP_WINDOW_BASE,
ACPI_HI_RSDP_WINDOW_SIZE);
if (!table_ptr) {
ACPI_ERROR((AE_INFO,
"Could not map memory at 0x%8.8X for length %u",
ACPI_HI_RSDP_WINDOW_BASE,
ACPI_HI_RSDP_WINDOW_SIZE));
return_ACPI_STATUS(AE_NO_MEMORY);
}
mem_rover =
acpi_tb_scan_memory_for_rsdp(table_ptr, ACPI_HI_RSDP_WINDOW_SIZE);
acpi_os_unmap_memory(table_ptr, ACPI_HI_RSDP_WINDOW_SIZE);
if (mem_rover) {
physical_address = (u32)
(ACPI_HI_RSDP_WINDOW_BASE +
ACPI_PTR_DIFF(mem_rover, table_ptr));
*table_address = (acpi_physical_address) physical_address;
return_ACPI_STATUS(AE_OK);
}
ACPI_BIOS_ERROR((AE_INFO, "A valid RSDP was not found"));
return_ACPI_STATUS(AE_NOT_FOUND);
}
u8 *acpi_tb_scan_memory_for_rsdp(u8 *start_address, u32 length)
{
acpi_status status;
u8 *mem_rover;
u8 *end_address;
ACPI_FUNCTION_TRACE(tb_scan_memory_for_rsdp);
end_address = start_address + length;
for (mem_rover = start_address; mem_rover < end_address;
mem_rover += ACPI_RSDP_SCAN_STEP) {
status =
acpi_tb_validate_rsdp(ACPI_CAST_PTR
(struct acpi_table_rsdp, mem_rover));
if (ACPI_SUCCESS(status)) {
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"RSDP located at physical address %p\n",
mem_rover));
return_PTR(mem_rover);
}
}
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"Searched entire block from %p, valid RSDP was not found\n",
start_address));
return_PTR(NULL);
}
