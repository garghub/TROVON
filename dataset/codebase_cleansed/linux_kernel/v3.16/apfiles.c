int ap_open_output_file(char *pathname)
{
struct stat stat_info;
FILE *file;
if (!stat(pathname, &stat_info)) {
fprintf(stderr,
"Target path already exists, overwrite? [y|n] ");
if (getchar() != 'y') {
return (-1);
}
}
file = freopen(pathname, "w", stdout);
if (!file) {
perror("Could not open output file");
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
FILE *file;
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
sprintf(instance_str, "%u", instance);
strcat(filename, instance_str);
}
strcat(filename, ACPI_TABLE_FILE_SUFFIX);
if (gbl_verbose_mode) {
fprintf(stderr,
"Writing [%4.4s] to binary file: %s 0x%X (%u) bytes\n",
table->signature, filename, table->length,
table->length);
}
file = fopen(filename, "wb");
if (!file) {
perror("Could not open output file");
return (-1);
}
actual = fwrite(table, 1, table_length, file);
if (actual != table_length) {
perror("Error writing binary output file");
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
FILE *file;
u32 file_size;
size_t actual;
file = fopen(pathname, "rb");
if (!file) {
perror("Could not open input file");
return (NULL);
}
file_size = cm_get_file_size(file);
if (file_size == ACPI_UINT32_MAX) {
fprintf(stderr,
"Could not get input file size: %s\n", pathname);
goto cleanup;
}
buffer = calloc(1, file_size);
if (!buffer) {
fprintf(stderr,
"Could not allocate file buffer of size: %u\n",
file_size);
goto cleanup;
}
actual = fread(buffer, 1, file_size, file);
if (actual != file_size) {
fprintf(stderr, "Could not read input file: %s\n", pathname);
free(buffer);
buffer = NULL;
goto cleanup;
}
*out_file_size = file_size;
cleanup:
fclose(file);
return (buffer);
}
