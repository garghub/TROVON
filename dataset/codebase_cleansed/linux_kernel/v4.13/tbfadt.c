static void
acpi_tb_init_generic_address(struct acpi_generic_address *generic_address,
u8 space_id,
u8 byte_width,
u64 address, const char *register_name, u8 flags)
{
u8 bit_width;
bit_width = (u8)(byte_width * 8);
if (byte_width > 31) {
if (!(flags & ACPI_FADT_GPE_REGISTER)) {
ACPI_ERROR((AE_INFO,
"%s - 32-bit FADT register is too long (%u bytes, %u bits) "
"to convert to GAS struct - 255 bits max, truncating",
register_name, byte_width,
(byte_width * 8)));
}
bit_width = 255;
}
ACPI_MOVE_64_TO_64(&generic_address->address, &address);
generic_address->space_id = space_id;
generic_address->bit_width = bit_width;
generic_address->bit_offset = 0;
generic_address->access_width = 0;
}
static u64
acpi_tb_select_address(char *register_name, u32 address32, u64 address64)
{
if (!address64) {
return ((u64)address32);
}
if (address32 && (address64 != (u64)address32)) {
ACPI_BIOS_WARNING((AE_INFO,
"32/64X %s address mismatch in FADT: "
"0x%8.8X/0x%8.8X%8.8X, using %u-bit address",
register_name, address32,
ACPI_FORMAT_UINT64(address64),
acpi_gbl_use32_bit_fadt_addresses ? 32 :
64));
if (acpi_gbl_use32_bit_fadt_addresses) {
return ((u64)address32);
}
}
return (address64);
}
void acpi_tb_parse_fadt(void)
{
u32 length;
struct acpi_table_header *table;
struct acpi_table_desc *fadt_desc;
acpi_status status;
fadt_desc = &acpi_gbl_root_table_list.tables[acpi_gbl_fadt_index];
status = acpi_tb_get_table(fadt_desc, &table);
if (ACPI_FAILURE(status)) {
return;
}
length = fadt_desc->length;
(void)acpi_tb_verify_checksum(table, length);
acpi_tb_create_local_fadt(table, length);
acpi_tb_put_table(fadt_desc);
acpi_tb_install_standard_table((acpi_physical_address)acpi_gbl_FADT.
Xdsdt,
ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL,
FALSE, TRUE, &acpi_gbl_dsdt_index);
if (!acpi_gbl_reduced_hardware) {
if (acpi_gbl_FADT.facs) {
acpi_tb_install_standard_table((acpi_physical_address)
acpi_gbl_FADT.facs,
ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL,
FALSE, TRUE,
&acpi_gbl_facs_index);
}
if (acpi_gbl_FADT.Xfacs) {
acpi_tb_install_standard_table((acpi_physical_address)
acpi_gbl_FADT.Xfacs,
ACPI_TABLE_ORIGIN_INTERNAL_PHYSICAL,
FALSE, TRUE,
&acpi_gbl_xfacs_index);
}
}
}
void acpi_tb_create_local_fadt(struct acpi_table_header *table, u32 length)
{
if (length > sizeof(struct acpi_table_fadt)) {
ACPI_BIOS_WARNING((AE_INFO,
"FADT (revision %u) is longer than %s length, "
"truncating length %u to %u",
table->revision, ACPI_FADT_CONFORMANCE,
length,
(u32)sizeof(struct acpi_table_fadt)));
}
memset(&acpi_gbl_FADT, 0, sizeof(struct acpi_table_fadt));
memcpy(&acpi_gbl_FADT, table,
ACPI_MIN(length, sizeof(struct acpi_table_fadt)));
acpi_gbl_reduced_hardware = FALSE;
if (acpi_gbl_FADT.flags & ACPI_FADT_HW_REDUCED) {
acpi_gbl_reduced_hardware = TRUE;
}
acpi_tb_convert_fadt();
acpi_tb_setup_fadt_registers();
}
static void acpi_tb_convert_fadt(void)
{
const char *name;
struct acpi_generic_address *address64;
u32 address32;
u8 length;
u8 flags;
u32 i;
if (acpi_gbl_FADT.header.length <= ACPI_FADT_V2_SIZE) {
acpi_gbl_FADT.preferred_profile = 0;
acpi_gbl_FADT.pstate_control = 0;
acpi_gbl_FADT.cst_control = 0;
acpi_gbl_FADT.boot_flags = 0;
}
acpi_gbl_FADT.header.length = sizeof(struct acpi_table_fadt);
acpi_gbl_FADT.Xdsdt = acpi_tb_select_address("DSDT",
acpi_gbl_FADT.dsdt,
acpi_gbl_FADT.Xdsdt);
if (acpi_gbl_reduced_hardware) {
return;
}
for (i = 0; i < ACPI_FADT_INFO_ENTRIES; i++) {
address32 = *ACPI_ADD_PTR(u32,
&acpi_gbl_FADT,
fadt_info_table[i].address32);
address64 = ACPI_ADD_PTR(struct acpi_generic_address,
&acpi_gbl_FADT,
fadt_info_table[i].address64);
length = *ACPI_ADD_PTR(u8,
&acpi_gbl_FADT,
fadt_info_table[i].length);
name = fadt_info_table[i].name;
flags = fadt_info_table[i].flags;
if (address32) {
if (address64->address) {
if (address64->address != (u64)address32) {
ACPI_BIOS_WARNING((AE_INFO,
"32/64X address mismatch in FADT/%s: "
"0x%8.8X/0x%8.8X%8.8X, using %u-bit address",
name, address32,
ACPI_FORMAT_UINT64
(address64->address),
acpi_gbl_use32_bit_fadt_addresses
? 32 : 64));
}
if ((ACPI_MUL_8(length) <= ACPI_UINT8_MAX) &&
(address64->bit_width !=
ACPI_MUL_8(length))) {
ACPI_BIOS_WARNING((AE_INFO,
"32/64X length mismatch in FADT/%s: %u/%u",
name,
ACPI_MUL_8(length),
address64->
bit_width));
}
}
if (!address64->address
|| acpi_gbl_use32_bit_fadt_addresses) {
acpi_tb_init_generic_address(address64,
ACPI_ADR_SPACE_SYSTEM_IO,
length,
(u64)address32,
name, flags);
}
}
if (fadt_info_table[i].flags & ACPI_FADT_REQUIRED) {
if (!address64->address || !length) {
ACPI_BIOS_ERROR((AE_INFO,
"Required FADT field %s has zero address and/or length: "
"0x%8.8X%8.8X/0x%X",
name,
ACPI_FORMAT_UINT64(address64->
address),
length));
}
} else if (fadt_info_table[i].flags & ACPI_FADT_SEPARATE_LENGTH) {
if ((address64->address && !length) ||
(!address64->address && length)) {
ACPI_BIOS_WARNING((AE_INFO,
"Optional FADT field %s has valid %s but zero %s: "
"0x%8.8X%8.8X/0x%X", name,
(length ? "Length" :
"Address"),
(length ? "Address" :
"Length"),
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
"PmRegisters", 0);
}
}
}
