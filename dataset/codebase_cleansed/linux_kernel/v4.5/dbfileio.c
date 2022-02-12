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
acpi_status acpi_db_load_tables(struct acpi_new_table_desc *list_head)
{
acpi_status status;
struct acpi_new_table_desc *table_list_head;
struct acpi_table_header *table;
table_list_head = list_head;
while (table_list_head) {
table = table_list_head->table;
status = acpi_load_table(table);
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
fprintf(stderr,
"Acpi table [%4.4s] successfully installed and loaded\n",
table->signature);
table_list_head = table_list_head->next;
}
return (AE_OK);
}
