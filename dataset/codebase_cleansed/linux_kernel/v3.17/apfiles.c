static int ap_is_existing_file(char *pathname)
{
#ifndef _GNU_EFI
struct stat stat_info;
if (!stat(pathname, &stat_info)) {
acpi_log_error("Target path already exists, overwrite? [y|n] ");
if (getchar() != 'y') {
return (-1);
}
}
#endif
return 0;
}
int ap_open_output_file(char *pathname)
{
ACPI_FILE file;
if (ap_is_existing_file(pathname) != 0) {
return (-1);
}
file = acpi_os_open_file(pathname, ACPI_FILE_WRITING);
if (!file) {
acpi_log_error("Could not open output file: %s\n", pathname);
return (-1);
}
gbl_output_file = file;
gbl_output_filename = pathname;
return (0);
}
int ap_write_to_binary_file(struct acpi_table_header *table, u32 instance)
{
char filename[ACPI_NAME_SIZE + 16];
char instance_str[16];
ACPI_FILE file;
size_t actual;
u32 table_length;
table_length = ap_get_table_length(table);
if (ACPI_VALIDATE_RSDP_SIG(table->signature)) {
ACPI_MOVE_NAME(filename, ACPI_RSDP_NAME);
} else {
ACPI_MOVE_NAME(filename, table->signature);
}
filename[0] = (char)ACPI_TOLOWER(filename[0]);
filename[1] = (char)ACPI_TOLOWER(filename[1]);
filename[2] = (char)ACPI_TOLOWER(filename[2]);
filename[3] = (char)ACPI_TOLOWER(filename[3]);
filename[ACPI_NAME_SIZE] = 0;
if (instance > 0) {
acpi_ut_snprintf(instance_str, sizeof(instance_str), "%u",
instance);
ACPI_STRCAT(filename, instance_str);
}
ACPI_STRCAT(filename, ACPI_TABLE_FILE_SUFFIX);
if (gbl_verbose_mode) {
acpi_log_error
("Writing [%4.4s] to binary file: %s 0x%X (%u) bytes\n",
table->signature, filename, table->length, table->length);
}
file = acpi_os_open_file(filename,
ACPI_FILE_WRITING | ACPI_FILE_BINARY);
if (!file) {
acpi_log_error("Could not open output file: %s\n", filename);
return (-1);
}
actual = acpi_os_write_file(file, table, 1, table_length);
if (actual != table_length) {
acpi_log_error("Error writing binary output file: %s\n",
filename);
acpi_os_close_file(file);
return (-1);
}
acpi_os_close_file(file);
return (0);
}
struct acpi_table_header *ap_get_table_from_file(char *pathname,
u32 *out_file_size)
{
struct acpi_table_header *buffer = NULL;
ACPI_FILE file;
u32 file_size;
size_t actual;
file =
acpi_os_open_file(pathname, ACPI_FILE_READING | ACPI_FILE_BINARY);
if (!file) {
acpi_log_error("Could not open input file: %s\n", pathname);
return (NULL);
}
file_size = cm_get_file_size(file);
if (file_size == ACPI_UINT32_MAX) {
acpi_log_error("Could not get input file size: %s\n", pathname);
goto cleanup;
}
buffer = ACPI_ALLOCATE_ZEROED(file_size);
if (!buffer) {
acpi_log_error("Could not allocate file buffer of size: %u\n",
file_size);
goto cleanup;
}
actual = acpi_os_read_file(file, buffer, 1, file_size);
if (actual != file_size) {
acpi_log_error("Could not read input file: %s\n", pathname);
ACPI_FREE(buffer);
buffer = NULL;
goto cleanup;
}
*out_file_size = file_size;
cleanup:
acpi_os_close_file(file);
return (buffer);
}
