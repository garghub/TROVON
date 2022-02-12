acpi_status __init acpi_load_tables(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_load_tables);
status = acpi_tb_load_namespace();
if (status == AE_CTRL_TERMINATE) {
status = AE_OK;
}
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"While loading namespace from ACPI tables"));
}
return_ACPI_STATUS(status);
}
acpi_status acpi_tb_load_namespace(void)
{
acpi_status status;
u32 i;
struct acpi_table_header *new_dsdt;
struct acpi_table_desc *table;
u32 tables_loaded = 0;
u32 tables_failed = 0;
ACPI_FUNCTION_TRACE(tb_load_namespace);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
table = &acpi_gbl_root_table_list.tables[acpi_gbl_dsdt_index];
if (!acpi_gbl_root_table_list.current_table_count ||
!ACPI_COMPARE_NAME(table->signature.ascii, ACPI_SIG_DSDT) ||
ACPI_FAILURE(acpi_tb_validate_table(table))) {
status = AE_NO_ACPI_TABLES;
goto unlock_and_exit;
}
acpi_gbl_DSDT = table->pointer;
if (acpi_gbl_copy_dsdt_locally) {
new_dsdt = acpi_tb_copy_dsdt(acpi_gbl_dsdt_index);
if (new_dsdt) {
acpi_gbl_DSDT = new_dsdt;
}
}
memcpy(&acpi_gbl_original_dsdt_header, acpi_gbl_DSDT,
sizeof(struct acpi_table_header));
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
status = acpi_ns_load_table(acpi_gbl_dsdt_index, acpi_gbl_root_node);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "[DSDT] table load failed"));
tables_failed++;
} else {
tables_loaded++;
}
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; ++i) {
table = &acpi_gbl_root_table_list.tables[i];
if (!acpi_gbl_root_table_list.tables[i].address ||
(!ACPI_COMPARE_NAME(table->signature.ascii, ACPI_SIG_SSDT)
&& !ACPI_COMPARE_NAME(table->signature.ascii,
ACPI_SIG_PSDT)
&& !ACPI_COMPARE_NAME(table->signature.ascii,
ACPI_SIG_OSDT))
|| ACPI_FAILURE(acpi_tb_validate_table(table))) {
continue;
}
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
status = acpi_ns_load_table(i, acpi_gbl_root_node);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status,
"(%4.4s:%8.8s) while loading table",
table->signature.ascii,
table->pointer->oem_table_id));
tables_failed++;
ACPI_DEBUG_PRINT_RAW((ACPI_DB_INIT,
"Table [%4.4s:%8.8s] (id FF) - Table namespace load failed\n\n",
table->signature.ascii,
table->pointer->oem_table_id));
} else {
tables_loaded++;
}
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
}
if (!tables_failed) {
ACPI_INFO((AE_INFO,
"%u ACPI AML tables successfully acquired and loaded\n",
tables_loaded));
} else {
ACPI_ERROR((AE_INFO,
"%u table load failures, %u successful",
tables_failed, tables_loaded));
status = AE_CTRL_TERMINATE;
}
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
acpi_status __init
acpi_install_table(acpi_physical_address address, u8 physical)
{
acpi_status status;
u8 flags;
u32 table_index;
ACPI_FUNCTION_TRACE(acpi_install_table);
if (physical) {
flags = ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL;
} else {
flags = ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL;
}
status = acpi_tb_install_standard_table(address, flags,
FALSE, FALSE, &table_index);
return_ACPI_STATUS(status);
}
acpi_status acpi_load_table(struct acpi_table_header *table)
{
acpi_status status;
u32 table_index;
ACPI_FUNCTION_TRACE(acpi_load_table);
if (!table) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_INTERPRETER);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_INFO((AE_INFO, "Host-directed Dynamic ACPI Table Load:"));
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
status = acpi_tb_install_standard_table(ACPI_PTR_TO_PHYSADDR(table),
ACPI_TABLE_ORIGIN_EXTERNAL_VIRTUAL,
TRUE, FALSE, &table_index);
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
if (ACPI_FAILURE(status)) {
goto unlock_and_exit;
}
status =
acpi_tb_validate_table(&acpi_gbl_root_table_list.
tables[table_index]);
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
