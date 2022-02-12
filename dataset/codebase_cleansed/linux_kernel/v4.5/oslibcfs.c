ACPI_FILE acpi_os_open_file(const char *path, u8 modes)
{
ACPI_FILE file;
u32 i = 0;
char modes_str[4];
if (modes & ACPI_FILE_READING) {
modes_str[i++] = 'r';
}
if (modes & ACPI_FILE_WRITING) {
modes_str[i++] = 'w';
}
if (modes & ACPI_FILE_BINARY) {
modes_str[i++] = 'b';
}
modes_str[i++] = '\0';
file = fopen(path, modes_str);
if (!file) {
perror("Could not open file");
}
return (file);
}
void acpi_os_close_file(ACPI_FILE file)
{
fclose(file);
}
int
acpi_os_read_file(ACPI_FILE file, void *buffer, acpi_size size, acpi_size count)
{
int length;
length = fread(buffer, size, count, file);
if (length < 0) {
perror("Error reading file");
}
return (length);
}
int
acpi_os_write_file(ACPI_FILE file,
void *buffer, acpi_size size, acpi_size count)
{
int length;
length = fwrite(buffer, size, count, file);
if (length < 0) {
perror("Error writing file");
}
return (length);
}
long acpi_os_get_file_offset(ACPI_FILE file)
{
long offset;
offset = ftell(file);
return (offset);
}
acpi_status acpi_os_set_file_offset(ACPI_FILE file, long offset, u8 from)
{
int ret = 0;
if (from == ACPI_FILE_BEGIN) {
ret = fseek(file, offset, SEEK_SET);
}
if (from == ACPI_FILE_END) {
ret = fseek(file, offset, SEEK_END);
}
if (ret < 0) {
return (AE_ERROR);
} else {
return (AE_OK);
}
}
