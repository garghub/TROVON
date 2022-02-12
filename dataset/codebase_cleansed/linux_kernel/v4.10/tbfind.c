acpi_status
acpi_tb_find_table(char *signature,
char *oem_id, char *oem_table_id, u32 *table_index)
{
acpi_status status = AE_OK;
struct acpi_table_header header;
u32 i;
ACPI_FUNCTION_TRACE(tb_find_table);
if (!acpi_ut_valid_nameseg(signature)) {
return_ACPI_STATUS(AE_BAD_SIGNATURE);
}
if ((strlen(oem_id) > ACPI_OEM_ID_SIZE) ||
(strlen(oem_table_id) > ACPI_OEM_TABLE_ID_SIZE)) {
return_ACPI_STATUS(AE_AML_STRING_LIMIT);
}
memset(&header, 0, sizeof(struct acpi_table_header));
ACPI_MOVE_NAME(header.signature, signature);
strncpy(header.oem_id, oem_id, ACPI_OEM_ID_SIZE);
strncpy(header.oem_table_id, oem_table_id, ACPI_OEM_TABLE_ID_SIZE);
(void)acpi_ut_acquire_mutex(ACPI_MTX_TABLES);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; ++i) {
if (memcmp(&(acpi_gbl_root_table_list.tables[i].signature),
header.signature, ACPI_NAME_SIZE)) {
continue;
}
if (!acpi_gbl_root_table_list.tables[i].pointer) {
status =
acpi_tb_validate_table(&acpi_gbl_root_table_list.
tables[i]);
if (ACPI_FAILURE(status)) {
goto unlock_and_exit;
}
if (!acpi_gbl_root_table_list.tables[i].pointer) {
continue;
}
}
if (!memcmp
(acpi_gbl_root_table_list.tables[i].pointer->signature,
header.signature, ACPI_NAME_SIZE) && (!oem_id[0]
||
!memcmp
(acpi_gbl_root_table_list.
tables[i].pointer->
oem_id,
header.oem_id,
ACPI_OEM_ID_SIZE))
&& (!oem_table_id[0]
|| !memcmp(acpi_gbl_root_table_list.tables[i].pointer->
oem_table_id, header.oem_table_id,
ACPI_OEM_TABLE_ID_SIZE))) {
*table_index = i;
ACPI_DEBUG_PRINT((ACPI_DB_TABLES,
"Found table [%4.4s]\n",
header.signature));
goto unlock_and_exit;
}
}
status = AE_NOT_FOUND;
unlock_and_exit:
(void)acpi_ut_release_mutex(ACPI_MTX_TABLES);
return_ACPI_STATUS(status);
}
