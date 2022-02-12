void acpi_ut_convert_string_to_uuid(char *in_string, u8 *uuid_buffer)
{
u32 i;
for (i = 0; i < UUID_BUFFER_LENGTH; i++) {
uuid_buffer[i] =
(acpi_ut_ascii_char_to_hex
(in_string[acpi_gbl_map_to_uuid_offset[i]]) << 4);
uuid_buffer[i] |=
acpi_ut_ascii_char_to_hex(in_string
[acpi_gbl_map_to_uuid_offset[i] +
1]);
}
}
