acpi_status acpi_tb_initialize_facs(void)
{
struct acpi_table_facs *facs;
if (acpi_gbl_reduced_hardware) {
acpi_gbl_FACS = NULL;
return (AE_OK);
} else if (acpi_gbl_FADT.Xfacs &&
(!acpi_gbl_FADT.facs
|| !acpi_gbl_use32_bit_facs_addresses)) {
(void)acpi_get_table_by_index(acpi_gbl_xfacs_index,
ACPI_CAST_INDIRECT_PTR(struct
acpi_table_header,
&facs));
acpi_gbl_FACS = facs;
} else if (acpi_gbl_FADT.facs) {
(void)acpi_get_table_by_index(acpi_gbl_facs_index,
ACPI_CAST_INDIRECT_PTR(struct
acpi_table_header,
&facs));
acpi_gbl_FACS = facs;
}
return (AE_OK);
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
memcpy(new_table, table_desc->pointer, table_desc->length);
acpi_tb_uninstall_table(table_desc);
acpi_tb_init_table_descriptor(&acpi_gbl_root_table_list.
tables[acpi_gbl_dsdt_index],
ACPI_PTR_TO_PHYSADDR(new_table),
ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL,
new_table);
ACPI_INFO(("Forced DSDT copy: length 0x%05X copied locally, original unmapped", new_table->length));
return (new_table);
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
return ((acpi_physical_address)(address64));
}
}
acpi_status ACPI_INIT_FUNCTION
acpi_tb_parse_root_table(acpi_physical_address rsdp_address)
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
u32 table_index;
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
address = (acpi_physical_address)rsdp->xsdt_physical_address;
table_entry_size = ACPI_XSDT_ENTRY_SIZE;
} else {
address = (acpi_physical_address)rsdp->rsdt_physical_address;
table_entry_size = ACPI_RSDT_ENTRY_SIZE;
}
acpi_os_unmap_memory(rsdp, sizeof(struct acpi_table_rsdp));
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
for (i = 0; i < table_count; i++) {
address =
acpi_tb_get_root_table_entry(table_entry, table_entry_size);
if (!address) {
goto next_table;
}
status = acpi_tb_install_standard_table(address,
ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL,
FALSE, TRUE,
&table_index);
if (ACPI_SUCCESS(status) &&
ACPI_COMPARE_NAME(&acpi_gbl_root_table_list.
tables[table_index].signature,
ACPI_SIG_FADT)) {
acpi_gbl_fadt_index = table_index;
acpi_tb_parse_fadt();
}
next_table:
table_entry += table_entry_size;
}
acpi_os_unmap_memory(table, length);
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_tb_get_table(struct acpi_table_desc *table_desc,
struct acpi_table_header **out_table)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_tb_get_table);
if (table_desc->validation_count == 0) {
status = acpi_tb_validate_table(table_desc);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
table_desc->validation_count++;
if (table_desc->validation_count == 0) {
ACPI_ERROR((AE_INFO,
"Table %p, Validation count is zero after increment\n",
table_desc));
table_desc->validation_count--;
return_ACPI_STATUS(AE_LIMIT);
}
*out_table = table_desc->pointer;
return_ACPI_STATUS(AE_OK);
}
void acpi_tb_put_table(struct acpi_table_desc *table_desc)
{
ACPI_FUNCTION_TRACE(acpi_tb_put_table);
if (table_desc->validation_count == 0) {
ACPI_WARNING((AE_INFO,
"Table %p, Validation count is zero before decrement\n",
table_desc));
return_VOID;
}
table_desc->validation_count--;
if (table_desc->validation_count == 0) {
acpi_tb_invalidate_table(table_desc);
}
return_VOID;
}
