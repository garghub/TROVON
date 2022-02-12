acpi_status __init acpi_load_tables(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_load_tables);
status = acpi_tb_load_namespace();
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"While loading namespace from ACPI tables"));
}
return_ACPI_STATUS(status);
}
static acpi_status acpi_tb_load_namespace(void)
{
acpi_status status;
u32 i;
struct acpi_table_header *new_dsdt;
ACPI_FUNCTION_TRACE(tb_load_namespace);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
if (!acpi_gbl_root_table_list.current_table_count ||
!ACPI_COMPARE_NAME(&
(acpi_gbl_root_table_list.
tables[ACPI_TABLE_INDEX_DSDT].signature),
ACPI_SIG_DSDT)
||
ACPI_FAILURE(acpi_tb_verify_table
(&acpi_gbl_root_table_list.
tables[ACPI_TABLE_INDEX_DSDT]))) {
status = AE_NO_ACPI_TABLES;
goto unlock_and_exit;
}
acpi_gbl_DSDT =
acpi_gbl_root_table_list.tables[ACPI_TABLE_INDEX_DSDT].pointer;
if (acpi_gbl_copy_dsdt_locally) {
new_dsdt = acpi_tb_copy_dsdt(ACPI_TABLE_INDEX_DSDT);
if (new_dsdt) {
acpi_gbl_DSDT = new_dsdt;
}
}
ACPI_MEMCPY(&acpi_gbl_original_dsdt_header, acpi_gbl_DSDT,
sizeof(struct acpi_table_header));
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
status = acpi_ns_load_table(ACPI_TABLE_INDEX_DSDT, acpi_gbl_root_node);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; ++i) {
if ((!ACPI_COMPARE_NAME
(&(acpi_gbl_root_table_list.tables[i].signature),
ACPI_SIG_SSDT)
&&
!ACPI_COMPARE_NAME(&
(acpi_gbl_root_table_list.tables[i].
signature), ACPI_SIG_PSDT))
||
ACPI_FAILURE(acpi_tb_verify_table
(&acpi_gbl_root_table_list.tables[i]))) {
continue;
}
if (acpi_gbl_disable_ssdt_table_load) {
ACPI_INFO((AE_INFO, "Ignoring %4.4s at %p",
acpi_gbl_root_table_list.tables[i].signature.
ascii, ACPI_CAST_PTR(void,
acpi_gbl_root_table_list.
tables[i].address)));
continue;
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
(void)acpi_ns_load_table(i, acpi_gbl_root_node);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
}
ACPI_INFO((AE_INFO, "All ACPI Tables successfully acquired"));
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
acpi_status acpi_load_table(struct acpi_table_header *table)
{
acpi_status status;
struct acpi_table_desc table_desc;
u32 table_index;
ACPI_FUNCTION_TRACE(acpi_load_table);
if (!table) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
ACPI_MEMSET(&table_desc, 0, sizeof(struct acpi_table_desc));
table_desc.address = ACPI_PTR_TO_PHYSADDR(table);
table_desc.pointer = table;
table_desc.length = table->length;
table_desc.flags = ACPI_TABLE_ORIGIN_UNKNOWN;
status = acpi_ut_acquire_mutex(ACPI_MTX_INTERPRETER);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_INFO((AE_INFO, "Host-directed Dynamic ACPI Table Load:"));
status = acpi_tb_add_table(&table_desc, &table_index);
if (ACPI_FAILURE(status)) {
goto unlock_and_exit;
}
status = acpi_ns_load_table(table_index, acpi_gbl_root_node);
if (acpi_gbl_table_handler) {
(void)acpi_gbl_table_handler(ACPI_TABLE_EVENT_LOAD, table,
acpi_gbl_table_handler_context);
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_INTERPRETER);
return_ACPI_STATUS(status);
}
acpi_status acpi_unload_parent_table(acpi_handle object)
{
struct acpi_namespace_node *node =
ACPI_CAST_PTR(struct acpi_namespace_node, object);
acpi_status status = AE_NOT_EXIST;
acpi_owner_id owner_id;
u32 i;
ACPI_FUNCTION_TRACE(acpi_unload_parent_table);
if (!object) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
owner_id = node->owner_id;
if (!owner_id) {
return_ACPI_STATUS(AE_TYPE);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_INTERPRETER);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; i++) {
if (owner_id != acpi_gbl_root_table_list.tables[i].owner_id) {
continue;
}
if (ACPI_COMPARE_NAME
(acpi_gbl_root_table_list.tables[i].signature.ascii,
ACPI_SIG_DSDT)) {
status = AE_TYPE;
break;
}
if (!acpi_tb_is_table_loaded(i)) {
status = AE_NOT_EXIST;
break;
}
if (acpi_gbl_table_handler) {
(void)acpi_gbl_table_handler(ACPI_TABLE_EVENT_UNLOAD,
acpi_gbl_root_table_list.
tables[i].pointer,
acpi_gbl_table_handler_context);
}
status = acpi_tb_delete_namespace_by_owner(i);
if (ACPI_FAILURE(status)) {
break;
}
status = acpi_tb_release_owner_id(i);
acpi_tb_set_table_loaded_flag(i, FALSE);
break;
}
(void)acpi_ut_release_mutex(ACPI_MTX_INTERPRETER);
return_ACPI_STATUS(status);
}
