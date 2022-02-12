static acpi_status
acpi_ut_check_text_mode_corruption(u8 *table, u32 table_length, u32 file_length)
{
u32 i;
u32 pairs = 0;
if (table_length != file_length) {
ACPI_WARNING((AE_INFO,
"File length (0x%X) is not the same as the table length (0x%X)",
file_length, table_length));
}
for (i = 1; i < file_length; i++) {
if (table[i] == 0x0A) {
if (table[i - 1] != 0x0D) {
return (AE_OK);
} else {
pairs++;
}
i++;
}
}
if (!pairs) {
return (AE_OK);
}
acpi_os_printf("Table has been corrupted by text mode conversion\n");
acpi_os_printf("All LFs (%u) were changed to CR/LF pairs\n", pairs);
acpi_os_printf("Table cannot be repaired!\n");
return (AE_BAD_VALUE);
}
static acpi_status
acpi_ut_read_table(FILE * fp,
struct acpi_table_header **table, u32 *table_length)
{
struct acpi_table_header table_header;
u32 actual;
acpi_status status;
u32 file_size;
u8 standard_header = TRUE;
s32 count;
file_size = cm_get_file_size(fp);
if (file_size == ACPI_UINT32_MAX) {
return (AE_ERROR);
}
if (file_size < 4) {
return (AE_BAD_HEADER);
}
fseek(fp, 0, SEEK_SET);
count = fread(&table_header, 1, sizeof(struct acpi_table_header), fp);
if (count != sizeof(struct acpi_table_header)) {
acpi_os_printf("Could not read the table header\n");
return (AE_BAD_HEADER);
}
if (ACPI_VALIDATE_RSDP_SIG(table_header.signature)) {
*table_length = file_size;
standard_header = FALSE;
} else {
#if 0
status = acpi_tb_validate_table_header(&table_header);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Table header is invalid!\n");
return (status);
}
#endif
if (table_header.length > file_size) {
acpi_os_printf
("TableHeader length [0x%X] greater than the input file size [0x%X]\n",
table_header.length, file_size);
#ifdef ACPI_ASL_COMPILER
status = fl_check_for_ascii(fp, NULL, FALSE);
if (ACPI_SUCCESS(status)) {
acpi_os_printf
("File appears to be ASCII only, must be binary\n");
}
#endif
return (AE_BAD_HEADER);
}
#ifdef ACPI_OBSOLETE_CODE
if (!ACPI_COMPARE_NAME
((char *)table_header.signature, ACPI_SIG_DSDT)
&& !ACPI_COMPARE_NAME((char *)table_header.signature,
ACPI_SIG_PSDT)
&& !ACPI_COMPARE_NAME((char *)table_header.signature,
ACPI_SIG_SSDT)) {
acpi_os_printf
("Table signature [%4.4s] is invalid or not supported\n",
(char *)table_header.signature);
ACPI_DUMP_BUFFER(&table_header,
sizeof(struct acpi_table_header));
return (AE_ERROR);
}
#endif
*table_length = table_header.length;
}
*table = acpi_os_allocate((size_t) file_size);
if (!*table) {
acpi_os_printf
("Could not allocate memory for ACPI table %4.4s (size=0x%X)\n",
table_header.signature, *table_length);
return (AE_NO_MEMORY);
}
fseek(fp, 0, SEEK_SET);
actual = fread(*table, 1, (size_t) file_size, fp);
if (actual == file_size) {
if (standard_header) {
status = acpi_tb_verify_checksum((void *)*table,
ACPI_CAST_PTR(struct
acpi_table_header,
*table)->
length);
if (status == AE_BAD_CHECKSUM) {
status =
acpi_ut_check_text_mode_corruption((u8 *)
*table,
file_size,
(*table)->
length);
return (status);
}
}
return (AE_OK);
}
if (actual > 0) {
acpi_os_printf("Warning - reading table, asked for %X got %X\n",
file_size, actual);
return (AE_OK);
}
acpi_os_printf("Error - could not read the table file\n");
acpi_os_free(*table);
*table = NULL;
*table_length = 0;
return (AE_ERROR);
}
acpi_status
acpi_ut_read_table_from_file(char *filename, struct acpi_table_header ** table)
{
FILE *file;
u32 file_size;
u32 table_length;
acpi_status status = AE_ERROR;
file = fopen(filename, "rb");
if (!file) {
perror("Could not open input file");
return (status);
}
file_size = cm_get_file_size(file);
if (file_size == ACPI_UINT32_MAX) {
goto exit;
}
fprintf(stderr,
"Loading Acpi table from file %10s - Length %.8u (%06X)\n",
filename, file_size, file_size);
status = acpi_ut_read_table(file, table, &table_length);
if (ACPI_FAILURE(status)) {
acpi_os_printf("Could not get table from the file\n");
}
exit:
fclose(file);
return (status);
}
