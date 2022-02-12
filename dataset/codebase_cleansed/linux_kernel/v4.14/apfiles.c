static int ap_is_existing_file(char *pathname)
{
#if !defined(_GNU_EFI) && !defined(_EDK2_EFI)
struct stat stat_info;
if (!stat(pathname, &stat_info)) {
fprintf(stderr,
"Target path already exists, overwrite? [y|n] ");
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
file = fopen(pathname, "w");
if (!file) {
fprintf(stderr, "Could not open output file: %s\n", pathname);
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
acpi_size actual;
u32 table_length;
table_length = ap_get_table_length(table);
if (ACPI_VALIDATE_RSDP_SIG(table->signature)) {
ACPI_MOVE_NAME(filename, ACPI_RSDP_NAME);
} else {
ACPI_MOVE_NAME(filename, table->signature);
}
filename[0] = (char)tolower((int)filename[0]);
filename[1] = (char)tolower((int)filename[1]);
filename[2] = (char)tolower((int)filename[2]);
filename[3] = (char)tolower((int)filename[3]);
filename[ACPI_NAME_SIZE] = 0;
if (instance > 0) {
snprintf(instance_str, sizeof(instance_str), "%u", instance);
strcat(filename, instance_str);
}
strcat(filename, FILE_SUFFIX_BINARY_TABLE);
if (gbl_verbose_mode) {
fprintf(stderr,
"Writing [%4.4s] to binary file: %s 0x%X (%u) bytes\n",
table->signature, filename, table->length,
table->length);
}
file = fopen(filename, "wb");
if (!file) {
fprintf(stderr, "Could not open output file: %s\n", filename);
return (-1);
}
actual = fwrite(table, 1, table_length, file);
if (actual != table_length) {
fprintf(stderr, "Error writing binary output file: %s\n",
filename);
fclose(file);
return (-1);
}
fclose(file);
return (0);
}
struct acpi_table_header *ap_get_table_from_file(char *pathname,
u32 *out_file_size)
{
struct acpi_table_header *buffer = NULL;
ACPI_FILE file;
u32 file_size;
acpi_size actual;
file = fopen(pathname, "rb");
if (!file) {
fprintf(stderr, "Could not open input file: %s\n", pathname);
return (NULL);
}
file_size = cm_get_file_size(file);
if (file_size == ACPI_UINT32_MAX) {
fprintf(stderr,
"Could not get input file size: %s\n", pathname);
goto cleanup;
}
buffer = ACPI_ALLOCATE_ZEROED(file_size);
if (!buffer) {
fprintf(stderr,
"Could not allocate file buffer of size: %u\n",
file_size);
goto cleanup;
}
actual = fread(buffer, 1, file_size, file);
if (actual != file_size) {
fprintf(stderr, "Could not read input file: %s\n", pathname);
ACPI_FREE(buffer);
buffer = NULL;
goto cleanup;
}
*out_file_size = file_size;
cleanup:
fclose(file);
return (buffer);
}
