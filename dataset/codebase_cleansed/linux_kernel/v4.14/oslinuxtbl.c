static acpi_status osl_get_last_status(acpi_status default_status)
{
switch (errno) {
case EACCES:
case EPERM:
return (AE_ACCESS);
case ENOENT:
return (AE_NOT_FOUND);
case ENOMEM:
return (AE_NO_MEMORY);
default:
return (default_status);
}
}
acpi_status
acpi_os_get_table_by_address(acpi_physical_address address,
struct acpi_table_header **table)
{
u32 table_length;
struct acpi_table_header *mapped_table;
struct acpi_table_header *local_table = NULL;
acpi_status status = AE_OK;
status = osl_table_initialize();
if (ACPI_FAILURE(status)) {
return (status);
}
status = osl_map_table(address, NULL, &mapped_table);
if (ACPI_FAILURE(status)) {
return (status);
}
table_length = ap_get_table_length(mapped_table);
if (table_length == 0) {
status = AE_BAD_HEADER;
goto exit;
}
local_table = calloc(1, table_length);
if (!local_table) {
status = AE_NO_MEMORY;
goto exit;
}
memcpy(local_table, mapped_table, table_length);
exit:
osl_unmap_table(mapped_table);
*table = local_table;
return (status);
}
acpi_status
acpi_os_get_table_by_name(char *signature,
u32 instance,
struct acpi_table_header **table,
acpi_physical_address *address)
{
acpi_status status;
status = osl_table_initialize();
if (ACPI_FAILURE(status)) {
return (status);
}
if (!gbl_dump_customized_tables) {
status =
osl_get_bios_table(signature, instance, table, address);
} else {
status = osl_get_customized_table(STATIC_TABLE_DIR, signature,
instance, table, address);
}
if (ACPI_FAILURE(status) && status == AE_LIMIT) {
if (gbl_dump_dynamic_tables) {
status =
osl_get_customized_table(DYNAMIC_TABLE_DIR,
signature, instance, table,
address);
}
}
return (status);
}
static acpi_status osl_add_table_to_list(char *signature, u32 instance)
{
struct osl_table_info *new_info;
struct osl_table_info *next;
u32 next_instance = 0;
u8 found = FALSE;
new_info = calloc(1, sizeof(struct osl_table_info));
if (!new_info) {
return (AE_NO_MEMORY);
}
ACPI_MOVE_NAME(new_info->signature, signature);
if (!gbl_table_list_head) {
gbl_table_list_head = new_info;
} else {
next = gbl_table_list_head;
while (1) {
if (ACPI_COMPARE_NAME(next->signature, signature)) {
if (next->instance == instance) {
found = TRUE;
}
if (next->instance >= next_instance) {
next_instance = next->instance + 1;
}
}
if (!next->next) {
break;
}
next = next->next;
}
next->next = new_info;
}
if (found) {
if (instance) {
fprintf(stderr,
"%4.4s: Warning unmatched table instance %d, expected %d\n",
signature, instance, next_instance);
}
instance = next_instance;
}
new_info->instance = instance;
gbl_table_count++;
return (AE_OK);
}
acpi_status
acpi_os_get_table_by_index(u32 index,
struct acpi_table_header **table,
u32 *instance, acpi_physical_address *address)
{
struct osl_table_info *info;
acpi_status status;
u32 i;
status = osl_table_initialize();
if (ACPI_FAILURE(status)) {
return (status);
}
if (index >= gbl_table_count) {
return (AE_LIMIT);
}
info = gbl_table_list_head;
for (i = 0; i < index; i++) {
info = info->next;
}
status = acpi_os_get_table_by_name(info->signature, info->instance,
table, address);
if (ACPI_SUCCESS(status)) {
*instance = info->instance;
}
return (status);
}
static acpi_physical_address
osl_find_rsdp_via_efi_by_keyword(FILE * file, const char *keyword)
{
char buffer[80];
unsigned long long address = 0;
char format[32];
snprintf(format, 32, "%s=%s", keyword, "%llx");
fseek(file, 0, SEEK_SET);
while (fgets(buffer, 80, file)) {
if (sscanf(buffer, format, &address) == 1) {
break;
}
}
return ((acpi_physical_address)(address));
}
static acpi_physical_address osl_find_rsdp_via_efi(void)
{
FILE *file;
acpi_physical_address address = 0;
file = fopen(EFI_SYSTAB, "r");
if (file) {
address = osl_find_rsdp_via_efi_by_keyword(file, "ACPI20");
if (!address) {
address =
osl_find_rsdp_via_efi_by_keyword(file, "ACPI");
}
fclose(file);
}
return (address);
}
static acpi_status osl_load_rsdp(void)
{
struct acpi_table_header *mapped_table;
u8 *rsdp_address;
acpi_physical_address rsdp_base;
acpi_size rsdp_size;
rsdp_size = sizeof(struct acpi_table_rsdp);
if (gbl_rsdp_base) {
rsdp_base = gbl_rsdp_base;
} else {
rsdp_base = osl_find_rsdp_via_efi();
}
if (!rsdp_base) {
rsdp_base = ACPI_HI_RSDP_WINDOW_BASE;
rsdp_size = ACPI_HI_RSDP_WINDOW_SIZE;
}
rsdp_address = acpi_os_map_memory(rsdp_base, rsdp_size);
if (!rsdp_address) {
return (osl_get_last_status(AE_BAD_ADDRESS));
}
mapped_table = ACPI_CAST_PTR(struct acpi_table_header,
acpi_tb_scan_memory_for_rsdp(rsdp_address,
rsdp_size));
if (!mapped_table) {
acpi_os_unmap_memory(rsdp_address, rsdp_size);
return (AE_NOT_FOUND);
}
gbl_rsdp_address =
rsdp_base + (ACPI_CAST8(mapped_table) - rsdp_address);
memcpy(&gbl_rsdp, mapped_table, sizeof(struct acpi_table_rsdp));
acpi_os_unmap_memory(rsdp_address, rsdp_size);
return (AE_OK);
}
static u8 osl_can_use_xsdt(void)
{
if (gbl_revision && !acpi_gbl_do_not_use_xsdt) {
return (TRUE);
} else {
return (FALSE);
}
}
static acpi_status osl_table_initialize(void)
{
acpi_status status;
acpi_physical_address address;
if (gbl_table_list_initialized) {
return (AE_OK);
}
if (!gbl_dump_customized_tables) {
status = osl_load_rsdp();
if (ACPI_FAILURE(status)) {
return (status);
}
if (gbl_rsdp.revision && !gbl_do_not_dump_xsdt) {
if (gbl_xsdt) {
free(gbl_xsdt);
gbl_xsdt = NULL;
}
gbl_revision = 2;
status = osl_get_bios_table(ACPI_SIG_XSDT, 0,
ACPI_CAST_PTR(struct
acpi_table_header
*, &gbl_xsdt),
&address);
if (ACPI_FAILURE(status)) {
return (status);
}
}
if (gbl_rsdp.rsdt_physical_address) {
if (gbl_rsdt) {
free(gbl_rsdt);
gbl_rsdt = NULL;
}
status = osl_get_bios_table(ACPI_SIG_RSDT, 0,
ACPI_CAST_PTR(struct
acpi_table_header
*, &gbl_rsdt),
&address);
if (ACPI_FAILURE(status)) {
return (status);
}
}
if (gbl_fadt) {
free(gbl_fadt);
gbl_fadt = NULL;
}
status = osl_get_bios_table(ACPI_SIG_FADT, 0,
ACPI_CAST_PTR(struct
acpi_table_header *,
&gbl_fadt),
&gbl_fadt_address);
if (ACPI_FAILURE(status)) {
return (status);
}
status = osl_add_table_to_list(ACPI_RSDP_NAME, 0);
if (ACPI_FAILURE(status)) {
return (status);
}
status = osl_add_table_to_list(ACPI_SIG_RSDT, 0);
if (ACPI_FAILURE(status)) {
return (status);
}
if (gbl_revision == 2) {
status = osl_add_table_to_list(ACPI_SIG_XSDT, 0);
if (ACPI_FAILURE(status)) {
return (status);
}
}
status = osl_add_table_to_list(ACPI_SIG_DSDT, 0);
if (ACPI_FAILURE(status)) {
return (status);
}
status = osl_add_table_to_list(ACPI_SIG_FACS, 0);
if (ACPI_FAILURE(status)) {
return (status);
}
status = osl_list_bios_tables();
if (ACPI_FAILURE(status)) {
return (status);
}
} else {
status = osl_list_customized_tables(STATIC_TABLE_DIR);
if (ACPI_FAILURE(status)) {
return (status);
}
}
if (gbl_dump_dynamic_tables) {
status = osl_list_customized_tables(DYNAMIC_TABLE_DIR);
if (ACPI_FAILURE(status)) {
return (status);
}
}
gbl_table_list_initialized = TRUE;
return (AE_OK);
}
static acpi_status osl_list_bios_tables(void)
{
struct acpi_table_header *mapped_table = NULL;
u8 *table_data;
u8 number_of_tables;
u8 item_size;
acpi_physical_address table_address = 0;
acpi_status status = AE_OK;
u32 i;
if (osl_can_use_xsdt()) {
item_size = sizeof(u64);
table_data =
ACPI_CAST8(gbl_xsdt) + sizeof(struct acpi_table_header);
number_of_tables =
(u8)((gbl_xsdt->header.length -
sizeof(struct acpi_table_header))
/ item_size);
} else {
item_size = sizeof(u32);
table_data =
ACPI_CAST8(gbl_rsdt) + sizeof(struct acpi_table_header);
number_of_tables =
(u8)((gbl_rsdt->header.length -
sizeof(struct acpi_table_header))
/ item_size);
}
for (i = 0; i < number_of_tables; ++i, table_data += item_size) {
if (osl_can_use_xsdt()) {
table_address =
(acpi_physical_address)(*ACPI_CAST64(table_data));
} else {
table_address =
(acpi_physical_address)(*ACPI_CAST32(table_data));
}
if (table_address == 0) {
continue;
}
status = osl_map_table(table_address, NULL, &mapped_table);
if (ACPI_FAILURE(status)) {
return (status);
}
osl_add_table_to_list(mapped_table->signature, 0);
osl_unmap_table(mapped_table);
}
return (AE_OK);
}
static acpi_status
osl_get_bios_table(char *signature,
u32 instance,
struct acpi_table_header **table,
acpi_physical_address *address)
{
struct acpi_table_header *local_table = NULL;
struct acpi_table_header *mapped_table = NULL;
u8 *table_data;
u8 number_of_tables;
u8 item_size;
u32 current_instance = 0;
acpi_physical_address table_address;
acpi_physical_address first_table_address = 0;
u32 table_length = 0;
acpi_status status = AE_OK;
u32 i;
if (ACPI_COMPARE_NAME(signature, ACPI_RSDP_NAME) ||
ACPI_COMPARE_NAME(signature, ACPI_SIG_RSDT) ||
ACPI_COMPARE_NAME(signature, ACPI_SIG_XSDT) ||
ACPI_COMPARE_NAME(signature, ACPI_SIG_DSDT) ||
ACPI_COMPARE_NAME(signature, ACPI_SIG_FACS)) {
find_next_instance:
table_address = 0;
if (ACPI_COMPARE_NAME(signature, ACPI_SIG_DSDT)) {
if (current_instance < 2) {
if ((gbl_fadt->header.length >=
MIN_FADT_FOR_XDSDT) && gbl_fadt->Xdsdt
&& current_instance == 0) {
table_address =
(acpi_physical_address)gbl_fadt->
Xdsdt;
} else
if ((gbl_fadt->header.length >=
MIN_FADT_FOR_DSDT)
&& gbl_fadt->dsdt !=
first_table_address) {
table_address =
(acpi_physical_address)gbl_fadt->
dsdt;
}
}
} else if (ACPI_COMPARE_NAME(signature, ACPI_SIG_FACS)) {
if (current_instance < 2) {
if ((gbl_fadt->header.length >=
MIN_FADT_FOR_XFACS) && gbl_fadt->Xfacs
&& current_instance == 0) {
table_address =
(acpi_physical_address)gbl_fadt->
Xfacs;
} else
if ((gbl_fadt->header.length >=
MIN_FADT_FOR_FACS)
&& gbl_fadt->facs !=
first_table_address) {
table_address =
(acpi_physical_address)gbl_fadt->
facs;
}
}
} else if (ACPI_COMPARE_NAME(signature, ACPI_SIG_XSDT)) {
if (!gbl_revision) {
return (AE_BAD_SIGNATURE);
}
if (current_instance == 0) {
table_address =
(acpi_physical_address)gbl_rsdp.
xsdt_physical_address;
}
} else if (ACPI_COMPARE_NAME(signature, ACPI_SIG_RSDT)) {
if (current_instance == 0) {
table_address =
(acpi_physical_address)gbl_rsdp.
rsdt_physical_address;
}
} else {
if (current_instance == 0) {
table_address =
(acpi_physical_address)gbl_rsdp_address;
signature = ACPI_SIG_RSDP;
}
}
if (table_address == 0) {
goto exit_find_table;
}
status = osl_map_table(table_address, signature, &mapped_table);
if (ACPI_FAILURE(status)) {
return (status);
}
table_length = ap_get_table_length(mapped_table);
if (first_table_address == 0) {
first_table_address = table_address;
}
if (current_instance != instance) {
osl_unmap_table(mapped_table);
mapped_table = NULL;
current_instance++;
goto find_next_instance;
}
} else {
if (osl_can_use_xsdt()) {
item_size = sizeof(u64);
table_data =
ACPI_CAST8(gbl_xsdt) +
sizeof(struct acpi_table_header);
number_of_tables =
(u8)((gbl_xsdt->header.length -
sizeof(struct acpi_table_header))
/ item_size);
} else {
item_size = sizeof(u32);
table_data =
ACPI_CAST8(gbl_rsdt) +
sizeof(struct acpi_table_header);
number_of_tables =
(u8)((gbl_rsdt->header.length -
sizeof(struct acpi_table_header))
/ item_size);
}
for (i = 0; i < number_of_tables; ++i, table_data += item_size) {
if (osl_can_use_xsdt()) {
table_address =
(acpi_physical_address)(*ACPI_CAST64
(table_data));
} else {
table_address =
(acpi_physical_address)(*ACPI_CAST32
(table_data));
}
if (table_address == 0) {
continue;
}
status =
osl_map_table(table_address, NULL, &mapped_table);
if (ACPI_FAILURE(status)) {
return (status);
}
table_length = mapped_table->length;
if (!ACPI_COMPARE_NAME
(mapped_table->signature, signature)) {
osl_unmap_table(mapped_table);
mapped_table = NULL;
continue;
}
if (current_instance != instance) {
osl_unmap_table(mapped_table);
mapped_table = NULL;
current_instance++;
continue;
}
break;
}
}
exit_find_table:
if (!mapped_table) {
return (AE_LIMIT);
}
if (table_length == 0) {
status = AE_BAD_HEADER;
goto exit;
}
local_table = calloc(1, table_length);
if (!local_table) {
status = AE_NO_MEMORY;
goto exit;
}
memcpy(local_table, mapped_table, table_length);
*address = table_address;
*table = local_table;
exit:
osl_unmap_table(mapped_table);
return (status);
}
static acpi_status osl_list_customized_tables(char *directory)
{
void *table_dir;
u32 instance;
char temp_name[ACPI_NAME_SIZE];
char *filename;
acpi_status status = AE_OK;
table_dir = acpi_os_open_directory(directory, "*", REQUEST_FILE_ONLY);
if (!table_dir) {
return (osl_get_last_status(AE_NOT_FOUND));
}
while ((filename = acpi_os_get_next_filename(table_dir))) {
status =
osl_table_name_from_file(filename, temp_name, &instance);
if (ACPI_FAILURE(status)) {
continue;
}
status = osl_add_table_to_list(temp_name, instance);
if (ACPI_FAILURE(status)) {
break;
}
}
acpi_os_close_directory(table_dir);
return (status);
}
static acpi_status
osl_map_table(acpi_size address,
char *signature, struct acpi_table_header **table)
{
struct acpi_table_header *mapped_table;
u32 length;
if (!address) {
return (AE_BAD_ADDRESS);
}
mapped_table =
acpi_os_map_memory(address, sizeof(struct acpi_table_header));
if (!mapped_table) {
fprintf(stderr, "Could not map table header at 0x%8.8X%8.8X\n",
ACPI_FORMAT_UINT64(address));
return (osl_get_last_status(AE_BAD_ADDRESS));
}
if (signature) {
if (ACPI_VALIDATE_RSDP_SIG(signature)) {
if (!ACPI_VALIDATE_RSDP_SIG(mapped_table->signature)) {
acpi_os_unmap_memory(mapped_table,
sizeof(struct
acpi_table_header));
return (AE_BAD_SIGNATURE);
}
} else
if (!ACPI_COMPARE_NAME(signature, mapped_table->signature))
{
acpi_os_unmap_memory(mapped_table,
sizeof(struct acpi_table_header));
return (AE_BAD_SIGNATURE);
}
}
length = ap_get_table_length(mapped_table);
acpi_os_unmap_memory(mapped_table, sizeof(struct acpi_table_header));
if (length == 0) {
return (AE_BAD_HEADER);
}
mapped_table = acpi_os_map_memory(address, length);
if (!mapped_table) {
fprintf(stderr,
"Could not map table at 0x%8.8X%8.8X length %8.8X\n",
ACPI_FORMAT_UINT64(address), length);
return (osl_get_last_status(AE_INVALID_TABLE_LENGTH));
}
(void)ap_is_valid_checksum(mapped_table);
*table = mapped_table;
return (AE_OK);
}
static void osl_unmap_table(struct acpi_table_header *table)
{
if (table) {
acpi_os_unmap_memory(table, ap_get_table_length(table));
}
}
static acpi_status
osl_table_name_from_file(char *filename, char *signature, u32 *instance)
{
if (strlen(filename) < ACPI_NAME_SIZE) {
return (AE_BAD_SIGNATURE);
}
if (isdigit((int)filename[ACPI_NAME_SIZE])) {
sscanf(&filename[ACPI_NAME_SIZE], "%u", instance);
} else if (strlen(filename) != ACPI_NAME_SIZE) {
return (AE_BAD_SIGNATURE);
} else {
*instance = 0;
}
ACPI_MOVE_NAME(signature, filename);
return (AE_OK);
}
static acpi_status
osl_read_table_from_file(char *filename,
acpi_size file_offset,
char *signature, struct acpi_table_header **table)
{
FILE *table_file;
struct acpi_table_header header;
struct acpi_table_header *local_table = NULL;
u32 table_length;
s32 count;
acpi_status status = AE_OK;
table_file = fopen(filename, "rb");
if (table_file == NULL) {
fprintf(stderr, "Could not open table file: %s\n", filename);
return (osl_get_last_status(AE_NOT_FOUND));
}
fseek(table_file, file_offset, SEEK_SET);
count = fread(&header, 1, sizeof(struct acpi_table_header), table_file);
if (count != sizeof(struct acpi_table_header)) {
fprintf(stderr, "Could not read table header: %s\n", filename);
status = AE_BAD_HEADER;
goto exit;
}
if (signature) {
if (ACPI_VALIDATE_RSDP_SIG(signature)) {
if (!ACPI_VALIDATE_RSDP_SIG(header.signature)) {
fprintf(stderr,
"Incorrect RSDP signature: found %8.8s\n",
header.signature);
status = AE_BAD_SIGNATURE;
goto exit;
}
} else if (!ACPI_COMPARE_NAME(signature, header.signature)) {
fprintf(stderr,
"Incorrect signature: Expecting %4.4s, found %4.4s\n",
signature, header.signature);
status = AE_BAD_SIGNATURE;
goto exit;
}
}
table_length = ap_get_table_length(&header);
if (table_length == 0) {
status = AE_BAD_HEADER;
goto exit;
}
local_table = calloc(1, table_length);
if (!local_table) {
fprintf(stderr,
"%4.4s: Could not allocate buffer for table of length %X\n",
header.signature, table_length);
status = AE_NO_MEMORY;
goto exit;
}
fseek(table_file, file_offset, SEEK_SET);
count = fread(local_table, 1, table_length, table_file);
if (count != table_length) {
fprintf(stderr, "%4.4s: Could not read table content\n",
header.signature);
status = AE_INVALID_TABLE_LENGTH;
goto exit;
}
(void)ap_is_valid_checksum(local_table);
exit:
fclose(table_file);
*table = local_table;
return (status);
}
static acpi_status
osl_get_customized_table(char *pathname,
char *signature,
u32 instance,
struct acpi_table_header **table,
acpi_physical_address *address)
{
void *table_dir;
u32 current_instance = 0;
char temp_name[ACPI_NAME_SIZE];
char table_filename[PATH_MAX];
char *filename;
acpi_status status;
table_dir = acpi_os_open_directory(pathname, "*", REQUEST_FILE_ONLY);
if (!table_dir) {
return (osl_get_last_status(AE_NOT_FOUND));
}
while ((filename = acpi_os_get_next_filename(table_dir))) {
if (!ACPI_COMPARE_NAME(filename, signature)) {
continue;
}
status =
osl_table_name_from_file(filename, temp_name,
&current_instance);
if (ACPI_FAILURE(status) || current_instance != instance) {
continue;
}
if (instance != 0) {
sprintf(table_filename, "%s/%4.4s%d", pathname,
temp_name, instance);
} else {
sprintf(table_filename, "%s/%4.4s", pathname,
temp_name);
}
break;
}
acpi_os_close_directory(table_dir);
if (!filename) {
return (AE_LIMIT);
}
*address = 0;
status = osl_read_table_from_file(table_filename, 0, NULL, table);
return (status);
}
