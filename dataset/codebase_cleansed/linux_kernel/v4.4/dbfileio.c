void acpi_db_close_debug_file(void)
{
#ifdef ACPI_APPLICATION
if (acpi_gbl_debug_file) {
fclose(acpi_gbl_debug_file);
acpi_gbl_debug_file = NULL;
acpi_gbl_db_output_to_file = FALSE;
acpi_os_printf("Debug output file %s closed\n",
acpi_gbl_db_debug_filename);
}
#endif
}
void acpi_db_open_debug_file(char *name)
{
#ifdef ACPI_APPLICATION
acpi_db_close_debug_file();
acpi_gbl_debug_file = fopen(name, "w+");
if (!acpi_gbl_debug_file) {
acpi_os_printf("Could not open debug file %s\n", name);
return;
}
acpi_os_printf("Debug output file %s opened\n", name);
strncpy(acpi_gbl_db_debug_filename, name,
sizeof(acpi_gbl_db_debug_filename));
acpi_gbl_db_output_to_file = TRUE;
#endif
}
static acpi_status ae_local_load_table(struct acpi_table_header *table)
{
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(ae_local_load_table);
#if 0
if (!table) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
table_info.pointer = table;
status = acpi_tb_recognize_table(&table_info, ACPI_TABLE_ALL);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_tb_init_table_descriptor(&table_info);
if (ACPI_FAILURE(status)) {
if (status == AE_ALREADY_EXISTS) {
status = AE_OK;
}
acpi_tb_delete_single_table(&table_info);
return_ACPI_STATUS(status);
}
#if (!defined (ACPI_NO_METHOD_EXECUTION) && !defined (ACPI_CONSTANT_EVAL_ONLY))
status =
acpi_ns_load_table(table_info.installed_desc, acpi_gbl_root_node);
if (ACPI_FAILURE(status)) {
acpi_tb_delete_tables_by_type(ACPI_TABLE_ID_DSDT);
return_ACPI_STATUS(status);
}
#endif
#endif
return_ACPI_STATUS(status);
}
acpi_status
acpi_db_get_table_from_file(char *filename,
struct acpi_table_header **return_table,
u8 must_be_aml_file)
{
#ifdef ACPI_APPLICATION
acpi_status status;
struct acpi_table_header *table;
u8 is_aml_table = TRUE;
status = acpi_ut_read_table_from_file(filename, &table);
if (ACPI_FAILURE(status)) {
return (status);
}
if (must_be_aml_file) {
is_aml_table = acpi_ut_is_aml_table(table);
if (!is_aml_table) {
ACPI_EXCEPTION((AE_INFO, AE_OK,
"Input for -e is not an AML table: "
"\"%4.4s\" (must be DSDT/SSDT)",
table->signature));
return (AE_TYPE);
}
}
if (is_aml_table) {
status = ae_local_load_table(table);
if (ACPI_FAILURE(status)) {
if (status == AE_ALREADY_EXISTS) {
acpi_os_printf
("Table %4.4s is already installed\n",
table->signature);
} else {
acpi_os_printf("Could not install table, %s\n",
acpi_format_exception(status));
}
return (status);
}
acpi_tb_print_table_header(0, table);
fprintf(stderr,
"Acpi table [%4.4s] successfully installed and loaded\n",
table->signature);
}
acpi_gbl_acpi_hardware_present = FALSE;
if (return_table) {
*return_table = table;
}
#endif
return (AE_OK);
}
