static u8
acpi_tb_compare_tables(struct acpi_table_desc *table_desc, u32 table_index)
{
acpi_status status = AE_OK;
u8 is_identical;
struct acpi_table_header *table;
u32 table_length;
u8 table_flags;
status =
acpi_tb_acquire_table(&acpi_gbl_root_table_list.tables[table_index],
&table, &table_length, &table_flags);
if (ACPI_FAILURE(status)) {
return (FALSE);
}
is_identical = (u8)((table_desc->length != table_length ||
memcmp(table_desc->pointer, table, table_length)) ?
FALSE : TRUE);
acpi_tb_release_table(table, table_length, table_flags);
return (is_identical);
}
void
acpi_tb_install_table_with_override(struct acpi_table_desc *new_table_desc,
u8 override, u32 *table_index)
{
u32 i;
acpi_status status;
status = acpi_tb_get_next_table_descriptor(&i, NULL);
if (ACPI_FAILURE(status)) {
return;
}
if (override) {
acpi_tb_override_table(new_table_desc);
}
acpi_tb_init_table_descriptor(&acpi_gbl_root_table_list.tables[i],
new_table_desc->address,
new_table_desc->flags,
new_table_desc->pointer);
acpi_tb_print_table_header(new_table_desc->address,
new_table_desc->pointer);
*table_index = i;
if (i == acpi_gbl_dsdt_index) {
acpi_ut_set_integer_width(new_table_desc->pointer->revision);
}
}
acpi_status
acpi_tb_install_standard_table(acpi_physical_address address,
u8 flags,
u8 reload, u8 override, u32 *table_index)
{
u32 i;
acpi_status status = AE_OK;
struct acpi_table_desc new_table_desc;
ACPI_FUNCTION_TRACE(tb_install_standard_table);
status = acpi_tb_acquire_temp_table(&new_table_desc, address, flags);
if (ACPI_FAILURE(status)) {
ACPI_ERROR((AE_INFO,
"Could not acquire table length at %8.8X%8.8X",
ACPI_FORMAT_UINT64(address)));
return_ACPI_STATUS(status);
}
if (!reload &&
acpi_gbl_disable_ssdt_table_install &&
ACPI_COMPARE_NAME(&new_table_desc.signature, ACPI_SIG_SSDT)) {
ACPI_INFO(("Ignoring installation of %4.4s at %8.8X%8.8X",
new_table_desc.signature.ascii,
ACPI_FORMAT_UINT64(address)));
goto release_and_exit;
}
status = acpi_tb_verify_temp_table(&new_table_desc, NULL);
if (ACPI_FAILURE(status)) {
goto release_and_exit;
}
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (reload) {
if ((new_table_desc.signature.ascii[0] != 0x00) &&
(!ACPI_COMPARE_NAME
(&new_table_desc.signature, ACPI_SIG_SSDT))
&& (strncmp(new_table_desc.signature.ascii, "OEM", 3))) {
ACPI_BIOS_ERROR((AE_INFO,
"Table has invalid signature [%4.4s] (0x%8.8X), "
"must be SSDT or OEMx",
acpi_ut_valid_nameseg(new_table_desc.
signature.
ascii) ?
new_table_desc.signature.
ascii : "????",
new_table_desc.signature.integer));
status = AE_BAD_SIGNATURE;
goto unlock_and_exit;
}
for (i = 0; i < acpi_gbl_root_table_list.current_table_count;
++i) {
if (!acpi_tb_compare_tables(&new_table_desc, i)) {
continue;
}
if (acpi_gbl_root_table_list.tables[i].flags &
ACPI_TABLE_IS_LOADED) {
status = AE_ALREADY_EXISTS;
goto unlock_and_exit;
} else {
acpi_tb_uninstall_table(&new_table_desc);
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
*table_index = i;
return_ACPI_STATUS(AE_OK);
}
}
}
acpi_tb_install_table_with_override(&new_table_desc, override,
table_index);
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
if (acpi_gbl_table_handler) {
(void)acpi_gbl_table_handler(ACPI_TABLE_EVENT_INSTALL,
new_table_desc.pointer,
acpi_gbl_table_handler_context);
}
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
release_and_exit:
acpi_tb_release_temp_table(&new_table_desc);
return_ACPI_STATUS(status);
}
void acpi_tb_override_table(struct acpi_table_desc *old_table_desc)
{
acpi_status status;
char *override_type;
struct acpi_table_desc new_table_desc;
struct acpi_table_header *table;
acpi_physical_address address;
u32 length;
status = acpi_os_table_override(old_table_desc->pointer, &table);
if (ACPI_SUCCESS(status) && table) {
acpi_tb_acquire_temp_table(&new_table_desc,
ACPI_PTR_TO_PHYSADDR(table),
ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL);
override_type = "Logical";
goto finish_override;
}
status = acpi_os_physical_table_override(old_table_desc->pointer,
&address, &length);
if (ACPI_SUCCESS(status) && address && length) {
acpi_tb_acquire_temp_table(&new_table_desc, address,
ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL);
override_type = "Physical";
goto finish_override;
}
return;
finish_override:
status = acpi_tb_verify_temp_table(&new_table_desc, NULL);
if (ACPI_FAILURE(status)) {
return;
}
ACPI_INFO(("%4.4s 0x%8.8X%8.8X"
" %s table override, new table: 0x%8.8X%8.8X",
old_table_desc->signature.ascii,
ACPI_FORMAT_UINT64(old_table_desc->address),
override_type, ACPI_FORMAT_UINT64(new_table_desc.address)));
acpi_tb_uninstall_table(old_table_desc);
acpi_tb_init_table_descriptor(old_table_desc, new_table_desc.address,
new_table_desc.flags,
new_table_desc.pointer);
acpi_tb_validate_temp_table(old_table_desc);
acpi_tb_release_temp_table(&new_table_desc);
}
void acpi_tb_uninstall_table(struct acpi_table_desc *table_desc)
{
ACPI_FUNCTION_TRACE(tb_uninstall_table);
if (!table_desc->address) {
return_VOID;
}
acpi_tb_invalidate_table(table_desc);
if ((table_desc->flags & ACPI_TABLE_ORIGIN_MASK) ==
ACPI_TABLE_ORIGIN_INTERNAL_VIRTUAL) {
ACPI_FREE(ACPI_PHYSADDR_TO_PTR(table_desc->address));
}
table_desc->address = ACPI_PTR_TO_PHYSADDR(NULL);
return_VOID;
}
