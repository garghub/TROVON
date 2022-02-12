acpi_status acpi_tb_initialize_facs(void)
{
acpi_status status;
if (acpi_gbl_reduced_hardware) {
acpi_gbl_FACS = NULL;
return (AE_OK);
}
status = acpi_get_table_by_index(ACPI_TABLE_INDEX_FACS,
ACPI_CAST_INDIRECT_PTR(struct
acpi_table_header,
&acpi_gbl_FACS));
return (status);
}
u8 acpi_tb_tables_loaded(void)
{
if (acpi_gbl_root_table_list.current_table_count >= 3) {
return (TRUE);
}
return (FALSE);
}
void acpi_tb_check_dsdt_header(void)
{
if (acpi_gbl_original_dsdt_header.length != acpi_gbl_DSDT->length ||
acpi_gbl_original_dsdt_header.checksum != acpi_gbl_DSDT->checksum) {
ACPI_BIOS_ERROR((AE_INFO,
"The DSDT has been corrupted or replaced - "
"old, new headers below"));
acpi_tb_print_table_header(0, &acpi_gbl_original_dsdt_header);
acpi_tb_print_table_header(0, acpi_gbl_DSDT);
ACPI_ERROR((AE_INFO,
"Please send DMI info to linux-acpi@vger.kernel.org\n"
"If system does not work as expected, please boot with acpi=copy_dsdt"));
acpi_gbl_original_dsdt_header.length = acpi_gbl_DSDT->length;
acpi_gbl_original_dsdt_header.checksum =
acpi_gbl_DSDT->checksum;
}
}
struct acpi_table_header *acpi_tb_copy_dsdt(u32 table_index)
{
struct acpi_table_header *new_table;
struct acpi_table_desc *table_desc;
table_desc = &acpi_gbl_root_table_list.tables[table_index];
new_table = ACPI_ALLOCATE(table_desc->length);
if (!new_table) {
ACPI_ERROR((AE_INFO, "Could not copy DSDT of length 0x%X",
table_desc->length));
return (NULL);
}
ACPI_MEMCPY(new_table, table_desc->pointer, table_desc->length);
acpi_tb_delete_table(table_desc);
table_desc->pointer = new_table;
table_desc->flags = ACPI_TABLE_ORIGIN_ALLOCATED;
ACPI_INFO((AE_INFO,
"Forced DSDT copy: length 0x%05X copied locally, original unmapped",
new_table->length));
return (new_table);
}
void
acpi_tb_install_table(acpi_physical_address address,
char *signature, u32 table_index)
{
struct acpi_table_header *table;
struct acpi_table_header *final_table;
struct acpi_table_desc *table_desc;
if (!address) {
ACPI_ERROR((AE_INFO,
"Null physical address for ACPI table [%s]",
signature));
return;
}
table = acpi_os_map_memory(address, sizeof(struct acpi_table_header));
if (!table) {
ACPI_ERROR((AE_INFO,
"Could not map memory for table [%s] at %p",
signature, ACPI_CAST_PTR(void, address)));
return;
}
if (signature && !ACPI_COMPARE_NAME(table->signature, signature)) {
ACPI_BIOS_ERROR((AE_INFO,
"Invalid signature 0x%X for ACPI table, expected [%s]",
*ACPI_CAST_PTR(u32, table->signature),
signature));
goto unmap_and_exit;
}
table_desc = &acpi_gbl_root_table_list.tables[table_index];
table_desc->address = address;
table_desc->pointer = NULL;
table_desc->length = table->length;
table_desc->flags = ACPI_TABLE_ORIGIN_MAPPED;
ACPI_MOVE_32_TO_32(table_desc->signature.ascii, table->signature);
final_table = acpi_tb_table_override(table, table_desc);
if (!final_table) {
final_table = table;
}
acpi_tb_print_table_header(table_desc->address, final_table);
if (table_index == ACPI_TABLE_INDEX_DSDT) {
acpi_ut_set_integer_width(final_table->revision);
}
if (final_table != table) {
acpi_tb_delete_table(table_desc);
}
unmap_and_exit:
acpi_os_unmap_memory(table, sizeof(struct acpi_table_header));
}
static acpi_physical_address
acpi_tb_get_root_table_entry(u8 *table_entry, u32 table_entry_size)
{
u64 address64;
if (table_entry_size == ACPI_RSDT_ENTRY_SIZE) {
return ((acpi_physical_address)
(*ACPI_CAST_PTR(u32, table_entry)));
} else {
ACPI_MOVE_64_TO_64(&address64, table_entry);
#if ACPI_MACHINE_WIDTH == 32
if (address64 > ACPI_UINT32_MAX) {
ACPI_BIOS_WARNING((AE_INFO,
"64-bit Physical Address in XSDT is too large (0x%8.8X%8.8X),"
" truncating",
ACPI_FORMAT_UINT64(address64)));
}
#endif
return ((acpi_physical_address) (address64));
}
}
static acpi_status acpi_tb_validate_xsdt(acpi_physical_address xsdt_address)
{
struct acpi_table_header *table;
u8 *next_entry;
acpi_physical_address address;
u32 length;
u32 entry_count;
acpi_status status;
u32 i;
table =
acpi_os_map_memory(xsdt_address, sizeof(struct acpi_table_header));
if (!table) {
return (AE_NO_MEMORY);
}
length = table->length;
acpi_os_unmap_memory(table, sizeof(struct acpi_table_header));
if (length < (sizeof(struct acpi_table_header) + ACPI_XSDT_ENTRY_SIZE)) {
return (AE_INVALID_TABLE_LENGTH);
}
table = acpi_os_map_memory(xsdt_address, length);
if (!table) {
return (AE_NO_MEMORY);
}
status = AE_OK;
next_entry = ACPI_ADD_PTR(u8, table, sizeof(struct acpi_table_header));
entry_count = (u32)((table->length - sizeof(struct acpi_table_header)) /
ACPI_XSDT_ENTRY_SIZE);
for (i = 0; i < entry_count; i++) {
address =
acpi_tb_get_root_table_entry(next_entry,
ACPI_XSDT_ENTRY_SIZE);
if (!address) {
status = AE_NULL_ENTRY;
break;
}
next_entry += ACPI_XSDT_ENTRY_SIZE;
}
acpi_os_unmap_memory(table, length);
return (status);
}
acpi_status __init acpi_tb_parse_root_table(acpi_physical_address rsdp_address)
{
struct acpi_table_rsdp *rsdp;
u32 table_entry_size;
u32 i;
u32 table_count;
struct acpi_table_header *table;
acpi_physical_address address;
u32 length;
u8 *table_entry;
acpi_status status;
ACPI_FUNCTION_TRACE(tb_parse_root_table);
rsdp = acpi_os_map_memory(rsdp_address, sizeof(struct acpi_table_rsdp));
if (!rsdp) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
acpi_tb_print_table_header(rsdp_address,
ACPI_CAST_PTR(struct acpi_table_header,
rsdp));
if ((rsdp->revision > 1) &&
rsdp->xsdt_physical_address && !acpi_gbl_do_not_use_xsdt) {
address = (acpi_physical_address) rsdp->xsdt_physical_address;
table_entry_size = ACPI_XSDT_ENTRY_SIZE;
} else {
address = (acpi_physical_address) rsdp->rsdt_physical_address;
table_entry_size = ACPI_RSDT_ENTRY_SIZE;
}
acpi_os_unmap_memory(rsdp, sizeof(struct acpi_table_rsdp));
if (table_entry_size == ACPI_XSDT_ENTRY_SIZE) {
status = acpi_tb_validate_xsdt(address);
if (ACPI_FAILURE(status)) {
ACPI_BIOS_WARNING((AE_INFO,
"XSDT is invalid (%s), using RSDT",
acpi_format_exception(status)));
address =
(acpi_physical_address) rsdp->rsdt_physical_address;
table_entry_size = ACPI_RSDT_ENTRY_SIZE;
}
}
table = acpi_os_map_memory(address, sizeof(struct acpi_table_header));
if (!table) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
acpi_tb_print_table_header(address, table);
length = table->length;
acpi_os_unmap_memory(table, sizeof(struct acpi_table_header));
if (length < (sizeof(struct acpi_table_header) + table_entry_size)) {
ACPI_BIOS_ERROR((AE_INFO,
"Invalid table length 0x%X in RSDT/XSDT",
length));
return_ACPI_STATUS(AE_INVALID_TABLE_LENGTH);
}
table = acpi_os_map_memory(address, length);
if (!table) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
status = acpi_tb_verify_checksum(table, length);
if (ACPI_FAILURE(status)) {
acpi_os_unmap_memory(table, length);
return_ACPI_STATUS(status);
}
table_count = (u32)((table->length - sizeof(struct acpi_table_header)) /
table_entry_size);
table_entry = ACPI_ADD_PTR(u8, table, sizeof(struct acpi_table_header));
acpi_gbl_root_table_list.current_table_count = 2;
for (i = 0; i < table_count; i++) {
if (acpi_gbl_root_table_list.current_table_count >=
acpi_gbl_root_table_list.max_table_count) {
status = acpi_tb_resize_root_table_list();
if (ACPI_FAILURE(status)) {
ACPI_WARNING((AE_INFO,
"Truncating %u table entries!",
(unsigned) (table_count -
(acpi_gbl_root_table_list.
current_table_count -
2))));
break;
}
}
acpi_gbl_root_table_list.tables[acpi_gbl_root_table_list.
current_table_count].address =
acpi_tb_get_root_table_entry(table_entry, table_entry_size);
table_entry += table_entry_size;
acpi_gbl_root_table_list.current_table_count++;
}
acpi_os_unmap_memory(table, length);
for (i = 2; i < acpi_gbl_root_table_list.current_table_count; i++) {
acpi_tb_install_table(acpi_gbl_root_table_list.tables[i].
address, NULL, i);
if (ACPI_COMPARE_NAME
(&acpi_gbl_root_table_list.tables[i].signature,
ACPI_SIG_FADT)) {
acpi_tb_parse_fadt(i);
}
}
return_ACPI_STATUS(AE_OK);
}
