char acpi_ut_hex_to_ascii_char(u64 integer, u32 position)
{
return (acpi_gbl_hex_to_ascii[(integer >> position) & 0xF]);
}
u8 acpi_ut_ascii_char_to_hex(int hex_char)
{
if (hex_char <= 0x39) {
return ((u8)(hex_char - 0x30));
}
if (hex_char <= 0x46) {
return ((u8)(hex_char - 0x37));
}
return ((u8)(hex_char - 0x57));
}
