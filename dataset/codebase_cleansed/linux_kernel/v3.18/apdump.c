u8 ap_is_valid_header(struct acpi_table_header *table)
{
if (!ACPI_VALIDATE_RSDP_SIG(table->signature)) {
if (!acpi_ut_valid_acpi_name(table->signature)) {
acpi_log_error("Table signature (0x%8.8X) is invalid\n",
*(u32 *)table->signature);
return (FALSE);
}
if (table->length < sizeof(struct acpi_table_header)) {
acpi_log_error("Table length (0x%8.8X) is invalid\n",
table->length);
return (FALSE);
}
}
return (TRUE);
}
u8 ap_is_valid_checksum(struct acpi_table_header *table)
{
acpi_status status;
struct acpi_table_rsdp *rsdp;
if (ACPI_VALIDATE_RSDP_SIG(table->signature)) {
rsdp = ACPI_CAST_PTR(struct acpi_table_rsdp, table);
status = acpi_tb_validate_rsdp(rsdp);
} else {
status = acpi_tb_verify_checksum(table, table->length);
}
if (ACPI_FAILURE(status)) {
acpi_log_error("%4.4s: Warning: wrong checksum in table\n",
table->signature);
}
return (AE_OK);
}
u32 ap_get_table_length(struct acpi_table_header *table)
{
struct acpi_table_rsdp *rsdp;
if (!ap_is_valid_header(table)) {
return (0);
}
if (ACPI_VALIDATE_RSDP_SIG(table->signature)) {
rsdp = ACPI_CAST_PTR(struct acpi_table_rsdp, table);
return (acpi_tb_get_rsdp_length(rsdp));
}
return (table->length);
}
static int
ap_dump_table_buffer(struct acpi_table_header *table,
u32 instance, acpi_physical_address address)
{
u32 table_length;
table_length = ap_get_table_length(table);
if (gbl_summary_mode) {
acpi_tb_print_table_header(address, table);
return (0);
}
if (gbl_binary_mode) {
return (ap_write_to_binary_file(table, instance));
}
acpi_ut_file_printf(gbl_output_file, "%4.4s @ 0x%8.8X%8.8X\n",
table->signature, ACPI_FORMAT_UINT64(address));
acpi_ut_dump_buffer_to_file(gbl_output_file,
ACPI_CAST_PTR(u8, table), table_length,
DB_BYTE_DISPLAY, 0);
acpi_ut_file_printf(gbl_output_file, "\n");
return (0);
}
int ap_dump_all_tables(void)
{
struct acpi_table_header *table;
u32 instance = 0;
acpi_physical_address address;
acpi_status status;
int table_status;
u32 i;
for (i = 0; i < AP_MAX_ACPI_FILES; i++) {
status =
acpi_os_get_table_by_index(i, &table, &instance, &address);
if (ACPI_FAILURE(status)) {
if (status == AE_LIMIT) {
return (0);
} else if (i == 0) {
acpi_log_error
("Could not get ACPI tables, %s\n",
acpi_format_exception(status));
return (-1);
} else {
acpi_log_error
("Could not get ACPI table at index %u, %s\n",
i, acpi_format_exception(status));
continue;
}
}
table_status = ap_dump_table_buffer(table, instance, address);
ACPI_FREE(table);
if (table_status) {
break;
}
}
return (-1);
}
int ap_dump_table_by_address(char *ascii_address)
{
acpi_physical_address address;
struct acpi_table_header *table;
acpi_status status;
int table_status;
u64 long_address;
status = acpi_ut_strtoul64(ascii_address, 0, &long_address);
if (ACPI_FAILURE(status)) {
acpi_log_error("%s: Could not convert to a physical address\n",
ascii_address);
return (-1);
}
address = (acpi_physical_address) long_address;
status = acpi_os_get_table_by_address(address, &table);
if (ACPI_FAILURE(status)) {
acpi_log_error("Could not get table at 0x%8.8X%8.8X, %s\n",
ACPI_FORMAT_UINT64(address),
acpi_format_exception(status));
return (-1);
}
table_status = ap_dump_table_buffer(table, 0, address);
ACPI_FREE(table);
return (table_status);
}
int ap_dump_table_by_name(char *signature)
{
char local_signature[ACPI_NAME_SIZE + 1];
u32 instance;
struct acpi_table_header *table;
acpi_physical_address address;
acpi_status status;
int table_status;
if (ACPI_STRLEN(signature) != ACPI_NAME_SIZE) {
acpi_log_error
("Invalid table signature [%s]: must be exactly 4 characters\n",
signature);
return (-1);
}
ACPI_STRCPY(local_signature, signature);
acpi_ut_strupr(local_signature);
if (ACPI_COMPARE_NAME(local_signature, "FADT")) {
ACPI_STRCPY(local_signature, ACPI_SIG_FADT);
} else if (ACPI_COMPARE_NAME(local_signature, "MADT")) {
ACPI_STRCPY(local_signature, ACPI_SIG_MADT);
}
for (instance = 0; instance < AP_MAX_ACPI_FILES; instance++) {
status = acpi_os_get_table_by_name(local_signature, instance,
&table, &address);
if (ACPI_FAILURE(status)) {
if (status == AE_LIMIT) {
return (0);
}
acpi_log_error
("Could not get ACPI table with signature [%s], %s\n",
local_signature, acpi_format_exception(status));
return (-1);
}
table_status = ap_dump_table_buffer(table, instance, address);
ACPI_FREE(table);
if (table_status) {
break;
}
}
return (-1);
}
int ap_dump_table_from_file(char *pathname)
{
struct acpi_table_header *table;
u32 file_size = 0;
int table_status = -1;
table = ap_get_table_from_file(pathname, &file_size);
if (!table) {
return (-1);
}
if (table->length > file_size) {
acpi_log_error
("Table length (0x%X) is too large for input file (0x%X) %s\n",
table->length, file_size, pathname);
goto exit;
}
if (gbl_verbose_mode) {
acpi_log_error
("Input file: %s contains table [%4.4s], 0x%X (%u) bytes\n",
pathname, table->signature, file_size, file_size);
}
table_status = ap_dump_table_buffer(table, 0, 0);
exit:
ACPI_FREE(table);
return (table_status);
}
