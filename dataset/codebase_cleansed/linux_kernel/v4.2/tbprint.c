static void acpi_tb_fix_string(char *string, acpi_size length)
{
while (length && *string) {
if (!isprint((int)*string)) {
*string = '?';
}
string++;
length--;
}
}
static void
acpi_tb_cleanup_table_header(struct acpi_table_header *out_header,
struct acpi_table_header *header)
{
memcpy(out_header, header, sizeof(struct acpi_table_header));
acpi_tb_fix_string(out_header->signature, ACPI_NAME_SIZE);
acpi_tb_fix_string(out_header->oem_id, ACPI_OEM_ID_SIZE);
acpi_tb_fix_string(out_header->oem_table_id, ACPI_OEM_TABLE_ID_SIZE);
acpi_tb_fix_string(out_header->asl_compiler_id, ACPI_NAME_SIZE);
}
void
acpi_tb_print_table_header(acpi_physical_address address,
struct acpi_table_header *header)
{
struct acpi_table_header local_header;
if (ACPI_COMPARE_NAME(header->signature, ACPI_SIG_FACS)) {
ACPI_INFO((AE_INFO, "%-4.4s 0x%8.8X%8.8X %06X",
header->signature, ACPI_FORMAT_UINT64(address),
header->length));
} else if (ACPI_VALIDATE_RSDP_SIG(header->signature)) {
memcpy(local_header.oem_id,
ACPI_CAST_PTR(struct acpi_table_rsdp, header)->oem_id,
ACPI_OEM_ID_SIZE);
acpi_tb_fix_string(local_header.oem_id, ACPI_OEM_ID_SIZE);
ACPI_INFO((AE_INFO, "RSDP 0x%8.8X%8.8X %06X (v%.2d %-6.6s)",
ACPI_FORMAT_UINT64(address),
(ACPI_CAST_PTR(struct acpi_table_rsdp, header)->
revision >
0) ? ACPI_CAST_PTR(struct acpi_table_rsdp,
header)->length : 20,
ACPI_CAST_PTR(struct acpi_table_rsdp,
header)->revision,
local_header.oem_id));
} else {
acpi_tb_cleanup_table_header(&local_header, header);
ACPI_INFO((AE_INFO,
"%-4.4s 0x%8.8X%8.8X"
" %06X (v%.2d %-6.6s %-8.8s %08X %-4.4s %08X)",
local_header.signature, ACPI_FORMAT_UINT64(address),
local_header.length, local_header.revision,
local_header.oem_id, local_header.oem_table_id,
local_header.oem_revision,
local_header.asl_compiler_id,
local_header.asl_compiler_revision));
}
}
acpi_status acpi_tb_verify_checksum(struct acpi_table_header *table, u32 length)
{
u8 checksum;
if (ACPI_COMPARE_NAME(table->signature, ACPI_SIG_S3PT) ||
ACPI_COMPARE_NAME(table->signature, ACPI_SIG_FACS)) {
return (AE_OK);
}
checksum = acpi_tb_checksum(ACPI_CAST_PTR(u8, table), length);
if (checksum) {
ACPI_BIOS_WARNING((AE_INFO,
"Incorrect checksum in table [%4.4s] - 0x%2.2X, "
"should be 0x%2.2X",
table->signature, table->checksum,
(u8)(table->checksum - checksum)));
#if (ACPI_CHECKSUM_ABORT)
return (AE_BAD_CHECKSUM);
#endif
}
return (AE_OK);
}
u8 acpi_tb_checksum(u8 *buffer, u32 length)
{
u8 sum = 0;
u8 *end = buffer + length;
while (buffer < end) {
sum = (u8)(sum + *(buffer++));
}
return (sum);
}
