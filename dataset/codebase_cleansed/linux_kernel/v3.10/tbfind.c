acpi_status
acpi_tb_find_table(char *signature,
char *oem_id, char *oem_table_id, u32 *table_index)
{
u32 i;
acpi_status status;
struct acpi_table_header header;
ACPI_FUNCTION_TRACE(tb_find_table);
ACPI_MEMSET(&header, 0, sizeof(struct acpi_table_header));
ACPI_MOVE_NAME(header.signature, signature);
ACPI_STRNCPY(header.oem_id, oem_id, ACPI_OEM_ID_SIZE);
ACPI_STRNCPY(header.oem_table_id, oem_table_id, ACPI_OEM_TABLE_ID_SIZE);
for (i = 0; i < acpi_gbl_root_table_list.current_table_count; ++i) {
if (ACPI_MEMCMP(&(acpi_gbl_root_table_list.tables[i].signature),
header.signature, ACPI_NAME_SIZE)) {
continue;
}
if (!acpi_gbl_root_table_list.tables[i].pointer) {
status =
acpi_tb_verify_table(&acpi_gbl_root_table_list.
tables[i]);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (!acpi_gbl_root_table_list.tables[i].pointer) {
continue;
}
}
if (!ACPI_MEMCMP
(acpi_gbl_root_table_list.tables[i].pointer->signature,
header.signature, ACPI_NAME_SIZE) && (!oem_id[0]
||
!ACPI_MEMCMP
(acpi_gbl_root_table_list.
tables[i].pointer->
oem_id,
header.oem_id,
ACPI_OEM_ID_SIZE))
&& (!oem_table_id[0]
|| !ACPI_MEMCMP(acpi_gbl_root_table_list.tables[i].
pointer->oem_table_id,
header.oem_table_id,
ACPI_OEM_TABLE_ID_SIZE))) {
*table_index = i;
ACPI_DEBUG_PRINT((ACPI_DB_TABLES,
"Found table [%4.4s]\n",
header.signature));
return_ACPI_STATUS(AE_OK);
}
}
return_ACPI_STATUS(AE_NOT_FOUND);
}
