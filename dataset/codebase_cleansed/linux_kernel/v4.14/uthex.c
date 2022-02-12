char acpi_ut_hex_to_ascii_char(u64 integer, u32 position)
{
u64 index;
acpi_ut_short_shift_right(integer, position, &index);
return (acpi_gbl_hex_to_ascii[index & 0xF]);
}
acpi_status acpi_ut_ascii_to_hex_byte(char *two_ascii_chars, u8 *return_byte)
{
if (!isxdigit((int)two_ascii_chars[0]) ||
!isxdigit((int)two_ascii_chars[1])) {
return (AE_BAD_HEX_CONSTANT);
}
*return_byte =
acpi_ut_ascii_char_to_hex(two_ascii_chars[1]) |
(acpi_ut_ascii_char_to_hex(two_ascii_chars[0]) << 4);
return (AE_OK);
}
u8 acpi_ut_ascii_char_to_hex(int hex_char)
{
if (hex_char <= '9') {
return ((u8)(hex_char - '0'));
}
if (hex_char <= 'F') {
return ((u8)(hex_char - 0x37));
}
return ((u8)(hex_char - 0x57));
}
