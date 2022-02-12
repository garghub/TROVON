static void
acpi_tb_init_generic_address(struct acpi_generic_address *generic_address,
u8 space_id,
u8 byte_width, u64 address, char *register_name)
{
u8 bit_width;
bit_width = (u8)(byte_width * 8);
if (byte_width > 31) {
ACPI_ERROR((AE_INFO,
"%s - 32-bit FADT register is too long (%u bytes, %u bits) "
"to convert to GAS struct - 255 bits max, truncating",
register_name, byte_width, (byte_width * 8)));
bit_width = 255;
}
ACPI_MOVE_64_TO_64(&generic_address->address, &address);
generic_address->space_id = space_id;
generic_address->bit_width = bit_width;
generic_address->bit_offset = 0;
generic_address->access_width = 0;
}
void acpi_tb_parse_fadt(u32 table_index)
{
u32 length;
struct acpi_table_header *table;
length = acpi_gbl_root_table_list.tables[table_index].length;
table =
acpi_os_map_memory(acpi_gbl_root_table_list.tables[table_index].
address, length);
if (!table) {
return;
}
(void)acpi_tb_verify_checksum(table, length);
acpi_tb_create_local_fadt(table, length);
acpi_os_unmap_memory(table, length);
acpi_tb_install_table((acpi_physical_address) acpi_gbl_FADT.Xdsdt,
ACPI_SIG_DSDT, ACPI_TABLE_INDEX_DSDT);
if (!acpi_gbl_reduced_hardware) {
acpi_tb_install_table((acpi_physical_address) acpi_gbl_FADT.
Xfacs, ACPI_SIG_FACS,
ACPI_TABLE_INDEX_FACS);
}
}
void acpi_tb_create_local_fadt(struct acpi_table_header *table, u32 length)
{
if (length > sizeof(struct acpi_table_fadt)) {
ACPI_BIOS_WARNING((AE_INFO,
"FADT (revision %u) is longer than ACPI 5.0 version, "
"truncating length %u to %u",
table->revision, length,
(u32)sizeof(struct acpi_table_fadt)));
}
ACPI_MEMSET(&acpi_gbl_FADT, 0, sizeof(struct acpi_table_fadt));
ACPI_MEMCPY(&acpi_gbl_FADT, table,
ACPI_MIN(length, sizeof(struct acpi_table_fadt)));
acpi_gbl_reduced_hardware = FALSE;
if (acpi_gbl_FADT.flags & ACPI_FADT_HW_REDUCED) {
acpi_gbl_reduced_hardware = TRUE;
}
acpi_tb_convert_fadt();
acpi_tb_validate_fadt();
acpi_tb_setup_fadt_registers();
}
static void acpi_tb_convert_fadt(void)
{
struct acpi_generic_address *address64;
u32 address32;
u32 i;
if (!acpi_gbl_FADT.Xfacs) {
acpi_gbl_FADT.Xfacs = (u64) acpi_gbl_FADT.facs;
} else if (acpi_gbl_FADT.facs &&
(acpi_gbl_FADT.Xfacs != (u64) acpi_gbl_FADT.facs)) {
ACPI_WARNING((AE_INFO,
"32/64 FACS address mismatch in FADT - two FACS tables!"));
}
if (!acpi_gbl_FADT.Xdsdt) {
acpi_gbl_FADT.Xdsdt = (u64) acpi_gbl_FADT.dsdt;
} else if (acpi_gbl_FADT.dsdt &&
(acpi_gbl_FADT.Xdsdt != (u64) acpi_gbl_FADT.dsdt)) {
ACPI_WARNING((AE_INFO,
"32/64 DSDT address mismatch in FADT - two DSDT tables!"));
}
if (acpi_gbl_FADT.header.length <= ACPI_FADT_V2_SIZE) {
acpi_gbl_FADT.preferred_profile = 0;
acpi_gbl_FADT.pstate_control = 0;
acpi_gbl_FADT.cst_control = 0;
acpi_gbl_FADT.boot_flags = 0;
}
acpi_gbl_FADT.header.length = sizeof(struct acpi_table_fadt);
for (i = 0; i < ACPI_FADT_INFO_ENTRIES; i++) {
address32 = *ACPI_ADD_PTR(u32,
&acpi_gbl_FADT,
fadt_info_table[i].address32);
address64 = ACPI_ADD_PTR(struct acpi_generic_address,
&acpi_gbl_FADT,
fadt_info_table[i].address64);
if (address64->address && address32 &&
(address64->address != (u64)address32)) {
ACPI_BIOS_ERROR((AE_INFO,
"32/64X address mismatch in FADT/%s: "
"0x%8.8X/0x%8.8X%8.8X, using 32",
fadt_info_table[i].name, address32,
ACPI_FORMAT_UINT64(address64->
address)));
}
if (address32) {
acpi_tb_init_generic_address(address64,
ACPI_ADR_SPACE_SYSTEM_IO,
*ACPI_ADD_PTR(u8,
&acpi_gbl_FADT,
fadt_info_table
[i].length),
(u64) address32,
fadt_info_table[i].name);
}
}
}
static void acpi_tb_validate_fadt(void)
{
char *name;
struct acpi_generic_address *address64;
u8 length;
u32 i;
if (acpi_gbl_FADT.facs &&
(acpi_gbl_FADT.Xfacs != (u64)acpi_gbl_FADT.facs)) {
ACPI_BIOS_WARNING((AE_INFO,
"32/64X FACS address mismatch in FADT - "
"0x%8.8X/0x%8.8X%8.8X, using 32",
acpi_gbl_FADT.facs,
ACPI_FORMAT_UINT64(acpi_gbl_FADT.Xfacs)));
acpi_gbl_FADT.Xfacs = (u64)acpi_gbl_FADT.facs;
}
if (acpi_gbl_FADT.dsdt &&
(acpi_gbl_FADT.Xdsdt != (u64)acpi_gbl_FADT.dsdt)) {
ACPI_BIOS_WARNING((AE_INFO,
"32/64X DSDT address mismatch in FADT - "
"0x%8.8X/0x%8.8X%8.8X, using 32",
acpi_gbl_FADT.dsdt,
ACPI_FORMAT_UINT64(acpi_gbl_FADT.Xdsdt)));
acpi_gbl_FADT.Xdsdt = (u64)acpi_gbl_FADT.dsdt;
}
if (acpi_gbl_reduced_hardware) {
return;
}
for (i = 0; i < ACPI_FADT_INFO_ENTRIES; i++) {
address64 = ACPI_ADD_PTR(struct acpi_generic_address,
&acpi_gbl_FADT,
fadt_info_table[i].address64);
length =
*ACPI_ADD_PTR(u8, &acpi_gbl_FADT,
fadt_info_table[i].length);
name = fadt_info_table[i].name;
if (address64->address &&
(address64->bit_width != ACPI_MUL_8(length))) {
ACPI_BIOS_WARNING((AE_INFO,
"32/64X length mismatch in FADT/%s: %u/%u",
name, ACPI_MUL_8(length),
address64->bit_width));
}
if (fadt_info_table[i].type & ACPI_FADT_REQUIRED) {
if (!address64->address || !length) {
ACPI_BIOS_ERROR((AE_INFO,
"Required FADT field %s has zero address and/or length: "
"0x%8.8X%8.8X/0x%X",
name,
ACPI_FORMAT_UINT64(address64->
address),
length));
}
} else if (fadt_info_table[i].type & ACPI_FADT_SEPARATE_LENGTH) {
if ((address64->address && !length) ||
(!address64->address && length)) {
ACPI_BIOS_WARNING((AE_INFO,
"Optional FADT field %s has zero address or length: "
"0x%8.8X%8.8X/0x%X",
name,
ACPI_FORMAT_UINT64
(address64->address),
length));
}
}
}
}
static void acpi_tb_setup_fadt_registers(void)
{
struct acpi_generic_address *target64;
struct acpi_generic_address *source64;
u8 pm1_register_byte_width;
u32 i;
if (acpi_gbl_use_default_register_widths) {
for (i = 0; i < ACPI_FADT_INFO_ENTRIES; i++) {
target64 =
ACPI_ADD_PTR(struct acpi_generic_address,
&acpi_gbl_FADT,
fadt_info_table[i].address64);
if ((target64->address) &&
(fadt_info_table[i].default_length > 0) &&
(fadt_info_table[i].default_length !=
target64->bit_width)) {
ACPI_BIOS_WARNING((AE_INFO,
"Invalid length for FADT/%s: %u, using default %u",
fadt_info_table[i].name,
target64->bit_width,
fadt_info_table[i].
default_length));
target64->bit_width =
fadt_info_table[i].default_length;
}
}
}
pm1_register_byte_width = (u8)
ACPI_DIV_16(acpi_gbl_FADT.xpm1a_event_block.bit_width);
for (i = 0; i < ACPI_FADT_PM_INFO_ENTRIES; i++) {
source64 =
ACPI_ADD_PTR(struct acpi_generic_address, &acpi_gbl_FADT,
fadt_pm_info_table[i].source);
if (source64->address) {
acpi_tb_init_generic_address(fadt_pm_info_table[i].
target, source64->space_id,
pm1_register_byte_width,
source64->address +
(fadt_pm_info_table[i].
register_num *
pm1_register_byte_width),
"PmRegisters");
}
}
}
